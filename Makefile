# Makefile for Libft

# Compiler
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Library Name
NAME = libft.a

# Source Files
SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
       ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
       ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c \
       ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c \
       ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c

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
