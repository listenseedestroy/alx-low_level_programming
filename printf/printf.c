#include <main.h>

/**
 * _printf - Printf function that handles c, s and %.
 * @format: format.
 * Return: Printed chars.
 */

int _printf(const char *format, ...) {
    int count = 0;

    while (*format) {
        if (*format == '%') {
            format++; // Move past '%'

            // Handle conversion specifiers
            switch (*format) {
                case 'c':
                    putchar((char)va_arg(&format, int)); // Note: Using va_arg directly
                    count++;
                    break;
                case 's':
                    {
                        const char *str = va_arg(&format, const char *);
                        while (*str) {
                            putchar(*str);
                            count++;
                            str++;
                        }
                    }
                    break;
                case '%':
                    putchar('%');
                    count++;
                    break;
                default:
                    // Unsupported specifier, just print it as is
                    putchar('%');
                    putchar(*format);
                    count += 2;
            }
        } else {
            putchar(*format);
            count++;
        }

        format++;
    }

    return count;
}

int main() {
    _printf("Hello, %s! The answer is %d%%. Character: %c\n", "User", 69, 'H');
    return 0;
}

/**printf now will handle speciifiers d and i
*/

int _printf(const char *format, ...) {
    int count = 0;

    while (*format) {
        if (*format == '%') {
            format++; // Move past '%'

            // Handle conversion specifiers
            switch (*format) {
                case 'c':
                    putchar((char)va_arg(&format, int));
                    count++;
                    break;
                case 's':
                    {
                        const char *str = va_arg(&format, const char *);
                        while (*str) {
                            putchar(*str);
                            count++;
                            str++;
                        }
                    }
                    break;
                case 'd':
                case 'i':
                    {
                        int num = va_arg(&format, int);
                        printf("%d", num);
                        count++;
                    }
                    break;
                case '%':
                    putchar('%');
                    count++;
                    break;
                default:
                    // Unsupported specifier, just print it as is
                    putchar('%');
                    putchar(*format);
                    count += 2;
            }
        } else {
            putchar(*format);
            count++;
        }

        format++;
    }

    return count;
}

int main() {
    _printf("Hello, %s! The answer is %d%%. Character: %c\n", "User", 69, 'H');
    _printf("This is a number: %d\n", 43564);
    return 0;
}
