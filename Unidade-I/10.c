#include <stdio.h>
#include <math.h>
double areaCircle(double raio);

int main() {
    double raio;

    printf("Digite o raio: ");
    scanf("%lf", &raio);
    if(raio < 0) {
        printf("Digite Corretamente o raio");
    } else{
        printf("Area do Circulo = %.2f", areaCircle(raio));
    }

    return 0;
}
double areaCircle(double raio) {
    return M_PI *  pow(raio, 2);
}