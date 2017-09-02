/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 18:39:43 by sbogar            #+#    #+#             */
/*   Updated: 2017/06/18 14:27:10 by sbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			get_flags(const char *str, t_modulus **res)
{
	if (*str == '+')
		(*res)->flags |= PLUS;
	if (*str == '-')
		(*res)->flags |= HYPHEN;
	if (*str == ' ')
		(*res)->flags |= SPACE;
	if (*str == '#')
		(*res)->flags |= POUND;
	if (*str == '0')
		(*res)->flags |= ZERO;
	if (*str == '#' || *str == '0' || *str == ' ' || *str == '+' || *str == '-')
		return (1);
	else
		return (0);
}

int			get_width_specifier(const char *str, t_modulus **res)
{
	int		ret_val;

	if (*str >= '1' && *str <= '9')
	{
		ret_val = ft_atoi((char*)str);
		(*res)->field_width = ret_val;
		return (ft_digitcounter(ret_val));
	}
	return (0);
}

int			get_precision(const char *str, t_modulus **res)
{
	int		ret_val;

	if (*str == '.')
	{
		(*res)->is_precision = 1;
		ret_val = ft_atoi((char*)(str + 1));
		if (*(str + 1) >= '0' && *(str + 1) <= '9')
		{
			(*res)->precision = ret_val;
			return (ft_digitcounterneg(ret_val) + 1);
		}
		else
		{
			(*res)->precision = 0;
			return (1);
		}
	}
	return (0);
}

int			get_length(const char *str, t_modulus **res, int prev_len)
{
	if (*str == 'h')
	{
		if (*(str + 1) == 'h' &&
			((*res)->length_modifier = prev_len > HH ? prev_len : HH))
			return (2);
		else if (((*res)->length_modifier = prev_len > H ? prev_len : H))
			return (1);
	}
	else if (*str == 'l')
	{
		if (*(str + 1) == 'l' &&
			((*res)->length_modifier = prev_len > LL ? prev_len : LL))
			return (2);
		else if (((*res)->length_modifier = prev_len > L ? prev_len : L))
			return (1);
	}
	else if (*str == 'j' &&
			((*res)->length_modifier = prev_len > J ? prev_len : J))
		return (1);
	else if (*str == 'z' &&
			((*res)->length_modifier = prev_len > Z ? prev_len : Z))
		return (1);
	return (0);
}

int			get_type(const char *str, t_modulus **res)
{
	if (*str == 's' || *str == 'S' ||
		*str == 'p' ||
		*str == 'd' || *str == 'D' ||
		*str == 'i' ||
		*str == 'o' || *str == 'O' ||
		*str == 'u' || *str == 'U' ||
		*str == 'x' || *str == 'X' ||
		*str == 'c' || *str == 'C' ||
		*str == '%')
	{
		(*res)->type = *str;
		if (*str == 'U' || *str == 'O' || *str == 'D')
			(*res)->length_modifier = (*res)->length_modifier > L ?
										(*res)->length_modifier : L;
		return (1);
	}
	return (0);
}
