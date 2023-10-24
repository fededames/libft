/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdamian- < fdamian-@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 18:07:36 by fdamian-          #+#    #+#             */
/*   Updated: 2023/10/24 21:12:07 by fdamian-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memory_destroyer(char **splitted, int memory_counter)
{
	int	i;

	i = 0;
	while (i < memory_counter)
	{
		free(splitted[i]);
		++i;
	}
	free(splitted);
	return (NULL);
}

size_t	ft_strqty(char *s, int c)
{
	size_t	i;
	size_t	s_len;
	size_t	substr_qty;
	int		flag;

	i = 0;
	flag = 0;
	s_len = ft_strlen(s);
	substr_qty = 0;
	if (s_len == 0)
		return (substr_qty);
	while (i < s_len)
	{
		if (s[i] == (char)c)
			flag = 1;
		else if (flag == 1 && s[i] != c)
		{
			++substr_qty;
			flag = 0;
		}
		++i;
	}
	if (*s != c)
		return (substr_qty + 1);
	return (substr_qty);
}

int	ft_offset(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != (char)c && s[i] != '\0')
		++i;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	*to_split;
	char	**splitted;
	size_t	i;

	i = 0;
	to_split = (char *)s;
	splitted = (char **)ft_calloc(ft_strqty((char *)s, c) + 1, sizeof(char *));
	if (splitted == NULL)
		return (NULL);
	while (i < ft_strqty((char *)s, c))
	{
		while (*to_split == c && *to_split != '\0')
			to_split++;
		if (to_split != NULL && ft_offset(to_split, c) > 0)
		{
			splitted[i] = ft_substr(to_split, 0, ft_offset(to_split, c));
			if (splitted[i] == NULL)
				return (ft_memory_destroyer(splitted, i));
		}
		to_split = ft_strchr(to_split, c);
		i++;
	}
	return (splitted);
}
