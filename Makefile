NAME = minishell
CFLAGS = -Wall -Wextra -Werror
CC = cc 

SRC =	Libft/ft_split.c \
		Libft/ft_strlen.c \
		Libft/ft_substr.c \
		Libft/ft_strjoin.c \
		Libft/ft_calloc.c \
		Libft/ft_strdup.c \
		Libft/ft_lstnew.c \
		Libft/ft_lstadd_front.c \
		Libft/ft_lstadd_back.c \
		minishell.c \
		Libft/ft_split_wid_char.c \


OBJS = $(SRC:.c=.o)

RM = rm -f

all : $(NAME)
#-fsanitize=address
$(NAME) : $(OBJS) 
		$(CC) -lreadline  $(CFLAGS) $(OBJS) -o $(NAME)
clean :
	$(RM) $(OBJS)

fclean :
	$(RM) $(NAME)

re : fclean all
