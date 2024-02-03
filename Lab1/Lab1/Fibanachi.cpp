#include "Fibanachi.h"

int Fibanachi(int number)
{
    if (number == 1)
        return 0;
    if (number == 2 || number == 3)
        return 1;
    return Fibanachi(number - 1) + Fibanachi(number - 2);
}