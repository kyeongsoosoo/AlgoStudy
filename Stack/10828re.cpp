#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

int main(){
    stack<int> st;
    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        char s[10];
        int param;
        scanf("%s", s);
        if(!strcmp(s,"push")){
            cin >> param;
            st.push(param);
        }
        else if(!strcmp(s,"pop")){
            if(st.empty())
                cout << "-1\n";
            else{
                cout << st.top() << "\n";
                st.pop();
            }
        }
        else if(!strcmp(s,"size")){
            cout << st.size() << '\n';
        }
        else if(!strcmp(s,"empty")){
            if(st.empty())
                cout << "1\n";
            else 
                cout << "0\n";
        }
        else {
            if(st.empty())
                cout << "-1\n";
            else{
                cout << st.top() << "\n";
            }
        }
    }
}