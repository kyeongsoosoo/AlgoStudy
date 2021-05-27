#include <iostream>

using namespace std;

int N;
long long M;

int arr[10001];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for(int i=0; i<N; i++){
        int temp_n;
        cin >> temp_n;
        arr[i] = temp_n;
    }

    int ans = 0;
    int start =0;
    int end = 0;
    int partial_sum = 0;

    while(end <= N){
        if(partial_sum >= M)
            partial_sum -= arr[start++];
        else if (partial_sum < M)
            partial_sum += arr[end++];
        if(partial_sum == M)
            ans++;
    }

    cout << ans;
}