/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 10:31:23 by msaouab           #+#    #+#             */
/*   Updated: 2021/12/04 15:45:46 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

size_t	ft_strlen(char *s);
char	*ft_strdup(char *s);
int		ft_check_ln(char *s);
char	*get_next_line(int fd);
char	*ft_ret_ft(char **saved);
char	*ft_read(char *save, char *s_read, int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);

#endif
