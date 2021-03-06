#if ! defined( BARALHO_ )
#define BARALHO_
/***************************************************************************
*  $MCI M�dulo de implementa��o: BAR  Baralho
*
*  Arquivo gerado:              BARALHO.c
*  Letras identificadoras:      BAR
*
*  Projeto: INF 1301 / 1628 Implementa��o do jogo de Truco Paulista em C
*  Gestor:  LES/DI/PUC-Rio
*  Autores: JML Julia Maria Lima
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*     1       jml   05/mai/2018 in�cio desenvolvimento
*
*  $ED Descri��o do m�dulo
*		Implementa um baralho generalizado.
*		O baralho primeiramente � criado inteiro.
*		Cada carta do baralho tem um n�mero e um naipe.
*		Os n�meros sao de 1 a 13, sendo �s = 1; J = 11; Q = 12; K = 13;
*		O baralho tamb�m possui dois coringas, tendo seus naipes marcados
*			como Coringa e seus n�meros 1 e 2 para diferenci�-los.
*		Os coringas s�o colocados no final do baralho, quando se cria
*			o baralho completo
*
*		Nesse m�dulo � capaz de retirar as cartas para que se transforme
*			no baralho do jogo de truco.
*
***************************************************************************/

#if defined( BARALHO_OWN )
#define BARALHO_EXT
#else
#define BARALHO_EXT extern
#endif


#include "LISTA.H"

/***** Declara��es exportadas pelo m�dulo *****/

/* Tipo refer�ncia para um baralho */

typedef  LIS_tppLista BAR_tppBaralho ;

/* Tipo refer�ncia para uma carta */

typedef struct BAR_Carta * BAR_tppCarta ;

/***********************************************************************
*
*  $TC Tipo de dados: BAR Condi��es de retorno
*
*
*  $ED Descri��o do tipo
*     Condi��es de retorno das fun��es do baralho
*
***********************************************************************/

typedef enum {

	BAR_CondRetOK ,
	/* Concluiu corretamente */

	BAR_CondRetBaralhoVazio ,
	/* O baralho n�o cont�m elementos */

	BAR_CondRetFimBaralho ,
	/* Foi atingido o fim do baralho */

	BAR_CondRetFaltouMemoriaBaralho ,
	/* Faltou mem�ria ao tentar criar um baralho */

	BAR_CondRetFaltouMemoriaCarta ,
	/* Faltou mem�ria ao tentar criar uma carta */

	BAR_CondRetNaoAchouCarta
	/* Faltou mem�ria ao tentar achar uma carta */

} BAR_tpCondRet ;

/***********************************************************************
*
*  $TC Tipo de dados: BAR Naipes
*
*
*  $ED Descri��o do tipo
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
*  $ED Descri��o do tipo
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
*  $FC Fun��o: BAR  &Criar Baralho
*
*  $ED Descri��o da fun��o
*		Cria um baralho.
*
*  $FV Valor retornado
*     Se executou corretamente retorna o ponteiro para o baralho.
*     Este ponteiro ser� utilizado pelas fun��es que manipulem este baralho.
*
*     Se ocorreu algum erro, por exemplo falta de mem�ria ou dados errados,
*     a fun��o retornar� NULL.
*     N�o ser� dada mais informa��o quanto ao problema ocorrido.
*
***********************************************************************/

BAR_tppBaralho BAR_CriarBaralho( ) ;

/***********************************************************************
*
*  $FC Fun��o: BAR  &Criar Carta
*
*  $ED Descri��o da fun��o
*		Essa fun��o aloca sizeof(BAR_tppCarta) para criar uma nova carta.
*		Recebendo um valor da carta e o naipe e botando dentro da struct.
*
*  $EP Par�metros
*		numero	- valor da carta
*		Naipe 	- naipe da carta
*
*  $FV Valor retornado
*		NULL 	- se a carta nao tiver sido alocada corretamente
*		carta 	- com as informa��es novas criadas
*
***********************************************************************/

BAR_tppCarta BAR_CriarCarta( int numero , BAR_tpNaipe Naipe ) ;

/***********************************************************************
*
*  $FC Fun��o: BAR  &Inserir carta antes
*
*  $ED Descri��o da fun��o
*		Essa fun��o insere uma carta antes da posi��o recebida da lista.
*		Utilizando a LIS_InserirElementoAntes do modulo lista
*
*  $EP Par�metros
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
*  $FC Fun��o: BAR  &Inserir carta apos
*
*  $ED Descri��o da fun��o
*		Essa fun��o insere uma carta depois da posi��o recebida da lista.
*		Utilizando a LIS_InserirElementoApos do modulo lista
*
*  $EP Par�metros
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
*  $FC Fun��o: BAR  &Avan�ar a carta
*
*  $ED Descri��o da fun��o
*		Avan�a o ponteiro do baralho o n�mero de vezes indicadas.
*		Para isso chama a fun��o LIS_AvancarElementoCorrente do modulo
*		lista, para auxiliar na fun��o.
*
*  $EP Par�metros
*		pBaralho - ponteiro para o baralho na posi��o onde dever ser avan�ada
*		cartas - numero de cartas a serem avan�adas
*
*  $FV Valor retornado
*		BAR_CondRetOK			- se "cartas" elementos tiverem sido andados
*		BAR_CondRetFimBaralho	- se encontrou o fim da lista antes de andar "cartas"
*                         elementos
*		BAR_CondRetBaralhoVazio	- se o baralho est� vazio
*
***********************************************************************/

