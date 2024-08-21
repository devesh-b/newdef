# newdef Language (WIP)
A custom programming language, built using C. It currently simulates the working of a programming language with basic operations such as printing the output on the terminal using variables and basic mathematical operations. `.hello` files are the code to be executed.


## Structure
- The input string either from file (or) interactive mode are sent as an argument to `lex.c` and hence is tokenized there.
- The tokenized data is stored in a structure with two fields: value, type.
- This structure is passed to next program, `parser.c` for evaluation and reduction of code.
- The reduced code is sent to the `evaluator.c` program to print the result on the terminal.

## To-do
- Flush datastream after every cycle in terminal mode
- Add new blocks such as `for`. `while`, etc
