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

#include "lem_in_tests.h"

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
	FILE	*pipe;

	result = "";
	pipe = popen(command, "r");
	ft_bzero(buffer, BUFF_LEN);
	fgets(buffer, BUFF_SIZE, pipe);
	pclose(pipe);
	if (evaluate(buffer, error))
	{
		ft_putstr("\x1B[31m FAILURE\t");
		ft_putstr(command);
		ft_putstr("\x1B[0m\n");
	}
	else
	{
		ft_putstr("\x1B[32m OK\t\t");
		ft_putstr(command);
		ft_putstr("\x1B[0m\n");
	}
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
	if ((dir = opendir(directory)) != NULL)
	{
		while ((ent = readdir(dir)) != NULL)
		{
			if (ent->d_name[0] == '.')
				continue ;
			ft_strcpy(command + start, ent->d_name);
			check_output(command, error);
		}
		closedir(dir);
	}
	else
		perror("CANNOT OPEN DIRECTORY `error_farms`");
}

int		main(void)
{
	int		status;
	char	command[COMMAND_LENGTH];

	if (access(BINARY_FILE, 1))
	{
		ft_putstr("\x1B[31m");
		ft_putstr(USAGE);
		ft_putstr("\x1B[0m\n");
		exit(0);
	}
	do_tests((char *)&command, FARMS, !RETURN_ERROR);
	do_tests((char *)&command, ERROR_FARMS, RETURN_ERROR);
	return (0);
}
