/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdamian- < fdamian-@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 00:01:28 by fdamian-          #+#    #+#             */
/*   Updated: 2023/10/07 17:28:14 by fdamian-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	len;
	void	*vdst;
	void	*vsrc;

	len = ft_strlen (src);
	if (!n)
		return (len);
	vdst = (void *) dst;
	vsrc = (void *) src;
	if (len + 1 < n)
		ft_memcpy (vdst, vsrc, len + 1);
	else if (len != 0)
	{
		ft_memcpy (vdst, vsrc, n - 1);
		dst[n - 1] = '\0';
	}
	return (len);
}
