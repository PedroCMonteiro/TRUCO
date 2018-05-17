##################################################
###
### Diretivas de MAKE para o construto: TesteEmbaralhar
### Gerado a partir de: TesteEmbaralhar.comp
###
### ----- Arquivo gerado, N�O EDITE!!! -----
###
##################################################

### Nomes globais

NOME            = TesteEmbaralhar


### Nomes de paths

Ph                   = ..\Fontes
Pobj                 = ..\Objetos
Perr                 = ..\Produtos
PDEFAULT             = ..\Fontes
Pc                   = ..\Fontes

### Nomes de diret�rios para gera��o

Fh                   = ..\Fontes
Fobj                 = ..\Objetos
Ferr                 = ..\Produtos
FDEFAULT             = ..\Fontes
Fc                   = ..\Fontes

### Macros da plataforma


O       = /D_CRT_SECURE_NO_DEPRECATE
OD      = /Zi /Od /D_CRT_SECURE_NO_DEPRECATE
L       =
LD      = /DEBUG /DEBUGTYPE:CV

!IFDEF PRD
O       = /Ox /D_CRT_SECURE_NO_DEPRECATE
!ENDIF

OPT     = /c /J /W4 /nologo
INCLUDE = $(INCLUDE);$(PDEFAULT)


### Regras de gera��o

all : limpa \
   $(Fobj)\TESTEMB.obj   $(Fobj)\EMBARALHAR.obj   $(Fobj)\BARALHO.obj \
   $(Fobj)\LISTA.obj \
   Construto

### Limpar arquivos

limpa :
   if exist $(Ferr)\$(NOME).err  del $(Ferr)\$(NOME).err


### Depend�ncias de m�dulos objeto a compilar

$(Fobj)\TESTEMB.obj :  {$(Pc)}\TESTEMB.c \
    {$(PDEFAULT)}BARALHO.H            {$(PDEFAULT)}EMBARALHAR.H         {$(Ph)}Generico.h           \
    {$(PDEFAULT)}GeraAlt.H            {$(PDEFAULT)}LISTA.H              {$(Ph)}LerParm.h            \
    {$(PDEFAULT)}TST_ESPC.H           {$(Ph)}TST_Espc.h          
   cl $(O) $(OPT) /Fo$(Fobj)\ $(Fc)\$(@B).c >> $(Ferr)\$(NOME).err

$(Fobj)\EMBARALHAR.obj :  {$(Pc)}\EMBARALHAR.c \
    {$(PDEFAULT)}BARALHO.H            {$(PDEFAULT)}EMBARALHAR.H         {$(PDEFAULT)}GERAALT.H            \
    {$(PDEFAULT)}LISTA.H             
   cl $(O) $(OPT) /Fo$(Fobj)\ $(Fc)\$(@B).c >> $(Ferr)\$(NOME).err

$(Fobj)\BARALHO.obj :  {$(Pc)}\BARALHO.c \
    {$(PDEFAULT)}BARALHO.H            {$(PDEFAULT)}LISTA.H             
   cl $(O) $(OPT) /Fo$(Fobj)\ $(Fc)\$(@B).c >> $(Ferr)\$(NOME).err

$(Fobj)\LISTA.obj :  {$(Pc)}\LISTA.c \
    {$(Ph)}LISTA.h             
   cl $(O) $(OPT) /Fo$(Fobj)\ $(Fc)\$(@B).c >> $(Ferr)\$(NOME).err


### Termina��o

Construto : \
   $(Fobj)\TESTEMB.obj   $(Fobj)\EMBARALHAR.obj   $(Fobj)\BARALHO.obj \
   $(Fobj)\LISTA.obj
    cd $(Fobj)
    LINK $(L) @$(NOME).build >> $(Ferr)\$(NOME).err

##################################################
###
### Fim de diretivas MAKE para o construto: TesteEmbaralhar
###
##################################################

