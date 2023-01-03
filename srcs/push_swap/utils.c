/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_min_up.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 00:40:33 by jutrera-          #+#    #+#             */
/*   Updated: 2022/12/28 00:40:33 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	where_is_min(t_list *p)
{
	int	where;
	int	min;
	int	i;

	if (!p)
		return (-1);
	min = p->index;
	i = 0;
	where = 0;
	p = p->next;
	while (p)
	{
		++i;
		if (min > p->index)
		{
			min = p->index;
			where = i;
		}	
		p = p->next;
	}
	return (where);
}

void	place_min_up(t_list **a, t_list **b, int print, char stack)
{
	int		len;
	int		where;
	t_list	**p;

	if (stack == 'a')
		p = a;
	else
		p = b;
	len = ft_lstsize(*p);
	where = where_is_min(*p);
	while (where > 0)
	{
		if (where < (len + 1) / 2)
			rotate(a, b, print, stack);
		else
			reverse(a, b, print, stack);
		where = where_is_min(*p);
	}
}

bool	its_max_min(t_list *p, int value)
{
	int	max;
	int	min;

	min = 2147483647;
	max = -1;
	while (p)
	{
		if (max < p->index)
			max = p->index;
		if (min > p->index)
			min = p->index;
		p = p->next;
	}
	return (value > max || value < min);
}

int	any_where(t_list *p, int value)
{
	int		j;
	bool	ok;
	int		len;
	t_list	*head;

	ok = false;
	j = 0;
	len = ft_lstsize(p);
	head = p;
	while (!ok)
	{
		ok = (p->index < value);
		p = p->next;
		if (!p)
			p = head;
		ok = (ok && (p->index > value));
		j = (j + 1) % len;
	}
	return (j);
}

void	count_followers(t_list **a, int len)
{
	t_list	*aux;
	t_list	*p;
	int		i;

	p = *a;
	while (p)
	{
		i = (p->index + 1) % len;
		p->follow = 0;
		aux = p->next;
		if (!aux)
			aux = *a;
		while (aux->index != p->index)
		{
			if (aux->index == i)
			{
				(p->follow)++;
				i = (i + 1) % len;
			}
			aux = aux->next;
			if (!aux)
				aux = *a;
		}
		p = p->next;
	}
}
