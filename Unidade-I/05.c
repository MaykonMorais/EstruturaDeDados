#include <stdio.h>
double avg(int sum);
int main() {
    int sum = 0;
    int num;
    int i;

    for(i = 0; i < 3; i++){
        printf("Digite o %i numero: ",i+1);
        scanf("%d", &num);
        sum+=num;
    }
    printf("\nMedia: %.3f", avg(sum));
    
    return 0;
}
double avg(int sum) {
    return (double)(sum) / 3;
}
