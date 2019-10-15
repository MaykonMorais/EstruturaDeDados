#include <stdio.h>

int verif(int num);
int main() {
    int num;

    printf("Digite um numero: ");
    scanf("%d", &num);
    
    if(verif(num)) {
        printf("Numero eh PAR");
    }
    else {
        printf("Numero eh IMPAR");
    }
    
    return 0;
}
int verif(int num) {
    if(num % 2 == 0) {
        return 1;
    }
    else {
        return 0;
    }
}