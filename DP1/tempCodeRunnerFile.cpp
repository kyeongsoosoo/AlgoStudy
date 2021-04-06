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

    for(int i=0; i<length1; i++){
        for(int j=0; j<length2; j++){
            if(word1[i] == word2[j]){
                DP[i][j] = DP[i-1][j-1] +1;
            }
            else{
                DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
            }
        }

    }
    cout << DP[length1-1][length2-1] << '\n';
}