#include <stdio.h>
#include <stdlib.h>

#define MIN_CODE_LENGTH 8

char* read_input ();
void init_interpreter (char const *code);
void operation (char operator, char **ptr, int memory_block);

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
    printf ("Symbol %d counted: %c\n", i, code[i]);
    if (code [i] == '>')
    {
      printf ("Inside the inc mem condition.\n");
      current_block++;  
      // if the memory allocated to the ptr_memory_block becomes insufficient for the next characters of the code
      if (current_block > (memory_allocated - 1)) // "-1" because we've already allocated 1 byte at the *ptr_memory_block definition
      {
        memory_allocated = current_block * sizeof(char);
        ptr_memory_block = realloc (ptr_memory_block, memory_allocated);
        *(ptr_memory_block + current_block) = 0; //making sure that the char starts with zero 
      }
    }
    else if (code [i] == '<') {current_block--;}
    else {operation (code[i], &ptr_memory_block, current_block);}
    i++;
  }

}

void operation (char operator, char **ptr, int memory_block) //  ptr -> *ptr -> **ptr
{
  switch (operator)
  {
    // +/- Operators
    case '+':
      (*((*ptr) + memory_block))++; // perform the '+' operation on the current memory block
      break;
    case '-':
      (*((*ptr) + memory_block))--; // perform the '+' operation on the current memory block
      break;

    // I/O Operators
    case '.':
      putchar(*(*ptr+memory_block)); // print the ASCII equivalent to the decimal number stored in the memory block
      break;
     
    case ',':

      *(*ptr+memory_block) = getchar(); // stores the decimal equivalent to the ASCII character entered on the console as input 
      break;

    default:
      break;
  }
  printf ("ptr%d = %d\n", memory_block, *((*ptr) + memory_block));
}
