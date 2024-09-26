#ifndef MUTATE_STRUCT_H
#define MUTATE_STRUCT_H

#include "./db_column_struct.h"
#include "./db_list_struct.h"
#include "./db_table_struct.h"
#include "./func_typedef.h"

void *SelectPreviousNode(void *node, GetPreviousNodeFunc get_previous_node) {
  return get_previous_node(node);
}

void *prev_data_node(void *node) {
  return ((DBColumnSingleLinkedListNode *)node)->previous_node;
}

/*
void *prev_data_node(void *node) {
    // Cast the void pointer to the appropriate type
    DBColumnSingleLinkedListNode *current_node = (DBColumnSingleLinkedListNode
*)node;

    // Check if the current node is NULL to avoid dereferencing a NULL pointer
    if (current_node == NULL) {
        return NULL;  // Return NULL if the current node is NULL
    }

    // Get the previous node
    DBColumnSingleLinkedListNode *prev_node = current_node->previous_node;

    // Free the current node
    free(current_node);

    // Return the previous node
    return prev_node;  // Return as void* to match the function signature
}
*/

void *prev_table_node(void *node) {
  return ((DBSingleLinkedListNode *)node)->previous_node;
}

void *prev_col_node(void *node) {
  return ((DBTableSingleLinkedListNode *)node)->previous_node;
}

void *CreateNewNode(void *node, CreateNewNodeFunc get_new_node) {
  return get_new_node(node);
}

void *new_data_node(void *node) {
  DBSingleLinkedListNode *new_node;
  new_node->previous_node = ((DBSingleLinkedListNode *)node);
  return node;
}

/*
void *new_data_node(void *node) {
    // Allocate memory for the new node
    DBSingleLinkedListNode *new_node = (DBSingleLinkedListNode
*)malloc(sizeof(DBSingleLinkedListNode));

    // Check if memory allocation was successful
    if (new_node == NULL) {
        return NULL;  // Return NULL if memory allocation failed
    }

    // Set the previous node pointer to the given node
    new_node->previous_node = (DBSingleLinkedListNode *)node;

    // Return the newly created node
    return new_node;
}
*/

void *new_table_node(void *node) {
  DBTableSingleLinkedListNode *new_node;
  new_node->previous_node = ((DBTableSingleLinkedListNode *)node);
  return node;
}

void *new_col_node(void *node) {
  DBColumnSingleLinkedListNode *new_node;
  new_node->previous_node = ((DBColumnSingleLinkedListNode *)node);
  return node;
}

#endif
