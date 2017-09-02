# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbogar <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/28 15:52:30 by sbogar            #+#    #+#              #
#    Updated: 2017/06/18 14:33:21 by sbogar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Werror -Wextra 

SRCS += ft_atoi.c		ft_isprint.c		ft_putchar_fd.c\
		ft_putstr_fd.c	ft_strequ.c			ft_strncat.c\
		ft_strsplit.c	ft_itoa.c			ft_strncmp.c\
		ft_putendl.c	ft_strcat.c			ft_striter.c\
		ft_strncpy.c	ft_strstr.c			ft_isalnum.c\
		ft_memalloc.c	ft_putendl_fd.c		ft_strchr.c\
		ft_strjoin.c	ft_strnequ.c		ft_strsub.c\
		ft_isalpha.c	ft_putnbr.c			ft_bzero.c\
		ft_strclr.c		ft_strlen.c			ft_strnew.c\
		ft_strtrim.c	ft_isascii.c		ft_memset.c\
		ft_putnbr_fd.c	ft_strcmp.c			ft_strmap.c\
		ft_strnstr.c	ft_tolower.c		ft_isdigit.c\
	    ft_putchar.c	ft_putstr.c			ft_strcpy.c\
		ft_strmapi.c	ft_strrchr.c		ft_toupper.c\
		ft_memccpy.c	ft_memchr.c			ft_memcmp.c\
		ft_memcpy.c		ft_memmove.c		ft_memset.c\
		ft_strdup.c		ft_lstadd.c			ft_lstdel.c\
		ft_lstdelone.c	ft_lstiter.c		ft_lstnew.c\
		ft_memdel.c		ft_striteri.c		ft_strdel.c\
		ft_strlcat.c	ft_lstmap.c			ft_digitcounter.c\
		ft_sqrrt.c		ft_itoabase.c		ft_printbits.c\
		ft_strrev.c		ft_digitcounterneg.c\
		ft_utoa.c		ft_uitoabase.c		ft_strjoini.c\
		ft_imxtoa.c		ft_ltoabase.c		ft_stoabase.c\
		ft_ctoabase.c	ft_sttoabase.c		ft_imxtoabase.c\
		ft_lltoabase.c	ft_ultoabase.c		ft_ulltoabase.c\
		ft_ustoabase.c	ft_uctoabase.c		ft_uimxtoabase.c

BIN = $(SRCS:.c=.o)

HEADER = libft.h

all: $(NAME)

$(NAME): $(SRCS:.c=.o)
	ar rc $(NAME) $(SRCS:.c=.o)
	ranlib $(NAME)

%.o:%.c
	gcc $(FLAGS) -I $(HEADER) -c $^ -o $@

clean:
	@rm -f $(BIN)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
