# nome do projeto
PROJ_NAME = projeto_ic

# o compilador
CC = g++

# todos os arquivos .cpp
CPP_SOURCE = $(wildcard ./src/*.cpp)

# todos os arquivos .h
H_SOURCE = $(wildcard ./include/*.h)

# todos os objetos
OBJ = $(subst .cpp,.o,$(subst src,objects,$(CPP_SOURCE)))

CC_FLAGS =  -c -I -std=c++11

RM = rm -rf

all: objFolder $(PROJ_NAME)

$(PROJ_NAME): $(OBJ)
	@echo "\n\nARQUIVO LIDO COM SUCESSO!\n\n"
	$(CC) $^ -o $@
 
./objects/%.o: ./src/%.cpp ./include/%.h
	$(CC) $< $(CC_FLAGS) -o $@

./objects/main.o: ./src/main.cpp $(H_SOURCE)
	$(CC) $< $(CC_FLAGS) -o $@

objFolder:
	@mkdir -p objects

clean:
	@$(RM) ./objects/*.o $(PROJ_NAME) *~
	@rmdir objects

.PHONY: all clean