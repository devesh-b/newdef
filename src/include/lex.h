# define TT_NUM "NUMBER"
# define TT_PLUS "+"
# define TT_MINUS "-"
# define TT_MUL "*"
# define TT_DIV "/"
# define TT_LPAREN "("
# define TT_RPAREN ")"
# define TT_RFPAREN "}"
# define TT_LFPAREN "{"
# define TT_WHILE "while"
# define TT_IF "if"
# define TT_ELSE "else"
# define TT_SEMICOLON ";"
# define TT_COMMA ","
# define TT_NOT "!"
# define TT_EQ "="
# define TT_P "print"
# define TT_BSLASH "\\"
# define TT_OP "OUTPUT"
# define TT_VAR "var" 

typedef struct _lex{
    /* data */
    char type[100],val[100];
    double num;
}Lex;

void lex(char *);
int make_number(char *,int ,int );
int word(char *,int ,int );
Lex* lex_main();

typedef struct _fin{
    char val[1000];
    char type[100];
}F;