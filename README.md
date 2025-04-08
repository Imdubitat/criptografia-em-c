# 🔐 Sistema de Criptografia XOR em C

Este projeto é um programa simples em linguagem C que permite **criptografar** e **descriptografar** mensagens utilizando a operação **XOR** (OU Exclusivo). Ele mostra, de maneira prática, como a lógica de criptografia simétrica pode ser implementada de forma compacta e eficaz.

---

## 📘 O que é a Criptografia XOR?

A operação lógica **XOR (OU Exclusivo)** funciona da seguinte maneira:
- **Retorna 1** se os bits comparados forem diferentes.
- **Retorna 0** se os bits forem iguais.

| Bit A | Bit B | A XOR B |
|-------|-------|----------|
|   0   |   0   |    0     |
|   0   |   1   |    1     |
|   1   |   0   |    1     |
|   1   |   1   |    0     |

Na criptografia, isso é útil porque:
- Aplicar XOR entre um byte da mensagem e um byte da chave gera um novo valor (criptografado).
- Aplicar XOR novamente entre esse valor criptografado e o mesmo byte da chave recupera o valor original:

```
Mensagem Original ^ Chave = Criptografado
Criptografado ^ Chave = Mensagem Original
```

Este é o princípio básico de **criptografia simétrica**, onde a mesma chave é usada tanto para criptografar quanto para descriptografar.

---

## 💡 Como o programa funciona?

1. O usuário escolhe entre **criptografar** ou **descriptografar** uma mensagem.
2. O programa aplica XOR entre cada caractere da mensagem e da chave (repetindo a chave, se necessário).
3. A mensagem criptografada é exibida como uma sequência hexadecimal.
4. Para descriptografar, o usuário informa o texto hexadecimal e a mesma chave usada originalmente. O programa converte os hexadecimais em bytes e aplica XOR novamente para obter a mensagem original.

---

## 💻 Código completo em C

```c
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
            printf("Erro: entrada hexadecimal invalida.\n");
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
```

---

## 📌 Observações importantes

- A **chave** pode ser de qualquer tamanho, mas será repetida se for menor que a mensagem.
- A mensagem criptografada é exibida como **texto hexadecimal** para facilitar a visualização e transmissão.
- A **mesma chave** usada na criptografia deve ser usada na descriptografia. Caso contrário, o resultado será incorreto.
- A entrada da mensagem criptografada deve conter uma quantidade **par de caracteres hexadecimais**.
- Este sistema é **educacional** e não deve ser usado para segurança real de dados.

---

## 🧪 Exemplo de uso

```
=== Sistema de Criptografia XOR ===
1 - Criptografar uma mensagem
2 - Descriptografar uma mensagem (hexadecimal)
Escolha uma opcao: 1
Digite a mensagem: lais
Digite a chave secreta: xy
Mensagem criptografada (em hexadecimal): 1418110A
```

Descriptografando:
```
Escolha uma opcao: 2
Digite a mensagem criptografada (hexadecimal): 1418110A
Digite a chave secreta: xy
Mensagem descriptografada: lais
```

