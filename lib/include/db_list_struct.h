#ifndef DB_LIST_STRUCT_H
#define DB_LIST_STRUCT_H

#include "./db_table_struct.h"

typedef struct DBSingleLinkedListNode {
  struct DBTableSingleLinkedListNode *table;
  struct DBSingleLinkedListNode *previous_struct;
} DBSingleLinkedListNode;

#endif