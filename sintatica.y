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
} variable;

typedef struct Atributos
{
	string tipo;
	string label;
	string traducao;
} atributos;

typedef struct{

	string implicita; //tradução após conversão
	string nomeVar; //nome da variável
	string varConvertida; //nome da variável que foi convertida
} structAux; //struct auxiliar utilizada para conversões

int valorVar = 0;
int valorTemp = 0;
int valorLoops = 0;
int valorAuxiliar = 0;
int mapAtual = 0; //indica qual contexto está
int tamanho_vetor = 0; //indica o tamanho do vetor atual
int tamanho_linhas = 0;
int tamanho_colunas = 0;
int elementos_matriz;

stack <string> label_vet; //stack para armazenar o nome dos elementos sendo adicionados no vetor
stack <string> tipo_vet; //stack para armazenar o tipo do elemento armazenado no vetor
stack <string> trad_vet; //stack para armazenar a traducao do elemento armazenado no vetor

unordered_map <string, variable> globalTabSym; //tabela de símbolos global
vector <string> tempVector; //vetor de impressão de variáveis em cód. interm.
vector <string> globalTempVector; //vetor de impressão global
stack <int> stackLoops; //pilha de variáveis de controle de loop
stack <string> stackCommands; //pilha que auxilia qual o tipo de loop existem
stack <string> stackVectors;

unordered_map <string, int> map_vetor;
unordered_map <string, int> map_linhas;
unordered_map <string, int> map_colunas;
unordered_map <string, int> pointer_vector;

unordered_map <string, variable> arrayPointerNames;

vector <unordered_map<string, variable>> contextoVariaveis; //pilha de contextos

//funções yacc
int yylex(void);
void yyerror(string);

//função geradora de label
string genLabel();

//funções de conversão
structAux implicitConversion(string tipo0, string tipo1, string nome0, string nome1);
string explicitConversion(string tipo0, string tipo1);

//funções para checar tipos específicos
string isBoolean(string tipo0, string tipo1);
int erroTipo(string tipo0, string tipo1);

//funções para acessar o vetor de variáveis
void addVarToTempVector(string nomeVar);
void addVarToTempVector(string nomeVar);
void addVarToGlobalTempVector(string nomeVar);
void printVector();
void freeVectors();
void printGlobalVector();

//funções de array e matrix
string addElementsToArray(int tamanhoArray, string nomeArray);

//funções para acessar tabela de simbolos
void addMapToStack();
string addVarToTabSym(string nomeGerado, string nomeDado, string conteudoVar, string tipoVar);
string addVarToGlobalTabSym(string nomeGerado, string nomeDado, string conteudoVar, string tipoVar);
variable searchForVariable(string nome);
variable searchForGlobalVariable(string nome);
void checkForVariable(string nome);
void printGlobalVariables();
%}

//lista de tokens
%token TK_MAIN
%token TK_IF TK_ELSE TK_TERN TK_THEN TK_END_LOOP TK_WHILE TK_DO TK_FOR TK_BREAK TK_CONTINUE TK_ENTRADA TK_SAIDA
%token TK_ID TK_DEC_VAR TK_GLOBAL
%token TK_TIPO_INT TK_TIPO_FLOAT TK_TIPO_BOOL TK_TIPO_CHAR TK_TIPO_STRING
%token TK_CONV_FLOAT TK_CONV_INT TK_LE TK_HE TK_EQ TK_DIFF
%token TK_UN_SUM TK_UN_SUB TK_NUN_SUM TK_NUN_SUB TK_NUN_MUL TK_NUN_DIV
%token TK_CHAR TK_FLOAT TK_BOOL TK_NUM
%token TK_STRING TK_FIM TK_ERROR

//estado inicial
%start S

//ordem de precedência
%right '=' '!'
%left '|'
%left '&'
%left TK_EQ TK_DIFF
%left '<' '>' TK_HE TK_LE
%left '+' '-'
%left '*' '/'
%left '(' ')'
%%

S 		: BLOCOGLOBAL BLOCOCONTEXTO TK_TIPO_INT TK_MAIN '(' ')' BLOCO
			{
				printGlobalVariables();
				cout << "/*Compilador Eva*/\n" << "#include <iostream>\n#include <string.h>\n#include <stdio.h>\n#define TRUE 1\n#define FALSE 0\n\nint main(void)\n{" <<endl;
				printVector();
				cout << $7.traducao << endl;
				freeVectors();
				cout << "\treturn 0;\n}" << endl;
			}
			;

BLOCO		  : '{' COMANDOS '}'
				{
					$$.traducao = $2.traducao;
				}
				;

BLOCOGLOBAL   :
							{
								contextoVariaveis.push_back(globalTabSym);
								cout << "Adicionado o contexto global!" << endl;
							}

