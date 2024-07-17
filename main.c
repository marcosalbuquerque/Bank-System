#include "program.c"

/**
 * @author: Marcos Albuquerque
 * @version: 1.0
*/
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
		printf("Erro ao abrir o arquivo de funcion�rios.\n");
		return 1;
	}
	if (relatorio == NULL) {+
		printf("Erro ao abrir o arquivo de relat�rio.\n");
		return 1;
	}
	setlocale(LC_ALL, "Portuguese");
	MenuPrincipal();
	return 0;
}
