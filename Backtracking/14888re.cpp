#include <iostream>
#define min -1000000001;
#define max 1000000001;

using namespace std;

int final_min = max;
int final_max = min;
int N;
int operand[100];
int given[4]; 

void track(int result, int level){
    if(level == N){
        if(result < final_min)
            final_min = result;
        if(result > final_max)
            final_max = result;
        return;
    }
    for(int i=0; i<4; i++){
        if(given[i] > 0){
            
            given[i]--;
            switch (i)
            {
            case 0:
                track(result+operand[level],level+1);
                break;
            case 1:
                track(result-operand[level],level+1);
                break;
            case 2:
                track(result*operand[level],level+1);
                break;
            case 3:
                track(result/operand[level],level+1);
                break;
            
            default:
                break;
            }
            given[i]++;
        }
    }
}


int main() {
    cin >> N;

    for(int i=0; i<N; i++){
        cin >> operand[i];
    }
    for(int i=0; i<4; i++){
        cin >> given[i];
    }
    track(operand[0],1);
    cout << final_max << '\n' << final_min;


}