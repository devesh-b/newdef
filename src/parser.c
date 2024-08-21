#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"include/parser.h"        
int fin_pos=0,start,end,c=0;

F* postfixafy(Lex a[])
{
    for (c=0;a[c].type[0]!='\0';c++);
    for(int i=0;i<c;i++)
    {
        int check=strcmp(a[i].type,TT_OP) && strcmp(a[i].type,TT_P) && strcmp(a[i].val,TT_COMMA) && strcmp(a[i].val,TT_EQ) && strcmp(a[i].val,TT_SEMICOLON);
        if(check && (!strcmp(a[i].type,TT_NUM) || !strcmp(a[i+1].type,TT_NUM)))
        {
            i=eval(a,i,f);
        } 
        else
        {
            add(a,i,f);
        }
    }
    return f;
}
int eval(Lex a[],int i,F f[])
{
    double output;
    char num[100];
    start=i;
    end=i;
    while (strcmp(a[i].type,TT_OP) && strcmp(a[i].type,TT_P) && strcmp(a[i].type,TT_COMMA) && strcmp(a[i].val,TT_SEMICOLON) && strcmp(a[i].type,TT_EQ) && i<c)
    {
      end=i;
      i++;
    }
    if((!strcmp(a[start-1].type,TT_P)))
    {
        end-=1;
        add(a,start,f);
        start+=1;
    }
    output=ans(a,start,end);
    sprintf(f[fin_pos].val,"%lf",output);
    strcpy(f[fin_pos].type,TT_NUM);
    fin_pos++;
    return end;
}
void add(Lex a[],int i,F f[])
{
    strcpy(f[fin_pos].val,a[i].val);
    strcpy(f[fin_pos].type,a[i].type);
    fin_pos++;
}
double ans(Lex a[],int s,int e)
{
    Lex exp[e-s+2];
    Lex STACK[e-s+1];
    Lex *e_ptr =exp;
    Lex *s_ptr = STACK;
    for(int i=s;i<=e;i++)
    {
        if(!strcmp(a[i].type,TT_NUM))
        {
            *e_ptr++=a[i];
        }
        else if(!(strcmp(a[i].val,TT_LPAREN)))
        {
            *s_ptr++=a[i];
        }
        else if(!strcmp(a[i].val,TT_RPAREN))
        {
            while(strcmp((s_ptr-1)->val,TT_LPAREN))
            {
                *e_ptr++=*--s_ptr;
            }
            s_ptr--;
        }
        else if(!(strcmp(a[i].val,TT_DIV) && strcmp(a[i].val,TT_MUL)))
        {
            while(!(strcmp((s_ptr-1)->val,TT_MUL) && strcmp((s_ptr-1)->val,TT_DIV)))
            {
                *e_ptr++ =*--s_ptr;
            }
            *s_ptr++=a[i];
        }
        else if(!(strcmp(a[i].val,TT_PLUS) && strcmp(a[i].val,TT_MINUS)))
        {
            while(!(strcmp((s_ptr-1)->val,TT_MUL) && strcmp((s_ptr-1)->val,TT_DIV) && strcmp((s_ptr-1)->val,TT_PLUS) && strcmp((s_ptr-1)->val,TT_MINUS)))
            {
                *e_ptr++=*--s_ptr;
            }
            *s_ptr++=a[i];
        }
    }
    while(s_ptr-STACK>0)
    {
        *e_ptr++=*--s_ptr;
    }
    while(exp[1].val[0]){
        int i=0;
        while(!strcmp(exp[i].type,TT_NUM))i++;
        if(!strcmp(exp[i].val,TT_PLUS)){
            exp[i-2].num=exp[i-2].num+exp[i-1].num;
            sprintf(exp[i-2].val,"%lf",exp[i-2].num);
            for(int j=i-1;j<e-s;j++){
                exp[j]=exp[j+2];
            }
        }else if(!strcmp(exp[i].val,TT_MINUS)){
            sprintf(exp[i-2].val,"%lf",exp[i-2].num=exp[i-2].num - exp[i-1].num);
            for(int j=i-1;j<e-s;j++){
                exp[j]=exp[j+2];
            }
        }else if(!strcmp(exp[i].val,TT_MUL)){
            sprintf(exp[i-2].val,"%lf",exp[i-2].num=exp[i-2].num*exp[i-1].num);
            for(int j=i-1;j<e-s;j++){
                exp[j]=exp[j+2];
            }
        }else if(!strcmp(exp[i].val,TT_DIV)){
            sprintf(exp[i-2].val,"%lf",exp[i-2].num=exp[i-2].num/exp[i-1].num);
            for(int j=i-1;j<e-s;j++){
                exp[j]=exp[j+2];
            }
        }
    }
    return exp[0].num;
}

