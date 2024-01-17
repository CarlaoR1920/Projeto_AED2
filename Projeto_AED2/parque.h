#include <time.h>

/*Estrutura para cada lugar do parque*/
typedef struct
    {
    	char* data_Entrada;
        time_t tempoEntrada;
        int ocupacao;
        char matricula[9];
    } viatura;
    
/*Estrutura do parque*/
typedef struct
    {
    	viatura **parque;
    	float taxa;
    	int linhas;
    	int colunas;
    } parque;
    
        
void inicializacao(parque *p);

void estacionar(parque *p);

void retirar(parque *p);

void selecionarTaxa(parque *p);

void visualizar(parque p);

void saberDataEntrada(parque p);


