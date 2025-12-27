#include <stdio.h>
#include <stdbool.h>

int main () {
    int SenhaDigitada;
    int SenhaCorreta = 2484;
    int tentativas = 3;
    bool acessopermitido;

    printf("\n --- bem-vindo ao caixa eletrônico --- \n");
    //usei o for para dar 3 tentativas para o usuario acertar a senha!
    for (int i = 0; i < tentativas; i++) {
        printf("Por Favor, digite a sua senha de 4 dígitos: ");

        if (scanf("%d", &SenhaDigitada) != 1) {
            printf("Erro: Entrada inválida. Use apenas números inteiros.\n");
            while (getchar () != '\n'); // usei o while getchar para limpar o lixo do teclado após a entrada inválida
            i--; // para não contar essa tentativa falha no contador
            continue; //continua o programa, sem dar retorno ao main
        } 
        
        if (SenhaDigitada == SenhaCorreta) { //aqui optei por usar if para verificar a senha
            acessopermitido = true;
            printf("\nSenha correta!\n");
            break; //break para quebrar o for
        } else {
            if (tentativas - 1 - i > 0) { //if para "Sempre que o numero de tentativas for maior que 0, continue e exiba isto".
                 printf("Senha incorreta! Você tem mais %d tentativa(s).\n", tentativas - 1 - i);
            }
        }
    }
    // aqui, se o acesso foi permitido, o programa começa de fato.

    if (acessopermitido) { 

        int opcao;
        double saldo = 1000;
        double saque, deposito;
        bool QuerSair; //declaração das variaveis locais 

        while (QuerSair == false) { //declaração do while para repetir o programa até que o usuario opte por sair.

            printf("\n ---Menu Principal --- \n");
            printf("");
            printf("1. Ver Saldo\n");
            printf("2. Sacar\n");
            printf("3. Realizar Depósito\n");
            printf("4. Sair\n");
            printf("--------------------------\n");
            
            printf("Digite a Opção desejada: ");
            if(scanf("%d", &opcao) != 1) { //verificando se o que o usuario escreveu é de fato um numero inteiro
                printf("Erro: Entrada inválida! Selecione uma opção de 1 a 4!\n");
                while (getchar () != '\n');
                continue;
            } else if (opcao > 4 || opcao <= 0) { //verificando se o usuario de fato colocou uma das opções descritas
                printf("Erro: opção inválida! Essa opção não existe, selecione uma opção de 1 a 4.\n");
                while (getchar () != '\n');
                continue;
            } else { //aqui segue o programa 
                switch (opcao) // declarei um switch para as opções do menu
                {
                case 1:
                    printf("Seu Saldo no momento é R$%.2f\n", saldo); //mostra saldo
                    printf("--------------------------\n");
                    break;
                case 2:
                    printf("--------------------------\n");
                    printf("\n --- MENU DE SAQUE ---\n");
                    printf("Seu Saldo no momento é R$%.2f\n", saldo); //aqui optei por mostrar o saldo e após isso pedir o saque.
                    printf("Quanto gostaria de sacar: R$");
                    if(scanf("%lf", &saque) != 1) { //outra verificação 
                         printf("Erro: Entrada inválida! Digite Apenas números de 0 em diante.\n");
                         while (getchar() != '\n');
                    } else if (saque > saldo) { //verificando se o saldo é suficiente para o saque
                         printf("Erro: Saldo Insuficiente!");
                         while(getchar() != '\n');
                    } else { 
                        printf("--------------------------\n");
                        saldo = (saldo - saque); //atualizei o saldo 
                        printf("Seu Saque de R$%.2f foi Realizado com sucesso!\n", saque);
                        printf("Seu Saldo Atual é de R$%.2f", saldo); //mostrei o saldo e o saque realizado
                        printf("--------------------------\n");
                    }
                    break; //alias, usei break para não dar um bug de loop e seguir para o menu principal normalmente
                case 3: 
                    printf("--------------------------\n");
                    printf("\n --- MENU DE DEPÓSITO ---\n");
                    printf("Seu Saldo no momento é R$%.2f", saldo); 
                    printf("Quanto Gostaria de Depositar: R$");
                    if(scanf("%lf", &deposito) != 1) { //verificação
                         printf("Erro: Entrada inválida. Digite Apenas números!\n");
                         while(getchar () != '\n'); 
                    } else if (deposito <= 0) { //verificação
                         printf("Erro: Valor insuficiente.");
                         while (getchar () != '\n');
                    } else {
                        printf("--------------------------\n");
                        saldo = saldo + deposito;
                        printf("Depósito de R$%.2f Realizado com sucesso!\n", deposito);
                        printf("Seu Saldo Atual é de R$%.2f", saldo);
                        printf("--------------------------\n");
                    }
                    break;
                case 4:
                    printf("--------------------------\n");
                    printf("Obrigado por utilizar nossos serviços!\n"); 
                    QuerSair = true; // aqui disse ao while que o usuario quer sair do programa
                    break; //quebrei o while
                default:
                    printf("Opção inválida!"); //verificando e garantindo acertos
                    break;
                }
            }
        }
    }
    return 0;
}