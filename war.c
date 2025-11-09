
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// --- Constantes Globais ---
#define MAX_TERRITORIO 5
//#define MAX_EMPRESTIMOS 100 // Definimos uma capacidade para empréstimos.
//#define TAM_STRING 100

// --- Definição da Estrutura (STruct) ---
// struct de livro agora tem um campo 'disponivel' para controlar o status
struct Territorio{
    char nome[30];
    char cor[10];
    int numero;
};

// Nova Struct para armazenar informações do emprestimo.
 

// --- Função de limpar o buffer de entrada ---
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// === Função Principal (main) ---
int main() {
    // 1. ALOCAÇÃO DINÂMICA DE MEMÓRIA
    // Agora, em vez de arrays estáticos, usamos ponteiros.
    struct Territorio *mapa;


    // Usando calloc para o array de livros. calloc(num_elementos, tamanho_de_cada_elemento)
    // vantagem: inicializa toda memória com zeros. Isso significa que 'disponivel' já comaça com zero
    mapa =(struct Territorio *) calloc(MAX_TERRITORIO, sizeof(struct Territorio));

    // Verificação; é crucial verificar se a alocação de memória deu certo.
    if (mapa == NULL) {
        printf("ERRO: falha ao alocar memória.\n");
        return 1; // Retorna 1 para indicar um erro.
    }
int num_territorio = 0;
int atacante ;
int defensor;
int dado1;
int dado2;

 

    printf("=================================== \n");
     printf("\n");
      printf("Vamos cadastrar os 5 territórios iniciais do nosso mundo.\n");
       printf(" \n");
    
    //laço for para ler os dados
    for(int i=0; i<MAX_TERRITORIO;i++){
        printf("---Cadastrando território %d---\n",i+1);// exibe o numero da pessoa

        // leitura do nome
        printf("Nome do Território:");
        fgets(mapa[i].nome, sizeof(mapa[i].nome),stdin);

        mapa[i].nome[strcspn(mapa[i].nome,"\n")] =0;

        //Leitura de cor
        printf("Cor do Exército:");
        fgets(mapa[i].cor, sizeof(mapa[i].cor),stdin);

        mapa[i].cor[strcspn(mapa[i].cor,"\n")] =0;

        //leitura da numero
        printf("Número de tropas:");
        scanf("%d",&mapa[i].numero);

         printf(" \n");
        //Limpa o buffer
        while(getchar()!='\n');
    }
     printf("Cadastro inicial concluido com sucesso!\n");
      printf(" \n");

do{

    // Inicializa o gerador de números aleatórios
    srand(time(NULL));

    // Gera e imprime um número aleatório entre 1 e 6
    dado1 = (rand() % 6) + 1;
    //printf("O número sorteado é: %d\n", dado1);
    dado2 = (rand() % 6) + 1;
   // printf("O número sorteado é: %d\n", dado2);

    // laço para exibir os dados
         printf("===================================\n");
         printf("   MAPA DO MUNDO - ESTADO ATUAL\n");
         printf("=================================\n");
          printf(" \n");                                                  
     for(int i=0; i<MAX_TERRITORIO;i++){
         printf(". %d",i+1);
         printf(" %s", mapa[i].nome);
         printf(" ( Exercito %s,",mapa[i].cor);
         printf(" Tropas: %d)",mapa[i].numero);
        printf(" \n");
        }

         printf(" \n");
         printf("--- FASE DE ATAQUE ---\n");
            printf("--- Escolha o território atacante (1 a 5, ou 0 para sair): ---");
                scanf("%d",&atacante);
                atacante = atacante -1;
                if(atacante == -1){
                   break;
                }

                printf("--- Escolha o território defensor (1 a 5): ---");
                scanf("%d",&defensor); 
                defensor = defensor -1; 
                limparBufferEntrada();

            printf(" \n");
            printf(" %s", mapa[atacante].nome);
            printf(" ( Exercito %s,",mapa[atacante].cor);
            printf(" Tropas: %d)",mapa[atacante].numero);
            printf(" \n");

        printf(" %s", mapa[defensor].nome);
         printf(" ( Exercito %s,",mapa[defensor].cor);
         printf(" Tropas: %d)",mapa[defensor].numero);
        printf(" \n");
        printf(" \n");
        
        // verificando resultado da batalha
        printf("--- RESULTADO DA BATALHA ---\n");
          printf("O atacante %s", mapa[atacante].nome);
          printf(" rolou um dado e tirou: %d\n", dado1);
             printf("O defensor %s", mapa[defensor].nome);
             printf(" rolou um dado e tirou: %d\n", dado2);

             // verificando vencedor
        if(dado1 > dado2){

            mapa[defensor].numero = mapa[defensor].numero -1;
            printf("VITÓRIA DO ATAQUE! O defensor perdeu 1 tropa\n");
            
                }else if(dado2 > dado1){

                    mapa[atacante].numero = mapa[atacante].numero -1;
                   printf("VITÓRIA DA DEFESA! O atacante perdeu 1 tropa\n");

                }else if(dado1 == dado2){

                   printf("HOUVE UM EMPATE NA BATALHA!\n");
                }

                // verificando conquista
        if(mapa[atacante].numero == 0){

            strcpy(mapa[atacante].cor, mapa[defensor].cor);
            printf("CONQUISTA! O territótio %s", mapa[atacante].nome);
            printf(" foi dominado pelo exercito %s", mapa[defensor].cor);
            printf(" \n");
            
                }else if(mapa[defensor].numero == 0){

                   strcpy(mapa[defensor].cor, mapa[atacante].cor);
                   printf("CONQUISTA! O territótio %s", mapa[defensor].nome);
                   printf(" foi dominado pelo exercito %s", mapa[atacante].cor);
                   printf(" \n");
            
                }

                 printf("\nPressione Enter para continuar...");
                getchar();
                

     }while (atacante != -1);
    printf("\nSaindo do sistema...\n");
         
    
    
    // 3. LIBERAÇÃO DA MEMÓRIA
    free(mapa); // Libera o array.
     return 0; 
} 
