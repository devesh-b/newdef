#include<stdio.h>
#include<string.h>
#include"include/lex.h"
Lex arr[250];

Lex* lex_main(char exp[])
{
    lex(exp);
    return arr;
}

void lex(char *e)
{
    int pos=0,npos=0;
    char current=*(e+pos);
    while (*(e+pos))
    {
        current =*(e+pos);
        switch (current)
        {
        case ' ':
        case '\t':
        case '\n':
            pos+=1;
            break;
        case '\"':
            strcpy(arr[npos].type,"QUOTES");
            strcpy(arr[npos].val,"\"");
            pos+=1;
            npos+=1;
            break;
        case '+':
            strcpy(arr[npos].type,"PLUS");
            strcpy(arr[npos].val,TT_PLUS);
            pos+=1;
            npos+=1;
            break;
        case '\\':
            strcpy(arr[npos].type,"BACK SLASH");
            strcpy(arr[npos].val,TT_BSLASH);
            pos+=1;
            npos+=1;
            break;
        case '-':
            strcpy(arr[npos].type,"MINUS");
            strcpy(arr[npos].val,TT_MINUS);
            pos+=1;
            npos+=1;
            break;
        case '*':
            strcpy(arr[npos].type,"MULTIPLICATION");
            strcpy(arr[npos].val,TT_MUL);
            pos+=1;
            npos+=1;
            break;
        case '/':
            strcpy(arr[npos].type,"DIVISION");
            strcpy(arr[npos].val,TT_DIV);
            pos+=1;
            npos+=1;
            break;
        case ';':
            strcpy(arr[npos].type,"SEMI COLON");
            strcpy(arr[npos].val,TT_SEMICOLON);
            pos+=1;
            npos+=1;
            break;
        case ',':
            strcpy(arr[npos].type,"COMMA");
            strcpy(arr[npos].val,TT_COMMA);
            pos+=1;
            npos+=1;
            break;
        case '!':
            strcpy(arr[npos].type,"NOT");
            strcpy(arr[npos].val,TT_NOT);
            pos+=1;
            npos+=1;
            break;
        case '=':
            strcpy(arr[npos].type,"EQUALS");
            strcpy(arr[npos].val,TT_EQ);
            pos+=1;
            npos+=1;
            break;
        case '(':
            strcpy(arr[npos].type,"LEFT PARANTHESIS");
            strcpy(arr[npos].val,TT_LPAREN);
            pos+=1;
            npos+=1;
            break;
        case ')':
            strcpy(arr[npos].type,"RIGHT PARANTHESIS");
            strcpy(arr[npos].val,TT_RPAREN);
            pos+=1;
            npos+=1;
            break;
        case '}':
            strcpy(arr[npos].type,"RIGHT FLOWER PARANTHESIS");
            strcpy(arr[npos].val,TT_RFPAREN);
            pos+=1;
            npos+=1;
            break;
        case '{':
            strcpy(arr[npos].type,"LEFT FLOWER PARANTHESIS");
            strcpy(arr[npos].val,TT_LFPAREN);
            pos+=1;
            npos+=1;
            break;
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        case '.':
            pos = make_number(e,pos,npos);
            npos+=1;
            break;
        default:
            if(current>=97 && current<=122 || (current>=65 && current<=90))
            {
                break;
            }
            printf("Error: wrong symbol \"%c\"\n",current);
            pos+=1;
            break;
        }
    if((current>=97 && current<=122) || (current>=65 && current<=90))
        {
            pos=word(e,pos,npos);
            npos+=1;
        }
    }
}

int make_number(char *exp,int p, int npos)
{
    char num_str[100]="h";
    int dot_count = 0,i=0;
    while ((*(exp+p) != '\0') && ((*(exp+p)>='0' && *(exp+p)<='9') || *(exp+p)=='.'))
    {
        if (*(exp+p) == '.')
        {
            if (dot_count == 1)
             break;
            dot_count += 1;
            num_str[i]= '.';
            i++;
        }
        else
        {
            num_str[i]=*(exp+p);
            i++;
        }
        p+=1;
    }
    strcpy(arr[npos].type,TT_NUM);
    strcpy(arr[npos].val,num_str);
    sscanf(num_str,"%lf",&arr[npos].num);
    return p;
}
int word(char *exp,int p,int npos)
{
    char s[100]="";
    int i=0;
    while (((*(exp+p)>=97 && *(exp+p)<=122) || (*(exp+p)>=65 && *(exp+p)<=90)) && (*(exp+p)!='\0'))
    {
        s[i]=*(exp+p);
        i++;
        p+=1;
    }
    
    if(strcmp(TT_P,s)==0)
        strcpy(arr[npos].type,TT_P);
    else if (strcmp(TT_WHILE,s)==0)
        strcpy(arr[npos].type,TT_WHILE);
    else if (strcmp(TT_IF,s)==0)
        strcpy(arr[npos].type,TT_IF);
    else if (strcmp(TT_ELSE,s)==0)
        strcpy(arr[npos].type,TT_ELSE);
    else if (strcmp(TT_VAR,s)==0)
        strcpy(arr[npos].type,TT_VAR);
    else
        strcpy(arr[npos].type,TT_OP);
    strcpy(arr[npos].val,s);
    return p;
}