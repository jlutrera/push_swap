/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 19:15:01 by jutrera-          #+#    #+#             */
/*   Updated: 2022/12/18 19:15:01 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/common.h"

void	ft_lstclear(t_list *lst)
{
	t_list	*p;

	if (lst)
	{
		p = lst;
		while (p)
		{
			p = (lst)->next;
			free(lst);
			lst = p;
		}
	}
}
