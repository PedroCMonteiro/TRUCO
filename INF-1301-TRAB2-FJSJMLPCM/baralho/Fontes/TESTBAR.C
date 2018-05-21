/***************************************************************************
*  $MCI Módulo de implementação: TEMB Teste embaralhar um baralho
*
*  Arquivo gerado:              TSTEMB.C
*  Letras identificadoras:      TEMB
*
*  Projeto: INF 1301 / 1628 Implementação do jogo de Truco Paulista em C
*  Gestor:  LES/DI/PUC-Rio
*  Autores: PCM  Pedro Castro Monteiro
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*     1       PCM   01/mai/2018 início desenvolvimento
*
***************************************************************************/

#include  <string.h>
#include  <stdio.h>
#include  <stdlib.h>
#include  <malloc.h>
#include  <assert.h>

#include  "TST_ESPC.H"

#include  "GeraAlt.H"
#include  "Generico.h"
#include  "LerParm.h"

#include  "BARALHO.H"


static const char RESET_BARALHO_CMD     			[ ] = "=resetteste"					;
static const char CRIAR_BARALHO_CMD        			[ ] = "=criarbaralho"				;
static const char CRIAR_CARTA_CMD        			[ ] = "=criarcarta"					;
static const char INSERIR_CARTA_ANTES_CMD        	[ ] = "=inserircartaantes"			;
static const char INSERIR_CARTA_APOS_CMD        	[ ] = "=inserircartaapos"			;
static const char AVANCAR_CARTA_CMD        			[ ] = "=avancarcarta"				;
static const char IR_INICIO_BARALHO_CMD 			[ ] = "=iriniciobaralho"			;
static const char IR_FINAL_BARALHO_CMD  			[ ] = "=irfinalbaralho"				;
static const char OBTER_CARTA_CMD        			[ ] = "=obtercarta"					;
static const char REMOVER_CARTA_CORRENTE_CMD		[ ] = "=removercartacorrente"		;
static const char REMOVER_CARTA_ESPECIFICADA_CMD	[ ] = "=removercartaespecificada"	;
static const char CRIAR_BARALHO_COMPLETO_CMD        [ ] = "=criarbaralhocompleto"		;
static const char CRIAR_BARALHO_TRUCO_CMD        	[ ] = "=criarbaralhotruco"			;

#define TRUE  1
#define FALSE 0

#define VAZIO     0
#define NAO_VAZIO 1

#define DIM_VT_BARALHO  4
#define MAX_CARTAS     50
#define NUM_NAIPE       5
#define NUM_CARTAS     13

BAR_tppBaralho vtBaralhos[ DIM_VT_BARALHO ] ;

static const BAR_tpNaipe NAIPE[ NUM_NAIPE ] = { Espadas , Copas , Paus , Ouros , Coringa } ;

/***** Protótipos das funções encapuladas no módulo *****/

   static void CriaBaralho( BAR_tppBaralho pBaralho ) ;

   static int ValidarInxBaralho( int inxBaralho , int Modo ) ;   

/*****  Código das funções exportadas pelo módulo  *****/


/***********************************************************************
*
*  $FC Função: TEMB &Testar embaralhar
*
*  $ED Descrição da função
*     Podem ser criadas até 4 baralhos, identificadas pelos índices 0 a 3.
*     Cada barlho pode ter no máximo 50 cartas, podendo ter cartas repitidas 
*
*     Comandos disponíveis:
*
*     =resetteste
*           - anula o vetor de baralhos. Provoca vazamento de memória
*     =criabaralho                  inxBaralho
*     =embaralhar                   inxBaralho  CondRetEsp
*
***********************************************************************/


    TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
    {
        int inxBaralho = -1 ,
            numLidos   = -1 ,        
            CondRetEsp = -1  ;

        TST_tpCondRet CondRet ;

        int i ;        

      /* Efetuar reset de teste de baralho */            

         if ( strcmp( ComandoTeste , RESET_BARALHO_CMD ) == 0 )
         {

            for ( i = 0 ; i < DIM_VT_BARALHO ; i++ )
            {
               vtBaralhos[ i ] = NULL ;
            } /* for */

            return TST_CondRetOK ;

         } /* fim ativa: Efetuar reset de teste de baralho */

      /* Efetuar criação de baralho sem cartas */
        else if ( strcmp( ComandoTeste , CRIA_BARALHO_CMD ) == 0 )
        {

            numLidos = LER_LerParametros( "i" ,
                  &inxBaralho ) ;           
          
            if ( ( numLidos != 1 )
              || ( ! ValidarInxBaralho( inxBaralho , VAZIO )))
            {
               return TST_CondRetParm ;
            } /* if */

            vtBaralhos[ inxBaralho ] = BAR_CriaBaralho( ) ;

            return TST_CondRetOK ;

        } /* fim ativa: Efetuar criação de baralho sem cartas */ 

      /* Efetuar criação de baralho com cartas */
        else if ( strcmp( ComandoTeste , CRIA_BARALHO_COM_CARTAS_CMD ) == 0 )
        {
            numLidos = LER_LerParametros( "i" ,
                                          &inxBaralho ) ;           
          
            if ( ( numLidos != 1 )
              || ( ! ValidarInxBaralho( inxBaralho , VAZIO )))
            {
               return TST_CondRetParm ;
            } /* if */

            vtBaralhos[ inxBaralho ] = BAR_CriaBaralho( ) ;
            CriaBaralho( vtBaralhos[ inxBaralho ] ) ;

            return TST_CondRetOK ;

        } /* fim ativa: Efetuar criação de baralho com cartas */             

      /* Testar Embaralhar */
        else if ( strcmp( ComandoTeste , EMBARALHAR_CMD ) == 0 )
        {

            numLidos = LER_LerParametros( "ii" ,
                  &inxBaralho , &CondRetEsp ) ;   

            if ( numLidos != 2
                 || ( ! ValidarInxBaralho( inxBaralho , NAO_VAZIO )))
            {
               return TST_CondRetParm ;
            } /* if */

            CondRet = EMB_Embaralhar( vtBaralhos[ inxBaralho ] ) ;

            return TST_CompararInt( CondRetEsp , CondRet ,
                     "Condicao de retorno errada ao embaralhar." ) ;

        } /* fim ativa: BAR &Testar Baralho */ 

    return TST_CondRetNaoConhec ;
    } /* Fim função: TBAR &Testar baralho */


/*****  Código das funções encapsuladas no módulo  *****/


/***********************************************************************
*
*  $FC Função: TBAR -Validar indice de baralho
*
***********************************************************************/

   int ValidarInxBaralho( int inxBaralho , int Modo )
   {

      if ( ( inxBaralho <  0 )
           || ( inxBaralho >= DIM_VT_BARALHO ) )
      {
         return FALSE ;
      } /* if */
         
      if ( Modo == VAZIO )
      {
         if ( vtBaralhos[ inxBaralho ] != 0 )
         {
            return FALSE ;
         } /* if */
      } else
      {
         if ( vtBaralhos[ inxBaralho ] == 0 )
         {
            return FALSE ;
         } /* if */
      } /* if */
         
      return TRUE ;

   } /* Fim função: TBAR -Validar indice de baralho */           

/********** Fim do módulo de implementação: TBAR Teste baralho **********/
