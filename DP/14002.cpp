#include <iostream>
#include <vector>


using namespace std;
int DP[1000];
int arr[1000];
vector<int> perm[1000];
vector<int> ans;

int N;

int max_n = 1;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for(int i=0; i< N; i++){
        cin >> arr[i];
    }

    for(int i=0; i<N; i++){
        DP[i] = 1;
        perm[i].push_back(arr[i]);
        for(int j=0; j<i; j++){
            if(arr[i] > arr[j]){
                if(DP[i] < DP[j] + 1){
                    perm[i].clear();
                    perm[i] = perm[j];
                    perm[i].push_back(arr[i]);
                    DP[i] = DP[j] + 1;
                }
            }
        }
        if(ans.size() < perm[i].size()){
            ans = perm[i];
        }
    }
    cout << ans.size() << '\n';

    for(int i=0 ; i< ans.size(); i++){
        cout << ans[i] << " ";
    }

}