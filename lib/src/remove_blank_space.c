#include "remove_blank_space.h"

void RemoveSpace(char *input) {
  int i, j = 0;
  int len = strlen(input); // Get the length of the input string

  // Iterate through each character in the input string
  for (i = 0; i < len; i++) {
    if (input[i] != ' ') {   // If the character is not a space
      input[j++] = input[i]; // Copy it to the next position
    }
  }
  input[j] = '\0'; // Null-terminate the modified string
}

void RemoveLeadingSpaces(char *input) {
  int i = 0, j = 0;

  // Skip leading spaces
  while (input[i] == ' ') {
    i++;
  }

  // Shift the rest of the string to the left
  while (input[i] != '\0') {
    input[j++] = input[i++];
  }

  // Null-terminate the new string
  input[j] = '\0';
}

char StoreUntilSpace(const char *input) {
  char firstWord[256];
  int i = 0;
  // Iterate through input and copy characters into firstWord until a space is
  // found
  while (input[i] != ' ' && input[i] != '\0') {
    firstWord[i] = input[i];
    i++;
  }
  firstWord[i] = '\0'; // Null-terminate the firstWord string

  return firstWord;
}

void ExtractValueInBrackets(const char *input, char *output) {
  int i = 0, j = 0;
  int len = strlen(input);

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
}
