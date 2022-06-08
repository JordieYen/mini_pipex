/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jking-ye <jking-ye@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 15:42:07 by jking-ye          #+#    #+#             */
/*   Updated: 2022/06/02 20:01:44 by jking-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *hay, const char *needle, unsigned int n)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (*needle == 0)
		return (hay);
	while (hay[i] != '\0' && i < n)
	{
		j = 0;
		while ((hay[i + j] == needle[j]) && (i + j) < n)
		{
			if (needle[j + 1] == '\0')
				return (hay + i + j + 1);
			j++;
		}
		i++;
	}
	return (0);
}
