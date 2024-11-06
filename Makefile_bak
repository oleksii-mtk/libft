# Makefile for Libft

# Compiler
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Library Name
NAME = libft.a

# Source Files
SRCS = ft_itoa.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	   ft_strlen.c


# Object Files (replace .c with .o)
OBJS = $(SRCS:.c=.o)

# Default rule to create the library
all: $(NAME)

# Rule to compile the library
$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "Library $(NAME) created."

# Rule to compile .c files to .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files
clean:
	@rm -f $(OBJS)
	@echo "Object files removed."

# Clean up all generated files, including the library
fclean: clean
	@rm -f $(NAME)
	@echo "Library $(NAME) removed."

# Recompile the library from scratch
re: fclean all

# Phony targets
.PHONY: all clean fclean re
