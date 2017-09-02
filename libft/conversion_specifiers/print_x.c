/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 15:18:13 by sbogar            #+#    #+#             */
/*   Updated: 2017/06/18 12:19:10 by sbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int			pop_res(char **res, int size, t_modulus *mod, char *tmps)
{
	int				i;
	int				str_len;

	str_len = (int)ft_strlen(tmps);
	if ((mod->flags & HYPHEN))
		i = new_get_arr_pos(mod, size, tmps);
	else
		i = mod->is_precision ? size - mod->precision : 0;
	tmps[str_len] = 0;
	while (i < size)
		(*res)[i++] = (mod->flags & ZERO) && !(mod->flags & HYPHEN) ? '0' : ' ';
	tmps[str_len] = 0;
	i = ((mod->flags & HYPHEN)) ? 0 : size - mod->precision;
	tmps[str_len] = 0;
	if (mod->precision > (int)ft_strlen(tmps))
		while (((mod->flags & HYPHEN)) ? i < mod->precision : i < size - 1)
			(*res)[i++] = '0';
	tmps[str_len] = 0;
	(*res)[i] = 0;
	tmps[str_len] = 0;
	return (new_handle_flags(mod, size, tmps));
}

static char			*get_result(t_modulus *mod, char *tmps)
{
	int				str_size;
	int				str_len;
	int				i;
	int				arr_pos;
	char			*res;

	str_size = new_get_str_size(mod, tmps);
	res = (char*)malloc(sizeof(char) * (str_size + 1));
	ft_bzero(res, str_size + 2);
	arr_pos = new_get_arr_pos(mod, str_size, tmps);
	i = 0;
	str_len = ft_strlen(tmps);
	if ((mod->flags & ZERO))
		while (i <= arr_pos)
			res[i++] = '0';
	else
		while (i < arr_pos)
			res[i++] = ' ';
	i = pop_res(&res, str_size, mod, tmps);
	if (mod->is_precision && mod->precision == 0 &&
			tmps[0] == '\0' && !mod->field_width)
		res[0] = 0;
	else
		ft_memcpy(res + (i < 0 ? 0 : i), tmps, ft_strlen(tmps));
	return (res);
}

static void			ox_if_hyphen(char **res, int up, int i)
{
	char			*vtmp;

	vtmp = ft_strnew(ft_strlen(*res) + 1);
	vtmp[0] = '0';
	vtmp[1] = up ? 'X' : 'x';
	while ((*res)[i] != ' ' && (*res)[i])
	{
		vtmp[i + 2] = (*res)[i];
		i++;
	}
	while (i + 2 < (int)ft_strlen(*res))
	{
		vtmp[i + 2] = (*res)[i];
		i++;
	}
	vtmp[i + 2] = 0;
	ft_memdel((void**)res);
	*res = ft_strdup(vtmp);
	ft_memdel((void**)&vtmp);
}

static void			prepend_ox(char **res, t_modulus *mod, int up, char *tmps)
{
	int				arr_pos;
	int				i;
	int				str_size;

	str_size = new_get_str_size(mod, tmps);
	arr_pos = new_get_arr_pos(mod, str_size, tmps);
	i = 0;
	if (tmps[0] == '0')
		return ;
	if (!(mod->flags & HYPHEN))
	{
		if (mod->precision >= (int)ft_strlen(tmps) + 1)
			arr_pos--;
		(*res)[arr_pos - 2 > 0 ? arr_pos - 2 : 0] = '0';
		(*res)[arr_pos - 1 > 0 ? arr_pos - 1 : 1] = up ? 'X' : 'x';
	}
	else
		ox_if_hyphen(res, up, i);
}

int					print_x(va_list *ap, t_modulus *mod, int up)
{
	int				str_size;
	char			*tmps;
	char			*res;
	int				i;

	i = 0;
	tmps = new_get_itoa_shit(ap, mod, up);
	str_size = new_get_str_size(mod, tmps);
	res = get_result(mod, tmps);
	if (!(mod->is_precision && mod->precision == 0 &&
				tmps[0] != '0' && !mod->field_width))
		if ((mod->flags & POUND))
			prepend_ox(&res, mod, up, tmps);
	mod->result = ft_strdup(res);
	ft_memdel((void**)&res);
	ft_memdel((void**)&tmps);
	return (0);
}
