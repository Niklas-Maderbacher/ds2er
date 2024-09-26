#ifndef READ_FILE_H
#define READ_FILE_H

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "db_column_struct.h"
#include "db_list_struct.h"
#include "db_table_struct.h"
#include "func_typedef.h"
#include "remove_blank_space.h"

const CreateNewNodeFunc new_col_node;
const CreateNewNodeFunc new_data_node;
const CreateNewNodeFunc new_table_node;

const GetPreviousNodeFunc prev_col_node;
const GetPreviousNodeFunc prev_data_node;
const GetPreviousNodeFunc prev_table_node;

/// @brief reads entire file and returns it as FILE pointer variable
/// @param filepath (const char*) path to file
/// @return (FILE*) returns entire file
FILE *read_file(const char *filepath) {}

/// @brief closes file
/// @param file
void close_file(const FILE *file) {}

/// @brief extract documentation from python file
/// @param py_file (FILE*) python file
/// @return SingleLinkedList including all tables with columns
struct DBSingleLinkedListNode extract_documentation_py(const FILE *py_file) {}

#endif
