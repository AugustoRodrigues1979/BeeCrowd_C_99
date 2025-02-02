# Compilador
CXX = gcc
CXXFLAGS = -Wall -std=c11 -o0 -g

# Flags de link para a CUnit
LDFLAGS = -lcunit

# Definições de variaveis
SRC = $(wildcard *.c)
PREFIX_TST_SRC = $(wildcard test_*.c)
PREFIX_TST = $(PREFIX_TST_SRC:test_%.c=setup_suit_test_%)
BUILD_DIR = build
OBJ = $(SRC:.c=.o)
OBJS = $(BUILD_DIR)/*.o
CUNIT_INC = \cygwin64\usr\include\CUnit
EXEC = test.exe

# Variavel para criacao de include file via makefile
AUTO_GENERATE_INCLUDE_FILE = $(BUILD_DIR)/suittest.h
HEADER_INCLUDE_FILE = $(BUILD_DIR)/headtst.h
BODY_INCLUDE_FILE = $(BUILD_DIR)/bodytst.h
TAIL_INCLUDE_FILE = $(BUILD_DIR)/tailtst.h

# Criação do diretório de objetos se não existir
$(shell mkdir -p $(BUILD_DIR))

# Regra para compilar os arquivos .c em arquivos .o
%.o: %.c
	@echo Building object file $(BUILD_DIR)/$@ ....
	@$(CXX) -c $(CXXFLAGS) -I$(CUNIT_INC) $< -o $(BUILD_DIR)/$@

# Regra padrão para compilar o executável
all: $(AUTO_GENERATE_INCLUDE_FILE) | $(OBJ)
	@echo Building executable $(EXEC) ....
	@$(CXX) $(OBJS) $(LDFLAGS) -o $(EXEC)
	@echo End Building $(EXEC)

header_file:
	@echo $(PREFIX_TST)

btoken1:
	@echo "" > $(BUILD_DIR)/$@.h
	@for file in $(PREFIX_TST); do \
		echo "extern ITEM_SUIT_TEST * $$file(int *amount_test, char *s_name_suit, int amount_char_suit_name);" >> $(BUILD_DIR)/$@.h; \
	done
	@echo "" >> $(BUILD_DIR)/$@.h

btoken2:
	@echo "SUIT_TEST all_suits_test[] = {" > $(BUILD_DIR)/$@.h
	@for file in $(PREFIX_TST); do \
		echo "	$$file," >> $(BUILD_DIR)/$@.h; \
	done
	@echo "	NULL" >> $(BUILD_DIR)/$@.h
	@echo "};" >> $(BUILD_DIR)/$@.h
	@echo "" >> $(BUILD_DIR)/$@.h

$(HEADER_INCLUDE_FILE):
	@echo "#ifndef __HEADER_SETUP_SUIT_TEST__" > $@
	@echo "#define __HEADER_SETUP_SUIT_TEST__" >> $@
	@echo "" >> $@.h

$(TAIL_INCLUDE_FILE):
	@echo "#endif" > $@
	@echo "" >> $@

$(BODY_INCLUDE_FILE): btoken1 btoken2
	@cat $(BUILD_DIR)/btoken1.h > $(BODY_INCLUDE_FILE)
	@cat $(BUILD_DIR)/btoken2.h >> $(BODY_INCLUDE_FILE)

$(AUTO_GENERATE_INCLUDE_FILE): $(HEADER_INCLUDE_FILE) $(BODY_INCLUDE_FILE) $(TAIL_INCLUDE_FILE)
	@echo Generating header file for tests...
	@cat $(HEADER_INCLUDE_FILE) > $(AUTO_GENERATE_INCLUDE_FILE)
	@cat $(BODY_INCLUDE_FILE) >> $(AUTO_GENERATE_INCLUDE_FILE)
	@cat $(TAIL_INCLUDE_FILE) >> $(AUTO_GENERATE_INCLUDE_FILE)
	@echo File $(AUTO_GENERATE_INCLUDE_FILE) created with success!

# Limpar arquivos de compilação
clean:
	rm -rf $(BUILD_DIR) $(EXEC)
