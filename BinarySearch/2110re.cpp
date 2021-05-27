#include <iostream>
#include <algorithm>

using namespace std;

int N,C;

int arr[200001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> C;

    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    sort(arr,arr+N);

    int start = 0;
    int end = arr[N-1];
    int mid;

    while(start <= end){
        mid = (start+end) / 2;

        int prev = arr[0];
        int cnt = 1;

        for(int i=0; i<N; i++){
            if(arr[i] - prev >= mid ){
                cnt++;
                prev = arr[i];
            }
        }


        if(cnt >= C)
            start = mid + 1;
        else
            end = mid - 1;
    }

    cout << end;

}