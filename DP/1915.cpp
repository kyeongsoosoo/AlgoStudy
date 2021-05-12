#include <iostream>

using namespace std;

int n,m;

int arr[1000][1000];

int DP[1000][1000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int max_n = 0;

    string temp;

    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> temp;
        for(int j=0; j<m; j++){
            arr[i][j] = temp[j] - '0';
            if( (i==0 || j==0) && arr[i][j] == 1){
                DP[i][j] = 1;
                max_n = 1;
            }
        }
    }

    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            if(arr[i][j] == 1){
                int len = min(DP[i][j-1], min(DP[i-1][j], DP[i-1][j-1]));
                DP[i][j] = len + 1;
                max_n = max(DP[i][j], max_n);
            }
        }
    }

    cout << max_n * max_n;
}