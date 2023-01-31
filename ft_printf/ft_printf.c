/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgalan <antgalan@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 01:09:54 by edbander          #+#    #+#             */
/*   Updated: 2023/01/31 17:37:59 by antgalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

static int	_ft_parse_args(const char *str, va_list args);
static int	_ft_printf_arg(char type, va_list args);
static char	*_ft_printf_arg_hex(char type, va_list args);
static int	_ft_putchar(char type, va_list args);

int	ft_printf(const char *s, ...)
{
	int		count;
	va_list	args;

	count = 0;
	if (!s || *s == '\0')
		return (count);
	va_start(args, s);
	count = _ft_parse_args(s, args);
	va_end(args);
	return (count);
}

static int	_ft_parse_args(const char *str, va_list args)
{
	int	count;
	int	i;

	count = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			count += _ft_printf_arg(str[++i], args);
			continue ;
		}		
		ft_putchar_fd(str[i], 1);
		count += 1;
	}
	return (count);
}

static int	_ft_printf_arg(char type, va_list args)
{
	char	*ptr;
	int		slen;

	if (type == 'c' || type == '%')
		return (_ft_putchar(type, args));
	else if (type == 's')
	{
		ptr = va_arg(args, char *);
		if (!ptr)
			ptr = "(null)";
	}
	else if (type == 'd' || type == 'i')
		ptr = ft_itoa((int)va_arg(args, int));
	else if (type == 'u')
		ptr = ft_itoa_unsinged_int((unsigned int)va_arg(args, unsigned int));
	else if (type == 'x' || type == 'X' || type == 'p')
		ptr = _ft_printf_arg_hex(type, args);
	ft_putstr_fd(ptr, 1);
	slen = ft_strlen(ptr);
	return (slen);
}

static char	*_ft_printf_arg_hex(char type, va_list args)
{
	char				*format;
	char				*ptr;
	unsigned long long	longarg;

	format = "";
	if (type == 'p')
	{
		format = "0x";
		longarg = va_arg(args, unsigned long long);
		if (!longarg)
			return ("0x0");
		return (ft_itoahex_unsigned_long(
				longarg,
				format,
				type - 'X'));
	}
	return (ft_itoahex_unsigned_long(
			(unsigned long long) va_arg(args, unsigned int),
			format,
			type - 'X'));
}

static int	_ft_putchar(char type, va_list args)
{
	if (type == '%')
		ft_putchar_fd('%', 1);
	else
		ft_putchar_fd(va_arg(args, int), 1);
	return (1);
}
