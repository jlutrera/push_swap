/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 00:22:53 by jutrera-          #+#    #+#             */
/*   Updated: 2022/12/21 00:22:53 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	where_is_max(t_list *p)
{
	int	where;
	int	max;
	int	i;

	if (!p)
		return (-1);
	max = p->index;
	i = 0;
	where = 0;
	p = p->next;
	while (p)
	{
		++i;
		if (max < p->index)
		{
			max = p->index;
			where = i;
		}	
		p = p->next;
	}
	return (where);
}

void	sort_three(t_list **a, t_list **b, int print)
{
	int	where;

	where = where_is_max(*a);
	if (where == 1)
		reverse(a, b, print, 'a');
	else if (where == 0)
		rotate(a, b, print, 'a');
	if ((*a)->content > ((*a)->next)->content)
		swap(a, b, print, 'a');
}
