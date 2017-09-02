/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <sbogar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 14:22:40 by sbogar            #+#    #+#             */
/*   Updated: 2017/07/24 21:20:42 by sbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				*ft_memdup(const void *src, size_t len);
char				*ft_uctoabase(unsigned char nbr, int base, int is_upper);
char				*ft_uimxtoabase(uintmax_t n, uintmax_t bs, int up);
char				*ft_ustoabase(unsigned short nbr, unsigned int bs, int up);
char				*ft_ulltoabase(unsigned long long nbr, int base, int up);
char				*ft_ultoabase(unsigned long nbr, int base, int is_upper);
char				*ft_stoabase(short nbr, int base, int is_upper);
char				*ft_ctoabase(char nbr, int base, int is_upper);
char				*ft_sttoabase(size_t nbr, int base, int is_upper);
char				*ft_imxtoabase(intmax_t nbr, intmax_t base, int is_upper);
char				*ft_lltoabase(long long nbr, int base, int is_upper);
char				*ft_ltoabase(long nbr, int base, int is_upper);
char				*ft_imxtoa(intmax_t nbr);
char				*ft_strjoini(char *str1, char *str2, int to_free);
char				*ft_uitoabase(unsigned int n, int base, int is_upper);
char				*ft_utoa_hex(unsigned int nbr, int is_upper);
char				*ft_utoa(unsigned int nbr);
int					ft_printf(const char *format, ...);
int					ft_digitcounterneg(int num);
void				ft_printbits(unsigned int n);
char				*ft_itoabase(int n, int base);
double				ft_pwr(int n, int pwr);
double				ft_sqrrt(double n);
int					ft_digitcounter(int num);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
size_t				ft_strlcat(char *dst, const char *src, size_t size);
void				ft_strdel(char **as);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_lstadd(t_list **alst, t_list *n);
void				ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
void				*ft_memccpy(void *dst, const void *src, int c, size_t len);
void				*ft_memchr(const void *s, int c, size_t len);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t len);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
size_t				ft_strlen(const char *s);
int					ft_atoi(char *str);
char				*ft_itoa(int n);
void				ft_putendl_fd(char const *s, int fd);
void				ft_strclr(char *s);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strrchr(const char *s, int c);
void				ft_bzero(void *s, size_t n);
void				*ft_memalloc(size_t size);
void				ft_putnbr(int n);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				**ft_strsplit(char const *s, char c);
int					ft_isalnum(int c);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				ft_putnbr_fd(int n, int fd);
char				*ft_strcpy(char *d, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
char				*ft_strstr(const char *big, const char *little);
int					ft_isalpha(int c);
void				*ft_memset(void *b, int c, size_t n);
void				ft_putstr(char const *s);
int					ft_strequ(char const *s1, char const *s2);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
int					ft_isascii(int c);
void				ft_putchar(int c);
void				ft_putstr_fd(char const *s, int fd);
void				ft_striter(char *s, void (*f)(char *));
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strtrim(char const *s);
int					ft_isdigit(int c);
void				ft_putchar_fd(char c, int fd);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strnew(size_t size);
int					ft_tolower(int c);
int					ft_isprint(int c);
void				ft_putendl(char const *s);
char				*ft_strchr(const char *s, int c);
char				*ft_strnstr(const char *b, const char *l, size_t len);
int					ft_toupper(int c);
char				*ft_strdup(const char *s1);
void				ft_memdel(void **ap);
char				*ft_strrev(char *str);
#endif
