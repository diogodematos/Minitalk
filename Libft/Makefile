NAME = libft.a

SRC = $(wildcard *.c)

CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
		@$(AR) $(NAME) $(OBJ)
		
clean:
		@$(RM) $(OBJ)
		
fclean: clean
		@$(RM) $(NAME)
		
re: fclean all

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC)
	cc -nostartfiles -shared -o libft.so $(OBJ)
