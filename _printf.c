#include "holberton.h"
#include <stdarg.h>

/**
 * _withformat - prints depending the format
 * @format: the format sent by the main
 * @i: index of _printf loop
 * @count: characters printed;
 * @valist: va_list args
 * Return: @count the number of characters printed
 */
int _withformat(const char *format, int i, int count, va_list valist)
{
	/*HERE THE DIFERENT IDENTIFIERS*/
	/*Scaping double %%*/
	if (format[i + 1] == '%')
	{
		int c = format[i + 1];

		_putchar(c);
		count++;
	}
	/*FOR CHARACTERS (%c)*/
	if (format[i + 1] == 'c')
	{
		int c = va_arg(valist, int);

		_putchar(c);
		count++;
	}
	/*For Strings (%s)*/
	if (format[i + 1] == 's')
	{
		char *s;
		s = va_arg(valist, char*);
		while(*s != '\0')
		{
			_putchar(*s);
			s++;
			count++;
		}
	}
	/*The formats "%i" and "%d" do the same when it comes to printf*/
	if (format[i + 1] == 'i' || format[i + 1] == 'd')
	{
		int n = va_arg(valist, int);

		if (!n)
		{
			count++;
			_putchar('0');
		} else
			count += print_number(n); /*We did this fucntion in the past*/
	}
	/*Print octal numbers "%o"*/
	if (format[i + 1] == 'o')
	{
		int n = va_arg(valist, int);
		int octalNumber;

		count += print_octal(n); /*Fuction that gets octal*/
	}
	/*Print unsigned ints "%u"*/
	if (format[i + 1] == 'u')
	{
		unsigned int n = va_arg(valist, unsigned int);

		count += print_unsig(n);
	}
	return (count);
}

/**
 * _printf - Fuction that prints to the std output
 * @format: list of parameters passed
 * Return: @count the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list valist;
	int i = 0;
	int count = 0;

	va_start(valist, format);
	while (format && format[i])
	{
		if (format[i] != '%')
		{
			count++;
			/*FOR NO ARGUMENTS*/
			_putchar(format[i]);
		} else
		{
			/* FUCTION THAT TAKES ALL OTHER CASES WITH FORMAT*/
			/* WE HAD TO CREATE THIS BECAUSE BETTY (40 LINES PER FUCNTION)*/
			count = _withformat(format, i, count, valist);
			i++; /*This will skip the next character after (%)*/
		}
		i++;
	}
	va_end(valist);
	return (count);
}
