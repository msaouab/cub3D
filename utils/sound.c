/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:39:48 by msaouab           #+#    #+#             */
/*   Updated: 2022/10/03 16:57:38 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	sfx_sound(t_ray *ray)
{
	char	*afplay[3];

	afplay[0] = "/usr/bin/afplay";
	afplay[1] = "./sound/the_pink_panther.mp3";
	afplay[2] = 0;
	ray->sfx.pid = fork();
	if (ray->sfx.pid == 0)
		execve(afplay[0], afplay, 0);
}
