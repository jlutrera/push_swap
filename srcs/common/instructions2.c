/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 22:25:45 by jutrera-          #+#    #+#             */
/*   Updated: 2023/01/14 22:25:45 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/common.h"

int	rr(t_list **x, t_list **y, int print)
{
	rotate(x, y, 2, 'a');
	rotate(x, y, 2, 'b');
	if (print < 2)
		ft_printf("rr\n");
	print_stacks(*x, *y, print);
	return (1);
}

int	rrr(t_list **x, t_list **y, int print)
{
	reverse(x, y, 2, 'a');
	reverse(x, y, 2, 'b');
	if (print < 2)
		ft_printf("rrr\n");
	print_stacks(*x, *y, print);
	return (1);
}
