#include "library.h"


void clear() {
	system("cls");
}

void MenuPrincipal() {
	int op;
	do {
		clear();
		
		printf("------ MENU PRINCIPAL ------\n");
		printf("1 - FUNCIONARIO\n");
		printf("2 - CLIENTE\n");
		printf("3 - SAIR\n");
		printf("-> ");
		scanf("%d", &op);
		switch(op) {
			case 1:
				CheckSenha(&flagSenha);
				if (flagSenha == 1)
					MenuFuncionario();
				break;
			case 2:
					MenuCliente();
				break;
			case 3:
				printf("\nSaindo...");
				fclose(arqcliente);
				sleep(1);
				break;
				default:
				printf("Opção incorreta, tente novamente.");
				sleep(1);
				break;
		}
	} while (op != 3);
}

void MenuFuncionario() {
	int op;
	do {
		clear();
		
		printf("------ MENU FUNCIONARIO ------\n");
		printf("1 - ABERTURA DE CONTA\n");
		printf("2 - ENCERRAMENTO DE CONTA\n");
		printf("3 - CONSULTAR DADOS\n");
		printf("4 - ALTERAR DADOS\n");
		printf("5 - CADASTRO DE FUNCIONARIO\n");
		printf("6 - GERAR RELATÁRIO\n");
		printf("7 - SAIR\n");
		printf("-> ");
		scanf("%d", &op);
		switch(op) {
			case 1:
				MenuAberturaDeConta();
				break;
			case 2:
				EncerramentoDeConta(arqcliente);
				break;
			case 3:
				MenuConsulta();
				break;
			case 4:
				MenuAlterarDados();
				break;
			case 5:
				AberturaFuncionario(arqfuncionario);
				break;
			case 6:
				GerarRelatorio(arqcliente, relatorio);
				break;
			case 7:
				break;
			default:
				printf("Opção incorreta, tente novamente.");
				sleep(1);
				break;
		}
	} while (op != 7);
}

void MenuAberturaDeConta() {
	int op;
	do {
		clear();
		printf("------ ABERTURA DE CONTA ------\n");
		printf("1 - CONTA POUPAN?A - CP\n");
		printf("2 - CONTA CORRENTE - CC\n");
		printf("3 - VOLTAR\n");
		printf("-> ");
		scanf("%d", &op);
	switch (op)
	{
		case 1:
			AberturaCP(arqcliente);
			break;
		case 2:
			AberturaCC(arqcliente);/////////conta corrente
			break; 
		case 3:
			break;
		default:
			printf("Opção incorreta, tente novamente.");
			sleep(1);
			break;
		}
	} while (op != 3);
}

void MenuCliente() {
	int op;
	do {
		clear();
		
		printf("------ MENU CLIENTE ------\n");
		printf("1 - SALDO\n");
		printf("2 - DEPOSITO\n");
		printf("3 - SAQUE\n");
		printf("4 - EXTRATO\n");
		printf("5 - CONSULTAR LIMITE\n");
		printf("6 - SAIR\n");
		printf("-> ");
		scanf("%d", &op);
		switch(op) {
			case 1:
				Saldo(arqcliente);
				break;
			case 2:
				Deposito(arqcliente);
				break;
			case 3:
				Saque(arqcliente);
				break;
			case 4:
				Extrato(arqcliente, extrato);
				break;
			case 5:
				Limite(arqcliente);
			case 6:
				break;
			default:
				printf("Opção incorreta, tente novamente.");
				sleep(1);
				break;
		}
	} while (op != 6);	
}

void MenuConsulta() {
	int op;
	do {
		clear();
		
		printf("------ CONSULTAR DADOS ------\n");
		printf("1 - CONSULTAR CONTA\n");
		printf("2 - CONSULTAR FUNCION?RIO\n");
		printf("3 - CONSULTAR CLIENTE\n");
		printf("4 - SAIR\n");
		printf("-> ");
		scanf("%d", &op);
		switch(op) {
			case 1:
				ConsultarConta(arqcliente);
				break;
			case 2:
				ConsultarFuncionario(arqfuncionario);
				break;
			case 3:
				ConsultarCliente(arqcliente);
				break;
			case 4:
				break;
			default:
				printf("Opção incorreta, tente novamente.");
				sleep(1);
				break;
		}
	} while (op != 4);	
}

void MenuAlterarDados() {
	int op;
	do {
		clear();
		
		printf("------ ALTERAR DADOS ------\n");
		printf("1 - ALTERAR CONTA\n");
		printf("2 - ALTERAR FUNCION?RIO\n");
		printf("3 - ALTERAR CLIENTE\n");
		printf("4 - VOLTAR\n");
		printf("-> ");
		scanf("%d", &op);
		switch(op) {
			case 1:
				AlterarConta(arqcliente);
				break;
			case 2:
				AlterarFuncionario(arqfuncionario);	
				break;
			case 3:
				AlterarCliente(arqcliente);
				break;
			case 4:
				
				break;
			default:
				printf("Opção incorreta, tente novamente.");
				sleep(1);
				break;
		}
	} while (op != 4);	
}

