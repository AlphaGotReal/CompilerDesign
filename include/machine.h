#include <stdbool.h>
#include <string.h>
#include <ctype.h>

extern char c;
extern FILE *file;
extern struct Token curr_token;

/* each state is a function here */
/* transition from one state to another can be thought 
 * of as recusrive calls of one function into another */
/* false is a sign of entering error state */

/* single character states */
bool state_i();
bool state_e();
bool state_w();
bool state_c();
bool state_b();
bool state_r();
bool state_f();
bool state_plus(); // +
bool state_minus(); // -
bool state_astrek(); // *
bool state_slash(); // /
bool state_percentage(); // %
bool state_aps(); // & 
bool state_pipe(); // |
bool state_ex(); // !
bool state_gr(); // >
bool state_ls(); // < 
bool state_eq(); // =

/* straight up return the token */
bool state_opara(); // open paranthesis
bool state_cpara();
bool state_obra(); // open braket
bool state_cbra();
bool state_obrace(); // open brace
bool state_cbrace();
bool state_comma();
bool state_scolcon(); // semi colcon

bool state_digit() {
  while (isdigit(c) || c == '.') {
    curr_token.identifier_value[curr_token.ptr++] = c;
    c = getc(file);
  }
  curr_token.type = TOK_NUMBER;
  curr_token.numerical_value = atof(curr_token.identifier_value);
  return true;
}

bool continue_state(char *string, enum TokenType type) {
  while (!strchr(" \n\t", c) && isalnum(c)) {
    curr_token.identifier_value[curr_token.ptr++] = c;
    c = getc(file);
  } 
  if (strcmp(curr_token.identifier_value, string) == 0) {
    curr_token.type = type;
    return true;
  }
  curr_token.type = TOK_IDENTIFIER;
  return true;
}

bool check_single_op(enum TokenType type) {
  c = getc(file);  
  if (isalnum(c) || strchr(" \n\t", c)) {
    curr_token.type = type;
    return true;
  }return false;
}

/* source */
bool state_i() {
  curr_token.identifier_value[curr_token.ptr++] = 'i';
  c = getc(file); // consume i 
  switch (c) {
    case 'f':
      return continue_state("if", TOK_IF);
    case 'n':
      return continue_state("int", TOK_INT);
    default:
      return continue_state("", TOK_IDENTIFIER);
  }
}

bool state_e() {
  return continue_state("else", TOK_ELSE);
}

bool state_w() {
  return continue_state("while", TOK_WHILE);
}


bool state_c() {
  curr_token.identifier_value[curr_token.ptr++] = 'c';
  c = getc(file); // consume c 
  switch (c) {
    case 'h':
      return continue_state("char", TOK_CHAR);
    case 'o':
      return continue_state("continue", TOK_CONTINUE);
    default:
      return continue_state("", TOK_IDENTIFIER);
  }
}

bool state_b() {
  return continue_state("break", TOK_BREAK);
}

bool state_r() {
  return continue_state("return", TOK_RETURN);
}

bool state_f() {
  return continue_state("float", TOK_FLOAT);
}

bool state_plus() {
  return check_single_op(TOK_ADD);
}

bool state_minus() {
  return check_single_op(TOK_SUB);
}

bool state_astrek() {
  return check_single_op(TOK_MUL);
}

bool state_slash() {
  c = getc(file); 
  if (c == '/') {
    curr_token.type = TOK_IGNORE;
    return true;
  }if (isalnum(c) || strchr(" \n\t", c)) {
    curr_token.type = TOK_DIV;
    return true;
  }return false;
}

bool state_percentage() {
  return check_single_op(TOK_MOD);
}

bool state_aps() {
  c = getc(file); // consume the & 
  if (c == '&') return check_single_op(TOK_AND);
  return false;
}

bool state_pipe() {
  c = getc(file); // consume the & 
  if (c == '|') return check_single_op(TOK_OR);
  return false;
}

bool state_ex() {
  c = getc(file); // consume the !
  enum TokenType type = TOK_NOT;
  if (c == '=') {
    type = TOK_NE;
    c = getc(file); // consume the =
  }
  if (isalnum(c) || strchr(" \n\t", c)) {
    curr_token.type = type;
    return true;
  }return false;
}

bool state_gr() {
  c = getc(file); // consume the >
  enum TokenType type = TOK_GT;
  if (c == '=') {
    type = TOK_GE;
    c = getc(file); // consume the =
  }
  if (isalnum(c) || strchr(" \n\t", c)) {
    curr_token.type = type;
    return true;
  }return false;
}

bool state_ls() {
  c = getc(file); // consume the <
  enum TokenType type = TOK_LT;
  if (c == '=') {
    type = TOK_LE;
    c = getc(file); // consume the =
  }
  if (isalnum(c) || strchr(" \n\t", c)) {
    curr_token.type = type;
    return true;
  }return false;
}

bool state_eq() {
  c = getc(file); // consume the =
  enum TokenType type = TOK_ASS;
  if (c == '=') {
    type = TOK_EQ;
    c = getc(file); // consume the =
  }
  if (isalnum(c) || strchr(" \n\t", c)) {
    curr_token.type = type;
    return true;
  }return false;
}

