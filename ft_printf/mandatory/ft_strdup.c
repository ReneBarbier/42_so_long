/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbier <rbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 13:33:17 by rbarbier          #+#    #+#             */
/*   Updated: 2023/10/14 17:00:11 by rbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *str)
{
	int		i;
	char	*d_str;

	i = ft_strlen(str);
	d_str = (void *)malloc(sizeof(char) * (i + 1));
	if (!d_str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		d_str[i] = str[i];
		i++;
	}
	d_str[i] = '\0';
	return (d_str);
}
