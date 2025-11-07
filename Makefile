NAME = libftprintf.a

SRC = ft_printf.c ft_char_utils.c ft_num_utils.c

OBJ = $(SRC:.c=.o)

CC = cc

AR = ar rcs

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
		$(AR) $(NAME) $(OBJ)

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re