void CheckSenha(int *flagSenha) { // ADMIN
	int senha;
	clear();
	printf("Digite a senha para acesso: ");
	scanf("%d", &senha);
	if (senha == SENHA) {
		(*flagSenha)++;
	} else {
		printf("Senha incorreta, tente novamente.");
		sleep(1);
	}
}

void AberturaCP(FILE *arq) {
	struct Conta usuario;
	usuario.tipo = 1;
	fclose(arq);
	clear();

	printf("------ CADASTRO ------\n");

	printf("Informe o nome completo do cliente: ");
	fflush(stdin);
	fgets(usuario.nome, sizeof(usuario.nome), stdin);
	usuario.nome[strcspn(usuario.nome, "\n")] = '\0';

	printf("Infome a senha do cliente (apenas números): ");
	scanf("%d", &usuario.senha);
	printf("Informe o CPF do cliente (apenas números): ");
	scanf("%s", &usuario.cpf);

	printf("Informe a data de nascimento do cliente (DD/MM/AAAA): ");
	scanf("%2s/%2s/%4s", &usuario.nascimento.dia, &usuario.nascimento.mes, &usuario.nascimento.ano);


	printf("Informe a Agência: ");
	scanf("%d", &usuario.agencia);

	printf("Informe o Número da Conta: ");
	scanf("%d", &usuario.numero);

	printf("Informe o Número do celular (XX XXXXXXXXX): ");
	scanf("%2s %9s", &usuario.celular.DDD, &usuario.celular.numero);

	printf("--- ENDEREÇO ---\n");
	printf("Estado: ");
	fflush(stdin);
	fgets(usuario.endereco.estado, sizeof(usuario.endereco.estado), stdin);
	usuario.endereco.estado[strcspn(usuario.endereco.estado, "\n")] = '\0';
	printf("Cidade: ");
	fflush(stdin);
	fgets(usuario.endereco.cidade, sizeof(usuario.endereco.cidade), stdin);
	usuario.endereco.cidade[strcspn(usuario.endereco.cidade, "\n")] = '\0';
	printf("Bairro: ");
	fflush(stdin);
	fgets(usuario.endereco.bairro, sizeof(usuario.endereco.bairro), stdin);
	usuario.endereco.bairro[strcspn(usuario.endereco.bairro, "\n")] = '\0';
	printf("CEP: ");
	scanf("%d", &usuario.endereco.cep);
	printf("Rua: ");
	fflush(stdin);
	fgets(usuario.endereco.rua, sizeof(usuario.endereco.rua), stdin);
	usuario.endereco.rua[strcspn(usuario.endereco.rua, "\n")] = '\0';
	printf("Numero: ");
	scanf("%d", &usuario.endereco.numero);
	
	arq = fopen(FILECLIENTE, "ab+");
	fseek(arq, 0, SEEK_END);
	fwrite(&usuario, sizeof(struct Conta), 1, arq);
	fclose(arq);

	printf("Cliente cadastrado com sucesso! \n");
	sleep(1);
}
void AberturaCC(FILE *arq) {
	struct Conta usuario;
	usuario.tipo = 0;
	fclose(arq);
	clear();

	printf("------ CADASTRO ------\n");

	printf("Informe o nome completo do cliente: ");
	fflush(stdin);
	fgets(usuario.nome, sizeof(usuario.nome), stdin);
	usuario.nome[strcspn(usuario.nome, "\n")] = '\0';

	printf("Infome a senha do cliente: ");
	scanf("%d", &usuario.senha);
	
	fflush(stdin);
	printf("Informe o CPF do cliente (apenas n?meros): ");
	scanf("%s", &usuario.cpf);

	printf("Informe a data de nascimento do cliente (DD/MM/AAAA): ");
	scanf("%2s/%2s/%4s", &usuario.nascimento.dia, &usuario.nascimento.mes, &usuario.nascimento.ano);

	printf("Informe o n?mero do celular (XX XXXXXXXXX): ");
	scanf("%2s %9s", &usuario.celular.DDD, &usuario.celular.numero);

	printf("Informe o Limite: ");
	scanf("%f", &usuario.limite);

	printf("Informe a Agência: ");
	scanf("%d", &usuario.agencia);

	printf("Informe o Número da Conta: ");
	scanf("%d", &usuario.numero);

	printf("Informe a Data De Vencimento (MM/AA): ");
	scanf("%2s/%2s", &usuario.vencimento.mes, &usuario.vencimento.ano);


	printf("--- ENDEREÇO ---\n");
	printf("Estado: ");
	scanf("%s", &usuario.endereco.estado);
	printf("Cidade: ");
	fflush(stdin);
	fgets(usuario.endereco.cidade, sizeof(usuario.endereco.cidade), stdin);
	usuario.endereco.cidade[strcspn(usuario.endereco.cidade, "\n")] = '\0';
	printf("Bairro: ");
	fflush(stdin);
	fgets(usuario.endereco.bairro, sizeof(usuario.endereco.bairro), stdin);
	usuario.endereco.bairro[strcspn(usuario.endereco.bairro, "\n")] = '\0';
	printf("CEP: ");
	scanf("%d", &usuario.endereco.cep);
	printf("Rua: ");
	fflush(stdin);
	fgets(usuario.endereco.rua, sizeof(usuario.endereco.rua), stdin);
	usuario.endereco.rua[strcspn(usuario.endereco.rua, "\n")] = '\0';
	printf("Numero: ");
	scanf("%d", &usuario.endereco.numero);

	arq = fopen(FILECLIENTE, "ab+");
	fseek(arq, 0, SEEK_END);
	fwrite(&usuario, sizeof(struct Conta), 1, arq);
	fclose(arq);
	
	printf("Cliente cadastrado com sucesso! \n");
	sleep(1);
}
void EncerramentoDeConta(FILE *arq) {
	clear();
	FILE *temp;
	fclose(arq);
	struct Conta cliente;
	int encontrado = 0;
	char nome[LIM];
	int check;

	printf("Informe o nome completo do cliente: ");
	fflush(stdin);
	fgets(nome, sizeof(nome), stdin);
	nome[strcspn(nome, "\n")] = '\0';
	arq = fopen(FILECLIENTE, "rb");
	
	if(arq == NULL){
		printf("Nenhum usuario cadastrado.\n");
		return;
	}

	temp = fopen("temp.dat", "wb");
	rewind(arq);
	
	while(fread(&cliente, sizeof(struct Conta), 1, arq) == 1) {
		if (strcmp(cliente.nome, nome) == 0) {
			printf("Digite a senha [ADMIN]: ");
			scanf("%d", &check);
			if (check == SENHA) {
				encontrado = 1;
				continue;				
			} else {
				printf("Senha incorreta.\n");
			}
		}

		fwrite(&cliente, sizeof(struct Conta), 1, temp);			
	}
	
	fclose(arq);
	fclose(temp);
	
	remove(FILECLIENTE);
	rename("temp.dat", FILECLIENTE);

	if (encontrado && check == SENHA) {
		printf("Usuário excluído com sucesso, voltando para o menu. \n");
		sleep(1);
	} else {
		printf("Usuário não econtrado, voltando para o menu. \n");
		sleep(1);
	}
}

