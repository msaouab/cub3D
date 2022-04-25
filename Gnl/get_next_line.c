/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 10:31:21 by msaouab           #+#    #+#             */
/*   Updated: 2021/12/04 12:09:11 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_check_ln(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

void	assign(char **dest, char *src, char *to_free)
{
	*dest = src;
	free(to_free);
}

char	*ft_read(char *save, char *s_read, int fd)
{
	int		n_read;

	n_read = 1;
	*s_read = 0;
	while (n_read != 0 && (ft_check_ln(s_read) == -1))
	{
		n_read = read(fd, s_read, BUFFER_SIZE);
		if (n_read <= 0)
		{
			free(s_read);
			if (save && !*save)
				assign(&save, NULL, save);
			return (save);
		}
		s_read[n_read] = '\0';
		assign(&save, ft_strjoin(save, s_read), save);
	}
	free (s_read);
	return (save);
}

char	*ft_ret_ft(char **saved)
{
	char	*line;
	int		i;

	i = 0;
	while ((*saved)[i] != '\n' && (*saved)[i] != '\0')
		i++;
	if ((*saved)[i] == '\n')
	{
		line = ft_substr((*saved), 0, i + 1);
		assign(saved, ft_strdup((*saved) + i + 1), *saved);
		return (line);
	}
	if ((*saved)[i] == '\0')
	{
		assign(&line, ft_substr((*saved), 0, ft_strlen(*saved)), *saved);
		*saved = NULL;
		return (line);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*s_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	s_read = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!s_read || read(fd, NULL, 0) < 0)
	{
		free(s_read);
		return (NULL);
	}
	save = ft_read(save, s_read, fd);
	if (save == NULL)
		return (NULL);
	return (ft_ret_ft(&save));
}
