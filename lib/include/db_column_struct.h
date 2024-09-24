#ifndef DB_COLUMN_STRUCT_H
#define DB_COLUMN_STRUCT_H

typedef struct DBColumnSingleLinkedListNode {
  char column_name;
  char column_type;
  struct DBColumnSingleLinkedListNode *previous_struct;
} DBColumnSingleLinkedListNode;

#endif
