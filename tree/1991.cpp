#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

struct Node {
    char left;
    char right;
};

struct Node arr[27];

int N;

void pre(char root){
    if(root == '.') return;
    
    int idx = root - 'A';
    cout << root;
    pre(arr[idx].left);
    pre(arr[idx].right);

}

void in(char root){
    if(root == '.') return;
    
    int idx = root - 'A';
    in(arr[idx].left);
    cout << root;
    in(arr[idx].right);
}

void post(char root){
    if(root == '.') return;
    
    int idx = root - 'A';
    post(arr[idx].left);
    post(arr[idx].right);
    cout << root;
}


int main(){
    cin >> N;
    for(int i=1 ; i <= N; i++){
        char par, left , right;
        cin >> par >> left >> right;

        int idx = par - 'A';

        arr[idx].left = left;
        arr[idx].right = right;
    }

    pre('A');
    cout << '\n';
    in('A');
    cout << '\n';
    post('A');
    cout << '\n';
}