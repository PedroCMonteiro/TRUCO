REM Executa os testes de todos os scripts através dos constructos .exe

cls

if exist ..\Scripts\estatisticas.estat  del ..\Scripts\estatisticas.estat

..\Produtos\TRAB2-1	/s..\Scripts\TesteEmbaralhar.script /l..\Produtos\TesteEmbaralhar.err /a..\Scripts\estatisticas.estat
if errorlevel 4 goto sai

..\Ferramentas\exbestat /e..\Scripts\estatisticas.estat

:sai