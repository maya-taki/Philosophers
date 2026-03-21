NAME		= philo

CC = cc
CFLAGS = -Wall -Werror -Wextra -pthread
INCLUDE = -I./include

RM = rm -rf

SRCSDIR	= sources
OBJDIR = objs

FILES = 	  main.c \
			  actions.c \
			  state.c \
			  inits.c \
			  parsing.c \
			  utils.c \
			  runtime.c \
			  monitor.c

YELLOW		= \033[33m
RED			= \033[31m
GREEN		= \033[32m
BLUE		= \033[34m
END			= \033[0m

DEBUG ?= 0
ifeq ($(DEBUG), 1)
	CFLAGS += -g2 -O0 -fsanitize=leak
endif

SRCS = $(addprefix $(SRCSDIR)/, $(FILES))

OBJS = $(SRCS:$(SRCSDIR)/%.c=$(OBJDIR)/%.o)

all: $(NAME)
	
$(NAME): $(OBJS)
	@echo "$(YELLOW)Linking objects...$(END)"
	@$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) -o $(NAME)
	@echo "$(GREEN)$(NAME) built successfully!$(END)"

$(OBJDIR)/%.o: $(SRCSDIR)/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	@$(RM) $(OBJDIR)
	@echo "$(RED)Object files deleted.$(END)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)Deleted everything!$(END)"

norminette:
	@echo "$(YELLOW)Running norminette...$(END)"
	@norminette $(SRCS) -R CheckForbiddenSourceHeader || true

re: fclean all

.PHONY: all clean fclean re norminette