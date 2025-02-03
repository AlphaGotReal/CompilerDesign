#include <stdbool.h>
#include <string.h>

extern char c;
extern FILE *file;
extern struct Token curr_token;

/* each state is a function here */
/* transition from one state to another can be thought 
 * of as recusrive calls of one function into another */
/* false return is a sign of entering error state */

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
                 
bool continue_state(char *string, enum TokenType type) {
  while (!strchr(" \n\t", c)) {
    curr_token.identifier_value[curr_token.ptr++] = c;
    c = getc(file);
  } 
  printf("\n%s\n", curr_token.identifier_value);
  if (strcmp(curr_token.identifier_value, string) == 0) {
    curr_token.type = type;
    return true;
  }
  return false;
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
      return false;
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
      return false;
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


