CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
IFLAGS	=	-I.


####################################===SOURCE FILES===####################################

CHAR_FT_DIR		=	char_ft
CHAR_FT_FILES	=	ft_isalpha.c	ft_isdigit.c	ft_isalnum.c	ft_isascii.c	\
					ft_isprint.c	ft_toupper.c	ft_tolower.c
CHAR_FT_SRCS	=	$(addprefix $(CHAR_FT_DIR)/, $(CHAR_FT_FILES))

STR_FT_DIR		=	str_ft
STR_FT_FILES	=	ft_strtolower.c	ft_strlen.c		ft_strlcpy.c	ft_strcat.c		\
					ft_strlcat.c	\
					ft_strchr.c		ft_strrchr.c	ft_strcmp.c		ft_strncmp.c	\
					ft_strnstr.c	ft_atoi.c		ft_atoi_safe.c	ft_atoi_base.c	\
					ft_itoa.c		ft_strdup.c		\
					ft_substr.c		ft_strjoin.c	ft_strtrim.c	ft_split.c		\
					ft_strmapi.c	ft_striteri.c
STR_FT_SRCS		=	$(addprefix $(STR_FT_DIR)/, $(STR_FT_FILES))

MEM_FT_DIR		=	mem_ft
MEM_FT_FILES	=	ft_memset.c		ft_bzero.c		ft_memcpy.c		ft_memmove.c	\
					ft_memchr.c		ft_memcmp.c		ft_memswap.c	ft_calloc.c 
MEM_FT_SRCS		=	$(addprefix $(MEM_FT_DIR)/, $(MEM_FT_FILES))

PUTS_DIR		=	puts
PUTS_FILES		=	ft_putchar_fd.c		ft_putstr_fd.c		ft_putendl_fd.c		\
					ft_putnbr_fd.c
PUTS_SRCS		=	$(addprefix $(PUTS_DIR)/, $(PUTS_FILES))

LST_FT_DIR		=	lst_ft
LST_FT_FILES	=	ft_lstnew.c			ft_lstadd_front.c		ft_lstsize.c	\
					ft_lstlast.c		ft_lstadd_back.c		ft_lstdelone.c	\
					ft_lstclear.c		ft_lstiter.c			ft_lstmap.c
LST_FT_SRCS		=	$(addprefix	$(LST_FT_DIR)/, $(LST_FT_FILES))

ALGO_FT_DIR		=	algo_ft
ALGO_FT_FILES	=	ft_qsort.c
ALGO_FT_SRCS	=	$(addprefix $(ALGO_FT_DIR)/, $(ALGO_FT_FILES))

FT_PRINTF_DIR	=	ft_printf
FT_PRINTF_FILES	=	ft_printf.c		handle_char.c	handle_str.c		handle_ptr.c	\
					handle_uints.c	handle_int.c	handle_percent.c	ft_putpadded.c	\
					put_strf.c		put_uintf.c		uitoa_base_prec.c
FT_PRINTF_SRCS	=	$(addprefix $(FT_PRINTF_DIR)/, $(FT_PRINTF_FILES))

GNL_DIR			=	get_next_line
GNL_FILES		=	get_next_line.c		get_next_line_utils.c
GNL_SRCS		=	$(addprefix $(GNL_DIR)/, $(GNL_FILES))

SRCS			=	$(CHAR_FT_SRCS)	$(STR_FT_SRCS)	$(MEM_FT_SRCS)		\
					$(PUTS_SRCS)	$(LST_FT_SRCS)	$(ALGO_FT_SRCS)		\
					$(FT_PRINTF_SRCS)	$(GNL_SRCS)

##########################################################################################


OBJDIR	=	OBJS
OBJS	=	$(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

NEEDS_REBUILD_CMD	:=															\
	for src in $(SRCS); do														\
		obj="$(OBJDIR)/$$src";													\
		obj="$${obj%.c}.o";														\
		if [ ! -f "$$obj" ] || [ "$$src" -nt "$$obj" ]; then echo "$$src"; fi;	\
	done
NEEDS_REBUILD 	:=	$(shell $(NEEDS_REBUILD_CMD))
SRCTOTAL		:=	$(words $(NEEDS_REBUILD))
SRCNUM			:=	0

RESET		=	\033[0m
BOLD		=	\033[1m
RED			=	\033[31m
GREEN		=	\033[32m
YELLOW		=	\033[33m
ORANGE		=	\033[38;5;208m
YLLWGRN		=	\033[38;2;150;255;25m
PREVLINE	=	\033[A
RMLINE		=	\r\033[K


#########################################################################################

NAME = libft.a

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "$(RMLINE)$(BOLD)$(YELLOW)$(NAME) successfully compiled$(RESET)"

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@
	@$(eval SRCNUM := $(shell expr $(SRCNUM) + 1))
	@$(eval CALCPERCENT := $(shell echo "scale=4; $(SRCNUM) / $(SRCTOTAL) * 100" | bc))
	@$(eval PERCENT := $(shell printf "%.0f" $(CALCPERCENT)))
	@if [ $(SRCNUM) -gt 1 ]; then printf "$(PREVLINE)\r"; fi;
	@printf "$(BOLD)Compiling $(NAME): ["
	@$(eval PROGRESS := $(shell expr $(PERCENT) / 5))
	@if [ $(PERCENT) -ge 5 ]; then printf "$(GREEN)%0.s#" $(shell seq 1 $(PROGRESS)); fi;
	@$(eval CALCPADS := $(shell expr 20 - $(PROGRESS)))
	@if [ $(PERCENT) -lt 100 ]; then printf "$(RESET)$(BOLD)%0.s-" $(shell seq 1 $(CALCPADS)); fi;
	@printf "$(RESET)$(BOLD)] "
	@if [ $(PERCENT) -lt 25  ]; then	\
		printf "$(RED)";				\
	elif [ $(PERCENT) -lt 50 ]; then	\
		printf "$(ORANGE)";				\
	elif [ $(PERCENT) -lt 75 ]; then	\
		printf "$(BOLD)$(YELLOW)";		\
	elif [ $(PERCENT) -lt 100 ]; then	\
		printf "$(BOLD)$(YLLWGRN)";		\
	else								\
		printf "$(BOLD)$(GREEN)"; fi;
	@printf "%d%% $(RESET)\n" $(PERCENT)
	@printf "Compiling %-34s" $(notdir $@)

clean:
	@printf "$(RED)"
	@if [ -d $(OBJDIR) ]; then						\
		rm -rf $(OBJDIR);							\
		printf "Removed $(NAME) OBJS directory\n";			\
	else											\
		printf "$(NAME) objects not found\n"; fi;
	@printf "$(RESET)"

fclean: clean
	@printf "$(RED)"
	@if [ -f $(NAME) ]; then				\
		rm -f $(NAME);						\
		printf "Removed $(NAME)\n";			\
	else									\
		printf "$(NAME) not found\n"; fi;
	@printf "$(RESET)"

re: fclean
	@make -s all

#########################################################################################


.PHONY: all clean fclean re
