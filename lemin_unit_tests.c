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

# define COMMAND_LENGTH	100
# define EXECUTE_LEM_IN	"./lem-in < error_farms/"
# define BUFF_LEN 128

void	check_output(char *command)
{
	char	buffer[BUFF_LEN];
	char	*result;
	FILE*	pipe;

	result = "";
	pipe = popen(command, "r");
	ft_bzero(buffer, BUFF_LEN);
	fgets(buffer, BUFF_SIZE, pipe);
	pclose(pipe);
	if (ft_strcmp(buffer, "ERROR\n") != 0)
		printf("\x1B[31m FAILURE\t%s\n", command);
	else
		printf("\x1B[32m OK\t\t%s\n", command);
}

int		main(void)
{
	DIR				*dir;
	struct dirent	*ent;
	int				status;
	char			command[COMMAND_LENGTH];
	int				start;

	start = ft_strlen(EXECUTE_LEM_IN);
	ft_bzero(&command, COMMAND_LENGTH);
	ft_strcpy((char *)&command, EXECUTE_LEM_IN);
	if ((dir = opendir ("./error_farms")) != NULL)
	{
		while ((ent = readdir(dir)) != NULL)
		{
			if (ent->d_name[0] == '.')
				continue ;
			ft_strcpy(&(command[start]), ent->d_name);
			check_output((char *)&command);
		}
		closedir (dir);
	}
	else
		perror ("CANNOT OPEN DIRECTORY `error_farms`");
	return (0);
}
