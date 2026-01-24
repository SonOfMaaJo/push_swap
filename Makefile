NAME = push_swap
NAME_CHECKER = checker
CC = cc
CFLAGS	= -Wall -Wextra -Werror -I includes
SRC_DIR	= srcs
SRC_CHECKER_DIR = srcs_checker
OBJ_DIR	= objs
OBJ_CHECKER_DIR = objs_checker
INC_DIR	= includes
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS_FILES	= main.c \
		  operations.c \
		  operations_otimized.c \
		  process.c \
		  turk_algorithm.c \
		  get_target_in_a.c \
		  ps_atoi.c \
		  check_valids.c

SRCS_CHECKER_FILES = main.c \
					check_valids.c \
					operations.c \
					process_check.c \
					utils.c

SRCS		= $(addprefix $(SRC_DIR)/, $(SRCS_FILES))
SRCS_CHECKER = $(addprefix $(SRC_CHECKER_DIR)/, $(SRCS_CHECKER_FILES))
OBJS		= $(addprefix $(OBJ_DIR)/, $(SRCS_FILES:.c=.o))
OBJS_CHECKER = $(addprefix $(OBJ_CHECKER_DIR)/, $(SRCS_CHECKER_FILES:.c=.o))

all: $(NAME)

bonus: $(NAME_CHECKER)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

$(NAME_CHECKER) : $(LIBFT) $(OBJS_CHECKER)
	$(CC) $(CFLAGS) $(OBJS_CHECKER) -L$(LIBFT_DIR) -lft -o $(NAME_CHECKER)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_CHECKER_DIR)/%.o : $(SRC_CHECKER_DIR)/%.c
	@mkdir -p $(OBJ_CHECKER_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(OBJ_CHECKER_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_CHECKER)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all bonus

.PHONY: all clean fclean re
