#include <iostream>
#define max(a,b) (a>b ? a : b)

using namespace std;

int line[100][2];
int DP[100];

void bubble_sort(int length) {
    int temp_x;
    int temp_y;
    for(int i=length-1; i>0; i--){
        for(int j=0; j<i; j++){
            if(line[j+1][0] < line[j][0]){ 
                temp_x = line[j+1][0];
                temp_y = line[j+1][1];
                line[j+1][0] = line[j][0];
                line[j+1][1] = line[j][1];
                line[j][0] = temp_x;
                line[j][1] = temp_y;}
        }
    }
}

int main(){
    int N;
    int maxN = 0;
    cin >> N;
    for(int i=0; i<N; i++){
        scanf("%d %d", &line[i][0], &line[i][1]);
    }
    bubble_sort(N);
    for(int i=0; i<N; i++){
        DP[i] = 1;
        for(int j=0; j<i; j++){
            if(line[j][1] < line[i][1]){
                DP[i] = max(DP[i], DP[j]+1);
            }
        }
    }
    for(int i=0; i<N; i++){
        maxN = max(DP[i], maxN);
    }
    cout << N - maxN;
}