void ConsultarConta(FILE *arq) {
	clear();
	fclose(arq);
	struct Conta cliente;
	char nome[LIM];	
	
	printf("Informe o nome completo do cliente: ");
	fflush(stdin);
	fgets(nome, sizeof(nome), stdin);
	nome[strcspn(nome, "\n")] = '\0';
	arq = fopen(FILECLIENTE, "rb");
	
	if(arq == NULL){
		printf("Nenhum usuario cadastrado.\n");
		return;
	}

	rewind(arq);
	
	while(fread(&cliente, sizeof(struct Conta), 1, arq) == 1) {
		if (strcmp(cliente.nome, nome) == 0) {
			clear();
			printf("-- DADOS DA CONTA --\n");
			if (cliente.tipo == 0)
				printf("Tipo de conta: Corrente\n");
			if (cliente.tipo == 1)
				printf("Tipo de conta: Poupança\n");
			printf("Nome do cliente: %s\n", cliente.nome);
			printf("Agência: %d\n", cliente.agencia);
			printf("Número da conta: %d\n", cliente.numero);
			printf("CPF: %s\n", cliente.cpf);
			printf("Saldo: R$ %.2f\n", cliente.saldo);
			if (cliente.tipo == 0)
				printf("Limite: R$ %.2f\n", cliente.limite);
			if (cliente.tipo == 0)
				printf("Vencimento: %2s/%2s\n", cliente.vencimento.mes, cliente.vencimento.ano);
			system("pause");
			continue;
		}
	}
	fclose(arq);
}

