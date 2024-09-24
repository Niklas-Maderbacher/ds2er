#include "read_file.h"

FILE *read_file(const char *filepath) { return fopen(filepath, "r"); }

void close_file(const FILE *file) { fclose(file); }

struct DBSingleLinkedList extract_documentation_py(const FILE *py_file) {
  char buffer[256];
  char name = NULL;
  char cols_name = NULL;
  bool in_docs = false;
  bool name_saved = false;
  bool at_cols = false;
  bool end_of_docs = false;
  DBSingleLinkedList entire_db;
  DBTableSingleLinkedList db_table;
  DBColumnSingleLinkedList db_column;

  // set last element pointers to NULLPOINTER
  entire_db.next_struct = NULL;
  db_table.next_struct = NULL;
  db_column.next_struct = NULL;

  while (fgets(buffer, sizeof(buffer), py_file) != NULL) {
    // end of documentation, reset all values
    if ((strncmp(buffer, "__tablename__", 13) == 0) && in_docs && at_cols) {
      in_docs = false;
      at_cols = false;
      name_saved = false;
    }

    char old_buffer[256];
    // remove leading spaces for easier work
    RemoveLeadingSpaces(buffer);

    if (in_docs && strncmp(buffer, "\"\"\"", 3) != 0 && !at_cols &&
        !name_saved) {
      db_table.table_name = StoreUntilSpace(buffer);
      name_saved = true;
    }

    else if (in_docs && at_cols) {
    }

    // check if docs begin or end
    if (strncmp(buffer, "class", 5) == 0 && !in_docs) {
      in_docs = true;
    }

    else if (strncmp(buffer, "Args:", 5) == 0 && in_docs) {
      at_cols = true;
    }
  }
}
