/*Modulo de implementação da partida*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "LISTA.H"
#include "BARALHO.H"
#include "EMBARALHAR.H"
#include "PARTIDA.H"

static const int PTD_FUGIU = -11;
static const int PTD_AVANCA = 11;
static const int PTD_PARA = 121;
static const int PTD_MAOFERRO = 222;
static const int PTD_MAOONZE = 111;

/***************************************************************************
*
*					Funções para manipulação dos jogadores
*
***************************************************************************/


/***************************************************************************
*
*  Função: PTD  &Criar Dados Jogador
*  ****/

PTD_tppDadosJogador PTD_CriaDadosJogador(char *nome, int Equipe, int ident)
{
	PTD_tppDadosJogador Dados;

	Dados = (PTD_tppDadosJogador)malloc(sizeof(PTD_tppDadosJogador));

	if (Dados == NULL)
	{
		return NULL;
	}

	Dados->Mao = BAR_CriarBaralho();

	if (Dados->Mao == NULL)
	{
		return NULL;
	}

	strcpy(Dados->Nome,nome);
	Dados->Equipe = Equipe;
	Dados->Id     = ident;
	Dados->Pontos = 0;

	return Dados;
}/*Fim função: PTD &Criar Dados Jogador*/

 /***************************************************************************
 *
 *  Função: PTD  &Remover Dado Jogador Corrente
 *  ****/

PTD_tpCondRet PTD_RemoverDadoJogadorCorrente(PTD_tppJogadores pjogadores)
{
	LIS_tpCondRet CondRet;

	CondRet = LIS_ExcluirElemento(pjogadores);

	if (CondRet == LIS_CondRetListaVazia)
	{
		return PTD_CondRetSemJogadores;
	}

	return PTD_CondRetOK;
}

/***************************************************************************
*
*  Função: PTD  &Excluir Dados Jogador
*  ****/

void PTD_ExcluirDadosJogador(PTD_tppDadosJogador pDados) 
{
	BAR_DestruirBaralho(pDados->Mao);

	free(pDados);
}/*Fim função: PTD &Excluir Dados Jogador*/

 /***************************************************************************
 *
 *  Função: PTD  &Ir Primeiro Jogador
 *  ****/

void PTD_IrPrimeiroJogador(PTD_tppJogadores pJogadores)
{ 
	IrInicioLista(pJogadores);
}/*Fim função: PTD &Ir Primeiro Jogador*/

 /***************************************************************************
 *
 *  Função: PTD  &Ir Ultimo Jogador
 *  ****/

void PTD_IrUltimoJogador(PTD_tppJogadores pJogadores) 
{
	IrFinalLista(pJogadores);
}/*Fim função: PTD &Ir Ultimo Jogador*/

 /***************************************************************************
 *
 *  Função: PTD  &Criar Jogadores Lista
 *  ****/

PTD_tppJogadores PTD_CriarJogadoresLista(void) 
{
	PTD_tppJogadores pJogadores;

	pJogadores = LIS_CriarLista(NULL);

	if (pJogadores == NULL)
	{
		return NULL;
	}

	return pJogadores;
}/*Fim função: PTD &Criar Jogadores Lista*/

 /***************************************************************************
 *
 *  Função: PTD  &Obter Dados Jogador
 *  ****/

PTD_tppDadosJogador PTD_ObterDadosJogador(PTD_tppJogadores pJogadores) 
{
	return (PTD_tppDadosJogador)LIS_ObterValor(pJogadores);
}/*Fim função: PTD &Obter Dados Jogador */

 /***************************************************************************
 *
 *  Função: PTD  &Inserir Jogador
 *  ****/

PTD_tpCondRet PTD_InserirJogador(PTD_tppDadosJogador pDados, PTD_tppJogadores pJogadores)
{
	LIS_tpCondRet CondRet;

	CondRet = LIS_InserirElementoAntes(pJogadores, pDados);
	
	if (CondRet == LIS_CondRetFaltouMemoria) 
	{
		return PTD_CondRetFaltouMemoriaDadosJogador;
	}

	return PTD_CondRetOK;
}/*Fim função: PTD &Obter Dados Jogador */

 /***************************************************************************
 *
 *  Função: PTD  &Avancar Jogador
 *  ****/

PTD_tpCondRet PTD_AvancarJogador(PTD_tppJogadores pJogadores, int numAvanco)
{
	LIS_tpCondRet CondRet;

#ifdef _DEBUG
	assert(pJogadores != NULL);
#endif

	CondRet = LIS_AvancarElementoCorrente(pJogadores, numAvanco);
	if (CondRet == LIS_CondRetFimLista)
	{
		return PTD_CondRetUltimoJogador;
	}
	else
	{
		if (CondRet == LIS_CondRetListaVazia)
		{
			return PTD_CondRetSemJogadores;
		}
	}
	return PTD_CondRetOK;
}/* Fim função: PTD  &Avançar Jogador */

 /***************************************************************************
 *
 *  Função: PTD  &Procurar Jogador
 *  ****/

