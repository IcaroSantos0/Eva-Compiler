%{
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <stack>
using std::string;
using std::getline;


#define YYSTYPE atributos

using namespace std;

typedef struct VetorChar
{
	char caractere;
	vetorChar *next;
} vetorChar;

typedef struct{

	string tipo;
	string nome;
	string valor;
	vetorChar *texto;
} variable;

typedef struct Atributos
{
	string tipo;
	string label;
	string traducao;
} atributos;

typedef struct{

	string implicita;
	string nomeVar;
	string varConvertida;
} structAux;

int valorVar = 0;
int valorTemp = 0;
int valorLoops = 0;
unordered_map <string, variable> tabSym;
vector <string> tempVector;
stack <int> stackLoops;

int yylex(void);
void yyerror(string);
string genLabel();
string addVarToTabSym(string nomeDado, string conteudoVar, string tipoVar);
structAux implicitConversion(string tipo0, string tipo1, string nome0, string nome1);
string explicitConversion(string tipo0, string tipo1);
string isBoolean(string tipo0, string tipo1);
int erroTipo(string tipo0, string tipo1);
void addVarToTempVector(string nomeVar);
void printVector();
%}

%token TK_MAIN TK_ID TK_IF TK_ELSE TK_THEN TK_END_LOOP TK_WHILE TK_DO
%token TK_DEC_VAR TK_TIPO_INT TK_TIPO_FLOAT TK_TIPO_BOOL TK_TIPO_CHAR
%token TK_CONV_FLOAT TK_CONV_INT TK_LE TK_HE TK_EQ TK_DIFF
%token TK_CHAR TK_FLOAT TK_BOOL TK_NUM
%token TK_STRING TK_FIM TK_ERROR

%start S

%right '=' '!'
%left '|'
%left '&'
%left TK_EQ TK_DIFF
%left '<' '>' TK_HE TK_LE
%left '+' '-'
%left '*' '/'
%left '(' ')'
%nonassoc TK_IF
%nonassoc TK_ELSE

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

						| IF
						{
							$$ = $1;
						}

						| ELSE
						{
							$$ = $1;
						}

						| DECLARACAO ';'
						{
							$$ = $1;
						}

						| WHILE
						{
							$$ = $1;
						}

						| DOWHILE ';'
						{
							$$ = $1;
						}
						;

