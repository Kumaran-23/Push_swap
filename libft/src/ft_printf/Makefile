NAME = libftprintf.a
HEADER = $(NAME:.a=.h)
SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)
GCC = gcc -c -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

all: $(NAME)

$(NAME): $(OBJECTS)
		$(AR) $(NAME) $(OBJECTS)

%.o: %.c $(HEADER)
		$(GCC) $<

clean:
		$(RM) $(OBJECTS) $(NAME)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
