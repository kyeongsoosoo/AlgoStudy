#include <iostream>
#include <vector>
#include <map>

using namespace std;

int N,S;
map<int,int> mp;
vector<int> v;
long long ans = 0;
int half;

void front(int idx, int sum){
    if(idx == half){
        mp[sum]++;
        return;
    }
    front(idx+1, sum);
    front(idx+1, sum + v[idx]);
}

void rear(int idx, int sum){
    if(idx == N){
        ans += mp[S-sum];
        return;
    }
    rear(idx+1, sum);
    rear(idx+1, sum + v[idx]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> S;

    half = N/2; v.resize(N);

    for(int i=0; i<N; i++) cin >> v[i];

    front(0,0);
    rear(half,0);

    if(S == 0 ) ans--;

    cout << ans;


}