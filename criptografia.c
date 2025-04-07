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

        //lógica para fazer a criptografia e exibir a mensagem criptografada

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