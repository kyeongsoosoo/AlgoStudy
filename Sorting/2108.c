#include <stdio.h>
#define limit 8001

int main() {
    int count;
    scanf("%d", &count);
    int num, original[count], counter[limit]={0,};
    int result[count];
    double sum=0;
    int max[3]={0,};
    for(int i=0; i<count; i++){
        scanf("%d", &num);
        original[i]=num;
        sum += num;
        counter[num+4000] += 1;
    }
    for(int i=0; i<limit;i++){
        if(counter[i]>max[0]){
            max[0] = counter[i];
            max[1] =i;
            max[2] = 0;
        } else if( counter[i] == max[0] && max[2]<1){
            max[1]= i;
            max[2]= 1;
        }
        if(i>0) counter[i] += counter[i-1];
    }
    for(int i=count-1; i>=0; i--){
        result[counter[original[i]+4000]-1] = original[i];
        counter[original[i]+4000]--;
    }
    
        printf("%.f\n", sum/count);
        printf("%d\n",result[count/2]);
        printf("%d\n", max[1]-4000);
        printf("%d\n", result[count-1]-result[0]);
}