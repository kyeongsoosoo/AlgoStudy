#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool max_n(int a, int b) {
    return (a > b ? true : false);
}
bool min_n(int a, int b) {
    return (a < b ? true : false);
}


int main() {
    int N;
    cin >> N;
    vector<int> plus;
    vector<int> minus;
    int temp;
    int sum = 0;

    for(int i=0; i<N; i++){
        cin >> temp;
        if(temp > 0){
            plus.push_back(temp);
        }
        else if(temp <= 0){
            minus.push_back(temp);
        }

    }
    sort(plus.begin(), plus.end(),min_n);
    sort(minus.begin(), minus.end(),max_n);

    while(plus.size() > 1){
        int first = plus.back();
        plus.pop_back();
        int second = plus.back();
        plus.pop_back();
        if( first != 1 && second != 1){
            sum += first*second;
        }
        else{
            sum += first + second;
        }
    }
    if(!plus.empty()){
        sum += plus.back();
        plus.pop_back();
    }

    while(minus.size() > 1){
        int first = minus.back();
        minus.pop_back();
        int second = minus.back();
        minus.pop_back();
        sum += first*second;

    }
    if(!minus.empty()){
        sum += minus.back();
        minus.pop_back();
    }

    cout << sum;

}