/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 17:45:55 by mbelaman          #+#    #+#             */
/*   Updated: 2022/07/08 15:52:06 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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
