#if ! defined( BARALHO_ )
#define BARALHO_
/***************************************************************************
*  $MCI Módulo de implementação: BAR  Baralho
*
*  Arquivo gerado:              BARALHO.c
*  Letras identificadoras:      BAR
*
*  Projeto: INF 1301 / 1628 Implementação do jogo de Truco Paulista em C
*  Gestor:  LES/DI/PUC-Rio
*  Autores: JML Julia Maria Lima
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*     1       jml   05/mai/2018 início desenvolvimento
*
*  $ED Descrição do módulo
*		Implementa um baralho generalizado.
*		O baralho primeiramente é criado inteiro.
*		Cada carta do baralho tem um número e um naipe.
*		Os números sao de 1 a 13, sendo Ás = 1; J = 11; Q = 12; K = 13;
*		O baralho também possui dois coringas, tendo seus naipes marcados
*			como Coringa e seus números 1 e 2 para diferenciá-los.
*		Os coringas são colocados no final do baralho, quando se cria
*			o baralho completo
*
*		Nesse módulo é capaz de retirar as cartas para que se transforme
*			no baralho do jogo de truco.
*
***************************************************************************/

#if defined( BARALHO_OWN )
#define BARALHO_EXT
#else
#define BARALHO_EXT extern
#endif


#include "LISTA.H"

/***** Declarações exportadas pelo módulo *****/

/* Tipo referência para um baralho */

typedef  LIS_tppLista BAR_tppBaralho ;

/* Tipo referência para uma carta */

typedef struct BAR_Carta * BAR_tppCarta ;

/***********************************************************************
*
*  $TC Tipo de dados: BAR Condições de retorno
*
*
*  $ED Descrição do tipo
*     Condições de retorno das funções do baralho
*
***********************************************************************/

typedef enum {

	BAR_CondRetOK ,
	/* Concluiu corretamente */

	BAR_CondRetBaralhoVazio ,
	/* O baralho não contém elementos */

	BAR_CondRetFimBaralho ,
	/* Foi atingido o fim do baralho */

	BAR_CondRetFaltouMemoriaBaralho ,
	/* Faltou memória ao tentar criar um baralho */

	BAR_CondRetFaltouMemoriaCarta ,
	/* Faltou memória ao tentar criar uma carta */

	BAR_CondRetNaoAchouCarta
	/* Faltou memória ao tentar achar uma carta */

} BAR_tpCondRet ;

/***********************************************************************
*
*  $TC Tipo de dados: BAR Naipes
*
*
*  $ED Descrição do tipo
*     Naipes das cartas
*
***********************************************************************/

typedef enum {

	Espadas ,
	/* naipe espadas */

	Paus ,
	/* naipe paus */

	Copas ,
	/* naipe copas */

	Ouros ,
	/* naipe ouros */

	Coringa
	/* naipe ouros */
} BAR_tpNaipe ;

/***********************************************************************
*
*  $TC Tipo de dados: BAR Cartas
*
*
*  $ED Descrição do tipo
*     Cartas
*
***********************************************************************/

typedef struct BAR_Carta {

	int numero ;
	/*  Guarda o numero da carta */

	BAR_tpNaipe naipe ;
	/* Guarda o naipe na carata */

} BAR_tpCarta ;

/***********************************************************************
*
*  $FC Função: BAR  &Criar Baralho
*
*  $ED Descrição da função
*		Cria um baralho.
*
*  $FV Valor retornado
*     Se executou corretamente retorna o ponteiro para o baralho.
*     Este ponteiro será utilizado pelas funções que manipulem este baralho.
*
*     Se ocorreu algum erro, por exemplo falta de memória ou dados errados,
*     a função retornará NULL.
*     Não será dada mais informação quanto ao problema ocorrido.
*
***********************************************************************/

BAR_tppBaralho BAR_CriarBaralho( ) ;

/***********************************************************************
*
*  $FC Função: BAR  &Criar Carta
*
*  $ED Descrição da função
*		Essa função aloca sizeof(BAR_tppCarta) para criar uma nova carta.
*		Recebendo um valor da carta e o naipe e botando dentro da struct.
*
*  $EP Parâmetros
*		numero	- valor da carta
*		Naipe 	- naipe da carta
*
*  $FV Valor retornado
*		NULL 	- se a carta nao tiver sido alocada corretamente
*		carta 	- com as informações novas criadas
*
***********************************************************************/

