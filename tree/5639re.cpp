#include <iostream>
#include <vector>
#define MAX 1000001
#define NODE_MAX 100001

using namespace std;

vector<int> preorder;

void post_order(int start, int end){
    if(start == end)
        return;
    if(start == end -1){
        cout << preorder[start] << '\n';
        return;
    }

    int idx = start + 1;

    while(1){
        if((idx < end && preorder[idx] < preorder[start]) == false){
            break;
        }
        idx++;
    }
    post_order(start+1, idx);
    post_order(idx,end);

    cout << preorder[start] << '\n';
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int temp_n;
    while(cin >>temp_n){
        preorder.push_back(temp_n);
    }
    post_order(0,preorder.size());
    
}
