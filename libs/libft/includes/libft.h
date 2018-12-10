/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:30:07 by pfaust            #+#    #+#             */
/*   Updated: 2018/12/03 14:55:15 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# define ABS(Value) (Value < 0 ? -Value : Value)


typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_strlen(const char *str);
char				*ft_strdup(const char *s);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_dir_strncpy(char *src, int n, char c);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
size_t				ft_strlcat(char *dest, const char *src, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *meule, const char *aiguille);
char				*ft_strnstr(const char *meule, const char *aiguille, \
					size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t len);
void				ft_memdel(void **ap);
void				*ft_strnew(size_t len);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned intm, char *));
char				*ft_strmap(const char *s, char (*f)(char));
char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));
int					ft_strequ(const char *s1, const char *s2);
int					ft_strnequ(const char *s1, const char *s2, size_t n);
char				*ft_strsub(const char *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(const char *s);
char				**ft_strsplit(const char *s, char c);
char				*ft_itoa(int n);
char				*ft_itoa_ll(long long n);
char				*ft_itoa_base(int n, int base);
char				*ft_itoa_base_uint(unsigned int n, int base, char a);
char				*ft_itoa_base_ll(long long n, unsigned int base);
char				*ft_itoa_base_ull(unsigned long long n, unsigned int base);
char				*ft_itoa_db(double n, int precision);
void				ft_putchar(char c);
void				ft_putstr(const char *s);
void				ft_putbinstr(const char *s);
void				ft_putendl(const char *s);
void				ft_putnbr(int c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(const char *c, int fd);
void				ft_putendl_fd(const char *s, int fd);
void				ft_putnbr_fd(int c, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
unsigned long long	ft_pow(unsigned int len);
unsigned long long	ft_int_pow(unsigned long long n);
size_t				ft_wordlen(const char *s, int i, char c);
size_t				ft_nbwords(const char *s, char c);
int					ft_never_negative(int nb);
int					ft_nb_entiers(double n);
void				ft_print_bits(unsigned char octet);
void				ft_binary_long(long n);
char				*ft_truncate(char *str, int n, char c);
char	*ft_cpyalpha(char *str);
#endif
