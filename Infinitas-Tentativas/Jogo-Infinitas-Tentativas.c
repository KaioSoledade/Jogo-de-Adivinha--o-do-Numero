#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("******************************************\n");
    printf("* Bem vindo ao nosso jogo de adivinhacao *\n");
    printf("******************************************\n");

    int numerosecreto;
    int chute;
    int tentativa = 1;
    double pontos = 1000;


    int segundos = time(0);
    srand(segundos);

    int numerobruto = rand();
    numerosecreto = numerobruto % 100;
    
    int nivel;
     
    while(1){
        printf("-----------------------------------\n");
        printf("Tentativa %d\n", tentativa);
        printf("Qual o seu chute?\n");

        scanf("%d", &chute);
        
        if(chute < 0){
            printf("Seu chute nao vale como uma tentativa\n");
            continue;
        }

        int acertou = (chute == numerosecreto);
        int maior = (chute > numerosecreto);


        if(acertou) {
            printf("Parabens, Voce acertou\n");
            break;
        }
        else if (maior){
            printf("Seu chute foi MAIOR, Tente Novamente\n");

        } else{
            printf("Seu chute foi MENOR, Tente Novamente\n");

        }

        tentativa++;
        double pontosperdidos = abs(chute - numerosecreto) / (double)2.0;
        pontos = pontos - pontosperdidos;
    };
    printf("-----------------------------------\n");
    printf("Voce usou %d tentativas\n", tentativa);
    printf("FIM DE JOGO\n");
    printf("Pontuacao: %.2f\n", pontos);

};
