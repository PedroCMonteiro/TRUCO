REM   Limpa tudo que sera' regerado

if exist TestaTudo.bat goto faz
rem >>> esta' no diretorio ilegal
goto sai

:faz

pushd .

cd ..\Batches
del *.bak

cd ..\Composicao
del *.bak
del *.list
del *.make

cd ..\Fontes
del *.bak
del *.err

cd ..\Objetos
del *.bak
del *.obj
del *.build

cd ..\Produtos
del *.bak
del *.log
del *.exe
del *.err
del *.estat

cd ..\Tabelas
del *.bak

cd ..\Scripts
del *.bak
del *.estat

cd ..\gmake
del *.bak
del *.err
del *.obj


popd

:sai