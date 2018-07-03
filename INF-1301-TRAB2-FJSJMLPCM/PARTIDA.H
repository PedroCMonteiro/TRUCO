
/***************************************************************************
*
*  $MCD Módulo de definição: PTD  Partida
*
*  Arquivo gerado:              Partida.h
*  Letras identificadoras:      PTD
*
*  Projeto: INF 1301 / 1628 Implementação do jogo de Truco Paulista em C
*  Gestor:  LES/DI/PUC-Rio
*  Autores: FJS Francisco J. Evangelista de Sousa
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*     1       FJS   28/mai/2018 início desenvolvimento
*
*  $ED Descrição do módulo
*		Implementa o cenario de uma partida de truco.
*		Primeiro cria-se os recursos para criação dos perfis de jogadores.
*		Cada jogador possuí campo para nome e pontuação.
*		Cria-se listas para armazenar os valores de cada partida.
*		O jogo é feito até alguma equipe atingir 12 pontos.
*		Implementa-se um menu com a pontuação corrente de cada jogador.
*		Cada jogador deve jogar na sua vez.
*
*
*
*
* COLOCAR MAIS DESCRIÇÃO OOOOOOOOOOOOOOOOOOOOOOOOOOOO
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



/***** Declarações exportadas pelo módulo *****/

typedef LIS_tppLista PTD_tppJogadores;
/* Tipo referência para os jogadores */


typedef BAR_tppBaralho PTD_tppMesa;
/* Tipo referência para os jogadores */

/***********************************************************************
*
*  $TC Tipo de dados: PTD Condições de retorno
*
*
*  $ED Descrição do tipo
*     Condições de retorno das funções da Partida
*
***********************************************************************/

/********Condições de retorno genericas**********/
typedef enum {

	PTD_CondRetOK,
	/* Concluiu corretamente */

	PTD_CondRetErroBaralho,
	/* Faltou memória ao tentar criar uma o baralho ou o baralho vazio */

	/********Condições de retorno para Jogadores**********/

	PTD_CondRetSemJogadores,
	/* A partida não contém jogadores */

	PTD_CondRetFaltouMemoriaDadosJogador,
	/* Faltou memória ao tentar criar uma jogador */

	PTD_CondRetFaltouMemoriaJogador,
	/* Faltou memória ao tentar criar uma jogador */

	PTD_CondRetNaoAchouJogador,
	/* Faltou memória ao tentar achar uma jogador */

	PTD_CondRetAumentarPartidaInvalida,
	/* Jogador não pode pedir truco */

	PTD_CondRetUltimoJogador,
	/* Está no ultimo nó da lista de jogadores */

	PTD_CondRetMaoCheia,
	/*O Jogador não pode receber cartas */

	PTD_CondRetMaoVazia,
	/*O Jogador está sem cartas */

	/********Condições de retorno para a Mesa**********/

	PTD_CondRetFaltouMemoriaMesa,
	/* Faltou memória ao tentar criar a mesa */

	PTD_CondRetMesaVazia,
	/* A mesa não possui cartas */

	PTD_CondRetUltimaCartaMesa
	/* Está no ultimo nó da lista da Mesa */

} PTD_tpCondRet;



/***********************************************************************
*
*  $TC Tipo de dados: PTD DadosJogador
*
*
*  $ED Descrição do tipo
*     Dados de cada Jogador
*
***********************************************************************/
typedef struct TAG_DadosJogador
{
	char Nome[60];
	/*Nome do jogador*/

	BAR_tppBaralho Mao;
	/*cartas que cada jogador terá em cada rodada*/

	int Equipe;
	/*Equipe a qual o jogador participa*/

	int Id;
	/*Identificador do jogador no jogo, número no valor de 1 a 6*/

	int Pontos;
	/*Pontuação do jogador*/

}PTD_tpDadosJogador;

typedef PTD_tpDadosJogador *  PTD_tppDadosJogador;
/* Tipo referência para os dados dos jogadores */

/***********************************************************************
*
*$TC Tipo de dados: PTD Ordenacao
*
*
*  $ED Descrição do tipo
*     Contem a ordem de força das cartas;
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
*  $FC Função: PTD  &Criar Dados Jogador
*
*  $ED Descrição da função
*		Cria um conjunto de dados do jogador com dados Default,
*		só nome é preenchido.
*
*  $EP Parâmetros
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
*  $FC Função: PTD  &Remover Dado Jogador Corrente
*
*  $ED Descrição da função
*		Remove os dados do jogador corrente na lista.
*
*  $EP Parâmetros
*		pJogadores - Lista com os jogadores apontando para o nó corrente.
*
*  $FV Valor retornado
*		PTD_CondRetOK - Os dados foram removidos com exito
*		PTD_CondRetSemJogadores - Não há jogadores na partida
*
***********************************************************************/