void ConsultarFuncionario(FILE *arq) {
	clear();
	fclose(arq);
	struct Funcionario funcionario;
	int encontrado = 0;
	int codigo;	
	
	arq = fopen(FILEFUNCIONARIO, "rb");
		if(arq == NULL){
		printf("Nenhum usuario cadastrado.\n");
		sleep(1);
		return;
	}

	rewind(arq);

	printf("Informe o c?digo do funcion?rio: ");
	fflush(stdin);
	scanf("%d", &codigo);
	
	while(fread(&funcionario, sizeof(struct Funcionario), 1, arq) == 1) {
		if (codigo == funcionario.codigo) {
			encontrado = 1;
			clear();
			printf("-- DADOS DO FUNCION?RIO --\n");
			printf("C?digo: %d \n", funcionario.codigo);
			printf("Cargo: %s\n", funcionario.cargo);
			printf("Nome: %s\n", funcionario.nome);
			printf("CPF: %s \n", funcionario.cpf);
			printf("Nascimento: %2s/%2s/%4s \n", funcionario.nascimento.dia, funcionario.nascimento.mes, funcionario.nascimento.ano);
			printf("Celular: (%2s) %9s\n", funcionario.celular.DDD, funcionario.celular.numero);	
			printf("- ENDERE?O -\n");	
			printf("Estado: %s\n", funcionario.endereco.estado);	
			printf("Cidade: %s\n", funcionario.endereco.cidade);	
			printf("Bairro: %s\n", funcionario.endereco.bairro);	
			printf("CEP: %d\n", funcionario.endereco.cep);
			printf("N?mero: %d\n", funcionario.endereco.numero);		
			system("pause");
			continue;
		}
	}
	if (!encontrado) {
		printf("Este funcion?rio n?o existe ou o c?digo est? incorreto.");
		sleep(1);				
	}
	fclose(arq);
}

void ConsultarCliente(FILE *arq) {
	clear();
	fclose(arq);
	struct Conta cliente;
	char nome[LIM];	
	
	printf("Informe o nome completo do cliente: ");
	fflush(stdin);
	fgets(nome, sizeof(nome), stdin);
	nome[strcspn(nome, "\n")] = '\0';
	arq = fopen(FILECLIENTE, "rb");
	
	if(arq == NULL){
		printf("Nenhum usuario cadastrado.\n");
		sleep(1);
		return;
	}

	rewind(arq);
	
	while(fread(&cliente, sizeof(struct Conta), 1, arq) == 1) {
		if (strcmp(cliente.nome, nome) == 0) {
			clear();
			printf("-- DADOS DO CLIENTE --\n");
			printf("Nome: %s\n", cliente.nome);
			printf("CPF: %s \n", cliente.cpf);
			printf("Nascimento: %2s/%2s/%4s \n", cliente.nascimento.dia, cliente.nascimento.mes, cliente.nascimento.ano);
			printf("Celular: (%2s) %9s\n", cliente.celular.DDD, cliente.celular.numero);	
			printf("- ENDERE?O -\n");	
			printf("Estado: %s\n", cliente.endereco.estado);	
			printf("Cidade: %s\n", cliente.endereco.cidade);	
			printf("Bairro: %s\n", cliente.endereco.bairro);	
			printf("CEP: %d\n", cliente.endereco.cep);
			printf("N?mero: %d\n", cliente.endereco.numero);
			system("pause");
			continue;
		}
	}
	fclose(arq);
}

void AlterarConta(FILE *arq) {
	clear();
	FILE *temp;
	fclose(arq);
	struct Conta cliente;
	int encontrado = 0;
	char nome[LIM];
	int op;
	int check;

	printf("Informe o nome completo do cliente: ");
	fflush(stdin);
	fgets(nome, sizeof(nome), stdin);
	nome[strcspn(nome, "\n")] = '\0';
	arq = fopen(FILECLIENTE, "rb");
	
	if(arq == NULL){
		printf("Nenhum usuario cadastrado.\n");
		return;
	}

	temp = fopen("temp.dat", "wb");
	rewind(arq);
	
	while(fread(&cliente, sizeof(struct Conta), 1, arq) == 1) {
		if (strcmp(cliente.nome, nome) == 0) {
			encontrado = 1;
			printf("Digite a senha [ADMIN]: ");
			scanf("%d", &check);
			if (check == SENHA) {
				clear();
				do {
					clear();
					printf("-- ALTERAR DADOS --\n");
					printf("1 - TIPO DA CONTA\n");
					printf("2 - LIMITE\n");
					printf("3 - DATA\n");
					printf("4 - VOLTAR\n");	
					printf("-> ");
					scanf("%d", &op);
					switch (op)
					{
					case 1:
						cliente.tipo = (cliente.tipo == 0) ? 1 : 0;
						if (cliente.tipo == 0) {
							printf("Informe a nova data de vencimento (MM/AA): ");
							scanf("%2s/%2s", &cliente.vencimento.mes, &cliente.vencimento.ano);
							printf("Data de vencimento alterado com sucesso!\n");
							printf("Informe o novo limite: R$ ");
							scanf("%f", &cliente.limite);
							printf("Limite alterado com sucesso!\n");
							sleep(1);	
						}
						printf("Tipo alterado com sucesso!\n");
						sleep(1);
						break;

					case 2:
						printf("Informe o novo limite: R$ ");
						scanf("%f", &cliente.limite);
						printf("Limite alterado com sucesso!\n");
						sleep(1);						
						break;

					case 3:
						printf("Informe a nova data de vencimento (MM/AA): ");
						scanf("%2s/%2s", &cliente.vencimento.mes, &cliente.vencimento.ano);
						printf("Data de vencimento alterado com sucesso!\n");
						sleep(1);						
						break;	
					case 4:
						break;					
					default:
						printf("Op??o incorreta, tente novamente.");
						sleep(1);
						break;
					}				
				} while (op != 4);				
			} else {
				printf("Senha incorreta.\n");
			}
		}

		fwrite(&cliente, sizeof(struct Conta), 1, temp);			
	}
	
	fclose(arq);
	fclose(temp);
	
	remove(FILECLIENTE);
	rename("temp.dat", FILECLIENTE);

	if (!encontrado) {
		printf("Usuário não econtrado, voltando para o menu. \n");
		sleep(1);
	}
}

