# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbogar <sbogar@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/28 15:52:30 by sbogar            #+#    #+#              #
#    Updated: 2017/09/05 15:06:06 by sbogar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

FLAGS = -Wall -Werror -Wextra

FILES = ft_ls.c\
		parse_args.c\
		get_files.c\
		linked_lists.c\
		print_out_list.c\
		sort_list.c\
		simple_checks.c\
		print_thing.c\
		long_format.c\
		long_format_sup.c\
		comparisons.c\
		loop_through_args.c

SRCS = $(addprefix srcs/,$(FILES))

OBJS = $(addprefix objs/,$(FILES:.c=.o))

LIB = libft/libft.a

HEADER = ft_ls.h

all: $(NAME)

$(NAME): objs/ $(LIB) $(OBJS)
	@gcc -o $(NAME) $(FLAGS) $(OBJS) -L./libft/ -lft
	@echo "ft_ls has been made!"

objs/%.o: src/%.c
	@gcc $(FLAGS) -c $^ -o $@

objs/:
	@mkdir objs

libft/libft.a:
	make -C libft/

clean:
	rm -rf objs
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all
