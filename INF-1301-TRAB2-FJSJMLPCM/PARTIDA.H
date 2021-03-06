
/***************************************************************************
*
*  $MCD M�dulo de defini��o: PTD  Partida
*
*  Arquivo gerado:              Partida.h
*  Letras identificadoras:      PTD
*
*  Projeto: INF 1301 / 1628 Implementa��o do jogo de Truco Paulista em C
*  Gestor:  LES/DI/PUC-Rio
*  Autores: FJS Francisco J. Evangelista de Sousa
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*     1       FJS   28/mai/2018 in�cio desenvolvimento
*
*  $ED Descri��o do m�dulo
*		Implementa o cenario de uma partida de truco.
*		Primeiro cria-se os recursos para cria��o dos perfis de jogadores.
*		Cada jogador possu� campo para nome e pontua��o.
*		Cria-se listas para armazenar os valores de cada partida.
*		O jogo � feito at� alguma equipe atingir 12 pontos.
*		Implementa-se um menu com a pontua��o corrente de cada jogador.
*		Cada jogador deve jogar na sua vez.
*
*
*
*
* COLOCAR MAIS DESCRI��O OOOOOOOOOOOOOOOOOOOOOOOOOOOO
*
*
*
*
*
*
***************************************************************************/


#include "LISTA.H"
#include "BARALHO.H"
#include "EMBARALHAR.H"


#define EQUIPE_A 101
#define EQUIPE_B 102

#define TRUE 100
#define FALSE -100



/***** Declara��es exportadas pelo m�dulo *****/

typedef LIS_tppLista PTD_tppJogadores;
/* Tipo refer�ncia para os jogadores */


typedef BAR_tppBaralho PTD_tppMesa;
/* Tipo refer�ncia para os jogadores */

/***********************************************************************
*
*  $TC Tipo de dados: PTD Condi��es de retorno
*
*
*  $ED Descri��o do tipo
*     Condi��es de retorno das fun��es da Partida
*
***********************************************************************/

/********Condi��es de retorno genericas**********/
typedef enum {

	PTD_CondRetOK,
	/* Concluiu corretamente */

	PTD_CondRetErroBaralho,
	/* Faltou mem�ria ao tentar criar uma o baralho ou o baralho vazio */

	/********Condi��es de retorno para Jogadores**********/

	PTD_CondRetSemJogadores,
	/* A partida n�o cont�m jogadores */

	PTD_CondRetFaltouMemoriaDadosJogador,
	/* Faltou mem�ria ao tentar criar uma jogador */

	PTD_CondRetFaltouMemoriaJogador,
	/* Faltou mem�ria ao tentar criar uma jogador */

	PTD_CondRetNaoAchouJogador,
	/* Faltou mem�ria ao tentar achar uma jogador */

	PTD_CondRetAumentarPartidaInvalida,
	/* Jogador n�o pode pedir truco */

	PTD_CondRetUltimoJogador,
	/* Est� no ultimo n� da lista de jogadores */

	PTD_CondRetMaoCheia,
	/*O Jogador n�o pode receber cartas */

	PTD_CondRetMaoVazia,
	/*O Jogador est� sem cartas */

	/********Condi��es de retorno para a Mesa**********/

	PTD_CondRetFaltouMemoriaMesa,
	/* Faltou mem�ria ao tentar criar a mesa */

	PTD_CondRetMesaVazia,
	/* A mesa n�o possui cartas */

	PTD_CondRetUltimaCartaMesa
	/* Est� no ultimo n� da lista da Mesa */

} PTD_tpCondRet;



/***********************************************************************
*
*  $TC Tipo de dados: PTD DadosJogador
*
*
*  $ED Descri��o do tipo
*     Dados de cada Jogador
*
***********************************************************************/
typedef struct TAG_DadosJogador
{
	char Nome[60];
	/*Nome do jogador*/

	BAR_tppBaralho Mao;
	/*cartas que cada jogador ter� em cada rodada*/

	int Equipe;
	/*Equipe a qual o jogador participa*/

	int Id;
	/*Identificador do jogador no jogo, n�mero no valor de 1 a 6*/

	int Pontos;
	/*Pontua��o do jogador*/

}PTD_tpDadosJogador;

