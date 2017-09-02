/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_print_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 19:35:30 by sbogar            #+#    #+#             */
/*   Updated: 2017/06/18 13:39:14 by sbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	*get_itoa(va_list *ap, t_modulus *mod, int is_upper)
{
	char	*res;

	if (!mod->length_modifier)
		res = ft_imxtoabase((int)va_arg(*ap, int), 10, is_upper);
	else if (mod->length_modifier == L)
		res = ft_imxtoabase((long)va_arg(*ap, long), 10, is_upper);
	else if (mod->length_modifier == LL)
		res = ft_imxtoabase((long long)va_arg(*ap, long long), 10, is_upper);
	else if (mod->length_modifier == H)
		res = ft_imxtoabase((short)va_arg(*ap, int), 10, is_upper);
	else if (mod->length_modifier == HH)
		res = ft_imxtoabase((char)va_arg(*ap, int), 10, is_upper);
	else if (mod->length_modifier == J)
		res = ft_imxtoabase((intmax_t)va_arg(*ap, intmax_t), 10, is_upper);
	else if (mod->length_modifier == Z)
		res = ft_imxtoabase(va_arg(*ap, size_t), 10, is_upper);
	if (mod->is_precision && mod->precision == 0 && res[0] == '0')
	{
		ft_memdel((void**)&res);
		return (ft_strdup(""));
	}
	else
		return (res);
}

static int	prepend(t_modulus *mod, char **res, int *i, int is_neg)
{
	int		prev_i;

	prev_i = *i;
	if (is_neg)
		(*res)[(*i)++] = '-';
	else if (mod->flags & PLUS && !is_neg)
		(*res)[(*i)++] = '+';
	else if (mod->flags & SPACE && !is_neg)
		(*res)[(*i)++] = ' ';
	return (*i - prev_i);
}

static void	if_hyphen(t_modulus *mod, char **res, char *tmp_str, int str_size)
{
	int		i;
	int		is_neg;
	int		tmp_str_len;
	int		cases[4];

	i = 0;
	is_neg = tmp_str[0] == '-' ? 1 : 0;
	tmp_str_len = ft_strlen(tmp_str) - is_neg;
	cases[3] = prepend(mod, res, &i, is_neg);
	cases[PREC_CASE] = (mod->is_precision && mod->precision >= tmp_str_len);
	cases[FW_CASE] = (mod->field_width == str_size);
	cases[ZERO_CASE] = ((mod->flags & ZERO) && !mod->is_precision);
	if (cases[PREC_CASE] || cases[FW_CASE])
	{
		if (mod->is_precision)
			while (i < mod->precision - tmp_str_len +
					(cases[FW_CASE] ? cases[3] : 0))
				(*res)[i++] = '0';
		ft_memcpy((*res) + i, tmp_str + is_neg, tmp_str_len);
		i += tmp_str_len;
		while (i < str_size)
			(*res)[i++] = ' ';
	}
	else
		ft_memcpy((*res) + i, tmp_str + is_neg, tmp_str_len);
}

static void	not_hyphen(t_modulus *mod, char **res, char *tmp_str, int str_size)
{
	int		i;
	int		is_neg;
	int		tmp_str_len;
	int		cases[4];

	i = 0;
	is_neg = tmp_str[0] == '-' ? 1 : 0;
	tmp_str_len = ft_strlen(tmp_str) - is_neg;
	cases[3] = prepend(mod, res, &i, is_neg);
	cases[PREC_CASE] = (mod->is_precision && mod->precision >= tmp_str_len);
	cases[FW_CASE] = (mod->field_width == str_size);
	cases[ZERO_CASE] = ((mod->flags & ZERO) && !mod->is_precision);
	i = 0;
	if (cases[PREC_CASE] || (cases[FW_CASE] && !cases[ZERO_CASE]))
		while (i < str_size - cases[3] -
				(cases[PREC_CASE] ? mod->precision : tmp_str_len))
			(*res)[i++] = ' ';
	prepend(mod, res, &i, is_neg);
	if (cases[PREC_CASE] || cases[ZERO_CASE])
		while (i < str_size - tmp_str_len + (is_neg && cases[PREC_CASE] &&
				!cases[FW_CASE] && !cases[ZERO_CASE]))
			(*res)[i++] = '0';
	ft_memcpy((*res) + i, tmp_str + is_neg, tmp_str_len);
}

int			print_d(va_list *ap, t_modulus *mod)
{
	int		str_size;
	char	*tmp_str;

	tmp_str = get_itoa(ap, mod, 0);
	str_size = new_get_str_size(mod, tmp_str);
	mod->result = ft_strnew(str_size + 1);
	if ((mod->flags & HYPHEN))
		if_hyphen(mod, &mod->result, tmp_str, str_size);
	else
		not_hyphen(mod, &mod->result, tmp_str, str_size);
	ft_memdel((void**)&tmp_str);
	return (1);
}
