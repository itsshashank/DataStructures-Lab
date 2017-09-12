#include<stdio.h>
#include<string.h>
#define max 100
int top=0;
char stack[max];
int priority(char a)
{
    if(a=='+'||a=='-')
        return 1;
    else if(a=='*'||a=='/')
        return 2;
    else if(a=='^')
        return 3;
    return 0;            
}
void push(char a)
{
    if(top<max)
    {
        stack[++top]=a;
    }
    else printf("overflow error!");
}
char pop()
{
    char a;
    if(top>0)
    {
     a=stack[top--];
    }
    //else printf("Underflow error {lower no.of operators} !");we need to take care that it doesnt underflow
    return a;
}
void main()
{
    int i,len;
 char exp[max],temp;
 printf("enter the expression:");
 scanf("%s",exp);
 len=strlen(exp);
 for(i=len;i>0;i--)
 {
     exp[i]=exp[i-1];
 }
 exp[0]='(';
 exp[len+1]=')';
 exp[len+2]='\0';
 printf("%s\n",exp);
 len=strlen(exp);
 for(i=0;i<len;i++)
 {
    if(isalnum(exp[i]))
        printf("%c",exp[i]);
    else if(exp[i]=='(')
    push(exp[i]);
    else if(exp[i]==')')
    {
        while((temp=pop())!='(')
            printf("%c",temp);
    }
    else
    { while(priority(exp[i])<priority(stack[top]))
        {
        printf("%c",pop());
        }
    push(exp[i]);
    }
 }
 printf("\n");   
}