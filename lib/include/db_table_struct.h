#ifndef DB_TABLE_STRUCT_H
#define DB_TABLE_STRUCT_H

#include "./db_column_struct.h"

typedef struct DBTableSingleLinkedList {
  char table_name;
  struct DBColumnSingleLinkedList *columns;
  struct DBTableSingleLinkedList *next_struct;
} DBTableSingleLinkedList;

#endif
