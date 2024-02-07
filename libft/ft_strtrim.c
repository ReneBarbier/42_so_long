/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbier <rbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:16:56 by rbarbier          #+#    #+#             */
/*   Updated: 2023/09/21 12:27:21 by rbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	char	*new_s;

	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	new_s = malloc(sizeof(char) * (end + 1 - start));
	if (!new_s)
		return (NULL);
	i = 0;
	while (start < end)
		new_s[i++] = s1[start++];
	new_s[i] = 0;
	return (new_s);
}
/*
#include <stdio.h>
int main ()
{
	char const s1[] = "  1   2  1  3hola que tal 3stas1  2  331 2";
	char const set[] = " 123";
	printf("%s\n", s1);
	printf("%s\n", ft_strtrim(s1, set));
}*/