PTD_tpCondRet PTD_ProcurarJogador(PTD_tppJogadores pJogadores, PTD_tppDadosJogador pDados) 
{
	LIS_tpCondRet CondRet;

#ifdef _DEBUG
	assert(pJogadores != NULL);
#endif

	CondRet = LIS_ProcurarValor(pJogadores, pDados);
	if (CondRet == LIS_CondRetNaoAchou)
	{
		return PTD_CondRetNaoAchouJogador;
	}
	else
	{
		if (CondRet == LIS_CondRetListaVazia) 
		{
			return PTD_CondRetSemJogadores;
		}
	}
	return PTD_CondRetOK;
}/* Fim função: PTD  &Procurar Jogador */

 /***************************************************************************
 *
 *  Função: PTD  &Atualiza Dados
 *  ****/
PTD_tpCondRet PTD_AtualizaDados(PTD_tppJogadores pJogadores, PTD_tppDadosJogador pDadosVelhos, PTD_tppDadosJogador pDadosNovos) 
{
	PTD_tpCondRet PtdCondRet;

	PtdCondRet = PTD_ProcurarJogador(pJogadores, pDadosVelhos);

	if (PtdCondRet != PTD_CondRetOK) 
	{
		return PtdCondRet;
	}

	PtdCondRet = PTD_InserirJogador(pDadosNovos, pJogadores);

	if (PtdCondRet != PTD_CondRetOK)
	{
		return PtdCondRet;
	}

	PtdCondRet = PTD_AvancarJogador(pJogadores, 1);

	if (PtdCondRet != PTD_CondRetOK)
	{
		return PtdCondRet;
	}

	PtdCondRet = PTD_RemoverDadoJogadorCorrente(pJogadores);

	if (PtdCondRet != PTD_CondRetOK)
	{
		return PtdCondRet;
	}

	return PtdCondRet;

}/* Fim função: PTD  &Atualiza Dados */

 /***************************************************************************
 *
 *  Função: PTD  &Gerar Maos
 *  ****/

PTD_tpCondRet PTD_GeraMaos(BAR_tppBaralho pBaralho, PTD_tppJogadores pJogadores) 
{

#ifdef _DEBUG
	assert(pJogadores != NULL);
#endif

	BAR_tpCondRet BarCondRet;
	PTD_tpCondRet PtdCondRet = PTD_CondRetOK;

	BAR_tppCarta pCarta;
	PTD_tppDadosJogador pDadosVelhos;
	PTD_tppDadosJogador pDados;

	int j = -1;

	pCarta       = (BAR_tppCarta)malloc(sizeof(BAR_tpCarta));
	pDados       = (PTD_tppDadosJogador)malloc(sizeof(PTD_tpDadosJogador));
	pDadosVelhos = (PTD_tppDadosJogador)malloc(sizeof(PTD_tpDadosJogador));

	if (pDados == NULL || pDadosVelhos == NULL)
	{
		return PTD_CondRetFaltouMemoriaDadosJogador;
	}

	if (pCarta == NULL)
	{
		return PTD_CondRetErroBaralho;
	}

	PTD_IrPrimeiroJogador(pJogadores);

	while (PtdCondRet == PTD_CondRetOK)
	{
		pDadosVelhos = PTD_ObterDadosJogador(pJogadores);

		if (pDadosVelhos == NULL)
		{
			return PTD_CondRetSemJogadores;
		}

		pDados = pDadosVelhos;

		for (j = 0;j<3;j++) 
		{
			pCarta = BAR_ObterCarta(pBaralho);

			if (pCarta == NULL)
			{
				return PTD_CondRetErroBaralho;
			}

			BarCondRet = BAR_RemoverCartaCorrente(pBaralho);

			if (BarCondRet != BAR_CondRetOK)
			{
				return PTD_CondRetErroBaralho;
			}

			BarCondRet = BAR_InserirCartaApos(pDados->Mao, pCarta);

			if (BarCondRet != BAR_CondRetOK)
			{
				return PTD_CondRetErroBaralho;
			}
		}

		PtdCondRet = PTD_AtualizaDados(pJogadores, pDadosVelhos, pDados);

		if (PtdCondRet != PTD_CondRetOK)
		{
			return PtdCondRet;
		}

		//Avança para o proximo jogador			
		PtdCondRet = PTD_AvancarJogador(pJogadores, 1);

		if (PtdCondRet == PTD_CondRetSemJogadores) 
		{
			return PTD_CondRetSemJogadores;
		}
	}

	return PTD_CondRetOK;

}/* Fim função: PTD  &Gerar Maos */

 /***************************************************************************
 *
 *  Função: PTD  &Destruit Mao
 *  ****/
void PTD_DestruirMao(PTD_tppJogadores pJogadores) 
{
	PTD_tppDadosJogador pDadosVelhos;
	PTD_tppDadosJogador pDadosNovos;

	pDadosNovos  = (PTD_tppDadosJogador)malloc(sizeof(PTD_tpDadosJogador));
	pDadosVelhos = (PTD_tppDadosJogador)malloc(sizeof(PTD_tpDadosJogador));


	pDadosNovos = PTD_ObterDadosJogador(pJogadores);
	pDadosVelhos = pDadosNovos;

	LIS_DestruirLista(pDadosNovos->Mao);

	PTD_AtualizaDados(pJogadores, pDadosVelhos, pDadosNovos);

}/* Fim função: PTD  &Destruir Mao */


 /***************************************************************************
 *
 *  Função: PTD  &Excluir Carta Mao
 *  ****/

