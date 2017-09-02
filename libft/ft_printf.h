/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <sbogar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 18:53:12 by sbogar            #+#    #+#             */
/*   Updated: 2017/07/24 20:01:10 by sbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

enum				e_cases{
	ZERO_CASE = 0,
	PREC_CASE = 1,
	FW_CASE = 2,
};

enum				e_length_mods{
	H = 1,
	HH = 2,
	L = 4,
	LL = 8,
	Z = 16,
	J = 32
};

enum				e_printf_flags{
	ZERO = 1,
	HYPHEN = 2,
	PLUS = 4,
	POUND = 8,
	SPACE = 16
};

typedef struct		s_modulus{
	int				arg_num;
	int				pos;

	unsigned char	flags;
	int				field_width;
	int				precision;
	int				is_precision;
	int				length_modifier;
	char			type;
	int				char_is_null;

	char			*result;
	int				cs_width;
}					t_modulus;

char				*new_get_itoa_shit(va_list *ap, t_modulus *m, int upper);
int					new_handle_flags(t_modulus *m, int strlen, char *tmp);
int					new_get_arr_pos(t_modulus *m, int strlen, char *tmp);
int					new_get_str_size(t_modulus *mod, char *tmp_str);
int					get_ismodulo(const char *format, t_modulus **res);
int					ft_printf(const char *format, ...);
void				resolve(va_list *ap, t_modulus *mod);
void				print_modulos(t_modulus *mod);
int					get_parameter(const char *format, t_modulus **res);
int					get_flags(const char *format, t_modulus **res);
int					get_width_specifier(const char *format, t_modulus **res);
int					get_precision(const char *format, t_modulus **res);
int					get_length(const char *f, t_modulus **res, int prev_len);
int					get_type(const char *format, t_modulus **res);
void				instantiate_modulus(t_modulus **res);
t_modulus			*define_modulus(const char *format, va_list *ap);
t_modulus			**get_modulos(const char *format);
int					get_modulus_count(const char *format);

int					print_d(va_list *ap, t_modulus *mod);
int					print_d_or_i(va_list *ap, t_modulus *mod);
int					print_p(va_list *ap, t_modulus *mod);
int					print_c(va_list *ap, t_modulus *mod);
int					print_u(va_list *ap, t_modulus *mod);
int					print_x(va_list *ap, t_modulus *mod, int up_low);
int					print_o(va_list *ap, t_modulus *mod, int up_low);
int					print_s(va_list *ap, t_modulus *mod);

#endif
