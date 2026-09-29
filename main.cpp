/*
  INF101 - Programacao de Computadores I
  Trabalho: Sistema de Registro e Gestao de Contas Bancarias
  Aluno: Gabriel da Silva Monteiro
  Matricula: 26514
*/

#include <iostream>
#include <string>

using namespace std;

int main() {

    // quantidade maxima de contas
    const int TAMANHO_MAXIMO = 5;

    // dados das contas
    int numeroConta[TAMANHO_MAXIMO];
    string nomeCliente[TAMANHO_MAXIMO];
    string cpf[TAMANHO_MAXIMO];
    int tipoConta[TAMANHO_MAXIMO];
    double saldo[TAMANHO_MAXIMO];
    bool contaAtiva[TAMANHO_MAXIMO];

    // controle do programa
    int totalContas = 0;
    int opcao = 0;

    // valores iniciais
    for (int i = 0; i < TAMANHO_MAXIMO; i++) {
        numeroConta[i] = 0;
        nomeCliente[i] = "";
        cpf[i] = "";
        tipoConta[i] = 0;
        saldo[i] = 0.0;
        contaAtiva[i] = false;
    }

    do {
        cout << "\n*****************************\n";
        cout << "****       Banco Gab      ****\n";
        cout << "*****************************\n";
        cout << "1 - Cadastrar conta\n";
        cout << "2 - Consultar conta\n";
        cout << "3 - Verificar saldo\n";
        cout << "4 - Alterar tipo da conta\n";
        cout << "5 - Ativar/Desativar conta\n";
        cout << "6 - Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {

            case 1: {

                if (totalContas >= TAMANHO_MAXIMO) {
                    cout << "\nErro: Limite maximo de "
                         << TAMANHO_MAXIMO
                         << " contas atingido!\n";
                    break;
                }

                cout << "\n--- Cadastro de Conta ---\n";

                int numTemp;

                do {
                    cout << "Digite o numero da conta: ";
                    cin >> numTemp;

                    if (numTemp <= 0) {
                        cout << "Erro: O numero da conta deve ser maior que zero!\n";
                    }

                } while (numTemp <= 0);

                numeroConta[totalContas] = numTemp;

                cin.ignore();

                cout << "Nome do titular: ";
                getline(cin, nomeCliente[totalContas]);

                cout << "CPF: ";
                getline(cin, cpf[totalContas]);

                int tipoTemp;

                do {
                    cout << "Tipo da conta (1 = Corrente, 2 = Poupanca): ";
                    cin >> tipoTemp;

                    if (tipoTemp != 1 && tipoTemp != 2) {
                        cout << "Erro: Digite 1 ou 2.\n";
                    }

                } while (tipoTemp != 1 && tipoTemp != 2);

                tipoConta[totalContas] = tipoTemp;

                double saldoTemp;

                do {
                    cout << "Saldo inicial (R$): ";
                    cin >> saldoTemp;

                    if (saldoTemp < 0) {
                        cout << "Erro: O saldo nao pode ser negativo!\n";
                    }

                } while (saldoTemp < 0);

                saldo[totalContas] = saldoTemp;

                contaAtiva[totalContas] = true;

                totalContas++;

                cout << "\nConta cadastrada com sucesso!\n";

                break;
            }

            case 2: {

                if (totalContas == 0) {

                    cout << "\nNenhuma conta cadastrada ainda.\n";

                } else {

                    cout << "\n--- Contas Cadastradas ---\n";

                    for (int i = 0; i < totalContas; i++) {

                        cout << "\nConta " << (i + 1) << "\n";
                        cout << "Numero: " << numeroConta[i] << "\n";
                        cout << "Titular: " << nomeCliente[i] << "\n";
                        cout << "CPF: " << cpf[i] << "\n";

                        cout << "Tipo: "
                             << (tipoConta[i] == 1 ? "Corrente" : "Poupanca")
                             << "\n";

                        cout << "Status: "
                             << (contaAtiva[i] ? "Ativa" : "Inativa")
                             << "\n";
                    }
                }

                break;
            }

            case 3: {

                if (totalContas == 0) {

                    cout << "\nNenhuma conta cadastrada ainda.\n";

                } else {

                    int indice;

                    cout << "\nDigite o indice da conta (1 a "
                         << totalContas << "): ";

                    cin >> indice;

                    indice--;

                    if (indice < 0 || indice >= totalContas) {

                        cout << "Erro: Conta nao encontrada!\n";

                    } else if (!contaAtiva[indice]) {

                        cout << "A conta esta inativa.\n";

                    } else {

                        cout << "Saldo da conta "
                             << numeroConta[indice]
                             << ": R$ "
                             << saldo[indice]
                             << "\n";
                    }
                }

                break;
            }

            case 4: {

                if (totalContas == 0) {

                    cout << "\nNenhuma conta cadastrada ainda.\n";

                } else {

                    int indice;

                    cout << "\nDigite o indice da conta para alterar (1 a "
                         << totalContas << "): ";

                    cin >> indice;

                    indice--;

                    if (indice < 0 || indice >= totalContas) {

                        cout << "Erro: Conta nao encontrada!\n";

                    } else if (!contaAtiva[indice]) {

                        cout << "A conta esta inativa.\n";

                    } else {

                        if (tipoConta[indice] == 1) {
                            tipoConta[indice] = 2;
                        } else {
                            tipoConta[indice] = 1;
                        }

                        cout << "Tipo alterado para: "
                             << (tipoConta[indice] == 1
                                     ? "Corrente"
                                     : "Poupanca")
                             << "\n";
                    }
                }

                break;
            }

            case 5: {

                if (totalContas == 0) {

                    cout << "\nNenhuma conta cadastrada ainda.\n";

                } else {

                    int indice;

                    cout << "\nDigite o indice da conta (1 a "
                         << totalContas << "): ";

                    cin >> indice;

                    indice--;

                    if (indice < 0 || indice >= totalContas) {

                        cout << "Erro: Conta nao encontrada!\n";

                    } else {

                        contaAtiva[indice] = !contaAtiva[indice];

                        cout << "Status alterado para: "
                             << (contaAtiva[indice]
                                     ? "Ativa"
                                     : "Inativa")
                             << "\n";
                    }
                }

                break;
            }

            case 6:

                cout << "\nEncerrando o programa.\n";

                break;

            default:

                cout << "\nOpcao invalida.\n";

                break;
        }

    } while (opcao != 6);

    return 0;
}