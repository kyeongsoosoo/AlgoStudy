#include <iostream>
#include <map>
#include <cstring>
using namespace std;

int t, n;
int pre[1010];
int in[1010];
map<int, int> mp;
 
void go(int pre_start, int pre_end, int in_start, int in_end) {
 
    if (pre_start > pre_end || in_start > in_end) return;
 
    int root = pre[pre_start];
    int pos = mp[pre[pre_start]];
 
    go(pre_start + 1, pre_start + (pos - in_start), in_start, pos - 1);
    go(pre_start + (pos - in_start) + 1, pre_end, pos + 1, in_end);
    cout << root << " ";
}

int main() {
    cin >> t;
    while (t--) {
        memset(pre, 0, sizeof(pre));
        mp.clear();
        cin >> n;

        for (int i = 1; i <= n; i++) 
            cin >> pre[i];

        for (int i = 1; i <= n; i++) {
            int x; 
            cin >> x;
            in[i] = x;
            mp[x] = i;
        }

        go(1, n, 1, n); 
        cout << "\n";
    }
}