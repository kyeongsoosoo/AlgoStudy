#include <stdio.h>

int level_position[16];

int cnt = 0;


int checkQ(int position, int level){
    if(level == 0 ) return 1;
    for(int i=0; i<level; i++){
        if(level_position[i] == position) return 0;
        else if(position - level_position[i] == level-i) return 0;
        else if(position - level_position[i] == (level-i)*(-1)) return 0;
    }
    return 1;
}

void nQueen(int position, int level, int goal){
    if(!checkQ(position, level)) return;
    if(level+1 == goal) {
        cnt++;
        return;
        }
    for(int i=0; i<goal; i++){
        level_position[level] = position;
        nQueen(i, level+1, goal);
    }
    return;
}



int main() {
    int goal;
    scanf("%d", &goal);
    for(int i=0; i<goal;i++)
        nQueen(i,0, goal);
    printf("%d", cnt);
}