/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riosorio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:08:19 by riosorio          #+#    #+#             */
/*   Updated: 2023/12/18 14:52:26 by rosorm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_overflow(char *num, int *error)
{
	int		data;
	int		j;
	char	*tmp;

	while (*num == '0' && *(num + 1))
		num++;
	data = ft_atoi(num);
	j = ft_strlen(num);
	tmp = ft_itoa(data);
	if (ft_strncmp(num, tmp, j))
	{
		free(tmp);
		*error = 1;
		return (-1);
	}
	free(tmp);
	return (data);
}

int	check_num(char *num, int *error)
{
	int		j;
	int		data;

	j = 0;
	while (num[j])
	{
		if (num[j] == '-' || num[j] == '+')
			j++;
		if (!ft_isdigit(num[j]))
		{
			*error = 1;
			return (-1);
		}
		j++;
	}
	data = check_overflow(num, error);
	return (data);
}

void	add_to_stack(t_list **lst_a, int num, int *error)
{
	t_stack	*data;
	t_list	*tmp;
	t_list	*a;
 
	data = (t_stack *)malloc(sizeof(t_stack));
	if (!data)
		ft_error(lst_a, 0, NULL);
	data->num = num;
	data->min = '0';
	data->max = '0';
	data->stack = 'a';
	data->rev = 0;
	a = ft_lstnew(data);
	tmp = *lst_a;
	while (tmp && (((t_stack *)(tmp->content))->num != num))
		tmp = tmp->next;
	if (tmp)
	{
		free(data);
		free(a);
		*error = 1;
		return ;
	}
	ft_lstadd_back(lst_a, a);
}

t_list	*ft_check_stack(char **argv, int one_param)
{
	int		i;
	int		num;
	int		error;
	t_list	*lst_a;

	i = 1 - one_param;
	lst_a = NULL;
	error = 0;
	while (argv[i])
	{
		num = check_num(argv[i], &error);
		if (error)
			ft_error(&lst_a, one_param, argv);
		add_to_stack(&lst_a, num, &error);
		if (error)
			ft_error(&lst_a, one_param, argv);
		i++;
	}
	return (lst_a);
}
