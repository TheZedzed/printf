/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_llist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azeraoul <azeraoul@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 23:26:13 by azeraoul          #+#    #+#             */
/*   Updated: 2021/02/12 19:24:15 by azeraoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_param		*last_param(t_param *head)
{
	t_param	*curr;
	t_param	*prev;

	prev = NULL;
	curr = head;
	while (curr)
	{
		prev = curr;
		curr = curr->next;
	}
	return (prev);
}

void		push_back(t_param **head, t_param *el)
{
	t_param	*last;

	last = NULL;
	if (head)
	{
		if (!(*head))
			(*head) = el;
		else
		{
			last = last_param((*head));
			last->next = el;
		}
	}
}

t_param		*curr_elem(t_param **head)
{
	t_param	*new;

	if (!(new = malloc(sizeof(t_param))))
		return (NULL);
	ft_memset(new, 0, sizeof(t_param));
	push_back(head, new);
	return (new);
}

void		final_free(char *buffer, t_param *head)
{
	t_param	*tmp;

	free(buffer);
	while (head)
	{
		tmp = head->next;
		free(head->value);
		free(head);
		head = tmp;
	}
	head = NULL;
}
