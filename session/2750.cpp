#include <iostream>

using namespace std;

int arr[1000];

void bubbleSort(int N) {
    for(int i=N-1; i>0; i--){
        for(int j=0; j<i;j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i] ;
    }
    bubbleSort(N);
    for(int i=0; i<N; i++){
        cout << arr[i] << '\n';
    }



}