void AlterarFuncionario(FILE *arq) {
	clear();
	FILE *temp;
	fclose(arq);
	struct Funcionario funcionario;
	int encontrado = 0;
	char nome[LIM];
	int op;
	int check;

	printf("Informe o nome completo do funcionário: ");
	fflush(stdin);
	fgets(nome, sizeof(nome), stdin);
	nome[strcspn(nome, "\n")] = '\0';
	arq = fopen(FILEFUNCIONARIO, "rb");
	
	if(arq == NULL){
		printf("Nenhum usuário cadastrado.\n");
		return;
	}

	temp = fopen("temp.dat", "wb");
	rewind(arq);
	
	while(fread(&funcionario, sizeof(struct Funcionario), 1, arq) == 1) {
		if (strcmp(funcionario.nome, nome) == 0) {
			if (encontrado == 1)
				continue;
			encontrado = 1;
			printf("Digite a senha [ADMIN]: ");
			scanf("%d", &check);
			if (check == SENHA) {
				clear();
				do {
					clear();
					printf("-- ALTERAR DADOS --\n");
					printf("1 - CODIGO\n");
					printf("2 - CARGO\n");
					printf("3 - TELEFONE\n");			
					printf("4 - ENDERE?O\n");
					printf("5 - VOLTAR\n");
					printf("-> ");
					scanf("%d", &op);
					switch (op)
					{
					case 1:
						printf("Digite o código: ");
						scanf("%d", &funcionario.codigo);
						printf("Código alterado com sucesso!\n");						
						sleep(1);
						break;

					case 2:
						printf("Digite o cargo: ");
						fflush(stdin);
						fgets(funcionario.cargo, sizeof(funcionario.cargo), stdin);
						funcionario.cargo[strcspn(funcionario.cargo, "\n")] = '\0';		
						printf("Cargo alterado com sucesso!\n");										
						sleep(1);						
						break;

					case 3:
						printf("Informe o número do celular (XX XXXXXXXXX): ");
						scanf("%2s %9s", &funcionario.celular.DDD, &funcionario.celular.numero);	
						printf("Número do celular alterado com sucesso!\n");												
						sleep(1);						
						break;

					case 4:
						printf("Estado: ");
						fflush(stdin);
						fgets(funcionario.endereco.estado, sizeof(funcionario.endereco.estado), stdin);
						funcionario.endereco.estado[strcspn(funcionario.endereco.estado, "\n")] = '\0';
						printf("Cidade: ");
						fflush(stdin);
						fgets(funcionario.endereco.cidade, sizeof(funcionario.endereco.cidade), stdin);
						funcionario.endereco.cidade[strcspn(funcionario.endereco.cidade, "\n")] = '\0';
						printf("Bairro: ");
						fflush(stdin);
						fgets(funcionario.endereco.bairro, sizeof(funcionario.endereco.bairro), stdin);
						funcionario.endereco.bairro[strcspn(funcionario.endereco.bairro, "\n")] = '\0';
						printf("CEP: ");
						scanf("%d", &funcionario.endereco.cep);
						printf("Rua: ");
						fflush(stdin);
						fgets(funcionario.endereco.rua, sizeof(funcionario.endereco.rua), stdin);
						funcionario.endereco.rua[strcspn(funcionario.endereco.rua, "\n")] = '\0';
						printf("Numero: ");
						scanf("%d", &funcionario.endereco.numero);
						printf("Endereço alterado com sucesso!\n");								
						sleep(1);						
						break;
					case 5:
						break;									
					default:
						printf("Opção incorreta, tente novamente.");
						sleep(1);
						break;
					}				
				} while (op != 5);				
			} else {
				printf("Senha incorreta.\n");
			}
		}

		fwrite(&funcionario, sizeof(struct Funcionario), 1, temp);			
	}
	
	fclose(arq);
	fclose(temp);
	
	remove(FILEFUNCIONARIO);
	rename("temp.dat", FILEFUNCIONARIO);

	if (!encontrado) {
		printf("Usuário não econtrado, voltando para o menu. \n");
		sleep(1);
	}
}

