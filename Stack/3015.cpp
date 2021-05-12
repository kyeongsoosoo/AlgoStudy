#include <iostream>
#include <stack>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;

    stack<pair<int, int> > st;

    long long result = 0;
    int temp;
    for (int i=0; i<N; i++){
        cin >> temp;

        while(!st.empty() && st.top().first < temp){
            result += st.top().second;
            st.pop();
        }

        pair<int,int> a = make_pair(temp,1);
        if(st.empty()){
            st.push(a);
        }
        else{
            if(st.top().first == temp){
                pair<int,int> t = st.top();
                st.pop();

                result += t.second;
                if(!st.empty())
                    result++;

                t.second++;
                st.push(t);
            }

            else{
                st.push(a);
                result++;
            }
        }
    }

    cout << result;
}