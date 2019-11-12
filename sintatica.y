%{
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <stack>
#include <list>
using std::string;
using std::getline;


#define YYSTYPE atributos

using namespace std;

typedef struct Variable{

	string tipo;
	string nome;
	string valor;
//std::list<char> caracteres;
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
int mapAtual = 0;
//unordered_map <string, variable> tabSym;
vector <string> tempVector;
stack <int> stackLoops;
vector <unordered_map<string, variable>> contextoVariaveis;

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
void addMapToStack();
variable searchForVariable(string nome);
void checkForVariable(string nome);
//string concatenacao();
%}

%token TK_MAIN TK_ID TK_IF TK_ELSE TK_THEN TK_END_LOOP TK_WHILE TK_DO TK_FOR TK_ENTRADA TK_SAIDA
%token TK_DEC_VAR TK_TIPO_INT TK_TIPO_FLOAT TK_TIPO_BOOL TK_TIPO_CHAR TK_TIPO_STRING
%token TK_UN_POS TK_CONV_FLOAT TK_CONV_INT TK_LE TK_HE TK_EQ TK_DIFF
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

%%

S 			  : BLOCOCONTEXTO TK_TIPO_INT TK_MAIN '(' ')' BLOCO
			{
				cout << "/*Compilador Eva*/\n" << "#include <iostream>\n#include <string.h>\n#include <stdio.h>\n#define TRUE 1\n#define FALSE 0\n\nint main(void)\n{" <<endl;
				printVector();
				cout << $6.traducao << "\treturn 0;\n}" << endl;
			}
			;

BLOCO		  : '{' COMANDOS '}'
				{
					$$.traducao = $2.traducao;
				}
				;

BLOCOCONTEXTO :
							{
								addMapToStack();
								$$.traducao = "";
							}

COMANDOS	  : COMANDO COMANDOS
					{
						$$.traducao = $1.traducao + $2.traducao;
					}

					|
					{
						$$.traducao = "";
					}
					;

COMANDO 	  : E ';'
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

			| ENTRADA ';'
			{
				$$ = $1;
			}

			| SAIDA ';'
			{
				$$ = $1;
			}

			| BLOCOCONTEXTO IF
			{
				$$ = $2;
			}

			| BLOCOCONTEXTO ELSE
			{
				$$ = $2;
			}

			| BLOCOCONTEXTO WHILE
			{
				$$ = $2;
			}

			| BLOCOCONTEXTO DOWHILE ';'
			{
				$$ = $2;
			}

			| BLOCOCONTEXTO FOR
			{
				$$ = $2;
			}
			;

ENTRADA 	: TK_ID '=' TK_ENTRADA
			{
				$$.label = genLabel();
				$$.tipo = $1.tipo;
				variable Var = searchForVariable($1.label);
				cout << "$3.label = " << $3.label << endl;
				$$.traducao = "\tstd::cin" + $$.traducao + $1.traducao + ";\n";
			};

SAIDA 		: TK_SAIDA '=' TK_ID
			{
				$$.label = genLabel();
				variable Var = searchForVariable($3.label);
				$$.traducao = "\tstd::cout " + $3.traducao + ";\n";
			}

ATRIBUICAO 	  : TK_DEC_VAR TK_ID TK_TIPO_CHAR '=' E
			{
				erroTipo("char", $5.tipo);
				string nomeAuxID = addVarToTabSym($2.label, $5.traducao, "char");
				$$.traducao = $5.traducao + "\t" + nomeAuxID + " = " + $5.label + ";\n";
				addVarToTempVector("\tchar " + nomeAuxID + ";\n");
			}

			| TK_DEC_VAR TK_ID TK_TIPO_STRING '=' E
			{
				erroTipo("string", $5.tipo);
				string nomeAuxID = addVarToTabSym($2.label, $5.traducao, "string");
				$$.traducao =  $5.traducao +  "\t" + nomeAuxID + " = " + $5.label + ";\n";
				addVarToTempVector("\tstring " + nomeAuxID + ";\n");
			}

			| TK_DEC_VAR TK_ID TK_TIPO_INT '=' E
			{
				$$.tipo = "int";
				if($$.tipo != $5.tipo){

					if($5.tipo == "char" || $5.tipo == "string"){
						yyerror("Declaração de char/string em int não permitido!");
					}

					else{
						string nomeAuxID = addVarToTabSym($2.label, $5.traducao, "int");
						$$.traducao = $5.traducao + "\t" + nomeAuxID + " = (int) " + $5.label  + ";\n";
						addVarToTempVector("\tint " + nomeAuxID +  ";\n");
					}
				}

				else{
					string nomeAuxID = addVarToTabSym($2.label, $5.traducao, "int");
					$$.traducao = $5.traducao + "\t" + nomeAuxID + " = " + $5.label  + ";\n";
					addVarToTempVector("\tint " + nomeAuxID +  ";\n");
				}
			}

			| TK_DEC_VAR TK_ID TK_TIPO_FLOAT '=' E
			{
				$$.tipo = "float";
				if($$.tipo != $5.tipo){
					if($5.tipo == "char" || $5.tipo == "string"){
						yyerror("Declaração de char/string em float não permitido!");
					}
					else{
						string nomeAuxID = addVarToTabSym($2.label, $5.traducao, "float");
						$$.traducao = $5.traducao + "\t" + nomeAuxID + " = (float) " + $5.label  + ";\n";
						addVarToTempVector("\tfloat " + nomeAuxID +  ";\n");
					}
				}
				else{
					string nomeAuxID = addVarToTabSym($2.label, $5.traducao, "float");
					$$.traducao = $5.traducao + "\t" + nomeAuxID + " = " + $5.label  + ";\n";
					addVarToTempVector("\tint " + nomeAuxID +  ";\n");
				}
			}

			| TK_DEC_VAR TK_ID TK_TIPO_BOOL '=' E
			{
				$$.tipo = "bool";
				if($$.tipo != $5.tipo){
					yyerror("Tipo booleano somente aceita boleano!");
				}
				else{
					string nomeAuxID = addVarToTabSym($2.label, $5.traducao, "int");
					$$.traducao = $5.traducao + "\t" + nomeAuxID + $5.label  + ";\n";
					addVarToTempVector("\tint " + nomeAuxID +  ";\n");
				}
			}

			| TK_ID '=' E
			{
				variable Var = searchForVariable($1.label);
				cout << "\n\nNome expressão: " << $3.label << "\nTipo expressão: " << $3.tipo << endl;

				if(($3.tipo != Var.tipo)){

					if(($3.tipo == "char" && Var.tipo != "char") || ($3.tipo == "bool" && Var.tipo != "bool") || ($3.tipo == "string" && Var.tipo != "string")){
						string msgError = "Atribuição de " + $3.tipo + " em " + Var.tipo  + " é inválida!\n";
						yyerror(msgError);
					}

					else{

						$$.tipo = Var.tipo;
						$$.traducao = $3.traducao + "\t" + Var.nome + " = " + "(" + Var.tipo + ") " + $3.label + ";\n";
					}
				}

				else{

					$$.tipo = $3.tipo;
					$$.traducao = $3.traducao + "\t" + Var.nome + " = " + $3.label + ";\n";
				}
			}

			| TK_ID '=' TK_CONV_FLOAT E
			{
				variable Var = searchForVariable($1.label);
				//unordered_map<string, variable> tabSym = contextoVariaveis.back();
				if(($4.tipo == "char" && Var.tipo != "char") || ($4.tipo == "bool" && Var.tipo != "bool")){
					string msgError = "Atribuição de " + $4.tipo + " em " + Var.tipo  + " é inválida!\n";
					yyerror(msgError);
				}

				else{

					if((Var.tipo == "int") && $4.tipo == "float"){

						cout << "Conversão para float em "<< Var.nome << " não suportada! Resultado será armazenado como inteiro!\n" << endl;
						$$.tipo = "int";
						$$.traducao = $4.traducao + "\t" + Var.nome + " = " + $4.label + ";\n";
					}
					else{
							$$.tipo = "float";
							$$.traducao = $4.traducao + "\t" + Var.nome + " = (float) " + $4.label + ";\n";
					}
				}
			}

			| TK_ID '=' TK_CONV_INT E
			{
				variable Var = searchForVariable($1.label);
				//unordered_map<string, variable> tabSym = contextoVariaveis.back();
				if(($4.tipo == "char" && Var.tipo != "char") || ($4.tipo == "bool" && Var.tipo != "bool")){
					string msgError = "Atribuição de " + $4.tipo + " em " + Var.tipo  + " é inválida!\n";
					yyerror(msgError);
				}

				else{

					$$.traducao = $4.traducao + "\t" + Var.nome + " = (int) " + $4.label + ";\n";
				}
			}
			;

DECLARACAO	  : TK_DEC_VAR TK_ID TK_TIPO_CHAR
			{
				string nomeAuxID = addVarToTabSym($2.label, "none", "char");
				addVarToTempVector("\tchar " + nomeAuxID +  ";\n");
			}

			| TK_DEC_VAR TK_ID TK_TIPO_STRING
			{
				string nomeAuxID = addVarToTabSym($2.label, "none", "string");
				addVarToTempVector("\tstring " + nomeAuxID +  ";\n");
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

IF			  : TK_IF {valorLoops++; stackLoops.push(valorLoops);} E TK_THEN COMANDOS TK_END_LOOP ';'
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
							contextoVariaveis.pop_back();
							mapAtual--;
						}
					}
					;

