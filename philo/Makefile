NAME		=		philo
CFLAGS		=		-Wall -Wextra -Werror -pthread -g #-fsanitize=address
SRC			=		$(wildcard *.c)
OBJDIR		=		obj
OBJ			=		$(patsubst %.c,$(OBJDIR)/%.o,$(SRC))

all: $(OBJDIR) $(NAME)

$(NAME): $(OBJ)
	cc $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJDIR)/%.o: %.c
	cc $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

.PHONY: all clean fclean re

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -rf $(OBJDIR)

re: fclean all
