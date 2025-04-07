#include<stdio.h>
#include<string.h>
#include<stdlib.h> // para strtol

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

    if (opcao == 1) { // Criptografia
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
        resultado[i] = '\0';

        printf("Mensagem criptografada (em hexadecimal): ");
        for (i = 0; i < strlen(mensagem); i++) {
            printf("%02X", (unsigned char)resultado[i]);
        }
        printf("\n");

    } else if (opcao == 2) { // Descriptografia
        printf("Digite a mensagem criptografada (hexadecimal): ");
        fgets(entrada_hex, sizeof(entrada_hex), stdin);
        entrada_hex[strcspn(entrada_hex, "\n")] = '\0';

        printf("Digite a chave secreta: ");
        fgets(chave, sizeof(chave), stdin);
        chave[strcspn(chave, "\n")] = '\0';

        int len = strlen(entrada_hex);
        if (len % 2 != 0) {
            printf("Erro: entrada hexadecimal inválida.\n");
            return 1;
        }

        int num_bytes = len / 2;
        for (int i = 0; i < num_bytes; i++) {
            char byte_hex[3];
            byte_hex[0] = entrada_hex[2 * i];
            byte_hex[1] = entrada_hex[2 * i + 1];
            byte_hex[2] = '\0';

            // Converte de hexadecimal para inteiro
            int valor = (int)strtol(byte_hex, NULL, 16);

            // Aplica XOR com a chave
            bytes_convertidos[i] = (char)(valor ^ chave[i % strlen(chave)]);
        }
        bytes_convertidos[num_bytes] = '\0';

        printf("Mensagem descriptografada: %s\n", bytes_convertidos);

    } else {
        printf("Opcao invalida. Encerrando programa.\n");
    }

    return 0;
}
