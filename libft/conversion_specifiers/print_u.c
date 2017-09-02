/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 15:18:13 by sbogar            #+#    #+#             */
/*   Updated: 2017/06/17 20:45:32 by sbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int			populate_res(char **res, int size, t_modulus *mod, char *s)
{
	int				i;
	int				arr_pos;

	arr_pos = new_get_arr_pos(mod, size, s);
	if (!s[0])
		arr_pos--;
	if ((mod->flags & HYPHEN))
		i = arr_pos;
	else
		i = mod->is_precision ? size - mod->precision : 0;
	while (i < size)
		(*res)[i++] = (mod->flags & ZERO) && !(mod->flags & HYPHEN) ? '0' : ' ';
	i = ((mod->flags & HYPHEN)) ? 0 : size - mod->precision;
	if (mod->precision > (int)ft_strlen(s))
		while (((mod->flags & HYPHEN)) ? i < mod->precision : i < size - 1)
			(*res)[i++] = '0';
	return (new_handle_flags(mod, size, s));
}

static void			get_result(t_modulus *mod, char *tmp_str, char **res)
{
	int				str_size;
	int				arr_pos;
	int				i;

	str_size = new_get_str_size(mod, tmp_str);
	arr_pos = new_get_arr_pos(mod, str_size, tmp_str);
	if (!tmp_str[0])
		arr_pos--;
	i = 0;
	while (i <= arr_pos)
		(*res)[i++] = ' ';
	if ((mod->flags & ZERO))
		while (i < arr_pos)
			(*res)[i++] = '0';
	i = populate_res(res, str_size, mod, tmp_str);
	ft_memcpy((*res) + i, tmp_str, ft_strlen(tmp_str));
}

int					print_u(va_list *ap, t_modulus *mod)
{
	int				str_size;
	char			*tmp_str;
	char			*res;
	int				i;

	i = 0;
	tmp_str = new_get_itoa_shit(ap, mod, 0);
	str_size = new_get_str_size(mod, tmp_str) + 1;
	res = (char*)malloc(sizeof(char) * str_size);
	ft_bzero(res, str_size + 1);
	get_result(mod, tmp_str, &res);
	mod->result = ft_strdup(res);
	ft_memdel((void**)&res);
	ft_memdel((void**)&tmp_str);
	return (0);
}
