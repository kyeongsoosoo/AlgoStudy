#include <iostream>
#include <algorithm>

using namespace std;

int N,M;
int arr[100001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    sort(arr,arr+N);
    cin >> M;
    for(int i=0; i<M; i++){
        int tmp,mid;
        cin >> tmp;
        int from = 0, to = N-1;
        int ans = 0;
        while(from<=to){
            mid = (from+to) / 2;

            if(arr[mid] == tmp){
                ans = 1;
                break;
            }
            else if(arr[mid] > tmp)
                to = mid - 1;
            else if(arr[mid] < tmp)
                from = mid + 1;
        }
        cout << ans << '\n';
    }
}