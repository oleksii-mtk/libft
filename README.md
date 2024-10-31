# Libft - Custom Implementation of libc Functions

## Overview
Libft is a project to recreate a comprehensive subset of standard C library functions. Each function mirrors the behavior and prototypes of the originals but is prefixed with `ft_` (e.g., `strlen` becomes `ft_strlen`). This project avoids using the `restrict` qualifier and does not compile with the `-std=c99` flag to ensure compatibility.

## Functions Included

### Character Checks
- `ft_isalpha` - Checks if a character is alphabetic.
- `ft_isdigit` - Checks if a character is a digit.
- `ft_isalnum` - Checks if a character is alphanumeric.
- `ft_isascii` - Checks if a character is in the ASCII range.
- `ft_isprint` - Checks if a character is printable.

### String Manipulation
- `ft_strlen` - Computes the length of a string.
- `ft_strlcpy` - Copies a string to a buffer, ensuring null-termination.
- `ft_strlcat` - Concatenates a string to a buffer, ensuring null-termination.
- `ft_strchr` - Locates the first occurrence of a character in a string.
- `ft_strrchr` - Locates the last occurrence of a character in a string.
- `ft_strncmp` - Compares two strings up to n characters.
- `ft_strnstr` - Locates a substring within a string, up to n characters.

### Memory Manipulation
- `ft_memset` - Fills a block of memory with a specific value.
- `ft_bzero` - Sets a block of memory to zero.
- `ft_memcpy` - Copies a block of memory.
- `ft_memmove` - Moves a block of memory, handling overlapping areas.
- `ft_memchr` - Scans a block of memory for a specific value.
- `ft_memcmp` - Compares two blocks of memory.

### Character Conversion
- `ft_toupper` - Converts a character to uppercase.
- `ft_tolower` - Converts a character to lowercase.

### Other Utility Functions
- `ft_atoi` - Converts a string to an integer.

### Memory Allocation (Using `malloc`)
- `ft_calloc` - Allocates zero-initialized memory.
- `ft_strdup` - Duplicates a string in dynamically allocated memory.

## Compilation
Each function can be compiled individually. Ensure you do not use the `-std=c99` flag, as the `restrict` keyword is omitted from these implementations.

Example compilation for `ft_strlen`:
```bash
gcc -Wall -Wextra -Werror -c ft_strlen.c -o ft_strlen.o
```

To create a static library containing all functions:
```bash
ar rcs libft.a *.o
```

## Usage
Include the compiled library (`libft.a`) in your C projects, and link it during compilation.

## License
This project is open-source and available for modification and distribution.
