#include <iostream>
#define limit 1000000

using namespace std;

int arr[limit], temp[limit];

void mergeSort(int start, int end){
    if(start == end) return;

    int middle = (start+end)/2;


    mergeSort(start, middle);
    mergeSort(middle+1, end);

    int S = start, M = middle+1;
    int T = start;
    while(S<=middle && M<=end){
        if(arr[S] > arr[M]){
            temp[T] = arr[M];
            M++;
        }else{
            temp[T] = arr[S];
            S++;
        }
        
        T++;
    }
    while( S<=middle){
        temp[T] = arr[S++];
        T++;
    }
    while(M<=end){
        temp[T] = arr[M++];
        T++;
    }
    for(int i=start; i<=end; i++){
        arr[i] = temp[i];
    }

}




int main() {
    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    mergeSort(0, N-1);
    for(int i=0; i<N; i++){
        cout << arr[i] << '\n';
    }

}