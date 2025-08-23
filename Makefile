NAME		:= philo
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror
DEBUGFLAGS	:= -g
LDFLAGS		:= -pthread

HEADIR		:= ./includes
SRCSDIR		:= ./src
OBJSDIR		:= ./obj

HEADLIST	:= philosophers.h
HEADERS		:= $(addprefix $(HEADIR)/, $(HEADLIST))

SRCSLIST	:= main.c \
				parse/parse.c \
				errors/usage_errors/usage_codes.c \
				errors/usage_errors/usage_errors.c \
				errors/value_errors/value_codes.c \
				errors/value_errors/value_errors.c \
				errors/mutex_errors/mutex_codes.c \
				errors/mutex_errors/mutex_errors.c \
				errors/allocation_errors/allocation_codes.c\
				errors/allocation_errors/allocation_errors.c\
				utils/utils.c \
				exit/ft_exit.c \
				init/init_table.c \
				init/init_silverware.c \
				init/init_philos.c

OBJSLIST	:= $(SRCSLIST:.c=.o)
OBJS		:= $(addprefix $(OBJSDIR)/, $(OBJSLIST))

vpath %.c $(SRCSDIR)

CYAN		:= \033[96m
RED			:= \033[91m
RESET		:= \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@echo ""
	@echo "$(CYAN)Linking $(NAME) ...$(RESET)"
	$(CC) $(CFLAGS) $(DEBUGFLAGS) $(OBJS) -o $@ $(LDFLAGS)
	@echo ""
	@echo "$(CYAN)$(NAME) Ready to use$(RESET)"

$(OBJSDIR)/%.o: %.c $(HEADERS)
	@echo "$(CYAN)Compiling $< ...$(RESET)"
	@mkdir -p $(dir $@)   # Cria diretórios pai necessários
	$(CC) $(CFLAGS) $(DEBUGFLAGS) -c $< -o $@

clean:
	@echo ""
	@echo "$(RED)Deleting $(NAME) Objects ...$(RESET)"
	@$(RM) -r $(OBJSDIR)

fclean: clean
	@echo ""
	@echo "$(RED)Deleting $(NAME) Executable ...$(RESET)"
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
