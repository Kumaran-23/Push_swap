NAME 			= libft.a
INCLUDE 		= inc/
SRC_DIR			= src/
OBJ			= $(SRC:.c=.o)
GCC 			= gcc -c -Wall -Wextra -Werror -I
AR 				= ar rcs
RM 				= rm -f

#src

LIBFT_DIR		=	libft/
LIBFT			=	ft_isalnum ft_isalpha ft_isascii ft_isdigit ft_isprint\
					ft_bzero ft_calloc ft_memchr ft_memcmp ft_memmove ft_memset\
					ft_putchar_fd ft_putendl_fd ft_putnbr_fd ft_putstr_fd\
					ft_atoi ft_itoa ft_tolower ft_toupper ft_split ft_strchr ft_strdup\
					ft_striteri ft_strjoin ft_strlcat ft_strlcpy ft_strlen ft_strmapi ft_strncmp\
					ft_strnstr ft_strrchr ft_strtrim ft_substr

GNL_DIR			=	gnl/
GNL				=	get_next_line get_next_line_utils

FTPRINTF_DIR	=	ft_printf/
FTPRINTF		=	ft_printf ft_print ft_printhex ft_printptr ft_putstr_fd\
					ft_unsigned

SRC_FILES+=$(addprefix $(LIBFT_DIR),$(LIBFT))
SRC_FILES+=$(addprefix $(GNL_DIR),$(GNL))
SRC_FILES+=$(addprefix $(FTPRINTF_DIR),$(FTPRINTF))

SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))

start:		
		@echo "Starting Make"
		@make all
all: $(NAME)

$(NAME): $(OBJ)
			@$(AR) $(NAME) $(OBJ)

%.o: %.c
						@$(GCC) $(INCLUDE) -c $< -o  $@
				
clean:
		@$(RM) $(OBJ)
		@echo "Cleaned!"

fclean: clean
		@$(RM) $(NAME)
		@echo "Cleaned!"

re: fclean all

.PHONY:		all clean fclean re
