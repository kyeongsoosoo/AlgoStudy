#include <iostream>
#include <algorithm>

#define MAX 2000000001

using namespace std;

int N;

long long arr[100000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for(int i=0; i<N; i++){
        long long tmp;
        cin >> tmp;
        arr[i] = tmp;
    }
    sort(arr, arr+N);

    int from = 0;
    int to = N-1;
    int a,b;
    long long min = MAX;

    while(from < to){
        long long tmp_a = arr[from];
        long long tmp_b = arr[to];


        bool test = abs(tmp_a+tmp_b) < min;
        //  cout << tmp_a << " arr " << test  <<  '\n';

        if(abs(tmp_a + tmp_b) < min){
             
            a = arr[from];
            b = arr[to];
            min = abs(tmp_a + tmp_b);
            // cout << a << " " << b << " " << min <<  "!\n";
            if(min == 0 ) break;
        }

        if(tmp_a < 0 && tmp_b <= 0){
            from++;
            continue;
        }
        else if(tmp_a >= 0 && tmp_b > 0 ){
            to--;
            continue;
        }

        // cout << from << " f/t " << to << '\n';

        if(tmp_a + tmp_b > 0)
            to--;
        else 
            from++;

    }

    cout << a << " " << b;
    
}