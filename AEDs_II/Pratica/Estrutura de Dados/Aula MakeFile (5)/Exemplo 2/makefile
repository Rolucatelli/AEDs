# Automatizando o makefile

# Nome do projeto
PROJ_NAME=hello

# Arquivos .c
C_SOURCE=$(wildcard *.c)

# Arquivos .h
H_SOURCE=$(wildcard *.h)

# Arquivos objeto
OBJ=$(C_SOURCE:.c=.o)

# Compilador
CC=gcc

# Flags (opções) para o compilador
CC_FLAGS=-c         \
         -W         \
         -Wall      \
         -ansi      \
         -pedantic

#########################
# Compilação e linkagem #
#########################
all: $(PROJ_NAME)

$(PROJ_NAME): $(OBJ)
	$(CC) -o $@ $^
# o $^ lista os pre requisitos e invoca o linker para compilar
%.o: %.c %.h
	$(CC) -o $@ $< $(CC_FLAGS)
# o $@ significa o arquivo .o e o $< significa o nome do primeiro pre requisito

main.o: main.c $(H_SOURCE)
	$(CC) -o $@ $< $(CC_FLAGS)

clean:
	rm -rf *.o $(PROJ_NAME) *~