#include <iostream>
#define max(a,b) (a>b ? a : b)

using namespace std;

string word1;
string word2;
int DP[1001][1001] = {{0,},};

int main() {
    cin >> word1;
    cin >> word2;
    int length1 = word1.length();
    int length2 = word2.length();

    for(int i=0; i<=length1; i++){
        DP[i][0] = 0;
    }
    for(int i=0; i<=length2; i++){
        DP[0][i] = 0;
    }

    for(int i=1; i<=length1; i++){
        for(int j=1; j<=length2; j++){
            if(word1[i-1] == word2[j-1]){
                DP[i][j] = DP[i-1][j-1] +1;
            }
            else{
                DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
            }
        }

    }
    cout << DP[length1][length2] << '\n';
}