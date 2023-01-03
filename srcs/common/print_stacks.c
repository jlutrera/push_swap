/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 19:15:37 by jutrera-          #+#    #+#             */
/*   Updated: 2022/12/18 19:15:37 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/common.h"

void	print_stack_a(t_list **p, int len)
{
	while (len > 0)
	{
		ft_printf("%s%12i%s |\n", KYEL, (*p)->content, KNRM);
		*p = (*p)->next;
		--len;
	}
}

void	print_stack_b(t_list **q, int len)
{
	while (len > 0)
	{
		ft_printf("%12s | %s%12i%s\n", "", KGRN, (*q)->content, KNRM);
		*q = (*q)->next;
		--len;
	}
}

void	print_stack_ab(t_list **p, t_list **q)
{
	while (*p && *q)
	{
		ft_printf("%s%12i%s | %s%12i%s\n", KYEL,
			(*p)->content, KNRM, KGRN, (*q)->content, KNRM);
		*q = (*q)->next;
		*p = (*p)->next;
	}
}

void	print_stacks(t_list *a, t_list *b, int print)
{
	t_list	*p;
	t_list	*q;
	int		len_a;
	int		len_b;

	if (print >= 2)
		print -= 2;
	if (print == 1)
	{
		len_a = ft_lstsize(a);
		len_b = ft_lstsize(b);
		p = a;
		q = b;
		print_stack_a(&p, len_a - len_b);
		print_stack_b(&q, len_b - len_a);
		print_stack_ab(&p, &q);
		ft_printf("------------ | ------------\n     a       |      b\n");
	}
}