ELSE		  : IF {valorLoops++; stackLoops.push(valorLoops);} TK_ELSE TK_THEN COMANDOS TK_END_LOOP ';'
				{
					int posiAlteracao = $1.traducao.rfind("final");
					string auxRetorno = $1.traducao;
					auxRetorno.insert(posiAlteracao, "goto final" + to_string(stackLoops.top()) + ";\n\n\t");
					$$.traducao = auxRetorno + $5.traducao + "\tfinal" + to_string(stackLoops.top()) + ":\n";
					stackLoops.pop();
					contextoVariaveis.pop_back();
					mapAtual--;
				}
				;

WHILE 		  : TK_WHILE {valorLoops++; stackLoops.push(valorLoops);} '(' E ')' BLOCO
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
							contextoVariaveis.pop_back();
							mapAtual--;
						}
					}
					;

DOWHILE		  : TK_DO {valorLoops++; stackLoops.push(valorLoops);} BLOCO TK_WHILE '(' E ')'
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
					contextoVariaveis.pop_back();
					mapAtual--;
				}
			}

FOR 		  :	TK_FOR {valorLoops++; stackLoops.push(valorLoops);} TK_ID ';' E ';' E ';' '{' COMANDOS '}'
				  {

				  	if($5.tipo != "bool"){
				  		string msgError = "For somente itera sobre booleano! Tentativa de iterar sobre " + $5.tipo + " inválida!\n";
				  		yyerror(msgError);
				  	}

			  	string nomeVar = addVarToTabSym($4.label, $7.traducao, "int");

			  	string auxVar = "temp" + to_string(valorVar++);
					addVarToTempVector("\tint " + auxVar + ";\n");

					string auxVar2 = genLabel();
					string auxVar3 = "!" + auxVar2;

					$$.traducao = "\n\tcomeco" + to_string(stackLoops.top()) + ":\n" + $5.traducao + "\n\tloop" + to_string(stackLoops.top()) + ": " + auxVar + " = " +
					auxVar3 + ";\n\tif(" + auxVar + ") goto final" + to_string(stackLoops.top()) + ";\n\t" + nomeVar + " = " + nomeVar + " + 1;\n" +
					"\tgoto loop" + to_string(stackLoops.top()) + ";\n\tfinal" + to_string(stackLoops.top()) + ":\n";
					stackLoops.pop();
					contextoVariaveis.pop_back();
					mapAtual--;
				  }

