 LIS_tppLista embralhar(LIS_tppLista baralho)
 {
     LIS_tpCondRet ret;
     LIS_tppLista embaralhado;
     int random;
    
     embaralhado = ( LIS_tppLista* ) malloc( sizeof( LIS_tppLista ) );
    
     if( embaralhado != NULL )
     {
         return NULL;
     }
    
     embaralhado = LIS_CriarLista( );
    
     if( embaralhado != NULL )
     {
         return NULL;
    
    
     srand( time( NULL ) );
     while ( baralho )
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
        
         ret = LIS_InserirElementoApos( embaralho,LIS_ObterValor( baralho ) );
        
         if ( ret == LIS_CondRetFaltouMemoria )
         {
             return NULL;
         }
        
         ret = LIS_ExcluirElemento( baralho );
         if ( ret == LIS_CondRetListaVazia )
         {
             break ( );
         }
        
     }
     LIS_limparLista( baralho );
    
     free( baralho );
    
     return embaralhado;
 }
