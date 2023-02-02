NAME = libft.a

SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
	ft_memset.c ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
	ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_substr.c \
	ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
	ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
	ft_printf.c ft_printchar.c ft_printnmb.c ft_printunmb.c ft_printhex.c \
	ft_printstr.c ft_printpnt.c \
	get_next_line.c \
	server.c client.c \
	
BNS = server_bonus.c client_bonus.c \

CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

OBJ = $(SRC:%.c=%.o)
BONUS = $(BNS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
		@$(AR) $(NAME) $(OBJ)
		@$(CC) $(CFLAGS) server.c libft.a -o server
		@$(CC) $(CFLAGS) client.c libft.a -o client
		
bonus: $(OBJ) $(BONUS)
		@$(AR) $(NAME) $(BONUS) $(OBJ)
		@$(CC) $(CFLAGS) server_bonus.c libft.a -o server_bonus
		@$(CC) $(CFLAGS) client_bonus.c libft.a -o client_bonus
	
		
		
clean:
		@$(RM) $(OBJ)
		
fclean: clean
		@$(RM) $(NAME) server client server_bonus client_bonus
		
re: fclean all

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC)
	cc -nostartfiles -shared -o libft.so $(OBJ)
