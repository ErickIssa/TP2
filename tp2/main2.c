// #include <stdio.h>
// #include <stdlib.h>

// #include "ListaSondas.h"

// // Função para resolver o problema da mochila para uma única sonda
// int mochila(SondaMarte *sonda, TCompartimento *comp, int n, int itens_selecionados[]) {
//     // Criar tabela DP
//     int M[n + 1][capacidade + 1];
//     int cont[n + 1][capacidade + 1]; // Para desempate baseado no número de itens

//     // Inicializar tabelas
//     for (int i = 0; i <= n; i++) {
//         for (int j = 0; j <= capacidade; j++) {
//             M[i][j] = 0;
//             cont[i][j] = 0;
//         }
//     }

//     // Preenchimento da tabela
//     for (int i = 1; i <= n; i++) {
//         for (int j = 0; j <= capacidade; j++) {
//             if (rochas[i - 1].usado || rochas[i - 1].peso > j) {
//                 // Não usar a rocha (incompatível ou já usada)
//                 M[i][j] = M[i - 1][j];
//                 cont[i][j] = cont[i - 1][j];
//             } else {
//                 // Tentar incluir a rocha
//                 int valor_incluindo = rochas[i - 1].valor + M[i - 1][j - rochas[i - 1].peso];
//                 int itens_incluindo = 1 + cont[i - 1][j - rochas[i - 1].peso];

//                 if (valor_incluindo > M[i - 1][j] ||
//                     (valor_incluindo == M[i - 1][j] && itens_incluindo > cont[i - 1][j])) {
//                     // Incluir a rocha
//                     M[i][j] = valor_incluindo;
//                     cont[i][j] = itens_incluindo;
//                 } else {
//                     // Não incluir a rocha
//                     M[i][j] = M[i - 1][j];
//                     cont[i][j] = cont[i - 1][j];
//                 }
//             }
//         }
//     }

//     // Rastrear itens selecionados
//     int capacidade_restante = capacidade;
//     for (int i = n; i > 0 && capacidade_restante > 0; i--) {
//         if (M[i][capacidade_restante] != M[i - 1][capacidade_restante]) {
//             itens_selecionados[i - 1] = 1; // A rocha foi selecionada
//             capacidade_restante -= rochas[i - 1].peso;
//             rochas[i - 1].usado = 1; // Marcar como usada
//         }
//     }

//     return M[n][capacidade];
// }

// int main() {
//     int x, c, n;

//     // Ler o número de sondas, capacidade e número de rochas
//     printf("Digite o número de sondas: ");
//     scanf("%d", &x);
//     printf("Digite a capacidade de cada sonda: ");
//     scanf("%d", &c);
//     printf("Digite o número de rochas: ");
//     scanf("%d", &n);

//     // Ler as rochas
//     Rocha rochas[n];
//     printf("Digite o peso e o valor de cada rocha (peso valor):\n");
//     for (int i = 0; i < n; i++) {
//         scanf("%d %d", &rochas[i].peso, &rochas[i].valor);
//         rochas[i].usado = 0; // Inicialmente, nenhuma rocha foi usada
//     }

//     // Resolver para cada sonda
//     for (int sonda = 1; sonda <= x; sonda++) {
//         int itens_selecionados[n];
//         for (int i = 0; i < n; i++) {
//             itens_selecionados[i] = 0; // Inicializar seleção
//         }

//         printf("\nSonda #%d:\n", sonda);
//         int valor_maximo = mochila(c, rochas, n, itens_selecionados);

//         // Exibir resultado para a sonda
//         printf("Valor máximo: %d\n", valor_maximo);
//         printf("Rochas selecionadas (índice 0-based): ");
//         int alguma_rocha = 0;
//         for (int i = 0; i < n; i++) {
//             if (itens_selecionados[i]) {
//                 printf("%d ", i);
//                 alguma_rocha = 1;
//             }
//         }
//         if (!alguma_rocha) {
//             printf("Nenhuma");
//         }
//         printf("\n");

//         // Encerrar se não houver mais rochas utilizáveis
//         int rochas_restantes = 0;
//         for (int i = 0; i < n; i++) {
//             if (!rochas[i].usado) {
//                 rochas_restantes++;
//             }
//         }
//         if (rochas_restantes == 0) {
//             printf("Sem mais rochas disponíveis.\n");
//             break;
//         }
//     }

//     return 0;
// }