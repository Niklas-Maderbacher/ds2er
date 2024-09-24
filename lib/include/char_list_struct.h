#ifndef CHAR_LIST_STRUCT_H
#define CHAR_LIST_STRUCE_H

typedef struct CharSingleLinkedList {
  char value;
  struct CharSingleLinkedList *next_struct;
} CharSingleLinkedList;

#endif