 BAR_tppBaralho embralhar(BAR_tppBaralho baralho)
 {
     LIS_tpCondRet ret ;
     BAR_tppBaralho embaralhado ;
     BAR_tppCarta carta ;
     int posicao ;
  
     #ifdef _DEBUG
         assert( baralho != NULL ) ;
     #endif    
  
     #ifdef _DEBUG
         assert( baralho->numElem <= 54 ) ;
     #endif
  
     embaralhado = ( BAR_tppBaralho * ) malloc( sizeof( BAR_tppBaralho ) );
    
     if( embaralhado != NULL )
     {
         return NULL;
     }
    
     embaralhado = BAR_CriarBaralho( );
    
     if( embaralhado != NULL )
     {
         return NULL;
    
     srand( time( NULL ) );
      
     while ( baralho->numELem > 0 )
     {
         IrTopoBaralho( baralho );
         posicao = rand % baralho->numElem;
        
         ret = LIS_AvancarElementoCorrente( baralho , posicao - 1 );
        
         if ( ret == LIS_CondRetListaVazia )
         {
             return NULL;
         }
        
         if ( ret == LIS_CondRetFimLista )
         {
             continue ( );
         }
      
         BAR_ObterCarta( baralho , carta ) ;
         ret = BAR_InserirCarta( embaralho , carta );
        
         if ( ret == LIS_CondRetFaltouMemoria )
         {
             return NULL;
         }
        
         ret = BAR_RemoverCarta( baralho );
         if ( ret == LIS_CondRetListaVazia )
         {
             break ( );
         }
      
         BAR_DestruirCarta( carta ) ;
        
     }
     BAR_destruirBaralho( baralho );
    
     free( baralho );
    
     return embaralhado;
 }
