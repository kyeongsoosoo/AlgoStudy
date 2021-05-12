#include <iostream>
#include <algorithm>

using namespace std;

int N,M;

int arr[500000];

int find_lower(int target){
    int start = 0;
    int last = N-1;
    while(last > start){
        int mid = (start + last) / 2;
        if (arr[mid] >= target)
            last = mid;
        else start =mid + 1;
    }
    return last;
}

int find_upper(int target){
    int start = 0;
    int last = N-1;
    while(last > start){
        int mid = (start + last) / 2;
        if (arr[mid] > target)
            last = mid;
        else start = mid + 1;
    }
    return last;
}

int count_temp(int target){
    int start = find_lower(target);
    int end = find_upper(target);

    cout << "start: " << start << "end : " << end << '\n';

    if(end == N-1 && target == arr[N-1])
        end++;

    return end - start;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for(int i=0; i<N; i++){
        cin >> arr[i];
    }

    sort(arr, arr+N);

    cin >> M;

    int temp;

    for(int i=0; i<M; i++){
        cin >> temp;
        cout << count_temp(temp) << "\n";
    }

}