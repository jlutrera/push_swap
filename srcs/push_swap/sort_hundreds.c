/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_onehundred.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 22:53:01 by jutrera-          #+#    #+#             */
/*   Updated: 2022/12/27 22:53:01 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_min(int x, int y)
{
	if (x < y)
		return (x);
	return (y);
}

int	max_f(t_list *p)
{
	int	r;

	r = 0;
	while (p)
	{
		if (r < p->follow)
			r = p->follow;
		p = p->next;
	}
	return (r);
}

void	count_rules(t_list **a, t_list **b)
{
	t_list	*q;
	int		i;
	int		j;

	q = *b;
	i = 0;
	while (q)
	{
		if (its_max_min(*a, q->index))
			j = where_is_min(*a);
		else
			j = any_where(*a, q->index);
		q->instr = ft_min(j, ft_lstsize(*a) - j)
			+ ft_min(i, ft_lstsize(*b) - i);
		q = q->next;
		i++;
	}
}

void	sort_hundreds(t_list **a, t_list **b, int print, int len)
{
	bool	sorted;
	int		f1;
	int		f2;

	count_followers(a, len);
	f1 = max_f(*a);
	swap(a, b, 2, 'a');
	count_followers(a, len);
	f2 = max_f(*a);
	swap(a, b, 2, 'a');
	if (f1 < f2)
		swap(a, b, print, 'a');
	sorted = (*a)->follow == (len - 1);
	if (!sorted)
	{
		manage_followers(a, b, print, len);
		while (*b)
		{		
			count_rules(a, b);
			manage_stackb(a, b, print);
		}
	}
}
