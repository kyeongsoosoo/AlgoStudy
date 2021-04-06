#include <stdio.h>

int main() {
    int caseN;
    int test;
    scanf("%d", &caseN);
    int student[caseN][2];
    for(int i=0; i<caseN; i++){
        scanf("%d %d", student[i], student[i]+1);
    }
    for (int i=0; i<caseN; i++) {
        test=1;
        for (int j=0; j<caseN; j++) {
            if(student[j][0]>student[i][0]&&student[j][1]>student[i][1]) test++;
        }
        printf("%d ", test);
    }

}