#include <stdio.h>

void calc(int x, int y);
int sum(int x,int y);
int dif(int x, int y);
int mult(int x,int y);
float div(int x,int y);
int rest(int x, int y);

int main() {
    int x, y;

    printf("Digite um numero: ");
    scanf("%d", &x);
    
    printf("Digite outro numero: ");
    scanf("%d", &y);
    
    calc(x,y);
    return 0;
}
void calc(int x, int y) {
    printf("Soma => %d + %d = %d\n",x, y, sum(x,y));
    printf("Subtracao => %d - %d = %d\n",x, y, dif(x,y));
    printf("Multiplicacao => %d * %d = %d\n",x, y, mult(x,y));
    printf("Divisao => %d / %d = %f\n",x, y, div(x,y));
    printf("Resto => %d mod %d = %d\n",x, y, rest(x,y));
    
}

int sum(int x,int y){
    return x + y;
}
int dif(int x,int y) {
    return x - y;
}
int mult(int x,int y) {
    return x * y;
}
float div(int x, int y) {
    return x / y;
}
int rest(int x,int y) {
    return x % y;
}