/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 19:07:49 by jutrera-          #+#    #+#             */
/*   Updated: 2022/12/18 19:07:49 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	bool	print;

	if (argc < 2)
		return (0);
	print = ft_strcmp(argv[1], "-v");
	if (argc < 3 && print)
		return (1);
	a = NULL;
	b = NULL;
	if (create_stack(&a, argv, argc, print + 1))
	{
		ft_lstclear(a);
		return (1);
	}
	read_rules(&a, &b, print + 2);
	if (check_order(a) != -1 && !b)
		ft_printf("%sOK%s\n", KGRN, KNRM);
	else
		ft_printf("%sKO%s\n", KRED, KNRM);
	ft_lstclear(a);
	ft_lstclear(b);
	return (0);
}