PTD_tpCondRet PTD_RemoverDadoJogadorCorrente(PTD_tppJogadores pjogadores);

/***********************************************************************
*
*  $FC Função: PTD  &Excluir Dados Jogador
*
*  $ED Descrição da função
*		Função a ser usada na crição da lista como ponteiro para remoção
*		de um elemento
*
*  $EP Parâmetros
*		pDados - TAD a ser removido.
*
*  $FV Valor retornado
*		Void
*
***********************************************************************/

void PTD_ExcluirDadosJogador(PTD_tppDadosJogador pDados);

/***********************************************************************
*
*  $FC Função: PTD  &Ir Primeiro Jogador
*
*  $ED Descrição da função
*		Vai para o primeiro nó da lista de jogadores
*
*  $EP Parâmetros
*		pJogadores - Lista com os jogadores da partida
*
*  $FV Valor retornado
*		void
*
***********************************************************************/

void PTD_IrPrimeiroJogador(PTD_tppJogadores pJogadores);

/***********************************************************************
*
*  $FC Função: PTD  &Ir Ultimo Jogador
*
*  $ED Descrição da função
*		Vai para o ultimo nó da lista de jogadores
*
*  $EP Parâmetros
*		pJogadores - Lista com os jogadores da partida
*
*  $FV Valor retornado
*		void
*
***********************************************************************/

void PTD_IrUltimoJogador(PTD_tppJogadores pJogadores);

/***********************************************************************
*
*  $FC Função: PTD  & Criar Jogadores Lista
*
*  $ED Descrição da função
*		Cria a lista para alocar os jogadores
*
*  $EP Parâmetros
*		void
*
*  $FV Valor retornado
*		Retorna o ponteiro para a lista criada
*
***********************************************************************/

PTD_tppJogadores PTD_CriarJogadoresLista(void);

/***********************************************************************
*
*  $FC Função: PTD  &Obter Dados Jogador
*
*  $ED Descrição da função
*		Obtem os dados do jogador corrente da lista de jogadores
*
*  $EP Parâmetros
*		pJogadores - Lista com os jogadores da partida
*
*  $FV Valor retornado
*		TAD com os dados do jogador corrente
*
***********************************************************************/

PTD_tppDadosJogador PTD_ObterDadosJogador(PTD_tppJogadores pJogadores);

/***********************************************************************
*
*  $FC Função: PTD  &Inserir Jogador
*
*  $ED Descrição da função
*		Insere os dados de um jogador na lista
*
*  $EP Parâmetros
*		pDados - TAD com os dados do jogador a ser inserido
*		pJogadores - Lista com os jogadores da partida
*
*  $FV Valor retornado
*		PTD_CondRetFaltouMemoriaDadosJogador - não há memoria disponivel
*		PTD_CondRetOK - Inseriu com sucesso o jogador
*
***********************************************************************/

PTD_tpCondRet PTD_InserirJogador(PTD_tppDadosJogador pDados, PTD_tppJogadores pJogadores);

/***********************************************************************
*
*  $FC Função: PTD  &Avancar Jogador
*
*  $ED Descrição da função
*		Avanca uma quantidade de posicao jogadores na lista
*
*  $EP Parâmetros
*		pjogadores - Lista com os jogadores da partida
*		numJogadores - numero de jogadores do jogo
*
*  $FV Valor retornado
*		PTD_CondRetUltimoJogador - atingiu o ultimo jogador
*		PTD_CondRetSemJogadores - Não jogadores na partida
*		PTD_CondRetOK - Avancou com sucesso
*
***********************************************************************/

PTD_tpCondRet PTD_AvancarJogador(PTD_tppJogadores pjogadores, int numAvanco);

/***********************************************************************
*
*  $FC Função: PTD  & Procurar Jogador
*
*  $ED Descrição da função
*		Verifica se o jogador se encontra na lista
*
*  $EP Parâmetros
*		pjogadores - Ponteiro para a lista de jogadores
*		pDados - TAD com os dados do jogador procurado
*
*  $FV Valor retornado
*		PTD_CondRetNaoAchouJogador - Não foi encontrado
*		PTD_CondRetSemJogadores - Não há jogadores na partida
*		PTD_CondRetOK - Jogador encontrado na lista
*
***********************************************************************/

PTD_tpCondRet PTD_ProcurarJogador(PTD_tppJogadores pjogadores, PTD_tppDadosJogador pDados);

