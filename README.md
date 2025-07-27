# libft

---

## ![C](https://imgs.search.brave.com/g4qCBV3wmAJK1V-IkpVcx7s33YufA8lTFHY44Jcj-w4/rs:fit:860:0:0:0/g:ce/aHR0cHM6Ly91cGxv/YWQud2lraW1lZGlh/Lm9yZy93aWtpcGVk/aWEvY29tbW9ucy9k/L2Q4L0NfTGFuZ3Vh/Z2VfTG9nby5zdmc)

![42](https://img.shields.io/badge/42-joamiran-blue.svg?style=flat-square) ![42 Lisboa](https://img.shields.io/badge/42-Lisboa-blue.svg?style=flat-square) ![GitHub](https://img.shields.io/github/license/joamiran/libft?style=flat-square) ![GitHub last commit](https://img.shields.io/github/last-commit/joamiran/libft?style=flat-square)

A comprehensive C library containing reimplementations of standard C library functions, plus additional utility functions for string manipulation, memory management, linked lists, and formatted output.

## 📋 Table of Contents

- [About](#-about)
- [Features](#-features)
  - [Part I - Standard C Library Functions](#part-i---standard-c-library-functions)
  - [Part II - Additional String Functions](#part-ii---additional-string-functions)
  - [Part III - Linked Lists](#part-iii---linked-lists)
  - [Printf Implementation](#printf-implementation)
  - [Get Next Line](#get-next-line)
- [Installation](#️-installation)
  - [Prerequisites](#prerequisites)
  - [Build](#build)
- [Usage](#-usage)
  - [Include in your project](#include-in-your-project)
  - [Link with your program](#link-with-your-program)
  - [Example usage](#example-usage)
- [Project Structure](#-project-structure)
- [Testing](#-testing)
- [Performance](#-performance)
- [Function Categories](#-function-categories)
- [Compilation Flags](#-compilation-flags)
- [Forbidden Functions](#-forbidden-functions)
- [Key Features](#-key-features)
- [Contributing](#-contributing)
- [License](#-license)
- [Author](#-author)

## 📚 About

**libft** is a custom C library developed as part of the 42 School curriculum. It provides essential functions for C programming, including:

- Standard C library function reimplementations
- Additional utility functions for string and memory operations
- Linked list manipulation functions
- Custom `printf` implementation with file descriptor support
- `get_next_line` function for reading files line by line

## 🚀 Features

### Part I - Standard C Library Functions

- **Character checks**: [`ft_isalpha`](ft_isalpha.c), [`ft_isdigit`](ft_isdigit.c), [`ft_isalnum`](ft_isalnum.c), [`ft_isascii`](ft_isascii.c), [`ft_isprint`](ft_isprint.c)
- **String functions**: [`ft_strlen`](ft_strlen.c), [`ft_strchr`](ft_strchr.c), [`ft_strrchr`](ft_strrchr.c), [`ft_strncmp`](ft_strncmp.c), [`ft_strnstr`](ft_strnstr.c)
- **Memory functions**: [`ft_memset`](ft_memset.c), [`ft_memcpy`](ft_memcpy.c), [`ft_memmove`](ft_memmove.c), [`ft_memchr`](ft_memchr.c), [`ft_memcmp`](ft_memcmp.c)
- **String copying**: [`ft_strlcpy`](ft_strlcpy.c), [`ft_strlcat`](ft_strlcat.c)
- **Character conversion**: [`ft_toupper`](ft_toupper.c), [`ft_tolower`](ft_tolower.c)
- **String to integer**: [`ft_atoi`](ft_atoi.c), [`ft_atol`](ft_atol.c)
- **Memory allocation**: [`ft_calloc`](ft_calloc.c), [`ft_bzero`](ft_bzero.c)
- **String duplication**: [`ft_strdup`](ft_strdup.c)

### Part II - Additional String Functions

- **String manipulation**: [`ft_substr`](ft_substr.c), [`ft_strjoin`](ft_strjoin.c), [`ft_strtrim`](ft_strtrim.c), [`ft_split`](ft_split.c)
- **Number to string**: [`ft_itoa`](ft_itoa.c), [`ft_itoa_base`](ft_itoa_base.c)
- **String iteration**: [`ft_strmapi`](ft_strmapi.c), [`ft_striteri`](ft_striteri.c)
- **File descriptor output**: [`ft_putchar_fd`](ft_putchar_fd.c), [`ft_putstr_fd`](ft_putstr_fd.c), [`ft_putendl_fd`](ft_putendl_fd.c), [`ft_putnbr_fd`](ft_putnbr_fd.c)

### Part III - Linked Lists

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
} t_list;
```

- **List operations**: [`ft_lstnew`](ft_lstnew.c), [`ft_lstadd_front`](ft_lstadd_front.c), [`ft_lstadd_back`](ft_lstadd_back.c)
- **List utilities**: [`ft_lstsize`](ft_lstsize.c), [`ft_lstlast`](ft_lstlast.c)
- **List manipulation**: [`ft_lstdelone`](ft_lstdelone.c), [`ft_lstclear`](ft_lstclear.c), [`ft_lstiter`](ft_lstiter.c), [`ft_lstmap`](ft_lstmap.c)

### Printf Implementation

Custom [`ft_printf`](ft_printf.c) function with support for:

- **Format specifiers**: `%c`, `%s`, `%d`, `%i`, `%u`, `%x`, `%X`, `%p`, `%%`
- **Flags**: `-`, `0`, `#`, ` `, `+`
- **Width and precision**: `*`, `.`
- **File descriptor version**: [`ft_printf_fd`](ft_printf_fd.c)

### Get Next Line

[`get_next_line`](get_next_line.c) function for reading files line by line with configurable buffer size.

## 🛠️ Installation

### Prerequisites

- GCC or any C compiler
- Make

### Build

```bash
# Clone the repository
git clone https://github.com/yourusername/libft.git
cd libft

# Compile the library
make

# Clean object files
make clean

# Clean everything
make fclean

# Recompile
make re
```

## 📖 Usage

### Include in your project

```c
#include "libft.h"
```

### Link with your program

```bash
gcc -Wall -Wextra -Werror your_file.c -L. -lft
```

### Example usage

```c
#include "libft.h"

int main(void)
{
    // String functions
    char *str = ft_strdup("Hello, World!");
    char **split = ft_split(str, ' ');

    // Linked list
    t_list *list = ft_lstnew("First");
    ft_lstadd_back(&list, ft_lstnew("Second"));

    // Printf
    ft_printf("Number: %d, String: %s\n", 42, "libft");

    // Memory cleanup
    free(str);
    // ... free split array and list

    return (0);
}
```

## 📁 Project Structure

```
libft/
├── Makefile                 # Build configuration
├── libft.h                 # Main header file
├── ft_printf.h             # Printf header file
├── get_next_line.h         # Get next line header file
├── README.md               # This file
├── .gitignore             # Git ignore rules
├── ft_*.c                 # Function implementations
└── obj/                   # Object files (created during build)
```

## 🧪 Testing

The library has been thoroughly tested with:

- Custom test suites
- 42 School testers
- Memory leak detection with Valgrind
- Edge cases and error handling

## ⚡ Performance

- Optimized algorithms for memory operations
- Efficient string manipulation
- Minimal memory footprint
- No unnecessary function calls

## 📊 Function Categories

| Category              | Functions     | Description                        |
| --------------------- | ------------- | ---------------------------------- |
| **Character Tests**   | 5 functions   | Check character properties         |
| **String Operations** | 15+ functions | String manipulation and analysis   |
| **Memory Management** | 8 functions   | Memory allocation and manipulation |
| **Linked Lists**      | 9 functions   | Dynamic data structure operations  |
| **File I/O**          | 6 functions   | File descriptor operations         |
| **Printf**            | 15+ functions | Formatted output implementation    |
| **Utilities**         | 10+ functions | Helper and conversion functions    |

## 🔧 Compilation Flags

The library is compiled with strict flags to ensure code quality:

```bash
-Wall -Wextra -Werror
```

## 🚫 Forbidden Functions

This implementation doesn't use any external libraries except for:

- `malloc`, `free` (memory management)
- `write` (system call)
- Standard library headers for type definitions

## 💡 Key Features

- **Memory Safe**: All functions handle edge cases and prevent buffer overflows
- **Norm Compliant**: Follows 42 School coding standards
- **Well Documented**: Each function includes comprehensive documentation
- **Modular Design**: Functions can be used independently
- **Performance Optimized**: Efficient algorithms and minimal overhead

## 🤝 Contributing

This is an educational project for 42 School. While not accepting external contributions, feel free to:

- Report bugs
- Suggest improvements
- Use as a reference for your own implementation

## 📜 License

This project is part of the 42 School curriculum and follows their academic guidelines.

## 👨‍💻 Author

**joamiran** - 42 Lisboa Student

---

_This library represents a comprehensive foundation for C programming, providing essential tools for memory management, string manipulation, and formatted output while maintaining high code quality standards._
