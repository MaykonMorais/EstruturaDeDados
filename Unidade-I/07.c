#include <stdio.h>
double calcTotalSemTaxa(int qtdRefri, int qtdFatiaPizza);
double calcTotalComTaxa(int qtdRefri, int qtdFatiaPizza);    
double calcTotalComTaxaPessoa(int qtdRefri, int qtdFatiaPizza, int qtdPessoas);
int main() {

    int qtdRefri;
    int qtdFatiaPizza;
    int qtdPessoas;

    printf("Quantidade de refri: ");
    scanf("%d", &qtdRefri);

    printf("Quantidade de Fatias: ");
    scanf("%d", &qtdFatiaPizza);

    printf("Quantidade de pessoas: ");
    scanf("%d", &qtdPessoas);

    printf("\nTotal Sem Taxa: R$ %.2f", calcTotalSemTaxa(qtdRefri, qtdFatiaPizza));
    printf("\nTotal Com Taxa: $ %.2f", calcTotalComTaxa(qtdRefri, qtdFatiaPizza));
    printf("\nRateio com taxa: R$ %.2f", calcTotalComTaxaPessoa(qtdRefri,qtdFatiaPizza, qtdPessoas));

    return 0;
}

double calcTotalSemTaxa(int qtdRefri, int qtdFatiaPizza) {
    double tot = ((qtdRefri * 1.5) + (qtdFatiaPizza * 3.50));
    return tot;
}
double calcTotalComTaxa(int qtdRefri, int qtdFatiaPizza) {
    double tot = ((qtdRefri * 1.5) + (qtdFatiaPizza * 3.50)) * 1.1;
    return tot;
}
double calcTotalComTaxaPessoa(int qtdRefri, int qtdFatiaPizza, int qtdPessoas) {
    double tot = (((qtdRefri * 1.5) + (qtdFatiaPizza * 3.50))* 1.1) / qtdPessoas;
    
}