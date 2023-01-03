/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 19:05:42 by jutrera-          #+#    #+#             */
/*   Updated: 2022/12/18 19:05:42 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include "../libft/include/libft.h"

# define KNRM  "\x1B[0m"
# define KRED  "\x1B[31m"
# define KGRN  "\x1B[32m"
# define KYEL  "\x1B[33m"
# define KBLU  "\x1B[34m"
# define KMAG  "\x1B[35m"
# define KCYN  "\x1B[36m"
# define KWHT  "\x1B[37m"

typedef struct s_list
{
	int				content;
	int				index;
	int				follow;
	int				instr;
	struct s_list	*next;
}	t_list;

int		check_order(t_list *a);
void	print_stacks(t_list *a, t_list *b, int print);
int		create_stack(t_list **a, char **av, int ac, int c);
void	ft_lstadd_back(t_list **lst, t_list *newp);
void	ft_lstadd_front(t_list **lst, t_list *newp);
void	ft_lstclear(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int content);
int		ft_lstsize(t_list *lst);
//instructions.c
int		rotate(t_list **x, t_list **y, int print, char stack);
int		reverse(t_list **x, t_list **y, int print, char stack);
int		swap(t_list **x, t_list **y, int print, char stack);
int		push(t_list **x, t_list **y, int print, char stack);

#endif
