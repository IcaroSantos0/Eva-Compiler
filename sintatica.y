%{
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
using std::string;
using std::getline;


#define YYSTYPE atributos

using namespace std;

typedef struct{

	string tipo;
	string nome;
} variable;

struct atributos
{
	string label;
	string traducao;
};

int valorVar = 0;
unordered_map <string, variable> tabSym;

int yylex(void);
void yyerror(string);
string genLabel();
string addVarToTabSym(string nomeDado);
%}

%token TK_NUM
%token TK_MAIN TK_ID TK_TIPO_INT TK_TIPO_BOOL
%token TK_FIM TK_ERROR

%start S

%left '+' '-'
%left '*' '/'
%left '(' ')'

%%

S 			: TK_TIPO_INT TK_MAIN '(' ')' BLOCO
			{
				cout << "/*Compilador Eva*/\n" << "#include <iostream>\n#include<string.h>\n#include<stdio.h>\nint main(void)\n{\n" << $5.traducao << "\treturn 0;\n}" << endl;
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
			;

ATRIBUICAO 	: TK_ID '=' E
			{
				string nomeAuxID = addVarToTabSym($1.label);
				$$.traducao = $3.traducao + "\t" + nomeAuxID + " = " + $3.label + ";\n";
			}

E 			: E '+' E
			{
				$$.label = genLabel();
				$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " + " + $3.label + ";\n";
			}

			| E '-' E
			{
				$$.label = genLabel();
				$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " - " + $3.label + ";\n";
			}

			| E '*' E
			{
				$$.label = genLabel();
				$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " * " + $3.label + ";\n";
			}

			| E '/' E
			{
				$$.label = genLabel();
				$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " / " + $3.label + ";\n";
			}

			| '(' E ')'
			{
				$$.label = genLabel();
				$$.traducao = $2.traducao + "\t" + $$.label + " = " + '(' + $2.label + ')' + ";\n";
			}

			| TK_NUM
			{
				$$.label = genLabel();
				$$.traducao = "\t" + $$.label + " = " + $1.traducao + ";\n";
			}

			| TK_ID
			{
				$$.label = genLabel();
				$$.traducao = "\t" + $$.label + " = " + $1.traducao + ";\n";
			}

			/*| TK_TIPO_BOOL COMANDO
			{
				$$.label = genLabel();

			}*/
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

	std::string nomeVar = "temp";
	valorVar++;
	return nomeVar + to_string(valorVar);
}

string addVarToTabSym(string nomeDado){

	unordered_map<string, variable>::const_iterator got = tabSym.find(nomeDado);
	string nomeGerado;

	if(got == tabSym.end()){
		
		variable Var;
		nomeGerado = genLabel();
		
		Var = {
				.tipo = "a", 
			   	.nome = nomeGerado
			  };

		tabSym[nomeDado] = Var;
		return tabSym[nomeDado].nome;
	} 

	else { 
		
		return tabSym[nomeDado].nome;
	}

	return "";
}
