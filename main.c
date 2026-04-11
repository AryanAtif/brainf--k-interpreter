#include <stdio.h>
#include <stdlib.h>

#define MIN_CODE_LENGTH 8

char* read_input ();
void init_interpreter (char const *code);
void operation (char *code, int char_index, size_t* code_memory, char **ptr, int *current_block);
void loop (char const *code, char **memory_blocks, int current_block);

int main(void)
{
  char *code = read_input();
  if (code == NULL) {printf ("Memory to the code array could not be allocated\n"); return 1;}
  init_interpreter (code);
  return 0; 
}

char* read_input ()
{
  size_t code_memory = MIN_CODE_LENGTH;
  char *code = malloc (code_memory);
  if (!code) { return NULL;}
  printf ("the size of code %zu\n", code_memory);

  printf ("Enter the brainfuck code: ");
  int i = 0;
  do 
  {
    if (i > (int)code_memory)  // to keep dynamically increasing the memory allocated to char* code
    {
      code = realloc(code, (i * MIN_CODE_LENGTH)); // increase the code length to 64
      code_memory += MIN_CODE_LENGTH;
      if (code == NULL) {return NULL;}
    }
    code[i] = getchar();
    i++;
  }
  while (code[i-1] != '\n'); // since we're incrementing i before the loop ends, code[i] would move over the last entered character.

  return code;
}

void init_interpreter (char const *code)
{
  printf ("You entered: %s\n", code);


  size_t memory_allocated = sizeof(char);
  char *ptr_memory_block = malloc (memory_allocated);
  *ptr_memory_block = 0; //making sure that the char starts with zero 
 
  if (!ptr_memory_block) {printf ("Memory allocation error.\n"); return;}
 

  int current_block = 0;
  int i = 0;
  while (code[i] != '\n')
  {
    operation (code, i, &memory_allocated, &ptr_memory_block, &current_block);
    i++;
  }
}

void operation (char *code, int char_index, size_t* code_memory, char **ptr, int *current_block) //  ptr -> *ptr -> **ptr
{
  char operator = code [char_index];
  switch (operator)
  {
    // +/- Operators
    case '+':
      (*((*ptr) + (*current_block)))++; // perform the '+' operation on the current memory block
      printf ("ptr%d = %d\n", *current_block, *((*ptr) + (*current_block)));
    break;
    case '-':
      (*((*ptr) + (*current_block)))--; // perform the '+' operation on the current memory block
      printf ("ptr%d = %d\n", *current_block, *((*ptr) + (*current_block)));
    break;

    // I/O Operators
    case '.':
      putchar(*((*ptr)+(*current_block))); // print the ASCII equivalent to the decimal number stored in the memory block
    break;
    case ',':
      *((*ptr) + *(current_block)) = getchar(); // stores the decimal equivalent to the ASCII character entered on the console as input 
    break;

    // > and < Operators
    case '>':
      (*current_block)++;  
      // if the memory allocated to the ptr_memory_block becomes insufficient for the next characters of the code
      if (*current_block > (*code_memory- 1)) // "-1" because we've already allocated 1 byte at the *ptr_memory_block definition
      {
        *code_memory = (*current_block) * sizeof(char);
        *ptr = realloc (*ptr, *code_memory);
        *((*ptr) + (*current_block)) = 0; //making sure that the char starts with zero 
      }
    break;
    
    case '<':
      *current_block--;
    break;
/*
    case '[':
      int i = 1;
      while ((operator + i) != ']')
      {
        operation (*(operator + i), ptr, memory_block);
        i++;
      }
*/
    default:
      break;
  }
}/*
void loop (char const **code, int char_index, char **memory_blocks, int current_block)
{
  while(true)
  {
    if (code[char_index] == '[') {void loop (code,  char_index,  memory_blocks, current_block)}
    else if (code[char_index] == ']') {break;}
    operation (code[char_index], &memory_blocks, current_block);
    char_index++;
  }
}*/
