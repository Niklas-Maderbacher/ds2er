#include "read_file.h"

FILE *read_file(const char *filepath) { return fopen(filepath, "r"); }

void close_file(const FILE *file) { fclose(file); }

struct DBSingleLinkedListNode extract_documentation_py(const FILE *py_file) {
  char buffer[256];
  bool cur_line_at_docs = false;
  bool table_name_saved = false;
  bool cur_line_before_cols = false;
  bool cur_line_at_cols = false;
  DBSingleLinkedListNode *cur_db_data_node;
  DBTableSingleLinkedListNode *cur_table_node;
  DBColumnSingleLinkedListNode *cur_col_node;

  // set last element pointers to NULLPOINTER
  cur_db_data_node->previous_node = NULL;
  cur_table_node->previous_node = NULL;
  cur_col_node->previous_node = NULL;

  while (fgets(buffer, sizeof(buffer), py_file) != NULL) {
    // remove leading spaces for easier work
    RemoveLeadingSpaces(buffer);

    // end of documentation, reset all values
    if ((strncmp(buffer, "\"\"\"", 3) == 0) && cur_line_at_docs &&
        cur_line_at_cols) {
      cur_line_at_docs = false;
      cur_line_at_cols = false;
      table_name_saved = false;

      // set table node in db data node
      cur_db_data_node->table_node = cur_table_node;

      // create new node
      // store current node in previous node variable of new node
      // and set current node to new node
      DBSingleLinkedListNode *new_db_data_node;
      new_db_data_node->previous_node = cur_db_data_node;
      cur_db_data_node = new_db_data_node;
    }

    // skip one iteration of loop
    // line between documentation start point and actual data is not needed
    if (cur_line_before_cols && cur_line_at_docs) {
      cur_line_at_cols = true;
      cur_line_before_cols = false;
    }

    if (cur_line_at_docs && strncmp(buffer, "\"\"\"", 3) != 0 &&
        !cur_line_at_cols && !table_name_saved) {
      cur_table_node->table_name = StoreUntilSpace(buffer);
      table_name_saved = true;
    }

    // done
    else if (cur_line_at_docs && cur_line_at_cols) {
      DBColumnSingleLinkedListNode *new_db_col_node;
      cur_col_node->column_name = StoreUntilSpace(buffer);
      cur_col_node->column_type = ExtractValueInBrackets(buffer);

      // store old node in new nodes previous node variable
      new_db_col_node->previous_node = cur_col_node;

      // set current node to new and empty node with exception,
      // that the previous node is stored in previous node variable
      cur_col_node = new_db_col_node;
    }

    // check if docs begin or end
    if (strncmp(buffer, "class", 5) == 0 && !cur_line_at_docs) {
      cur_line_at_docs = true;
    }

    else if (strncmp(buffer, "Args:", 5) == 0 && cur_line_at_docs) {
      cur_line_before_cols = true;
    }
  }
}
