/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iportill <iportill@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:25:18 by iportill          #+#    #+#             */
/*   Updated: 2023/03/08 17:04:43 by iportill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t			len_src;
	size_t			len_dst;
	unsigned int	point;

	len_src = ft_strlen(src);
	if (!dstsize)
		return (len_src);
	len_dst = ft_strlen(dst);
	if (dstsize < len_dst)
		return (len_src + dstsize);
	point = 0;
	while (src[point] && point < dstsize - len_dst)
	{
		dst[point + len_dst] = src[point];
		point++;
	}
	if (point == dstsize - len_dst && dstsize > len_dst)
		point--;
	dst[point + len_dst] = '\0';
	return (len_src + len_dst);
}
/*
int	main(void)
{

	char	src[20] = "hola";
	char	dst[20] = "paco";

	printf("%zu\n", ft_strlcat(dst, src, 8));
	printf("%s\n", dst);
}
*/