/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_stackb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 00:39:55 by jutrera-          #+#    #+#             */
/*   Updated: 2022/12/28 00:39:55 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	bestoption(t_list *b)
{
	t_list	*q;
	t_list	*r;

	q = b;
	if (!q)
		return (-1);
	r = q;
	q = q->next;
	while (q)
	{
		if (q->instr < r->instr)
			r = q;
		q = q->next;
	}
	return (r->index);
}

int	put_bestoption(t_list **a, t_list **b, int print, int choosed)
{
	t_list	*p;
	int		i;
	int		len;

	p = *b;
	i = 0;
	len = ft_lstsize(*b);
	while (p && p->index != choosed)
	{
		p = p->next;
		i++;
	}	
	if (len - i < i)
		return (i - len);
	else
		return (i);
}

int	prepare_push(t_list **a, t_list **b, int print, int choosed)
{
	int		j;
	int		len;

	len = ft_lstsize(*a);
	if (its_max_min(*a, choosed))
		j = where_is_min(*a);
	else
		j = any_where(*a, choosed);
	if (len - j < j)
		return (j - len);
	else
		return (j);
}

void	manage_stackb(t_list **a, t_list **b, int print)
{
	int	choosed;
	int	x;
	int	y;

	choosed = bestoption(*b);
	y = put_bestoption(a, b, print, choosed);
	x = prepare_push(a, b, print, choosed);
	while (x > 0 && y > 0)
	{
		rr(a, b, print);
		x--;
		y--;
	}
	while (x < 0 && y < 0)
	{
		rrr(a, b, print);
		y++;
		x++;
	}
	move_a(a, b, print, x);
	move_b(a, b, print, y);
	push(a, b, print, 'a');
}