typedef PTD_tpDadosJogador *  PTD_tppDadosJogador;
/* Tipo refer�ncia para os dados dos jogadores */

/***********************************************************************
*
*$TC Tipo de dados: PTD Ordenacao
*
*
*  $ED Descri��o do tipo
*     Contem a ordem de for�a das cartas;
*
***********************************************************************/

typedef struct Tag_Ordenacao
{
	BAR_tpNaipe OrdemNaipe[4];

	int OrdemValor[10];

}PTD_tpOrdenacao;

typedef PTD_tpOrdenacao * PTD_tppOrdenacao;

/***********************************************************************
*
*  $FC Fun��o: PTD  &Criar Dados Jogador
*
*  $ED Descri��o da fun��o
*		Cria um conjunto de dados do jogador com dados Default,
*		s� nome � preenchido.
*
*  $EP Par�metros
*		*nome	- ponteiro para a string que contem o nome do jogador
*		Equipe  - Equipe do jogador
*		ident  - Identificador do jogador
*
*  $FV Valor retornado
*		PTD_tppDadosJogador -Ponteiro para TAD dos dados do jogador
*
***********************************************************************/

PTD_tppDadosJogador PTD_CriaDadosJogador(char * nome, int Equipe, int ident);

/***********************************************************************
*
*  $FC Fun��o: PTD  &Remover Dado Jogador Corrente
*
*  $ED Descri��o da fun��o
*		Remove os dados do jogador corrente na lista.
*
*  $EP Par�metros
*		pJogadores - Lista com os jogadores apontando para o n� corrente.
*
*  $FV Valor retornado
*		PTD_CondRetOK - Os dados foram removidos com exito
*		PTD_CondRetSemJogadores - N�o h� jogadores na partida
*
***********************************************************************/

PTD_tpCondRet PTD_RemoverDadoJogadorCorrente(PTD_tppJogadores pjogadores);

/***********************************************************************
*
*  $FC Fun��o: PTD  &Excluir Dados Jogador
*
*  $ED Descri��o da fun��o
*		Fun��o a ser usada na cri��o da lista como ponteiro para remo��o
*		de um elemento
*
*  $EP Par�metros
*		pDados - TAD a ser removido.
*
*  $FV Valor retornado
*		Void
*
***********************************************************************/

void PTD_ExcluirDadosJogador(PTD_tppDadosJogador pDados);

/***********************************************************************
*
*  $FC Fun��o: PTD  &Ir Primeiro Jogador
*
*  $ED Descri��o da fun��o
*		Vai para o primeiro n� da lista de jogadores
*
*  $EP Par�metros
*		pJogadores - Lista com os jogadores da partida
*
*  $FV Valor retornado
*		void
*
***********************************************************************/

void PTD_IrPrimeiroJogador(PTD_tppJogadores pJogadores);

/***********************************************************************
*
*  $FC Fun��o: PTD  &Ir Ultimo Jogador
*
*  $ED Descri��o da fun��o
*		Vai para o ultimo n� da lista de jogadores
*
*  $EP Par�metros
*		pJogadores - Lista com os jogadores da partida
*
*  $FV Valor retornado
*		void
*
***********************************************************************/

void PTD_IrUltimoJogador(PTD_tppJogadores pJogadores);

/***********************************************************************
*
*  $FC Fun��o: PTD  & Criar Jogadores Lista
*
*  $ED Descri��o da fun��o
*		Cria a lista para alocar os jogadores
*
*  $EP Par�metros
*		void
*
*  $FV Valor retornado
*		Retorna o ponteiro para a lista criada
*
***********************************************************************/

PTD_tppJogadores PTD_CriarJogadoresLista(void);

/***********************************************************************
*
*  $FC Fun��o: PTD  &Obter Dados Jogador
*
*  $ED Descri��o da fun��o
*		Obtem os dados do jogador corrente da lista de jogadores
*
*  $EP Par�metros
*		pJogadores - Lista com os jogadores da partida
*
*  $FV Valor retornado
*		TAD com os dados do jogador corrente
*
***********************************************************************/