void AlterarCliente(FILE *arq) {
	clear();
	FILE *temp;
	fclose(arq);
	struct Conta cliente;
	int encontrado = 0;
	char nome[LIM];
	int op;
	int check;

	printf("Informe o nome completo do cliente: ");
	fflush(stdin);
	fgets(nome, sizeof(nome), stdin);
	nome[strcspn(nome, "\n")] = '\0';
	arq = fopen(FILECLIENTE, "rb");
	
	if(arq == NULL){
		printf("Nenhum usuário cadastrado.\n");
		return;
	}

	temp = fopen("temp.dat", "wb");
	rewind(arq);
	
	while(fread(&cliente, sizeof(struct Conta), 1, arq) == 1) {
		if (strcmp(cliente.nome, nome) == 0) {
			encontrado = 1;
			if (encontrado == 1)
				continue;
			printf("Digite a senha [ADMIN]: ");
			scanf("%d", &check);
			if (check == SENHA) {
				clear();
				do {
					clear();
					printf("-- ALTERAR DADOS --\n");
					printf("1 - TELEFONE\n");
					printf("2 - ENDEREÇO\n");
					printf("3 - VOLTAR\n");	
					printf("-> ");
					scanf("%d", &op);
					switch (op)
					{
					case 1:
						printf("Informe o número do celular (XX XXXXXXXXX): ");
						scanf("%2s %9s", &cliente.celular.DDD, &cliente.celular.numero);	
						printf("Número do celular alterado com sucesso!\n");						
						sleep(1);
						break;

					case 2:
						printf("Estado: ");
						fflush(stdin);
						fgets(cliente.endereco.estado, sizeof(cliente.endereco.estado), stdin);
						cliente.endereco.estado[strcspn(cliente.endereco.estado, "\n")] = '\0';
						printf("Cidade: ");
						fflush(stdin);
						fgets(cliente.endereco.cidade, sizeof(cliente.endereco.cidade), stdin);
						cliente.endereco.cidade[strcspn(cliente.endereco.cidade, "\n")] = '\0';
						printf("Bairro: ");
						fflush(stdin);
						fgets(cliente.endereco.bairro, sizeof(cliente.endereco.bairro), stdin);
						cliente.endereco.bairro[strcspn(cliente.endereco.bairro, "\n")] = '\0';
						printf("CEP: ");
						scanf("%d", &cliente.endereco.cep);
						printf("Rua: ");
						fflush(stdin);
						fgets(cliente.endereco.rua, sizeof(cliente.endereco.rua), stdin);
						cliente.endereco.rua[strcspn(cliente.endereco.rua, "\n")] = '\0';
						printf("Número: ");
						scanf("%d", &cliente.endereco.numero);
						printf("Endere?o alterado com sucesso!\n");						
						sleep(1);						
						break;

					case 3:					
						break;					
					default:
						printf("Opção incorreta, tente novamente.");
						sleep(1);
						break;
					}				
				} while (op != 4);				
			} else {
				printf("Senha incorreta.\n");
			}
		}

		fwrite(&cliente, sizeof(struct Conta), 1, temp);			
	}
	
	fclose(arq);
	fclose(temp);
	
	remove(FILECLIENTE);
	rename("temp.dat", FILECLIENTE);

	if (!encontrado) {
		printf("Usuário não econtrado, voltando para o menu. \n");
		sleep(1);
	}
}
void AberturaFuncionario(FILE *arq) {
	struct Funcionario funcionario;
	int check;
	
	fclose(arq);
	clear();
	printf("Digite a senha [ADMIN]: ");
	scanf("%d", &check);
	if (check == SENHA) {
		printf("------ CADASTRO FUNCIONÁRIO ------\n");
		
		printf("Informe o código do funcionário: ");
		scanf("%d", &funcionario.codigo);

		printf("Informe o cargo do funcionário: ");
		fflush(stdin);
		fgets(funcionario.cargo, sizeof(funcionario.cargo), stdin);
		funcionario.cargo[strcspn(funcionario.cargo, "\n")] = '\0';
				
		printf("Informe o nome completo do funcionário: ");
		fflush(stdin);
		fgets(funcionario.nome, sizeof(funcionario.nome), stdin);
		funcionario.nome[strcspn(funcionario.nome, "\n")] = '\0';

		printf("Informe o CPF do funcionário (apenas números): ");
		scanf("%s", &funcionario.cpf);

		printf("Informe a data de nascimento do funcionário (DD/MM/AAAA): ");
		scanf("%2s/%2s/%4s", &funcionario.nascimento.dia, &funcionario.nascimento.mes, &funcionario.nascimento.ano);

		printf("Informe o número do celular (XX XXXXXXXXX): ");
		scanf("%2s %9s", &funcionario.celular.DDD, &funcionario.celular.numero);

		printf("--- ENDEREÇO ---\n");
		printf("Estado: ");
		fflush(stdin);
		fgets(funcionario.endereco.estado, sizeof(funcionario.endereco.estado), stdin);
		funcionario.endereco.estado[strcspn(funcionario.endereco.estado, "\n")] = '\0';
		printf("Cidade: ");
		fflush(stdin);
		fgets(funcionario.endereco.cidade, sizeof(funcionario.endereco.cidade), stdin);
		funcionario.endereco.cidade[strcspn(funcionario.endereco.cidade, "\n")] = '\0';
		printf("Bairro: ");
		fflush(stdin);
		fgets(funcionario.endereco.bairro, sizeof(funcionario.endereco.bairro), stdin);
		funcionario.endereco.bairro[strcspn(funcionario.endereco.bairro, "\n")] = '\0';
		printf("CEP: ");
		scanf("%d", &funcionario.endereco.cep);
		printf("Rua: ");
		fflush(stdin);
		fgets(funcionario.endereco.rua, sizeof(funcionario.endereco.rua), stdin);
		funcionario.endereco.rua[strcspn(funcionario.endereco.rua, "\n")] = '\0';
		printf("Numero: ");
		scanf("%d", &funcionario.endereco.numero);
		
		printf("Infome a senha do funcion?rio (apenas números): ");
		scanf("%d", &funcionario.senha);
		
		arq = fopen(FILEFUNCIONARIO, "ab+");
		fseek(arq, 0, SEEK_END);
		fwrite(&funcionario, sizeof(struct Funcionario), 1, arq);
		fclose(arq);

		printf("Cliente cadastrado com sucesso! \n");
		sleep(1);
	} else {
		printf("Senha incorreta.\n");
		sleep(1);
	}
}

