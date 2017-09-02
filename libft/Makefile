# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbogar <sbogar@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/28 15:52:30 by sbogar            #+#    #+#              #
#    Updated: 2017/07/24 21:20:40 by sbogar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Werror -Wextra

SRCS += libft/ft_atoi.c			libft/ft_isprint.c			libft/ft_putchar_fd.c\
		libft/ft_putstr_fd.c	libft/ft_strequ.c			libft/ft_strncat.c\
		libft/ft_strsplit.c		libft/ft_itoa.c				libft/ft_strncmp.c\
		libft/ft_putendl.c		libft/ft_strcat.c			libft/ft_striter.c\
		libft/ft_strncpy.c		libft/ft_strstr.c			libft/ft_isalnum.c\
		libft/ft_memalloc.c		libft/ft_putendl_fd.c		libft/ft_strchr.c\
		libft/ft_strjoin.c		libft/ft_strnequ.c			libft/ft_strsub.c\
		libft/ft_isalpha.c		libft/ft_putnbr.c			libft/ft_bzero.c\
		libft/ft_strclr.c		libft/ft_strlen.c			libft/ft_strnew.c\
		libft/ft_strtrim.c		libft/ft_isascii.c			libft/ft_memset.c\
		libft/ft_putnbr_fd.c	libft/ft_strcmp.c			libft/ft_strmap.c\
		libft/ft_strnstr.c		libft/ft_tolower.c			libft/ft_isdigit.c\
	    libft/ft_putchar.c		libft/ft_putstr.c			libft/ft_strcpy.c\
		libft/ft_strmapi.c		libft/ft_strrchr.c			libft/ft_toupper.c\
		libft/ft_memccpy.c		libft/ft_memchr.c			libft/ft_memcmp.c\
		libft/ft_memcpy.c		libft/ft_memmove.c			libft/ft_memset.c\
		libft/ft_strdup.c		libft/ft_lstadd.c			libft/ft_lstdel.c\
		libft/ft_lstdelone.c	libft/ft_lstiter.c			libft/ft_lstnew.c\
		libft/ft_memdel.c		libft/ft_striteri.c			libft/ft_strdel.c\
		libft/ft_strlcat.c		libft/ft_lstmap.c			libft/ft_digitcounter.c\
		libft/ft_sqrrt.c		libft/ft_itoabase.c			libft/ft_printbits.c\
		libft/ft_strrev.c		libft/ft_digitcounterneg.c\
		libft/ft_utoa.c			libft/ft_utoa_hex.c			libft/ft_uitoabase.c\
		libft/ft_strjoini.c		libft/ft_imxtoa.c			libft/ft_ltoabase.c\
		libft/ft_stoabase.c		libft/ft_ctoabase.c			libft/ft_sttoabase.c\
		libft/ft_imxtoabase.c	libft/ft_lltoabase.c		libft/ft_ultoabase.c\
		libft/ft_ulltoabase.c	libft/ft_ustoabase.c		libft/ft_uctoabase.c\
		libft/ft_uimxtoabase.c libft/ft_memdup.c\
		ft_printf.c				get_stuff.c					get_modulos.c\
		resolve.c				get_str_size.c				get_arr_pos.c\
		handle_flags.c			get_itoa_stuff.c\
		conversion_specifiers/tmp_print_d.c					conversion_specifiers/print_u.c\
		conversion_specifiers/print_x.c						conversion_specifiers/print_o.c\
		conversion_specifiers/print_s.c						conversion_specifiers/print_c.c\
		conversion_specifiers/print_p.c

BIN = $(SRCS:.c=.o)

HEADER = libft/libft.h

all: $(NAME)

$(NAME): $(SRCS:.c=.o)
	@ar rc $(NAME) $(SRCS:.c=.o)
	@ranlib $(NAME)

%.o:%.c
	@gcc $(FLAGS) -I $(HEADER) -I ft_printf.h -c $^ -o $@

clean:
	@rm -f $(BIN)

fclean: clean
	rm -f $(NAME)

re: fclean all
