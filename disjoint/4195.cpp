#include <iostream>
#include <map>
#include <string>
#include <algorithm>


#define MAX 200005

using namespace std;

int T,F;
int parent[MAX], t_size[MAX];

// 친구 목록 스트링 벡터에 저장 <- 인덱스를 알기 위함
// 분리 집합 만듦. 카운팅 해줄 수 있는 백터 하나 있어야할듯.

int findP(int idx){
    if(parent[idx] == idx) return idx;

    return findP(parent[idx]);
}

void merge(int a, int b){
    a = findP(a);
    b = findP(b);

    if( a == b) return;
    else{
        parent[a] = b;
        t_size[b] += t_size[a];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;


    for(int i=0; i<T; i++){
        cin >> F;
        for(int k=0; k<MAX; k++){
            parent[k] = k;
            t_size[k] = 1;
        }

        map<string,int> name;
        int idx = 0;


        for(int j=0; j<F; j++){
            string temp1, temp2;
            cin >> temp1 >> temp2;
            if(name.count(temp1) == 0)
                name[temp1] = idx++;
            if(name.count(temp2) == 0)
                name[temp2] = idx++;
            
            int idx1 = findP(name[temp1]);
            int idx2 = findP(name[temp2]);

            if(idx1 == idx2){
                cout << t_size[idx1];
            }
            else{
                merge(idx1, idx2);
                cout << max(t_size[idx1],t_size[idx2]);
            }
            cout << '\n';
        }
    }
    
}