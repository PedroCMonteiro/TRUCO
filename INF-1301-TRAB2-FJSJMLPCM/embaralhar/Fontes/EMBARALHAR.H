#if ! defined( EMBARALHAR_ )
#define EMBARALHAR_
/***************************************************************************
*
*  $MCD M�dulo de defini��o: EMB  Embaralhar um baralho
*
*  Arquivo gerado:              EMBARALHAR.H
*  Letras identificadoras:      EMB
*
*  Projeto: INF 1301 / 1628 Implementa��o do jogo de Truco Paulista em C
*  Gestor:  LES/DI/PUC-Rio
*  Autores: PCM Pedro Castro Monteiro
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*     1       PCM   01/mai/2018 in�cio desenvolvimento
*
*  $ED Descri��o do m�dulo
*     Embaralha um baralho com n�mero gen�rico de cartas.
*     Se o baralho passado n�o tiver nenhuma carta o m�dulo n�o faz nada com o baralho.
*
***************************************************************************/

#if defined( EMBARALHAR_OWN )
#define EMBARALHAR_EXT
#else
#define EMBARALHAR_EXT extern
#endif

#include "BARALHO.H"

/***** Declara��es exportadas pelo m�dulo *****/

/*  $TC Tipo de dados: EMB Condi��es de retorno
*
*
*  $ED Descri��o do tipo
*     Condi��es de retorno da fun��o de embaralhar
*
***********************************************************************/

typedef enum {

	EMB_CondRetOK ,
	/* Embaralhou corretamente */

	EMB_CondRetBaralhoVazio ,
	/* O baralho n�o cont�m elementos */

	EMB_CondRetFaltouMemoriaBaralho ,
	/* Faltou mem�ria ao tentar criar um baralho */

	EMB_CondRetFaltouMemoriaCarta ,
	/* Faltou mem�ria ao tentar criar uma carta */

	EMB_CondRetFaltouMemoriaInserirCarta
	/* Faltou mem�ria ao tentar inseriri uma carta em um baralho */

} EMB_tpCondRet ;


/***********************************************************************
*
*  $FC Fun��o: EMB  &Embaralhar
*
*  $ED Descri��o da fun��o
*     Embaralha todas as cartas de um baralho com n�mero gen�rico de cartas,
*	  pegando uma carta aleat�ria, na parte do baralho onde ainda n�o foi
*     embaralhado baralho a colocando ela no final dele, assim embaralhando-a.
*     O baralho retornado tem a carta corrente como a primeira carta do baralho.
*     Se o barlho passado n�o tiver cartas, a fun��o n�o faz nada com ele e retorna
*     como se tivesse embaralhado sem problemas.
*
*  $EP Par�metros
*     pBaralho  - ponteiro para o baralho a ser embaralhado
*
*  $FV Valor retornado
*     EMB_CondRetOK                         - embaralhou sem problemas
*     EMB_CondRetBaralhoVazio               - o baralho passado estava vazio
*     EMB_CondRetFaltouMemoriaBaralho       - memoria insuficiente para criar um baralho
*     EMB_CondRetFaltouMemoriaCarta         - memoria insuficiente para criar uma carta
*     EMB_CondRetFaltouMemoriaInserirCarta  - memoria insuficiente ao tentar inserir um carta no baralho
*
***********************************************************************/

EMB_tpCondRet EMB_Embaralhar( BAR_tppBaralho pBaralho ) ;

#undef EMBARALHAR_EXT

/********** Fim do m�dulo de defini��o: EMB  Embaralhar um baralho **********/

#else
#endif
