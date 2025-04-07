/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include<stdio.h>
#include<string.h>

int main() {
    char mensagem[256];
    char chave[256];
    char resultado[256];
    char entrada_hex[512];
    char bytes_convertidos[256];

    int opcao;

    printf("=== Sistema de Criptografia XOR ===\n");
    printf("1 - Criptografar uma mensagem\n");
    printf("2 - Descriptografar uma mensagem (hexadecimal)\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    getchar(); // limpa o \n do buffer

    if (opcao == 1) { //opcao para realizar criptografia
        printf("Digite a mensagem: ");
        fgets(mensagem, sizeof(mensagem), stdin);
        mensagem[strcspn(mensagem, "\n")] = '\0';

        printf("Digite a chave secreta: ");
        fgets(chave, sizeof(chave), stdin);
        chave[strcspn(chave, "\n")] = '\0';

        int i;
        for (i = 0; i < strlen(mensagem); i++) {
            resultado[i] = mensagem[i] ^ chave[i % strlen(chave)];
        }
        resultado[i] = '\0'; // finaliza a string resultante

        printf("Mensagem criptografada (em hexadecimal): ");
        for (i = 0; i < strlen(mensagem); i++) {
            printf("%02X", (unsigned char)resultado[i]);
        }
        printf("\n");

    } else if (opcao == 2) { //opcao para realizar descriptografia
        printf("Digite a mensagem criptografada (hexadecimal): ");
        fgets(entrada_hex, sizeof(entrada_hex), stdin);
        entrada_hex[strcspn(entrada_hex, "\n")] = '\0';

        printf("Digite a chave secreta: ");
        fgets(chave, sizeof(chave), stdin);
        chave[strcspn(chave, "\n")] = '\0';

        //lógica para fazer a descriptografia e exibir a mensagem descriptografada

    } else {
        printf("Opcao invalida. Encerrando programa.\n");
    }

    return 0;
}