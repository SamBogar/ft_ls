/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 14:22:22 by sbogar            #+#    #+#             */
/*   Updated: 2017/06/17 16:27:23 by sbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** This function addresses the effects of each possible flag
*/

static int		initialize(t_modulus *mod, int pos, int str_size, char **res)
{
	int i;

	i = 0;
	if ((mod->flags & ZERO))
		while (i <= pos)
			(*res)[i++] = '0';
	else
		while (i <= pos)
			(*res)[i++] = ' ';
	if ((mod->flags & HYPHEN))
		return (pos);
	else
		return (mod->is_precision ? str_size - mod->precision : 0);
}

static void		get_result(t_modulus *mod, char *tmp_str, char **res)
{
	int		str_size;
	int		arr_pos;
	int		i;

	str_size = new_get_str_size(mod, tmp_str);
	arr_pos = new_get_arr_pos(mod, str_size, tmp_str);
	i = initialize(mod, arr_pos, str_size, res);
	while (i < str_size)
		(*res)[i++] = (mod->flags & ZERO) && !(mod->flags & HYPHEN) ? '0' : ' ';
	i = ((mod->flags & HYPHEN)) ? 0 : str_size - mod->precision;
	if (mod->precision > (int)ft_strlen(tmp_str))
		while (((mod->flags & HYPHEN)) ? i < mod->precision : i < str_size - 1)
			(*res)[i++] = '0';
	i = new_handle_flags(mod, str_size, tmp_str);
	if (mod->is_precision && mod->precision == 0 && tmp_str[0] == ' ')
	{
		if (mod->field_width)
			(*res)[i++] = ' ';
		(*res)[i] = 0;
	}
	else
		ft_memcpy((*res) + i + (i < 0 ? 1 : 0), tmp_str, ft_strlen(tmp_str));
}

int				print_o(va_list *ap, t_modulus *mod, int is_upper)
{
	int				str_size;
	char			*tmp_str;
	char			*res;
	int				i;

	i = 0;
	tmp_str = new_get_itoa_shit(ap, mod, is_upper);
	if (mod->is_precision && mod->precision == 0 && tmp_str[0] == '0')
	{
		ft_memdel((void**)&tmp_str);
		if ((mod->flags & POUND))
			tmp_str = ft_strdup("0");
		else
			tmp_str = ft_strdup(" ");
	}
	if ((mod->flags & POUND) && tmp_str[0] != '0')
		tmp_str = ft_strjoini("0", tmp_str, 2);
	str_size = new_get_str_size(mod, tmp_str);
	res = (char*)malloc(sizeof(char) * str_size);
	ft_bzero(res, str_size + 1);
	get_result(mod, tmp_str, &res);
	mod->result = ft_strdup(res);
	ft_memdel((void**)&res);
	ft_memdel((void**)&tmp_str);
	return (0);
}
