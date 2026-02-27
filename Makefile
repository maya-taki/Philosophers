NAME		= philo

CC			= cc
CFLAGS		= -Wall -Werror -Wextra
INCLUDE		= -I include

RM			= rm -rf

SRCSDIR		= srcs
OBJDIR		= objs

SRCS		= main.c \
			  actions.c \
			  inits.c \
			  parsing.c \
			  utils.c \
			  runtime.c \
			  monitor.c

SRCS		:= $(addprefix $(SRCSDIR)/, $(SRCS))

OBJS		:= $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.c=.o)))

all: $(NAME)
	$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: $(SRCSDIR)/%.c | $(OBJDIR)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	@$(RM) $(OBJDIR)

fclean: clean

re: fclean all

.PHONY: all clean fclean re norminette