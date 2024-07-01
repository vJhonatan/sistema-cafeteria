#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <string.h>
#include <conio.h>

#define MAX_ITEM_LEN 50
#define MAX_PEDIDOS 5

    // ESTRUTURAS

// DADOS COLABORADOR
struct {
    char usuarioColab[50],senhaColab[50],usuarioLoginColab[50],senhaLoginColab[50];
    int opColaborador2;
}Colab;

// DADOS CLIENTE
struct {
    char usuarioCli[50],senhaCli[50],usuarioLoginCli[50],senhaLoginCli[50];
    int opCliente2;
}Cli;

// DADOS PEDIDO
typedef struct {
    char item[MAX_ITEM_LEN];
    float preco;
    int qtd;
}Ped;

// GLOBAIS
Ped pedidosPendentes[MAX_PEDIDOS];
int numPedidos = 0;
float totalPreco = 0;
int opPedido, qtd;

    // FUNÇÕES

// BANNER SISTEMA
void banner() {
    printf("\n\n\n\n========================================================================================================================\n");
    printf("\n---------------------------------------------  SEJA BEM VINDO A EXPRESS CAFÉ  ------------------------------------------\n\n");
    printf("========================================================================================================================\n");
}

// ABA COLABORADOR
void colaborador(){
    printf("                                                      ADMINISTRADOR                                                     ");
    printf("\n========================================================================================================================\n\n");
}

// ABA CLIENTE
void cliente() {
    printf("                                                         CLIENTE                                                  ");
    printf("\n========================================================================================================================\n\n");
}

// ANIMAÇAO DE ERRO
void error() {
    system("cls");
    banner();
    printf("\n                                          OPÇÃO INVÁLIDA! TENTE NOVAMENTE EM... ");
    Sleep(1500);
    printf("\n\n                                                           3... ");
    Sleep(700);
    printf("\n\n                                                           2... ");
    Sleep(700);
    printf("\n\n                                                           1...");
    Sleep(500);
    system("cls");
}

// FUNÇÃO COM OPÇOES DE LOGIN / CADASTRO
void opLogin(){
    printf("                                                   1. EFETUAR CADASTRO; \n\n");
    printf("                                                   2. EFETUAR LOGIN; \n\n");
    printf("                                                   3. VOLTAR PARA O INICIO; \n\n\n");
    printf("========================================================================================================================");
}

// OCULTAR CARACTERERS DA SENHA
void esconderSenha(char *password, int max_length) {
    int i = 0;
    char ch;
    while ((ch = getch()) != '\r' && i < max_length - 1) {
        if (ch == '\b') {
            if (i > 0) {
                printf("\b \b");
                i--;
            }
        } else {
            password[i++] = ch;
            printf("*");
        }
    }
    password[i] = '\0';
}

// ANIMAÇÃO DE ERRO AO CADASTRAR SENHA COM MENOS DE 8 DIGITOS
void errorSenha() {
    system("cls");
    banner();
    printf("\n                                  A SENHA DEVE TER NO MINIMO 8 DIGITOS! TENTE NOVAMENTE EM... ");
    Sleep(1500);
    printf("\n\n                                                            3... ");
    Sleep(700);
    printf("\n\n                                                            2... ");
    Sleep(700);
    printf("\n\n                                                            1...");
    Sleep(500);
    system("cls");
}

// ANIMAÇÃO DE ERRO SE USUARIO E SENHA ESTIVER INCORRETO AO REALIZAR O LOGIN
void errorLogin() {
    printf("                                  NOME DE USUARIO OU SENHA INCORRETOS! TENTE NOVAMENTE EM... ");
    Sleep(1500);
    printf("\n\n                                                             3... ");
    Sleep(700);
    printf("\n\n                                                             2... ");
    Sleep(700);
    printf("\n\n                                                             1...");
    Sleep(500);
    system("cls");
}

