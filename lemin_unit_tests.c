/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_unit_tests.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 15:39:26 by pberge            #+#    #+#             */
/*   Updated: 2020/12/05 16:40:35 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dirent.h"
#include <stdio.h>
#include "libft.h"

# define COMMAND_LENGTH			100
# define EXECUTE_LEM_IN			"./lem-in < "
# define ERROR_FARMS			"./error_farms/"
# define FARMS					"./farms/"
# define BUFF_LEN 				128
# define RETURN_ERROR			1

int		evaluate(const char *buffer, int error)
{
	if (error)
		return (ft_strcmp(buffer, "ERROR\n") != 0 ? 1 : 0);
	else
		return (ft_strcmp(buffer, "ERROR\n") == 0 ? 1 : 0);
}

void	check_output(char *command, int error)
{
	char	buffer[BUFF_LEN];
	char	*result;
	FILE*	pipe;

	result = "";
	pipe = popen(command, "r");
	ft_bzero(buffer, BUFF_LEN);
	fgets(buffer, BUFF_SIZE, pipe);
	pclose(pipe);
	if (evaluate(buffer, error))
		printf("\x1B[31m FAILURE\t%s\n", command);
	else
		printf("\x1B[32m OK\t\t%s\n", command);
}

void	do_tests(char *command, char *directory, int error)
{
	DIR				*dir;
	struct dirent	*ent;
	int				start;

	ft_bzero(command, COMMAND_LENGTH);
	ft_strcpy(command, EXECUTE_LEM_IN);
	ft_strcat(command, directory);
	start = ft_strlen(command);
	if ((dir = opendir (directory)) != NULL)
	{
		while ((ent = readdir(dir)) != NULL)
		{
			if (ent->d_name[0] == '.')
				continue ;
			ft_strcpy(command + start, ent->d_name);
			check_output(command, error);
		}
		closedir (dir);
	}
	else
		perror ("CANNOT OPEN DIRECTORY `error_farms`");
}

int		main(void)
{
	int				status;
	char			command[COMMAND_LENGTH];

	do_tests((char *)&command, FARMS, !RETURN_ERROR);
	do_tests((char *)&command, ERROR_FARMS, RETURN_ERROR);
	return (0);
}
