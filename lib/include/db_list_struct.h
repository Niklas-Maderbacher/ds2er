#ifndef DB_LIST_STRUCT_H
#define DB_LIST_STRUCT_H

#include "./db_table_struct.h"

typedef struct DBSingleLinkedList {
  struct DBTableSingleLinkedList *tables;
  struct DBSingleLinkedList *next_struct;
} DBSingleLinkedList;

#endif