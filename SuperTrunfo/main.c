#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ================= STRUCT DA CARTA =================
struct Carta {
    char nome[50];
    unsigned long int populacao; // valor nao pode ser negativo
    float area;
    float pibPerCapita;
    float pib;
    int pontosTuristicos;
    int codigo;
};

// ================= PROTÓTIPOS =================
void menuPrincipal();
void iniciarJogo();
void cadastroCartas(struct Carta cartas[], int quantidade);
void CartasPreCadastradas(struct Carta cartas[]);
void mostrarCartas(struct Carta cartas[], int quantidade);
void menuAtributos(struct Carta carta1, struct Carta carta2);
void rodadaJogo(struct Carta cartas[]);
int validarMenu(int min, int max);

// ================= VALIDAÇÃO DE ENTRADA MENU =================
int validarMenu(int min, int max){
    char linha[100];
    int valor;

    while(1){
        fgets(linha, sizeof(linha), stdin);

        if(sscanf(linha, "%d", &valor) != 1){
            printf("Digite um número válido!\n");
            continue;
        }

        if(valor < min || valor > max){
            printf("Digite um valor entre %d e %d.\n", min, max);
            continue;
        }

        return valor;
    }
}

// ================= MENU PRINCIPAL =================
void menuPrincipal(){

    int opcao;

    do{
        printf("\n====== SUPER TRUNFO ======\n\n");
        printf("1. JOGAR\n");
        printf("2. REGRAS\n");
        printf("3. SAIR\n\n");
        printf("============================\n");
        printf("Escolha: ");

        opcao = validarMenu(1,3); // funcao para ver se valor entrada esta no intervalo

        if(opcao < 1 || opcao > 3){
            printf("\nOpção inválida!\n");
            continue; // volta e redesenha o menu
        }

        switch(opcao){
            case 1:
                iniciarJogo();
                break;

            case 2:
                printf("\n====== REGRAS ======\n");
                printf("Comparar atributos das cartas.\n");
                printf("Quem tiver o maior valor vence.\n\n");
                break;

            case 3:
                printf("Encerrando jogo...\n");
                break;
        }

    }while(opcao != 3); // mantem o loop roando enquanto opcao != 3
}

// ================= INICIAR JOGO / SUB-MENU CARTAS =================
void iniciarJogo(){

    struct Carta cartas[2];
    int opcao;

    while(1){

        printf("\n====== SUPER TRUNFO ======\n\n");
        printf("1. Cadastrar Cartas\n");
        printf("2. Cartas Pré-Cadastradas\n");
        printf("3. Menu Inicial\n\n");
        printf("============================\n");
        printf("Escolha: ");

        opcao = validarMenu(1,3);

        if(opcao == 1){
            cadastroCartas(cartas, 2);
            break;
        }
        else if(opcao == 2){
            usarCartasPreCadastradas(cartas);
            break;
        }
        else if(opcao == 3){
            return;
        }
    }

    // chama a função para iniciar a rodada do jogo
    rodadaJogo(cartas);
}

// ================= INICIO DA RODADA =================
void rodadaJogo(struct Carta cartas[]){ // array cartas vazio - nao tem limite de cartas
    mostrarCartas(cartas, 2); // definido limte cartas
    menuAtributos(cartas[0], cartas[1]); 
}

// ================= MENU DE ATRIBUTOS =================
void menuAtributos(struct Carta carta1, struct Carta carta2){

    int atr;

    printf("\n===== Escolha um atributo =====\n\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - PIB per Capita\n\n");
    printf("============================\n"); 
    printf("Escolha: ");

    atr = validarMenu(1,5);

    printf("\n===== RESULTADO =====\n\n");

    // comparação dos atributos
    switch(atr){ 
        case 1:
            if(carta1.populacao > carta2.populacao)
                printf("Carta 1 venceu!\n");
            else if(carta2.populacao > carta1.populacao)
                printf("Carta 2 venceu!\n");
            else
                printf("Empate!\n");
        break;

        case 2:
            if(carta1.area > carta2.area)
                printf("Carta 1 venceu!\n");
            else if(carta2.area > carta1.area)
                printf("Carta 2 venceu!\n");
            else
                printf("Empate!\n");
        break;

        case 3:
            if(carta1.pib > carta2.pib)
                printf("Carta 1 venceu!\n");
            else if(carta2.pib > carta1.pib)
                printf("Carta 2 venceu!\n");
            else
                printf("Empate!\n");
        break;

        case 4:
            if(carta1.pontosTuristicos > carta2.pontosTuristicos)
                printf("Carta 1 venceu!\n");
            else if(carta2.pontosTuristicos > carta1.pontosTuristicos)
                printf("Carta 2 venceu!\n");
            else
                printf("Empate!\n");
        break;

        case 5:
            if(carta1.pibPerCapita > carta2.pibPerCapita)
                printf("Carta 1 venceu!\n");
            else if(carta2.pibPerCapita > carta1.pibPerCapita)
                printf("Carta 2 venceu!\n");
            else
                printf("Empate!\n");
        break;
    }

    printf("\n=====================\n\n");
}

// ================= CADASTRO DE CARTA =================
void cadastroCartas(struct Carta cartas[], int quantidade){

    for(int i = 0; i < quantidade; i++){

        cartas[i].codigo = i + 1;

        printf("\n===== Cadastro da Carta %d =====\n", i + 1);

        printf("Nome do país: ");
        fgets(cartas[i].nome, sizeof(cartas[i].nome), stdin);
        cartas[i].nome[strcspn(cartas[i].nome, "\n")] = '\0';

        printf("População: ");
        scanf("%f", &cartas[i].populacao);

        printf("Área: ");
        scanf("%f", &cartas[i].area);

        printf("PIB: ");
        scanf("%f", &cartas[i].pib);

        printf("Pontos turísticos: ");
        scanf("%d", &cartas[i].pontosTuristicos);

        while(getchar() != '\n');

        cartas[i].pibPerCapita = cartas[i].pib / cartas[i].populacao;
    }
}

// ================= CARTAS PRÉ-CADASTRADAS =================
void CartasPreCadastradas(struct Carta cartas[]){

    strcpy(cartas[0].nome, "Brasil");
    cartas[0].codigo = 1;
    cartas[0].populacao = 213000000;
    cartas[0].area = 8510000;
    cartas[0].pib = 186800000.0;
    cartas[0].pontosTuristicos = 50;
    cartas[0].pibPerCapita = cartas[0].pib / cartas[0].populacao;

    strcpy(cartas[1].nome, "Alemanha");
    cartas[1].codigo = 2;
    cartas[1].populacao = 83000000;
    cartas[1].area = 357000;
    cartas[1].pib = 4200000.0;
    cartas[1].pontosTuristicos = 40;
    cartas[1].pibPerCapita = cartas[1].pib / cartas[1].populacao;
}

// ================= MOSTRAR CARTAS =================
void mostrarCartas(struct Carta cartas[], int quantidade){

    for(int i = 0; i < quantidade; i++){

        printf("\n============= Carta %d =============\n", i+1);
        printf("País: %s\n", cartas[i].nome);
        printf("Código: %d\n", cartas[i].codigo);
        printf("População: %lu\n", cartas[i].populacao);
        printf("Área: %.2f km²\n", cartas[i].area);
        printf("PIB: %.2f\n", cartas[i].pib);
        printf("Pontos Turísticos: %d\n", cartas[i].pontosTuristicos);
        printf("PIB per Capita: %.2f\n", cartas[i].pibPerCapita);
        printf("-------------------------------------------\n");
    }
}

// ================= MAIN =================
int main(){
    menuPrincipal();
    return 0;
}