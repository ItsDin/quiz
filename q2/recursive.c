/* FIXME: Recursive version and add boundary case */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#define SIZE 1000
char smallest_character(char str[], char c)
{
    char result;
    if(!str[0]) {
        assert(!"empty array");
        return 0;
    } else {
        if( !((str[0]>='A' && str[0]<='Z') || (str[0]>='a' && str[0]<='z'))) {
            return 0;
        } else {
            if(str[0] > c) {
                return str[0];
            } else {
                result = smallest_character(str+1, c);
                if(result > c) {
                    return result;
                } else {
                    return str[0];
                }
            }
        }
    }
}

int main()
{
    char smallest;
    smallest = smallest_character("cck", 'f');
    printf("Smallest character : %c\n", smallest);
    return 0;
}
