/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 19:14:55 by jutrera-          #+#    #+#             */
/*   Updated: 2022/12/18 19:14:55 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/common.h"

void	ft_lstadd_front(t_list **lst, t_list *newp)
{
	if (!(*lst))
		*lst = newp;
	else
	{
		newp->next = *lst;
		*lst = newp;
	}
}