PTD_tppDadosJogador PTD_ObterDadosJogador(PTD_tppJogadores pJogadores);

/***********************************************************************
*
*  $FC Fun��o: PTD  &Inserir Jogador
*
*  $ED Descri��o da fun��o
*		Insere os dados de um jogador na lista
*
*  $EP Par�metros
*		pDados - TAD com os dados do jogador a ser inserido
*		pJogadores - Lista com os jogadores da partida
*
*  $FV Valor retornado
*		PTD_CondRetFaltouMemoriaDadosJogador - n�o h� memoria disponivel
*		PTD_CondRetOK - Inseriu com sucesso o jogador
*
***********************************************************************/

PTD_tpCondRet PTD_InserirJogador(PTD_tppDadosJogador pDados, PTD_tppJogadores pJogadores);

/***********************************************************************
*
*  $FC Fun��o: PTD  &Avancar Jogador
*
*  $ED Descri��o da fun��o
*		Avanca uma quantidade de posicao jogadores na lista
*
*  $EP Par�metros
*		pjogadores - Lista com os jogadores da partida
*		numJogadores - numero de jogadores do jogo
*
*  $FV Valor retornado
*		PTD_CondRetUltimoJogador - atingiu o ultimo jogador
*		PTD_CondRetSemJogadores - N�o jogadores na partida
*		PTD_CondRetOK - Avancou com sucesso
*
***********************************************************************/

PTD_tpCondRet PTD_AvancarJogador(PTD_tppJogadores pjogadores, int numAvanco);

/***********************************************************************
*
*  $FC Fun��o: PTD  & Procurar Jogador
*
*  $ED Descri��o da fun��o
*		Verifica se o jogador se encontra na lista
*
*  $EP Par�metros
*		pjogadores - Ponteiro para a lista de jogadores
*		pDados - TAD com os dados do jogador procurado
*
*  $FV Valor retornado
*		PTD_CondRetNaoAchouJogador - N�o foi encontrado
*		PTD_CondRetSemJogadores - N�o h� jogadores na partida
*		PTD_CondRetOK - Jogador encontrado na lista
*
***********************************************************************/

PTD_tpCondRet PTD_ProcurarJogador(PTD_tppJogadores pjogadores, PTD_tppDadosJogador pDados);

/***********************************************************************
*
*  $FC Fun��o: PTD  & Atualiza Dados
*
*  $ED Descri��o da fun��o
*		Verifica se o jogador se encontra na lista
*
*  $EP Par�metros
*		pjogadores - Ponteiro para a lista de jogadores
*		pDadosVelhos - TAD com os dados originais do jogador
*		pDadosNovos - TAD com os dados que ser�o atualizados
*
*  $FV Valor retornado
*		PTD_CondRetNaoAchouJogador - N�o foi encontrado
*		PTD_CondRetSemJogadores - N�o h� jogadores na partida
*		PTD_CondRetOK - Jogador encontrado na lista
*
***********************************************************************/

PTD_tpCondRet PTD_AtualizaDados(PTD_tppJogadores pJogadores, PTD_tppDadosJogador pDadosVelhos, PTD_tppDadosJogador pDadosNovos);

/***********************************************************************
*
*  $FC Fun��o: PTD  &Gera Maos
*
*  $ED Descri��o da fun��o
*		Forma as maos dos jogadores com as tres cartas, sacadas do baralho
*
*  $EP Par�metros
*		pBaralho - Baralho com as cartas do jogo
*		pJogadores - Ponteiro para a lista de jogadores
*
*  $FV Valor retornado
*
*
***********************************************************************/

PTD_tpCondRet PTD_GeraMaos(BAR_tppBaralho pBaralho, PTD_tppJogadores pJogadores);

/***********************************************************************
*
*  $FC Fun��o: PTD  &
*
*  $ED Descri��o da fun��o
*
*
*  $EP Par�metros
*
*
*  $FV Valor retornado
*
*
***********************************************************************/

void PTD_DestruirMao(PTD_tppJogadores pJogadores);

