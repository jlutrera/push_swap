/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 19:14:45 by jutrera-          #+#    #+#             */
/*   Updated: 2022/12/18 19:14:45 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/common.h"

int	free_numbers(char **numbers, bool er)
{
	int	i;

	i = 0;
	while (numbers[i])
		free(numbers[i++]);
	free(numbers);
	if (er)
	{
		write(STDERR_FILENO, "Error\n", 6);
		return (1);
	}
	return (0);
}

int	error_intro(char **numbers)
{
	if (!numbers)
	{
		write(STDERR_FILENO, "Error\n", 6);
		return (1);
	}	
	if (!*numbers)
		return (free_numbers(numbers, true));
	return (0);
}

int	number_exist(t_list *a, int n)
{
	t_list	*p;

	p = a;
	while (p && p->content != n)
		p = p->next;
	if (!p)
		return (0);
	return (1);
}

int	create_stack(t_list **a, char **av, int ac, int c)
{
	t_list	*temp;
	char	**numbers;
	int		i;
	int		n;

	while (c < ac)
	{
		numbers = ft_split(av[c], ' ');
		if (error_intro(numbers))
			return (1);
		i = -1;
		while (numbers[++i])
		{
			if (ft_atoi(numbers[i], &n) || number_exist(*a, n))
				return (free_numbers(numbers, true));
			temp = ft_lstnew(n);
			if (!temp)
				return (1);
			ft_lstadd_back(a, temp);
		}
		c++;
		free_numbers(numbers, false);
	}
	return (0);
}
