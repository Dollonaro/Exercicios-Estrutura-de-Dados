//Cauã Souza Dias - RA: 1988941
//João Pedro Ramos Ferreira - RA: 1993757
//Lucas Belia Canguçu Strambaioli - RA: 1996497
//Rian Moraes Carvalho - RA: 2001292

#include <stdio.h>
#include <locale.h>

// Função que recebe 3 valores reais e retornar o maior deles
float encontrarMaior(float num1, float num2, float num3) {
    float maior;

    maior = num1;

    if (num2 > maior) {
        maior = num2;
    }

    if (num3 > maior) {
        maior = num3;
    }

    return maior;
}


// Função para calcular a^b, onde b >= 0
float calcularPotencia(float a, int b) {
    float resultado = 1;
    int i;

    if (b < 0) {
        printf("O expoente deve ser maior ou igual a 0.\n");
        return;
    }

    for (i = 1; i <= b; i++) {
        resultado = resultado * a;
    }

    return resultado;
}


// Função para calcular f(x) = x^2 - 3 + x/2
float calcularFuncao(float x) {
    float fx;

    fx = (x * x) - 3 + (x / 2);

    return fx;
}


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

    int opcao;
    
    do{
        printf("\n\nDigite 1 para verificar dentre 3 valores qual o maior");
        printf("\nDigite 2 para calcular o resultado de uma potenciação, sabendo que o expoente deve ser maior ou igual a 0");
        printf("\nDigite 3 para calcular o valor de f(x), no qual f(x)=x^2 -3 + x/2, para um valor dado de x");
        printf("\nDigite 4 para verificar a tabuada de um número");
        printf("\nDigite 5 para verificar a quantidade de números pares numa matriz [4][5]");
        printf("\nDigite 0 para sair");
        printf("\nBem vindos, escolha uma opção para acessar: ");
        scanf("%d", &opcao);
        switch (opcao){
            case 1:{
                float num1,num2,num3;
                printf("\nDigite um número:\n");
                scanf("%f", &num1);
                printf("\nDigite um número:\n");
                scanf("%f", &num2);
                printf("\nDigite um número:\n");
                scanf("%f", &num3);
                printf("\n%.2f\n",encontrarMaior(num1,num2,num3));
                break;
            }

            case 2:{
                float base;
                int expoente;
                printf("\nDigite o valor da base:\n");
                scanf("%f", &base);
                printf("\nDigite o valor do expoente:\n");
                scanf("%d", &expoente);
                printf("\n%.2f\n",calcularPotencia(base, expoente));
                break;
            }

            case 3:{
                float x;
                printf("\nDigite o valor desejado de x:\n");
                scanf("%f", &x);
                printf("\n%.2f\n",calcularFuncao(x));
                break;
            }

            case 4:{
                int i, valor;
                printf("Digite um valor: ");
                scanf("%d", &valor);
                for(i=0;i<10;i++){
                    printf("\n%d\n", tabuada(valor).vetor[i]);
                }
                break;
            }

            case 5:{
                int i, j, valor_matriz, m[4][5];
                for(i=0;i<4;i++){
                    for(j=0;j<5;j++){
                        printf("Digite um valor para a posicao [%d][%d]",i,j);
                        scanf("%d", &valor_matriz);
                        m[i][j]=valor_matriz;
                    }
                }
                fflush(stdin);
                for(i=0;i<4;i++){
                    printf("\n");
                    for(j=0;j<5;j++){
                        printf("%d ",m[i][j]);
                    }
                }
                printf("\n\nA quantidade de pares nessa matriz eh %d\n", paresDaMatriz(m));
                break;
            }

            case 0:{
                printf("\nObrigado por utilizar!!\n");
                break;
            }
            
            default:{
                printf("\nDigite uma opção válida.\n");
                break;
            }
        }
    system("pause");
    system("cls");

    }while(opcao!=0);

}