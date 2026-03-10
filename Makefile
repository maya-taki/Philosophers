NAME		= philo

CC = cc
CFLAGS = -Wall -Werror -Wextra
INCLUDE = -I./include

RM = rm -rf

SRCSDIR	= sources
OBJDIR = objs

FILES = 	  main.c \
			  actions.c \
			  inits.c \
			  parsing.c \
			  utils.c \
			  runtime.c \
			  monitor.c

DEBUG ?= 0
ifeq ($(DEBUG), 1)
	CFLAGS += -g2 -O0 -fsanitize=leak
endif

SRCS = $(addprefix $(SRCSDIR)/, $(FILES))

OBJS = $(SRCS:$(SRCSDIR)/%.c=$(OBJDIR)/%.o)

all: $(NAME)
	
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: $(SRCSDIR)/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	@$(RM) $(OBJDIR)

fclean: clean

re: fclean all

.PHONY: all clean fclean re norminette