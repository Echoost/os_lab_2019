#include "swap.h"

void Swap(char *left, char *right)
{
    char temp = *left;  // Сохраняем значение, на которое указывает left
    *left = *right;     // Присваиваем значение, на которое указывает right
    *right = temp;      // Присваиваем сохраненное значение в right
}