BAR_tpCondRet BAR_AvancarCarta( BAR_tppBaralho pBaralho , int cartas ) ;

/***********************************************************************
*
*  $FC Fun��o: BAR  &Ir para o inicio do baralho
*
*  $ED Descri��o da fun��o
*		Essa fun��o chama IrInicioLista que � uma fun��o do modulo lista,
*		que faz com que volte para o inicio da lista, que no caso �
*		o inicio do baralho.
*
*  $EP Par�metros
*		pBaralho - ponteiro para o baralho a manipular
*
*
***********************************************************************/

void BAR_IrInicioBaralho( BAR_tppBaralho pBaralho ) ;

/***********************************************************************
*
*  $FC Fun��o: BAR  &Ir para o fim do baralho
*
*  $ED Descri��o da fun��o
*		Essa fun��o chama IrFimLista que � uma fun��o do modulo lista,
*		que faz com que v� para o fim da lista, que no caso �
*		o fim do baralho.
*
*  $EP Par�metros
*		pBaralho - ponteiro para o baralho a manipular
*
*
***********************************************************************/

void BAR_IrFinalBaralho( BAR_tppBaralho pBaralho ) ;

/***********************************************************************
*
*  $FC Fun��o: BAR  &Obter refer�ncia para a carta contida no baralho
*
*  $ED Descri��o da fun��o
*     Obtem a refer�ncia para a carta contida no elemento corrente do baralho
*
*  $EP Par�metros
*     pBaralho - ponteiro para o baralho de onde se quer a carta
*
*  $FV Valor retornado
*     n�o NULL - se a carta corrente existe
*     NULL     - se o baralho estiver vazio
*                Pode retornar NULL se o valor inserido na carta for NULL.
*
***********************************************************************/

BAR_tppCarta BAR_ObterCarta( BAR_tppBaralho pBaralho ) ;

/***********************************************************************
*
*  $FC Fun��o: BAR  &Remover Carta Corrente
*
*  $ED Descri��o da fun��o
*		Essa fun��o remove a carta corrente.
*
*  $EP Par�metros
*		pBaralho	- ponteiro para o baralho a manipular
*		numero 		- numero da carta a ser removida
*		Naipe 		- naipe da carta a ser removida
*
*  $FV Valor retornado
*		BAR_CondRetOK			 - se a carta exigida foi removida
*		BAR_CondRetBaralhoVazio	 - se o baralho est� vazio
*	*	 - se o baralho est� vazio
*		BAR_CondRetNaoAchouCarta - se a carta nao estava no baralho
***********************************************************************/

BAR_tpCondRet BAR_RemoverCartaCorrente( BAR_tppBaralho pBaralho ) ;

/***********************************************************************
*
*  $FC Fun��o: BAR  &Remover Carta Especificada
*
*  $ED Descri��o da fun��o
*		Essa fun��o remove a carta que o usu�rio necessitar.
*		O baralho quando retornado tem a carta corrente como a
*			primeira carta do baralho
*
*  $EP Par�metros
*		pBaralho	- ponteiro para o baralho a manipular
*		numero 		- numero da carta a ser removida
*		Naipe 		- naipe da carta a ser removida
*
*  $FV Valor retornado
*		BAR_CondRetOK			 - se a carta exigida foi removida
*		BAR_CondRetBaralhoVazio	 - se o baralho est� vazio
*	*	 - se o baralho est� vazio
*		BAR_CondRetNaoAchouCarta - se a carta nao estava no baralho
***********************************************************************/

BAR_tpCondRet BAR_RemoverCartaEspecificada( BAR_tppBaralho pBaralho ,
											BAR_tppCarta pCarta ) ;

/***********************************************************************
*
*  $FC Fun��o: BAR  &Cria Baralho Completo
*
*  $ED Descri��o da fun��o
*		Essa fun�ao cria um baralho gen�rico. Qualquer jogo de baralho
*		poderia usar essa fun��o para ter o baralho completo.
*		Ele cria as cartas e vai inserindo na lista.
*
*  $EP Par�metros
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
*  $FC Fun��o: BAR  &Criar Baralho Truco
*
*  $ED Descri��o da fun��o
*		Essa fun��o recebe um baralho e remove deles as cartas que n�o s�o
*		utilizadas para o jogo do truco, transformando num baralho apenas
*		para o truco.
*
*  $EP Par�metros
*		pBaralho	- ponteiro para o baralho que vai ser manipulado
*
*  $FV Valor retornado
*		BAR_CondRetFaltouMemoriaCarta  	- se faltou memoria para criar 
*										  a carta a ser removida
*		BAR_CondRetOK					- se o baralho foi editado 
*										  corretamente
*		BAR_CondRetBaralhoVazio	 		- se o baralho est� vazio
*
***********************************************************************/

BAR_tpCondRet BAR_CriarBaralhoTruco( BAR_tppBaralho pBaralho ) ;

/***********************************************************************
*
*  $FC Fun��o: BAR  &Libera carta
*
*  $ED Descri��o da fun��o
*		Essa fun��o libera o armazenamento da mem�ria de uma carta
*
*  $EP Par�metros
*		pCarta	- ponteiro para a carta que vai ser libertada
*
*
***********************************************************************/

void LiberarCarta( BAR_tppCarta pCarta ) ;

#undef BARALHO_EXT

#else
#endif