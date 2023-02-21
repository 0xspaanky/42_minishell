NAME = minishell
CFLAGS = -Wall -Wextra -Werror
CC = cc 

SRC = minishell.c 

OBJS = $(SRC:.c=.o)

RM = rm -f

all : $(NAME)

$(NAME) : $(OBJS) 
		$(CC) -lreadline $(CFLAGS) $(OBJS) -o $(NAME)
clean :
	$(RM) $(OBJS)

fclean :
	$(RM) $(NAME)

re : fclean all
