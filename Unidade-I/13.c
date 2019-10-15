#include <stdio.h>
double media(float n1, float n2, float n3);

int main() {
    float nota1, nota2, nota3;
    printf("Digite a primeira nota: ");
    scanf("%f", &nota1);

    printf("Digite a segunda nota: ");
    scanf("%f", &nota2);

    printf("Digite a terceira nota: ");
    scanf("%f", &nota3);

    printf("Media: %.2f\n", media(nota1, nota2, nota3));
    if(media(nota1, nota2, nota3) >= 7) {
        printf("Aprovado");
    } else if(media(nota1, nota2, nota3) >= 3.5) {
        printf("Recuperacao");
    } else {
        printf("Reprovado");
    }

    return 0;
}
double media(float n1, float n2, float n3) {
    return (n1 + n2 + n3) / 3;
}
