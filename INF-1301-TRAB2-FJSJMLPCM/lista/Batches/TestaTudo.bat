REM Executa os testes de todos os scripts atrav�s dos constructos .exe

cls

if exist ..\Scripts\estatisticas.estat  del ..\Scripts\estatisticas.estat

..\Produtos\TRAB2-2	/s..\Scripts\TesteLista.script /l..\Produtos\TesteLista.err /a..\Scripts\estatisticas.estat
if errorlevel 4 goto sai

..\Ferramentas\exbestat /e..\Scripts\estatisticas.estat

:sai