#include <iostream>
#include <string>

int stack[50];

using namespace std;

bool isVPS(string s){
    int s_length  = s.size();
    int count = 0;

    for(int i=0; i<s_length; i++){
        if(s[i] == '(')
            count++;
        else{
            count--;
            if(count < 0)
                return false;
        }    
    }
    if(count == 0)
        return true;
    else
        return false;
}

int main() {
    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        string ex;
        
        cin >> ex;

        if(isVPS(ex))
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
}