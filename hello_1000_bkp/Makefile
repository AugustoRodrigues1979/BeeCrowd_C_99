# Definições de variáveis
CXX = gcc
CXXFLAGS = -Wall -std=c11 -o0 -g

# Arquivos de origem
SRC = main.c

# Arquivos objeto
OBJ = $(SRC:.c=.o)

# Nome do executável
EXEC = hello_1000_bkp.exe

# Regra principal
all: $(EXEC)

# Como criar o executável
$(EXEC): $(OBJ)
	@echo Building $(EXEC)
	$(CXX) $(OBJ) -o $(EXEC)
	@echo End Building $(EXEC)

# Como criar os arquivos .o
%.o: %.c
	@echo Building $@ ...
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpar arquivos de compilação
clean:
	rm -f $(OBJ) $(EXEC)
