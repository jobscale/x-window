PROG_NAME = main

BIN_DIR = bin
BUILD_DIR = build
SRC_DIR = src

CC = g++
CFLAGS = -Wall
LIB = -lX11
INC = -l include

SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(patsubst $(SRC_DIR)/%,$(BUILD_DIR)/%,$(SRC:.cpp=.o))

CLEAR = rm -f $(BIN_DIR)/$(PROG_NAME) $(BUILD_DIR)/*.o

$(BIN_DIR)/$(PROG_NAME): $(OBJ)
	@mkdir -p $(BIN_DIR)
	$(CC) $^ -o $@ $(LIB)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

run: $(BIN_DIR)/$(PROG_NAME)
	$(MAKE) && $^

clear:
	$(CLEAR)
