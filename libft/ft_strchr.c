/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbier <rbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:28:05 by rbarbier          #+#    #+#             */
/*   Updated: 2023/09/20 13:03:15 by rbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (s[size])
		size++;
	while (s[i] != (char)c)
	{
		if (i == size)
			return (NULL);
		else
			i++;
	}
	return ((char *)&s[i]);
}
/*
#include <stdio.h>
int main()
{
	const char str[] = "teste";

	printf("%s\n", ft_strchr(str, 'e'));
	printf("%s\n", strchr(str, 'e'));
}*/