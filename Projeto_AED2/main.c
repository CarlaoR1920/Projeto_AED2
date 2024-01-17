#include <stdio.h>
#include <stdlib.h>
#include "parque.h"

main() {
	int caso,i;
	parque estacionamento;

	inicializacao(&estacionamento);

	do
    {	/*Escolha da a��o a realizar*/
    	system("cls");
        printf("Insira o numero correspondente a a�ao que pretende realizar\n\n");
        printf("1- Adicionar uma viatura ao parque\n\n");
        printf("2- Retirar uma viatura do parque\n\n");
        printf("3- Visualizar o parque\n\n");
        printf("4- Alterar o preco por hora\n\n");
        printf("5- Saber data de entrada de um veiculo\n\n");
        printf("6- Sair do programa\n\n");
        scanf("%d", &caso);
        switch (caso)
        {
        	/*Adicionar uma Viatura ao parque*/
            case 1 :
				estacionar(&estacionamento);
            break;
			
			/*Retirar um veiculo do parque*/
            case 2 :
        		retirar(&estacionamento);
            break;
			
			/*Imprime na consola uma visualiza��o do parque*/
            case 3 :
            	visualizar(estacionamento);
            break;
			
			/*Escolha do pre�o por hora*/
			case 4:
				selecionarTaxa(&estacionamento);
			break;
			
			/*Mostra a data de entrada do veiculo pedido*/
			case 5:
				saberDataEntrada(estacionamento);
			break;
			
			/*Encerra o programa*/
			case 6:
				for (i=0; i<estacionamento.linhas; i++)
		    	{
		    		free(estacionamento.parque[i]);
				}
				
				free(estacionamento.parque);
				exit(0);
			break;
			
			/*Mensagem caso o utilizador selecione uma op��o invalida*/
            default: 
            
            printf("O n�mero inserido n�o corresponde a nenhuma das op��es\n");
    	
		
    	
        }
}while(1!=2);
}
