#include <stdio.h>

#include "interpreter.h"

int main(void)
{
  char *code = read_input();
  if (code == NULL) {printf ("Memory to the code array could not be allocated\n"); return 1;}
  init_interpreter (code);
  return 0; 
}
