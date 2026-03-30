#include <stdio.h>
#include <stdlib.h>

#define MIN_CODE_LENGTH 64

char* read_input ();
void init_interpreter (char const *code);
void operation (char operator, char **ptr);
// int count_occurence (char operator, char *code);

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
  if (code == NULL) { return NULL;}
  printf ("the size of code %zu\n", code_memory);

  printf ("Enter the brainfuck code: ");
  int i = 0;
  do 
  {
    if (i > code_memory)  // to keep dynamically increasing the memory allocated to char* code
    {
      /*printf ("rellocating... %d\n", i-10);
      printf ("the size of code %zu\n", sizeof(code));*/
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

  int i = 0;
  char memory_block = 0;
  char *ptr_memory_block = &memory_block;

  while (code[i] != '\0')
  {
    printf ("\nSymbol %d counted: %c", i, code[i]);
    operation (code[i], &ptr_memory_block); //  <<--- Function call
    i++;
  }

}

void operation (char operator, char **ptr) // invalid char** pass
{
  switch (operator) 
  {
    // +/- Operators
    case '+':
      (**ptr)++; // perform the '+' operation on the current memory block
      break;
    case '-':
      (**ptr)--; // perform the '+' operation on the current memory block
      break;
    
    // >/< Operators
    case '>':
      *ptr++; // move the pointer to the memory block to the next memory block
      break;
    case '<':
      *ptr++; // move the pointer to the memory block to the next memory block
      break;

    // I/O Operators
    case '.':
      putchar(**ptr); // print the ASCII equivalent to the decimal number stored in the memory block
      break;
      
    case ',':
      **ptr = getchar(); // stores the decimal equivalent to the ASCII character entered on the console as input 
      break;

    default:
      break;
  }
}
