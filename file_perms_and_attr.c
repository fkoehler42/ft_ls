/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_perms_and_attr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 11:37:20 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/08 21:13:31 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	set_owner_and_group_perms(struct stat *file, char *perms)
{
	if ((*file).st_mode & S_IRUSR)
		perms[0] = 'r';
	if ((*file).st_mode & S_IWUSR)
		perms[1] = 'w';
	if (((*file).st_mode & S_IXUSR) && ((*file).st_mode & S_ISUID))
		perms[2] = 's';
	else if ((*file).st_mode & S_ISUID)
		perms[2] = 'S';
	else if ((*file).st_mode & S_IXUSR)
		perms[2] = 'x';
	if ((*file).st_mode & S_IRGRP)
		perms[3] = 'r';
	if ((*file).st_mode & S_IWGRP)
		perms[4] = 'w';
	if (((*file).st_mode & S_IXGRP) && ((*file).st_mode & S_ISGID))
		perms[5] = 's';
	else if ((*file).st_mode & S_ISGID)
		perms[5] = 'S';
	else if ((*file).st_mode & S_IXGRP)
		perms[5] = 'x';
}

void	set_other_perms(struct stat *file, char *perms)
{
	if ((*file).st_mode & S_IROTH)
		perms[6] = 'r';
	if ((*file).st_mode & S_IWOTH)
		perms[7] = 'w';
	if (((*file).st_mode & S_IXOTH) && ((*file).st_mode & S_ISVTX))
		perms[8] = 's';
	if ((*file).st_mode & S_ISVTX)
		perms[8] = 'T';
	else if ((*file).st_mode & S_IXOTH)
		perms[8] = 'x';
}

int		print_file_attr(t_file *file)
{
	char	buf[1024];
	acl_t	*acl;

	ft_bzero(buf, 1024);
	if (!(acl = (acl_t *)malloc(sizeof(acl_t))))
	{
		perror("ft_ls : malloc");
		return (-1);
	}
	if ((listxattr(file->f_path, buf, 1023, XATTR_NOFOLLOW)) && buf[0])
	{
		ft_putchar('@');
		acl_free((void *)acl);
		return (1);
	}
	else if (((*acl) = (acl_get_file(file->f_path, ACL_TYPE_EXTENDED))) != NULL)
	{
		ft_putchar('+');
		acl_free((void *)acl);
		return (1);
	}
	return (2);
}
