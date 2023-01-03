/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 19:11:38 by jutrera-          #+#    #+#             */
/*   Updated: 2022/12/18 19:11:38 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	int		print;
	int		error;

	if (argc < 2)
		return (1);
	print = ft_strcmp(argv[1], "-v");
	if (argc < 3 && print)
		return (1);
	a = NULL;
	error = create_stack(&a, argv, argc, print + 1);
	if (error)
	{
		ft_lstclear(a);
		return (1);
	}
	print_stacks(a, NULL, print);
	if (check_order(a) == -1)
		sort_stack(&a, print);
	ft_lstclear(a);
	return (0);
}