PTD_tpCondRet PTD_ExcluirCartaMao(PTD_tppJogadores pJogadores, PTD_tppDadosJogador pDados, int PosicaoCarta)
{
	//Intervalo válido para PosicaoCarta [1,3]
	//Exclui apenas uma carta de apenas um jogador
	BAR_tpCondRet BarCondRet;
	PTD_tpCondRet PtdCondRet;
	PTD_tppDadosJogador pDadosNovos;
#ifdef _DEBUG
	assert(pJogadores != NULL);
	assert(PosicaoCarta != 0);
#endif
	PtdCondRet = PTD_ProcurarJogador(pJogadores, pDados);
	if (PtdCondRet != PTD_CondRetOK)
	{
		return PtdCondRet;
	}
	pDadosNovos = PTD_ObterDadosJogador(pJogadores);
	BAR_IrInicioBaralho(pDadosNovos->Mao);
	BarCondRet = BAR_AvancarCarta(pDadosNovos->Mao, PosicaoCarta - 1);
	if (BarCondRet != BAR_CondRetOK)
	{
		return PTD_CondRetErroBaralho;
	}
	BarCondRet = BAR_RemoverCartaCorrente(pDadosNovos->Mao);
	if (BarCondRet != BAR_CondRetOK)
	{
		return PTD_CondRetErroBaralho;
	}
	PtdCondRet = PTD_AtualizaDados(pJogadores, pDados, pDadosNovos);
	if (PtdCondRet != PTD_CondRetOK)
	{
		return PtdCondRet;
	}
	return PTD_CondRetOK;


}/* Fim função: PTD  &Excluir Carta Mao */

 /***************************************************************************
 *
 *  Função: PTD  &Obter Carta Mao
 *  ****/

BAR_tppCarta PTD_ObterCartaMao(PTD_tppJogadores pJogadores, PTD_tppDadosJogador pDados, int PosicaoCarta) 
{
	BAR_tppCarta pCarta;
	PTD_tppDadosJogador pDadosNovos;
	BAR_tpCondRet BarCondRet;
	PTD_tpCondRet PtdCondRet;
	PtdCondRet = PTD_ProcurarJogador(pJogadores, pDados);
	if (PtdCondRet != PTD_CondRetOK) 
	{
		return NULL;
	}
	pDadosNovos = PTD_ObterDadosJogador(pJogadores);
	if (pDados == NULL)
	{
		return NULL;
	}
	BAR_IrInicioBaralho(pDadosNovos->Mao);
	BarCondRet = BAR_AvancarCarta(pDadosNovos->Mao, PosicaoCarta - 1);
	if (BarCondRet == BAR_CondRetBaralhoVazio)
	{
		return NULL;
	}
	pCarta = BAR_ObterCarta(pDadosNovos->Mao);
	return pCarta;
}/* Fim função: PTD  &Obter Carta Mao */


 /**************************************************************************
 *
 *							Funções para manipulação da Mesa
 *
 ***************************************************************************/

 /***************************************************************************
 *
 *  Função: PTD  &Criar Mesa
 *  ****/

PTD_tppMesa PTD_CriarMesa(void) 
{
	PTD_tppMesa pMesa;

	pMesa = BAR_CriarBaralho();

	if (pMesa == NULL) 
	{
		return NULL;
	}

	return pMesa;

}/*Fim função: PTD &Criar Mesa */

 /***************************************************************************
 *
 *  Função: PTD  &Esvaziar Mesa
 *  ****/

void PTD_EsvaziarMesa(PTD_tppMesa pMesa) 
{
	BAR_LimparBaralho(pMesa); // <<<------------------------------- Trocar por função do Baralho
}/*Fim função: PTD &Esvaziar Mesa */

 /***************************************************************************
 *
 *  Função: PTD  &Destruir Mesa
 *  ****/

void PTD_DestruirMesa(PTD_tppMesa pMesa)
{
	BAR_DestruirBaralho(pMesa); //<<<------------------------------- Trocar por função do Baralho
}/*Fim função: PTD &Destruir Mesa */

 /***************************************************************************
 *
 *  Função: PTD  &Ir Inicio Mesa
 *  ****/

void PTD_IrInicioMesa(PTD_tppMesa pMesa)
{
	BAR_IrInicioBaralho(pMesa);
}/*Fim função: PTD &Ir Inicio Mesa */

 /***************************************************************************
 *
 *  Função: BAR  &Inserir carta  Mesa
 *  ****/

BAR_tppCarta PTD_ObterCartaMesa(PTD_tppMesa pMesa) 
{
	return BAR_ObterCarta(pMesa);
}

/***************************************************************************
*
*  Função: BAR  &Inserir carta  Mesa
*  ****/


PTD_tpCondRet PTD_InserirCartaMesa(PTD_tppMesa pMesa, BAR_tppCarta pCarta)
{
	BAR_tpCondRet CondRet;

	CondRet = BAR_InserirCartaApos(pMesa, pCarta);

	if (CondRet == BAR_CondRetFaltouMemoriaBaralho)
	{
		return PTD_CondRetFaltouMemoriaMesa;
	}

	return PTD_CondRetOK;
}/* Fim função: BAR  &Inserir Carta Mesa */

 /***************************************************************************
 *
 *  Função: PTD  &Avancar Carta Mesa
 *  ****/

