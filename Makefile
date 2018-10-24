PROG_NAME = main

BIN_DIR = bin
BUILD_DIR = build
SRC_DIR = src

CC = g++
CFLAGS = -Wall -W -Wformat=0 -Wcast-qual -Wcast-align -Wwrite-strings -Wconversion -Wfloat-equal -Wpointer-arith -I/usr/include/freetype2
LIB = -lX11 -lXft

SRC = $(wildcard $(SRC_DIR)/*.cpp $(SRC_DIR)/*/*.cpp)
INC = $(wildcard $(SRC_DIR)/*.h $(SRC_DIR)/*/*.h) Makefile
OBJ = $(patsubst $(SRC_DIR)/%,$(BUILD_DIR)/%,$(SRC:.cpp=.o))
CLEAR = rm -fr $(BUILD_DIR)/*

$(BIN_DIR)/$(PROG_NAME): $(OBJ)
	@mkdir -p $(BIN_DIR)
	$(CC) $^ -o $@ $(LIB)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(INC)
	@mkdir -p $(BUILD_DIR)/$*
	$(CC) $(CFLAGS) -o $@ -c $< -g -O0

run: $(BIN_DIR)/$(PROG_NAME)
	$(MAKE) && $^

all:
	$(CLEAR) && $(MAKE)

clean:
	$(CLEAR)

clear:
	$(CLEAR)
