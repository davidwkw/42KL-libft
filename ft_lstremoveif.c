/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremoveif.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwang <kwang@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 00:14:40 by kwang             #+#    #+#             */
/*   Updated: 2022/09/28 00:14:41 by kwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
						void (*free_fct)(void *))
{
	t_list	*curr;
	t_list	*next;
	t_list	*prev;

	curr = *begin_list;
	prev = NULL;
	while (curr)
	{
		next = curr->next;
		if ((*cmp)(curr->content, data_ref) == 0)
		{
			(*free_fct)(curr->content);
			free(curr);
			if (prev)
				prev->next = next;
			else
				*begin_list = next;
		}
		else
			prev = curr;
		curr = next;
	}
}
