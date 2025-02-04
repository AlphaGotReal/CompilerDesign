#include <stdlib.h>
#include <string.h>

extern FILE *ofile;

struct Row;
struct SymbolTable;

static struct SymbolTable symbol_table;

struct Row {
  char *name;
  enum TokenType type;
  void *value;
};

struct SymbolTable {
  size_t length;
  size_t top;
  struct Row *rows;

  void (*init)(size_t length);
  void (*push)(struct Row *row);
  struct Row *(*pop)();
};

void init(size_t length) {
  symbol_table.length = length;
  symbol_table.top = 0;
  symbol_table.rows = (struct Row *) malloc(sizeof(struct Row) * length);
}

void push(struct Row *row) {
  if (symbol_table.top == symbol_table.length) 
    return ;
  symbol_table.rows[symbol_table.top++] = *row;
}

struct Row *pop() {
  symbol_table.top--;
  return symbol_table.rows + (symbol_table.top+1);
}

void display_table() {
  for (size_t t = 0; t < symbol_table.top; ++t) {
    fprintf(ofile, "name: %s\t", symbol_table.rows[t].name);
    fprintf(ofile, "type: %d\n", symbol_table.rows[t].type);
  }
}

