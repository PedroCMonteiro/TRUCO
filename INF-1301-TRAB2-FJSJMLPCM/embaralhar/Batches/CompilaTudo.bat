REM  Compila todos os .makes
REM Requer o ambiente (environment) inicializado para compilar com o VisualStudio

cls

del ..\Objetos\*.obj
del ..\Produtos\*.err
del ..\Produtos\*.exe

REM compila para producao sem otimizacoes
pushd .
cd ../Ferramentas
nmake /F..\Composicao\TesteEmbaralhar.make 
popd

copy ..\Produtos\*.err ..\Produtos\tudo.err

notepad ..\Produtos\tudo.err