CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS =	ft_printf.c			handle_char.c		handle_str.c		handle_ptr.c	\
		handle_uints.c		handle_int.c		handle_percent.c	ft_putpadded.c	\
		put_strf.c			put_uintf.c			uitoa_base_prec.c

OBJS	= $(SRCS:.c=.o)

LIB_DIR = libft
LIB		= $(LIB_DIR)/libft.a

NAME = libftprintf.a

.PHONY = all clean fclean re

all: $(NAME)

$(NAME): $(LIB) $(OBJS)
	@echo Compiled to $(NAME)
	@ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -I$(LIB_DIR) -c $< -o $@

$(LIB):
	@echo Compiling library...
	@make -s -C $(LIB_DIR)
	@cp $(LIB) $(NAME)

bonus: all

clean:
	@rm -f $(OBJS)
	@make clean -s -C $(LIB_DIR)

fclean: clean
	@rm $(NAME)
	@make fclean -s -C $(LIB_DIR)

re: fclean all
