%{
#include <string>

%}

ESPACO [ \t]
DIGITO [0-9]
LETRA [A-Za-z_]

DELIM {ESPACO}+
NUM {DIGITO}+
REAL {NUM}+("."{NUM}+)?
CHAR \'({LETRA}|{NUM})\'
ID {LETRA}({LETRA}|{NUM})*
BOOL "TRUE"|"FALSE"
STRING \'({LETRA}|{NUM})*\'

%%

"//".*      {}

"/*"([^*]|\*+[^*/])*\*+"/"  {}

{DELIM} 	{}

"main"		{return TK_MAIN;}

"int"		{return TK_TIPO_INT;}

"char"      {return TK_TIPO_CHAR;}

"float"     {return TK_TIPO_FLOAT;}

"var"       {return TK_DEC_VAR;}

"global"    {return TK_GLOBAL;}

"if"        {return TK_IF;}

"then"      {return TK_THEN;}

"else"      {return TK_ELSE;}

"end"       {return TK_END_LOOP;}

"while"     {return TK_WHILE;}

"do"        {return TK_DO;}

"for"		{return TK_FOR;}

"ternario"	{return TK_TERN;}

"entrada"	{return TK_ENTRADA;}

"saida"		{return TK_SAIDA;}

"(f)"		{return TK_CONV_FLOAT;}

"break" {return TK_BREAK;}

"continue" {return TK_CONTINUE;}

"(i)"		{return TK_CONV_INT;}

"++"    {return TK_UN_SUM;}

"--"    {return TK_UN_SUB;}

"+="    {return TK_NUN_SUM;}

"-="    {return TK_NUN_SUB;}

"*="    {return TK_NUN_MUL;}

"/="    {return TK_NUN_DIV;}

"bool"		{yylval.label = "bool"; yylval.traducao = yytext; return TK_TIPO_BOOL;}

"string"	{return TK_TIPO_STRING;}

[(){}[\];,=<>!|&]	{ return *yytext; }

"<="        {return TK_LE;}

">="        {return TK_HE;}

"=="        {return TK_EQ;}

"!="        {return TK_DIFF;}

[+\-*/]		{ return *yytext; }

{NUM}		{ yylval.traducao = yytext; return TK_NUM;  }
{BOOL}		{ yylval.traducao = yytext; return TK_BOOL; }
{CHAR}      { yylval.traducao = yytext; return TK_CHAR; }
{REAL}      { yylval.traducao = yytext; return TK_FLOAT;}
{STRING}	{ yylval.traducao = yytext; return TK_STRING;}
{ID}		{ yylval.label = yytext; return TK_ID;      }

.			{ *yytext; }

%%
