%{
#include <stdio.h>
int word_count = 0;
%}
delim 			[  \t\n]
digit			[0-9]
letter                  [A-Za-z]
id                      {letter}+
%%
if {printf("key: %s\n",yytext);}
then {printf("key: %s\n",yytext);}
{id}	{printf("id: %s\n",yytext); word_count++;}
{delim}+ {}
{digit}+	{  printf("digit:%s\n",yytext);  }
%%
int main()
{
	
	
	
	yylex();
	
	printf("Total Count: %d",word_count);
	
	return 0;
}
