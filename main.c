/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 01:29:49 by msaouab           #+#    #+#             */
/*   Updated: 2022/04/27 01:40:52 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"

int main(int ac, char *av[])
{
	t_data all;
	parse_map(ac, av[1], &all, 0);
	return (0);
}