void GerarRelatorio(FILE *arq, FILE *relatorio) {
	struct Conta cliente;
	int check;
	clear();
		
	arq = fopen(FILECLIENTE, "rb");
	relatorio = fopen(FILERELATORIO, "w");
	
	if(arq == NULL){
		printf("Nenhum usuário cadastrado.\n");
		return;
	}

	rewind(arq);
	printf("Digite a senha [ADMIN]: ");
	scanf("%d", &check);
	if (check == SENHA) {

		fprintf(relatorio, "Nome,Saldo,Agência,Número da conta,CPF,Tipo,Vencimento,Limite\n");
		while(fread(&cliente, sizeof(struct Conta), 1, arq) == 1) {
            fprintf(relatorio, "%s,R$ %.0f,%d,%d,%s,", cliente.nome, cliente.saldo, cliente.agencia, cliente.numero, cliente.cpf);

			if (cliente.tipo == 0) {
				fprintf(relatorio, "Conta Corrente,%02s/%02s,R$ %.0f\n", cliente.vencimento.mes, cliente.vencimento.ano, cliente.limite);
			} 
			if (cliente.tipo == 1) { 
				fprintf(relatorio, "Conta Poupança\n");					
			}						
		}
		printf("Relatário gerado com sucesso!");
		sleep(1);
		fclose(arq);
		fclose(relatorio);
		
	} else {
		printf("Senha incorreta.\n");
		sleep(1);
	}	
} 
void Saldo(FILE *arq) {
	clear();
	fclose(arq);
	struct Conta cliente;
	char nome[LIM];	
	int check;
	
	printf("Informe o nome completo do cliente: ");
	fflush(stdin);
	fgets(nome, sizeof(nome), stdin);
	nome[strcspn(nome, "\n")] = '\0';
	arq = fopen(FILECLIENTE, "rb");
	
	if(arq == NULL){
		printf("Nenhum usuário cadastrado.\n");
		return;
	}

	rewind(arq);
	
	while(fread(&cliente, sizeof(struct Conta), 1, arq) == 1) {
		if (strcmp(cliente.nome, nome) == 0) {
			printf("Digite a senha do %s: ", cliente.nome);
			scanf("%d", &check);
			if (check != cliente.senha) {
				printf("Senha incorreta. ");
				sleep(1);
				return;
			}
			clear();
			printf("-- SALDO DE %s --\n", cliente.nome);
			printf("Saldo: R$ %.2f\n", cliente.saldo);
			system("pause");
			continue;
		}
	}
	fclose(arq);
}

