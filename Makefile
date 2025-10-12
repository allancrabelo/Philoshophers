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
				controller/utilitaries.c \
				controller/start.c \
				controller/loop.c \
				controller/routine.c \
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
	@mkdir -p $(dir $@)
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

credit:
	@echo " =================================================="
	@echo "     Philosophers - Dining Philosophers Problem"
	@echo " =================================================="
	@echo " Developer: Allan Rabelo - Fullstack Developer"
	@echo " Institution: 42 School® Porto - 2025"
	@echo " ------------------------------------------"
	@echo " Email: allanaugustocarneirorabelo@gmail.com"
	@echo " GitHub: https://github.com/allancrabelo"
	@echo " ------------------------------------------"
	@echo " Total Commits: $(shell git rev-list --count HEAD 2>/dev/null || echo 'N/A')"
	@echo " Last Updated: $(shell git log -1 --format=%cd --date=short 2>/dev/null || echo 'N/A')"
	@echo " ================================================="

.PHONY: all clean fclean re