ATRIBUICAO 	: TK_DEC_VAR TK_ID TK_TIPO_CHAR '=' TK_CHAR
			{
				erroTipo("char", $5.tipo);
				string nomeAuxID = addVarToTabSym($2.label, $5.traducao, "char");
				$$.traducao = "\t" + nomeAuxID + " = " + $5.traducao + ";\n";
				addVarToTempVector("\tchar " + nomeAuxID + ";\n");
			}

			TK_DEC_VAR TK_ID TK_TIPO_CHAR '=' TK_CHAR
			{
				erroTipo("char", $5.tipo);
				string nomeAuxID = addVarToTabSym($2.label, $5.traducao, "char");
				$$.traducao = "\t" + nomeAuxID + " = " + $5.traducao + ";\n";
				addVarToTempVector("\tchar " + nomeAuxID + ";\n");
			}

			| TK_DEC_VAR TK_ID TK_TIPO_INT '=' E
			{
				$$.tipo = "int";
				string nomeAuxID = addVarToTabSym($2.label, $5.traducao, "int");
				$$.traducao = $5.traducao + "\t" + nomeAuxID + " = " + $5.label + ";\n";
				addVarToTempVector("\tint " + nomeAuxID +  ";\n");
			}

			| TK_DEC_VAR TK_ID TK_TIPO_FLOAT '=' E
			{
				$$.tipo = "float";
				string nomeAuxID = addVarToTabSym($2.label, $5.traducao, "float");
				$$.traducao = $5.traducao + "\t" + nomeAuxID + " = " + $5.label + ";\n";
				addVarToTempVector("\tfloat " + nomeAuxID +  ";\n");
			}

			| TK_DEC_VAR TK_ID TK_TIPO_BOOL '=' E
			{
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

IF			: TK_IF {valorLoops++; stackLoops.push(valorLoops);} E TK_THEN COMANDOS TK_END_LOOP ';'
						{
							if($3.tipo != "bool"){
								yyerror("Condicional sem declaração do tipo booleano!\n");
							}

							else{
								string auxVar = "temp" + to_string(valorVar++);
								addVarToTempVector("\tint " + auxVar + ";\n");
								string auxVar2 = "!" + $3.label;
								$$.traducao = "\n\tcomeco" + to_string(stackLoops.top()) + ":\n" + $3.traducao + "\n\t" + auxVar + " = " +
								auxVar2 + ";\n\tif(" + auxVar + ") goto final" + to_string(stackLoops.top()) + ";\n" + $5.traducao + "\tfinal" +
								to_string(stackLoops.top()) + ":\n";
								stackLoops.pop();
							}
						}
						;

ELSE		: IF {valorLoops++; stackLoops.push(valorLoops);} TK_ELSE TK_THEN COMANDOS TK_END_LOOP ';'
						{
							int posiAlteracao = $1.traducao.rfind("final");
							string auxRetorno = $1.traducao;
							auxRetorno.insert(posiAlteracao, "goto final" + to_string(stackLoops.top()) + ";\n\n\t");
							$$.traducao = auxRetorno + $5.traducao + "\tfinal" + to_string(stackLoops.top()) + ":\n";
							stackLoops.pop();
						}
						;

WHILE 		: TK_WHILE {valorLoops++; stackLoops.push(valorLoops);} '(' E ')' BLOCO
					{
						if($4.tipo != "bool"){
							yyerror("Condicional sem declaração do tipo booleano!\n");
						}

						else{
							string auxVar = "temp" + to_string(valorVar++);
							addVarToTempVector("\tint " + auxVar + ";\n");
							string auxVar2 = "!" + $4.label;
							$$.traducao = "\n\tcomeco" + to_string(stackLoops.top()) + ":\n" + $4.traducao + "\n\tloop" + to_string(stackLoops.top()) + ": " + auxVar + " = " +
							auxVar2 + ";\n\tif(" + auxVar + ") goto final" + to_string(stackLoops.top()) + ";\n" + $6.traducao + "\tgoto loop" + to_string(stackLoops.top()) +
							";\n\tfinal" + to_string(stackLoops.top()) + ":\n";
							stackLoops.pop();
						}
					}
					;

DOWHILE		: TK_DO {valorLoops++; stackLoops.push(valorLoops);} BLOCO TK_WHILE '(' E ')'
			{
				if($6.tipo != "bool"){
					yyerror("Condicional sem declaração do tipo booleano!\n");
				}

				else{
					string auxVar = "temp" + to_string(valorVar++);
					addVarToTempVector("\tint " + auxVar + ";\n");
					string auxVar2 = "!" + $6.label;
					$$.traducao = "\n\tcomeco" + to_string(stackLoops.top()) + ":\n" + $3.traducao + "\n\tloop" + to_string(stackLoops.top()) + ":\n" + $6.traducao +
					"\t" + auxVar + " = " + auxVar2 + ";\n\tif (" + auxVar + ") goto final" + to_string(stackLoops.top()) + ";\n\tgoto comeco" + to_string(stackLoops.top()) +
					";\n\tfinal" + to_string(stackLoops.top()) + ":\n";
					stackLoops.pop();
				}
			}

E 			: E '+' E
			{
				$$.label = genLabel();
				structAux aux = implicitConversion($1.tipo, $3.tipo, $1.label, $3.label);
				if(aux.varConvertida == $1.label){ //se primeira variável for int, muda pra float e entra nesse if
					$$.traducao = $1.traducao + $3.traducao + aux.implicita + "\t" + $$.label + " = " + aux.nomeVar + " + " + $3.label + ";\n";
				}
				else if(aux.varConvertida == $3.label){ //se segunda variável for int, muda pra float e entra nesse else
					$$.traducao = $1.traducao + $3.traducao + aux.implicita + "\t" + $$.label + " = " + $1.label + " + " + aux.nomeVar + ";\n";
				}
				else{ //se as duas variáveis são do mesmo tipo
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " + " + $3.label + ";\n";
				}
				addVarToTempVector("\t" + $$.tipo + " " + $$.label  + ";\n");
			}

			| E '-' E
			{
				$$.label = genLabel();
				structAux aux = implicitConversion($1.tipo, $3.tipo, $1.label, $3.label);
				if(aux.varConvertida == $1.label){
					$$.traducao = $1.traducao + $3.traducao + aux.implicita + "\t" + $$.label + " = " + aux.nomeVar + " - " + $3.label + ";\n";
				}
				else if(aux.varConvertida == $3.label){
					$$.traducao = $1.traducao + $3.traducao + aux.implicita + "\t" + $$.label + " = " + $1.label + " - " + aux.nomeVar + ";\n";
				}
				else{ //se as duas variáveis são do mesmo tipo
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " - " + $3.label + ";\n";
				}
				addVarToTempVector("\t" + $$.tipo + " " + $$.label + ";\n");
			}

			| E '*' E
			{
				$$.label = genLabel();
				structAux aux = implicitConversion($1.tipo, $3.tipo, $1.label, $3.label);
				if(aux.varConvertida == $1.label){
					$$.traducao = $1.traducao + $3.traducao + aux.implicita + "\t" + $$.label + " = " + aux.nomeVar + " * " + $3.label + ";\n";
				}
				else if(aux.varConvertida == $3.label){
					$$.traducao = $1.traducao + $3.traducao + aux.implicita + "\t" + $$.label + " = " + $1.label + " * " + aux.nomeVar + ";\n";
				}
				else{ //se as duas variáveis são do mesmo tipo
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " * " + $3.label + ";\n";
				}
				addVarToTempVector("\t" + $$.tipo + " " + $$.label + ";\n");
			}

			| E '/' E
			{
				$$.label = genLabel();
				structAux aux = implicitConversion($1.tipo, $3.tipo, $1.label, $3.label);
				if(aux.varConvertida == $1.label){
					$$.traducao = $1.traducao + $3.traducao + aux.implicita + "\t" + $$.label + " = " + aux.nomeVar + " / " + $3.label + ";\n";
				}
				else if(aux.varConvertida == $3.label){
					$$.traducao = $1.traducao + $3.traducao + aux.implicita + "\t" + $$.label + " = " + $1.label + " / " + aux.nomeVar + ";\n";
				}
				else{ //se as duas variáveis são do mesmo tipo
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " / " + $3.label + ";\n";
				}
				addVarToTempVector("\t" + $$.tipo + " " + $$.label + ";\n");
			}

			| E '<' E
			{
				$$.label = genLabel();
				$$.tipo = "bool";
				//cout << "SOU DO TIPO " << $$.tipo << endl;
				structAux aux = implicitConversion($1.tipo, $3.tipo, $1.label, $3.label);
				if(aux.varConvertida == $1.label){
					$$.traducao = $1.traducao + $3.traducao + aux.implicita + "\t" + $$.label + " = " + aux.nomeVar + " < " + $3.label + ";\n";
				}
				else if(aux.varConvertida == $3.label){
					$$.traducao = $1.traducao + $3.traducao + aux.implicita + "\t" + $$.label + " = " + $1.label + " < " + aux.nomeVar + ";\n";
				}
				else{ //se as duas variáveis são do mesmo tipo
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " < " + $3.label + ";\n";
				}

				addVarToTempVector("\tint " + $$.label + ";\n");
			}

			| E '>' E
			{
				$$.label = genLabel();
				$$.tipo = "bool";
				//cout << "SOU DO TIPO " << $$.tipo << endl;
				structAux aux = implicitConversion($1.tipo, $3.tipo, $1.label, $3.label);

				if(aux.varConvertida == $1.label){
					$$.traducao = $1.traducao + $3.traducao + aux.implicita + "\t" + $$.label + " = " + aux.nomeVar + " > " + $3.label + ";\n";
				}
				else if(aux.varConvertida == $3.label){
					$$.traducao = $1.traducao + $3.traducao + aux.implicita + "\t" + $$.label + " = " + $1.label + " > " + aux.nomeVar + ";\n";
				}
				else{ //se as duas variáveis são do mesmo tipo
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " > " + $3.label + ";\n";
				}

				addVarToTempVector("\tint " + $$.label + ";\n");
			}

			| E TK_LE E
			{
				$$.label = genLabel();
				$$.tipo = "bool";
				//cout << "SOU DO TIPO " << $$.tipo << endl;
				structAux aux = implicitConversion($1.tipo, $3.tipo, $1.label, $3.label);
				if(aux.varConvertida == $1.label){
					$$.traducao = $1.traducao + $3.traducao + aux.implicita + "\t" + $$.label + " = " + aux.nomeVar + " <= " + $3.label + ";\n";
				}
				else if(aux.varConvertida == $3.label){
					$$.traducao = $1.traducao + $3.traducao + aux.implicita + "\t" + $$.label + " = " + $1.label + " <= " + aux.nomeVar + ";\n";
				}
				else{ //se as duas variáveis são do mesmo tipo
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " <= " + $3.label + ";\n";
				}

				addVarToTempVector("\tint " + $$.label + ";\n");
			}

			| E TK_HE E
			{
				$$.label = genLabel();
				$$.tipo = "bool";
				//cout << "SOU DO TIPO " << $$.tipo << endl;
				structAux aux = implicitConversion($1.tipo, $3.tipo, $1.label, $3.label);
				if(aux.varConvertida == $1.label){
					$$.traducao = $1.traducao + $3.traducao + aux.implicita + "\t" + $$.label + " = " + aux.nomeVar + " >= " + $3.label + ";\n";
				}
				else if(aux.varConvertida == $3.label){
					$$.traducao = $1.traducao + $3.traducao + aux.implicita + "\t" + $$.label + " = " + $1.label + " >= " + aux.nomeVar + ";\n";
				}
				else{ //se as duas variáveis são do mesmo tipo
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " >= " + $3.label + ";\n";
				}

				addVarToTempVector("\tint " + $$.label + ";\n");
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
					structAux aux = implicitConversion($1.tipo, $3.tipo, $1.label, $3.label);
					if(aux.varConvertida == $1.label){
						$$.traducao = $1.traducao + $3.traducao + aux.implicita + "\t" + $$.label + " = " + aux.nomeVar + " == " + $3.label + ";\n";
					}
					else if(aux.varConvertida == $3.label){
						$$.traducao = $1.traducao + $3.traducao + aux.implicita + "\t" + $$.label + " = " + $1.label + " == " + aux.nomeVar + ";\n";
					}
					else{ //se as duas variáveis são do mesmo tipo
						$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " == " + $3.label + ";\n";
					}
					addVarToTempVector("\tint " + $$.label + ";\n");

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

					structAux aux = implicitConversion($1.tipo, $3.tipo, $1.label, $3.label);
					if(aux.varConvertida == $1.label){
						$$.traducao = $1.traducao + $3.traducao + aux.implicita + "\t" + $$.label + " = " + aux.nomeVar + " != " + $3.label + ";\n";
					}
					else if(aux.varConvertida == $3.label){
						$$.traducao = $1.traducao + $3.traducao + aux.implicita + "\t" + $$.label + " = " + $1.label + " != " + aux.nomeVar + ";\n";
					}
					else{ //se as duas variáveis são do mesmo tipo
						$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " != " + $3.label + ";\n";
					}
					addVarToTempVector("\tint " + $$.label + ";\n");
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
	//yydebug = 1;
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

		/*if(tipoVar != tabSym[nomeDado].tipo){

			cout << "Variável " << nomeDado << " de tipo " << tabSym[nomeDado].tipo << " e variável de mesmo nome de tipo " << tipoVar << " tentando ser criada!\n" << endl;
			yyerror("Variáveis de mesmo nome com tipos diferentes!\n");
		}*/

		//yyerror("Detectado tentativa de criação de duas variáveis de nome igual!\n");

		return tabSym[nomeDado].nome;
	}

	return "";
}

