#include <iostream>
#define MAX 1000001

using namespace std;

int N,M;
int arr[MAX];

int findP(int num){
    if(arr[num] == num) return num;
    return arr[num] = findP(arr[num]);
}

void merge(int a, int b){
    a = findP(a);
    b = findP(b);
    if( a != b)
        arr[a] = b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for(int i=0; i<=N; i++){
        arr[i] = i;
    }
    for(int i=0; i < M; i++){
        int op,a,b;
        cin >> op >> a >> b;

        if(op ==0){
            if(a>=b){
                merge(a,b);
            }
            else{
                merge(b,a);
            }
        }
        else if(op == 1){
            if(findP(a) == findP(b))
                cout << "YES" << '\n';
            else
                cout << "NO" << '\n';
        }
    }

}