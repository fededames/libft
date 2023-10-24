/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdamian- < fdamian-@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:48:47 by fdamian-          #+#    #+#             */
/*   Updated: 2023/10/24 21:10:41 by fdamian-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_errors(char const *s, unsigned int start, size_t len)
{
	if (!s)
		return (1);
	else if (start > ft_strlen(s) || len == 0)
		return (2);
	else if (((size_t)start + len) > ft_strlen(s))
		return (3);
	else
		return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	int		catch_error;

	ptr = NULL;
	catch_error = ft_check_errors(s, start, len);
	if (catch_error == 1)
		return (NULL);
	else if (catch_error == 2)
		return (ft_strdup(""));
	else if (catch_error == 3)
		len = ft_strlen(s) - (size_t)start;
	while (start > 0 && *s)
	{
		s++;
		--start;
	}
	ptr = ft_calloc((len + 1), sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, s, len + 1);
	return (ptr);
}
