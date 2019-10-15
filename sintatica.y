%{
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
using std::string;
using std::getline;


#define YYSTYPE atributos

using namespace std;

typedef struct{

	string tipo;
	string nome;
	string valor;
} variable;

struct atributos
{
	string tipo;
	string label;
	string traducao;
};

int valorVar = 0;
int valorTemp = 0;
unordered_map <string, variable> tabSym;
vector <string> tempVector;


int yylex(void);
void yyerror(string);
string genLabel();
string addVarToTabSym(string nomeDado, string conteudoVar, string tipoVar);
string implicitConversion(string tipo0, string tipo1);
string explicitConversion(string tipo0, string tipo1);
string isBoolean(string tipo0, string tipo1);
int erroTipo(string tipo0, string tipo1);
void addVarToTempVector(string nomeVar);
void printVector();
%}

%token TK_MAIN TK_ID
%token TK_DEC_VAR TK_TIPO_INT TK_TIPO_FLOAT TK_TIPO_BOOL TK_TIPO_CHAR
%token TK_CONV_FLOAT TK_CONV_INT TK_LE TK_HE TK_EQ TK_DIFF
%token TK_CHAR TK_FLOAT TK_BOOL TK_NUM
%token TK_FIM TK_ERROR

%start S

%right '=' '!'
%left '|'
%left '&'
%left TK_EQ TK_DIFF
%left '<' '>' TK_HE TK_LE
%left '+' '-'
%left '*' '/'
%left '(' ')'

%%

S 			: TK_TIPO_INT TK_MAIN '(' ')' BLOCO
			{
				cout << "/*Compilador Eva*/\n" << "#include <iostream>\n#include <string.h>\n#include <stdio.h>\n#define TRUE 1\n#define FALSE 0\n\nint main(void)\n{" <<endl;
				printVector();
				cout << $5.traducao << "\treturn 0;\n}" << endl;
			}
			;

BLOCO		: '{' COMANDOS '}'
			{
				$$.traducao = $2.traducao;
			}
			;

COMANDOS	: COMANDO COMANDOS
			{
				$$.traducao = $1.traducao + $2.traducao;
			}
			|

			{
				$$.traducao = "";
			}
			;

COMANDO 	: E ';'
			{
				$$ = $1;
			}

			| ATRIBUICAO ';'
			{
				$$ = $1;
			}

			| DECLARACAO ';'
			{
				$$ = $1;
			}
			;

