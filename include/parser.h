#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define IDSIZE 100

extern char c;
extern FILE *file;

enum TokenType;
struct Token;
struct Token curr_token;

/* this function populates the curr_token variable */
/* this also functions as the input state in the state machine */
bool get_next_token();

/* clears the curr_token */
bool clear();

/* source */
enum TokenType {

  /* end of file token */
  TOK_EOF = -1,

  /* identifiers and numbers */
  TOK_IDENTIFIER = -2,
  TOK_NUMBER = -3,

  /* keywords */
  TOK_IF = -4,
  TOK_ELSE = -5, 
  TOK_WHILE = -6,
  TOK_CONTINUE = -7,
  TOK_BREAK = -8, 
  TOK_RETURN = -9, 
  TOK_INT = -10,
  TOK_FLOAT = -11,
  TOK_CHAR = -12,

  /* operators */
  TOK_DIV = 20,
  TOK_MUL = 19,
  TOK_ADD = 15,
  TOK_SUB = 14,
  TOK_MOD = 10,

  TOK_AND = 8,
  TOK_OR = 7,
  TOK_NOT = 6,

  TOK_ASS = -13,
  TOK_E = -14,
  TOK_NE = -15,
  TOK_GE = -16,
  TOK_LE = -17,
  TOK_GT = -18,
  TOK_LT = -19,

  /* punctuations */
  TOK_OP = -20, // open para (
  TOK_CP = -21,
  TOK_OB = -22, // open braket [
  TOK_CB = -24,
  TOK_OBR = -25, // open brace { 
  TOK_CBR = -26,
  TOK_COMMA = -27,
  TOK_SCOLON = -28

};

struct Token {
  enum TokenType type;
  char *identifier_value;
  double numerical_value;
  size_t ptr;
}; 

#include "machine.h"

bool get_next_token() {
  
  // clear the white spaces
  while (strchr(" \n\t", c)) c = getc(file);

  // remove the headers 
  if (c == '#') {
    while (c != '\n') c = getc(file); // consume the entire line
    return get_next_token();
  }

  switch (c) {
    case EOF:
      curr_token.type = TOK_EOF;
      return true;
    
    /* identifiers */
    case 'i':
      return state_i();
    case 'e':
      return state_e();
    case 'w':
      return state_w();
    case 'c':
      return state_c();
    case 'b':
      return state_b();
    case 'r':
      return state_r();
    case 'f':
      return state_f();

    /* single characters */ 
    case '+':
      return state_plus();
    case '-':
      return state_minus();
    case '*':
      return state_astrek();
    case '/':
      return state_slash();
    case '%':
      return state_percentage();
    case '(':
      return state_opara();
    case ')':
      return state_cpara();
    case '[':
      return state_obra();
    case ']':
      return state_cbra();
    case '{':
      return state_obrace();
    case '}':
      return state_cbrace();

    default:
      return false;
  }
}

bool clear() {
  curr_token.type = 0;
  memset(curr_token.identifier_value, '\0', sizeof(char) * IDSIZE);
  curr_token.numerical_value = 0;
  curr_token.ptr = 0;
}

