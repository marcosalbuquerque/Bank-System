#include "program.c"

int main() {
	arqcliente = fopen(FILECLIENTE, "ab+");
	arqfuncionario = fopen(FILEFUNCIONARIO, "ab+");
	relatorio = fopen(FILERELATORIO, "w");
	extrato = fopen(FILEEXTRATO, "w");
	
	if (arqcliente == NULL) {
		printf("Erro ao abrir o arquivo de clientes.\n");
		return 1;
	}
	if (arqfuncionario == NULL) {
		printf("Erro ao abrir o arquivo de funcionários.\n");
		return 1;
	}
	if (relatorio == NULL) {+
		printf("Erro ao abrir o arquivo de relatório.\n");
		return 1;
	}
	setlocale(LC_ALL, "Portuguese");
	MenuPrincipal();
	return 0;
}
