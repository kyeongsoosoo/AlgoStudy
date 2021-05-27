#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,c,ans, a[33];
vector<int> v1,v2;

void dfs(int idx, int e, int sum, vector<int>& v){
    if(sum>c) return;
    if(idx > e) return v.push_back(sum);
    dfs(idx+ 1, e, sum, v);
    dfs(idx+ 1, e, sum + a[idx], v);
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> c;
    for(int i=0; i<n; i++) cin >> a[i];

    dfs(0, n/2 -1, 0, v1); 
    sort(v1.begin(), v1.end());
    dfs(n/2, n-1, 0, v2);
    sort(v2.begin(), v2.end());

    int e = v2.size() - 1 ;
    for(int idx =0; idx < v1.size(); idx++){
        while(e >= 0 && v1[idx] + v2[e] > c) e--;
        ans += e + 1;
    }

    cout << ans;

}