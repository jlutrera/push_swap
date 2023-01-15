/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 23:55:52 by jutrera-          #+#    #+#             */
/*   Updated: 2023/01/14 23:55:52 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	move_a(t_list **a, t_list **b, int print, int x)
{
	while (x > 0)
	{
		rotate(a, b, print, 'a');
		x--;
	}	
	while (x < 0)
	{
		reverse(a, b, print, 'a');
		x++;
	}
}

void	move_b(t_list **a, t_list **b, int print, int y)
{
	while (y > 0)
	{
		rotate(a, b, print, 'b');
		y--;
	}	
	while (y < 0)
	{
		reverse(a, b, print, 'b');
		y++;
	}
}
