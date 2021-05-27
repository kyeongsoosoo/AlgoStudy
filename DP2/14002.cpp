#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int arr[1000];
int DP[1000];
vector<int> order[1000];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    int max_n = 0;
    int idx = 0;
    for(int i=0; i<N; i++){
        DP[i] = 1;
        order[i].push_back(arr[i]);
        for(int j=0; j<i; j++){
            if(arr[i] > arr[j]){
                if(DP[i] < DP[j] + 1){
                    DP[i] = DP[j] + 1;
                    order[i] = order[j];
                    order[i].push_back(arr[i]); 
                    if(DP[i] > max_n){
                        max_n = DP[i];
                        idx = i;
                    }      
                }
                
            }
        }
    }
    cout << DP[idx] << '\n';
    for(int i=0; i<order[idx].size(); i++){
        cout << order[idx][i] << " ";
    }
}