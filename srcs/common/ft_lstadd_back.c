/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 19:14:50 by jutrera-          #+#    #+#             */
/*   Updated: 2022/12/18 19:14:50 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/common.h"

void	ft_lstadd_back(t_list **lst, t_list *newp)
{
	t_list	*p;

	if (!*lst)
		*lst = newp;
	else
	{
		p = ft_lstlast(*lst);
		if (!p)
			*lst = newp;
		else
			p->next = newp;
	}
}
