#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;

    int start = 1; int last = K;
    int result = 0;
    while(start <= last) {
        int cnt = 0;
        int mid = (start + last) / 2;
        for(int i= 1; i<=N; i++)
            cnt += min(mid/i, N);
        if(cnt < K)
            start = mid + 1;
        else{
            result = mid;
            last = mid - 1;
        }
    }

    cout << result << '\n';
}