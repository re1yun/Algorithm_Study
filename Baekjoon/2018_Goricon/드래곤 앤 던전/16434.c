#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int h_maxhp;
    int h_curhp;
    int h_atk;
}HERO;

int main(){
    int N;
    int dungeon[123456][3];
    HERO hero;
    scanf("%d %d", &N, &hero.h_atk);
    for(int i = 0; i < N; i++){
        scanf("%d %d %d", &dungeon[i][0], &dungeon[i][1], &dungeon[i][2]);
    }

    for(int i = 0; i < N; i++){
        switch(dungeon[i][0]){
            case 1:
                while(1){
                    int remaining = dungeon[i][2] - hero.h_atk;
                    if(remaining <= 0){
                        break;
                    }
                    hero.h_curhp -= dungeon[i][1];

                }
                
        }
    }
    return 0;
}