/***********************************************************************
*
*  $FC Fun��o: PTD  &
*
*  $ED Descri��o da fun��o
*
*
*  $EP Par�metros
*
*
*  $FV Valor retornado
*
*
***********************************************************************/

PTD_tpCondRet PTD_ExcluirCartaMao(PTD_tppJogadores pJogadores, PTD_tppDadosJogador pDados, int PosicaoCarta);

/***********************************************************************
*
*  $FC Fun��o: PTD  &
*
*  $ED Descri��o da fun��o
*
*
*  $EP Par�metros
*
*
*  $FV Valor retornado
*
*
***********************************************************************/

BAR_tppCarta PTD_ObterCartaMao(PTD_tppJogadores pJogadores, PTD_tppDadosJogador pDados, int PosicaoCarta);

/**************************************************************************
*
*							Fun��es para manipula��o da Mesa
*
***************************************************************************/

/***********************************************************************
*
*  $FC Fun��o: PTD  &
*
*  $ED Descri��o da fun��o
*
*
*  $EP Par�metros
*
*
*  $FV Valor retornado
*
*
***********************************************************************/

PTD_tppMesa PTD_CriarMesa(void);

/***********************************************************************
*
*  $FC Fun��o: PTD  &
*
*  $ED Descri��o da fun��o
*
*
*  $EP Par�metros
*
*
*  $FV Valor retornado
*
*
***********************************************************************/

void PTD_EsvaziarMesa(PTD_tppMesa pMesa);

/***********************************************************************
*
*  $FC Fun��o: PTD  &
*
*  $ED Descri��o da fun��o
*
*
*  $EP Par�metros
*
*
*  $FV Valor retornado
*
*
***********************************************************************/

void PTD_DestruirMesa(PTD_tppMesa pMesa);

/***********************************************************************
*
*  $FC Fun��o: PTD  &
*
*  $ED Descri��o da fun��o
*
*
*  $EP Par�metros
*
*
*  $FV Valor retornado
*
*
***********************************************************************/

void PTD_IrInicioMesa(PTD_tppMesa pMesa);

/***********************************************************************
*
*  $FC Fun��o: PTD  &
*
*  $ED Descri��o da fun��o
*
*
*  $EP Par�metros
*
*
*  $FV Valor retornado
*
*
***********************************************************************/

BAR_tppCarta PTD_ObterCartaMesa(PTD_tppMesa pMesa);

/***********************************************************************
*
*  $FC Fun��o: PTD  &
*
*  $ED Descri��o da fun��o
*
*
*  $EP Par�metros
*
*
*  $FV Valor retornado
*
*
***********************************************************************/

PTD_tpCondRet PTD_InserirCartaMesa(PTD_tppMesa pMesa, BAR_tppCarta pCarta);

/***********************************************************************
*
*  $FC Fun��o: PTD  &
*
*  $ED Descri��o da fun��o
*
*
*  $EP Par�metros
*
*
*  $FV Valor retornado
*
*
***********************************************************************/

PTD_tpCondRet PTD_AvancarCartaMesa(PTD_tppMesa pMesa, int numCarta);

/***********************************************************************
*
*  $FC Fun��o: PTD  &
*
*  $ED Descri��o da fun��o
*
*
*  $EP Par�metros
*
*
*  $FV Valor retornado
*
*
***********************************************************************/

PTD_tppOrdenacao PTD_OrdemPrimordial(void);

/***********************************************************************
*
*  $FC Fun��o: PTD  &
*
*  $ED Descri��o da fun��o
*
*
*  $EP Par�metros
*
*
*  $FV Valor retornado
*
*
***********************************************************************/

void PTD_DeterminaManilha(PTD_tppOrdenacao pOrdem, BAR_tppCarta pCartaVira);

/***********************************************************************
*
*  $FC Fun��o: PTD  &
*
*  $ED Descri��o da fun��o
*
*
*  $EP Par�metros
*
*
*  $FV Valor retornado
*
*
***********************************************************************/

int PTD_ComparaCartas(BAR_tppCarta pCarta1, BAR_tppCarta pCarta2, PTD_tppOrdenacao pOrdem);

