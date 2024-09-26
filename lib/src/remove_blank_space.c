#include "remove_blank_space.h"

char *RemoveLeadingSpaces(char *input) {
  int i = 0;

  // Skip leading spaces
  while (input[i] == ' ') {
    i++;
  }

  return &(input[i]);
}

char *StoreUntilSpace(const char *input) {
  char firstWord[256];
  int i = 0;
  // Iterate through input and copy characters into firstWord until a space is
  // found
  while (input[i] != ' ' && input[i] != '\0') {
    firstWord[i] = input[i];
    i++;
  }
  firstWord[i] = '\0'; // Null-terminate the firstWord string

  return &firstWord;
}

char *ExtractValueInBrackets(const char *input) {
  int i = 0, j = 0;
  int len = strlen(input);
  char output[256];

  // Traverse to find the opening '('
  while (i < len && input[i] != '(') {
    i++;
  }

  // If opening '(' found, find the closing ')'
  if (i < len && input[i] == '(') {
    i++; // Move past '('
    while (i < len && input[i] != ')') {
      output[j++] = input[i++];
    }
  }

  // Null terminate the output string
  output[j] = '\0';

  return &output;
}