BLOCOCONTEXTO :
							{
								addMapToStack();
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

						| TERNARIO
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

						|	BREAK ';'
						{
							$$ = $1;
						}

						|	CONTINUE ';'
						{
							$$ = $1;
						}

						| TK_GLOBAL ATTGLOBAL ';'
						{
							$$ = $2;
						}
						;

VETOR	: E
			{
				$$.traducao = $1.traducao;
				tamanho_vetor++;
				//tamanho_linhas++;
				label_vet.push($1.label);
				tipo_vet.push($1.tipo);
				trad_vet.push($1.traducao);
				$$.tipo = $1.tipo;
				cout << "TAMANHO: " << tamanho_vetor << endl;
			}

			| VETOR ',' E
			{
				$$.traducao = $1.traducao + $3.traducao;
				tamanho_vetor++;
				$$.tipo = $1.tipo;
				label_vet.push($3.label);
				tipo_vet.push($3.tipo);
				trad_vet.push($3.traducao);
				cout << "TAMANHO: " << tamanho_vetor << endl;
			}
			;

MATRIZ	: '[' VETOR ']'
				{
					$$.traducao = $2.traducao;
					$$.tipo = $2.tipo;
          tamanho_linhas++;
					tamanho_vetor = 0;
					cout << "Adicionado uma linha! Linhas totais: " << tamanho_linhas << endl;
				}

				| MATRIZ ',' '['VETOR']'
        {
          $$.traducao = $1.traducao + $4.traducao;
          tamanho_linhas++;
					tamanho_colunas = tamanho_vetor;
					tamanho_vetor = 0;
					cout << "Adicionado uma linha! Linhas totais: " << tamanho_linhas << endl;
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

ATRIBUICAO 	: TK_DEC_VAR TK_ID TK_TIPO_CHAR '=' E
						{
							erroTipo("char", $5.tipo);
							string nomeAuxID = genLabel();
							$$.traducao = $5.traducao + "\t" + nomeAuxID + " = " + $5.label + ";\n";
							addVarToTabSym(nomeAuxID, $2.label, $$.traducao, "char");
							addVarToTempVector("\tchar " + nomeAuxID + ";\n");
						}

						/*| TK_DEC_VAR TK_ID TK_TIPO_STRING '=' E
						{
							erroTipo("string", $5.tipo);
							string nomeAuxID = addVarToTabSym($2.label, $5.traducao, "string");
							$$.traducao =  $5.traducao +  "\t" + nomeAuxID + " = " + $5.label + ";\n";
							addVarToTempVector("\tstring " + nomeAuxID + ";\n");
						}*/

						| TK_DEC_VAR TK_ID TK_TIPO_INT '=' E
						{
							$$.tipo = "int";
							if($$.tipo != $5.tipo){

								if($5.tipo == "char" || $5.tipo == "string"){
									yyerror("Declaração de char/string em int não permitido!");
								}

								else{

									string nomeAuxID = genLabel();
									$$.traducao = $5.traducao + "\t" + nomeAuxID + " = (int) " + $5.label  + ";\n";

									addVarToTabSym(nomeAuxID, $2.label, $$.traducao, "int");
									addVarToTempVector("\tint " + nomeAuxID +  ";\n");
								}
							}

							else{

								string nomeAuxID = genLabel();
								$$.traducao = $5.traducao + "\t" + nomeAuxID + " = " + $5.label  + ";\n";

								addVarToTabSym(nomeAuxID, $2.label, $$.traducao, "int");
								variable Var = searchForVariable($2.label);
								cout << "WHATS IN THE BOX? " << Var.valor << endl;
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
									string nomeAuxID = genLabel();
									$$.traducao = $5.traducao + "\t" + nomeAuxID + " = (float) " + $5.label  + ";\n";
									addVarToTabSym(nomeAuxID, $2.label, $$.traducao, "float");
									addVarToTempVector("\tfloat " + nomeAuxID +  ";\n");
								}
							}
							else{
								string nomeAuxID = genLabel();
								$$.traducao = $5.traducao + "\t" + nomeAuxID + " = " + $5.label  + ";\n";
								addVarToTabSym(nomeAuxID, $2.label, $$.traducao, "float");
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
								string nomeAuxID = genLabel();
								$$.traducao = $5.traducao + "\t" + nomeAuxID + " = " + $5.label  + ";\n";
								addVarToTabSym(nomeAuxID, $2.label, $$.traducao, "int");
								addVarToTempVector("\tint " + nomeAuxID +  ";\n");
							}
						}

						//array sem tamanho determinado
						| TK_DEC_VAR TK_ID '*' TK_TIPO_INT '=' MATRIZ
						{
							$$.tipo = "int";
							if($6.tipo != $$.tipo){
								yyerror("Erro de tipo na atribuição de vetor!");
							}
							else{
								string nomeAuxID = genLabel();
								stackVectors.push("\tfree(" + nomeAuxID + ");\n");
								//variable Var = searchForVariable(nomeAuxID);
								$$.traducao = $6.traducao + "\t" + nomeAuxID + " = (int*) malloc(" +
								addVarToTabSym(nomeAuxID, $2.label, $$.traducao, "int*");
								to_string(tamanho_vetor) + " * sizeof(int));\n" + addElementsToArray(tamanho_vetor, nomeAuxID);
								addVarToTempVector("\tint* " + nomeAuxID + ";\n");
								tamanho_vetor = 0;
							}
						}

						| TK_DEC_VAR TK_ID '*' TK_TIPO_FLOAT '=' MATRIZ
						{
							$$.tipo = "float";
							if($6.tipo != $$.tipo){
								yyerror("Erro de tipo na atribuição de vetor!");
							}
							else{
								string nomeAuxID = genLabel();stackVectors.push("\tfree(" + nomeAuxID + ");\n");
								//variable Var = searchForVariable(nomeAuxID);
								$$.traducao = $6.traducao + "\t" + nomeAuxID + " = (float*) malloc(" +
								addVarToTabSym(nomeAuxID, $2.label, $$.traducao, "float*");
								to_string(tamanho_vetor) + " * sizeof(float));\n" + addElementsToArray(tamanho_vetor, nomeAuxID);
								addVarToTempVector("\tfloat* " + nomeAuxID + ";\n");
								tamanho_vetor = 0;
							}
						}

						|TK_DEC_VAR TK_ID '*' TK_TIPO_CHAR '=' MATRIZ
						{
							$$.tipo = "char";
							if($6.tipo != $$.tipo){
								yyerror("Erro de tipo na atribuição de vetor!");
							}
							else{
								string nomeAuxID = genLabel();stackVectors.push("\tfree(" + nomeAuxID + ");\n");
								//variable Var = searchForVariable(nomeAuxID);
								$$.traducao = $6.traducao + "\t" + nomeAuxID + " = (char*) malloc(" +
								addVarToTabSym(nomeAuxID, $2.label, $$.traducao, "char*");
								to_string(tamanho_vetor) + " * sizeof(char));\n" + addElementsToArray(tamanho_vetor, nomeAuxID);
								addVarToTempVector("\tchar* " + nomeAuxID + ";\n");
								tamanho_vetor = 0;
							}
						}

						//globais

						| TK_DEC_VAR TK_GLOBAL TK_ID TK_TIPO_CHAR '=' E
						{
							erroTipo("char", $6.tipo);
							string nomeAuxID = genLabel();
							addVarToGlobalTabSym(nomeAuxID, $2.label, $6.traducao, "char");
							$$.traducao = $6.traducao + "\t" + nomeAuxID + " = " + $6.label + ";\n";
							addVarToGlobalTempVector("\tchar " + nomeAuxID +  ";\n");
						}

						/*| TK_DEC_VAR TK_GLOBAL TK_ID TK_TIPO_STRING '=' E
						{
							erroTipo("string", $6.tipo);
							string nomeAuxID = addVarToGlobalTabSym($2.label, $6.traducao, "string");
							$$.traducao =  $6.traducao +  "\t" + nomeAuxID + " = " + $6.label + ";\n";
						}
						*/

						| TK_DEC_VAR TK_GLOBAL TK_ID TK_TIPO_INT '=' E
						{
							$$.tipo = "int";
							if($$.tipo != $6.tipo){

								if($6.tipo == "char" || $6.tipo == "string"){
									yyerror("Declaração de char/string em int não permitido!");
								}

								else{
									string nomeAuxID = genLabel();
									addVarToGlobalTabSym(nomeAuxID, $2.label, $6.traducao, "int");
									$$.traducao = $6.traducao + "\t" + nomeAuxID + " = (int) " + $6.label  + ";\n";
									addVarToGlobalTempVector("\tint " + nomeAuxID +  ";\n");
								}
							}

							else{
								string nomeAuxID = genLabel();
								addVarToGlobalTabSym(nomeAuxID, $2.label, $6.traducao, "int");
								$$.traducao = $6.traducao + "\t" + nomeAuxID + " = " + $6.label  + ";\n";
								addVarToGlobalTempVector("\tint " + nomeAuxID +  ";\n");
							}
						}

						| TK_DEC_VAR TK_GLOBAL TK_ID TK_TIPO_FLOAT '=' E
						{
							$$.tipo = "float";
							if($$.tipo != $6.tipo){
								if($6.tipo == "char" || $6.tipo == "string"){
									yyerror("Declaração de char/string em float não permitido!");
								}
								else{
									string nomeAuxID = genLabel();
									addVarToGlobalTabSym(nomeAuxID, $2.label, $6.traducao, "float");
									$$.traducao = $6.traducao + "\t" + nomeAuxID + " = (float) " + $6.label  + ";\n";
									addVarToGlobalTempVector("\tfloat " + nomeAuxID +  ";\n");
								}
							}
							else{
								string nomeAuxID = genLabel();
								addVarToGlobalTabSym(nomeAuxID, $2.label, $6.traducao, "float");
								$$.traducao = $6.traducao + "\t" + nomeAuxID + " = " + $6.label  + ";\n";
								addVarToGlobalTempVector("\tfloat " + nomeAuxID +  ";\n");
							}
						}

						| TK_DEC_VAR TK_GLOBAL TK_ID TK_TIPO_BOOL '=' E
						{
							$$.tipo = "bool";
							if($$.tipo != $6.tipo){
								yyerror("Tipo booleano somente aceita boleano!");
							}
							else{
								string nomeAuxID = genLabel();
								addVarToGlobalTabSym(nomeAuxID, $2.label, $6.traducao, "int");
								$$.traducao = $6.traducao + "\t" + nomeAuxID + " = " + $6.label  + ";\n";
								addVarToGlobalTempVector("\tint " + nomeAuxID +  ";\n");
							}
						}

						//global arrays

						| TK_DEC_VAR TK_GLOBAL TK_ID '*' TK_TIPO_INT '=' MATRIZ
						{
							$$.tipo = "int";
							if($7.tipo != $$.tipo){
								yyerror("Erro de tipo na atribuição de vetor!");
							}
							else{
								string nomeAuxID = genLabel();
								addVarToGlobalTabSym(nomeAuxID, $2.label, $7.traducao, "int*");
								//variable Var = searchForVariable(nomeAuxID);
								$$.traducao = $7.traducao + "\t" + nomeAuxID + " = (int*) malloc(" +
								to_string(tamanho_vetor) + " * sizeof(int));\n" + addElementsToArray(tamanho_vetor, nomeAuxID);
								addVarToGlobalTempVector("\tint* " + nomeAuxID + ";\n");
								tamanho_vetor = 0;
							}
						}

						| TK_DEC_VAR TK_GLOBAL TK_ID '*' TK_TIPO_FLOAT '=' MATRIZ
						{
							$$.tipo = "float";
							if($7.tipo != $$.tipo){
								yyerror("Erro de tipo na atribuição de vetor!");
							}
							else{
								string nomeAuxID = genLabel();
								addVarToGlobalTabSym(nomeAuxID, $2.label, $7.traducao, "float*");
								//variable Var = searchForVariable(nomeAuxID);

								$$.traducao = $7.traducao + "\t" + nomeAuxID + " = (float*) malloc(" +
								to_string(tamanho_vetor) + " * sizeof(float));\n" + addElementsToArray(tamanho_vetor, nomeAuxID);
								addVarToGlobalTempVector("\tfloat* " + nomeAuxID + ";\n");
								tamanho_vetor = 0;
							}
						}

						|TK_DEC_VAR TK_GLOBAL TK_ID '*' TK_TIPO_CHAR '=' MATRIZ
						{
							$$.tipo = "char";
							if($7.tipo != $$.tipo){
								yyerror("Erro de tipo na atribuição de vetor!");
							}
							else{
								string nomeAuxID = genLabel();
								addVarToGlobalTabSym(nomeAuxID, $2.label, $7.traducao, "char*");
								//variable Var = searchForVariable(nomeAuxID);
								$$.traducao = $7.traducao + "\t" + nomeAuxID + " = (char*) malloc(" +
								to_string(tamanho_vetor) + " * sizeof(char));\n" + addElementsToArray(tamanho_vetor, nomeAuxID);
								addVarToGlobalTempVector("\tchar* " + nomeAuxID + ";\n");
								tamanho_vetor = 0;
							}
						}

						//atribuicao sem declaracao

						| TK_ID '=' E
						{
							variable Var = searchForVariable($1.label);

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

						//"unário"
						| TK_ID TK_NUN_SUM E
						{
							variable Var = searchForVariable($1.label);
							variable Var2 = searchForVariable($3.label);
							if(($3.tipo != Var.tipo)){

								if(($3.tipo == "char" && Var.tipo != "char") || ($3.tipo == "bool" && Var.tipo != "bool") || ($3.tipo == "string" && Var.tipo != "string")){
									string msgError = "Atribuição de " + $3.tipo + " em " + Var.tipo  + " é inválida!\n";
									yyerror(msgError);
								}
							}
							else{

								$$.tipo = Var.tipo;
								$$.label = Var.nome;
								$$.traducao = Var2.valor + "\t" + Var.nome + " = " + Var.nome + " + " + $3.label + ";\n";
							}
						}

						| TK_ID TK_NUN_SUB E
						{
							variable Var = searchForVariable($1.label);
							variable Var2 = searchForVariable($3.label);
							if(($3.tipo != Var.tipo)){

								if(($3.tipo == "char" && Var.tipo != "char") || ($3.tipo == "bool" && Var.tipo != "bool") || ($3.tipo == "string" && Var.tipo != "string")){
									string msgError = "Atribuição de " + $3.tipo + " em " + Var.tipo  + " é inválida!\n";
									yyerror(msgError);
								}
							}
							else{

								$$.tipo = Var.tipo;
								$$.label = Var.nome;
								$$.traducao = Var2.valor + "\t" + Var.nome + " = " + Var.nome + " - " + $3.label + ";\n";
							}
						}

						| TK_ID TK_NUN_MUL E
						{
							variable Var = searchForVariable($1.label);
							variable Var2 = searchForVariable($3.label);
							if(($3.tipo != Var.tipo)){

								if(($3.tipo == "char" && Var.tipo != "char") || ($3.tipo == "bool" && Var.tipo != "bool") || ($3.tipo == "string" && Var.tipo != "string")){
									string msgError = "Atribuição de " + $3.tipo + " em " + Var.tipo  + " é inválida!\n";
									yyerror(msgError);
								}
							}
							else{

								$$.tipo = Var.tipo;
								$$.label = Var.nome;
								$$.traducao = Var2.valor + "\t" + Var.nome + " = " + Var.nome + " * " + $3.label + ";\n";
							}
						}

						| TK_ID TK_NUN_DIV E
						{
							variable Var = searchForVariable($1.label);
							variable Var2 = searchForVariable($3.label);
							if(($3.tipo != Var.tipo)){

								if(($3.tipo == "char" && Var.tipo != "char") || ($3.tipo == "bool" && Var.tipo != "bool") || ($3.tipo == "string" && Var.tipo != "string")){
									string msgError = "Atribuição de " + $3.tipo + " em " + Var.tipo  + " é inválida!\n";
									yyerror(msgError);
								}
							}
							else{

								$$.tipo = Var.tipo;
								$$.label = Var.nome;
								$$.traducao = Var2.valor + "\t" + Var.nome + " = " + Var.nome + " / " + $3.label + ";\n";
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

						| TK_ID '=' '[' VETOR ']'
						{
							variable Var = searchForVariable($1.label);
							map_vetor[Var.nome] = tamanho_vetor;
							cout << Var.nome << endl;
							cout << Var.tipo << endl;
							cout << Var.valor << endl;

							if(Var.tipo != $4.tipo + '*'){

								yyerror("Um elemento tentando ser adicionado ao vetor que não é do mesmo tipo!");
							}

							else{

								if(map_linhas[Var.nome] >= map_vetor[Var.nome]){

									$$.traducao = $4.traducao + addElementsToArray(map_vetor[Var.nome], Var.nome);
									cout << "TAMANHO VETOR: " << tamanho_vetor <<"\nTAMANHO LINHA: " << tamanho_linhas << endl;
									map_linhas[Var.nome] = map_linhas[Var.nome] - map_vetor[Var.nome];
									cout << "TAMANHO LINHA ATUAL: " << tamanho_linhas << endl;
									tamanho_vetor = 0;
									map_vetor[Var.nome] = 0;
								}

								else{
									yyerror("Vetor atribuido maior que suportado na variável!");
								}
							}
						}

						| TK_ID '=' '{' MATRIZ '}'
						{
							variable Var = searchForVariable($1.label);
							cout << Var.nome << endl;
							cout << Var.tipo << endl;
							cout << Var.valor << endl;
							if(Var.tipo != $4.tipo + '*'){
								yyerror("Um elemento tentando ser adicionado ao vetor que não é do mesmo tipo!");
							}
							else{
							if(tamanho_vetor > elementos_matriz){
									yyerror("Vetor atribuido maior que variável suporta!");
								}
								else{
									variable Var = searchForVariable($1.label);
									$$.traducao = $4.traducao + addElementsToArray(elementos_matriz, Var.nome);
									//tamanho_vetor -= tamanho_linhas;
									tamanho_vetor = 0;
								}
							}
						}

						| TRYING TK_ID ']' '=' E //array[posicao] = valor
						{
							variable Var = searchForVariable($1.label);

							if(Var.tipo != $5.tipo + "*"){

								yyerror("Um elemento tentando ser adicionado ao vetor que não é do mesmo tipo!");
							}

							else{
								if(map_linhas[Var.nome] != 0){
									//checkForVariable($2.label);
									variable pointer = arrayPointerNames[Var.nome];
									variable kmpls = searchForVariable($2.label);
									$$.traducao = $5.traducao + "\t" + pointer.nome + " = " + kmpls.nome +
									";\n\t" + Var.nome + "[" + pointer.nome + "] = " + $5.label + ";\n";
								}
							}
						}

						| TRYING E ']' '=' E
						{
							variable Var = searchForVariable($1.label);

							if(Var.tipo != $5.tipo + "*"){

								yyerror("Um elemento tentando ser adicionado ao vetor que não é do mesmo tipo!");
							}

							else{
								if(map_linhas[Var.nome] != 0){
									//checkForVariable($2.label);
									variable pointer = arrayPointerNames[Var.nome];
									//variable kmpls = searchForVariable($3.label);
									$$.traducao = $2.traducao + $5.traducao + "\t" + pointer.nome + " = " + $2.label +
									";\n\t" + Var.nome + "[" + pointer.nome + "] = " + $5.label + ";\n";
								}
							}
						}

						| TK_ID '=' TRYING TK_ID ']'
						{
							variable Var = searchForVariable($1.label);
							variable Vector = searchForVariable($3.label);
							variable Index = searchForVariable($4.label);

							if(Var.tipo + "*" != Vector.tipo){

								yyerror("Atribuição de elemento de vetor em uma variável de tipo incompatível!");
							}

							else{

								variable pointer = arrayPointerNames[Vector.nome];
								$$.traducao = "\t" + pointer.nome + " = " + Index.nome + ";\n\t" +
								Var.nome + " = " + Vector.nome + "[" + pointer.nome + "];\n";
							}

						}

						// variavel = array[posicao]
						| TK_ID '=' TRYING E ']'
						{
							variable Var = searchForVariable($1.label);
							variable Vector = searchForVariable($3.label);
							variable Index = searchForVariable($4.label);

							if(Var.tipo + "*" != Vector.tipo){

								yyerror("Atribuição de elemento de vetor em uma variável de tipo incompatível!");
							}

							else{

								variable pointer = arrayPointerNames[Vector.nome];
								$$.traducao = $4.traducao + "\t" + pointer.nome + " = " + Index.nome + ";\n\t" +
								Var.nome + " = " + Vector.nome + "[" + pointer.nome + "];\n";
							}
						}
						;

TRYING	: TK_ID '['
				{
					$$ = $1;
				}

ATTGLOBAL	: TK_ID '=' E
					{
						variable Var = searchForGlobalVariable($1.label);

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

					| TK_ID '=' TK_GLOBAL TK_ID
					{
						variable Var = searchForGlobalVariable($1.label);
						variable Var2 = searchForGlobalVariable($4.label);
						if((Var2.tipo != Var.tipo)){

							if((Var2.tipo == "char" && Var.tipo != "char") || (Var2.tipo == "bool" && Var.tipo != "bool") || (Var2.tipo == "string" && Var.tipo != "string")){
								string msgError = "Atribuição de " + Var2.tipo + " em " + Var.tipo  + " é inválida!\n";
								yyerror(msgError);
							}

							else{

								$$.tipo = Var.tipo;
								$$.traducao = Var2.valor + "\t" + Var.nome + " = " + "(" + Var.tipo + ") " + Var2.nome + ";\n";
							}
						}

						else{

							$$.tipo = Var2.tipo;
							$$.traducao = Var2.valor + "\t" + Var.nome + " = " + Var2.nome + ";\n";
						}
					}

					//"unário"
					| TK_ID TK_NUN_SUM E
					{
						variable Var = searchForGlobalVariable($1.label);
						variable Var2 = searchForVariable($3.label);
						if(($3.tipo != Var.tipo)){

							if(($3.tipo == "char" && Var.tipo != "char") || ($3.tipo == "bool" && Var.tipo != "bool") || ($3.tipo == "string" && Var.tipo != "string")){
								string msgError = "Atribuição de " + $3.tipo + " em " + Var.tipo  + " é inválida!\n";
								yyerror(msgError);
							}
						}
						else{

							$$.tipo = Var.tipo;
							$$.label = Var.nome;
							$$.traducao = Var2.valor + "\t" + Var.nome + " = " + Var.nome + " + " + $3.label + ";\n";
						}
					}

					| TK_ID TK_NUN_SUB E
					{
						variable Var = searchForGlobalVariable($1.label);
						variable Var2 = searchForVariable($3.label);
						if(($3.tipo != Var.tipo)){

							if(($3.tipo == "char" && Var.tipo != "char") || ($3.tipo == "bool" && Var.tipo != "bool") || ($3.tipo == "string" && Var.tipo != "string")){
								string msgError = "Atribuição de " + $3.tipo + " em " + Var.tipo  + " é inválida!\n";
								yyerror(msgError);
							}
						}
						else{

							$$.tipo = Var.tipo;
							$$.label = Var.nome;
							$$.traducao = Var2.valor + "\t" + Var.nome + " = " + Var.nome + " - " + $3.label + ";\n";
						}
					}

					| TK_ID TK_NUN_MUL E
					{
						variable Var = searchForGlobalVariable($1.label);
						variable Var2 = searchForVariable($3.label);
						if(($3.tipo != Var.tipo)){

							if(($3.tipo == "char" && Var.tipo != "char") || ($3.tipo == "bool" && Var.tipo != "bool") || ($3.tipo == "string" && Var.tipo != "string")){
								string msgError = "Atribuição de " + $3.tipo + " em " + Var.tipo  + " é inválida!\n";
								yyerror(msgError);
							}
						}
						else{

							$$.tipo = Var.tipo;
							$$.label = Var.nome;
							$$.traducao = Var2.valor + "\t" + Var.nome + " = " + Var.nome + " * " + $3.label + ";\n";
						}
					}

					| TK_ID TK_NUN_DIV E
					{
						variable Var = searchForGlobalVariable($1.label);
						variable Var2 = searchForVariable($3.label);
						if(($3.tipo != Var.tipo)){

							if(($3.tipo == "char" && Var.tipo != "char") || ($3.tipo == "bool" && Var.tipo != "bool") || ($3.tipo == "string" && Var.tipo != "string")){
								string msgError = "Atribuição de " + $3.tipo + " em " + Var.tipo  + " é inválida!\n";
								yyerror(msgError);
							}
						}
						else{

							$$.tipo = Var.tipo;
							$$.label = Var.nome;
							$$.traducao = Var2.valor + "\t" + Var.nome + " = " + Var.nome + " / " + $3.label + ";\n";
						}
					}

					| TK_ID '=' TK_CONV_FLOAT E
					{
						variable Var = searchForGlobalVariable($1.label);
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
						variable Var = searchForGlobalVariable($1.label);
						//unordered_map<string, variable> tabSym = contextoVariaveis.back();
						if(($4.tipo == "char" && Var.tipo != "char") || ($4.tipo == "bool" && Var.tipo != "bool")){
							string msgError = "Atribuição de " + $4.tipo + " em " + Var.tipo  + " é inválida!\n";
							yyerror(msgError);
						}

						else{

							$$.traducao = $4.traducao + "\t" + Var.nome + " = (int) " + $4.label + ";\n";
						}
					}

					| TK_ID '=' '[' VETOR ']'
					{
						variable Var = searchForGlobalVariable($1.label);
						map_vetor[Var.nome] = tamanho_vetor;
						cout << Var.nome << endl;
						cout << Var.tipo << endl;
						cout << Var.valor << endl;

						if(Var.tipo != $4.tipo + '*'){

							yyerror("Um elemento tentando ser adicionado ao vetor que não é do mesmo tipo!");
						}

						else{

							if(map_linhas[Var.nome] >= map_vetor[Var.nome]){

								$$.traducao = $4.traducao + addElementsToArray(map_vetor[Var.nome], Var.nome);
								cout << "TAMANHO VETOR: " << tamanho_vetor <<"\nTAMANHO LINHA: " << tamanho_linhas << endl;
								map_linhas[Var.nome] = map_linhas[Var.nome] - map_vetor[Var.nome];
								cout << "TAMANHO LINHA ATUAL: " << tamanho_linhas << endl;
								tamanho_vetor = 0;
								map_vetor[Var.nome] = 0;
							}

							else{
								yyerror("Vetor atribuido maior que suportado na variável!");
							}
						}
					}

					| TK_ID '=' '{' MATRIZ '}'
					{
						variable Var = searchForGlobalVariable($1.label);
						cout << Var.nome << endl;
						cout << Var.tipo << endl;
						cout << Var.valor << endl;
						if(Var.tipo != $4.tipo + '*'){
							yyerror("Um elemento tentando ser adicionado ao vetor que não é do mesmo tipo!");
						}
						else{
						if(tamanho_vetor > elementos_matriz){
								yyerror("Vetor atribuido maior que variável suporta!");
							}
							else{
								variable Var = searchForVariable($1.label);
								$$.traducao = $4.traducao + addElementsToArray(elementos_matriz, Var.nome);
								//tamanho_vetor -= tamanho_linhas;
								tamanho_vetor = 0;
							}
						}
					}

					| TRYING TK_ID ']' '=' E //array[posicao] = valor
					{
						variable Var = searchForGlobalVariable($1.label);

						if(Var.tipo != $5.tipo + "*"){
							cout << "TIPO E: " << Var.tipo << endl;
							yyerror("Um elemento tentando ser adicionado ao vetor que não é do mesmo tipo!");
						}

						else{
							if(map_linhas[Var.nome] != 0){
								//checkForVariable($2.label);
								variable pointer = arrayPointerNames[Var.nome];
								variable kmpls = searchForVariable($2.label);
								$$.traducao = $5.traducao + "\t" + pointer.nome + " = " + kmpls.nome +
								";\n\t" + Var.nome + "[" + pointer.nome + "] = " + $5.label + ";\n";
							}
						}
					}

					| TRYING E ']' '=' E
					{
						variable Var = searchForGlobalVariable($1.label);

						if(Var.tipo != $5.tipo + "*"){

							yyerror("Um elemento tentando ser adicionado ao vetor que não é do mesmo tipo!");
						}

						else{
							if(map_linhas[Var.nome] != 0){
								//checkForVariable($2.label);
								variable pointer = arrayPointerNames[Var.nome];
								//variable kmpls = searchForVariable($3.label);
								$$.traducao = $2.traducao + $5.traducao + "\t" + pointer.nome + " = " + $2.label +
								";\n\t" + Var.nome + "[" + pointer.nome + "] = " + $5.label + ";\n";
							}
						}
					}

					| TK_ID '=' TRYING TK_ID ']'
					{
						variable Var = searchForGlobalVariable($1.label);
						variable Vector = searchForVariable($3.label);
						variable Index = searchForVariable($4.label);

						if(Var.tipo + "*" != Vector.tipo){

							yyerror("Atribuição de elemento de vetor em uma variável de tipo incompatível!");
						}

						else{

							variable pointer = arrayPointerNames[Vector.nome];
							$$.traducao = "\t" + pointer.nome + " = " + Index.nome + ";\n\t" +
							Var.nome + " = " + Vector.nome + "[" + pointer.nome + "];\n";
						}
					}

					// variavel = array[posicao]
					| TK_ID '=' TRYING E ']'
					{
						variable Var = searchForGlobalVariable($1.label);
						variable Vector = searchForVariable($3.label);
						variable Index = searchForVariable($4.label);

						if(Var.tipo + "*" != Vector.tipo){

							yyerror("Atribuição de elemento de vetor em uma variável de tipo incompatível!");
						}

						else{

							variable pointer = arrayPointerNames[Vector.nome];
							$$.traducao = $4.traducao + "\t" + pointer.nome + " = " + Index.nome + ";\n\t" +
							Var.nome + " = " + Vector.nome + "[" + pointer.nome + "];\n";
						}
					}
					;

DECLARACAO	: TK_DEC_VAR TK_ID TK_TIPO_CHAR
						{
							string nomeAuxID = genLabel();
							$$.traducao = "";
							addVarToTabSym(nomeAuxID, $2.label, "none", "char");
							addVarToTempVector("\tchar " + nomeAuxID +  ";\n");
						}

						/*| TK_DEC_VAR TK_ID TK_TIPO_STRING
						{
							string nomeAuxID = addVarToTabSym($2.label, "none", "string");
							$$.traducao = "\t";
							addVarToTempVector("\tstring " + nomeAuxID +  ";\n");
						}*/

						| TK_DEC_VAR TK_ID TK_TIPO_INT
						{
							string nomeAuxID = genLabel();
							$$.traducao = "\t" + nomeAuxID + " = 0;\n";
							addVarToTabSym(nomeAuxID, $2.label, "0", "int");
							addVarToTempVector("\tint " + nomeAuxID + ";\n");
						}

						| TK_DEC_VAR TK_ID TK_TIPO_FLOAT
						{
							string nomeAuxID = genLabel();

							$$.traducao = "\t" + nomeAuxID + " = 0.0;\n";;
							addVarToTabSym(nomeAuxID, $2.label, "0.0", "float");
							addVarToTempVector("\tfloat " + nomeAuxID + ";\n");
						}

						| TK_DEC_VAR TK_ID TK_TIPO_BOOL
						{
							string nomeAuxID = genLabel();
							$$.traducao = "\t" + nomeAuxID + " = TRUE;\n";;
							addVarToTabSym(nomeAuxID, $2.label, "TRUE", "bool");
							addVarToTempVector("\tint " + nomeAuxID + ";\n");
						}

						//arrays

						//tamanho fixo

						| ARRAYDECLARATION TK_TIPO_CHAR
						{
							string nomeAuxID = genLabel();
							stackVectors.push("\tfree(" + nomeAuxID + ");\n");
							variable auxiliarInteiro = searchForVariable($1.label);
							map_linhas[nomeAuxID] = tamanho_linhas;

							string nome0 = "Auxiliar" + to_string(valorAuxiliar++);
							string nome1 = "Auxiliar" + to_string(valorAuxiliar++);
							string nomeAux = genLabel();
							addVarToTabSym(nomeAux, nome0, "0", "int");
							string acrescimo = genLabel();
							addVarToTabSym(acrescimo, nome1, "1", "int");
							addVarToTempVector("\tint " + nomeAux + ";\n");
							addVarToTempVector("\tint " + acrescimo + ";\n");
							Variable Var1 = searchForVariable(nome0); //usar "var" como nome de variável é uma decisão horrível
							Variable Var2 = searchForVariable(nome1); //seja quem for lendo isso, não faça o que eu fiz
							string trad = "\t" + Var1.nome + " = 0;\n" + "\t" + Var2.nome + " = 1;\n";
							arrayPointerNames[nomeAuxID] = Var1; //aqui eu armazeno o nome da variável que servirá de ponteiro pro vetor
							arrayPointerNames[nomeAuxID + "Acrescimo"] =  Var2; //essa é o " + 1"

							$$.traducao = "\t" + nomeAuxID + " = (char*) malloc(" +
							auxiliarInteiro.valor + " * sizeof(char));\n";
							addVarToTabSym(nomeAuxID, $$.label, "empty", "char*");
							addVarToTempVector("\tchar* " + nomeAuxID + ";\n");
						}

						| ARRAYDECLARATION TK_TIPO_FLOAT
						{
							string nomeAuxID = genLabel();
							stackVectors.push("\tfree(" + nomeAuxID + ");\n");
							variable auxiliarInteiro = searchForVariable($1.label);
							map_linhas[nomeAuxID] = tamanho_linhas;

							string nome0 = "Auxiliar" + to_string(valorAuxiliar++);
							string nome1 = "Auxiliar" + to_string(valorAuxiliar++);
							string nomeAux = genLabel();
							addVarToTabSym(nomeAux, nome0, "0", "int");
							string acrescimo = genLabel();
							addVarToTabSym(acrescimo, nome1, "1", "int");
							addVarToTempVector("\tint " + nomeAux + ";\n");
							addVarToTempVector("\tint " + acrescimo + ";\n");
							Variable Var1 = searchForVariable(nome0); //usar "var" como nome de variável é uma decisão horrível
							Variable Var2 = searchForVariable(nome1); //seja quem for lendo isso, não faça o que eu fiz
							string trad = "\t" + Var1.nome + " = 0;\n" + "\t" + Var2.nome + " = 1;\n";
							arrayPointerNames[nomeAuxID] = Var1; //aqui eu armazeno o nome da variável que servirá de ponteiro pro vetor
							arrayPointerNames[nomeAuxID + "Acrescimo"] =  Var2; //essa é o " + 1"

							$$.traducao = "\t" + nomeAuxID + " = (float*) malloc(" +
							auxiliarInteiro.valor + " * sizeof(float));\n";
							addVarToTabSym(nomeAuxID, $2.label, "empty", "float*");
							addVarToTempVector("\tfloat* " + nomeAuxID + ";\n");
						}

						| ARRAYDECLARATION TK_TIPO_INT
						{
							string nomeAuxID = genLabel();
							stackVectors.push("\tfree(" + nomeAuxID + ");\n");
							variable auxiliarInteiro = searchForVariable($1.label);
							map_linhas[nomeAuxID] = tamanho_linhas;

							string nome0 = "Auxiliar" + to_string(valorAuxiliar++);
							string nome1 = "Auxiliar" + to_string(valorAuxiliar++);
							string nomeAux = genLabel();
							addVarToTabSym(nomeAux, nome0, "0", "int");
							string acrescimo = genLabel();
							addVarToTabSym(acrescimo, nome1, "1", "int");
							addVarToTempVector("\tint " + nomeAux + ";\n");
							addVarToTempVector("\tint " + acrescimo + ";\n");
							Variable Var1 = searchForVariable(nome0); //usar "var" como nome de variável é uma decisão horrível
							Variable Var2 = searchForVariable(nome1); //seja quem for lendo isso, não faça o que eu fiz
							string trad = "\t" + Var1.nome + " = 0;\n" + "\t" + Var2.nome + " = 1;\n";
							arrayPointerNames[nomeAuxID] = Var1; //aqui eu armazeno o nome da variável que servirá de ponteiro pro vetor
							arrayPointerNames[nomeAuxID + "Acrescimo"] =  Var2; //essa é o " + 1"

							$$.traducao = trad + "\t" + nomeAuxID + " = (int*) malloc(" +
							auxiliarInteiro.valor + " * sizeof(int));\n";
 							addVarToTabSym(nomeAuxID, $2.label, "empty", "int*");
							addVarToTempVector("\tint* " + nomeAuxID + ";\n");
						}

						//matrizes
						| MATRIXDECLARATION TK_TIPO_INT
						{
							string nomeAuxID = genLabel();
							stackVectors.push("\tfree(" + nomeAuxID + ");\n");

							string nome0 = "Auxiliar" + to_string(valorAuxiliar++);
							string nome1 = "Auxiliar" + to_string(valorAuxiliar++);
							string nomeAux = genLabel();
							addVarToTabSym(nomeAux, nome0, "0", "int");
							string acrescimo = genLabel();
							addVarToTabSym(acrescimo, nome1, "1", "int");
							addVarToTempVector("\tint " + nomeAux + ";\n");
							addVarToTempVector("\tint " + acrescimo + ";\n");
							Variable Var1 = searchForVariable(nome0); //usar "var" como nome de variável é uma decisão horrível
							Variable Var2 = searchForVariable(nome1); //seja quem for lendo isso, não faça o que eu fiz
							string trad = "\t" + Var1.nome + " = 0;\n" + "\t" + Var2.nome + " = 1;\n";
							arrayPointerNames[nomeAuxID] = Var1; //aqui eu armazeno o nome da variável que servirá de ponteiro pro vetor
							arrayPointerNames[nomeAuxID + "Acrescimo"] =  Var2; //essa é o " + 1"

							$$.traducao = trad + "\t" + nomeAuxID + " = (int*) malloc(" +
							to_string(elementos_matriz) + " * sizeof(int));\n";
							addVarToTabSym(nomeAuxID, $2.label, "empty", "int*");
							addVarToTempVector("\tint* " + nomeAuxID + ";\n");
						}

						| MATRIXDECLARATION TK_TIPO_FLOAT
						{
							string nomeAuxID = genLabel();
							stackVectors.push("\tfree(" + nomeAuxID + ");\n");

							string nome0 = "Auxiliar" + to_string(valorAuxiliar++);
							string nome1 = "Auxiliar" + to_string(valorAuxiliar++);
							string nomeAux = genLabel();
							addVarToTabSym(nomeAux, nome0, "0", "int");
							string acrescimo = genLabel();
							addVarToTabSym(acrescimo, nome1, "1", "int");
							addVarToTempVector("\tint " + nomeAux + ";\n");
							addVarToTempVector("\tint " + acrescimo + ";\n");
							Variable Var1 = searchForVariable(nome0); //usar "var" como nome de variável é uma decisão horrível
							Variable Var2 = searchForVariable(nome1); //seja quem for lendo isso, não faça o que eu fiz
							string trad = "\t" + Var1.nome + " = 0;\n" + "\t" + Var2.nome + " = 1;\n";
							arrayPointerNames[nomeAuxID] = Var1; //aqui eu armazeno o nome da variável que servirá de ponteiro pro vetor
							arrayPointerNames[nomeAuxID + "Acrescimo"] =  Var2; //essa é o " + 1"

							$$.traducao = "\t" + nomeAuxID + " = (float*) malloc(" +
							to_string(elementos_matriz) + " * sizeof(float));\n";
							addVarToTabSym(nomeAuxID, $2.label, "empty", "float*");
							addVarToTempVector("\tfloat* " + nomeAuxID + ";\n");
						}

						| MATRIXDECLARATION TK_TIPO_CHAR
						{
							string nomeAuxID = genLabel();
							stackVectors.push("\tfree(" + nomeAuxID + ");\n");

							string nome0 = "Auxiliar" + to_string(valorAuxiliar++);
							string nome1 = "Auxiliar" + to_string(valorAuxiliar++);
							string nomeAux = genLabel();
							addVarToTabSym(nomeAux, nome0, "0", "int");
							string acrescimo = genLabel();
							addVarToTabSym(acrescimo, nome1, "1", "int");
							addVarToTempVector("\tint " + nomeAux + ";\n");
							addVarToTempVector("\tint " + acrescimo + ";\n");
							Variable Var1 = searchForVariable(nome0); //usar "var" como nome de variável é uma decisão horrível
							Variable Var2 = searchForVariable(nome1); //seja quem for lendo isso, não faça o que eu fiz
							string trad = "\t" + Var1.nome + " = 0;\n" + "\t" + Var2.nome + " = 1;\n";
							arrayPointerNames[nomeAuxID] = Var1; //aqui eu armazeno o nome da variável que servirá de ponteiro pro vetor
							arrayPointerNames[nomeAuxID + "Acrescimo"] =  Var2; //essa é o " + 1"

							$$.traducao = "\t" + nomeAuxID + " = (char*) malloc(" +
							to_string(elementos_matriz) + " * sizeof(char));\n";
							addVarToTabSym(nomeAuxID, $2.label, "empty", "char*");
							addVarToTempVector("\tchar* " + nomeAuxID + ";\n");
						}

						//tamanho variável

						| TK_DEC_VAR TK_ID '*' TK_TIPO_INT
						{
							string nomeAuxID = genLabel();
							stackVectors.push("\tfree(" + nomeAuxID + ");\n");

							string nome0 = "Auxiliar" + to_string(valorAuxiliar++);
							string nome1 = "Auxiliar" + to_string(valorAuxiliar++);
							string nomeAux = genLabel();
							addVarToTabSym(nomeAux, nome0, "0", "int");
							string acrescimo = genLabel();
							addVarToTabSym(acrescimo, nome1, "1", "int");
							addVarToTempVector("\tint " + nomeAux + ";\n");
							addVarToTempVector("\tint " + acrescimo + ";\n");
							Variable Var1 = searchForVariable(nome0); //usar "var" como nome de variável é uma decisão horrível
							Variable Var2 = searchForVariable(nome1); //seja quem for lendo isso, não faça o que eu fiz
							string trad = "\t" + Var1.nome + " = 0;\n" + "\t" + Var2.nome + " = 1;\n";
							arrayPointerNames[nomeAuxID] = Var1; //aqui eu armazeno o nome da variável que servirá de ponteiro pro vetor
							arrayPointerNames[nomeAuxID + "Acrescimo"] =  Var2; //essa é o " + 1"

							map_linhas[nomeAuxID] = 50;
							$$.traducao = trad + "\t" + nomeAuxID + " = (int*) malloc(50 * sizeof(int));\n";
							addVarToTabSym(nomeAuxID, $2.label, "empty", "int*");
							//tamanho_vetor = 50;
							addVarToTempVector("\tint* " + nomeAuxID + ";\n");
						}

						| TK_DEC_VAR TK_ID '*' TK_TIPO_FLOAT
						{
							string nomeAuxID = genLabel();

							stackVectors.push("\tfree(" + nomeAuxID + ");\n");

							string nome0 = "Auxiliar" + to_string(valorAuxiliar++);
							string nome1 = "Auxiliar" + to_string(valorAuxiliar++);
							string nomeAux = genLabel();
							addVarToTabSym(nomeAux, nome0, "0", "int");
							string acrescimo = genLabel();
							addVarToTabSym(acrescimo, nome1, "1", "int");
							addVarToTempVector("\tint " + nomeAux + ";\n");
							addVarToTempVector("\tint " + acrescimo + ";\n");
							Variable Var1 = searchForVariable(nome0); //usar "var" como nome de variável é uma decisão horrível
							Variable Var2 = searchForVariable(nome1); //seja quem for lendo isso, não faça o que eu fiz
							string trad = "\t" + Var1.nome + " = 0;\n" + "\t" + Var2.nome + " = 1;\n";
							arrayPointerNames[nomeAuxID] = Var1; //aqui eu armazeno o nome da variável que servirá de ponteiro pro vetor
							arrayPointerNames[nomeAuxID + "Acrescimo"] =  Var2; //essa é o " + 1"

							map_linhas[nomeAuxID] = 50;
							$$.traducao = "\t" + nomeAuxID + " = (float*) malloc(" +
							to_string(tamanho_vetor) + " * sizeof(float));\n";
							addVarToTabSym(nomeAuxID, $2.label, "empty", "float*");
							addVarToTempVector("\tfloat* " + nomeAuxID + ";\n");
						}

						| TK_DEC_VAR TK_ID '*' TK_TIPO_CHAR
						{
							string nomeAuxID = genLabel();
							stackVectors.push("\tfree(" + nomeAuxID + ");\n");

							string nome0 = "Auxiliar" + to_string(valorAuxiliar++);
							string nome1 = "Auxiliar" + to_string(valorAuxiliar++);
							string nomeAux = genLabel();
							addVarToTabSym(nomeAux, nome0, "0", "int");
							string acrescimo = genLabel();
							addVarToTabSym(acrescimo, nome1, "1", "int");
							addVarToTempVector("\tint " + nomeAux + ";\n");
							addVarToTempVector("\tint " + acrescimo + ";\n");
							Variable Var1 = searchForVariable(nome0); //usar "var" como nome de variável é uma decisão horrível
							Variable Var2 = searchForVariable(nome1); //seja quem for lendo isso, não faça o que eu fiz
							string trad = "\t" + Var1.nome + " = 0;\n" + "\t" + Var2.nome + " = 1;\n";
							arrayPointerNames[nomeAuxID] = Var1; //aqui eu armazeno o nome da variável que servirá de ponteiro pro vetor
							arrayPointerNames[nomeAuxID + "Acrescimo"] =  Var2; //essa é o " + 1"

							map_linhas[nomeAuxID] = 50;
							$$.traducao = "\t" + nomeAuxID + " = (char*) malloc(50 * sizeof(char));\n";
							addVarToTabSym(nomeAuxID, $2.label, "empty", "char*");
							addVarToTempVector("\tchar* " + nomeAuxID + ";\n");
						}

						//globais

						| TK_DEC_VAR TK_GLOBAL TK_ID TK_TIPO_CHAR
						{
							string nomeAuxID = genLabel();
							addVarToTabSym(nomeAuxID, $2.label, "none", "char");
							$$.traducao = "";
							addVarToGlobalTempVector("\tchar " + nomeAuxID + ";\n");
						}

						/*| TK_DEC_VAR TK_GLOBAL TK_ID TK_TIPO_STRING
						{
							string nomeAuxID = addVarToGlobalTabSym($2.label, "none", "string");
							$$.traducao = "\t";
						}*/

						| TK_DEC_VAR TK_GLOBAL TK_ID TK_TIPO_INT
						{
							string nomeAuxID = genLabel();
							$$.traducao = "\t" + nomeAuxID + " = 0;\n";
							addVarToGlobalTabSym(nomeAuxID, $3.label, "0", "int");
							//addVarToGlobalTempVector("\tint " + nomeAuxID + ";\n");
						}

						| TK_DEC_VAR TK_GLOBAL TK_ID TK_TIPO_FLOAT
						{
							string nomeAuxID = genLabel();
							addVarToGlobalTabSym(nomeAuxID, $2.label, "0.0", "float");
							$$.traducao = "\t" + nomeAuxID + " = 0.-;\n";
							addVarToGlobalTempVector("\tfloat " + nomeAuxID + ";\n");
						}

						| TK_DEC_VAR TK_GLOBAL TK_ID TK_TIPO_BOOL
						{
							string nomeAuxID = genLabel();
							addVarToGlobalTabSym(nomeAuxID, $2.label, "TRUE", "bool");
							$$.traducao = "\t" + nomeAuxID + " = TRUE;\n";
							addVarToGlobalTempVector("\tint " + nomeAuxID + ";\n");
						}

						//global arrays

						//tamanho variável
						| TK_DEC_VAR TK_GLOBAL TK_ID '*' TK_TIPO_INT
						{
							string nomeAuxID = genLabel();
							stackVectors.push("\tfree(" + nomeAuxID + ");\n");

							string nome0 = "Auxiliar" + to_string(valorAuxiliar++);
							string nome1 = "Auxiliar" + to_string(valorAuxiliar++);
							string nomeAux = genLabel();
							addVarToTabSym(nomeAux, nome0, "0", "int");
							string acrescimo = genLabel();
							addVarToTabSym(acrescimo, nome1, "1", "int");
							addVarToTempVector("\tint " + nomeAux + ";\n");
							addVarToTempVector("\tint " + acrescimo + ";\n");
							Variable Var1 = searchForVariable(nome0); //usar "var" como nome de variável é uma decisão horrível
							Variable Var2 = searchForVariable(nome1); //seja quem for lendo isso, não faça o que eu fiz
							string trad = "\t" + Var1.nome + " = 0;\n" + "\t" + Var2.nome + " = 1;\n";
							arrayPointerNames[nomeAuxID] = Var1; //aqui eu armazeno o nome da variável que servirá de ponteiro pro vetor
							arrayPointerNames[nomeAuxID + "Acrescimo"] =  Var2; //essa é o " + 1"

							map_linhas[nomeAuxID] = 50;
							$$.traducao = trad + "\t" + nomeAuxID + " = (int*) malloc(50 * sizeof(int));\n";
							addVarToGlobalTabSym(nomeAuxID, $3.label, "empty", "int*");
						}

						| TK_DEC_VAR TK_GLOBAL TK_ID '*' TK_TIPO_FLOAT
						{
							string nomeAuxID = genLabel();

							stackVectors.push("\tfree(" + nomeAuxID + ");\n");

							string nome0 = "Auxiliar" + to_string(valorAuxiliar++);
							string nome1 = "Auxiliar" + to_string(valorAuxiliar++);
							string nomeAux = genLabel();
							addVarToTabSym(nomeAux, nome0, "0", "int");
							string acrescimo = genLabel();
							addVarToTabSym(acrescimo, nome1, "1", "int");
							addVarToTempVector("\tint " + nomeAux + ";\n");
							addVarToTempVector("\tint " + acrescimo + ";\n");
							Variable Var1 = searchForVariable(nome0); //usar "var" como nome de variável é uma decisão horrível
							Variable Var2 = searchForVariable(nome1); //seja quem for lendo isso, não faça o que eu fiz
							string trad = "\t" + Var1.nome + " = 0;\n" + "\t" + Var2.nome + " = 1;\n";
							arrayPointerNames[nomeAuxID] = Var1; //aqui eu armazeno o nome da variável que servirá de ponteiro pro vetor
							arrayPointerNames[nomeAuxID + "Acrescimo"] =  Var2; //essa é o " + 1"

							map_linhas[nomeAuxID] = 50;
							$$.traducao = "\t" + nomeAuxID + " = (float*) malloc(" +
							to_string(tamanho_vetor) + " * sizeof(float));\n";
							addVarToGlobalTabSym(nomeAuxID, $3.label, "empty", "float*");
						}

						| TK_DEC_VAR TK_GLOBAL TK_ID '*' TK_TIPO_CHAR
						{
							string nomeAuxID = genLabel();
							stackVectors.push("\tfree(" + nomeAuxID + ");\n");

							string nome0 = "Auxiliar" + to_string(valorAuxiliar++);
							string nome1 = "Auxiliar" + to_string(valorAuxiliar++);
							string nomeAux = genLabel();
							addVarToTabSym(nomeAux, nome0, "0", "int");
							string acrescimo = genLabel();
							addVarToTabSym(acrescimo, nome1, "1", "int");
							addVarToTempVector("\tint " + nomeAux + ";\n");
							addVarToTempVector("\tint " + acrescimo + ";\n");
							Variable Var1 = searchForVariable(nome0); //usar "var" como nome de variável é uma decisão horrível
							Variable Var2 = searchForVariable(nome1); //seja quem for lendo isso, não faça o que eu fiz
							string trad = "\t" + Var1.nome + " = 0;\n" + "\t" + Var2.nome + " = 1;\n";
							arrayPointerNames[nomeAuxID] = Var1; //aqui eu armazeno o nome da variável que servirá de ponteiro pro vetor
							arrayPointerNames[nomeAuxID + "Acrescimo"] =  Var2; //essa é o " + 1"

							map_linhas[nomeAuxID] = 50;
							$$.traducao = "\t" + nomeAuxID + " = (char*) malloc(50 * sizeof(char));\n";
							addVarToGlobalTabSym(nomeAuxID, $3.label, "empty", "char*");
						}

						//tamanho fixo

						| GADECLARATION TK_TIPO_INT
						{
							string nomeAuxID = genLabel();
							stackVectors.push("\tfree(" + nomeAuxID + ");\n");
							variable auxiliarInteiro = searchForVariable($1.label);
							map_linhas[nomeAuxID] = tamanho_linhas;

							string nome0 = "Auxiliar" + to_string(valorAuxiliar++);
							string nome1 = "Auxiliar" + to_string(valorAuxiliar++);
							string nomeAux = genLabel();
							addVarToTabSym(nomeAux, nome0, "0", "int");
							string acrescimo = genLabel();
							addVarToTabSym(acrescimo, nome1, "1", "int");
							addVarToTempVector("\tint " + nomeAux + ";\n");
							addVarToTempVector("\tint " + acrescimo + ";\n");
							Variable Var1 = searchForVariable(nome0); //usar "var" como nome de variável é uma decisão horrível
							Variable Var2 = searchForVariable(nome1); //seja quem for lendo isso, não faça o que eu fiz
							string trad = "\t" + Var1.nome + " = 0;\n" + "\t" + Var2.nome + " = 1;\n";
							arrayPointerNames[nomeAuxID] = Var1; //aqui eu armazeno o nome da variável que servirá de ponteiro pro vetor
							arrayPointerNames[nomeAuxID + "Acrescimo"] =  Var2; //essa é o " + 1"

							$$.traducao = trad + "\t" + nomeAuxID + " = (int*) malloc(" +
							auxiliarInteiro.valor + " * sizeof(int));\n";
 							addVarToGlobalTabSym(nomeAuxID, $2.label, "empty", "int*");
							//addVarToGlobalTempVector("\tint* " + nomeAuxID + ";\n");
						}

						| GADECLARATION TK_TIPO_FLOAT
						{
							string nomeAuxID = genLabel();
							stackVectors.push("\tfree(" + nomeAuxID + ");\n");
							variable auxiliarInteiro = searchForVariable($1.label);
							map_linhas[nomeAuxID] = tamanho_linhas;

							string nome0 = "Auxiliar" + to_string(valorAuxiliar++);
							string nome1 = "Auxiliar" + to_string(valorAuxiliar++);
							string nomeAux = genLabel();
							addVarToTabSym(nomeAux, nome0, "0", "int");
							string acrescimo = genLabel();
							addVarToTabSym(acrescimo, nome1, "1", "int");
							addVarToTempVector("\tint " + nomeAux + ";\n");
							addVarToTempVector("\tint " + acrescimo + ";\n");
							Variable Var1 = searchForVariable(nome0); //usar "var" como nome de variável é uma decisão horrível
							Variable Var2 = searchForVariable(nome1); //seja quem for lendo isso, não faça o que eu fiz
							string trad = "\t" + Var1.nome + " = 0;\n" + "\t" + Var2.nome + " = 1;\n";
							arrayPointerNames[nomeAuxID] = Var1; //aqui eu armazeno o nome da variável que servirá de ponteiro pro vetor
							arrayPointerNames[nomeAuxID + "Acrescimo"] =  Var2; //essa é o " + 1"

							$$.traducao = trad + "\t" + nomeAuxID + " = (float*) malloc(" +
							auxiliarInteiro.valor + " * sizeof(float));\n";
 							addVarToGlobalTabSym(nomeAuxID, $2.label, "empty", "float*");
							//addVarToGlobalTempVector("\tint* " + nomeAuxID + ";\n");
						}

						| GADECLARATION TK_TIPO_CHAR
						{
							string nomeAuxID = genLabel();
							stackVectors.push("\tfree(" + nomeAuxID + ");\n");
							variable auxiliarInteiro = searchForVariable($1.label);
							map_linhas[nomeAuxID] = tamanho_linhas;

							string nome0 = "Auxiliar" + to_string(valorAuxiliar++);
							string nome1 = "Auxiliar" + to_string(valorAuxiliar++);
							string nomeAux = genLabel();
							addVarToTabSym(nomeAux, nome0, "0", "int");
							string acrescimo = genLabel();
							addVarToTabSym(acrescimo, nome1, "1", "int");
							addVarToTempVector("\tint " + nomeAux + ";\n");
							addVarToTempVector("\tint " + acrescimo + ";\n");
							Variable Var1 = searchForVariable(nome0); //usar "var" como nome de variável é uma decisão horrível
							Variable Var2 = searchForVariable(nome1); //seja quem for lendo isso, não faça o que eu fiz
							string trad = "\t" + Var1.nome + " = 0;\n" + "\t" + Var2.nome + " = 1;\n";
							arrayPointerNames[nomeAuxID] = Var1; //aqui eu armazeno o nome da variável que servirá de ponteiro pro vetor
							arrayPointerNames[nomeAuxID + "Acrescimo"] =  Var2; //essa é o " + 1"

							$$.traducao = trad + "\t" + nomeAuxID + " = (char*) malloc(" +
							auxiliarInteiro.valor + " * sizeof(char));\n";
 							addVarToGlobalTabSym(nomeAuxID, $2.label, "empty", "char*");
							//addVarToGlobalTempVector("\tint* " + nomeAuxID + ";\n");
						}

						//matrizes
						|	GMDECLARATION TK_TIPO_INT
						{
							string nomeAuxID = genLabel();
							stackVectors.push("\tfree(" + nomeAuxID + ");\n");

							string nome0 = "Auxiliar" + to_string(valorAuxiliar++);
							string nome1 = "Auxiliar" + to_string(valorAuxiliar++);
							string nomeAux = genLabel();
							addVarToTabSym(nomeAux, nome0, "0", "int");
							string acrescimo = genLabel();
							addVarToTabSym(acrescimo, nome1, "1", "int");
							addVarToTempVector("\tint " + nomeAux + ";\n");
							addVarToTempVector("\tint " + acrescimo + ";\n");
							Variable Var1 = searchForVariable(nome0); //usar "var" como nome de variável é uma decisão horrível
							Variable Var2 = searchForVariable(nome1); //seja quem for lendo isso, não faça o que eu fiz
							string trad = "\t" + Var1.nome + " = 0;\n" + "\t" + Var2.nome + " = 1;\n";
							arrayPointerNames[nomeAuxID] = Var1; //aqui eu armazeno o nome da variável que servirá de ponteiro pro vetor
							arrayPointerNames[nomeAuxID + "Acrescimo"] =  Var2; //essa é o " + 1"

							$$.traducao = trad + "\t" + nomeAuxID + " = (int*) malloc(" +
							to_string(elementos_matriz) + " * sizeof(int));\n";
							addVarToGlobalTabSym(nomeAuxID, $2.label, "empty", "int*");
						}

						|	GMDECLARATION TK_TIPO_FLOAT
						{
							string nomeAuxID = genLabel();
							stackVectors.push("\tfree(" + nomeAuxID + ");\n");

							string nome0 = "Auxiliar" + to_string(valorAuxiliar++);
							string nome1 = "Auxiliar" + to_string(valorAuxiliar++);
							string nomeAux = genLabel();
							addVarToTabSym(nomeAux, nome0, "0", "int");
							string acrescimo = genLabel();
							addVarToTabSym(acrescimo, nome1, "1", "int");
							addVarToTempVector("\tint " + nomeAux + ";\n");
							addVarToTempVector("\tint " + acrescimo + ";\n");
							Variable Var1 = searchForVariable(nome0); //usar "var" como nome de variável é uma decisão horrível
							Variable Var2 = searchForVariable(nome1); //seja quem for lendo isso, não faça o que eu fiz
							string trad = "\t" + Var1.nome + " = 0;\n" + "\t" + Var2.nome + " = 1;\n";
							arrayPointerNames[nomeAuxID] = Var1; //aqui eu armazeno o nome da variável que servirá de ponteiro pro vetor
							arrayPointerNames[nomeAuxID + "Acrescimo"] =  Var2; //essa é o " + 1"

							$$.traducao = trad + "\t" + nomeAuxID + " = (float*) malloc(" +
							to_string(elementos_matriz) + " * sizeof(float));\n";
							addVarToGlobalTabSym(nomeAuxID, $2.label, "empty", "float*");
						}

						| GMDECLARATION TK_TIPO_CHAR
						{
							string nomeAuxID = genLabel();
							stackVectors.push("\tfree(" + nomeAuxID + ");\n");

							string nome0 = "Auxiliar" + to_string(valorAuxiliar++);
							string nome1 = "Auxiliar" + to_string(valorAuxiliar++);
							string nomeAux = genLabel();
							addVarToTabSym(nomeAux, nome0, "0", "int");
							string acrescimo = genLabel();
							addVarToTabSym(acrescimo, nome1, "1", "int");
							addVarToTempVector("\tint " + nomeAux + ";\n");
							addVarToTempVector("\tint " + acrescimo + ";\n");
							Variable Var1 = searchForVariable(nome0); //usar "var" como nome de variável é uma decisão horrível
							Variable Var2 = searchForVariable(nome1); //seja quem for lendo isso, não faça o que eu fiz
							string trad = "\t" + Var1.nome + " = 0;\n" + "\t" + Var2.nome + " = 1;\n";
							arrayPointerNames[nomeAuxID] = Var1; //aqui eu armazeno o nome da variável que servirá de ponteiro pro vetor
							arrayPointerNames[nomeAuxID + "Acrescimo"] =  Var2; //essa é o " + 1"

							$$.traducao = trad + "\t" + nomeAuxID + " = (char*) malloc(" +
							to_string(elementos_matriz) + " * sizeof(char));\n";
							addVarToGlobalTabSym(nomeAuxID, $2.label, "empty", "char*");
						}
						;

ARRAYDECLARATION : TK_DEC_VAR TK_ID '[' E ']'
								 {
									 $$ = $4;
									 stringstream tamanho;

									 tamanho << $4.traducao;
									 string temp;
									 int found;

									 while(!tamanho.eof()){
										 tamanho >> temp;

										 if(stringstream(temp) >> found){
											 cout << "______________ " << found << endl;
											 tamanho_linhas = found;
										 }
									 }
								 }
								 ;

GADECLARATION 	: TK_DEC_VAR TK_GLOBAL TK_ID '[' E ']'
								{
									$$ = $5;
									stringstream tamanho;

									tamanho << $5.traducao;
									string temp;
									int found;

									while(!tamanho.eof()){
										tamanho >> temp;

										if(stringstream(temp) >> found){
											cout << "______________ " << found << endl;
											tamanho_linhas = found;
										}
									}
								}

MATRIXDECLARATION: TK_DEC_VAR TK_ID '[' E ']' '[' E ']'
								 {
									 $$ = $4;

									 //cout << $4.traducao << $7.traducao << endl;

									 stringstream v0;
									 stringstream v1;

									 v0 << $4.traducao;
									 v1 << $7.traducao;

									 string temp;

									 int found0;
									 int found1;

									 while(!v0.eof()){

										 //extraindo palavra por palavra
										 v0 >> temp;

										 //checando se a palavra é um inteiro ou não
										 if(stringstream(temp) >> found0){
											 //cout << found0 << " ";
										 }
									 }

									 while(!v1.eof()){

										 v1 >> temp;

										 if(stringstream(temp) >> found1){
											 //cout << found1 << " ";
										 }
									 }

									 cout << "tamanho linhas " << found0 << "\ntamanho colunas " << found1 << endl;
									 tamanho_linhas = found0;
									 tamanho_colunas = found1;
									 elementos_matriz = tamanho_linhas * tamanho_colunas;
									 cout << "quantidade de elementos na matriz: " << elementos_matriz << endl;
									 //tamanho_vetor =  found0 * found1;
								 }
								 ;

GMDECLARATION		:	TK_DEC_VAR TK_GLOBAL TK_ID '[' E ']' '[' E ']'
								{
									$$ = $5;

									//cout << $4.traducao << $7.traducao << endl;

									stringstream v0;
									stringstream v1;

									v0 << $5.traducao;
									v1 << $8.traducao;

									string temp;

									int found0;
									int found1;

									while(!v0.eof()){

										//extraindo palavra por palavra
										v0 >> temp;

										//checando se a palavra é um inteiro ou não
										if(stringstream(temp) >> found0){
											//cout << found0 << " ";
										}
									}

									while(!v1.eof()){

										v1 >> temp;

										if(stringstream(temp) >> found1){
											//cout << found1 << " ";
										}
									}

									cout << "tamanho linhas " << found0 << "\ntamanho colunas " << found1 << endl;
									tamanho_linhas = found0;
									tamanho_colunas = found1;
									elementos_matriz = tamanho_linhas * tamanho_colunas;
									cout << "quantidade de elementos na matriz: " << elementos_matriz << endl;
									//tamanho_vetor =  found0 * found1;
								}

IF			  : TK_IF {valorLoops++; stackLoops.push(valorLoops);} E TK_THEN COMANDOS TK_END_LOOP ';'
					{
						if($3.tipo != "bool"){
							yyerror("Condicional sem declaração do tipo booleano!\n");
						}

						else{
							string auxVar = "temp" + to_string(valorVar++);
							addVarToTempVector("\tint " + auxVar + ";\n");
							string auxVar2 = "!" + $3.label;
							$$.traducao = "\n//if\n\tcomeco" + to_string(stackLoops.top()) + ":\n" + $3.traducao + "\n\t" + auxVar + " = " +
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


TERNARIO	: TK_TERN {valorLoops++; stackLoops.push(valorLoops);} E '?' COMANDO ':' COMANDO ';'
			
			{
				if($3.tipo != "bool"){
				yyerror("Condicional sem declaração do tipo booleano!\n");
			}

			else{
				string auxVar = "temp" + to_string(valorVar++);
				addVarToTempVector("\tint " + auxVar + ";\n");
				string auxVar2 = "!" + $3.label;
				$$.traducao = "\n//if\n\tcomeco" + to_string(stackLoops.top()) + ":\n" + $3.traducao + "\n\t" + auxVar + " = " +
				auxVar2 + ";\n\tif(" + auxVar + ") goto final" + to_string(stackLoops.top()) + ";\n" + $5.traducao + ";\tgoto final" + to_string(stackLoops.top() + 1) + ";\n" + "\n\tfinal" + to_string(stackLoops.top()) + ":\n" + $5.traducao + "\tfinal" + to_string(stackLoops.top() + 1) + ":\n";
				stackLoops.pop();
			}
			};


WHILE 		: TK_WHILE {valorLoops++; stackLoops.push(valorLoops); stackCommands.push("while");} '(' E ')' BLOCO
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

DOWHILE		: TK_DO {valorLoops++; stackLoops.push(valorLoops); stackCommands.push("while");} BLOCO TK_WHILE '(' E ')'
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
					;

FOR 		  :	TK_FOR {valorLoops++; stackLoops.push(valorLoops); stackCommands.push("for");} FORMODES
				  {
				  	$$ = $3;
				  }

					| TK_FOR {valorLoops++; stackLoops.push(valorLoops); stackCommands.push("for");} '(' FORMODES ')'
					{
						$$ = $4;
					}

FORMODES 		: TK_ID ';' E ';' E BLOCO
						{

							variable Var = searchForVariable($3.label);

				  		if($3.tipo != "bool"){
				  			string msgError = "For somente itera sobre booleano! Tentativa de iterar sobre " + $3.tipo + " inválida!\n";
				  			yyerror(msgError);
				  		}

				  		string nomeVar = genLabel();
							addVarToTempVector("\tint " + nomeVar + ";\n");

				  		string auxVar = "temp" + to_string(valorVar++);
							addVarToTempVector("\tint " + auxVar + ";\n");

							string auxVar2 = genLabel();
							string auxVar3 = "!" + $3.label;

							$$.traducao = "\n//for\n" + $1.traducao + "\n\tcomeco" + to_string(stackLoops.top()) + ":\n" + $3.traducao + "\n\tloop" + to_string(stackLoops.top()) + ": " + auxVar + " = " +
							auxVar3 + ";\n\tif(" + auxVar + ") goto final" + to_string(stackLoops.top()) + ";\n" + $6.traducao + "\t" + nomeVar + " = " + Var.nome + " + 1;\n" +
							"\tgoto loop" + to_string(stackLoops.top()) + ";\n\tfinal" + to_string(stackLoops.top()) + ":\n";
							addVarToTabSym(nomeVar, $5.label, $5.traducao, $5.tipo);
							stackLoops.pop();
							contextoVariaveis.pop_back();
							mapAtual--;
						}

						| ATRIBUICAO ';' E ';' E BLOCO
					  {

							variable Var = searchForVariable($3.label);

					  	if($3.tipo != "bool"){
					  		string msgError = "For somente itera sobre booleano! Tentativa de iterar sobre " + $3.tipo + " inválida!\n";
					  		yyerror(msgError);
					  	}

						  string nomeVar = genLabel();
							addVarToTempVector("\tint " + nomeVar + ";\n");

						  string auxVar = "temp" + to_string(valorVar++);
							addVarToTempVector("\tint " + auxVar + ";\n");

							string auxVar2 = genLabel();
							string auxVar3 = "!" + $3.label;

							$$.traducao = "\n//for\n" + $1.traducao + "\n\tcomeco" + to_string(stackLoops.top()) + ":\n" + $3.traducao + "\n\tloop" + to_string(stackLoops.top()) + ": " + auxVar + " = " +
							auxVar3 + ";\n\tif(" + auxVar + ") goto final" + to_string(stackLoops.top()) + ";\n" + $6.traducao + $5.traducao + "\n" +
							"\tgoto loop" + to_string(stackLoops.top()) + ";\n\tfinal" + to_string(stackLoops.top()) + ":\n";
							stackLoops.pop();
							contextoVariaveis.pop_back();
							mapAtual--;
						}
						;

BREAK			: TK_BREAK
					{
						if(stackLoops.empty()){
							$$.traducao = "";
						}

						else if(stackCommands.empty()){
							yyerror("Break fora de um laço. Erro!");
						}

						else{
							$$.traducao = "\tgoto final" + to_string(stackLoops.top()) + ";// isso é um break\n";
						}
					}

CONTINUE 	:	TK_CONTINUE
					{
						if(stackLoops.empty()){
							$$.traducao = "";
						}

						else if(stackCommands.empty()){
							yyerror("Continue fora de um laço. Erro!");
						}

						else{
							$$.traducao = "\tgoto comeco" + to_string(stackLoops.top()) + ";// isso é um continue\n";
						}
					}

E 			  : E '+' E
			{
				$$.label = genLabel();

				if($$.tipo != "string" && $1.tipo != "string" && $3.tipo != "string")
				{
					cout << $$.tipo << endl;
					structAux aux = implicitConversion($1.tipo, $3.tipo, $1.label, $3.label);
					if(aux.varConvertida == $1.label){
						$$.traducao = $3.traducao + aux.implicita + "\t" + $$.label + " = " + aux.nomeVar + " + " + $3.label + ";\n";
					}
					else if(aux.varConvertida == $3.label){
						$$.traducao = $1.traducao + aux.implicita + "\t" + $$.label + " = " + $1.label + " + " + aux.nomeVar + ";\n";
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
					$$.traducao =  $3.traducao + aux.implicita + "\t" + $$.label + " = " + aux.nomeVar + " - " + $3.label + ";\n";
				}
				else if(aux.varConvertida == $3.label){
					$$.traducao = $1.traducao + aux.implicita + "\t" + $$.label + " = " + $1.label + " - " + aux.nomeVar + ";\n";
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
					$$.traducao =  $3.traducao + aux.implicita + "\t" + $$.label + " = " + aux.nomeVar + " * " + $3.label + ";\n";
				}
				else if(aux.varConvertida == $3.label){
					$$.traducao = $1.traducao + aux.implicita + "\t" + $$.label + " = " + $1.label + " * " + aux.nomeVar + ";\n";
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
					$$.traducao = $3.traducao + aux.implicita + "\t" + $$.label + " = " + aux.nomeVar + " / " + $3.label + ";\n";
				}
				else if(aux.varConvertida == $3.label){
					$$.traducao = $1.traducao + aux.implicita + "\t" + $$.label + " = " + $1.label + " / " + aux.nomeVar + ";\n";
				}
				else{ //se as duas variáveis são do mesmo tipo
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " / " + $3.label + ";\n";
				}
				addVarToTempVector("\t" + $$.tipo + " " + $$.label + ";\n");
			}

			| TK_ID TK_UN_SUM
			{

				variable Var = searchForVariable($1.label);
				$$.tipo = Var.tipo;
				$$.label = Var.nome;
				$$.traducao = "\t" + Var.nome + " = " + Var.nome + " + 1;\n";
			}

			| TK_ID TK_UN_SUB
			{

				variable Var = searchForVariable($1.label);
				$$.tipo = Var.tipo;
				$$.label = Var.nome;
				$$.traducao = "\t" + Var.nome + " = " + Var.nome + " - 1;\n";
			}

			| E '<' E
			{
				$$.label = genLabel();
				$$.tipo = "bool";
				//cout << "carai " << $1.traducao << endl;
				structAux aux = implicitConversion($1.tipo, $3.tipo, $1.label, $3.label);

				if(aux.varConvertida == $1.label){

					$$.traducao = $3.traducao + aux.implicita + "\t" + $$.label + " = " + aux.nomeVar + " < " + $3.label + ";\n";
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
					$$.traducao = $3.traducao + aux.implicita + "\t" + $$.label + " = " + aux.nomeVar + " > " + $3.label + ";\n";
				}
				else if(aux.varConvertida == $3.label){
					$$.traducao = $1.traducao + aux.implicita + "\t" + $$.label + " = " + $1.label + " > " + aux.nomeVar + ";\n";
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
					$$.traducao = $3.traducao + aux.implicita + "\t" + $$.label + " = " + aux.nomeVar + " <= " + $3.label + ";\n";
				}
				else if(aux.varConvertida == $3.label){
					$$.traducao = $1.traducao + aux.implicita + "\t" + $$.label + " = " + $1.label + " <= " + aux.nomeVar + ";\n";
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
					$$.traducao = $3.traducao + aux.implicita + "\t" + $$.label + " = " + aux.nomeVar + " >= " + $3.label + ";\n";
				}
				else if(aux.varConvertida == $3.label){
					$$.traducao = $1.traducao + aux.implicita + "\t" + $$.label + " = " + $1.label + " >= " + aux.nomeVar + ";\n";
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
				//cout << "SOU DO TIPO " << $$.tipo << endl;
				structAux aux = implicitConversion($1.tipo, $3.tipo, $1.label, $3.label);
				if(aux.varConvertida == $1.label){
					$$.traducao = $3.traducao + aux.implicita + "\t" + $$.label + " = " + aux.nomeVar + " == " + $3.label + ";\n";
				}
				else if(aux.varConvertida == $3.label){
					$$.traducao = $1.traducao + aux.implicita + "\t" + $$.label + " = " + $1.label + " == " + aux.nomeVar + ";\n";
				}
				else{ //se as duas variáveis são do mesmo tipo
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " == " + $3.label + ";\n";
				}

				addVarToTempVector("\tint " + $$.label + ";\n");
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
						$$.traducao = $3.traducao + aux.implicita + "\t" + $$.label + " = " + aux.nomeVar + " != " + $3.label + ";\n";
					}
					else if(aux.varConvertida == $3.label){
						$$.traducao = $1.traducao + aux.implicita + "\t" + $$.label + " = " + $1.label + " != " + aux.nomeVar + ";\n";
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
				addVarToTabSym($$.label, $$.label, $1.traducao, "int");
			}

			| TK_FLOAT
		 	{
				$$.label = "nomeTemporarioFloat" + to_string(valorTemp++);
				$$.tipo = "float";
				addVarToTempVector("\tfloat " + $$.label + ";\n");
				$$.traducao = "\t" + $$.label + " = " + $1.traducao + ";\n";
				addVarToTabSym($$.label, $$.label, $$.traducao, "float");
		 	}

			| TK_CHAR
			{
				$$.label = "nomeTemporarioChar" + to_string(valorTemp++);
				$$.tipo = "char";
				addVarToTempVector("\tchar "  + $$.label + ";\n");
				$$.traducao = "\t" + $$.label + " = " + $1.traducao + ";\n";
				addVarToTabSym($$.label, $$.label, $$.traducao, "char");
			}

			| TK_BOOL
			{
				$$.label = "nomeTemporarioBool" + to_string(valorTemp++);
				$$.tipo = "bool";
				addVarToTempVector("\tint " + $$.label + ";\n");
				$$.traducao = "\t" + $$.label + " = " + $1.traducao + ";\n";
				addVarToTabSym($$.label, $$.label, $$.traducao, "int");
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
				variable auxVar = searchForVariable($1.label);
				$$.label = auxVar.nome;
				$$.tipo = auxVar.tipo;
				$$.traducao = auxVar.valor;
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
	cout << "==== Valor atual: " << valorVar << endl;
}

string addVarToTabSym(string nomeGerado, string nomeDado, string conteudoVar, string tipoVar){

	checkForVariable(nomeDado);
	unordered_map<string, variable> tabSym = contextoVariaveis.back();
	cout << "\ntabSym antes " << (tabSym.empty() ? "is empty" : "is not empty" ) << endl;
	cout << "\nconteudo da variavel: " << conteudoVar << endl;
	unordered_map<string, variable>::const_iterator got = tabSym.find(nomeDado);

	if(got == tabSym.end()){

		variable Var2;

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

	else {

		return tabSym[nomeDado].nome;
	}

	return "";
}

string addVarToGlobalTabSym(string nomeGerado, string nomeDado, string conteudoVar, string tipoVar){

	checkForVariable(nomeGerado);
	cout << "\nglobalTabSym antes " << (globalTabSym.empty() ? "is empty" : "is not empty" ) << endl;
	unordered_map<string, variable>::const_iterator got = globalTabSym.find(nomeDado);

	if(got == globalTabSym.end()){

		variable Var;

		Var =	{
						.tipo = tipoVar,
				   	.nome = nomeGerado,
						.valor = conteudoVar
		  		};

		globalTabSym[nomeDado] = Var;
		cout << "globalTabSym depois " << (globalTabSym.empty() ? "is empty" : "is not empty" ) << endl;
		cout << "\nAdicionado " << globalTabSym[nomeDado].nome << " de tipo "<< globalTabSym[nomeDado].tipo <<" na tabela global de simbolos!\n" << endl;
		return globalTabSym[nomeDado].nome;
	}

	else {

		return globalTabSym[nomeDado].nome;
	}

	return "";
}

void printGlobalVariables(){

	unordered_map<string, variable> auxMap = globalTabSym;

	for (auto& it: globalTabSym){

		addVarToGlobalTempVector("\t" + it.second.tipo + " " + it.second.nome + ";\n");
	}

	printGlobalVector();
}

structAux implicitConversion(string tipo0, string tipo1, string nome0, string nome1){

	if(tipo0 == "float" && tipo1 == "int"){ //se a primeira variável for float e segunda for int

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

	else if(tipo0 == "int" && tipo1 == "float") //se a primeira variável for int e a segunda for float
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

  else if(tipo0 == "float" && tipo1 == "float") //se as duas são float
  {

	string nomeAuxID = "nomeTemporarioFloat" + to_string(valorTemp);
	string stringRetorno = "";
	structAux aux = {

						.implicita = stringRetorno,
						.nomeVar = nomeAuxID,
						.varConvertida = nome0
					};
	return aux;
   }

  else if(tipo0 == "int" && tipo1 == "int") //se as duas são int
  {

	string nomeAuxID = "nomeTemporarioInt" + to_string(valorTemp);
	string stringRetorno = "";
	structAux aux = {

						.implicita = stringRetorno,
						.nomeVar = nomeAuxID,
						.varConvertida = nome0
					};
	return aux;
  }

  else
  {
    yyerror("Nao e possivel realizar operacoes com tipos nao numericos!\n");
  }
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

void addVarToGlobalTempVector(string nomeVar)
{
	globalTempVector.push_back(nomeVar);
}

void printVector()
{
	for(auto i: tempVector)
	{
		cout << i;
	}
	cout << "\n\n" << endl;
}

void printGlobalVector()
{
	cout << "\n" << endl;
	for(auto i: globalTempVector)
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
	cout << "global " << (globalTabSym.empty() ? "is empty" : "is not empty" ) << endl;

	for(i; i > 0; i--){

		auxMap = auxVector.back();
		auxVector.pop_back();

		cout << "auxMap search iteração " << i << " " << (auxMap.empty() ? "is empty" : "is not empty" ) << endl;

		unordered_map<string, variable>::const_iterator got = auxMap.find(nome); //procuro a variável pelo nome no map mais interno

		if(got != auxMap.end()){ //se esse if for verdade, quer dizer que encontrei a variável no map

			cout << "\n\nEncontrada variável!\nNome: " << nome << "\nTipo: " << auxMap[nome].tipo <<"\nContexto: " << i << endl;
			cout << "Conteudo: " << auxMap[nome].valor << endl;
			variable auxVar = auxMap[nome];
			return auxVar; //se for, retorno essa variável
		}
	}
}

void checkForVariable(string nome){

	unordered_map<string, variable>::const_iterator got = (contextoVariaveis.back()).find(nome); //procuro a variável pelo nome no map mais interno

	if(got != (contextoVariaveis.back()).end()){ //se esse if for verdade, quer dizer que encontrei a variável no map

		string errorMessage = "\n\nEncontrada variável 2!\nNome: " + nome + "\nTipo: " + (contextoVariaveis.back())[nome].tipo + "\n";
		yyerror(errorMessage);
	}
}

variable searchForGlobalVariable(string nome){

	unordered_map<string, variable>::const_iterator got = globalTabSym.find(nome); //procuro a variável pelo nome no map mais interno

	if(got != globalTabSym.end()){ //se esse if for verdade, quer dizer que encontrei a variável no map

		cout << "\n\nEncontrada variável!\nNome: " << nome << "\nTipo: " << globalTabSym[nome].tipo << endl;
		cout << "Conteudo: " << globalTabSym[nome].valor << endl;
		variable auxVar = globalTabSym[nome];
		return auxVar; //se for, retorno essa variável
	}
}

string addElementsToArray(int tamanhoArray, string nomeArray){

	string trad = "";
	stack <string> auxStack;

	for(int i = 0; i < tamanhoArray; i++){ //uma das gambiarras mais criminosas que eu fiz
		auxStack.push(label_vet.top());
		label_vet.pop();
		tipo_vet.pop();
		trad_vet.pop();
	}

	variable Var1 = arrayPointerNames[nomeArray];
	variable Var2 = arrayPointerNames[nomeArray + "Acrescimo"];

	for(int i = 0; i < tamanhoArray; i++){
		trad = trad + "\t" + nomeArray + "[" + Var1.nome + "] = " + auxStack.top() +
		";\n\t" + Var1.nome + " = " + Var1.nome + " + " + Var2.nome + ";\n"; //olha que coisa feia
		auxStack.pop();
	}

	return trad;
}

void freeVectors(){

	string aux;
	while (!stackVectors.empty()){
		aux = stackVectors.top();
		stackVectors.pop();
		cout << aux << endl;
	}
	cout << "\n\n" << endl;
}