ATRIBUICAO 	: TK_DEC_VAR TK_ID TK_TIPO_CHAR '=' TK_CHAR
			{
				//erroTipo("char", $5.tipo);
				string nomeAuxID = addVarToTabSym($2.label, $5.traducao, "char");
				$$.traducao = "\t" + nomeAuxID + " = " + $5.traducao + ";\n";
				addVarToTempVector("\tchar " + nomeAuxID + ";\n");
			}

			| TK_DEC_VAR TK_ID TK_TIPO_INT '=' E
			{
				$$.tipo = implicitConversion("int", $5.tipo);	
				string nomeAuxID = addVarToTabSym($2.label, $5.traducao, "int");
				
				if($$.tipo != $5.tipo){
					$$.traducao = $5.traducao + "\t" + nomeAuxID + " = (int) " + $5.label + ";\n";
				}
				else{
					$$.traducao = $5.traducao + "\t" + nomeAuxID + " = " + $5.label + ";\n";
				}
				addVarToTempVector("\tint " + nomeAuxID +  ";\n");
			}

			| TK_DEC_VAR TK_ID TK_TIPO_FLOAT '=' E
			{
				$$.tipo = implicitConversion("float", $5.tipo);	
				string nomeAuxID = addVarToTabSym($2.label, $5.traducao, "float");
				
				if($$.tipo != $5.tipo){
					$$.traducao = $5.traducao + "\t" + nomeAuxID + " = (float) " + $5.label + ";\n";
				}
				else{
					$$.traducao = $5.traducao + "\t" + nomeAuxID + " = " + $5.label + ";\n";
				}
				addVarToTempVector("\tfloat " + nomeAuxID +  ";\n");
			}

			| TK_DEC_VAR TK_ID TK_TIPO_BOOL '=' E
			{
				erroTipo("bool", $5.tipo);
				string nomeAuxID = addVarToTabSym($2.label, $5.traducao, "bool");
				$$.traducao = $5.traducao + "\t" + nomeAuxID + " = " + $5.label + ";\n";
				addVarToTempVector("\tint " + nomeAuxID + ";\n");
			}

			| TK_ID '=' E
			{

				if(($3.tipo != tabSym[$1.label].tipo)){

					if(($3.tipo == "char" && tabSym[$1.label].tipo != "char") || ($3.tipo == "bool" && tabSym[$1.label].tipo != "bool")){
						string msgError = "Atribuição de " + $3.tipo + " em " + tabSym[$1.label].tipo  + " é inválida!\n";
						yyerror(msgError);
					}

					else{
						$$.tipo = tabSym[$1.label].tipo;
						$$.traducao = $3.traducao + "\t" + tabSym[$1.label].nome + " = " + "("+ tabSym[$1.label].tipo + ") " + $3.label + ";\n";

					}
				}

				else{
					$$.tipo = $3.tipo;
					$$.traducao = $3.traducao + "\t" + tabSym[$1.label].nome + " = " + $3.label + ";\n";
				}
			}

			| TK_ID '=' TK_CONV_FLOAT E
			{

				if(($4.tipo == "char" && tabSym[$1.label].tipo != "char") || ($4.tipo == "bool" && tabSym[$1.label].tipo != "bool")){
					string msgError = "Atribuição de " + $4.tipo + " em " + tabSym[$1.label].tipo  + " é inválida!\n";
					yyerror(msgError);
				}

				else{

					if((tabSym[$1.label].tipo == "int") && $4.tipo == "float"){

						cout << "Conversão para float em "<< tabSym[$1.label].nome << " não suportada! Resultado será armazenado como inteiro!\n" << endl;
							$$.traducao = $4.traducao + "\t" + tabSym[$1.label].nome + " = " + $4.label + ";\n";
					}
					else{
							$$.traducao = $4.traducao + "\t" + tabSym[$1.label].nome + " = (float) " + $4.label + ";\n";
					}
				}
			}

			| TK_ID '=' TK_CONV_INT E
			{
				if(($4.tipo == "char" && tabSym[$1.label].tipo != "char") || ($4.tipo == "bool" && tabSym[$1.label].tipo != "bool")){
					string msgError = "Atribuição de " + $4.tipo + " em " + tabSym[$1.label].tipo  + " é inválida!\n";
					yyerror(msgError);
				}

				else{

					$$.traducao = $4.traducao + "\t" + tabSym[$1.label].nome + " = (int) " + $4.label + ";\n";
				}
			}
			;

DECLARACAO	: TK_DEC_VAR TK_ID TK_TIPO_CHAR
			{
				string nomeAuxID = addVarToTabSym($2.label, "none", "char");
				addVarToTempVector("\tchar " + nomeAuxID +  ";\n");
			}

			| TK_DEC_VAR TK_ID TK_TIPO_INT
			{
				string nomeAuxID = addVarToTabSym($2.label, "0", "int");
				addVarToTempVector("\tint " + nomeAuxID + ";\n");
			}

			| TK_DEC_VAR TK_ID TK_TIPO_FLOAT
			{
				string nomeAuxID = addVarToTabSym($2.label, "0.0", "float");
				addVarToTempVector("\tfloat " + nomeAuxID + ";\n");
			}

			| TK_DEC_VAR TK_ID TK_TIPO_BOOL
			{
				string nomeAuxID = addVarToTabSym($2.label, "TRUE", "bool");
				addVarToTempVector("\tint " + nomeAuxID + ";\n");
			}
			;

