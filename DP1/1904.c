#include <stdio.h>

long long arr[1000000] = {1,2};

long long DP(int n){
    if(n == 1){
        return arr[0];
    }
    else if(n == 2)
        return arr[1];
    else if(arr[n-1] ==0){
        return arr[n-1] = (DP(n-1) + DP(n-2))%15746;
    }
    return arr[n-1];
}

int main(){
    int target;
    scanf("%d", &target);
    printf("%lld\n", DP(target));
}
