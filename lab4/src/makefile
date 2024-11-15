CC = gcc
CFLAGS = -Wall -Wextra -g
LDFLAGS =

# Исходные файлы
SRC = parallel_min_max.c find_min_max.c utils.c
OBJ = $(SRC:.c=.o)

# Имя исполнимого файла
EXEC = parallel_min_max

# Опции компилятора
DEPS = find_min_max.h utils.h

# Правило по умолчанию
all: $(EXEC)

# Линковка исполнимого файла
$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC) $(LDFLAGS)

# Правило для компиляции .c файлов в .o
%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

# Очистка объектных файлов и исполнимого файла
clean:
	rm -f $(OBJ) $(EXEC)

# Правило для запуска программы
run: $(EXEC)
	./$(EXEC)

# Правило для запуска программы с параметром таймаута
run_timeout: $(EXEC)
	./$(EXEC) --timeout 10 --seed 42 --array_size 100 --pnum 4

# Удаление временных файлов
fclean: clean
	rm -f $(EXEC)

.PHONY: all clean run fclean run_timeout
