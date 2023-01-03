/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 19:05:51 by jutrera-          #+#    #+#             */
/*   Updated: 2022/12/18 19:05:51 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "common.h"

void	sort_stack(t_list **a, int print);
void	sort_three(t_list **a, t_list **b, int print);
void	sort_five(t_list **a, t_list **b, int print, int len);
void	sort_hundreds(t_list **a, t_list **b, int print, int len);
void	manage_stackb(t_list **a, t_list **b, int print);
void	manage_followers(t_list **a, t_list **b, int print, int len);
//utils.c
void	place_min_up(t_list **a, t_list **b, int print, char stack);
void	count_followers(t_list **a, int len);
int		where_is_min(t_list *p);
bool	its_max_min(t_list *p, int value);
int		any_where(t_list *p, int value);

#endif
