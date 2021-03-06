/***************************************************************************
*  $MCI M�dulo de implementa��o: EMB  Embaralhar um baralho
*
*  Arquivo gerado:              EMBARALHAR.C
*  Letras identificadoras:      EMB
*
*  Projeto: INF 1301 / 1628 Implementa��o do jogo de Truco Paulista em C
*  Gestor:  LES/DI/PUC-Rio
*  Autores: PCM Pedro Castro Monteiro
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*     1       avs   02/mai/2018 in�cio desenvolvimento
*
***************************************************************************/

#include   <stdio.h>
#include   <stdlib.h>
#include   <memory.h>
#include   <malloc.h>
#include   <assert.h>

#include   "BARALHO.H"
#include   "GERAALT.H"

#define EMBARALHAR_OWN
#include "EMBARALHAR.H"
#undef EMBARALHAR_OWN

/*****  C�digo das fun��es exportadas pelo m�dulo  *****/

/***************************************************************************
*
*  Fun��o: EMB  &Embaralhar
*  ****/

EMB_tpCondRet EMB_Embaralhar( BAR_tppBaralho pBaralho )
{

	BAR_tpCondRet CondRet = BAR_CondRetOK ;

	/* pCarta: ponteiro para os valores(naipe e n�mero) da carta a ser realocada 
	           para o final do baralho, assim embaralhando-a */
	BAR_tppCarta pCarta ;

	/* posi��o:   guardar� a posi��o da carta a ser embaralhada 
	   numCartas: guardar� o numCartas existes no baralho, passado como par�metro */
	int posicao = -1 ,
		numCartas = 0  ;

#ifdef _DEBUG
	assert( pBaralho != NULL );
#endif    

	pCarta = ( BAR_tppCarta )malloc( sizeof( BAR_tpCarta )) ;

	if ( pCarta == NULL )
	{
		return EMB_CondRetFaltouMemoriaCarta ;
	} /* if */

	/* Obter o n�mero de cartas existentes no barlho passado */

	BAR_IrInicioBaralho( pBaralho ) ;

	while ( CondRet != BAR_CondRetFimBaralho && CondRet != BAR_CondRetBaralhoVazio )
	{
		numCartas++ ;
		CondRet = BAR_AvancarCarta( pBaralho , 1 ) ;
	} /* while */

	while ( CondRet != BAR_CondRetBaralhoVazio && numCartas != 0 )
	{
		BAR_IrInicioBaralho( pBaralho ) ;

		/* Obter a posi��o aleat�ria da carta a ser remeovida e colocar no final do baralho */

		ALT_Inicializar( 1 ) ;

		posicao = ALT_GerarDistUniforme( 0 , numCartas - 1  ) ;

		CondRet = BAR_AvancarCarta( pBaralho , posicao ) ;

		if ( CondRet != BAR_CondRetOK ) 
		{
			break ;
		} /* if */

		/* Obter a carta a ser colocada no final do baralho */
		pCarta = BAR_ObterCarta( pBaralho ) ;

		if ( pCarta == NULL )
		{
			break ;
		} /* if */

		/* Remover a carta que s�ra colocada no final do baralho */

		CondRet = BAR_RemoverCartaCorrente( pBaralho ) ;

		if (CondRet == BAR_CondRetOK)
		{
			numCartas--;
		} /* if */
		
		/* Colocar a carta retirada no final do baralho e atualizar o 
		n�mero de cartas que faltam embaralhar*/

		BAR_IrFinalBaralho( pBaralho ) ;

		CondRet = BAR_InserirCartaApos( pBaralho , pCarta ) ;

		if ( CondRet == BAR_CondRetFaltouMemoriaBaralho )
		{
			return EMB_CondRetFaltouMemoriaInserirCarta ;
		}
		else
		{
			if ( CondRet == BAR_CondRetBaralhoVazio )
			{
				return EMB_CondRetBaralhoVazio ;
			} /* if */
		} /* if */
	} /* while */

	BAR_IrInicioBaralho( pBaralho ) ;

	return  EMB_CondRetOK ;

} /* Fim fun��o: EMB  &Embaralhar */

  /********** Fim do m�dulo de implementa��o: EMB  Embaralhar um baralho **********/

