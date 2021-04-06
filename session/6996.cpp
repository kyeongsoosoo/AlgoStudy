#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main(){
    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        string s1, s2;
        string c1, c2;
        cin >> s1;
        cin >> s2;
        c1 = s1;
        c2 = s2;
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());

        if(s1 == s2)
            cout << c1 << " & " << c2 << " are anagrams.\n";
           
        else 
            cout << c1 << " & " << c2 << " are NOT anagrams.\n";
            
    }
}