all:
		clear
		lex -d lexica.l
		yacc -d sintatica.y
		g++ -o glf y.tab.c -ll 
		./glf < exemplo.eva