// CARDÁPIO
void cardapio() {
     printf("                                            |=================================|\n");
    printf("                                            |             CARDÁPIO            |\n");
    printf("                                            |=================================|\n");
    printf("                                            |                                 |\n");
    printf("                                            |                                 |\n");
    printf("                                            |  1. Café Preto........R$ 3.50   |\n");
    printf("                                            |                                 |\n");
    printf("                                            |  2. Café com Leite....R$ 4.00   |\n");
    printf("                                            |                                 |\n");
    printf("                                            |  3. Cappuccino........R$ 5.00   |\n");
    printf("                                            |                                 |\n");
    printf("                                            |  4. Café Expresso.....R$ 3.00   |\n");
    printf("                                            |                                 |\n");
    printf("                                            |  5. Mocha.............R$ 5.50   |\n");
    printf("                                            |                                 |\n");
    printf("                                            |  6. Café Americano....R$ 3.50   |\n");
    printf("                                            |                                 |\n");
    printf("                                            |  7. Latte.............R$ 4.50   |\n");
    printf("                                            |                                 |\n");
    printf("                                            |  8. Macchiato.........R$ 4.00   |\n");
    printf("                                            |_________________________________|\n");
}

// ADICIONAR PEDIDO
void addPedido(int qtd, int opPedido){
    addPedido:
        if(numPedidos < MAX_PEDIDOS){
            Ped novoPedido;
            switch(opPedido){
                case 1:
                    strcpy(novoPedido.item,"Café Preto");
                    novoPedido.preco = 3.50;
                    break;
                case 2:
                    strcpy(novoPedido.item,"Café com Leite");
                    novoPedido.preco = 4.00;
                    break;
                case 3:
                    strcpy(novoPedido.item,"Cappuccino");
                    novoPedido.preco = 5.00;
                    break;
                case 4:
                    strcpy(novoPedido.item,"Café Expresso");
                    novoPedido.preco = 3.00;
                    break;
                case 5:
                    strcpy(novoPedido.item,"Mocha");
                    novoPedido.preco = 5.50;
                    break;
                case 6:
                    strcpy(novoPedido.item,"Café Americano");
                    novoPedido.preco = 3.50;
                    break;
                case 7:
                    strcpy(novoPedido.item,"Latte");
                    novoPedido.preco = 4.50;
                    break;
                case 8:
                    strcpy(novoPedido.item,"Macchiato");
                    novoPedido.preco = 4.00;
                    break;
                default:
                    error();
                    goto addPedido;
            }
            novoPedido.qtd = qtd;
            pedidosPendentes[numPedidos++] = novoPedido;
            totalPreco += novoPedido.preco * qtd;
            printf("\n                                               PEDIDO CONCLUÍDO COM SUCESSO!");
            } else {
                printf("\n                                                LIMITE DE PEDIDOS ATINGIDO!");
            }
}

// PEDIDOS PENDENTES DE FORMA CENTRALIZADA
void PedidosPend() {
    int i;
    printf("                   -------------------------------------------------------------------------------\n");
    printf("                   |                              PEDIDOS EM ANDAMENTO                           |\n");
    printf("                   |-----------------------------------------------------------------------------|\n");

    for (i = 0; i < numPedidos; i++) {
        int len = strlen(pedidosPendentes[i].item);
        int spaces = (50 - len) / 2;
        printf("                   |%*s%s%*s%11d unidade(s)     |\n", spaces, "", pedidosPendentes[i].item, spaces + (len % 2 != 0), "", pedidosPendentes[i].qtd);
        printf("                   |-----------------------------------------------------------------------------|\n");
    }
}

// NENHUM PEDIDO EM ANDAMENTO
void zeroPedido(){
    printf("\n");
    printf("                   -------------------------------------------------------------------------------\n");
    printf("                   |                              PEDIDOS EM ANDAMENTO                           |\n");
    printf("                   |-----------------------------------------------------------------------------|\n");
    printf("                   |                                                                             |\n");
    printf("                   |                           NENHUM PEDIDO EM ANDAMENTO                        |\n");
    printf("                   |                                                                             |\n");
    printf("                   |_____________________________________________________________________________|\n");
    printf("\n");
}

