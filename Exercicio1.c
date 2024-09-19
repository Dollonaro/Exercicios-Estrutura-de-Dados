//Cauã Souza Dias - RA: 1988941
//João Pedro Ramos Ferreira - RA: 1993757
//Lucas Belia Canguçu Strambaioli - RA: 1996497
//Rian Moraes Carvalho - RA: 2001292

#include <stdio.h>

typedef struct{
    int vetor[10]
} t_tabuada;


t_tabuada tabuada(int N){
    int i;
    t_tabuada vetorTabuada;
    for(i=1; i<=10; i++){
        vetorTabuada.vetor[i-1] = N*i;
    }
    return vetorTabuada;
    
}


int eh_par(int x){
    if(x%2==0){
        return 0;
    } else{
        return 1;
    }
}


int paresDaMatriz(int matriz[4][5]){
    int i,j,quantPar=0;
    for(i=0; i<4; i++){
        for(j=0; i<5; i++){
            if(eh_par(matriz[i][j]) == 0){
                quantPar+=1;
            }
        }
    }
    return quantPar;
}



void main(){
    int i, j, m[4][5], valor;
    //printf("Digite um valor: ");
    //scanf("%d", &valor);
    //for(i=0;i<10;i++){
    //    printf("%d\n", tabuada(valor).vetor[i]);
    //}
    //fflush(stdin);
    

    for(i=0;i<4;i++){
        for(j=0;j<5;j++){
           m[i][j]=j;
        }
    }
    for(i=0;i<4;i++){
        for(j=0;j<5;j++){
           printf("%d",m[i][j]);
        }
    }
    printf("A quantidade de pares nessa matriz eh %d", paresDaMatriz(m));
    fflush(stdin);
}