PTD_tpCondRet PTD_AvancarCartaMesa(PTD_tppMesa pMesa, int numCarta) 
{
	BAR_tpCondRet CondRet;

	CondRet = BAR_AvancarCarta(pMesa, numCarta);
	if (CondRet == BAR_CondRetFimBaralho) 
	{
		return PTD_CondRetUltimaCartaMesa;
	}
	else
	{
		if (CondRet == BAR_CondRetBaralhoVazio)
		{
			return PTD_CondRetMesaVazia;
		}
	}
	return PTD_CondRetOK;
}/* Fim função: PTD  &Avançar Carta Mesa */



 /***************************************************************************
 *
 *  Função: PTD  &Ordem Primordial
 *  ****/

PTD_tppOrdenacao PTD_OrdemPrimordial(void)
{
	int i;
	PTD_tppOrdenacao pOrdem;

	pOrdem = (PTD_tppOrdenacao)malloc(sizeof(PTD_tpOrdenacao));

	if (pOrdem == NULL)
	{
		return NULL;
	}

	BAR_tpNaipe naipe[] = { Ouros, Espadas, Copas, Paus };
	int	valores[]       = { 4, 5, 6, 7, 12, 11, 13, 1, 2, 3 };

	for (i = 0;i<10;i++)
	{
		if (i < 4)
		{
			pOrdem->OrdemNaipe[i] = naipe[i];
		}
		pOrdem->OrdemValor[i] = valores[i];
	}
	
	return pOrdem;

}/* Fim função: PTD  &Ordem Primordial */

 /***************************************************************************
 *
 *  Função: PTD  &Determina Manilha
 *  ****/


void PTD_DeterminaManilha(PTD_tppOrdenacao pOrdem, BAR_tppCarta pCartaVira)
{
	int ValorMax = -1,
		posicao = 0;

	if (pCartaVira->numero == 3)
	{
		ValorMax = 4;
	}
	else
	{
		for (posicao = 0;posicao < 9;posicao++)
		{

			if (pOrdem->OrdemValor[posicao] == pCartaVira->numero)
			{

				posicao++;
				ValorMax = pOrdem->OrdemValor[posicao];
				break;
			} /* if */
		} /* for */
	} /* if */

	while (posicao < 9)
	{
		pOrdem->OrdemValor[posicao] = pOrdem->OrdemValor[posicao + 1];
		posicao++;
	} /* while */

	pOrdem->OrdemValor[posicao] = ValorMax;

}/* Fim função: PTD  &Determina Manilha */

 /***************************************************************************
 *
 *  Função: PTD  &Comparar Cartas
 *  ****/

int PTD_ComparaCartas(BAR_tppCarta pCarta1, BAR_tppCarta pCarta2, PTD_tppOrdenacao pOrdem)
{
	//Retorna a posição da carta de maior forca
	int p1 = -1, p2 = -1, i;

	for (i = 0;i<10;i++)
	{
		if (pOrdem->OrdemValor[i] == pCarta1->numero)
		{
			p1 = i;
		}
		if (pOrdem->OrdemValor[i] == pCarta2->numero)
		{
			p2 = i;
		}
	}

	if (p2 > p1)
	{
		return 2;
	}
	else if (p1 > p2)
	{
		return 1;
	}	
	else
	{
		for (i = 0;i<4;i++)
		{
			if (pOrdem->OrdemNaipe[i] == pCarta1->naipe)
			{
				p1 = i;
			}
			if (pOrdem->OrdemNaipe[i] == pCarta2->naipe)
			{
				p2 = i;
			}
		}
		if (p1>p2)
		{
			return 2;
		}
		if (p1>p2)
		{
			return 1;
		}
		else {
			return 0;
		}
	}
}

/***************************************************************************
*
*  Função: PTD  &Computa Vencedor Mao
*  ****/
int PTD_ComputaVencedorRodada(PTD_tppMesa pMesa, PTD_tppOrdenacao pOrdem) 
{
	int i = -1,
		id = -1,
		comp = -1;
	PTD_tpCondRet PtdCondRet = PTD_CondRetOK;

	BAR_tppCarta pCartaMaior;
	BAR_tppCarta pCarta2;

	pCartaMaior = (BAR_tppCarta)malloc(sizeof(BAR_tpCarta));
	pCarta2 = (BAR_tppCarta)malloc(sizeof(BAR_tpCarta));

	if (pCartaMaior == NULL || pCarta2 == NULL)
	{
		return FALSE;
	}

	//Carta mais fraca
	pCartaMaior->numero = pOrdem->OrdemValor[0];
	pCartaMaior->naipe = Ouros;

	i = 0;

	PTD_IrInicioMesa(pMesa);
	while (PtdCondRet != PTD_CondRetUltimaCartaMesa)
	{			
		pCarta2 = PTD_ObterCartaMesa(pMesa);
		comp = PTD_ComparaCartas(pCartaMaior, pCarta2, pOrdem);
		//Função Compara cartas retorna o numero da maior, 1 ou 2		
		if (comp == 2)
		{
			id = i;
			pCartaMaior = pCarta2;
		}
		PtdCondRet = PTD_AvancarCartaMesa(pMesa, 1);
		i++;
	}

	if (id % 2 == 0) 
	{
		return EQUIPE_A;
	}
	else
	{
		return EQUIPE_B;
	}

}/* Fim função: PTD  &Computa Vencedor Mao */

 /***************************************************************************
 *
 *  Função: PTD  &Remover Carta Mesa Corrente
 *  ****/
