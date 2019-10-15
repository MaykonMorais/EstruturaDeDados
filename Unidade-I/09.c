#include <stdio.h>
#include <math.h>

double imc(double altura, double peso);
int main() {
    double altura, peso;

    printf("Digite sua altura (m): ");
    scanf("%lf", &altura);

    printf("Digite seu peso: (kg)");
    scanf("%lf", &peso);

    printf("IMC = %.2f", imc(altura, peso));
    return 0;
}

double imc(double altura, double peso) {
    double tot =((peso)/ pow(altura, 2));
    return tot;
}