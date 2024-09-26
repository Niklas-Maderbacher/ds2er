#include "read_file.h"

FILE *read_file(const char *filepath) { return fopen(filepath, "r"); }

void close_file(const FILE *file) { fclose(file); }

struct DBTableSingleLinkedListNode
extract_documentation_py(const FILE *py_file) {
  // set new variable, that stores data of current line in it
  char buffer[256];
  // set new variables for checks
  // if the current line is in the docs,
  // the table name is saved
  // the current line is one line before cols data,
  // the current line is at cols data
  bool cur_line_at_docs = false;
  bool table_name_saved = false;
  bool cur_line_before_cols = false;
  bool cur_line_at_cols = false;
  // create node pointer instances for
  // all table nodes
  // DBSingleLinkedListNode *cur_db_data_node;
  DBTableSingleLinkedListNode *cur_table_node;
  DBColumnSingleLinkedListNode *cur_col_node;

  // set last node pointers to NULL
  // because first node can not have a previous node
  // cur_db_data_node->previous_node = NULL;
  cur_table_node->previous_node = NULL;
  cur_col_node->previous_node = NULL;

  // read file line for line
  while (fgets(buffer, sizeof(buffer), py_file) != NULL) {
    // remove leading spaces for easier work
    RemoveLeadingSpaces(buffer);

    // end of documentation, reset all values
    // checks, if line contains """,
    // the current line is in the docs,
    // the current line is at cols
    if ((strncmp(buffer, "\"\"\"", 3) == 0) && cur_line_at_docs &&
        cur_line_at_cols) {
      cur_line_at_docs = false;
      cur_line_at_cols = false;
      table_name_saved = false;

      // set table node in db data node
      // cur_db_data_node->table_node = cur_table_node;
      cur_table_node = CreateNewNode(cur_table_node, new_table_node);
      // cur_db_data_node = CreateNewNode(cur_db_data_node, new_data_node);

      /*
      // create new node
      // store current node in previous node variable of new node
      // and set current node to new node
      DBSingleLinkedListNode *new_db_data_node;
      new_db_data_node->previous_node = cur_db_data_node;
      cur_db_data_node = new_db_data_node;
      */
    }

    // skip one iteration of loop
    // line between documentation start point and actual data is not needed
    if (cur_line_before_cols && cur_line_at_docs) {
      cur_line_at_cols = true;
      cur_line_before_cols = false;
    }

    // save name of table
    // in docs its the second line after """
    // checks if current line is at docks,
    // the line does not contain """,
    // the line is not at cols,
    // and name of table is not safed
    if (cur_line_at_docs && strncmp(buffer, "\"\"\"", 3) != 0 &&
        !cur_line_at_cols && !table_name_saved) {
      cur_table_node->table_name = StoreUntilSpace(buffer);
      table_name_saved = true;
    }

    // save cols with name and type of table
    // in docs its the line after Args:
    // checks, if the line is in docs and actual at cols
    else if (cur_line_at_docs && cur_line_at_cols) {
      // DBColumnSingleLinkedListNode *new_db_col_node;
      cur_col_node->column_name = StoreUntilSpace(buffer);
      cur_col_node->column_type = ExtractValueInBrackets(buffer);

      // store old node in new nodes previous node variable
      // new_db_col_node->previous_node = cur_col_node;

      // set current node to new and empty node with exception,
      // that the previous node is stored in previous node variable
      // cur_col_node = new_db_col_node;
      cur_col_node = CreateNewNode(cur_col_node, new_col_node);
    }

    // check if docs begin
    // its the line right after the line contains "class"
    // but need to skip one more line, beause line between class and actual data
    // needed for table name is """
    if (strncmp(buffer, "class", 5) == 0 && !cur_line_at_docs) {
      cur_line_at_docs = true;
    }

    // check if current line is one line before the cols of the table begin
    // in docs its right after the line containing "Args:"
    else if (strncmp(buffer, "Args:", 5) == 0 && cur_line_at_docs) {
      cur_line_before_cols = true;
    }
  }
}