PTD_tpCondRet PTD_RemoverCartaMesaCorrente(PTD_tppMesa pMesa)
{
	BAR_tpCondRet BarCondRet;
	BarCondRet = BAR_RemoverCartaCorrente(pMesa);

	if (BarCondRet != BAR_CondRetOK) 
	{
		return PTD_CondRetErroBaralho;
	}

	return PTD_CondRetOK;

}/* Fim função: PTD  &Remover Carta Mesa Corrente */

 /***************************************************************************
 *
 *  Função: PTD  &Jogar Carta Mesa
 *  ****/

PTD_tpCondRet PTD_JogarCartaMesa(PTD_tppMesa pMesa, PTD_tppJogadores pJogadores, int PosicaoCarta) 
{
	//PosicaoCarta é a posição da carta que o jogador deseja jogar
	BAR_tppCarta pCarta;
	PTD_tpCondRet CondRet;
	PTD_tppDadosJogador pDados;

	pDados = PTD_ObterDadosJogador(pJogadores);
	int id;
	id = pDados->Id;

	pCarta = PTD_ObterCartaMao(pJogadores, pDados, PosicaoCarta);

	if (pCarta == NULL)
	{
		return PTD_CondRetMaoVazia;
	}

	CondRet = PTD_InserirCartaMesa(pMesa, pCarta);

	if (CondRet != PTD_CondRetOK)
	{
		return CondRet;
	}

	CondRet = PTD_ExcluirCartaMao(pJogadores, pDados, PosicaoCarta);

	return CondRet;

	//
	//
	//								ATENÇÃO
	//		NA IMPLEMENTAÇÃO, A MESA DEVERA SER ESVAZIADA E/OU DESTRUIDA A CADA RODADA E A CADA MAO
	//

}/* Fim função: PTD  &Jogar Carta Mesa */



 /***************************************************************************
 *
 *  Função: PTD  &Obter Equipe Corrente
 *  ****/

int PTD_ObterEquipeCorrente(PTD_tppJogadores pJogadores)
{
	PTD_tppDadosJogador pDados;

	pDados = PTD_ObterDadosJogador(pJogadores);

	return pDados->Equipe;
}/* Fim função: PTD  &Obter Equipe Corrente */

 /***************************************************************************
 *
 *  Função: PTD  &Mao De Onze
 *  ****/

void PTD_MaoDeOnze(PTD_tppJogadores pJogadores, int Equipe)
{
	PTD_tpCondRet PtdCondRet = PTD_CondRetOK;

	PTD_IrPrimeiroJogador(pJogadores);

	if (Equipe == EQUIPE_A)
	{
		printf("\n Equipe A veja as cartas de seus integrantes\n");
	}
	else 
	{
		printf("\n Equipe B veja as cartas de seus integrantes\n");
		PtdCondRet = PTD_AvancarJogador(pJogadores, 1);		
	}	

	while (PtdCondRet != PTD_CondRetUltimoJogador)
	{	
		if (PtdCondRet == PTD_CondRetOK)
		{
			PTD_ImprimeMao(pJogadores);
		}

		PtdCondRet = PTD_AvancarJogador(pJogadores, 2);
	}

}/* Fim função: PTD  &Mao de Onze */


 /***************************************************************************
 *
 *  Função: PTD  &Menu Aumentar Partida
 *  ****/

int PTD_MenuAumentarPontos(void)
{
	int opcao = -1;
	while ( 1 ) 
	{
		printf("\n\t Menu:\n \n Escolha uma opcao:\n");
		printf("\n Digite 1 para pedir truco:");
		printf("\n Digite 2 para pedir retruco:");
		printf("\n Digite 99 para continuar sem aumentar a partida:");
		scanf("%d", &opcao);
		if ((opcao == 1) || (opcao == 2) || (opcao == 99)) 
		{
			break;
		}
		else
		{
			printf("\n Opcao errada! Tente novamente! \n");
		}
	}
	return opcao;
}/* Fim função: PTD  &Menu Aumentar Pontos */

 /***************************************************************************
 *
 *  Função: PTD  &Print Ordem
 *  ****/

void PTD_PrintOrdem(PTD_tppOrdenacao pOrdem) 
{
	int i, a;
	printf("\n\nDa menor para a maior\n");
	printf("Ordem de forca: \n");
	for (i = 0;i<10;i++) 
	{
		a = pOrdem->OrdemValor[i];
		printf("%d; ", a);
	}
	printf("\n\n Ordem Naipe:\n");
	printf("\n Ouros; Espadas; Copas; Paus\n");

}/* Fim função: PTD  &Imprime Ordem da forca das cartas */

 /***************************************************************************
 *
 *  Função: PTD  &Imprime carta
 *  ****/

