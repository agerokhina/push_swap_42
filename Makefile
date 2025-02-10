LIB_PATH = ./lib
BUILD_PATH = ./build
SRC_PATH = ./src
NAME = push_swap
CC = cc
CFLAGS = -I./include -Wall -Wextra -Werror -g # -fsanitize=address

# Указываем все исходные файлы
SRC = $(SRC_PATH)/push_swap.c \
						$(SRC_PATH)/array.c \
						$(SRC_PATH)/stacknode.c \
						$(SRC_PATH)/stacksort.c \
						$(SRC_PATH)/stackread.c \
						$(SRC_PATH)/stackutils.c \
						$(SRC_PATH)/stackmovea.c \
						$(SRC_PATH)/stackmoveb.c \
						$(SRC_PATH)/validators.c

OBJ = $(SRC:$(SRC_PATH)/%.c=$(BUILD_PATH)/%.o)

LIBFT = $(LIB_PATH)/libft/libft.a
PRINTFT = $(LIB_PATH)/ft_printf/libftprintf.a

all: $(NAME)

# Сборка основного исполняемого файла
$(NAME): $(OBJ) $(LIBFT) $(PRINTFT) 
	$(CC)  $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTFT) -o $(NAME)
	@echo "Project $(NAME) created."

# Создание объектных файлов
$(BUILD_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(BUILD_PATH)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_PATH)/%.o: $(GNL_PATH)/%.c
	@mkdir -p $(BUILD_PATH)
	$(CC) $(CFLAGS) -c $< -o $@

# Сборка libft
$(LIBFT):
	@$(MAKE) -C $(LIB_PATH)/libft  OBJ_DIR=$(BUILD_PATH)

# Сборка ft_printf
$(PRINTFT):
	@$(MAKE) -C $(LIB_PATH)/ft_printf OBJ_DIR=$(BUILD_PATH)

clean:
	@rm -f $(OBJ)
	@rm -rf $(BUILD_PATH)
	@-$(MAKE) clean -C $(LIB_PATH)/libft || echo "libft clean skipped."
	@-$(MAKE) clean -C $(LIB_PATH)/ft_printf || echo "ft_printf clean skipped."
	@echo "Object files and build directories cleaned."

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) fclean -C $(LIB_PATH)/libft
	@$(MAKE) fclean -C $(LIB_PATH)/ft_printf

re: fclean all