/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jledesma <jledesma@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 15:25:39 by jledesma          #+#    #+#             */
/*   Updated: 2023/03/27 18:14:49 by jledesma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>

/* 
**	First 23 functions
*/

int				ft_atoi(const char *str);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t nitems, size_t size);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *ptr1, const void *ptr2, size_t num);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *str1, const void *str2, size_t n);
void			*ft_memset(void *str, int c, size_t n);
char			*ft_strchr(const char *str, int c);
char			*ft_strdup(const char *s);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t			ft_strlen(const char *str);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(const char *big, const char *light, size_t len);
char			*ft_strrchr(const char *str, int c);
int				ft_tolower(int c);
int				ft_toupper(int c);

/*
** Additionals funtions
*/

void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_itoa(int n);
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
/*** Bonus 
*/

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), \
					void (*del)(void *));
/*
** get_next_line
*/

size_t			ft_strlen_protected(const char *s);
char			*ft_substr_sizeprotected(char const *s,
					unsigned int start, size_t len);
char			*ft_strjoin_sizeprotected(char const *s1, char const *s2);
char			*get_until(char **buffer, int until);
char			*read_line(int fd, char **buffer);
char			*get_next_line(int fd);
char			*read_find(int fd, char **buffer,
					char *buf_read, size_t *by_read);

/*
** ft_printf 
*/

void			ft_putchar_i(char c, int *i);
void			ft_puthex(unsigned long long n, int *i, char *base);
void			ft_putint(unsigned int nb, int *i);
void			ft_putstr_i(char *str, int *i);
void			ft_putnbr_i(int nb, int *i);
void			ft_print_all(const char *str, int *i, va_list args, int x);
int				ft_printf(char const *str, ...);
#endif