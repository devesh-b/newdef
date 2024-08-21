#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include"include/evaluator.h"

void print_help()
{
    printf("Usage:\nhello.exe <filename>\n");
    exit(1);
}

char* get_file_contents(const char* filepath)
{
    char* buffer = 0;
    long length;

    FILE* f = fopen(filepath, "rb");

    if (f)
    {
        fseek(f, 0, SEEK_END);
        length = ftell(f);
        fseek(f, 0, SEEK_SET);

        buffer = calloc(length, length);

        if (buffer)
            fread(buffer, 1, length, f);

        fclose(f);
        return buffer;
    }

    printf("Error reading file %s\n", filepath);
    exit(2);
}

int main(int argc, char* argv[])
{
    if (argc >= 2){
        for(int i = 1; i < argc; i++)
        {
            int len = strlen(argv[i]);
            char* last_four = &argv[i][len-6];
            if(strcmp(last_four,".hello") == 0)
            {
                Lex *a=lex_main(get_file_contents(argv[i]));
                F *b=postfixafy(a);
                final(b);
            }

            else {
                print_help();
            }
        }
    }
    else {
        char input[1000];
        printf("Welcome to the newdef language v. 0.0.1!\n");
        while(1){
            printf(">>> ");
            fgets(input,1000, stdin);
            Lex *a=lex_main(input);
            F *b=postfixafy(a);
            final(b);
        }
    }
    return 0;
}