/***********************************************************************
*
*  $FC Função: PTD  & Atualiza Dados
*
*  $ED Descrição da função
*		Verifica se o jogador se encontra na lista
*
*  $EP Parâmetros
*		pjogadores - Ponteiro para a lista de jogadores
*		pDadosVelhos - TAD com os dados originais do jogador
*		pDadosNovos - TAD com os dados que serão atualizados
*
*  $FV Valor retornado
*		PTD_CondRetNaoAchouJogador - Não foi encontrado
*		PTD_CondRetSemJogadores - Não há jogadores na partida
*		PTD_CondRetOK - Jogador encontrado na lista
*
***********************************************************************/

PTD_tpCondRet PTD_AtualizaDados(PTD_tppJogadores pJogadores, PTD_tppDadosJogador pDadosVelhos, PTD_tppDadosJogador pDadosNovos);

/***********************************************************************
*
*  $FC Função: PTD  &Gera Maos
*
*  $ED Descrição da função
*		Forma as maos dos jogadores com as tres cartas, sacadas do baralho
*
*  $EP Parâmetros
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
*  $FC Função: PTD  &
*
*  $ED Descrição da função
*
*
*  $EP Parâmetros
*
*
*  $FV Valor retornado
*
*
***********************************************************************/

void PTD_DestruirMao(PTD_tppJogadores pJogadores);

/***********************************************************************
*
*  $FC Função: PTD  &
*
*  $ED Descrição da função
*
*
*  $EP Parâmetros
*
*
*  $FV Valor retornado
*
*
***********************************************************************/

PTD_tpCondRet PTD_ExcluirCartaMao(PTD_tppJogadores pJogadores, PTD_tppDadosJogador pDados, int PosicaoCarta);

/***********************************************************************
*
*  $FC Função: PTD  &
*
*  $ED Descrição da função
*
*
*  $EP Parâmetros
*
*
*  $FV Valor retornado
*
*
***********************************************************************/

BAR_tppCarta PTD_ObterCartaMao(PTD_tppJogadores pJogadores, PTD_tppDadosJogador pDados, int PosicaoCarta);

/**************************************************************************
*
*							Funções para manipulação da Mesa
*
***************************************************************************/

/***********************************************************************
*
*  $FC Função: PTD  &
*
*  $ED Descrição da função
*
*
*  $EP Parâmetros
*
*
*  $FV Valor retornado
*
*
***********************************************************************/

PTD_tppMesa PTD_CriarMesa(void);

/***********************************************************************
*
*  $FC Função: PTD  &
*
*  $ED Descrição da função
*
*
*  $EP Parâmetros
*
*
*  $FV Valor retornado
*
*
***********************************************************************/

void PTD_EsvaziarMesa(PTD_tppMesa pMesa);

/***********************************************************************
*
*  $FC Função: PTD  &
*
*  $ED Descrição da função
*
*
*  $EP Parâmetros
*
*
*  $FV Valor retornado
*
*
***********************************************************************/

void PTD_DestruirMesa(PTD_tppMesa pMesa);

/***********************************************************************
*
*  $FC Função: PTD  &
*
*  $ED Descrição da função
*
*
*  $EP Parâmetros
*
*
*  $FV Valor retornado
*
*
***********************************************************************/

void PTD_IrInicioMesa(PTD_tppMesa pMesa);

/***********************************************************************
*
*  $FC Função: PTD  &
*
*  $ED Descrição da função
*
*
*  $EP Parâmetros
*
*
*  $FV Valor retornado
*
*
***********************************************************************/

BAR_tppCarta PTD_ObterCartaMesa(PTD_tppMesa pMesa);

/***********************************************************************
*
*  $FC Função: PTD  &
*
*  $ED Descrição da função
*
*
*  $EP Parâmetros
*
*
*  $FV Valor retornado
*
*
***********************************************************************/

PTD_tpCondRet PTD_InserirCartaMesa(PTD_tppMesa pMesa, BAR_tppCarta pCarta);

/***********************************************************************
*
*  $FC Função: PTD  &
*
*  $ED Descrição da função
*
*
*  $EP Parâmetros
*
*
*  $FV Valor retornado
*
*
***********************************************************************/

PTD_tpCondRet PTD_AvancarCartaMesa(PTD_tppMesa pMesa, int numCarta);

/***********************************************************************
*
*  $FC Função: PTD  &
*
*  $ED Descrição da função
*
*
*  $EP Parâmetros
*
*
*  $FV Valor retornado
*
*
***********************************************************************/

PTD_tppOrdenacao PTD_OrdemPrimordial(void);

