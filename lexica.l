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

{DELIM} 	{}

"main"		{return TK_MAIN;}

"int"		{return TK_TIPO_INT;}

"char"      {return TK_TIPO_CHAR;}

"float"     {return TK_TIPO_FLOAT;}

"var"       {return TK_DEC_VAR;}

"if"        {return TK_IF;}

"then"      {return TK_THEN;}

"else"      {return TK_ELSE;}

"end"       {return TK_END_LOOP;}

"while"     {return TK_WHILE;}

"do"        {return TK_DO;}

"(f)"		{return TK_CONV_FLOAT;}

"(i)"		{return TK_CONV_INT;}

"bool"		{yylval.label = "bool"; yylval.traducao = yytext; return TK_TIPO_BOOL;}

"string"	{return TK_STRING;}

[(){}[\];,=<>!|&]	{ return *yytext; }

"<="        {return TK_LE;}

">="        {return TK_HE;}

"=="        {return TK_EQ;}

"!="        {return TK_DIFF;}

[+\-*/]		{ return *yytext; }

{NUM}		{ yylval.traducao = yytext; return TK_NUM;  }
{BOOL}		{ yylval.traducao = yytext; return TK_BOOL; }
{CHAR}      { yylval.traducao = yytext; return TK_CHAR; }
{STRING}	{ yylval.traducao = yytext; return TK_STRING;}
{REAL}      { yylval.traducao = yytext; return TK_FLOAT;}
{ID}		{ yylval.label = yytext; return TK_ID;      }

.			{ *yytext; }

%%
