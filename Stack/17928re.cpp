#include <iostream>


using namespace std;

int arr[1000000];
int origin[1000000];
int ans[1000000];

int main() {
    int N;
    int count = 0;
    cin >> N;
    for(int i=0; i<N; i++){
        ans[i] = -1;
    }
    for(int i=0; i<N; i++){
        cin >> origin[i];
        
        if(count == 0){
            arr[count++] = i;
            continue;
        }
        
        while( count > 0 && origin[i] > origin[arr[count-1]]){
            
            ans[arr[--count]] = origin[i];
        }
        arr[count++] = i;
        
    }
    for(int i=0; i<N-1; i++){
        cout << ans[i] << " ";
    }
    cout << ans[N-1] << '\n';
}