/***********************************************************************
*
*  $FC Fun��o: PTD  &
*
*  $ED Descri��o da fun��o
*
*
*  $EP Par�metros
*
*
*  $FV Valor retornado
*
*
***********************************************************************/

int PTD_ComputaVencedorRodada(PTD_tppMesa pMesa, PTD_tppOrdenacao pOrdem);

/***********************************************************************
*
*  $FC Fun��o: PTD  &
*
*  $ED Descri��o da fun��o
*
*
*  $EP Par�metros
*
*
*  $FV Valor retornado
*
*
***********************************************************************/

PTD_tpCondRet PTD_RemoverCartaMesaCorrente(PTD_tppMesa pMesa);

/***********************************************************************
*
*  $FC Fun��o: PTD  &
*
*  $ED Descri��o da fun��o
*
*
*  $EP Par�metros
*
*
*  $FV Valor retornado
*
*
***********************************************************************/

PTD_tpCondRet PTD_JogarCartaMesa(PTD_tppMesa pMesa, PTD_tppJogadores pJogadores, int PosicaoCarta);

/***********************************************************************
*
*  $FC Fun��o: PTD  &
*
*  $ED Descri��o da fun��o
*
*
*  $EP Par�metros
*
*
*  $FV Valor retornado
*
*
***********************************************************************/

int PTD_ObterEquipeCorrente(PTD_tppJogadores pJogadores);

/***********************************************************************
*
*  $FC Fun��o: PTD  &
*
*  $ED Descri��o da fun��o
*
*
*  $EP Par�metros
*
*
*  $FV Valor retornado
*
*
***********************************************************************/

int PTD_MenuAumentarPontos(void);

/***********************************************************************
*
*  $FC Fun��o: PTD  &
*
*  $ED Descri��o da fun��o
*
*
*  $EP Par�metros
*
*
*  $FV Valor retornado
*
*
***********************************************************************/

void PTD_PrintOrdem(PTD_tppOrdenacao pOrdem);

/***********************************************************************
*
*  $FC Fun��o: PTD  &
*
*  $ED Descri��o da fun��o
*
*
*  $EP Par�metros
*
*
*  $FV Valor retornado
*
*
***********************************************************************/

void PTD_MaoDeOnze(PTD_tppJogadores pJogadores, int Equipe);

/***********************************************************************
*
*  $FC Fun��o: PTD  &
*
*  $ED Descri��o da fun��o
*
*
*  $EP Par�metros
*
*
*  $FV Valor retornado
*
*
***********************************************************************/

void PTD_PrintCarta(BAR_tppCarta carta);

/***********************************************************************
*
*  $FC Fun��o: PTD  &
*
*  $ED Descri��o da fun��o
*
*
*  $EP Par�metros
*
*
*  $FV Valor retornado
*
*
***********************************************************************/

void PTD_PrintCartaMesa(PTD_tppMesa pMesa, int Virada);

/***********************************************************************
*
*  $FC Fun��o: PTD  &
*
*  $ED Descri��o da fun��o
*
*
*  $EP Par�metros
*
*
*  $FV Valor retornado
*
*
***********************************************************************/

void PTD_PrintJogador(PTD_tppJogadores jogador,int PontosEquipe);

/***********************************************************************
*
*  $FC Fun��o: PTD  &
*
*  $ED Descri��o da fun��o
*
*
*  $EP Par�metros
*
*
*  $FV Valor retornado
*
*
***********************************************************************/

void PTD_ImprimeMao(PTD_tppJogadores pJogadores);

/***********************************************************************
*
*  $FC Fun��o: PTD  &
*
*  $ED Descri��o da fun��o
*
*
*  $EP Par�metros
*
*
*  $FV Valor retornado
*
*
***********************************************************************/

void PTD_PrintCartaVirada(void);

/***********************************************************************
*
*  $FC Fun��o: PTD  &
*
*  $ED Descri��o da fun��o
*
*
*  $EP Par�metros
*
*
*  $FV Valor retornado
*
*
***********************************************************************/

void PTD_IniciaPartida(void);
