#include <stdio.h>

int main() {
    int day, night, height;
    scanf("%d %d %d", &day, &night, &height);
    int result = (height-day)/(day-night);
    int residue = (height-day)%(day-night);
    if(result==0 && height-day == 0)printf("1");
    else if(result == 0) printf("2");
    else if(residue != 0) printf("%d", result+2);
    else printf("%d", result+1);
}


