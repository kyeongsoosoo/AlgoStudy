#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N;
int Alpha[26];
vector<string> V;

bool Cmp(int A, int B){
    if (A > B) return true;
    return false;
}

int main (){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for(int i=0; i<N; i++){
        string str;
        cin >> str;
        V.push_back(str);
    }

    for(int i= 0; i< N; i++){
        string S = V[i];
        int len = S.length();
        int pow = 1;

        for(int j= len - 1; j>= 0; j--){
            int tmp = S[j] - 'A';
            Alpha[tmp] += pow;
            pow *= 10;
        }
    }
    sort(Alpha, Alpha+26, Cmp);

    int ans = 0;
    int num = 9;
    for (int i=0; i<26; i++){
        if(Alpha[i] ==0) break;
        ans = ans + (Alpha[i] * num--);
    }

    cout << ans;
}