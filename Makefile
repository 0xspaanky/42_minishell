NAME = minishell
CFLAGS = -Wall -Wextra -Werror
CC = cc 

SRC =	Libft/ft_split.c \
		Libft/ft_strlen.c \
		Libft/ft_substr.c \
		Libft/ft_strjoin.c \
		Libft/ft_calloc.c \
		minishell.c \


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
