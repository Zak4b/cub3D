/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:19:56 by asene             #+#    #+#             */
/*   Updated: 2024/11/20 15:39:03 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// cspdiuxX%
static int	is_conversion(char c)
{
	static const char	*specifiers = "cspdiuxX%";
	int					i;

	i = 0;
	while (specifiers[i])
	{
		if (c == specifiers[i])
			return (1);
		i++;
	}
	return (0);
}

static int	handle_conversion(int fd, char **str, va_list args)
{
	int	count;

	count = 0;
	(*str)++;
	if (**str == 'c')
		count = ft_printf_putchar(fd, va_arg(args, int));
	else if (**str == 's')
		count = ft_printf_putstr(fd, va_arg(args, char *));
	else if (**str == 'p')
		count = ft_printf_put_pointer(fd, va_arg(args, void *));
	else if (**str == 'd' || **str == 'i')
		count = ft_printf_putnbr(fd, va_arg(args, int));
	else if (**str == 'u')
		count = ft_printf_putnbru(fd, (int)va_arg(args, unsigned int));
	else if (**str == 'x')
		count = ft_printf_puthex(fd, va_arg(args, unsigned int), HEX_BASE_L);
	else if (**str == 'X')
		count = ft_printf_puthex(fd, va_arg(args, unsigned int), HEX_BASE_U);
	else if (**str == '%')
		count = ft_printf_putchar(fd, '%');
	(*str)++;
	return (count);
}

static int	ft_printf_va(int fd, const char *format, va_list args)
{
	int	char_count;

	char_count = 0;
	while (*format)
	{
		if (*format == '%' && *(format + 1) && is_conversion(*(format + 1)))
			char_count += handle_conversion(fd, (char **)&format, args);
		else
			char_count += ft_printf_putchar(fd, *(format++));
	}
	return (char_count);
}

int	ft_printf(const char *format, ...)
{
	int		char_count;
	va_list	args;

	va_start(args, format);
	char_count = ft_printf_va(1, format, args);
	va_end(args);
	return (char_count);
}

int	ft_fprintf(int fd, char *format, ...)
{
	int		char_count;
	va_list	args;

	va_start(args, format);
	char_count = ft_printf_va(fd, format, args);
	va_end(args);
	return (char_count);
}
