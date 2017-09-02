/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 19:28:46 by sbogar            #+#    #+#             */
/*   Updated: 2017/06/17 15:55:08 by sbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void			resolve(va_list *ap, t_modulus *mod)
{
	if (mod->type == 's' || mod->type == 'S')
		print_s(ap, mod);
	else if (mod->type == 'p')
		print_p(ap, mod);
	else if (mod->type == 'd' || mod->type == 'D' || mod->type == 'i')
		print_d(ap, mod);
	else if (mod->type == 'o' || mod->type == 'O')
		print_o(ap, mod, 0);
	else if (mod->type == 'u' || mod->type == 'U')
		print_u(ap, mod);
	else if (mod->type == 'x' || mod->type == 'X')
		print_x(ap, mod, mod->type == 'x' ? 0 : 1);
	else if (mod->type)
		print_c(ap, mod);
}