void Deposito(FILE *arq) {
	clear();
	FILE *temp;
	fclose(arq);
	struct Conta cliente;
	int encontrado = 0;
	char nome[LIM];
	int op;
	int check;
	float deposito;

	printf("Informe o nome completo do cliente: ");
	fflush(stdin);
	fgets(nome, sizeof(nome), stdin);
	nome[strcspn(nome, "\n")] = '\0';
	arq = fopen(FILECLIENTE, "rb");
	
	if(arq == NULL){
		printf("Nenhum usuário cadastrado.\n");
		return;
	}

	temp = fopen("temp.dat", "wb");
	rewind(arq);
	
	while(fread(&cliente, sizeof(struct Conta), 1, arq) == 1) {
		if (strcmp(cliente.nome, nome) == 0) {
			if (encontrado == 1)
				continue;
			encontrado = 1;
			printf("Digite a senha do %s: ", cliente.nome);
			scanf("%d", &check);
			if (check != cliente.senha) {
				printf("Senha incorreta. ");
				sleep(1);
				return;
			}
			printf("Informe o valor do depósito: ");
			scanf("%f", &deposito);
			cliente.saldo += deposito;
			printf("Valor de R$ %.2f depositado com sucesso!", deposito);
			sleep(1);
		}

		fwrite(&cliente, sizeof(struct Conta), 1, temp);			
	}
	
	fclose(arq);
	fclose(temp);
	
	remove(FILECLIENTE);
	rename("temp.dat", FILECLIENTE);

	if (!encontrado) {
		printf("Usuário não econtrado, voltando para o menu. \n");
		sleep(1);
	}
}

void Saque(FILE *arq) {
	clear();
	FILE *temp;
	fclose(arq);
	struct Conta cliente;
	int encontrado = 0;
	char nome[LIM];
	int op;
	int check;
	float saque;

	printf("Informe o nome completo do cliente: ");
	fflush(stdin);
	fgets(nome, sizeof(nome), stdin);
	nome[strcspn(nome, "\n")] = '\0';
	arq = fopen(FILECLIENTE, "rb");
	
	if(arq == NULL){
		printf("Nenhum usuário cadastrado.\n");
		return;
	}

	temp = fopen("temp.dat", "wb");
	rewind(arq);
	
	while(fread(&cliente, sizeof(struct Conta), 1, arq) == 1) {
		if (strcmp(cliente.nome, nome) == 0) {
			if (encontrado == 1)
				continue;
			encontrado = 1;
			printf("Digite a senha do %s: ", cliente.nome);
			scanf("%d", &check);
			if (check != cliente.senha) {
				printf("Senha incorreta. ");
				sleep(1);
				return;
			}
			printf("Informe o valor do saque: ");
			scanf("%f", &saque);
			if (cliente.saldo < saque) {
				printf("Saldo insuficiente.");
				sleep(1);	
			} else {
				cliente.saldo -= saque;
				printf("Valor de R$ %.2f sacado com sucesso!", saque);
				sleep(1);				
			}
		}

		fwrite(&cliente, sizeof(struct Conta), 1, temp);			
	}
	
	fclose(arq);
	fclose(temp);
	
	remove(FILECLIENTE);
	rename("temp.dat", FILECLIENTE);

	if (!encontrado) {
		printf("Usuário não econtrado, voltando para o menu. \n");
		sleep(1);
	}
}

void Limite(FILE *arq) {
	clear();
	fclose(arq);
	struct Conta cliente;
	char nome[LIM];	
	int check;
	
	printf("Informe o nome completo do cliente: ");
	fflush(stdin);
	fgets(nome, sizeof(nome), stdin);
	nome[strcspn(nome, "\n")] = '\0';
	arq = fopen(FILECLIENTE, "rb");
	
	if(arq == NULL){
		printf("Nenhum usuário cadastrado.\n");
		return;
	}

	rewind(arq);
	
	while(fread(&cliente, sizeof(struct Conta), 1, arq) == 1) {
		if (strcmp(cliente.nome, nome) == 0) {
			printf("Digite a senha do %s: ", cliente.nome);
			scanf("%d", &check);
			if (check != cliente.senha) {
				printf("Senha incorreta. ");
				sleep(1);
				return;
			}
			clear();
			printf("-- LIMITE DE %s --\n", cliente.nome);
			printf("Limite: R$ %.2f\n", cliente.limite);
			system("pause");
			continue;
		}
	}
	fclose(arq);
}

void Extrato(FILE *arq, FILE *extrato) {
	struct Conta cliente;
	int check;
	char nome[LIM];
	clear();
		
	arq = fopen(FILECLIENTE, "rb");
	extrato = fopen(FILEEXTRATO, "w");
	
	if(arq == NULL){
		printf("Nenhum usuário cadastrado.\n");
		return;
	}
	printf("Informe o nome completo do cliente: ");
	fflush(stdin);
	fgets(nome, sizeof(nome), stdin);
	nome[strcspn(nome, "\n")] = '\0';
	
	rewind(arq);
		
	fprintf(extrato, "Nome,Saldo\n");
	while(fread(&cliente, sizeof(struct Conta), 1, arq) == 1) {
		if (strcmp(cliente.nome, nome) == 0) {
			printf("Digite a senha do %s: ", cliente.nome);
			scanf("%d", &check);
			if (check != cliente.senha) {
				printf("Senha incorreta. ");
				sleep(1);
				return;
			}
			fprintf(extrato, "%s,R$ %.0f", cliente.nome, cliente.saldo);			
		}
				
	}
	printf("Extrato gerado com sucesso!");
	sleep(1);
	fclose(arq);
	fclose(extrato);

} 
