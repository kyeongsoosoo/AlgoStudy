#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

int arr[1000001];
vector<int> L;
int N;

int find_lower_b(int num){
    int start = 0;
    int last = L.size()-1;
    int ret = 1000000007;
    while( last >= start){
        int mid = (start + last) / 2 ;
        if(L[mid] >= num){    
            ret = mid;
            last = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }

    return ret;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for(int i=0;i<N; i++){
        int temp;
        cin >> temp;
        arr[i] = temp;
    }

    for(int i=0; i<N; i++){
        if(L.empty()){
            L.push_back(arr[i]);
        }
        else if(arr[i] > L.back()){
            L.push_back(arr[i]);
        }
        else{
            int idx = find_lower_b(arr[i]);
            L[idx] = arr[i];
        }
    }

    cout << L.size();
}