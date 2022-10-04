/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:17:44 by msaouab           #+#    #+#             */
/*   Updated: 2022/09/23 16:17:47 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*ft_strrchr(const char *s, int c)
{
	int		index;
	char	ch;

	index = 0;
	ch = (char)c;
	while (s[index])
		index++;
	while (s[index] != ch && index > 0)
		index--;
	if (s[index] == ch)
		return ((char *)&s[index]);
	else
		return (NULL);
}
