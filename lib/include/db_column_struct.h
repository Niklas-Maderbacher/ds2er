#ifndef DB_COLUMN_STRUCT_H
#define DB_COLUMN_STRUCT_H

typedef struct DBColumnSingleLinkedList {
  char column_name;
  char column_type;
  struct DBColumnSingleLinkedList *next_struct;
} DBColumnSingleLinkedList;

#endif
