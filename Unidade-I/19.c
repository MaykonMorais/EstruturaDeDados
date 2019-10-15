#include <stdio.h>
#include <string.h>

void verificaSenhaDoWhile(char * senha, char * senhaDigitada);
void verificaSenhaWhile(char * senha, char * senhaDigitada);

int main() {
    char * senha = "senha"; // vetor dinamico de char
    char * senhaDigitada;
    int verificador;
    
    printf("==== Testando Com do-while ==== \n");
    verificaSenhaDoWhile(senha, senhaDigitada); // passando por referencia
    
    printf("\n==== Testando com while ==== \n");
    verificaSenhaWhile(senha, senhaDigitada);

    return 0;
}

void verificaSenhaDoWhile(char * senha, char * senhaDigitada) {
    int verificador;
    printf("%s\n",senha);
    printf(senhaDigitada);

    do {
        printf("\nDigite a senha: ");
        scanf("%s", senhaDigitada);

         verificador = strcmp(senha, senhaDigitada);
        if(verificador == 0) {
            printf("Senha Correta");
        } else {
            printf("Senha Incorreta\n");
        }
    } while (verificador !=0);
}
void verificaSenhaWhile(char * senha, char * senhaDigitada) {
    int verificador = 1;

    while(verificador != 0) {
        printf("\nDigite a senha: ");
        scanf("%s", senhaDigitada);

        verificador = strcmp(senha, senhaDigitada);

        if(verificador == 0) {
            printf("Senha Correta");
        } else {
            printf("Senha Incorreta\n");
        }
    } 
}