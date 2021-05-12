#include <iostream>
#include <stack>
#include <math.h>

using namespace std;

stack<int> origin;
stack<int> ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, erase_N;
    cin >> N >> erase_N;
    int length = erase_N;
    string result;
    char temp;
    cin >> result;
    int first = origin.top();
    origin.pop();
    ans.push(first);
    for(int i=0; i<N; i++){
        temp = result[i];
        if(temp > ans.top()){
            while(temp > ans.top() && erase_N != 0){
                ans.pop();
                erase_N--;
                if(ans.empty())
                    break;
            }
            ans.push(temp);
        }
        else {
            ans.push(temp);
        }
      
    }
    
    while(erase_N-- != 0){
        ans.pop();
    }
    int idx = 1;

    string answer;
    
    for(int i=0; i<N -length;i++){
        char a = ans.top() + '0';
        answer = a + answer;
        ans.pop();
     
    }
    cout << answer;
}