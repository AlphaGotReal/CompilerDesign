#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "parser.h"

char c;
FILE *file;

char *keywords[7];

int main(int argc, char **argv) {

  keywords[0] = "if";
  keywords[1] = "else";
  keywords[2] = "while";
  keywords[3] = "break";
  keywords[4] = "continue";
  keywords[5] = "return";
  keywords[6] = "double";
  keywords[7] = "void";

  file = fopen(argv[1], "r");

  struct Token token;
  while (true) {
    token = get_next_token();
    printf("%d: %s\n", token.type, token.identifier_value);
    if (token.type == tok_eof) {
      break;
    }
  }

  return 0;
}