BAR_tppCarta BAR_CriarCarta( int numero , BAR_tpNaipe Naipe ) ;

/***********************************************************************
*
*  $FC Função: BAR  &Inserir carta antes
*
*  $ED Descrição da função
*		Essa função insere uma carta antes da posição recebida da lista.
*		Utilizando a LIS_InserirElementoAntes do modulo lista
*
*  $EP Parâmetros
*		pBaralho	- ponteiro para o baralho onde deve ser inserido 
*					  o elemento antes
*		pCarta		- ponteiro da carta a ser inserida
*
*  $FV Valor retornado
*		BAR_CondRetFaltouMemoriaBaralho  - se faltou memoria para inserir
*		BAR_CondRetOK					 - se a carta exigida foi inserida
*															corretamente
***********************************************************************/

BAR_tpCondRet BAR_InserirCartaAntes( BAR_tppBaralho pBaralho , 
									 BAR_tppCarta pCarta ) ;

/***********************************************************************
*
*  $FC Função: BAR  &Inserir carta apos
*
*  $ED Descrição da função
*		Essa função insere uma carta depois da posição recebida da lista.
*		Utilizando a LIS_InserirElementoApos do modulo lista
*
*  $EP Parâmetros
*		pBaralho	- ponteiro para o baralho onde deve ser inserido 
*					  o elemento apos
*		pCarta		- ponteiro da carta a ser inserida
*
*  $FV Valor retornado
*		BAR_CondRetFaltouMemoriaBaralho  - se faltou memoria para inserir 
*										   no baralho
*		BAR_CondRetOK					 - se a carta exigida foi inserida
*										   corretamente
***********************************************************************/

BAR_tpCondRet BAR_InserirCartaApos( BAR_tppBaralho pBaralho , 
									BAR_tppCarta pCarta ) ;

/***********************************************************************
*
*  $FC Função: BAR  &Avançar a carta
*
*  $ED Descrição da função
*		Avança o ponteiro do baralho o número de vezes indicadas.
*		Para isso chama a função LIS_AvancarElementoCorrente do modulo
*		lista, para auxiliar na função.
*
*  $EP Parâmetros
*		pBaralho - ponteiro para o baralho na posição onde dever ser avançada
*		cartas - numero de cartas a serem avançadas
*
*  $FV Valor retornado
*		BAR_CondRetOK			- se "cartas" elementos tiverem sido andados
*		BAR_CondRetFimBaralho	- se encontrou o fim da lista antes de andar "cartas"
*                         elementos
*		BAR_CondRetBaralhoVazio	- se o baralho está vazio
*
***********************************************************************/

BAR_tpCondRet BAR_AvancarCarta( BAR_tppBaralho pBaralho , int cartas ) ;

/***********************************************************************
*
*  $FC Função: BAR  &Ir para o inicio do baralho
*
*  $ED Descrição da função
*		Essa função chama IrInicioLista que é uma função do modulo lista,
*		que faz com que volte para o inicio da lista, que no caso é
*		o inicio do baralho.
*
*  $EP Parâmetros
*		pBaralho - ponteiro para o baralho a manipular
*
*
***********************************************************************/

void BAR_IrInicioBaralho( BAR_tppBaralho pBaralho ) ;

/***********************************************************************
*
*  $FC Função: BAR  &Ir para o fim do baralho
*
*  $ED Descrição da função
*		Essa função chama IrFimLista que é uma função do modulo lista,
*		que faz com que vá para o fim da lista, que no caso é
*		o fim do baralho.
*
*  $EP Parâmetros
*		pBaralho - ponteiro para o baralho a manipular
*
*
***********************************************************************/

void BAR_IrFinalBaralho( BAR_tppBaralho pBaralho ) ;

/***********************************************************************
*
*  $FC Função: BAR  &Obter referência para a carta contida no baralho
*
*  $ED Descrição da função
*     Obtem a referência para a carta contida no elemento corrente do baralho
*
*  $EP Parâmetros
*     pBaralho - ponteiro para o baralho de onde se quer a carta
*
*  $FV Valor retornado
*     não NULL - se a carta corrente existe
*     NULL     - se o baralho estiver vazio
*                Pode retornar NULL se o valor inserido na carta for NULL.
*
***********************************************************************/

