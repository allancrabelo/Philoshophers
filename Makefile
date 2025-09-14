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
				controller/initializer.c \
				controller/dead.c \
				controller/start.c \
				errors/error_messages.c \
				parse/parse.c \
				utils/classification_functions.c \
				utils/output_functions.c \
				utils/philosophers_utilities_functions.c \
				utils/type_conversion_functions.c \

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
