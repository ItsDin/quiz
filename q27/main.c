/* Poker shuffle*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10000 //假設1萬次
void shuffle(int card[52]){
	int choose_card;
	int i;
	int tmp;
	for(i=0; i<52; i++){
		choose_card = rand() % 52;
		if(i != choose_card){
			tmp = card[i];
			card[i] = card[choose_card];
			card[choose_card] = tmp;
		}
	}
}

int main()
{
	int i, j;
	int Poker[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,
					14,15,16,17,18,19,20,21,22,23,24,25,26,
					27,28,29,30,31,32,33,34,35,36,37,38,39,
					40,41,42,43,44,45,46,47,48,49,50,51,52};
	for(j=0; j<SIZE; j++){
		shuffle(Poker);
		for(i=0; i<52; i++){
			printf("%d ",Poker[i]);
		}
		printf("\n");
	}
    return 0;
}