E 			  : E '+' E
			{
				$$.label = genLabel();

				if($$.tipo != "string" && $1.tipo != "string" && $3.tipo != "string")
				{
					cout << $$.tipo << endl;
					structAux aux = implicitConversion($1.tipo, $3.tipo, $1.label, $3.label);
					if(aux.varConvertida == $1.label){
						$$.traducao = $1.traducao + $3.traducao + aux.implicita + "\t" + $$.label + " = " + aux.nomeVar + " + " + $3.label + ";\n";
					}
					else if(aux.varConvertida == $3.label){
						$$.traducao = $1.traducao + $3.traducao + aux.implicita + "\t" + $$.label + " = " + $1.label + " + " + aux.nomeVar + ";\n";
					}
					else{ //se as duas variáveis são do mesmo tipo
						$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " + " + $3.label + ";\n";
				}				}

				else
				{
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " + " + $3.label + ";\n";
					cout << "aqui" << endl;
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

			| TK_ID TK_UN_POS
			{

				variable Var = searchForVariable($1.label);
				$$.tipo = Var.tipo;

				$$.traducao = "\t" + $1.label + " = " + $1.label + " + 1;\n";

			}

			| E '<' E
			{
				$$.label = genLabel();
				$$.tipo = "bool";
				//cout << "SOU DO TIPO " << $1.tipo << endl;

				if(($1.tipo).empty()){ //se a variavel 1 for TK_ID (n vem com tipo)
						cout << "pantomima " << $1.label << endl;
						variable auxVar1 = searchForVariable($1.label);
						$1.tipo = auxVar1.tipo;
						cout << "brita " << $1.tipo << endl;
				}

				if(($3.tipo).empty()){ //se a variavel 3 for TK_ID (n vem com tipo)

						cout << "tireoide " << endl;
						variable auxVar2 = searchForVariable($3.label);
						$3.tipo = auxVar2.tipo;
				}

				if($1.tipo == $3.tipo){ //se elas são do mesmo tipo, não é necessário conversão

					$$.traducao = $1.traducao + $3.traducao + "\n\t" + $$.label + " = " + $1.label + " < " + $3.label + ";\n";
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
				addVarToTempVector("\t" + $$.tipo + " " + $$.label + ";\n");
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

			| TK_STRING
			{
				$$.label = "nomeTemporarioString" + to_string(valorTemp++);
				$$.tipo = "string";
				addVarToTempVector("\tstring "  + $$.label + ";\n");
				$$.traducao = "\t" + $$.label + " = " + $1.traducao + ";\n";
			}

			| TK_ID
			{
				cout << "trombeta " << $1.label << endl;
				variable auxVar = searchForVariable($1.label);
				$$.label = auxVar.nome;
				cout << "carambolas filho " << $$.label << endl;
				$$.tipo = auxVar.tipo;
				$$.traducao;
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

	checkForVariable(nomeDado);
	unordered_map<string, variable> tabSym = contextoVariaveis.back();
	cout << "\ntabSym antes " << (tabSym.empty() ? "is empty" : "is not empty" ) << endl;
	unordered_map<string, variable>::const_iterator got = tabSym.find(nomeDado);
	string nomeGerado;

	if(got == tabSym.end()){

		variable Var2;
		nomeGerado = genLabel();

		Var2 =	{
					.tipo = tipoVar,
				   	.nome = nomeGerado,
					.valor = conteudoVar
		  		};

		tabSym[nomeDado] = Var2;
		contextoVariaveis.pop_back();
		contextoVariaveis.push_back(tabSym);
		cout << "tabSym depois " << (contextoVariaveis.empty() ? "is empty" : "is not empty" ) << endl;
		cout << "\nAdicionado " << tabSym[nomeDado].nome << " de tipo "<< tabSym[nomeDado].tipo <<" na tabela de simbolos " << mapAtual << "!\n" << endl;
		return tabSym[nomeDado].nome;
	}

	/*else {

		return tabSym[nomeDado].nome;
	}*/

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

void addMapToStack(void){

	unordered_map<string, variable> auxMap;
	contextoVariaveis.push_back(auxMap);
	mapAtual++;
	cout << "adicionei o map de numero " << mapAtual << " na tabela de mapas!\n" << endl;
}

variable searchForVariable(string nome){

	int i = mapAtual; //inteiro para percorrer o vetor de mapas
	vector<unordered_map<string, variable>> auxVector; //vetor auxiliar para percorrer
	auxVector = contextoVariaveis; //atribuo o vetor de contexto global para o vetor auxiliar
	unordered_map<string, variable> auxMap; //mapa auxiliar para checar as variáveis dele

	cout << "\ncontextoVariaveis " << (contextoVariaveis.empty() ? "is empty" : "is not empty" ) << endl;
	cout << "quantidade de contextos: " << i << endl;
	cout << "variavel buscando: " << nome << endl;
	cout << "auxVector " << (auxVector.empty() ? "is empty" : "is not empty" ) << endl;

	for(i; i > 0; i--){

		auxMap = auxVector.back();
		auxVector.pop_back();

		cout << "auxMap search iteração " << i << " " << (auxMap.empty() ? "is empty" : "is not empty" ) << endl;

		unordered_map<string, variable>::const_iterator got = auxMap.find(nome); //procuro a variável pelo nome no map mais interno

		if(got != auxMap.end()){ //se esse if for verdade, quer dizer que encontrei a variável no map

			cout << "\n\nEncontrada variável!\nNome: " << nome << "\nTipo: " << auxMap[nome].tipo << "\n" << endl;
			variable auxVar = auxMap[nome];
			return auxVar; //se for, retorno essa variável
		}
	}
	//se não encontrei, a variável não existe e está tentando ser acessada. Erro!
	yyerror("Variável não declarada tentando ser usada!\n");
}

void checkForVariable(string nome){

	int i = mapAtual; //inteiro para percorrer o vetor de mapas
	vector<unordered_map<string, variable>> auxVector; //vetor auxiliar para percorrer
	auxVector = contextoVariaveis; //atribuo o vetor de contexto global para o vetor auxiliar
	unordered_map<string, variable> auxMap; //mapa auxiliar para checar as variáveis dele

	cout << "\ncontextoVariaveis " << (contextoVariaveis.empty() ? "is empty" : "is not empty" ) << endl;
	cout << "quantidade de contextos: " << i << endl;
	cout << "variavel buscando: " << nome << endl;
	cout << "auxVector " << (auxVector.empty() ? "is empty" : "is not empty" ) << endl;

	for(i; i > 0; i--){

		auxMap = auxVector.back();
		auxVector.pop_back();

		cout << "auxMap check iteração " << i << " " << (auxMap.empty() ? "is empty" : "is not empty" ) << endl;

		unordered_map<string, variable>::const_iterator got = auxMap.find(nome); //procuro a variável pelo nome no map mais interno

		if(got != auxMap.end()){ //se esse if for verdade, quer dizer que encontrei a variável no map

			string errorMessage = "\n\nEncontrada variável!\nNome: " + nome + "\nTipo: " + auxMap[nome].tipo + "\n";
			yyerror(errorMessage);
		}
	}
	//se não encontrei, a variável não existe e poderá ser adicionada.
}
