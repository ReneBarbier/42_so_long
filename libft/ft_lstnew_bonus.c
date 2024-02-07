/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbier <rbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 10:58:47 by rbarbier          #+#    #+#             */
/*   Updated: 2023/11/05 18:20:12 by rbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_points	*ft_lstnew(int y, int x)
{
	t_points	*nodo;

	nodo = malloc(sizeof(t_points));
	if (!nodo)
		return (NULL);
	nodo->y = y;
	nodo->x = x;
	nodo->next = NULL;
	return (nodo);
}
