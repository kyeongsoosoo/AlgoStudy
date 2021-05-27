#include <iostream>
#include <algorithm>
#define MAX 100001

using namespace std;

int n,x;
int arr[MAX];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0; i< n; i++){
        int tmp;
        cin >> tmp;
        arr[i] = tmp;
    }

    sort(arr,arr+n);

    cin >> x;

    int from = 0;
    int to = n-1;
    int ans = 0;

    while(from < to){
        if(arr[from] > x) break;

        if(arr[from] + arr[to] == x) ans++;

        if(arr[from] + arr[to] <= x)
            from++;
        else if(arr[from] + arr[to] > x)
            to--;
    
    }

    cout << ans;
}