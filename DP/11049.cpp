#include <iostream>
#define min(a,b) (a<=b ? a : b)
#define MAX 987654321

using namespace std;

pair<int, int> mat[501];
pair<int,int> dp[501][501];
int sum_mul[501][501];

int main(){
    int N;
    cin >> N;
    int row, col;
    pair<int,int> single;
    for(int i=0; i<N; i++){
        cin >> row >> col;
        single = make_pair(row,col);
        mat[i] = single;
        dp[i][i].first = row;
        dp[i][i].second = col;

    }
    for(int gap = 1; gap<N; gap++){
        for(int sta = 0; sta+gap <N; sta++){
            int end = sta+gap;
            sum_mul[sta][end] = MAX;
            dp[sta][end].first = dp[sta][sta].first;
            dp[sta][end].second = dp[end][end].second;
            for(int mid = sta; mid<=end; mid++){
                int mul = dp[sta][mid].first * dp[mid+1][end].first * dp[mid+1][end].second;
                sum_mul[sta][end] = min(sum_mul[sta][end],sum_mul[sta][mid] + sum_mul[mid+1][end] + mul);
            }

        }
    }
    cout << sum_mul[0][N-1];
}