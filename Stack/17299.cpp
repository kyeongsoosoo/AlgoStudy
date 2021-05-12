#include <iostream>
#define MAX 1000000

using namespace std;

int N;
int st[MAX+1];
int num[MAX+1];
int print[MAX+1];
int arr[MAX+1];
int idx = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    int temp;

    for(int i=1; i<=N; i++){
        cin >> num[i];
        st[num[i]]++;
    }
    for(int i=N; i>=1; i--){
        if(idx == 0){
            print[i] = -1;
            arr[idx++] = num[i];
        }
        else if(st[num[i]] < st[arr[idx-1]]){
            print[i] = arr[idx-1];
            arr[idx++] = num[i];
        }
        else{
            while(idx-- != 0){
                if(st[num[i]] < st[arr[idx-1]]){
                    print[i] = arr[idx-1];
                    arr[idx++] = num[i];
                    break;
                }
                else if(idx == 0){
                    print[i] = -1;
                    arr[idx++] = num[i];
                    break;
                }
            }
        }

    }
    for(int i=1; i<= N; i++){
        cout << print[i] << " ";
    }

}