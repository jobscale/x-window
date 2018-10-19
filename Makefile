PROG_NAME = main

BIN_DIR = bin
BUILD_DIR = build
SRC_DIR = src

CC = g++
CFLAGS = -Wall
LIB = -lX11

SRC = $(wildcard $(SRC_DIR)/*.cpp $(SRC_DIR)/*/*.cpp)
INC = $(wildcard $(SRC_DIR)/*.h $(SRC_DIR)/*/*.h)
OBJ = $(patsubst $(SRC_DIR)/%,$(BUILD_DIR)/%,$(SRC:.cpp=.o))
CLEAR = rm -fr $(BUILD_DIR)/*

$(BIN_DIR)/$(PROG_NAME): $(OBJ)
	@mkdir -p $(BIN_DIR)
	$(CC) $^ -o $@ $(LIB)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(INC)
	@mkdir -p $(BUILD_DIR)/$*
	$(CC) $(CFLAGS) -o $@ -c $<

run: $(BIN_DIR)/$(PROG_NAME)
	$(MAKE) && $^

clean:
	$(CLEAR)

clear:
	$(CLEAR)
