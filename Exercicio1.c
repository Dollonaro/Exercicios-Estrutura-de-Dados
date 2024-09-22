//Cauã Souza Dias - RA: 1988941
//João Pedro Ramos Ferreira - RA: 1993757
//Lucas Belia Canguçu Strambaioli - RA: 1996497
//Rian Moraes Carvalho - RA: 2001292

#include <stdio.h>
#include <locale.h>

//Criação de um novo tipo de dados para possibilitar o retorno na função tabuada
typedef struct{
    int vetor[10];
} t_tabuada;


//Função que recebe um valor inteiro, multiplica ele por valores de 1 a 10 e retorna o vetor com esses valores multiplicados
t_tabuada tabuada(int N){
    int i;
    t_tabuada vetorTabuada;
    for(i=1; i<=10; i++){
        vetorTabuada.vetor[i-1] = N*i;
    }
    return vetorTabuada;
    
}


//Função que recebe um valor inteiro e verifica se ele é par, retornando 1 nos pares e 0 nos ímpares   
int eh_par(int x){
    if(x%2==0){
        return 1;
    } else{
        return 0;
    }
}


//Função que recebe uma matriz[4][5] de valores inteiros e utiliza da função eh_par para verificar a quantidade de pares presentes nela, depois retorna essa quantidade
int paresDaMatriz(int matriz[4][5]){
    int i,j,quantPar=0;
    for(i=0; i<4; i++){
        for(j=0; j<5; j++){
            if(eh_par(matriz[i][j]) == 1){
                quantPar+=1;
            }
        }
    }
    return quantPar;
}



void main(){
    setlocale(LC_ALL, "Portuguese");


    int i, j, m[4][5], valor, valor_matriz;
    printf("Digite um valor: ");
    scanf("%d", &valor);
    for(i=0;i<10;i++){
        printf("%d\n", tabuada(valor).vetor[i]);
    }
    
    

    for(i=0;i<4;i++){
        for(j=0;j<5;j++){
            printf("Digite um valor para a posicao [%d][%d]",i,j);
            scanf("%d", &valor_matriz);
           m[i][j]=valor_matriz;
        }
    }
    for(i=0;i<4;i++){
        printf("\n");
        for(j=0;j<5;j++){
           printf("%d ",m[i][j]);
        }
    }
    printf("\nA quantidade de pares nessa matriz eh %d", paresDaMatriz(m));

}