#ifndef DB_TABLE_STRUCT_H
#define DB_TABLE_STRUCT_H

#include "./db_column_struct.h"

typedef struct DBTableSingleLinkedListNode {
  char table_name;
  struct DBColumnSingleLinkedListNode *columns;
  struct DBTableSingleLinkedListNode *previous_struct;
} DBTableSingleLinkedListNode;

#endif
