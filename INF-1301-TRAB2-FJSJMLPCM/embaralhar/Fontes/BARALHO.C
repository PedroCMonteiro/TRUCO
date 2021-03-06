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
*
***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "LISTA.H"

#define BARALHO_OWN
#include "BARALHO.H"
#undef BARALHO_OWN

static const BAR_tpNaipe NAIPE[5] = { Espadas, Paus, Copas, Ouros , Coringa};
static const int NUM_NAIPE = 4;
static const int NUM_CARTAS = 13;

/***************************************************************************
*
*  Fun��o: BAR  &Ir para o inicio do baralho
*  ****/

void BAR_IrInicioBaralho(BAR_tppBaralho pBaralho) {
	IrInicioLista(pBaralho);
} /* Fim fun��o: BAR  &Ir para o inicio do baralho */

  /***************************************************************************
  *
  *  Fun��o: BAR  &Ir para o final do baralho
  *  ****/

void BAR_IrFinalBaralho(BAR_tppBaralho pBaralho) {
	IrFinalLista(pBaralho);
} /* Fim fun��o: BAR  &Ir para o final do baralho */

  /***************************************************************************
  *
  *  Fun��o: BAR  &Liberar carta
  *  ****/

void LiberarCarta(BAR_tppCarta pCarta) {
//	free(pCarta);
}/* Fim fun��o: BAR  &Liberar carta */

 /***************************************************************************
 *
 *  Fun��o: BAR  &Avan�ar a carta
 *  ****/

BAR_tpCondRet BAR_AvancarCarta(BAR_tppBaralho pBaralho, int numCarta) {
	LIS_tpCondRet CondRet;

#ifdef _DEBUG
	assert(pBaralho != NULL);
#endif

	CondRet = LIS_AvancarElementoCorrente(pBaralho, numCarta);
	if (CondRet == LIS_CondRetFimLista) {
		return BAR_CondRetFimBaralho;
	}
	else
	{
		if (CondRet == LIS_CondRetListaVazia) {
			return BAR_CondRetBaralhoVazio;
		}
	}
	return BAR_CondRetOK;
}/* Fim fun��o: BAR  &Avan�ar a carta */

BAR_tppBaralho BAR_CriaBaralho()
{
	BAR_tppBaralho pBaralho;

	pBaralho = LIS_CriarLista(LiberarCarta);
	if (pBaralho == NULL) {
		return NULL;
	}

	return pBaralho;

}


/***************************************************************************
*
*  Fun��o: BAR  &Obter carta
*  ****/

BAR_tppCarta BAR_ObterCarta(BAR_tppBaralho pBaralho) {
	return LIS_ObterValor(pBaralho);
}/* Fim fun��o: BAR  &Obter carta */

 /***************************************************************************
 *
 *  Fun��o: BAR  &Criar carta
 *  ****/

BAR_tppCarta BAR_CriaCarta(int numero, BAR_tpNaipe naipe) {
	BAR_tppCarta carta;
	carta = (BAR_tppCarta)malloc(sizeof(BAR_tppCarta));
	if (carta == NULL) {
		return NULL;
	}
	carta->naipe = naipe;
	carta->numero = numero;
	return carta;
}/* Fim fun��o: BAR  &Criar carta */

 /***************************************************************************
 *
 *  Fun��o: BAR  &Inserir carta antes
 *  ****/

BAR_tpCondRet BAR_InserirCartaAntes(BAR_tppBaralho pBaralho, BAR_tppCarta pCarta) {
	LIS_tpCondRet CondRet;
	CondRet = LIS_InserirElementoAntes(pBaralho, pCarta);
	if (CondRet == LIS_CondRetFaltouMemoria) {
		return BAR_CondRetFaltouMemoriaBaralho;
	}
	return BAR_CondRetOK;
}/* Fim fun��o: BAR  &Inserir carta antes */

 /***************************************************************************
 *
 *  Fun��o: BAR  &Inserir carta apos
 *  ****/

BAR_tpCondRet BAR_InserirCartaApos(BAR_tppBaralho pBaralho, BAR_tppCarta pCarta) {
	LIS_tpCondRet CondRet;
	CondRet = LIS_InserirElementoApos(pBaralho, pCarta);
	if (CondRet == LIS_CondRetFaltouMemoria) {
		return BAR_CondRetFaltouMemoriaBaralho;
	}
	return BAR_CondRetOK;
}/* Fim fun��o: BAR  &Inserir carta apos */

 /***************************************************************************
 *
 *  Fun��o: BAR  &Remove carta corrente
 *  ****/

BAR_tpCondRet BAR_RemoverCartaCorrente(BAR_tppBaralho pBaralho) {
	LIS_tpCondRet CondRet;
	CondRet = LIS_ExcluirElemento(pBaralho);
	if (CondRet == LIS_CondRetListaVazia) {
		return BAR_CondRetBaralhoVazio;
	}
	return BAR_CondRetOK;
}/* Fim fun��o: BAR  &Remover carta corrente */

 /***************************************************************************
 *
 *  Fun��o: BAR  &Remove cartas
 *  ****/

