#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "parser.h"

char c;
FILE *file;
FILE *ofile;

void display_token() {
  fprintf(ofile, "type: %d\n", curr_token.type);
  fprintf(ofile, "identifier_value: %s\n", curr_token.identifier_value);
  fprintf(ofile, "numerical_value: %f\n", curr_token.numerical_value);
  fprintf(ofile, "ptr: %ld\n", curr_token.ptr);
}

int main(int argc, char **argv) {

  ofile = stdout;

  curr_token.identifier_value = (char *) malloc(sizeof(char) * IDSIZE);
  clear();

  file = fopen(argv[1], "r");
  c = getc(file);

  while (get_next_token()) {
    display_token(curr_token);
    if (curr_token.type == TOK_EOF) break;
    fprintf(ofile, "\n");
    clear();
  }

  return 0;
}

