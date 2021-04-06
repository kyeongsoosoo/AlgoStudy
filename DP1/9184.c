#include <stdio.h>

int solved[21][21][21];

int w(int a, int b, int c){
    if(a<=0 || b<= 0 || c<=0)
        return 1;
    else if(a > 20 || b>20 || c>20)
        return w(20,20,20);
    else if(a<b && b<c){
        if(solved[a][b][c] != 0) return solved[a][b][c];
        else return solved[a][b][c] =  w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
    }
    else{
        if(solved[a][b][c] != 0) return solved[a][b][c];
        else return solved[a][b][c] =   w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
    }
    return solved[a][b][c];
}


int main() {
    int a,b,c;
    while(1){
        scanf("%d %d %d", &a, &b, &c);
        if(a==-1 && b==-1 && c==-1) break;
        printf("w(%d, %d, %d) = %d\n", a,b,c,w(a,b,c));
    }

}