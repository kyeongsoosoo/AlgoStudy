#include <stdio.h>
#include <stdlib.h>

int tableSize;
int teamA[20];
int teamB[20];
int table[20][20];
int min = 20000000;

void findTeam(int index, int level){
    
    if( level == tableSize/2){
        int sumA=0;
        int sumB=0;
        
        int teamBIndex =0;
        for(int i=0; i<tableSize; i++){
            int count=0;
            for(int j=0; j<level; j++){
                if(i == teamA[j]) count++;
            }
            if(count ==0) teamB[teamBIndex++]=i;
        }

        for(int i=0; i<level; i++){
            
            for(int j=0; j<level; j++){
                sumA += table[teamA[i]][teamA[j]];
                sumB += table[teamB[i]][teamB[j]];
            }
        }
        if( abs(sumA-sumB) <min ) min = abs(sumA-sumB);
        return;
    }

    for(int i=index; i<tableSize; i++){
        teamA[level] = i;
        findTeam(i+1, level+1);
    }
}

int main() {
    scanf("%d", &tableSize);
    for(int i=0;i<tableSize;i++){
        for(int j=0;j<tableSize;j++){
            scanf("%d", table[i]+j);
        }
    }
    findTeam(0,0); 
    printf("%d", min);
}