/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 17:01:34 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/11 16:00:27 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_file_time(struct stat *file)
{
	char	*file_time;
	char	*cut_time;
	char	*tmp1;
	char	*tmp2;
	time_t	current_time;

	tmp1 = NULL;
	tmp2 = NULL;
	current_time = time(NULL);
	file_time = ctime(&file->st_mtime);
	if (!file_time)
		file_time = ctime(&file->st_mtimespec.tv_sec);
	if (((current_time - (*file).st_mtime) > 15811200) ||
		((current_time - (*file).st_mtime) < -15811200))
	{
		tmp1 = ft_strsub(file_time, 4, 7);
		tmp2 = ft_strsub(file_time, 19, 5);
		cut_time = ft_strjoin(tmp1, tmp2);
		free(tmp1);
		free(tmp2);
	}
	else
		cut_time = ft_strsub(file_time, 4, 12);
	ft_printf("%s ", cut_time);
	free(cut_time);
}
