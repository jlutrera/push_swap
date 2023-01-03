/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 19:14:38 by jutrera-          #+#    #+#             */
/*   Updated: 2022/12/18 19:14:38 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/common.h"

int	check_order(t_list *a)
{
	t_list	*p;
	t_list	*q;

	p = a;
	q = p->next;
	while (q)
	{
		if (p->content > q->content)
			return (-1);
		p = q;
		q = q->next;
	}
	return (0);
}
