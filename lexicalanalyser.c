
//AIM : Design and implement lexical analyzer for a given language using C and lexical analyzer  ignore redundant spaces , tabs and newlines. 
  
#include<string.h> 
#include<ctype.h> 
#include<stdio.h> 
int isOperator(char ch) 
{ 
int i, flag = 0; 
//char operators[6] = {'+','-','*','/','%','='}; 
char operators[] = "+-*/%="; 
for(i = 0; i < 6; ++i){ 
if(ch == operators[i]){
flag = 1; 
break; 
} 
} 
return flag; 
} 
void keyword(char str[10]) 
{ 
char keywords[32][10] = {"auto","break","case","char","const","continue","default", "do","double","else","enum","extern","float","for","goto", 
"if","int","long","register","return","short","signed", 
"sizeof","static","struct","switch","typedef","union", 
"unsigned","void","volatile","while" 
}; 
int i, flag = 0; 
for(i = 0; i < 32; ++i){ 
if(strcmp(keywords[i], str) == 0){ 
flag = 1; 
break; 
}
} 
if(flag == 1) 
{ 
printf("\n%s is a keyword",str); 
} 
else 
{ 
printf("\n%s is an identifier",str);; 
} 
} 
int main() 
{ 
FILE *f1,*f2,*f3,*f4; 
char c,str[10],st1[10]; 
int num[100],lineno=0,tokenvalue=0,i=0,j=0,k=0; printf("\nEnter the c program");/*gets(st1);*/ f1=fopen("input","w"); 
while((c=getchar())!='$') 
putc(c,f1); 
fclose(f1);
f1=fopen("input","r"); 
f2=fopen("identifier","w"); 
f3=fopen("specialchar","w"); 
f4=fopen("operatorchar","w"); 
while((c=getc(f1))!=EOF){ 
if(isdigit(c)) 
{ 
tokenvalue=c-'0'; 
c=getc(f1); 
while(isdigit(c)){ 
tokenvalue*=10+c-'0'; 
c=getc(f1); 
} 
num[i++]=tokenvalue; 
ungetc(c,f1); 
} 
else if(isalpha(c)) 
{ 
putc(c,f2); 
c=getc(f1); 
while(isdigit(c)||isalpha(c)||c=='_'||c=='$') { 
putc(c,f2); 
c=getc(f1);
} 
putc(' ',f2); 
ungetc(c,f1); 
} 
else if(c==' '||c=='\t') printf(" "); 
else 
if(c=='\n') 
lineno++; 
else{ 
if(isOperator(c)==1) { 
putc(c,f4); 
} 
else 
{ 
putc(c,f3); 
} 
} 
} 
fclose(f2); 
fclose(f3); 
fclose(f1); 
fclose(f4);
printf("\nThe digits in the program are : "); for(j=0;j<i;j++) 
printf("%d \t",num[j]); 
printf("\n"); 
f2=fopen("identifier","r"); 
k=0; 
printf("The keywords and identifiers are: "); while((c=getc(f2))!=EOF){ 
if(c!=' ') 
str[k++]=c; 
else 
{ 
str[k]='\0'; 
keyword(str); 
k=0; 
} 
} 
fclose(f2); 
f3=fopen("specialchar","r"); 
printf("\nSpecial characters are : "); while((c=getc(f3))!=EOF) 
printf("%c",c); 
printf("\n \t"); 
fclose(f3);
f4=fopen("operatorchar","r"); 
printf("\n operators are : "); 
while((c=getc(f4))!=EOF) 
printf("%c \t",c); 
printf("\n"); 
fclose(f4); 
printf("Total no. of lines are: %d",lineno); 
} 


