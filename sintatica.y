%{
#include <iostream>
#include <string>
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
std::unordered_map <std::string, variable> tabSym;

int yylex(void);
void yyerror(string);
string genLabel();
%}

%token TK_NUM
%token TK_MAIN TK_ID TK_TIPO_INT
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

COMANDOS: COMANDO COMANDOS
			|
			;

COMANDO 	: E ';'
			;

	E 		: E '+' E
			{
				$$.label = genLabel();
				$$.traducao = $1.traducao + $3.traducao + $$.label + " = " + $1.label + " + " + $3.label + ";\n";
			}

			| E '-' E
			{
				$$.label = genLabel();
				$$.traducao = $1.traducao + $3.traducao + $$.label + " = " + $1.label + " - " + $3.label + ";\n";
			}

			| E '*' E
			{
				$$.label = genLabel();
				$$.traducao = $1.traducao + $3.traducao + $$.label + " = " + $1.label + " * " + $3.label + ";\n";
			}

			| E '/' E
			{
				$$.label = genLabel();
				$$.traducao = $1.traducao + $3.traducao + $$.label + " = " + $1.label + " / " + $3.label + ";\n";
			}

			| '(' E ')'
			{
				$$.label = genLabel();
				$$.traducao = $2.traducao + $$.label + " = " + '(' + $2.label + ')' + ";\n";
			}

			| TK_NUM
			{
				$$.label = genLabel();
				$$.traducao = $$.label + " = " + $1.traducao + ";\n";
			}

			/*| TK_ID " = " E
			{

				$$.traducao = $3.traducao + $$.label + TK_ID + " = " + $$.label + ";\n";
			}*/

			| TK_ID
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
	return nomeVar + std::to_string(valorVar);
}