E 		: E '+' E
			{
				$$.label = genLabel();
				$$.tipo = implicitConversion($1.tipo, $3.tipo);
				$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " + " + $3.label + ";\n";
				addVarToTempVector("\t" + $$.tipo + " " + $$.label  + ";\n");
			}

			| E '-' E
			{
				$$.label = genLabel();
				$$.tipo = implicitConversion($1.tipo, $3.tipo);
				$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " - " + $3.label + ";\n";
				addVarToTempVector("\t" + $$.tipo + " " + $$.label + ";\n");
			}

			| E '*' E
			{
				$$.label = genLabel();
				$$.tipo = implicitConversion($1.tipo, $3.tipo);
				$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " * " + $3.label + ";\n";
				addVarToTempVector("\t" + $$.tipo + " " + $$.label + ";\n");
			}

			| E '/' E
			{
				$$.label = genLabel();
				$$.tipo = "float";
				$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " / " + $3.label + ";\n";
				addVarToTempVector("\t" + $$.tipo + " " + $$.label + ";\n");
			}

			| E '<' E
			{
				$$.label = genLabel();
				$$.tipo = "bool";

				if(($1.tipo != $3.tipo) && ($1.tipo == "int" && $3.tipo == "float")){

					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " < (int) " + $3.label + ";\n";
					addVarToTempVector("\tint " + $$.label + ";\n");
				}

				else if(($1.tipo != $3.tipo) && ($1.tipo == "float" && $3.tipo == "int")){

					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = (int) " + $1.label + " < " + $3.label + ";\n";
					addVarToTempVector("\tint " + $$.label + ";\n");
				}

				else if(($1.tipo == "bool" || $3.tipo == "bool") ||($1.tipo == "char" || $1.tipo == "char" )){

					yyerror("Não é possível operar utilizando booleano ou char!\n");
				}

				else{

					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " < " + $3.label + ";\n";
					addVarToTempVector("\tint " + $$.label + ";\n");
				}
			}

			| E '>' E
			{
				$$.label = genLabel();
				$$.tipo = "bool";

				if(($1.tipo != $3.tipo) && ($1.tipo == "int" && $3.tipo == "float")){

					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " > (int) " + $3.label + ";\n";
					addVarToTempVector("\tint " + $$.label + ";\n");
				}

				else if(($1.tipo != $3.tipo) && ($1.tipo == "float" && $3.tipo == "int")){

					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = (int) " + $1.label + " > " + $3.label + ";\n";
					addVarToTempVector("\tint " + $$.label + ";\n");
				}

				else if(($1.tipo == "bool" || $3.tipo == "bool") ||($1.tipo == "char" || $1.tipo == "char" )){

					yyerror("Não é possível operar utilizando booleano ou char!\n");
				}

				else{

					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " > " + $3.label + ";\n";
					addVarToTempVector("\tint " + $$.label + ";\n");
				}
			}

			| E TK_LE E
			{
				$$.label = genLabel();
				$$.tipo = "bool";

				if(($1.tipo != $3.tipo) && ($1.tipo == "int" && $3.tipo == "float")){

					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " <= (int) " + $3.label + ";\n";
					addVarToTempVector("\tint " + $$.label + ";\n");
				}

				else if(($1.tipo != $3.tipo) && ($1.tipo == "float" && $3.tipo == "int")){

					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = (int) " + $1.label + " <= " + $3.label + ";\n";
					addVarToTempVector("\tint " + $$.label + ";\n");
				}

				else if(($1.tipo == "bool" || $3.tipo == "bool") ||($1.tipo == "char" || $1.tipo == "char" )){

					yyerror("Não é possível operar utilizando booleano ou char!\n");
				}

				else{

					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " <= " + $3.label + ";\n";
					addVarToTempVector("\tint " + $$.label + ";\n");
				}
			}

			| E TK_HE E
			{
				$$.label = genLabel();
				$$.tipo = "bool";

				if(($1.tipo != $3.tipo) && ($1.tipo == "int" && $3.tipo == "float")){

					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " >= (int) " + $3.label + ";\n";
					addVarToTempVector("\tint " + $$.label + ";\n");
				}

				else if(($1.tipo != $3.tipo) && ($1.tipo == "float" && $3.tipo == "int")){

					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = (int) " + $1.label + " >= " + $3.label + ";\n";
					addVarToTempVector("\tint " + $$.label + ";\n");
				}

				else if(($1.tipo == "bool" || $3.tipo == "bool") ||($1.tipo == "char" || $1.tipo == "char" )){

					yyerror("Não é possível operar utilizando booleano ou char!\n");
				}

				else{

					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " >= " + $3.label + ";\n";
					addVarToTempVector("\tint " + $$.label + ";\n");
				}
			}

			| E '|' E
			{
				$$.label = genLabel();
				$$.tipo = isBoolean($1.tipo, $3.tipo);
				$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " || " + $3.label + ";\n";
				addVarToTempVector("\tint " + $$.label + ";\n");
			}

			| E '&' E
			{
				$$.label = genLabel();
				$$.tipo = isBoolean($1.tipo, $3.tipo);
				$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " && " + $3.label + ";\n";
				addVarToTempVector("\tint " + $$.label + ";\n");
			}

			| '!' E
			{
				$$ = $2;
				$$.tipo = isBoolean("bool", $2.tipo);
				$$.label = genLabel();
				$$.traducao = $2.traducao + "\t" + $$.label + " = !" + $2.label + ";\n";
				addVarToTempVector("\tint " + $$.label + ";\n");
			}

			| E TK_EQ E
			{
				$$.label = genLabel();
				$$.tipo = "bool";

				if(($1.tipo == "bool" && $3.tipo == "bool") || ($1.tipo == "char" && $3.tipo == "char")){

					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " == " + $3.label + ";\n";
				}

				else{

					if(($1.tipo != $3.tipo) && ($1.tipo == "int" && $3.tipo == "float")){

						$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " == (int) " + $3.label + ";\n";
						addVarToTempVector("\tint " + $$.label + ";\n");
					}

					else if(($1.tipo != $3.tipo) && ($1.tipo == "float" && $3.tipo == "int")){

						$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = (int) " + $1.label + " == " + $3.label + ";\n";
						addVarToTempVector("\tint " + $$.label + ";\n");
					}

					else if(($1.tipo == "char" || $1.tipo == "bool") || ($3.tipo == "char" || $3.tipo == "bool")){
						yyerror("Não é permitido operações entre char/booleano com tipo numérico!\n");
					}

					else{

						$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " == " + $3.label + ";\n";
						addVarToTempVector("\tint " + $$.label + ";\n");
					}
				}
			}

			| E TK_DIFF E
			{
				$$.label = genLabel();
				$$.tipo = "bool";

				if(($1.tipo == "bool" && $3.tipo == "bool") || ($1.tipo == "char" && $3.tipo == "char")){

					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " != " + $3.label + ";\n";
				}

				else{

					if(($1.tipo != $3.tipo) && ($1.tipo == "int" && $3.tipo == "float")){

						$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " != (int) " + $3.label + ";\n";
						addVarToTempVector("\tint " + $$.label + ";\n");
					}

					else if(($1.tipo != $3.tipo) && ($1.tipo == "float" && $3.tipo == "int")){

						$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = (int) " + $1.label + " != " + $3.label + ";\n";
						addVarToTempVector("\tint " + $$.label + ";\n");
					}

					else if(($1.tipo == "char" || $1.tipo == "bool") || ($3.tipo == "char" || $3.tipo == "bool")){
						yyerror("Não é permitido operações entre char/booleano com tipo numérico!\n");
					}

					else{

						$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " != " + $3.label + ";\n";
						addVarToTempVector("\tint " + $$.label + ";\n");
					}
				}
			}

			| '(' E ')'
			{
				$$ = $2;
			}

			| TK_NUM
			{
				$$.label = "nomeTemporarioInt" + to_string(valorTemp++);
				$$.tipo = "int";
				addVarToTempVector("\tint "  + $$.label + ";\n");
				$$.traducao = "\t" + $$.label + " = " + $1.traducao + ";\n";
			}

			| TK_FLOAT
		 	{
				$$.label = "nomeTemporarioFloat" + to_string(valorTemp++);
				$$.tipo = "float";
				addVarToTempVector("\tfloat " + $$.label + ";\n");
				$$.traducao = "\t" + $$.label + " = " + $1.traducao + ";\n";
		 	}

			| TK_CHAR
			{
				$$.label = "nomeTemporarioChar" + to_string(valorTemp++);
				$$.tipo = "char";
				addVarToTempVector("\tchar "  + $$.label + ";\n");
				$$.traducao = "\t" + $$.label + " = " + $1.traducao + ";\n";
			}

			| TK_BOOL
			{
				$$.label = "nomeTemporarioBool" + to_string(valorTemp++);
				$$.tipo = "bool";
				addVarToTempVector("\tint " + $$.label + ";\n");
				$$.traducao = "\t" + $$.label + " = " + $1.traducao + ";\n";
			}

			| TK_ID
			{
				$$.label = tabSym[$1.label].nome;
				$$.tipo = tabSym[$1.label].tipo;
				$$.traducao = tabSym[$1.label].valor;
			}
			;
