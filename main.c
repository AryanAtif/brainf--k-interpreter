#include <stdio.h>

void init_interpreter (char *code);
void operation (char operator, char **ptr);
// int count_occurence (char operator, char *code);

int main(int argc, char **argv)
{
  if (argc <= 1 || argc > 2) {printf ("Usage: ./interpreter.o <brainfuck code>.\n"); return 1;}


  init_interpreter (&(*argv[1]));
  return 0;
}

void init_interpreter (char *code)
{
  printf ("You entered: %s\n", code);

  int i = 0;
  char memory_block = 0;
  char *ptr_memory_block = &memory_block;

  while (code[i] != '\0')
  {
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

