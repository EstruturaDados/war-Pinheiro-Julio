#include <stdio.h>
#include <string.h>

// Definindo estrutura
struct Territorio{
    char nome[30];
    char cor[10];
    int numero;
};

int main(){
    //Definindo o numero de pessoas que iremos cadastrar
    int num_territorio = 5;

    // Declarando um array de struct
    struct Territorio territorios[num_territorio];

    printf("=================================== \n");
     printf("\n");
      printf("Vamos cadastrar os 5 territórios iniciais do nosso mundo.\n");
       printf(" \n");
    
    //laço for para ler os dados
    for(int i=0; i<num_territorio;i++){
        printf("---Cadastrando território %d---\n",i+1);// exibe o numero da pessoa

        // leitura do nome
        printf("Nome do Território:");
        fgets(territorios[i].nome, sizeof(territorios[i].nome),stdin);

        territorios[i].nome[strcspn(territorios[i].nome,"\n")] =0;

        //Leitura de cor
        printf("Cor do Exército:");
        fgets(territorios[i].cor, sizeof(territorios[i].cor),stdin);

        territorios[i].cor[strcspn(territorios[i].cor,"\n")] =0;

        //leitura da numero
        printf("Número de tropas:");
        scanf("%d",&territorios[i].numero);

         printf(" \n");
        //Limpa o buffer
        while(getchar()!='\n');
    }
     printf("Cadastro inicial concluido com sucesso!\n");
      printf(" \n");

    // laço para exibir os dados
     printf("===================================\n");
      printf("   MAPA DO MUNDO - ESTADO ATUAL\n");
       printf("=================================\n");
        printf(" \n");
    for(int i=0; i<num_territorio;i++){
        printf("TERRITÓRIO %d\n",i+1);
        printf("- Nome:%s\n", territorios[i].nome);
        printf("- Dominado por: Exercito %s\n",territorios[i].cor);
        printf("- Tropas:%d\n",territorios[i].numero);
         printf(" \n");

    }
return 0;
}