#include "parque.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*Inicializa o parque comforme os dados inseridos pelo utilizador*/
void inicializacao(parque *p)
{
	int linhas, colunas, i, j;
	float taxa;	
	
	/*Pergunta o tamanho que o parque devera ter*/	
	do{
		printf("Insira o numero de linhas do parque: ");
    	scanf("%d", &linhas);
    	printf("Insira o numero de colunas do parque: ");
    	scanf("%d", &colunas);
    	if (!(linhas>0 && colunas>0)) 
		{
			printf("Dados Invalidos!\n");
		} else {
			p->linhas=linhas;
			p->colunas=colunas;
		}
	}while(!(linhas>0 && colunas>0));
	
	/*Pergunta o valor a pagar por hora no parque*/
	do{
		printf("Insira o preco por hora do parque: ");
		scanf("%f", &taxa);
		if(taxa<0)
		{
			printf("Valor Invalido!\n");
		} else {
			p->taxa=taxa;
		}
		}while (taxa<0);
		
		/* Aloca espaço em memoria para o parque*/
		p->parque = (viatura **) malloc(linhas*sizeof(viatura*));
    	if(p->parque == NULL) 
    	{
    		printf("Erro: Memoria Insuficiente");
    		system("PAUSE");
    		exit(1);
		}
		
    	for (i=0; i<linhas; i++)
    	{
    		p->parque[i] = (viatura *) malloc(colunas*sizeof(viatura));
    		if(p->parque[i]==NULL)
    		{
    			printf("Erro: Memoria Insuficiente");
    			system("PAUSE");
    			exit(1);
			}
		}
		
		/*Coloca a ocupação dos lugares a livre*/
		for(i=0;i<linhas; i++)
    	{
	        for(j=0; j<colunas; j++)
	        {
	            p->parque[i][j].ocupacao=0;
	        }
    	}
}

/*Função para estacionar um veiculo*/
void estacionar(parque *p)
{
	char matriculaP[9];
	int ver, i, j;
	
	/*Pede a matricula do veiculo a inserir*/
	printf("Insira a matricula no formato mm-mm-mm: ");
    scanf("%s", matriculaP);
    
   	/*Verifica se existe algum veiculo com a mesma matricula no interior do parque*/
   	ver=0;
    for(i=0;i<p->linhas;i++)
    {
  		for(j=0;j<p->colunas;j++)
        {
       		if(strcmp(p->parque[i][j].matricula, matriculaP)==0) ver=1;
            if(ver==1) break;
		}
		if(ver==1) break;
	}
	
    /*Caso seja encontrado um veiculo com matricula igual a inserida pelo utilizador infarma-o do mesmo*/
	if(ver==1)
	{
		printf("Ja existe um veiculo com a matricula inserida no interior do parque\n");
	} else {
				
	    /*Escolhe o lugar em que o veiculo sera estacionado*/
	    ver=0;
	    for(i=0;i<p->linhas;i++)
	    {
	        for(j=0;j<p->colunas;j++)
	        {
	        	if(p->parque[i][j].ocupacao==0) ver=1;
				if(ver==1) break;
			}
			if(ver==1) break;
		}
		
		/*Caso todos os lugares estejam ocupados informa o utilizador senão estaciona o parque*/
		if(ver==0)
		{
			printf("Todos os lugares estao ocupados\n");
		} else {
			/*Guarda os dados do veiculo estacionado*/
			p->parque[i][j].tempoEntrada = time(NULL);
			strcpy(p->parque[i][j].matricula,matriculaP);
		    p->parque[i][j].ocupacao=1;
		    p->parque[i][j].data_Entrada = ctime(&p->parque[i][j].tempoEntrada);
		    printf("Veiculo estacionado com sucesso!\n");
		}
    }
	system("PAUSE");
}

/*Função para retirar um veiculo do parque*/
void retirar(parque *p)
{
	char matriculaP[9];
	int ver, i, j;
	time_t tempoSaida;
	
	/*Pede a matricula do veiculo a ser retirado*/
    printf("Insira a matricula no formato mm-mm-mm: ");
    scanf("%s", &matriculaP);
    
     /*Procura o lugar do veiculo com a matricula correspondente a que foi inserida*/
    ver=0;
    for(i=0;i<p->linhas;i++)
    {
    	for(j=0;j<p->colunas;j++)
        {
        	if(strcmp(p->parque[i][j].matricula, matriculaP)==0) ver=1;
           	if(ver==1) break;
		}
		if(ver==1) break;
	}
	/*Caso não encontre um veiculo com a matricula inserida informa o utilizador, se encontrar remove o veiculo e informa o total a pagar*/
	if(ver==0)
	{
		printf("O veiculo nao se encontra nas instalacoes\n");
	} else {
		tempoSaida = time(NULL);
		printf("O total a pagar e %.2f\n", (float) ((p->taxa/3600)*(tempoSaida-p->parque[i][j].tempoEntrada)));
		p->parque[i][j].tempoEntrada = 0;
		strcpy(p->parque[i][j].matricula,"");
	    p->parque[i][j].ocupacao=0;
	    p->parque[i][j].data_Entrada = NULL;
	    printf("Veiculo removido com sucesso!\n");
	}
	system("PAUSE");
}

/*Função para alterar o preço por hora a pagar*/
void selecionarTaxa(parque *p)
{
	float taxa;
	do{
		/*Pergunta o novo preço a ser aplicado*/
		printf("Insira o preco por hora do parque: ");
		scanf("%f", &taxa);
		
		/*Verifica a validade do preço inserido*/
		if(taxa<0)
		{
			printf("Valor Invalido!\n");
		} else {
			p->taxa = taxa;
			printf("Preço alterado com sucesso!\n");
		}
	}while (taxa<0);
	system("PAUSE");
}

/*Fução para mostrar na consola uma visualização do parque*/
void visualizar(parque p)
{
	int i, j;
	printf("========================================================");
	printf("\n          Visualizacao da ocupacao do parque");
	printf("\n========================================================\n");
	printf("  ");
	for(j=0;j<p.colunas;j++)
	{
		printf("%d ", j+1);
	}
	printf("\n");
	            
	for(i=0;i<p.linhas; i++)
	{
	    printf("%d",i+1);
		printf("|");
	    for(j=0; j<p.colunas; j++)
	    {
	        if(p.parque[i][j].ocupacao==1)
	        {
	        	printf("O|");	
			} else {
				printf("L|");
			}
	                	
		}
		printf("\n");
	}
	printf("\n========================================================\n");
    system("PAUSE");
}

/*Função que informa da data de entrada de um veiculo*/
void saberDataEntrada(parque p)
{
	char matriculaP[9];
	int ver, i, j;
	
	/*Pede a matricula do veiculo sobre o qual deseja obter a informação*/
	printf("Insira a matricula do veiculo no formato mm-mm-mm: ");
    scanf("%s", matriculaP);
    
    ver=0;
	for(i=0;i<p.linhas;i++)
		{
	        for(j=0;j<p.colunas;j++)
	        {
	        	if(strcmp(p.parque[i][j].matricula, matriculaP)==0) ver=1;
	        	if(ver==1) break;
			}
			if(ver==1) break;
		}

	if(ver==1)
	{
		printf("A data em que o veiculo entrou foi %s\n", p.parque[i][j].data_Entrada);
	} else {
		printf("Não existe nenhum veiculo com a matricula inserida nas instalacoes\n");
	}
	system("PAUSE");
}

