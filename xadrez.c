#include <stdio.h>

/*
 * ========================================================================
 * PROGRAMA AVANÇADO DE MOVIMENTAÇÃO DAS PEÇAS DE XADREZ
 * ========================================================================
 * Este programa simula os movimentos das peças de xadrez utilizando:
 * - RECURSIVIDADE para Torre, Bispo e Rainha
 * - LOOPS COMPLEXOS para o Cavalo
 * - LOOPS ANINHADOS para implementação alternativa do Bispo
 * ========================================================================
 */

// ===== FUNÇÕES RECURSIVAS =====

/*
 * FUNÇÃO RECURSIVA: Movimento da Torre
 * Parâmetros: casas_restantes - número de casas ainda a percorrer
 * Funcionalidade: Move a Torre horizontalmente para a direita de forma recursiva
 */
void mover_torre_recursivo(int casas_restantes) {
    // Caso base: se não há mais casas para mover, encerra a recursão
    if (casas_restantes <= 0) {
        return;
    }
    
    // Imprime o movimento atual
    printf("Direita\n");
    
    // Chamada recursiva: diminui uma casa e continua o movimento
    mover_torre_recursivo(casas_restantes - 1);
}

/*
 * FUNÇÃO RECURSIVA: Movimento da Rainha
 * Parâmetros: casas_restantes - número de casas ainda a percorrer
 * Funcionalidade: Move a Rainha horizontalmente para a esquerda de forma recursiva
 */
void mover_rainha_recursivo(int casas_restantes) {
    // Caso base: se não há mais casas para mover, encerra a recursão
    if (casas_restantes <= 0) {
        return;
    }
    
    // Imprime o movimento atual
    printf("Esquerda\n");
    
    // Chamada recursiva: diminui uma casa e continua o movimento
    mover_rainha_recursivo(casas_restantes - 1);
}

/*
 * FUNÇÃO RECURSIVA: Movimento do Bispo
 * Parâmetros: casas_restantes - número de casas ainda a percorrer
 * Funcionalidade: Move o Bispo na diagonal (cima e direita) de forma recursiva
 */
void mover_bispo_recursivo(int casas_restantes) {
    // Caso base: se não há mais casas para mover, encerra a recursão
    if (casas_restantes <= 0) {
        return;
    }
    
    // Imprime o movimento diagonal atual
    printf("Cima Direita\n");
    
    // Chamada recursiva: diminui uma casa e continua o movimento
    mover_bispo_recursivo(casas_restantes - 1);
}

/*
 * FUNÇÃO COM LOOPS ANINHADOS: Movimento alternativo do Bispo
 * Parâmetros: movimentos_diagonais - número de movimentos diagonais a realizar
 * Funcionalidade: Implementa o movimento do Bispo usando loops aninhados
 * Loop externo: controla o movimento vertical (cima)
 * Loop interno: controla o movimento horizontal (direita)
 */
void mover_bispo_loops_aninhados(int movimentos_diagonais) {
    printf("BISPO (com loops aninhados) - Movendo %d casas na diagonal:\n", movimentos_diagonais);
    
    // Loop externo: controla os movimentos verticais
    for (int movimento_vertical = 1; movimento_vertical <= movimentos_diagonais; movimento_vertical++) {
        
        // Loop interno: para cada movimento vertical, há um movimento horizontal correspondente
        for (int movimento_horizontal = 1; movimento_horizontal <= 1; movimento_horizontal++) {
            printf("Cima Direita\n");
        }
    }
}

/*
 * FUNÇÃO COM LOOPS COMPLEXOS: Movimento avançado do Cavalo
 * Funcionalidade: Move o Cavalo em "L" (2 casas para cima + 1 casa para a direita)
 * Utiliza loops aninhados com múltiplas variáveis e condições de controle
 */
