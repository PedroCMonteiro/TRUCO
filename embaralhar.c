 BAR_tppBaralho embralhar(BAR_tppBaralho baralho)
 {
     LIS_tpCondRet ret;
     BAR_tppBaralho embaralhado;
     int random;
  
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
    
     embaralhado = LIS_CriarLista( );
    
     if( embaralhado != NULL )
     {
         return NULL;
    
     srand( time( NULL ) );
      
     while ( baralho->numELem > 0 )
     {
         IrInicioLista( baralho );
         random = rand % baralho->numElem;
        
         ret = LIS_AvancarElementoCorrente( baralho,random );
        
         if ( ret == LIS_CondRetListaVazia )
         {
             break ( );
         }
        
         if ( ret == LIS_CondRetFimLista )
         {
             continue ( );
         }
        
         ret = LIS_InserirElementoApos( embaralho , LIS_ObterValor( baralho ) );
        
         if ( ret == LIS_CondRetFaltouMemoria )
         {
             return NULL;
         }
        
         ret = BAR_RemoverCarta( baralho );
         if ( ret == LIS_CondRetListaVazia )
         {
             break ( );
         }
        
     }
     BAR_destruirBaralho( baralho );
    
     free( baralho );
    
     return embaralhado;
 }