BAR_tpCondRet BAR_RemoverCartaEspecificada(BAR_tppBaralho pBaralho, BAR_tppCarta pCarta) {
	BAR_tpCondRet CondRet = BAR_CondRetOK;
	BAR_tppCarta carta;
#ifdef _DEBUG
	assert(pBaralho != NULL);
#endif

	BAR_IrInicioBaralho(pBaralho);
	carta = BAR_ObterCarta(pBaralho);
	while (carta != NULL) {
		if (carta->numero == pCarta->numero
			&& carta->naipe == pCarta->naipe) {
			CondRet = BAR_RemoverCartaCorrente(pBaralho);
			if (CondRet == LIS_CondRetListaVazia) {
				return BAR_CondRetBaralhoVazio;
			}
			else
				return BAR_CondRetOK;
		}
		CondRet = BAR_AvancarCarta(pBaralho, 1);
		if (CondRet == BAR_CondRetBaralhoVazio) {
			return BAR_CondRetBaralhoVazio;
		}
		else if (CondRet == BAR_CondRetFimBaralho) {
			break;
		}
		carta = BAR_ObterCarta(pBaralho);
	}
	BAR_IrInicioBaralho(pBaralho);
	return BAR_CondRetNaoAchouCarta;
}/* Fim fun��o: BAR  &Remover carta  especificada*/

 /***************************************************************************
 *
 *  Fun��o: BAR  &Criar baralho completo
 *  ****/

BAR_tpCondRet BAR_CriarBaralhoCompleto(BAR_tppBaralho pBaralho) {
	BAR_tpCondRet CondRet;
	BAR_tppCarta pCarta;
	int numero = -1,
		naipe = -1;
#ifdef _DEBUG
	assert(pBaralho != NULL);
#endif
	for (naipe = 0; naipe < NUM_NAIPE; naipe++) {
		for (numero = 1; numero < (NUM_CARTAS + 1); numero++) {
			pCarta = BAR_CriaCarta(numero, NAIPE[naipe]);
			if (pCarta == NULL) {
				return BAR_CondRetFaltouMemoriaCarta;
			}
			CondRet = BAR_InserirCartaApos(pBaralho, pCarta);
			if (CondRet == BAR_CondRetFaltouMemoriaBaralho) {
				return BAR_CondRetFaltouMemoriaBaralho;
			}
		}
	}
	/* Inser��o dos coringas */
	pCarta = BAR_CriaCarta(1, NAIPE[naipe]);
	if (pCarta == NULL) {
		return BAR_CondRetFaltouMemoriaCarta;
	}
	CondRet = BAR_InserirCartaApos(pBaralho, pCarta);
	if (CondRet == BAR_CondRetFaltouMemoriaBaralho) {
		return BAR_CondRetFaltouMemoriaBaralho;
	}

	pCarta = BAR_CriaCarta(2, NAIPE[naipe]);
	if (pCarta == NULL) {
		return BAR_CondRetFaltouMemoriaCarta;
	}
	CondRet = BAR_InserirCartaApos(pBaralho, pCarta);
	if (CondRet == BAR_CondRetFaltouMemoriaBaralho) {
		return BAR_CondRetFaltouMemoriaBaralho;
	}

	BAR_IrInicioBaralho(pBaralho);
	return BAR_CondRetOK;
}/* Fim fun��o: BAR  &Criar baralho completo */

 /***************************************************************************
 *
 *  Fun��o: BAR  &Criar baralho truco
 *  ****/

BAR_tpCondRet BAR_CriarBaralhoTruco(BAR_tppBaralho pBaralho) {
	BAR_tpCondRet CondRet;
	BAR_tppCarta pCarta;
	int naipe = -1,
		numero = -1;
#ifdef _DEBUG
	assert(pBaralho != NULL);
#endif
	CondRet = BAR_CriarBaralhoCompleto(pBaralho);
	if (CondRet != BAR_CondRetOK) {
		return CondRet;
	}
	for (naipe = 0; naipe < NUM_NAIPE; naipe++) {
		for (numero = 8; numero < 11; numero++) {
			pCarta = BAR_CriaCarta(numero, NAIPE[naipe]);
			if (pCarta == NULL) {
				return BAR_CondRetFaltouMemoriaCarta;
			}
			CondRet = BAR_RemoverCartaEspecificada(pBaralho, pCarta);
			if (CondRet == BAR_CondRetBaralhoVazio) {
				return BAR_CondRetBaralhoVazio;
			}
		}
	}
	/* Removendo os coringas */
	pCarta = BAR_CriaCarta(1, NAIPE[naipe]);
	if (pCarta == NULL) {
		return BAR_CondRetFaltouMemoriaCarta;
	}
	CondRet = BAR_RemoverCartaEspecificada(pBaralho, pCarta);
	if (CondRet == BAR_CondRetBaralhoVazio) {
		return BAR_CondRetBaralhoVazio;
	}

	pCarta = BAR_CriaCarta(2, NAIPE[naipe]);
	if (pCarta == NULL) {
		return BAR_CondRetFaltouMemoriaCarta;
	}
	CondRet = BAR_RemoverCartaEspecificada(pBaralho, pCarta);
	if (CondRet == BAR_CondRetBaralhoVazio) {
		return BAR_CondRetBaralhoVazio;
	}

	BAR_IrInicioBaralho(pBaralho);
	return BAR_CondRetOK;
}/* Fim fun��o: BAR  &Criar baralho truco */

 /********** Fim do m�dulo de implementa��o: BAR Baralho **********/
