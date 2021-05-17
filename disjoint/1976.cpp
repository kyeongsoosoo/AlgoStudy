#include <iostream>

using namespace std;

int N,M;

int arr[201];

int find_root(int idx){
    if(arr[idx] == idx) return idx;

    return find_root(arr[idx]);
}

void merge(int a, int b){
    a = find_root(a);
    b = find_root(b);

    if( a == b) return;
    else{
        arr[a] = b;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for(int i=0; i<N; i++)
        arr[i] = i;

    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            int is_con = 0;
            cin >> is_con;
            if(is_con == 1){
                merge(i,j);
            }
        }
    }

    int root_idx;
    int temp_node;
    int is_sameGroup = 1;
    for(int i=0; i<M; i++){
        cin >> temp_node;

        temp_node -= 1;

        if(i == 0)
            root_idx = find_root(temp_node);
        else{
            if(find_root(temp_node) != root_idx){
                is_sameGroup = 0;
                break;
            }
        }
    }
    if(is_sameGroup == 1){
        cout << "YES";
    }else{
        cout << "NO";
    }

}