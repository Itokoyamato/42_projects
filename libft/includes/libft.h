/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 12:52:05 by llaporte          #+#    #+#             */
/*   Updated: 2018/01/30 15:28:50 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# define BUFF_SIZE 4096
# define BASE16 "0123456789ABCDEF"

# define PCS dt->precisions[dt->cur_pcs]
# define LM dt->length_mod[dt->cur_pcs]
# define ML dt->minimum_lenght[dt->cur_pcs]
# define CI dt->str[dt->i + 1]
# define FH dt->flag_hash[dt->cur_pcs]
# define FZ dt->flag_zero[dt->cur_pcs]
# define FM dt->flag_minu[dt->cur_pcs]
# define FP dt->flag_plus[dt->cur_pcs]
# define FS dt->flag_spac[dt->cur_pcs]

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>
# include <inttypes.h>
# include "ft_printf.h"

typedef unsigned char	t_byte;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_data
{
	int		fd;
	int		i;
	char	*buf;
}					t_data;

int					ft_abs(intmax_t i);
int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
wchar_t				ft_ctowc(char c);
int					ft_gnl(const int fd, char **line);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isstrdigit(char *str);
int					ft_islower(int c);
int					ft_isprint(int c);
int					ft_isspace(int c);
int					ft_isupper(int c);
char				*ft_itoa(int n);
char				*ft_itoa_base(intmax_t value, int base);
char				*ft_iutoa_base(intmax_t value, int base);
void				ft_lstadd(t_list **alst, t_list *newlst);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
int					ft_nbdigit(int n);
int					ft_nbrlen(intmax_t value, int base);
int					ft_negnull(intmax_t i);
double				ft_pow(double x, double y);
void				ft_putchar(unsigned char c);
void				ft_putchar_fd(unsigned char c, int fd);
void				ft_putendl(char *str);
void				ft_putendl_fd(char *str, int fd);
void				ft_putnbr(int nbr);
void				ft_putnbr_fd(int nbr, int fd);
void				ft_putstr(char const *str);
void				ft_putstr_fd(char const *str, int fd);
void				ft_putwchar(wchar_t c);
void				ft_putwchar_fd(wchar_t c, int fd);
void				ft_putwstr(wchar_t const *str);
void				ft_putwstr_fd(wchar_t const *str, int fd);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
void				ft_strdel(char **as);
char				*ft_strdup(char *src);
int					ft_strequ(char const *s1, char const *s2);
char				*ft_strerase(char const *s1, int where, int lenght);
char				*ft_strinsert(char const *s1, char const *s2, int where);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *str);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *s1, const char *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *big,
	const char *little, size_t len);
char				*ft_strrchr(const char *s, int c);
char				**ft_strsplit(char const *s, char c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtoupper(char *str);
char				*ft_strtolower(char *str);
wchar_t				*ft_strtowstr(char *str);
char				*ft_strtrim(char const *s);
int					ft_tolower(int c);
int					ft_toupper(int c);
char				*ft_uitoa_base(uintmax_t value, int base);
int					ft_unbrlen(uintmax_t value, int base);
size_t				ft_wcharsize(wchar_t const wchar);
wchar_t				*ft_wstrinsert(wchar_t const *s1,
	wchar_t const *s2, int where);
wchar_t				*ft_wstrjoin(wchar_t const *s1, wchar_t const *s2);
size_t				ft_wstrlen(wchar_t const *str);
wchar_t				*ft_wstrsub(wchar_t const *s,
	unsigned int start, size_t len);

#endif