/***********************************************************************
*
*  $FC Função: PTD  &
*
*  $ED Descrição da função
*
*
*  $EP Parâmetros
*
*
*  $FV Valor retornado
*
*
***********************************************************************/

void PTD_DeterminaManilha(PTD_tppOrdenacao pOrdem, BAR_tppCarta pCartaVira);

/***********************************************************************
*
*  $FC Função: PTD  &
*
*  $ED Descrição da função
*
*
*  $EP Parâmetros
*
*
*  $FV Valor retornado
*
*
***********************************************************************/

int PTD_ComparaCartas(BAR_tppCarta pCarta1, BAR_tppCarta pCarta2, PTD_tppOrdenacao pOrdem);

/***********************************************************************
*
*  $FC Função: PTD  &
*
*  $ED Descrição da função
*
*
*  $EP Parâmetros
*
*
*  $FV Valor retornado
*
*
***********************************************************************/

int PTD_ComputaVencedorRodada(PTD_tppMesa pMesa, PTD_tppOrdenacao pOrdem);

/***********************************************************************
*
*  $FC Função: PTD  &
*
*  $ED Descrição da função
*
*
*  $EP Parâmetros
*
*
*  $FV Valor retornado
*
*
***********************************************************************/

PTD_tpCondRet PTD_RemoverCartaMesaCorrente(PTD_tppMesa pMesa);

/***********************************************************************
*
*  $FC Função: PTD  &
*
*  $ED Descrição da função
*
*
*  $EP Parâmetros
*
*
*  $FV Valor retornado
*
*
***********************************************************************/

PTD_tpCondRet PTD_JogarCartaMesa(PTD_tppMesa pMesa, PTD_tppJogadores pJogadores, int PosicaoCarta);

/***********************************************************************
*
*  $FC Função: PTD  &
*
*  $ED Descrição da função
*
*
*  $EP Parâmetros
*
*
*  $FV Valor retornado
*
*
***********************************************************************/

int PTD_ObterEquipeCorrente(PTD_tppJogadores pJogadores);

/***********************************************************************
*
*  $FC Função: PTD  &
*
*  $ED Descrição da função
*
*
*  $EP Parâmetros
*
*
*  $FV Valor retornado
*
*
***********************************************************************/

int PTD_MenuAumentarPontos(void);

/***********************************************************************
*
*  $FC Função: PTD  &
*
*  $ED Descrição da função
*
*
*  $EP Parâmetros
*
*
*  $FV Valor retornado
*
*
***********************************************************************/

void PTD_PrintOrdem(PTD_tppOrdenacao pOrdem);

/***********************************************************************
*
*  $FC Função: PTD  &
*
*  $ED Descrição da função
*
*
*  $EP Parâmetros
*
*
*  $FV Valor retornado
*
*
***********************************************************************/

void PTD_MaoDeOnze(PTD_tppJogadores pJogadores, int Equipe);

/***********************************************************************
*
*  $FC Função: PTD  &
*
*  $ED Descrição da função
*
*
*  $EP Parâmetros
*
*
*  $FV Valor retornado
*
*
***********************************************************************/

void PTD_PrintCarta(BAR_tppCarta carta);

/***********************************************************************
*
*  $FC Função: PTD  &
*
*  $ED Descrição da função
*
*
*  $EP Parâmetros
*
*
*  $FV Valor retornado
*
*
***********************************************************************/

void PTD_PrintCartaMesa(PTD_tppMesa pMesa, int Virada);

/***********************************************************************
*
*  $FC Função: PTD  &
*
*  $ED Descrição da função
*
*
*  $EP Parâmetros
*
*
*  $FV Valor retornado
*
*
***********************************************************************/

void PTD_PrintJogador(PTD_tppJogadores jogador,int PontosEquipe);

/***********************************************************************
*
*  $FC Função: PTD  &
*
*  $ED Descrição da função
*
*
*  $EP Parâmetros
*
*
*  $FV Valor retornado
*
*
***********************************************************************/

void PTD_ImprimeMao(PTD_tppJogadores pJogadores);

/***********************************************************************
*
*  $FC Função: PTD  &
*
*  $ED Descrição da função
*
*
*  $EP Parâmetros
*
*
*  $FV Valor retornado
*
*
***********************************************************************/

void PTD_PrintCartaVirada(void);

/***********************************************************************
*
*  $FC Função: PTD  &
*
*  $ED Descrição da função
*
*
*  $EP Parâmetros
*
*
*  $FV Valor retornado
*
*
***********************************************************************/

void PTD_IniciaPartida(void);
