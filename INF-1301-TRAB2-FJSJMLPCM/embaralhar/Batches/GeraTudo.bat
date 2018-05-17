@ECHO  OFF
REM  Gera todos scripts de make pelos arquivos .comp

cls

pushd  .

cd ..\Ferramentas
REM gmake /b..\Composicao /c..\Composicao\TesteEmbaralhar
gmake /b..\Composicao /cTesteEmbaralhar
popd