// CENTRALIZA TOTAL VALOR
void printTotalPrice(float totalPreco) {
    char buffer[20];
    sprintf(buffer, "Total: R$ %.2f", totalPreco);
    int totalWidth = 44;
    int contentWidth = strlen(buffer);
    int spaces = (totalWidth - contentWidth - 2) / 2;
    printf("                   |                   %*s%s%*s                |\n", spaces, "", buffer, spaces + (totalWidth - contentWidth - 2) % 2, "");
}

// INICIO PROGRAMA
int main () {

    setlocale(LC_ALL, "Portuguese");

    // VARIAVEIS
    int opInicio,opCliente,opColaborador,continuar=1,opCard,opPend,opPendColab,opCardColab;

    // DO WHILE PRINCIPAL DO SISTEMA
    inicio:
        system("cls");
        do {
            banner();
            printf("\n                                                    1. ADMINISTRADOR;");
            printf("\n\n                                                    2. CLIENTE;");
            printf("\n\n                                                    3. SAIR;");
            printf("\n\n========================================================================================================================");
            printf("\n\n                                           ENTRE COMO ADMINISTRADOR OU CLIENTE: ");
            scanf("%d",&opInicio);

            // INICIO SWITCH CASE - TELA INICIAL
            switch (opInicio) {

            // AREA COLABORADOR
            case 1:
                tela_colaborador: // TELA DE CADASTRO E LOGIN COLABORADOR
                    system("cls");
                    banner();
                    colaborador();
                    opLogin();
                    printf("\n\n                                                ESCOLHA A OPÇÃO DESEJADA: ");
                    scanf("%d",&opColaborador);

                    // SWITCH CASE PARA OPÇAO DE CADASTRO / LOGIN COLABORADOR
                    switch(opColaborador){

                        //CADASTRO COLABORADOR
                        case 1:
                            cadastro_colaborador:
                                system("cls");
                                banner();
                                colaborador();
                                printf("                                                        USUARIO: ");
                                scanf(" %[^\n]",Colab.usuarioColab);
                                printf("\n                                                        SENHA: ");
                                esconderSenha(Colab.senhaColab, sizeof(Colab.senhaColab));

                                // CONDIÇÃO SENHA MINIMO 8 DIGITOS
                                if (strlen(Colab.senhaColab) < 8){
                                    errorSenha();
                                    goto cadastro_colaborador;
                                }
                                system("cls");
                                banner();
                                colaborador();
                                printf("                                    CADASTRO EFETUADO COM SUCESSO! SEJA BEM VINDO %s!",Colab.usuarioColab);
                                Sleep(2000);

                                // INTERFACE COLABORADOR
                                interfaceColab:
                                    system("cls");
                                    banner();
                                    colaborador();
                                    printf("                                                 1. VER CARDÁPIO;");
                                    printf("\n\n                                                 2. VER PEDIDOS EM ANDAMENTO;");
                                    printf("\n\n                                                 3. VOLTAR;");
                                    printf("\n\n                                                 4. IR PARA O INICIO;");
                                    printf("\n\n========================================================================================================================");
                                    printf("\n\n                                                ESCOLHA A OPÇÃO DESEJADA: ");
                                    scanf("%d",&Colab.opColaborador2);
                                    switch(Colab.opColaborador2){
                                        case 1:
                                            cardColab:
                                                system("cls");
                                                banner();
                                                colaborador();
                                                cardapio();
                                                printf("\n========================================================================================================================");
                                                printf("\n\n                                                   DIGITE 1 PARA VOLTAR: ");
                                                scanf("%d",&opCardColab);
                                                switch(opCardColab){
                                                    case 1:
                                                        goto interfaceColab;
                                                        break;
                                                    default:
                                                        error();
                                                        goto cardColab;
                                                }
                                        case 2:
                                            pedidosPendColab:
                                                system("cls");
                                                banner();
                                                colaborador();
                                                if(numPedidos == 0){
                                                    zeroPedido();
                                                } else {
                                                    PedidosPend();
                                                }
                                                printf("\n========================================================================================================================");
                                                printf("\n\n                                                   DIGITE 1 PARA VOLTAR: ");
                                                scanf("%d",&opPendColab);
                                                switch(opPendColab){
                                                        case 1:
                                                            goto interfaceColab;
                                                            break;
                                                        default:
                                                            error();
                                                            goto pedidosPendColab;
                                                    }
                                            break;
                                        case 3:
                                            system("cls");
                                            goto tela_colaborador;
                                            break;
                                        case 4:
                                            system("cls");
                                            goto inicio;
                                            break;
                                        default:
                                            error();
                                            goto interfaceColab;
                                            break;
                                    }
                            break;

                        //LOGIN COLABORADOR
                        case 2:
                            login_colaborador:
                                system("cls");
                                banner();
                                colaborador();
                                printf("                                                         USUARIO: ");
                                scanf(" %[^\n]",Colab.usuarioLoginColab);
                                printf("\n                                                         SENHA: ");
                                esconderSenha(Colab.senhaLoginColab, sizeof(Colab.senhaLoginColab));

                                // VERIFICANDO SE USUARIO E SENHA ESTAO CORRETOS DE ACORDO COM CADASTRO
                                if (strcmp(Colab.usuarioLoginColab, Colab.usuarioColab) == 0 && strcmp(Colab.senhaLoginColab, Colab.senhaColab) == 0){
                                    system("cls");
                                    banner();
                                    colaborador();
                                    printf("                                              LOGIN EFETUADO COM SUCESSO! SEJA BEM VINDO %s!",Colab.senhaLoginColab);
                                    Sleep(2000);
                                    system("cls");
                                    goto interfaceColab;
                                } else {
                                    system("cls");
                                    banner();
                                    colaborador();
                                    errorLogin();
                                    goto login_colaborador;
                                }
                            break;

                        // VOLTAR PARAO INICIO
                        case 3:
                            system("cls");
                            goto inicio;
                            break;
                        default:
                            error();
                            goto tela_colaborador;
                            break;
                        }
                break;

            // AREA CLIENTE
            case 2:
                tela_cliente:
                    system("cls");
                    banner();
                    cliente();
                    opLogin();
                    printf("\n\n                                                ESCOLHA A OPÇÃO DESEJADA: ");
                    scanf("%d",&opCliente);

                    // SWITCH CASE PARA OPÇAO DE CADASTRO / LOGIN CLIENTE
                    switch(opCliente){

                        // CADASTRO CLIENTE
                        case 1:
                            cadastro_cliente:
                                system("cls");
                                banner();
                                cliente();

                                printf("                                                        USUARIO: ");
                                scanf(" %[^\n]",Cli.usuarioCli);
                                printf("\n                                                        SENHA: ");
                                esconderSenha(Cli.senhaCli, sizeof(Cli.senhaCli));

                                // CONDIÇÃO SENHA MINIMO 8 DIGITOS
                                if (strlen(Cli.senhaCli) < 8){
                                    errorSenha();
                                    goto cadastro_cliente;
                                }

                                system("cls");
                                banner();
                                cliente();
                                printf("                                     CADASTRO EFETUADO COM SUCESSO! SEJA BEM VINDO %s!",Cli.usuarioCli);
                                Sleep(2000);

                                // INTERFACE CLIENTE
                                interfaceCliente:
                                    system("cls");
                                    banner();
                                    cliente();
                                    printf("                                                    1. CARDÁPIO;");
                                    printf("\n\n                                                    2. FAZER PEDIDO;");
                                    printf("\n\n                                                    3. VER PEDIDOS EM ANDAMENTO;");
                                    printf("\n\n                                                    4. VOLTAR;");
                                    printf("\n\n                                                    5. IR PARA O INICIO;");
                                    printf("\n\n========================================================================================================================");
                                    printf("\n\n                                                ESCOLHA A OPÇÃO DESEJADA: ");
                                    scanf("%d",&Cli.opCliente2);

                                    switch(Cli.opCliente2){
                                        case 1:
                                             cardapio:
                                                system("cls");
                                                banner();
                                                cliente();
                                                cardapio();
                                                printf("\n========================================================================================================================");
                                                printf("\n\n                                                   DIGITE 1 PARA VOLTAR: ");
                                                scanf("%d",&opCard);

                                                switch(opCard){

                                                    case 1:
                                                        goto interfaceCliente;
                                                        break;
                                                    default:
                                                        error();
                                                        goto cardapio;
                                                }
                                                break;
                                        case 2:
                                            fazerPedido:
                                                system("cls");
                                                banner();
                                                cliente();
                                                cardapio();
                                                printf("\n                                            DIGITE O NÚMERO DO ITEM QUE DESEJA: ");
                                                scanf("%d",&opPedido);
                                                printf("                                            INFORME A QUANTIDADE: ");
                                                scanf("%d",&qtd);
                                                system("cls");
                                                banner();
                                                cliente();
                                                addPedido(qtd, opPedido);
                                                Sleep(2500);
                                                goto pedidosPend;
                                                break;
                                        case 3:
                                            pedidosPend:
                                                system("cls");
                                                banner();
                                                cliente();
                                                PedidosPend();
                                                printf("                   |                                                                             |\n");
                                                printf("                   |                                                                             |\n");
                                                printTotalPrice(totalPreco);
                                                printf("                   |                                                                             |\n");
                                                printf("                   |_____________________________________________________________________________|\n");
                                                printf("\n                                                   1. FAZER OUTRO PEDIDO;");
                                                printf("\n\n                                                   2. VOLTAR;");
                                                printf("\n\n========================================================================================================================");
                                                printf("\n\n                                               ESCOLHA A OPÇÃO DESEJADA: ");
                                                scanf("%d",&opPend);
                                                switch(opPend){

                                                    case 1:
                                                        goto fazerPedido;
                                                        break;
                                                    case 2:
                                                        goto interfaceCliente;
                                                        break;
                                                    default:
                                                        error();
                                                        goto pedidosPend;
                                                }
                                                break;
                                        case 4:
                                            system("cls");
                                            goto tela_cliente;
                                            break;
                                        case 5:
                                            system("cls");
                                            goto inicio;
                                            break;
                                        default:
                                            error();
                                            goto interfaceCliente;
                                            break;
                                    }
                            break;

                        // LOGIN CLIENTE
                        case 2:
                            login_cliente:
                                system("cls");
                                banner();
                                cliente();
                                printf("                                                        USUARIO: ");
                                scanf(" %[^\n]",Cli.usuarioLoginCli);
                                printf("\n                                                        SENHA: ");
                                esconderSenha(Cli.senhaCli, sizeof(Cli.senhaCli));

                                // VERIFICANDO SE USUARIO E SENHA ESTAO CORRETOS DE ACORDO COM CADASTRO
                                if (strcmp(Cli.usuarioLoginCli, Cli.usuarioCli) == 0 && strcmp(Cli.senhaLoginCli, Cli.senhaCli) == 0){
                                    system("cls");
                                    banner();
                                    cliente();
                                    printf("                                      LOGIN EFETUADO COM SUCESSO. SEJA BEM VINDO %s!",Cli.usuarioLoginCli);
                                    Sleep(1700);
                                    system("cls");
                                    goto interfaceCliente;
                                } else {
                                    system("cls");
                                    banner();
                                    cliente();
                                    errorLogin();
                                    goto login_cliente;
                                }
                            break;

                        // VOLTA INICIO
                        case 3:
                            system("cls");
                            goto inicio;
                            break;
                        default:
                            error();
                            goto tela_cliente;
                            break;
                        }
                break;
            case 3:
                system("cls");
                banner();
                Sleep(300);
                printf("\n\n                                              ******************************\n");
                Sleep(300);
                printf("                                              ******************************\n");
                Sleep(300);
                printf("                                              ****                      ****\n");
                Sleep(300);
                printf("                                              ****  PROGRAMA ENCERRADO  ****\n");
                Sleep(300);
                printf("                                              ****                      ****\n");
                Sleep(300);
                printf("                                              ******************************\n");
                Sleep(300);
                printf("                                              ******************************\n\n\n\n\n\n\n\n\n");
                Sleep(300);
                continuar = 0;
                break;
            default:
                error();
                goto inicio;
                break;
            } // FIM SWITCH CASE TELA INICIAL
        } while(continuar); // FIM WHILE
    return 0;
} // FIM PROGRAMA
