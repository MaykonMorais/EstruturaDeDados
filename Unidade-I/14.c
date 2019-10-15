#include <stdio.h>
double mediaPonderada(float n1, float n2, float n3);
double mediaAritmetica(float n1, float n2, float n3);
void verificaMedia(double media, int opcao);
void mediaFinalPonderada(double mediaParcial,double nota4);
void mediaFinalAritmetica(double mediaParcial, double nota4);

int main() {
    float nota1, nota2, nota3;
    int opcao;
    printf("Digite a primeira nota: ");
    scanf("%f", &nota1);

    printf("Digite a segunda nota: ");
    scanf("%f", &nota2);

    printf("Digite a terceira nota: ");
    scanf("%f", &nota3);

    printf("\n[1] Media Aritmetica\n[2] Media Ponderada\nOpcao: ");
    scanf("%d", &opcao);
    double media;

    switch (opcao)
    {
    case 1:
        media = mediaAritmetica(nota1, nota2, nota3);
        verificaMedia(media, opcao);
        break;
    case 2:
        media = mediaPonderada(nota1, nota2, nota3);
        verificaMedia(media, opcao);
        break;
    default:
        printf("Digite uma opcao valida");
        break;
    }
    return 0;
}
double mediaAritmetica(float n1, float n2, float n3) {
    return (n1 + n2 + n3) / 3;
}
double mediaPonderada(float n1, float n2, float n3) {
    return ((n1 * 2) + (n2 * 3) + (n3 * 4)) / 9;
}

void verificaMedia(double media, int opcao) {
    if(media >= 7) {
        printf("Aprovado\n");
        printf("Media: %.2f\n", media);
    } else if(media >= 3.5) {
        double nota4;
        
        printf("Recuperacao\nMedia: %.2f\n", media);
        printf("Digite a nota da 4 Prova: ");
        scanf("%lf", &nota4);

        if(opcao == 1) {
            mediaFinalAritmetica(media, nota4);
        } else {
            mediaFinalPonderada(media, nota4);
        }

    } else {
        printf("Reprovado");
        printf("Media: %.2f", media);
    }
}

void mediaFinalPonderada(double mediaParcial,double nota4) {
    double final  = ((mediaParcial * 7) + (nota4 * 3)) / 10;
    
    if(final >= 5) {
        printf("\nAprovado\n");
    } else
    {
        printf("\nReprovado\n");
    }
    printf("Media Final: %.2f", final);
}

void mediaFinalAritmetica(double mediaParcial, double nota4) {
    double p = ((mediaParcial * 6) + (nota4 * 4));
    double final = p / 10;

    if(final >= 5) {
        printf("\nAprovado\n");
    } else
    {
        printf("\nReprovado\n");
    }
    printf("Media Final: %.2f", final);
}