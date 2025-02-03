#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "parser.h"

char c;
FILE *file;

int main(int argc, char **argv) {

  file = fopen(argv[1], "r");

  return 0;
}

