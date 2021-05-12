#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

int main() {
    
    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        stack<char> st;
        char paren[51];
        bool isCorrect = true;
        cin >> paren;
        int len = strlen(paren);
        for(int i=0; i<len; i++){
            
            if(paren[i] == '('){
                st.push('(');
            }
            else{
                if(st.empty()){
                    isCorrect = false;
                    break;
                }
                else{
                    st.pop();
                }
            }
        }
        if(!st.empty())
            isCorrect = false;
        if(isCorrect)
            cout << "YES\n";
        else
            cout << "NO\n";
        
    }
}