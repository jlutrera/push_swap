/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_followers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 23:59:12 by jutrera-          #+#    #+#             */
/*   Updated: 2022/12/27 23:59:12 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	found_candidates(t_list *p, int *limits, int *w)
{
	int	aux;

	aux = 0;
	while (p && (p->follow || p->index < limits[0] || p->index >= limits[1]))
	{
		p = p->next;
		aux++;
	}
	w[0] = aux;
	w[1] = w[0];
	while (p)
	{
		if (p->follow == 0 && p->index >= limits[0] && p->index < limits[1])
			w[1] = aux;
		aux++;
		p = p->next;
	}
}

void	get_limits(bool ini, int *limits, int len)
{
	int	chunk;

	chunk = 2 * len / 7;
	if (len > 200)
		chunk = len / 6;
	if (ini)
	{
		limits[0] = 0;
		limits[1] = chunk;
	}
	else
	{
		limits[0] = limits[1];
		limits[1] += chunk;
		if (limits[1] > len)
			limits[1] = len;
	}
}

void	push_nofollowers_chunking(t_list **a, t_list **b, int print, int len)
{
	int	w[2];
	int	limits[2];
	int	l;

	l = len;
	get_limits(1, limits, len);
	while (limits[0] < limits[1])
	{
		w[0] = 0;
		while (w[0] != l)
		{
			found_candidates(*a, limits, w);
			if (w[0] < l)
			{
				if (w[0] < l - w[1])
					while (w[0]-- > 0)
						rotate(a, b, print, 'a');
				else
					while (l > w[1]++)
						reverse(a, b, print, 'a');
				l -= push(a, b, print, 'b');
			}		
		}
		get_limits(0, limits, len);
	}
}

void	mark_followers(t_list **a, int len, int head)
{
	t_list	*aux;
	t_list	*p;
	int		i;

	p = *a;
	while (p->index != head)
		p = p->next;
	i = (p->index + 1) % len;
	p->follow = 1;
	aux = p->next;
	if (!aux)
		aux = *a;
	while (aux->index != p->index)
	{
		if (aux->index == i)
		{
			aux->follow = 1;
			i = (i + 1) % len;
		}
		else
			aux->follow = 0;
		aux = aux->next;
		if (!aux)
			aux = *a;
	}
}

void	manage_followers(t_list **a, t_list **b, int print, int len)
{
	int		head;
	t_list	*p;
	t_list	*h;

	h = *a;
	if (h)
		p = h->next;
	while (p)
	{
		if ((p->follow > h->follow)
			|| (p->follow == h->follow && p->index < h->index))
			h = p;
		p = p->next;
	}
	head = h->index;
	mark_followers(a, len, head);
	push_nofollowers_chunking(a, b, print, len);
}
