/*Iterative Version and add the boundary case  */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#define SIZE 1000
char smallest_character(char str[], char c){
	int i;
	//boundary case
	if(str[0]==0){
		assert(!"empty array");
		return 0;
	}else{
		for(i=0; i<strlen(str); i++){
			//English alphabet
			if( !((str[i]>='A' && str[i]<='Z') || (str[i]>='a' && str[i]<='z'))){
				return 0;
			}else{
				if(str[i] > c)
					return str[i];
			}
		}
	}
	return str[0];
}
int main(){
    char smallest;
    smallest = smallest_character("cck", 'f');
    printf("Smallest character : %c\n", smallest);
    return 0;
}