void PTD_PrintCarta(BAR_tppCarta carta)
{
	if (carta->naipe != Coringa)
	{
		printf(" _________\n|         |\n|         |\n|%d %c|\n|         |\n|_________|\n", carta->numero, carta->naipe + 3);
	}
	else
	{
		printf(" _________\n|         |\n|         |\n|%d %c|\n|         |\n|_________|\n", carta->numero, carta->naipe - 2);
	}
}/* Fim função: PTD  &Imprime carta */

 /***************************************************************************
 *
 *  Função: PTD  &Imprime jogador
 *  ****/

void PTD_PrintCartaMesa(PTD_tppMesa pMesa, int Virada) 
{
	BAR_tppCarta pCarta;

	pCarta = (BAR_tppCarta)malloc(sizeof(BAR_tpCarta));

	pCarta = PTD_ObterCartaMesa(pMesa);

	if (pCarta == NULL)
	{
		return;
	}

	if (Virada == TRUE)
	{
		PTD_PrintCartaVirada();
	}
	else 
	{
		PTD_PrintCarta(pCarta);
	}

}/* Fim função: PTD  &Imprime jogador */
 /***************************************************************************
 *
 *  Função: PTD  &Imprime jogador
 *  ****/

void PTD_PrintJogador(PTD_tppJogadores pJogadores, int PontosEquipe)
{
	PTD_tppDadosJogador pDados;
	pDados = PTD_ObterDadosJogador(pJogadores);
	printf("::::::Jogador::::::\nNome: %s\nEquipe: %d\nId: %d\nPontos: %d\n", pDados->Nome, pDados->Equipe, pDados->Id, PontosEquipe);
	PTD_ImprimeMao(pJogadores);
}/* Fim função: PTD  &Imprime jogador */

 /***************************************************************************
 *
 *  Função: PTD  &Imprime mao
 *  ****/

void PTD_ImprimeMao(PTD_tppJogadores pJogadores)
{
	BAR_tpCondRet CondRet = BAR_CondRetOK;
	BAR_tppCarta carta;
	carta = (BAR_tppCarta)malloc(sizeof(BAR_tpCarta));
	PTD_tppDadosJogador pDados;

	pDados = PTD_ObterDadosJogador(pJogadores);

	BAR_IrInicioBaralho(pDados->Mao);

	printf("Mao:\n");

	while (CondRet == BAR_CondRetOK)
	{
		carta = BAR_ObterCarta(pDados->Mao);

		if (carta == NULL)
		{
			return;
		}

		PTD_PrintCarta(carta);
		CondRet = BAR_AvancarCarta(pDados->Mao, 1);
	}
}/* Fim função: PTD  &Imprime MAO */

 /***************************************************************************
 *
 *  Função: PTD  &Imprime Carta virada
 *  ****/

void PTD_PrintCartaVirada(void) 
{
	printf(" _________\n|         |\n|  CARTA  |\n|  VIRADA |\n|         |\n|_________|\n");
}

/***************************************************************************
*
*  Função: PTD  &Menu Aumentar Partida
*  ****/

