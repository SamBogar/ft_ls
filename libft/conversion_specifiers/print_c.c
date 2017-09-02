/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 19:45:51 by sbogar            #+#    #+#             */
/*   Updated: 2017/06/17 15:58:14 by sbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int			print_c(va_list *ap, t_modulus *mod)
{
	char	tmp;
	int		str_size;
	char	*res;
	int		i;

	i = 0;
	tmp = mod->type == 'c' || mod->type == 'C' ? va_arg(*ap, int) : mod->type;
	str_size = mod->field_width > 1 ? mod->field_width : 1;
	res = (char *)ft_memalloc(sizeof(char) * (str_size + 1));
	if ((mod->flags & HYPHEN))
	{
		res[i++] = tmp;
		while (i < str_size)
			res[i++] = ' ';
	}
	else
	{
		while (i < str_size)
			res[i++] = (mod->flags & ZERO) ? '0' : ' ';
		res[i - 1] = tmp;
	}
	if (tmp == 0)
		mod->char_is_null = 1;
	mod->result = res;
	return (0);
}
