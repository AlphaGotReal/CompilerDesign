#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#include "machine.h"

extern char c;
extern FILE *file;
 
/*
  Possible tokens:

  @identifier
  @number

  @keyword
  - if 
  - else 
  - while 
  - break 
  - continue 
  - return 
  - double 
  - void 

  @relation-op
  - ==
  - !=
  - >=
  - <=
  - >
  - <

  @arithmetic-op
  - +
  - *
  - / 
  - -
  - %

  @logical-op 
  - ||
  - && 
  - !
  - ^

  @assignment-op
  - =
  - +=
  - -=
  - *=
  - /=
  - %=
  
  @punctuation
  - (
  - )
  - {
  - }
  - [
  - ]
  - ;
  - ,
*/

enum TokenType {
  tok_eof = -1,
  tok_identifier = -2,
  tok_number = -3,
  tok_keyword = -4,
  tok_relop = -5,
  tok_arthop = -6,
  tok_logicalop = -7,
  tok_assop = -8,
  tok_punc = -9
};

struct Token {
  enum TokenType type;
  char *identifier_value;
  double numerical_value;
}; 

struct Token get_next_token() {
  
  struct Token token;
  token.identifier_value = (char *) malloc(100 * sizeof(char));

  c = getc(file);

  // consume white spaces and macros  
  while (c == ' ' || c == '\t' || c == '\n') {
    c = getc(file);
  }


  if (c == '#') {

    while (c != '\n') {
      c = getc(file);
    }

    if (c == EOF) {
      token.type = tok_eof;
      token.identifier_value = "EOF";
      return token;
    }else {
      return get_next_token();
    }

  }

  if (c == EOF) {
    token.type = tok_eof;
      token.identifier_value = "EOF";
    return token;
  }

  if (isalpha(c)) {
    int jumps;
    if (is_keyword(&jumps)) {
      token.type = tok_keyword;
      token.identifier_value = identifier;
      return token;
    }else {

      int ptr = 0;
      while (isalnum(c)) {
        token.identifier_value[ptr++] = c;
        c = getc(file);
      }

      token.type = tok_identifier;
      return token;
    } 
  }

  if (isdigit(c)) {
    int ptr = 0;
    while (isdigit(c) || c == '.') {
      token.identifier_value[ptr++] = c;
      c = getc(file);
    }

    token.type = tok_number;
    token.numerical_value = atof(token.identifier_value);
    return token;
  }

}

