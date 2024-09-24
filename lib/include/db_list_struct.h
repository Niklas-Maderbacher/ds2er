#ifndef DB_LIST_STRUCT_H
#define DB_LIST_STRUCT_H

#include "./db_table_struct.h"

typedef struct DBSingleLinkedListNode {
  struct DBTableSingleLinkedListNode *table_node;
  struct DBSingleLinkedListNode *previous_node;
} DBSingleLinkedListNode;

#endif