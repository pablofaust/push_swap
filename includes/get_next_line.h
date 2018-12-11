/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 14:27:02 by pfaust            #+#    #+#             */
/*   Updated: 2018/12/11 14:45:34 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# define BUFF_SIZE 300

typedef struct				s_stock
{
	int						fd;
	char					*str;
	int						done;
	struct s_stock			*next;
}							t_stock;
int							get_next_line(const int fd, char **line);
#endif
