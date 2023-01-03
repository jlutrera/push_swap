/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 19:15:22 by jutrera-          #+#    #+#             */
/*   Updated: 2022/12/18 19:15:22 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/common.h"

int	rotate(t_list **x, t_list **y, int print, char stack)
{
	t_list	*p;
	t_list	**aux;
	int		r;

	if (stack == 'a')
		aux = x;
	else
		aux = y;
	if (*aux && (*aux)->next)
	{
		p = *aux;
		*aux = (*aux)->next;
		p->next = NULL;
		ft_lstadd_back(aux, p);
		r = 1;
	}
	else
		r = 0;
	if (print < 2)
		ft_printf("r%c\n", stack);
	print_stacks(*x, *y, print);
	return (r);
}

int	reverse(t_list **x, t_list **y, int print, char stack)
{
	t_list	*p1;
	t_list	*p2;
	t_list	**aux;
	int		r;

	if (stack == 'a')
		aux = x;
	else
		aux = y;
	if ((*aux) && (*aux)->next)
	{
		p1 = ft_lstlast(*aux);
		p2 = *aux;
		while (p2->next != p1)
			p2 = p2->next;
		p2->next = NULL;
		ft_lstadd_front(aux, p1);
		r = 1;
	}
	else
		r = 0;
	if (print < 2)
		ft_printf("rr%c\n", stack);
	print_stacks(*x, *y, print);
	return (r);
}

int	swap(t_list **x, t_list **y, int print, char stack)
{
	t_list	**p;
	t_list	*q;
	int		r;

	if (stack == 'a')
		p = x;
	else
		p = y;
	if ((*p) && (*p)->next)
	{
		q = *p;
		*p = (*p)->next;
		q->next = (*p)->next;
		(*p)->next = q;
		r = 1;
	}
	else
		r = 0;
	if (print < 2)
		ft_printf("s%c\n", stack);
	print_stacks(*x, *y, print);
	return (r);
}

int	push(t_list **x, t_list **y, int print, char stack)
{
	t_list	*p;
	int		r;

	if (stack == 'a' && *y)
	{
		p = *y;
		*y = (*y)->next;
		p->next = NULL;
		ft_lstadd_front(x, p);
		r = 1;
	}	
	else if (stack == 'b' && *x)
	{
		p = *x;
		*x = (*x)->next;
		p->next = NULL;
		ft_lstadd_front(y, p);
		r = 1;
	}	
	else
		r = 0;
	if (print < 2)
		ft_printf("p%c\n", stack);
	print_stacks(*x, *y, print);
	return (r);
}
