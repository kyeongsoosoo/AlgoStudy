#include <stdio.h>
#define min(a,b) ((a<b) ? a : b)

int size[1000000] = {0,1,1};

int find_n(int n){
    if(n==1 || size[n-1])
        return size[n-1];
    else if(n%6 == 0)
        return size[n-1] = min(find_n(n/3),min(find_n(n/2), find_n(n-1))) +1 ;
    else if(n%2 == 0)
        return size[n-1] = min(find_n(n/2), find_n(n-1)) +1;
    else if(n%3 == 0)
        return size[n-1] = min(find_n(n/3), find_n(n-1)) +1;
    else 
        return size[n-1] = find_n(n-1) + 1;
}

int main(){
    int testN;
    scanf("%d", &testN);
    find_n(testN);
    printf("%d\n",size[testN-1]);
}