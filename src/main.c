#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "parser.h"
#include "symbol_table.h"

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

  symbol_table.init = init;
  symbol_table.push = push;
  symbol_table.pop = pop;

  ofile = stdout;

  curr_token.identifier_value = (char *) malloc(sizeof(char) * IDSIZE);
  clear();

  file = fopen(argv[1], "r");
  c = getc(file);

  symbol_table.init(10);

  bool skip = false;
  while (skip || get_next_token()) {
    skip = false;
    // display_token(curr_token);
    if (curr_token.type == TOK_INT || curr_token.type == TOK_CHAR || curr_token.type == TOK_FLOAT) {
      skip = true;
      enum TokenType type = curr_token.type;
      clear();
      get_next_token();
      if (curr_token.type == TOK_IDENTIFIER) {
        struct Row row;
        row.name = (char *) malloc(sizeof(char) * IDSIZE);
        strcpy(row.name, curr_token.identifier_value);
        row.type = type;
        push(&row);
      }
      continue;
    }
    if (curr_token.type == TOK_EOF) {
      break ;
    }
    // fprintf(ofile, "\n");
    clear();
  }

  display_table();

  return 0;
}

