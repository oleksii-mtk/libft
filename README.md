Here's a `README.md` for your project:

```markdown
# Libft - Custom C Standard Library Functions

This repository contains a set of C functions that replicate behavior from the C standard library (libc) with a custom prefix, `ft_`. These functions are part of a project to reimplement some essential libc functions from scratch to gain a deeper understanding of C programming.

## Table of Contents

- [Overview](#overview)
- [Functions](#functions)
- [Usage](#usage)
- [Installation](#installation)
- [License](#license)

## Overview

This project reimplements key functions from libc. Each function is prefixed with `ft_` to distinguish them from standard libc functions. The goal is to create a custom library that provides core functionalities needed for low-level operations, string manipulation, and memory management in C.

## Functions

### Character Functions
- **ft_isalpha**: Checks if a character is alphabetic.
- **ft_isdigit**: Checks if a character is a digit.
- **ft_isalnum**: Checks if a character is alphanumeric.
- **ft_isascii**: Checks if a character is within the ASCII range.
- **ft_isprint**: Checks if a character is printable.
- **ft_toupper**: Converts a character to uppercase.
- **ft_tolower**: Converts a character to lowercase.

### String Functions
- **ft_strlen**: Computes the length of a string.
- **ft_strlcpy**: Copies up to a specified length from one string to another.
- **ft_strlcat**: Concatenates strings up to a specified length.
- **ft_strchr**: Finds the first occurrence of a character in a string.
- **ft_strrchr**: Finds the last occurrence of a character in a string.
- **ft_strncmp**: Compares two strings up to a specified length.
- **ft_strnstr**: Finds a substring within another string.
- **ft_strdup**: Duplicates a string using dynamic memory allocation.
- **ft_substr**: Extracts a substring from a string.
- **ft_strjoin**: Joins two strings into a new dynamically allocated string.
- **ft_strtrim**: Trims specified characters from the beginning and end of a string.
- **ft_split**: Splits a string by a specified delimiter.
- **ft_strmapi**: Applies a function to each character of a string and creates a new string.
- **ft_striteri**: Applies a function to each character of a string by reference.

### Memory Functions
- **ft_memset**: Fills a block of memory with a specific value.
- **ft_bzero**: Sets a block of memory to zero.
- **ft_memcpy**: Copies a block of memory.
- **ft_memmove**: Moves a block of memory with handling for overlapping regions.
- **ft_memchr**: Finds a character in a block of memory.
- **ft_memcmp**: Compares two blocks of memory.
- **ft_calloc**: Allocates zero-initialized memory for an array.
  
### Utility Functions
- **ft_atoi**: Converts a string to an integer.
- **ft_itoa**: Converts an integer to a string.
- **ft_putchar_fd**: Writes a character to a file descriptor.
- **ft_putstr_fd**: Writes a string to a file descriptor.
- **ft_putendl_fd**: Writes a string followed by a newline to a file descriptor.
- **ft_putnbr_fd**: Writes an integer to a file descriptor.

## Usage

1. Clone the repository:
   ```bash
   git clone https://github.com/oleksii-mtk/libft.git
   cd libft
   ```

2. Compile the library:
   ```bash
   make
   ```

3. Include the library in your C projects:
   ```c
   #include "libft.h"
   ```

4. Link the library when compiling:
   ```bash
   gcc -L. -lft your_file.c -o your_program
   ```

## Installation

After cloning the repository, use `make` to build the library. This will generate a `libft.a` file, which can be linked with your projects.

```bash
make
```

To clean up object files after building:
```bash
make clean
```

To remove all files generated by the build:
```bash
make fclean
```

To rebuild the library:
```bash
make re
```

## License

This project is open source and available under the [MIT License](LICENSE).
```