void PTD_IniciaPartida(void)
{

	//Condições de retorno
	BAR_tpCondRet BarCondRet;
	PTD_tpCondRet PtdCondRet;
	EMB_tpCondRet EmbCondRet;

	//Variaveis
	int numJogadores = 0;
	int Rodada, i;
	int PontuacaoPartida[2][2];
	int PosicaoCarta = -1;
	int Opcao, verificador;
	int Equipe, VencedorRodada;
	//Cada linha é um equipe e a coluna corresponde aos valores da equipe e a pontucação global

	int MaoOnzeFerro;
	//Verifica se a mão de onze ou de ferro foi atingida

	int ChecaTruco;
	//Consta a equipe que pediu truco

	int ValorPartida;
	//Pontuação corrente


	//Baralho
	BAR_tppBaralho pBaralho;
	pBaralho = BAR_CriarBaralho();

	//Lista
	LIS_tppLista pLista;

	//Vira
	BAR_tppCarta pCartaVira;

	//Carta corrente na mesa
	BAR_tppCarta pCartaCorrente;

	//Dados do jogador
	PTD_tppDadosJogador pDados;

	pDados = (PTD_tppDadosJogador)malloc(sizeof(PTD_tpDadosJogador));
	pDados->Mao = BAR_CriarBaralho();

	//Tipo de ordem das cartas
	PTD_tppOrdenacao pOrdem;
	//Gera Ordem primordial de força
	pOrdem = PTD_OrdemPrimordial();

	// Mesa
	PTD_tppMesa pMesa;
	pMesa = PTD_CriarMesa();

	//Jogadores
	PTD_tppJogadores pJogadores;
	pJogadores = PTD_CriarJogadoresLista();

	//Inicializa Variaveis de controle;	
	//1° e 2° elementos da 1° coluna da matriz são as equipes
	PontuacaoPartida[0][0] = EQUIPE_A;
	PontuacaoPartida[1][0] = EQUIPE_B;

	//1° e 2° elementos da 2° coluna da matriz são os pontos das equipes
	PontuacaoPartida[0][1] = 0;
	PontuacaoPartida[1][1] = 0;


	//Definir quantidade de jogadores
	while (numJogadores == 0)
	{

		printf("\n\nBem vindo ao Jogo de Truco\n\n");
		printf("\n Digite o numero total de jogadores a serem divididos em duas equipes \n");
		printf(" (Atencao os numeros so podem ser: 2, 4 ou 6 participantes)\n\n\t");
		scanf("%d", &numJogadores);

		if ((numJogadores % 2 != 0) || (numJogadores > 6) || (numJogadores < 2))
		{
			numJogadores = 0;
			system("cls");
			printf("\n\n ERRO! Valor invalido, tente novamente\n\n\n\n");
			system("pause");
			system("cls");
		}
	}
	//Armazena os dados dos jogadores
	printf("\n\nAgora cada jogador ira digitar seus dados, atencao:\n\n");

	for (i = 0;i < numJogadores;i++) 
	{
		printf("\nJogador numero 0%d\n", i + 1);
		printf("\n Digite seu nome \n\n");

		scanf("%s", pDados->Nome);

		// Jogadores de números pares são da equipe A, ímpares da equipe B
		if ((i % 2) == 0)
		{
			printf("\n\tVoce sera da equipe A\n\n");

			pDados->Equipe = EQUIPE_A;
		}
		else {
			printf("\n\n\tVoce sera da equipe B\n\n");
			pDados->Equipe = EQUIPE_B;
		}

		printf("\nSeu numero identificado eh: %d\n\n\n", i + 1);
		pDados->Id = i + 1;

		//pDados = PTD_CriaDadosJogador(pDados->Nome, pDados->Equipe, i+1);

		PtdCondRet = PTD_InserirJogador(pDados, pJogadores);

		if (PtdCondRet != PTD_CondRetOK)
		{
			printf("\nERRO na insercao do jogador\n");
			printf("Tente novamente do inicio");
			i--;
		}
	}

	/*Inicio do jogo:*/

	MaoOnzeFerro = 0;

	//O jogo termina quando a pontuação de alguma equipe atingir 12	
	while ((PontuacaoPartida[0][1] < 12) && (PontuacaoPartida[1][1] < 12))
	{


		BarCondRet = BAR_CriarBaralhoTruco(pBaralho);
		if (BarCondRet != BAR_CondRetOK) 
		{
			printf("\n Erro na criacao do baralho - erro %d! \n", BarCondRet);
			exit(1);
		}

		EmbCondRet = EMB_Embaralhar(pBaralho); //Embaralhamento

		if (EmbCondRet != EMB_CondRetOK)
		{
			printf("\n Erro no embaralhamento - erro %d! \n", EmbCondRet);
			exit(1);
		}

		//Ponto de Inicio da mao

		//Determinação do vira
		pCartaVira = BAR_ObterCarta(pBaralho);

		printf("\n\n\n");
		printf("\n\n\tAtencao jogadores, essa e a carta vira\n\n");
		PTD_PrintCarta(pCartaVira);
		printf("\n");
		system("pause");

		//Remove do Baralho a carta que foi obtida
		BarCondRet = BAR_RemoverCartaCorrente(pBaralho);

		if (BarCondRet != BAR_CondRetOK) 
		{
			printf("\nErro na remocao de cartas - erro %d\n", BarCondRet);
		}

		//Determina a sequencia de forca com a manilha
		PTD_DeterminaManilha(pOrdem, pCartaVira);

		PTD_PrintOrdem(pOrdem);

		//Gera as Maos de todos os jogadores da partida
		PtdCondRet = PTD_GeraMaos(pBaralho, pJogadores);

		if (PtdCondRet != PTD_CondRetOK) 
		{
			printf("Erro na criacao das maos dos jogadores");
			exit(1);
		}

		Rodada = 0;
		ChecaTruco = 0;
		ValorPartida = 1;

		//A mão reinicia após 3 rodadas
		while (Rodada < 3)
		{ //Inicio while 1.0
			i = 0;
			PTD_IrPrimeiroJogador(pJogadores);
			printf("\nRodada numero %d\n", Rodada + 1);
			//Jogar Carta		
			while (i < numJogadores)
			{ //Inicio while 2.0

									 //Condição da mão de FERRO
				if ((PontuacaoPartida[0][1] == 11) && (PontuacaoPartida[1][1] == 11))
				{
					system("cls");
					printf("\n Atencao!!!\n");
					printf("\n Mao de Ferro atingida ");
					ValorPartida = 1;
					MaoOnzeFerro = PTD_MAOFERRO;
				}
				else
				{
					//Condição da mão de onze
					if ((PontuacaoPartida[0][1] == 11) || (PontuacaoPartida[1][1] == 11))
					{
						system("cls");
						printf("\n Atencao!!!\n");
						printf("\n Mao de onze atingida ");

						if (PontuacaoPartida[0][1] == 11)
						{
							printf("Pela Equipe A\n");
							PTD_MaoDeOnze(pJogadores, EQUIPE_A);
						}

						else
						{
							printf("Pela Equipe B\n");
							PTD_MaoDeOnze(pJogadores, EQUIPE_B);
						}
						ValorPartida = 3;
						MaoOnzeFerro = PTD_MAOONZE;
					}
				}

				system("cls");
				if (i != numJogadores)
				{
					printf("\n\n\tProximo Jogador\n");
				}
				system("pause");

				printf("\n Jogador %d\n\n", i + 1);

				Equipe = PTD_ObterEquipeCorrente(pJogadores);

				//Imprime os dados do jogador e sua mão e pontuação da equipe
				PTD_PrintJogador(pJogadores, PontuacaoPartida[Equipe - 101][1]);

				verificador = PTD_PARA;
				Opcao = 0;
				if ((ValorPartida == 3) && (MaoOnzeFerro == 0))
				{
					//Validação da dinamica de truco

					while (verificador == PTD_PARA)
					{
						printf("\n A equipe adversaria pediu truco.\n");
						printf("\n Digite: \n 1 - Para coontinuar\n 2 - Para fugir.");
						scanf("%d", &Opcao);

						if ((Opcao != 1) && (Opcao != 2))
						{
							printf("\nValor invalido, tente novamente\n");
						}
						else verificador = PTD_AVANCA;
					}


					if (Opcao == 2)
					{
						//Caso em que os aversários fogem do truco

						if (Equipe == EQUIPE_B)
						{
							PontuacaoPartida[0][1] = 1;
						}
						else
						{
							PontuacaoPartida[1][1] = 1;
						}
						verificador = PTD_FUGIU;
						//Valor que indica que a dupla fugiu	
					}

					else
					{
						//Caso em que os aversários aceitam o truco
						verificador = PTD_PARA;

						while (verificador == PTD_PARA)
						{

							if (MaoOnzeFerro != PTD_MAOFERRO)
							{
								//Na mão de Ferro não pode pedir Truco

								Opcao = PTD_MenuAumentarPontos();

								switch (Opcao)
								{
								case 1:
								{
									if ((ChecaTruco != 0) || (MaoOnzeFerro != 0))
									{
										printf("Nao pode pedir truco no momento");
										verificador = PTD_PARA;
									}
									else
									{
										ChecaTruco = Equipe;
										ValorPartida = 3;
										verificador = PTD_AVANCA;
									}
									break;
								}
								case 2:
								{
									if ((ChecaTruco == Equipe) || (ValorPartida > 12))
									{
										printf("Nao pode aumentar o valor da partida no momento");
										verificador = PTD_PARA;
									}
									else
									{
										ChecaTruco = Equipe;
										ValorPartida = ValorPartida + 3;
										verificador = PTD_AVANCA;
									}
									break;
								}
								default:
								{
									ValorPartida = 1;
									verificador = PTD_AVANCA;
									break;
								}
								}
							}

							else
							{
								verificador = PTD_AVANCA;
							}
						}
					}
				}

				PosicaoCarta = -1;
				printf("\n\nEscolha a posicao da carta que deseja jogar: 1, 2 ou 3 \n");

				while (PosicaoCarta == -1)
				{
					scanf("%d", &PosicaoCarta);

					if ((PosicaoCarta != 1) && (PosicaoCarta != 2) && (PosicaoCarta != 3))
					{
						printf("\n Erro! \n\nPosicao incorreta, digite um valor valido. \n");
						PosicaoCarta = -1;
					}
				}

				PtdCondRet = PTD_JogarCartaMesa(pMesa, pJogadores, PosicaoCarta);

				//Caso em que foi atingida a mão de ferro
				if (MaoOnzeFerro == PTD_MAOFERRO)
				{
					PTD_PrintCartaMesa(pMesa, TRUE);
				}
				else
				{
					verificador = PTD_PARA;
					printf("\nDeseja imprimir a carta virada ou desvirada?\n");
					printf("\tDigite 1 para virada e 2 para desvirada\n");

					while (verificador == PTD_PARA)
					{
						scanf("%d", &Opcao);

						if ((Opcao != 1) && (Opcao != 2))
						{
							printf("\nValor invalido, tente novamente\n");
						}

						else verificador = PTD_AVANCA;

					}

					if (Opcao == 1)
					{
						PTD_PrintCartaMesa(pMesa, TRUE);
					}
					else PTD_PrintCartaMesa(pMesa, FALSE);

				}


				if (PtdCondRet != PTD_CondRetOK)
				{
					printf("\nErro ao tentar inserir uma carta na mesa\n");
					exit(1);
				}
			}
			PtdCondRet = PTD_AvancarJogador(pJogadores, 1);

			if (PtdCondRet != PTD_CondRetOK)
			{
				printf("Erro ao tentar avancar um jogador");
			}
			i++;

		}//fim while 2.0

		if (verificador != PTD_FUGIU) 
		{
			VencedorRodada = PTD_ComputaVencedorRodada(pMesa, pOrdem);

			if (VencedorRodada == EQUIPE_A)
			{
				PontuacaoPartida[0][1] = ValorPartida;
			}

			else {
				PontuacaoPartida[1][1] = ValorPartida;
			}
		}

		Rodada++;
		PTD_DestruirMesa(pMesa);
	} //Fim while 1.0	

		  //BAR_DestruirBaralho() <--------------------
	PTD_DestruirMesa(pBaralho);



	printf("\nParabens a equipe vencedora!\n");
	if (VencedorRodada == EQUIPE_A)
	{
		printf("\nParabens Equipe A");
	}
	else
	{
		printf("\nParabens Equipe B");
	}

	system("pause");
}