#include <stdio.h>
double avg(double sum);
int main() {
    double sum = 0;
    double num; // get real number
    int i;

    for(i = 0; i < 3; i++){
        printf("Digite o %i numero: ",i+1);
        scanf("%lf", &num);
        sum+=num;
        
    }
    printf("\nMedia: %.3f", avg(sum));
    
    return 0;
}
double avg(double sum) {
    return sum / 3;
}
