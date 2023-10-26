/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riosorio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:20:30 by riosorio          #+#    #+#             */
/*   Updated: 2023/10/25 21:32:06 by riosorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

# define PLUS_FLAG 0b1       //1
# define SPACE_FLAG 0b10     //2
# define HASH_FLAG 0b100     //3
# define ZERO_FLAG 0b1000    //4
# define MINUS_FLAG 0b10000  //5
# define NUM_FLAG 0b100000   //6
# define DOT_FLAG 0b1000000  //7

typedef struct word_p
{
	char	*str;
	size_t	str_sz;
}	t_word_p;

int			ft_printf(const char *c, ...);
t_word_p	check_convertion(const char *c, va_list args);
int			ft_putnbr_base(void *nbr, char *str, char c);
int			ft_putchar(char c);
int			ft_putstr(char *c, size_t len);
t_word_p	check_for_flag(char **c, va_list args);
char		*ft_get_lnb(unsigned long int num, char *base, char *str, int sz);
int			numlen(unsigned long int num, int base);
void		ft_bzero(void *s, size_t n);
int			ft_get_len(char c, char *str);
int			ft_aux_printf(char **c, va_list args);
int			ft_isspace(char s);
char		*move_point(char *s);
void		clean_all_p(char*str, int sz);
void		insert_beginning(t_word_p *str, char new_s, size_t new_len, int s);
void		insert_end(t_word_p *str, char new_s, size_t new_len);
void		cut_string(char **str, size_t numChars);
size_t		to_move(char *s);
void		ft_hash_flag(t_word_p *str, char c);
void		ft_space_flag(t_word_p *str, char c);
void		ft_plus_flag(t_word_p *str, char c);
void		ft_minus_flag(t_word_p *str, size_t lenght);
void		ft_no_flag(t_word_p *str, size_t lenght);
void		ft_zero_flag(t_word_p *str, char c, size_t lenght);
void		ft_dot_flag(t_word_p *str, char c, size_t pres);
int			ft_just_zero(char *s);
void		num_flag(size_t *flags, int *length, char *c, size_t *i);
void		dot_flag(size_t *flags, int *pres, char *c, size_t *i);
void		plus_flag(size_t *flags);
size_t		zero_minus_flag(size_t *flags, size_t flag, int *length, char *c);
t_word_p	ft_check_string(char *s);
t_word_p	ft_check_other(int c);
t_word_p	ft_check_int(va_list args);
t_word_p	ft_check_ln(va_list args, char *base);
t_word_p	ft_check_un(va_list args, char *base);

#endif
