#include <stdbool.h>
#include <string.h>

extern char c;
extern FILE *file;

static char *identifier;
static double number;

extern char *keywords[7];

bool is_keyword(int *jumps) {

  identifier = (char *) malloc(sizeof(char) * 100);
  for (int t = 0; t < 7; ++t) {
    
    bool flag = false;
    *jumps = 0;
    memset(identifier, 0, sizeof(char) * 100);
    
    while (keywords[t][*jumps] == c) {
      identifier[*jumps] = c;
      c = fgetc(file);
      ++(*jumps);
      if (keywords[t][*jumps] == '\0' && (c == ' ' || c == ',' || c == '\n' || c == '\t' || c == '(' || c == ')' || c == ';' || c == '{' || c == '}' || c == '[' || c == ']' || c == EOF)) {
        flag = true;
        break;
      }
    } 

    if (flag) {
      return true;
    }else {
      fseek(file, -(*jumps), SEEK_CUR);
    }

  }

  return false;
}



