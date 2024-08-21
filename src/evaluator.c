#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"include/evaluator.h"
int pos=0,k=0;
var finale[100];
int start=0,imp=0;
void final(F end[])
{
    for(pos=0;end[pos].type[0]!='\0';pos++);
    for(k=0;k<pos;k++)
    {
       if(!strcmp(end[k].type,TT_VAR))
       {
            start=k+1;
            strcpy(finale[imp].name,end[k+1].val);
            if(!strcmp(end[start+2].val,"\""))
            {
                while(strcmp(end[k].val,TT_SEMICOLON))k+=1;
                for(int s=start+3;s<k-1;s++)
                {
                strcat(finale[imp].val,end[s].val);
                }
            }
            else{
                for(int s=start+2;s<k+4;s++)
                {
                strcat(finale[imp].val,end[s].val);
                }
            }
            imp++;
       }
    }
    for(k=0;k<pos;k++)
    {
       if(!strcmp(end[k].val,TT_P))
       {
            int count=-1,flag=0;
            k+=2;
            start=k;
            while(strcmp(end[k].val,TT_RPAREN))
            {
                for(;count<imp;count++)
                {
                    if(!strcmp(end[k].val,finale[count].name))
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==1)
                {
                    printf("%s",finale[count].val);
                    flag=0;
                }
                else
                {
                    printf("%s",end[k].val);
                }
                k+=1;
                count=-1;
            }
            printf("\n");
       }  
    }
}