#include <stdio.h>

int main(void)
{
    const int container[] = { 2, 1, 4, 6, 8, 666, 0 };

    const int* begin;
    const int* end = container+7;

    for (begin = container; begin != end; begin++)
        printf("%d\n", *begin);

    return 0;
}
