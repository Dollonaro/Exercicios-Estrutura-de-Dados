//Cauã Souza Dias - RA: 1988941
//João Pedro Ramos Ferreira - RA: 1993757
//Lucas Belia Canguçu Strambaioli - RA: 1996497
//Rian Moraes Carvalho - RA: 2001292

// Incluindo as bibliotecas
#include <stdio.h>
#include <string.h>


// Definindo a struct e utilizando o typedef para tornar 'Funcionario' uma variável
typedef struct {
    char nome[30];
    char cpf[12];
    int idade;
    char sexo[2];
    float salario;
} Funcionario;


Funcionario funcionarios[100]; //Vetor que armazenará cada funcionario e seus dados

//Função de cadastrar funcionario
int cadastrarFuncionario(int x) {

    char resposta; // Variável que receberá um 'char' que definirá se o usuário deseja ou não cadastrar um novo funcionario
    do{ // 'do' utilizado para cadastrar ao menos um funcionario 
        printf("Informe o nome do funcionario: ");
        fgets(funcionarios[x].nome, sizeof(funcionarios[x].nome), stdin); // 'fgets' para receber a string emitida pela entrada padrão (teclado)
        funcionarios[x].nome[strcspn(funcionarios[x].nome, "\n")] = '\0'; // Função utilizada para consumir o '\n' emitido automaticamente após o "enter" ser pressionado pelo usuário no 'fgets'

        // As funções "print" "fgets" e "strcspn" são repetidas, porém cada nova vez adicionando um novo dado para o funcionario (cpf, sexo)
        
        printf("Informe o CPF do funcionario: ");
        fgets(funcionarios[x].cpf, sizeof(funcionarios[x].cpf), stdin);
        funcionarios[x].cpf[strcspn(funcionarios[x].cpf, "\n")] = '\0';

        printf("Informe a idade do funcionario: ");
        scanf("%d", &funcionarios[x].idade); // Por receber um valor inteiro (idade), a função 'scanf' foi escolhida
        getchar(); // 'getchar' tem o mesmo papel da função 'strcspn' de consumir newlines ('\n') para não deixar residuos e atrapalhar em novos 'fgets' ou 'scanf'

        printf("Informe o sexo [f/m] do funcionario: ");
        fgets(funcionarios[x].sexo, sizeof(funcionarios[x].sexo), stdin);
        funcionarios[x].sexo[strcspn(funcionarios[x].sexo, "\n")] = '\0';

        printf("Informe o salario do funcionario: ");
        scanf("%f", &funcionarios[x].salario);
        getchar();
        
        x++; // Variável criada para acumular valor, servir de guia no índice do vetor 'funcionarios' e referência no número de funcionários cadastrados
        
        /*Verifica se o número de funcionarios cadastrados é maior ou igual o número de posições da lista, 'printando' um aviso de lotação caso esteja 
        lotada e quebrando a função para não dar "over" no vetor*/ 
        if (x >= 100) {
            printf("Lista cheia!\n");
            break;
        }
        
        // Pergunta ao usuário se ele deseja cadastrar um novo funcionario
        printf("Deseja cadastrar um novo usuário? (s/n): ");
        resposta = getchar(); 
        getchar(); 

        //Se a resposta for diferente de 's' ou 'n' uma mensagem de erro é exibida e a função "quebra"
        if (resposta != 's' && resposta != 'n'){
            printf("Resposta inválida");
            break;
        }

    } while(resposta == 's'); // Condição que define a repetição do processo de cadastro
    
    return x;
    };

 // Passa-se os parâmetros funcionarios e x, funcioanarios será para percorrer a lista na qual ficará armazenados os dados e x agirá como um "contador"
