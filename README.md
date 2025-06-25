# ft_printf

A custom implementation of the printf function from the C standard library, created as part of the 42 Tokyo curriculum.

## Overview

ft_printf is a library that mimics the behavior of the standard printf function, supporting various format specifiers and providing formatted output to stdout.

## Supported Format Specifiers

- `%c` - Character
- `%s` - String
- `%p` - Pointer address (hexadecimal)
- `%d` - Signed decimal integer
- `%i` - Signed decimal integer
- `%u` - Unsigned decimal integer
- `%x` - Unsigned hexadecimal integer (lowercase)
- `%X` - Unsigned hexadecimal integer (uppercase)
- `%%` - Literal percent sign

## Project Structure

```
.
├── Makefile                    # Build configuration
├── README.md                   # Project documentation
├── include/
│   └── ft_printf.h            # Header file with function declarations
├── ft_printf.c                # Main printf implementation
├── ft_put_fd.c                # File descriptor output functions
├── ft_print_void_hex.c        # Pointer hexadecimal printing
├── ft_print_num_hex.c         # Number hexadecimal printing
└── ft_print_us_num_dec.c      # Unsigned decimal printing
```

## Key Functions

### Core Functions
- `ft_printf()` - Main function that handles format string parsing and output
- `print_chr()` - Prints a single character
- `print_str()` - Prints a string with null handling

### Numeric Functions
- `print_num_dec()` - Prints signed decimal integers
- `print_us_num_dec()` - Prints unsigned decimal integers
- `print_num_hex()` - Prints integers in hexadecimal format (both upper/lowercase)
- `print_void_hex()` - Prints pointer addresses in hexadecimal format

### Utility Functions
- `ft_putchar_fd()` - Outputs character to file descriptor
- `ft_putnbr_fd()` - Outputs number to file descriptor
- `ft_putstr_fd()` - Outputs string to file descriptor

## Building

```bash
# Compile the library
make

# Clean object files
make clean

# Clean all generated files
make fclean

# Rebuild everything
make re
```

The build process creates `libftprintf.a`, a static library that can be linked with your projects.

## Usage

Include the header file and link with the library:

```c
#include "ft_printf.h"

int main() {
    ft_printf("Hello %s! The answer is %d.\n", "World", 42);
    ft_printf("Pointer: %p, Hex: %x, Uppercase: %X\n", &main, 255, 255);
    return 0;
}
```

Compile with:
```bash
gcc your_program.c -L. -lftprintf
```

## Implementation Details

- Uses variadic functions (`va_start`, `va_arg`, `va_end`) for handling variable arguments
- Implements custom number-to-string conversion for decimal and hexadecimal formats
- Handles edge cases like null pointers and zero values
- Returns the number of characters printed (like standard printf)
- Memory-safe with proper error handling

## Author

**kmiyazaw** - 42 Tokyo Student

## License

This project is part of the 42 School curriculum.