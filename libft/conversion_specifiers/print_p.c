/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 18:24:36 by sbogar            #+#    #+#             */
/*   Updated: 2017/06/17 20:20:36 by sbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int			get_arr_pos(t_modulus *mod, int str_size, char *tmp_str)
{
	if ((mod->field_width == str_size && (mod->flags & ZERO)) ||
			mod->precision + 2 == str_size)
		return (0);
	else
	{
		if (mod->precision > (int)ft_strlen(tmp_str))
			return (str_size - mod->precision - 2);
		return (str_size - ft_strlen(tmp_str) - 2);
	}
}

static char			*if_hyphen(char *tmp_str, int str_size, t_modulus *mod)
{
	char			*res;
	int				str_len;
	int				i;
	int				j;

	i = 0;
	j = 0;
	res = (char *)malloc(sizeof(char) * (str_size + 1));
	str_len = (int)ft_strlen(tmp_str);
	res[i++] = '0';
	res[i++] = 'x';
	if (mod->precision > str_len + 2)
		while (i - 2 < (mod->precision - str_len))
			res[i++] = '0';
	while (tmp_str[j])
		res[i++] = tmp_str[j++];
	while (i < str_size)
		res[i++] = ' ';
	res[i] = 0;
	return (res);
}

static char			*handle_flags(char *tmp_str, t_modulus *mod, int str_size)
{
	char			*res;
	int				i;
	int				j;

	j = 0;
	i = 0;
	if ((mod->flags & HYPHEN))
		res = if_hyphen(tmp_str, str_size, mod);
	else
	{
		res = (char *)malloc(sizeof(char) * (str_size + 1));
		while (i < get_arr_pos(mod, str_size, tmp_str))
			res[i++] = ' ';
		res[i++] = '0';
		res[i++] = 'x';
		j = i;
		while (i < str_size)
			res[i++] = '0';
		i = str_size - (int)ft_strlen(tmp_str);
		j = 0;
		while (tmp_str[j])
			res[i++] = tmp_str[j++];
		res[i] = 0;
	}
	return (res);
}

int					print_p(va_list *ap, t_modulus *mod)
{
	char			*tmp_str;
	int				str_size;
	unsigned long	tmp_long;

	tmp_long = va_arg(*ap, unsigned long);
	tmp_str = ft_ultoabase(tmp_long, 16, 0);
	if (tmp_str[0] == '0' &&
			mod->is_precision &&
			!mod->precision &&
			!mod->field_width)
	{
		free(tmp_str);
		tmp_str = ft_strdup("");
	}
	str_size = new_get_str_size(mod, tmp_str);
	mod->result = handle_flags(tmp_str, mod, str_size);
	ft_memdel((void**)&tmp_str);
	return (0);
}
