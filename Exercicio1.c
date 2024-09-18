//Cauã Souza Dias - RA: 1988941
//João Pedro Ramos Ferreira - RA: 1993757
//Lucas Belia Canguçu Strambaioli - RA: 1996497
//Rian Moraes Carvalho - RA: 2001292

#include <stdio.h>

void tabuada(int N, int vetorTabuada[10]){
    int i;
    for(i=1; i<=10; i++){
        vetorTabuada[i-1] = N*i;
    }
    
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