BAR_tppCarta BAR_ObterCarta( BAR_tppBaralho pBaralho ) ;

/***********************************************************************
*
*  $FC Função: BAR  &Remover Carta Corrente
*
*  $ED Descrição da função
*		Essa função remove a carta corrente.
*
*  $EP Parâmetros
*		pBaralho	- ponteiro para o baralho a manipular
*		numero 		- numero da carta a ser removida
*		Naipe 		- naipe da carta a ser removida
*
*  $FV Valor retornado
*		BAR_CondRetOK			 - se a carta exigida foi removida
*		BAR_CondRetBaralhoVazio	 - se o baralho está vazio
*	*	 - se o baralho está vazio
*		BAR_CondRetNaoAchouCarta - se a carta nao estava no baralho
***********************************************************************/

BAR_tpCondRet BAR_RemoverCartaCorrente( BAR_tppBaralho pBaralho ) ;

/***********************************************************************
*
*  $FC Função: BAR  &Remover Carta Especificada
*
*  $ED Descrição da função
*		Essa função remove a carta que o usuário necessitar.
*		O baralho quando retornado tem a carta corrente como a
*			primeira carta do baralho
*
*  $EP Parâmetros
*		pBaralho	- ponteiro para o baralho a manipular
*		numero 		- numero da carta a ser removida
*		Naipe 		- naipe da carta a ser removida
*
*  $FV Valor retornado
*		BAR_CondRetOK			 - se a carta exigida foi removida
*		BAR_CondRetBaralhoVazio	 - se o baralho está vazio
*	*	 - se o baralho está vazio
*		BAR_CondRetNaoAchouCarta - se a carta nao estava no baralho
***********************************************************************/

BAR_tpCondRet BAR_RemoverCartaEspecificada( BAR_tppBaralho pBaralho ,
											BAR_tppCarta pCarta ) ;

/***********************************************************************
*
*  $FC Função: BAR  &Cria Baralho Completo
*
*  $ED Descrição da função
*		Essa funçao cria um baralho genérico. Qualquer jogo de baralho
*		poderia usar essa função para ter o baralho completo.
*		Ele cria as cartas e vai inserindo na lista.
*
*  $EP Parâmetros
*		pBaralho	- ponteiro para o baralho que vai ser manipulado
*
*  $FV Valor retornado
*		BAR_CondRetFaltouMemoriaBaralho  - se faltou memoria para inserir no baralho
*		BAR_CondRetOK					 - se o baralho foi criado corretamente
*		BAR_CondRetFaltouMemoriaCarta    - se faltou memoria para inserir na carta
*
***********************************************************************/

BAR_tpCondRet BAR_CriarBaralhoCompleto( BAR_tppBaralho pBaralho ) ;

/***********************************************************************
*
*  $FC Função: BAR  &Criar Baralho Truco
*
*  $ED Descrição da função
*		Essa função recebe um baralho e remove deles as cartas que não são
*		utilizadas para o jogo do truco, transformando num baralho apenas
*		para o truco.
*
*  $EP Parâmetros
*		pBaralho	- ponteiro para o baralho que vai ser manipulado
*
*  $FV Valor retornado
*		BAR_CondRetFaltouMemoriaCarta  	- se faltou memoria para criar 
*										  a carta a ser removida
*		BAR_CondRetOK					- se o baralho foi editado 
*										  corretamente
*		BAR_CondRetBaralhoVazio	 		- se o baralho está vazio
*
***********************************************************************/

BAR_tpCondRet BAR_CriarBaralhoTruco( BAR_tppBaralho pBaralho ) ;

/***********************************************************************
*
*  $FC Função: BAR  &Libera carta
*
*  $ED Descrição da função
*		Essa função libera o armazenamento da memória de uma carta
*
*  $EP Parâmetros
*		pCarta	- ponteiro para a carta que vai ser libertada
*
*
***********************************************************************/

void LiberarCarta( BAR_tppCarta pCarta ) ;

#undef BARALHO_EXT

#else
#endif