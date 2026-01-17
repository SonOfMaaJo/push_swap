NAME = push_swap
CC = cc
CFLAGS	= -Wall -Wextra -Werror -I includes
SRC_DIR	= srcs
OBJ_DIR	= objs
INC_DIR	= includes

SRCS_FILES	= main.c \
		  operations.c \
		  operations_otimized.c \
		  process.c \
		  turk_algorithm.c \
		  get_target_in_a.c \
		  ft_atoi.c \
		  ft_perfdivp.c \
		  ft_printarg.c \
		  ft_printf.c \
		  ft_printp.c \
		  ft_putchar.c \
		  ft_putnbrbase.c \
		  ft_putstr.c \
		  ft_strchr.c \
		  ft_strlcat.c \
		  ft_strlen.c \
		  check_valids.c \
		  ft_strcmp.c 

SRCS		= $(addprefix $(SRC_DIR)/, $(SRCS_FILES))
OBJS		= $(addprefix $(OBJ_DIR)/, $(SRCS_FILES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