void buscarCPF(Funcionario funcionarios[], int x) {
    char cpfBusca[12]; // Váriavel para a busca do cpf sendo possível digitar 12 digitos(número de digitos de um cpf real)
    printf("Digite o CPF do funcionário a ser buscado (somente números): "); //Mostra essa mensagem na tela do usuário
    scanf("%s", cpfBusca); // Faz a leitura desses digitos
    getchar(); // Sem ele o scanf deixa um '\n'

    for (int i = 0; i < x; i++) { //Percorre os dados de 'funcionarios'
        if (strcmp(funcionarios[i].cpf, cpfBusca) == 0) { //usa strcmp para comparar os cpfs de 'i' e aquele que o usuário digitou     
            printf("Funcionário encontrado:\n");
            printf("Nome: %s\n", funcionarios[i].nome);//mostra o nome
            printf("CPF: %s\n", funcionarios[i].cpf); //mostra o cpf
            printf("Idade: %d\n", funcionarios[i].idade); //mostra a idade
            printf("Sexo: %s\n", funcionarios[i].sexo); //mostra o sexo
            printf("Salário: %.2f\n", funcionarios[i].salario); //mostra o salário
            return; //encerra a função
        }
    }

    printf("Funcionário com o CPF %s não encontrado.\n", cpfBusca); //se o cpf não for encontrado, mostra essa mensagem
}

//função para verificar quais funcionarios recebem mais do que a media salarial. Funcioanarios será para percorrer a lista na qual ficará armazenados os dados e x agirá como um "contador"
void salarioAcimaMedia(Funcionario funcionarios[], int x) { 
    if (x == 0) { //verifica se há algum cadastro de funcionario
        printf("Não há nenhum funcionário cadastrado!\n"); //caso entre nessa condição, exibe essa mensagem
        return;
    }

    float soma = 0; //soma o salario dos funcionários
    float media; //faz a média do salário dos funcionários

    for (int i = 0; i<x; i++) {
        soma += funcionarios[i].salario;
    } //vai somando cada salario de cada funcionario existente

    media = soma/x; //faz a conta para saber qual é a média final da empresa

    printf("\nMédia salarial: %.2f\n", media); //printa a média
    printf("Funcionários com salário acima da média:\n"); //e os funcionários que ganham mais do que essa média
   

    for (int i = 0; i < x; i++) { //exibi todos os dados dos funcionários acima da média salarial
         if (funcionarios[i].salario > media) {
            printf("Nome: %s\n", funcionarios[i].nome);
            printf("CPF: %s\n", funcionarios[i].cpf);
            printf("Idade: %d\n", funcionarios[i].idade);
            printf("Sexo: %s\n", funcionarios[i].sexo);
            printf("Salário: %.2f\n\n", funcionarios[i].salario);
            
        }
    }

}

// Função principal
void main() {
    int escolha; // Variável que armazena a escolha do usuário para seleção de opção do menu (switch)
    int x = 0; // Variável de referência para funcionamento das funções
    do { // Sempre exibirá o menu enquanto a condição for True
        
        // Opções do menu
        printf("1. Cadastrar novo funcionário\n"); // Opção 1
        printf("2. Buscar funcionário pelo CPF\n"); // Opção 2
        printf("3. Exibir funcionários com salário acima da média\n"); // Opção 3
        printf("4. Sair\n"); // Opção 4
        printf("O que deseja fazer? :"); 
        scanf("%d", &escolha); // "Ganha" a escolha de opção do usuário
        getchar(); // Sem ele o scanf deixa um '\n'
        
        // Declaração do menu que corresponde a váriavel 'escolha' 
        switch (escolha) {
            case 1: // Realiza a fução de cadastrar funcionario
                x=cadastrarFuncionario(x);
                break;
            case 2: // Realiza a função de buscar funcionario por CPF
                buscarCPF(funcionarios, x);
                break;
            case 3: // Realiza a função de exibir funcionario com salário acima da média
                salarioAcimaMedia(funcionarios, x);
                break;  
            case 4: // Realiza a função de sair
                printf("Saindo do sistema\n");
                break;
            default: // Se a 'escolha' receber um valor diferente do estipulado pelos 'cases', a função raiz é exibir "opção inválida"
                printf("Opção inválida, tente novamente.\n");
                break;
        }
    } while (escolha != 4); // Condição estipulada para que o 'do' continue funcionando. Caso a escolha for "4", a função "sair" é chamada e logo após o menu não reaparece já que a condição de funcionamento do 'do' foi quebrada
    
}