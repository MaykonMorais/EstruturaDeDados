#include <stdio.h>
#include <math.h>

double delta(int a, int b, int c);
void raizes(double delta, int a, int b, int c);

int main() {
    int a, b, c;

    printf("Digite o A: ");
    scanf("%d", &a);

    printf("Digite o B: ");
    scanf("%d", &b);

    printf("Digite o C: ");
    scanf("%d", &c);

    printf("Funcao: %dx² + %dx + %d = 0\n", a, b, c);
    double delt = delta(a,b,c);
    raizes(delt, a, b, c);
    return 0;
}

double delta(int a, int b, int c) {
    return pow(b,2) - 4 * a * c;;
}

void raizes(double delta, int a, int b, int c) {
    if(delta < 0) {
        printf("A funcao nao existe raizes reais\n");
    } else if(delta == 0) {
        double result = (-b + sqrt(delta)) / 2 * a;
        printf("Raiz x = %.2f\n", result);
    } else {
        double result1 = (-b - sqrt(delta)) / 2 * a;
        double result2 = (-b + sqrt(delta)) / 2 * a;
        
        printf("Raiz x1 = %.2f\n", result1);
        printf("Raiz x2 = %.2f\n", result2);
    
    }
}
