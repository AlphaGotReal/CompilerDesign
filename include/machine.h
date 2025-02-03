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
                 
/* word specific states */
bool state_if();
bool state_int();
bool state_else();
bool state_while();
bool state_continue();
bool state_char();
bool state_break();
bool state_return();
bool state_float();

bool state_add();
bool state_min();
bool state_mul();
bool state_div();
bool state_mod();

bool state_and();
bool state_and();
bool state_or();
bool state_not();
bool state_neq();

bool state_gt();
bool state_ge();
bool state_lt();
bool state_le();
bool state_assign();
bool state_equals();


