#include "revert_string.h"

void RevertString(char *str)
{
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++)
    {
        // Меняем местами символы
        char temp = str[i];
        str[i] = str[length - 1 - i];
        str[length - 1 - i] = temp;
    }
}
