#include "main.h"
/**
 * _printf - print to stout formatted text
 *
 * @format: format spacifier
 * Return: number of bytes printed
 */
int _printf(const char *format, ...)
{
	unsigned int i, s_count, count = 0;

	va_list arg;

	va_start(arg, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
		}
		else if (format[i + 1] == 'c')
		{
			_putchar(va_arg(arg, int));
			i++;

		}
		else if (format[i + 1] == 's')
		{
			s_count = putss(va_arg(arg, char *));
			i++;
			count += (s_count - 1);
		}
		else if (format[i + 1] == '%')
		{
			_putchar('%');
		}
		count += 1;
	}

	va_end(arg);
	return (count);
}
