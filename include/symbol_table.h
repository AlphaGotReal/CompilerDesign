
struct Row {
  char *name;
  enum TokenType type;
  void *value;
};

struct SymbolTable {
  size_t length;
  struct Row *rows;

  void (*init)(struct SymbolTable *self);
  void (*push)(struct SymbolTable *self, struct Row *row);
  void (*pop)(struct SymbolTable *self);
};

