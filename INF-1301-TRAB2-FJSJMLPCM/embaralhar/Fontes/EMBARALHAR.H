#if ! defined( EMBARALHAR_ )
#define EMBARALHAR_
/***************************************************************************
*
*  $MCD Módulo de definição: EMB  Embaralhar um baralho
*
*  Arquivo gerado:              EMBARALHAR.H
*  Letras identificadoras:      EMB
*
*  Projeto: INF 1301 / 1628 Implementação do jogo de Truco Paulista em C
*  Gestor:  LES/DI/PUC-Rio
*  Autores: PCM Pedro Castro Monteiro
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*     1       PCM   01/mai/2018 início desenvolvimento
*
*  $ED Descrição do módulo
*     Embaralha um baralho com número genérico de cartas.
*     Se o baralho passado não tiver nenhuma carta o módulo não faz nada com o baralho.
*
***************************************************************************/

#if defined( EMBARALHAR_OWN )
#define EMBARALHAR_EXT
#else
#define EMBARALHAR_EXT extern
#endif

#include "BARALHO.H"

/***** Declarações exportadas pelo módulo *****/

/*  $TC Tipo de dados: EMB Condições de retorno
*
*
*  $ED Descrição do tipo
*     Condições de retorno da função de embaralhar
*
***********************************************************************/

typedef enum {

	EMB_CondRetOK ,
	/* Embaralhou corretamente */

	EMB_CondRetBaralhoVazio ,
	/* O baralho não contém elementos */

	EMB_CondRetFaltouMemoriaBaralho ,
	/* Faltou memória ao tentar criar um baralho */

	EMB_CondRetFaltouMemoriaCarta ,
	/* Faltou memória ao tentar criar uma carta */

	EMB_CondRetFaltouMemoriaInserirCarta
	/* Faltou memória ao tentar inseriri uma carta em um baralho */

} EMB_tpCondRet ;


/***********************************************************************
*
*  $FC Função: EMB  &Embaralhar
*
*  $ED Descrição da função
*     Embaralha todas as cartas de um baralho com número genérico de cartas,
*	  pegando uma carta aleatória, na parte do baralho onde ainda não foi
*     embaralhado baralho a colocando ela no final dele, assim embaralhando-a.
*     O baralho retornado tem a carta corrente como a primeira carta do baralho.
*     Se o barlho passado não tiver cartas, a função não faz nada com ele e retorna
*     como se tivesse embaralhado sem problemas.
*
*  $EP Parâmetros
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

/********** Fim do módulo de definição: EMB  Embaralhar um baralho **********/

#else
#endif
