/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantremb <dantremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 10:27:51 by marvin            #+#    #+#             */
/*   Updated: 2022/03/03 11:57:14 by dantremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char *ft_strncat(char *dest, char *src, unsigned int nb)
{
	int i;
	int ii;

	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	ii = 0;
	while (src[ii] != '\0' && ii < nb)
	{
		dest[i + ii] = src[ii];
		ii++;
	}
	dest[i + ii] = '\0';
	return (dest);
}

int		main(void)
{
	char	dest[50] = "bonjour";
	char	*src = "les amis";
	unsigned int	size = 2;
	printf("%s\n", ft_strncat(dest, src, size));
}