@ECHO  OFF
REM  Compila programa C usando nmake %1.mak  do conjunto MS Visual c/c++
REM  Sintaxe:  faz  nome-do-arquivo.mak  [o]
REM                    opção  o : compila otimizado. Todos os obj devem 
REM                               ter sido destruidos antes
REM Requer o ambiente (environment) inicializado para compilar com o VisualStudio Microsoft

pushd  .

if ""=="%1" goto erro

del *.err
if "o"=="%2" goto otimz
if "O"=="%2" goto otimz

cd ..\Ferramentas
nmake /F..\Composicao\%1.make
goto contin

:otimz
cd ..\Ferramentas
nmake /F..\Composicao\%1.make "PRD="

:contin
notepad ..\Produtos\%1.err

goto sai

:erro
echo Falta nome do arquivo a compilar

:sai
popd