%%

#include "lex.yy.c"

int yyparse();

int main( int argc, char* argv[] )
{

	yyparse();
	return 0;
}

void yyerror( string MSG )
{
	cout << MSG << endl;
	exit (0);
}

string genLabel(){

	return "temp" + to_string(valorVar++);
}

string addVarToTabSym(string nomeDado, string conteudoVar, string tipoVar){

	unordered_map<string, variable>::const_iterator got = tabSym.find(nomeDado);
	string nomeGerado;

	if(got == tabSym.end()){

		variable Var;
		nomeGerado = genLabel();

		Var = {
						.tipo = tipoVar,
			   		.nome = nomeGerado,
						.valor = conteudoVar
			  	};

		tabSym[nomeDado] = Var;
		return tabSym[nomeDado].nome;
	}

	else {

		if(tipoVar != tabSym[nomeDado].tipo){

			cout << "Variável " << nomeDado << " de tipo " << tabSym[nomeDado].tipo << " e variável de mesmo nome de tipo " << tipoVar << " tentando ser criada!\n" << endl;
			yyerror("Variáveis de mesmo nome com tipos diferentes!\n");
		}

		return tabSym[nomeDado].nome;
	}

	return "";
}

string implicitConversion(string tipo0, string tipo1)
{

	if(tipo1 == "int" && tipo0 == "float" || tipo0 == "int" && tipo1 == "float")
    {

    	string nomeAuxID = "nomeTemporarioFloat" + to_string(valorTemp);
    	return "float";

    }

    else if(tipo0 == "float" && tipo1 == "float")
    {

    	string nomeAuxID = "nomeTemporarioFloat" + to_string(valorTemp);
    	return "float";
    }

    else if(tipo0 == "int" && tipo1 == "int")
    {

    	string nomeAuxID = "nomeTemporarioInt" + to_string(valorTemp);
    	return "int";
    }

    else
    {
    	yyerror("nao e possivel realizar operacoes com tipos nao numericos!\n");
    }

    return "";
}

string explicitConversion(string tipo0, string tipo1){

	if (tipo0 == "char" || tipo0 == "bool")
	{
		yyerror("não é possivel converter em char ou booleano!\n");
	}

	else
	{
		string nomeAuxID = "nomeTemporario" + tipo1 + to_string(valorTemp);
    	addVarToTempVector("\t" + tipo1 + " " + nomeAuxID + ";\n");
    	return tipo1;
	}

	return "";
}

void addVarToTempVector(string nomeVar)
{
	tempVector.push_back(nomeVar);
}

void printVector()
{
	for(auto i: tempVector)
	{
		cout << i;
	}

	cout << "\n\n" << endl;
}

string isBoolean(string tipo0, string tipo1)
{
	if (tipo1 != "bool" || tipo0 != "bool")
	{
		yyerror("Operacao logica sem tipo booleano!\n");
	}

	else{

		return "bool";
	}

	return "";
}

int erroTipo(string tipo0, string tipo1)
{
	if (tipo1 != tipo0)
	{
		yyerror("tipo de variaveis incompativeis\n");

	}
	else
			return 0;
}
