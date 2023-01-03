/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 19:07:58 by jutrera-          #+#    #+#             */
/*   Updated: 2022/12/18 19:07:58 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void	exit_error(t_list *a, t_list *b)
{
	write(2, "Error\n", 6);
	ft_lstclear(a);
	ft_lstclear(b);
	exit(EXIT_FAILURE);
}

void	init(char *rule, t_list **a, t_list **b, int print)
{
	int		i;

	i = 0;
	while (i < 4)
		rule[i++] = 0;
	print_stacks(*a, *b, print);
}

void	execute_action(char *name, t_list **a, t_list **b, int print)
{
	if (ft_strcmp(name, "sa") || ft_strcmp(name, "sb"))
		swap(a, b, print, name[1]);
	else if (ft_strcmp(name, "pa") || ft_strcmp(name, "pb"))
		push(a, b, print, name[1]);
	else if (ft_strcmp(name, "ra") || ft_strcmp(name, "rb"))
		rotate(a, b, print, name[1]);
	else if (ft_strcmp(name, "rr"))
	{
		rotate(a, b, 2, 'a');
		rotate(a, b, print, 'b');
	}
	else if (ft_strcmp(name, "rra") || ft_strcmp(name, "rrb"))
		reverse(a, b, print, name[2]);
	else if (ft_strcmp(name, "rrr"))
	{
		reverse(a, b, 2, 'a');
		reverse(a, b, print, 'b');
	}
	else
		exit_error(*a, *b);
}

void	read_rules(t_list **a, t_list **b, int print)
{
	char	*rule;
	int		i;
	int		pi;
	bool	out;

	i = 0;
	out = false;
	rule = (char *)malloc(4 * sizeof(char));
	init(rule, a, b, print);
	while (i < 4 && !out)
	{
		pi = i;
		i += read(STDIN_FILENO, rule + i, 1);
		out = (rule[0] == '\n' || rule[0] == 0);
		if (!out && (rule[pi] == '\n' || rule[pi] == 0))
		{
			rule[pi] = 0;
			execute_action(rule, a, b, print);
			i = 0;
			init(rule, a, b, 0);
		}
	}
	free(rule);
	if (i == 4)
		exit_error(*a, *b);
}
