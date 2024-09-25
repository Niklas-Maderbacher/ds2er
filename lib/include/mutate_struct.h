#ifndef MUTATE_STRUCT_H
#define MUTATE_STRUCT_H

#include "./db_column_struct.h"
#include "./db_list_struct.h"
#include "./db_table_struct.h"

typedef void *(*GetPreviousNodeFunc)(void *);

void *select_previous_node(void *node, GetPreviousNodeFunc get_previous_node) {
  return get_previous_node(node);
}

void *prev_data_node(void *node) {
  return ((struct DBColumnSingleLinkedListNode *)node)->previous_node;
}

void *prev_table_node(void *node) {
  return ((struct DBSingleLinkedListNode *)node)->previous_node;
}

void *prev_col_node(void *node) {
  return ((struct DBTableSingleLinkedListNode *)node)->previous_node;
}

#endif
