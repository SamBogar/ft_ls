/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 16:33:40 by sbogar            #+#    #+#             */
/*   Updated: 2017/06/17 20:21:25 by sbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	get_strsize(t_modulus *mod, char *tmp_str)
{
	int		str_size;

	str_size = (int)ft_strlen(tmp_str);
	if (mod->is_precision && mod->precision < str_size)
		str_size = mod->precision;
	str_size = mod->field_width > str_size ? mod->field_width : str_size;
	return (str_size);
}

static void	ft_is_hyphen(t_modulus *mod, char *tmp_str, int i, int str_size)
{
	if (mod->is_precision && mod->precision < (int)ft_strlen(tmp_str))
	{
		while (i < mod->precision)
		{
			(mod->result)[i] = tmp_str[i];
			i++;
		}
		while (i < str_size)
		{
			(mod->result)[i] = ' ';
			i++;
		}
		return ;
	}
	while (tmp_str[i])
	{
		(mod->result)[i] = tmp_str[i];
		i++;
	}
	while (i < str_size)
	{
		(mod->result)[i] = ' ';
		i++;
	}
}

static void	ft_not_hyphen(t_modulus *mod, char *tmp_str, int i, int str_size)
{
	int		j;

	j = 0;
	if (mod->is_precision && mod->precision < (int)ft_strlen(tmp_str))
	{
		i = str_size - mod->precision;
		while (i < str_size)
		{
			(mod->result)[i] = tmp_str[j];
			j++;
			i++;
		}
		i = 0;
		while (i < str_size - mod->precision)
		{
			(mod->result)[i] = (mod->flags & ZERO) ? '0' : ' ';
			i++;
		}
		return ;
	}
	while (i < str_size - (int)ft_strlen(tmp_str))
		(mod->result)[i++] = (mod->flags & ZERO) ? '0' : ' ';
	while (i < str_size)
		(mod->result)[i++] = tmp_str[j++];
	(mod->result)[i] = 0;
}

int			print_s(va_list *ap, t_modulus *mod)
{
	char	*tmp_str;
	int		str_size;
	int		i;

	i = 0;
	tmp_str = va_arg(*ap, char *);
	if (!tmp_str)
		tmp_str = "(null)";
	str_size = get_strsize(mod, tmp_str);
	mod->result = (char*)malloc(sizeof(char) * (str_size + 1));
	(mod->result)[str_size] = 0;
	if (mod->flags & HYPHEN)
		ft_is_hyphen(mod, tmp_str, i, str_size);
	else
		ft_not_hyphen(mod, tmp_str, i, str_size);
	(mod->result)[str_size] = 0;
	return (0);
}
