#include <stdio.h>
#define limit 2000001

int count;
int XCord[limit];
int YCord[limit];
int Cord[100000][2];
int YAligned[100000][2];
int XAligned[100000][2];


#include <stdio.h>
#define limit 2000001

int count;
int XCord[limit];
int YCord[limit];
int Cord[100000][2];
int YAligned[100000][2];
int XAligned[100000][2];



int main() {
    scanf("%d", &count);
    for(int i=0; i<count; i++){
        scanf("%d %d", &Cord[i][0],&Cord[i][1]);
        
        XCord[Cord[i][0]+100000] += 1;
        YCord[Cord[i][1]+100000] += 1;
    }
    
    for(int i=1;i<limit; i++){
        XCord[i] += XCord[i-1];
        YCord[i] += YCord[i-1];
    }
    for(int i=count-1;i>=0;i--){
        YAligned[YCord[Cord[i][1]+100000]-1][0] = Cord[i][0];
        YAligned[(YCord[Cord[i][1]+100000]--)-1][1] = Cord[i][1];
       
    }
    for(int i=count-1;i>=0;i--){
        XAligned[XCord[YAligned[i][0]+100000]-1][0] = YAligned[i][0];
        XAligned[(XCord[YAligned[i][0]+100000]--)-1][1] = YAligned[i][1];
        
    }
    for(int i=0; i<count;i++){
        
        printf("%d %d\n", XAligned[i][0], XAligned[i][1]);
    
        
    }


}
int main() {
    scanf("%d", &count);
    for(int i=0; i<count; i++){
        scanf("%d %d", &Cord[i][0],&Cord[i][1]);
        
        XCord[Cord[i][0]+100000] += 1;
        YCord[Cord[i][1]+100000] += 1;
    }
    
    for(int i=1;i<limit; i++){
        XCord[i] += XCord[i-1];
        YCord[i] += YCord[i-1];
    }
    for(int i=count-1;i>=0;i--){
        YAligned[YCord[Cord[i][1]+100000]-1][0] = Cord[i][0];
        YAligned[(YCord[Cord[i][1]+100000]--)-1][1] = Cord[i][1];
       
    }
    for(int i=count-1;i>=0;i--){
        XAligned[XCord[YAligned[i][0]+100000]-1][0] = YAligned[i][0];
        XAligned[(XCord[YAligned[i][0]+100000]--)-1][1] = YAligned[i][1];
        
    }
    for(int i=0; i<count;i++){
        
        printf("%d %d\n", XAligned[i][0], XAligned[i][1]);
    
        
    }


}