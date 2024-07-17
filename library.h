#include <stdio.h>
#include <unistd.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//#include <xlsxwriter.h>

#define SENHA 123456
#define LIM 100
#define FILECLIENTE "clientes.dat"
#define FILEFUNCIONARIO "funcionarios.dat"
#define FILERELATORIO "relatorio.csv"
#define FILEEXTRATO "extrato.csv"

FILE *arqcliente, *arqfuncionario, *relatorio, *extrato;

// STRUCTS
struct Data {
	char dia[3];
	char mes[3];
	char ano[5];
};

struct Telefone
{
	char DDD[3];
	char numero[10];
};


struct Endereco {
	char estado[LIM];
	char cidade[LIM];
	char bairro[LIM];
	int cep;
	char rua[LIM];
	int numero;
};

struct Funcionario {
	int codigo;
	char cargo[LIM];
	char nome[LIM];
	char cpf[11];
	struct Data nascimento;
	struct Telefone celular;
	struct Endereco endereco;
	int senha;
	
};

struct Conta {
	int agencia;
	int numero;  
	float limite; // CONTA CORRENTE
	struct Data vencimento; // CONTA CORRENTE
	char nome[LIM];
	char cpf[11];
	struct Data nascimento;
	struct Telefone celular;
	struct Endereco endereco;
	int senha;
	int tipo; // 0 para corrente e 1 para poupan?a
	float saldo;
	
};

// MENU
void MenuPrincipal();
void MenuFuncionario();
void MenuCliente();
void MenuAberturaDeConta();
void MenuConsulta();
void MenuAlterarDados();

// SENHA
void CheckSenha(int *flagSenha); // ADMIN
int flagSenha = 0;

// CLEAR TERMINAL
void clear();

// CONTA
void AberturaCP(FILE *arqcliente);
void AberturaCC(FILE *arqcliente);
void EncerramentoDeConta(FILE *arqcliente);
void ConsultarConta(FILE *arqcliente);
void ConsultarFuncionario(FILE *arqfuncionario);
void ConsultarCliente(FILE *arqcliente);
void AlterarConta(FILE *arqcliente);
void AberturaFuncionario(FILE *arqfuncionario);
void GerarRelatorio(FILE *arqcliente, FILE *relatorio);
void Saldo(FILE *arqcliente);
void Deposito(FILE *arqcliente);
void Saque(FILE *arqcliente);
void Limite(FILE *arqcliente);
void Extrato(FILE *arqcliente, FILE *extrato);
