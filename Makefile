CC = cc
FLAGS = -Wall -Wextra -Werror -I
SRCS = srcs
INCLUDES = includes
SRCS_FILES = $(shell find $(SRCS) -name "*.c")
OBJS_FILES = $(SRCS_FILES:.c=.o)
NAME = libftprintf.a

all : $(NAME)

$(NAME) : $(OBJS_FILES)
	ar rcs $@ $^

%.o : %.c
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

clean :
	rm -f $(OBJS_FILES)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
