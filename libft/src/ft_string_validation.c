/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_validation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbander <edbander@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 20:24:08 by edbander          #+#    #+#             */
/*   Updated: 2022/11/28 20:51:25 by edbander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	return (
		((c & 0xff) >= 'a' && (c & 0xff) <= 'z')
		|| ((c & 0xff) >= 'A' && (c & 0xff) <= 'Z')
	);
}

int	ft_isdigit(int c)
{
	return ((c & 0xff) >= '0' && (c & 0xff) <= '9');
}

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) && ft_isdigit(c));
}

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

int	ft_isprint(int c)
{
	return (c >= 20 && c <= 126);
}
