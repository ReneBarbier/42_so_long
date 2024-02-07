/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbier <rbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 11:26:09 by rbarbier          #+#    #+#             */
/*   Updated: 2023/09/24 13:12:57 by rbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		count;

	count = 0;
	if (lst)
		count++;
	else
		return (0);
	while (lst->next)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}
