#include <stdio.h>

void intervaloWhile(int num1, int num2);
void intervalorDoWhile(int num1, int num2);
void intervaloFor(int num1, int num2);

int main() {
    int num1, num2;

    printf("Digite o inicio do intervalo: ");
    scanf("%d", &num1);

    printf("Digite o fim do intervalo: ");
    scanf("%d", &num2);

    printf("Intervalo  com While: ");
    intervaloWhile(num1, num2);

    printf("Intervalo Com Do-While: ");
    intervalorDoWhile(num1, num2);

    printf("Intervalo com For");
    intervaloFor(num1, num2);
    return 0;
}


void intervaloWhile(int num1, int num2) {
    while(num1 <= num2){
        printf(" %d", num1);
        ++num1;
    }
    printf("\n");
}
void intervalorDoWhile(int num1, int num2) {
    do {
        printf(" %d", num1);
        ++num1;
    } while(num1 <= num2);
    printf("\n");
}
void intervaloFor(int num1, int num2) {
    int i = num1;
    for(i; i <= num2; i++) {
        printf(" %d", i);
    }
    printf("\n");
}