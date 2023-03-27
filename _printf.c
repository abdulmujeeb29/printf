#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - produces output according to a format
 * @format: format string
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
    int printed = 0;
    va_list args;

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;

            switch (*format)
            {
                case 'c':
                    printed += putchar(va_arg(args, int));
                    break;

                case 's':
                    printed += printf("%s", va_arg(args, char *));
                    break;

                case '%':
                    printed += putchar('%');
                    break;

                default:
                    putchar('%');
                    putchar(*format);
                    printed += 2;
                    break;
            }
        }
        else
        {
            putchar(*format);
            printed++;
        }

        format++;
    }

    va_end(args);

    return printed;
}
