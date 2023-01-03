/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 00:23:00 by jutrera-          #+#    #+#             */
/*   Updated: 2022/12/21 00:23:00 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

size_t	fix_index_stack(t_list **a)
{
	t_list	*p;
	t_list	*min;
	size_t	i;

	i = 1;
	while (true)
	{
		p = *a;
		while (p && p->index > 0)
			p = p->next;
		if (!p)
			return (i -1);
		min = p;
		p = p->next;
		while (p)
		{
			if ((min->content > p->content) && (p->index == 0))
				min = p;
			p = p->next;
		}
		min->index = i;
		++i;
	}
}

void	adjust_stack(t_list **a)
{
	t_list	*p;

	p = *a;
	while (p)
	{
		p->index = (p->index) - 1;
		p = p->next;
	}
}

void	sort_stack(t_list **a, int print)
{
	int		len;
	t_list	*b;
	bool	sorted;

	b = NULL;
	len = fix_index_stack(a);
	adjust_stack(a);
	count_followers(a, len);
	sorted = (*a)->follow == (len - 1);
	if (!sorted)
	{
		if (len < 4)
			sort_three(a, &b, print);
		else if (len < 20)
			sort_five(a, &b, print, len);
		else
			sort_hundreds(a, &b, print, len);
	}
	place_min_up(a, &b, print, 'a');
	ft_lstclear(b);
}
