#ifndef INTERPRETER_H
#define INTERPRETER_H


#define MIN_CODE_LENGTH 8

char* read_input ();
void init_interpreter (char *code);
void operation (char *code, int *char_index, size_t* code_memory, char **ptr, int *current_block);
void loop (char *code, int *char_index, size_t* code_memory, char **ptr, int *current_block);
int get_closing_bracket (char *code, int close_index);

#endif 
