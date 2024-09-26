#include <stdio.h>

#include "db_table_struct.h"
#include "read_file.h"

int main() {
  FILE *my_file = read_file(
      "d:\\Coding\\first-db-application-with-orm-nge9nike\\code\\backend.py");
  DBTableSingleLinkedListNode my_data = extract_documentation_py(my_file);
  close_file(my_file);

  printf("%s\n", my_data.table_name);
}