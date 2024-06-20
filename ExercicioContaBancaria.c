#include <stdio.h>

void logErro(){														//funcao de mensagem de erro
	
	puts("Saldo insuficiente!");
	
}

void menuPrincipal(){
	puts("Bem Vindo! Por favor escolha o tipo de conta: "); 			 //funcao menu principal
	puts("1 - Conta corrente");
	puts("2 - Conta salario");
	puts("3 - Conta poupanca");
	puts("4 - Investimentos");
	puts("5 - Fechar programa");
}

float opcaoContaCorrente(float saldo){									//funcao conta corrente
	float valor;
	int opcao;
	
	do{
		puts("Conta corrente:");
		puts ("Escolha uma operacao: ");
		puts ("1 - Saque");
		puts ("2 - Deposito");
		puts ("3 - Voltar ao menu");
		
		puts("escolha uma opcao: ");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1:
				printf("\nSaldo : %.2f\n", saldo);					  //opcao saque
				puts("Saque: ");
				puts ("Informe o valor: ");  
				scanf("%f", &valor);
				
				if(valor > saldo){ 									 //verifica se possui saldo suficiente
					logErro();
				}
				else{
					saldo = saldo - valor;
					puts("Saque realizado com sucesso!");
					printf("\nSeu saldo atual e: %.2f.\n", saldo);
				}
				
			break;
			case 2:
				puts("Deposito: ");									//opcao depositar
				puts ("Informe o valor: ");
				scanf("%f", &valor);
				
				saldo = saldo + valor;
				
			break;
			case 3:
				puts ("Voltando ao Menu Principal");
			break;
			default:
				puts("Opcao invalida, escolha uma opcao valida!");
		}
	}while(opcao != 3);
	
	return (saldo);
}

void opcaoContaSalario(){										//funcao conta salario
	
	int opcao;
	float valor, saldo = 3000.00;
	
	do{
		puts("Conta salario: ");
		puts("Escolha uma operacao: ");
		puts("1 - Consultar saldo");
		puts("2 - Saque");
		puts("3 - Voltar ao menu principal");
	
		puts("Escolha uma opcao: ");
		scanf("%d", &opcao);
	
		switch(opcao){
			case 1:
				printf("\nSaldo atual : %.2f\n", saldo);		//opcao consulta saldo
			break;
			case 2:
				puts("Saque: ");								//opcao saque
				puts("Informe o valor: ");
				scanf("%f", &valor);
				
				if(valor > saldo){								//verifica se possui saldo suficiente
					logErro();
				}
				else{
					saldo = saldo - valor;
					printf("\nSeu saldo atual e %.2f\n", saldo);
				}
			break;
			case 3:
				puts("Voltando ao menu!");
			break;
			default:
				puts("Opcao invalida, escolha uma opcao valida!");
		}
	}while(opcao != 3);
}

void poupanca(){												//funcao poupanca
	
	int opcao;
	float saldo, valor;
	
	do{
		puts("Poupanca: ");
		puts("Escolha uma operacao: ");
		puts("1 - Aplicar");
		puts("2 - resgatar");
		puts("3 - Voltar ao menu principal");
		
		puts("Escolha uma opcao: ");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1:
				puts("Aplicar: ");									//opcao aplicar na poupanca
				puts("Informe o valor: ");
				scanf("%f", &valor);
				
				saldo = saldo + valor;
				printf("\nSaldo da poupanca: %.2f\n", saldo);
			break;
			case 2: 
				puts("Resgatar: ");									//opcao resgatar da poupanca
				puts("Informe o valor: ");
				scanf("%f", &valor);
				
				if(valor > saldo){
					logErro();										//verifica se posuui saldo suficiente
				}
				else{
					saldo = saldo - valor;
					printf("\nOperacao realizada com sucesso! Saldo atual e %.2f\n", saldo);
				}
			break;
			case 3: 
					puts("Voltando ao menu principal!");
			break;
			default:
					puts("Opcao invalida, informe uma opcao valida!");
		}
	}while(opcao != 3);
}

float investimento(float saldo){								//funcao investimento
	
	int opcao;
	float valor;
	
	do{
		puts("Investimentos:");
		puts("Escolha uma operacao: ");
		puts("1 - Investir");
		puts("2 - Voltar ao menu principal");
		
		puts("Escolha uma opcao: ");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1: 
				printf("\nSaldo na conta: %.2f\n", saldo);			//opcao investir 
				puts("informe o valor: ");
				scanf("%f", &valor);
				
				if(valor > saldo){									//verifica se possui saldo suficiente
					logErro();
				}
				else{
					saldo = saldo - valor;
					printf("\nVoce aplicou %.2f, Seu saldo atual e %.2f\n", valor, saldo);
				}
			break;
			case 2: 
				puts("Voltando ao menu principal");
			break;
			default:
				puts("Opcao invalida, por favor escolha uma opcao valida!");
		}
	}while(opcao != 2);
	
	return(saldo);
}

int main (){
	
	int opcao;
	float saldoConta = 0;
	
	do{
		menuPrincipal();
		
		puts("escolha uma opcao: ");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1:
				saldoConta = opcaoContaCorrente(saldoConta);
			break;
			case 2: 
				opcaoContaSalario();
			break;
			case 3:
				poupanca();
			break;
			case 4:
				saldoConta = investimento(saldoConta);
			break;
			case 5:
				puts("Saindo do programa!");
			break;
			default:
				puts("Opcao invalida, escolha uma opcao valida!");
		}
		
	}while(opcao!=5);
	
}