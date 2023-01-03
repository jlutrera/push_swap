/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 00:22:47 by jutrera-          #+#    #+#             */
/*   Updated: 2022/12/21 00:22:47 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_five(t_list **a, t_list **b, int print, int len)
{
	place_min_up(a, b, print, 'a');
	while (len > 3)
	{
		push(a, b, print, 'b');
		--len;
		if (len > 3)
			place_min_up(a, b, print, 'a');
	}
	if (len > 1)
		sort_three(a, b, print);
	while (*b)
		push(a, b, print, 'a');
}
