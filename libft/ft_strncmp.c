/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbier <rbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:43:50 by rbarbier          #+#    #+#             */
/*   Updated: 2023/09/18 13:49:03 by rbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n - 1)
		++i;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*
#include <string.h>
#include <stdio.h>
int main ()
{
	char s1[] = "\x12\xff\x65\x12\xbd\xde\xad";
	char s2[] = "\x12\x02";
	printf("%d\n", ft_strncmp(s1, s2, 2));
	printf("%d", strncmp(s1, s2, 2));
}*/
