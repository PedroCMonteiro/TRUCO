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

#include  "EMBARALHAR.H"


static const char RESET_EMBARALHAR_CMD         [ ] = "=resetteste"            ;
static const char CRIA_BARALHO_SEM_CARTAS_CMD  [ ] = "=criabaralhosemcartas"  ;
static const char CRIA_BARALHO_COM_CARTAS_CMD  [ ] = "=criabaralhocomcartas"  ;
static const char EMBARALHAR_CMD               [ ] = "=embaralhar"            ;

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

      /* Efetuar reset de teste de embaralhar */            

         if ( strcmp( ComandoTeste , RESET_EMBARALHAR_CMD ) == 0 )
         {

            for( i = 0 ; i < DIM_VT_BARALHO ; i++ )
            {
               vtBaralhos[ i ] = NULL ;
            } /* for */

            return TST_CondRetOK ;

         } /* fim ativa: Efetuar reset de teste de embaralhar */

      /* Efetuar criação de baralho sem cartas */
        else if ( strcmp( ComandoTeste , CRIA_BARALHO_SEM_CARTAS_CMD ) == 0 )
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

        } /* fim ativa: EMB &Testar Embaralhar */ 

    return TST_CondRetNaoConhec ;
    } /* Fim função: TLIS &Testar lista */


/*****  Código das funções encapsuladas no módulo  *****/


/***********************************************************************
*
*  $FC Função: TEBM -Cria Baralho
*
***********************************************************************/

    void static CriaBaralho( BAR_tppBaralho pBaralho )
    {


      BAR_tppCarta pCarta ;

      int naipe      = -1 ,
          numero     = -1 ,
          numCartas  = -1  ;

      #ifdef _DEBUG
        assert( pBaralho != NULL );
      #endif 
         
      ALT_Inicializar( 1 ) ;          
    
      numCartas = ALT_GerarDistUniforme( 0 , MAX_CARTAS ) ;

      while( numCartas > 0 )
      {
    
        naipe = ALT_GerarDistUniforme( 0 , ( NUM_NAIPE - 1 ) );
        numero = ALT_GerarDistUniforme( 1 , NUM_CARTAS ) ;

        /* Validação da carta a ser criada */

        if ( ( ( naipe  * NUM_NAIPE ) + ( numero - 1 ) ) > MAX_CARTAS )
        {
         continue ;
        } /* if */
        
        pCarta = BAR_CriaCarta( numero , NAIPE[ naipe ] ) ;
        BAR_InserirCartaApos( pBaralho , pCarta ) ; 

        numCartas-- ;
      } /* while */
  } /* Fim função: TEMB -Criar Baralho */

/***********************************************************************
*
*  $FC Função: TLIS -Validar indice de baralho
*
***********************************************************************/

   int ValidarInxBaralho( int inxBaralho , int Modo )
   {

      if ( ( inxBaralho <  0 )
        || ( inxBaralho >= DIM_VT_BARALHO ))
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

   } /* Fim função: TEMB -Validar indice de baralho */           

/********** Fim do módulo de implementação: TEMB Teste embaralhar **********/
