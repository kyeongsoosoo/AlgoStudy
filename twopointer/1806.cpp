#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> V;

int N;
long long S;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> S;

    int start = 0;
    int to = 0;
    
    int len = 111111;

    int tmp_n;
    for(int i=0; i<N; i++){
        cin>>tmp_n;
        V.push_back(tmp_n);
    }

    long long sum  = V[0];

    while(to < N && start <= to ){
        if(len == 1) break;
       if(sum < S)
            sum += V[++to];
        else if (sum == S){
            len = min(len, to - start + 1);
            sum += V[++to];
        }
        else if(sum > S){
            len = min(len, to - start + 1);
            sum -= V[start++];
        }
    }

    if(len == 111111)
        cout << 0 << '\n';
    else
        cout << len;
}