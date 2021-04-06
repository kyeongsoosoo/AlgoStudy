#include <stdio.h>

int min[1000][3];
int houseN;
int R,G,B;

int find_min(int a, int b, int c){
    if( a<=b && a<=c)
        return a;
    else if( b<=a && b<=c)
        return b;
    else if(c<=a && c<=b)
        return c;
    return 0;
}

int main() {
    scanf("%d", &houseN);
    scanf("%d %d %d", &min[0][0],&min[0][1],&min[0][2]);
    for(int i=1; i<houseN; i++){
        scanf("%d %d %d", &R, &G, &B);
        for(int j=0; j<3; j++){
            if(j==0){
                if(min[i-1][1]<=min[i-1][2])
                    min[i][0] += min[i-1][1] + R;
                else
                    min[i][0] += min[i-1][2] + R;
            }
            else if(j==1){
                if(min[i-1][0]<=min[i-1][2])
                    min[i][1] += min[i-1][0] + G;
                else
                    min[i][1] += min[i-1][2] + G;
            }
            else{
                if(min[i-1][0]<=min[i-1][1])
                    min[i][2] += min[i-1][0] + B;
                else
                    min[i][2] += min[i-1][1] + B;
            }
        }
    }
    printf("%d\n",find_min(min[houseN-1][0],min[houseN-1][1],min[houseN-1][2]));
}