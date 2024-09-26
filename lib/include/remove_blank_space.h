#ifndef REMOVE_BLANK_SPACE_H
#define REMOVE_BLANK_SPACE_H

#include <stdlib.h>
#include <string.h>

char *RemoveLeadingSpaces(char *input);

char *StoreUntilSpace(const char *input);

char *ExtractValueInBrackets(const char *input);

#endif