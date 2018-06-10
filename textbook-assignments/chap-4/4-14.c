/* 
 * Macro expansion exercise
 */
#include <stdio.h>

#define swap(type, x, y) {type tmp = x; x = y; y = tmp;}

int main()
{
    int x = 1;
    int y = 2;
    printf("x = %d, y = %d\n", x, y);
    swap(int, x, y)
    printf("x = %d, y = %d\n", x, y);
    swap(int, x, y)
    printf("x = %d, y = %d\n", x, y);
    return 0;
}
