NAME = get_next_line.a

SRCS = get_next_line.c get_next_line_utils.c get_next_line_h

OBJ = $(SRCS:.c=.o)
INCLUDES = get_next_line.h
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)

%.o: %.c libft.h
	$(CC) $(FLAGS) -c $< -o $@
	ar rc $(NAME) $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