void mover_cavalo_complexo() {
    printf("CAVALO (loops complexos) - Movendo em 'L' (2 casas para cima + 1 casa para a direita):\n");
    
    // Constantes para definir o padrão de movimento do Cavalo
    const int MOVIMENTO_VERTICAL = 2;      // Duas casas para cima
    const int MOVIMENTO_HORIZONTAL = 1;    // Uma casa para a direita
    const int TOTAL_ETAPAS = 2;           // Duas etapas no movimento em L
    
    /*
     * LOOPS COMPLEXOS COM MÚLTIPLAS VARIÁVEIS E CONDIÇÕES:
     * - etapa: controla as duas fases do movimento (vertical e horizontal)
     * - passo: controla cada passo individual dentro de cada etapa
     * - movimento_concluido: flag para controlar quando uma etapa está completa
     */
    
    // Loop externo: controla as etapas do movimento em L
    for (int etapa = 1; etapa <= TOTAL_ETAPAS; etapa++) {
        int passo = 1;                    // Contador de passos na etapa atual
        int movimento_concluido = 0;      // Flag de controle da etapa
        int casas_na_etapa;               // Número de casas a mover na etapa atual
        
        // Determina quantas casas mover na etapa atual
        if (etapa == 1) {
            casas_na_etapa = MOVIMENTO_VERTICAL;    // Primeira etapa: movimento vertical
        } else {
            casas_na_etapa = MOVIMENTO_HORIZONTAL;  // Segunda etapa: movimento horizontal
        }
        
        // Loop interno complexo: executa os movimentos da etapa atual
        while (!movimento_concluido) {
            
            // Verifica se ainda há movimentos a fazer na etapa atual
            if (passo > casas_na_etapa) {
                movimento_concluido = 1;  // Marca a etapa como concluída
                continue;                 // Pula para a próxima iteração (sai do while)
            }
            
            // Executa o movimento baseado na etapa atual
            if (etapa == 1) {
                // Primeira etapa: movimento vertical (para cima)
                printf("Cima\n");
            } else if (etapa == 2) {
                // Segunda etapa: movimento horizontal (para a direita)
                printf("Direita\n");
            } else {
                // Condição de segurança (nunca deveria ser executada)
                break;  // Sai do loop em caso de erro
            }
            
            passo++;  // Incrementa o contador de passos
        }
    }
}

// ===== FUNÇÃO PRINCIPAL =====

int main() {
    // Definindo as constantes para número de movimentos de cada peça
    const int CASAS_TORRE = 5;
    const int CASAS_BISPO = 5;
    const int CASAS_RAINHA = 8;
    
    printf("=== SIMULAÇÃO AVANÇADA DE MOVIMENTOS DAS PEÇAS DE XADREZ ===\n");
    printf("Utilizando RECURSIVIDADE e LOOPS COMPLEXOS\n\n");
    
    // 1. TORRE - Movimento recursivo para a direita
    printf("TORRE (recursiva) - Movendo %d casas para a direita:\n", CASAS_TORRE);
    mover_torre_recursivo(CASAS_TORRE);
    printf("\n");
    
    // 2. BISPO - Movimento recursivo na diagonal
    printf("BISPO (recursivo) - Movendo %d casas na diagonal (cima e direita):\n", CASAS_BISPO);
    mover_bispo_recursivo(CASAS_BISPO);
    printf("\n");
    
    // 3. RAINHA - Movimento recursivo para a esquerda
    printf("RAINHA (recursiva) - Movendo %d casas para a esquerda:\n", CASAS_RAINHA);
    mover_rainha_recursivo(CASAS_RAINHA);
    printf("\n");
    
    // 4. CAVALO - Movimento com loops complexos
    mover_cavalo_complexo();
    printf("\n");
    
    // 5. BISPO - Implementação alternativa com loops aninhados
    mover_bispo_loops_aninhados(CASAS_BISPO);
    printf("\n");
    
    printf("=== FIM DA SIMULAÇÃO AVANÇADA ===\n");
    
    return 0;
}