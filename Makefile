CC = gcc
CFLAGS = -Wall -pthread -I./include
SRC = src/main.c src/server.c src/socket.c src/response.c src/handler.c
OBJ = $(patsubst src/%.c, build/%.o, $(SRC))
EXEC = server

$(EXEC): $(OBJ)
	$(CC) -o $(EXEC) $(OBJ) -pthread

build/%.o: src/%.c
	mkdir -p build
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf build $(EXEC)

run: $(EXEC)
	./$(EXEC)