structAux implicitConversion(string tipo0, string tipo1, string nome0, string nome1){

	if(tipo0 == "float" && tipo1 == "int"){

		string nomeAuxID = "nomeTemporarioFloat" + to_string(valorTemp);
		addVarToTempVector("\tfloat " + nomeAuxID + ";\n");
		string stringRetorno = "\t" + nomeAuxID + " = (float) " + nome1 + ";\n";

		structAux aux = {

							.implicita = stringRetorno,
							.nomeVar = nomeAuxID,
							.varConvertida = nome1
						};

		return aux;
	}

	else if(tipo0 == "int" && tipo1 == "float")
  {

  	string nomeAuxID = "nomeTemporarioFloat" + to_string(valorTemp);
		addVarToTempVector("\tfloat " + nomeAuxID + ";\n");
		string stringRetorno = "\t" + nomeAuxID + " = (float) " + nome0 + ";\n";

		structAux aux = {

							.implicita = stringRetorno,
							.nomeVar = nomeAuxID,
							.varConvertida = nome0
						};

		return aux;

  }

  else if(tipo0 == "float" && tipo1 == "float")
  {

    	string nomeAuxID = "nomeTemporarioFloat" + to_string(valorTemp);

    }

  else if(tipo0 == "int" && tipo1 == "int")
  {

    	string nomeAuxID = "nomeTemporarioInt" + to_string(valorTemp);
    	//return "int";
    }

  else
  {
    yyerror("Nao e possivel realizar operacoes com tipos nao numericos!\n");
  }

    //return "";
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
			return 0;
}
