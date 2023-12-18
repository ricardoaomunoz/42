/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riosorio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:46:24 by riosorio          #+#    #+#             */
/*   Updated: 2023/12/18 12:55:15 by rosorm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "lib/libft/libft.h"
# include "lib/printf/ft_printf.h"
# include <stdio.h>

typedef struct s_stack
{
	int		num;
	char	stack;
	char	min;
	char	max;
	int		position;
	int		effort;
	int		rev;
}	t_stack;

t_list	*ft_check_stack(char **argv, int one_param);
void	ft_error(t_list **lst, int one_param, char **argv);
void	ft_clean_str(char **c);
void	ft_swap(t_list **lst, int i);
void	ft_rotate(t_list **lst, int i);
void	ft_rev_rotate(t_list **lst, int i);
void	ft_push(t_list **lsta, t_list **lstb, int stack);
void	ft_sort(t_list **a, t_list **b);
void	ft_find_max(t_list **lst);
void	ft_find_min(t_list **lst);
void	print_list(t_list *lsta, t_list *lstb);
int		ft_is_sorted(t_list *lst, int des);
void	ft_find_min(t_list **lst);
void	ft_find_max(t_list **lst);
int		ft_get_position(t_list *lst, int des, t_list *first);
int		ft_get_min_pos(t_list *a);
void	ft_organize(t_list **a);
void	ft_move(t_list **b, int forward);
void	ft_sort_stacks(t_list **a, t_list **b, int des);
void	ft_sort_min(t_list **a, int eff);
int		ft_find_min_eff(t_list *a, int sizea);
void	ft_push_min(t_list **a, t_list **b);
void	ft_calculate_effort(t_list **a, t_list **b, int sizeb, int sizea);

#endif
