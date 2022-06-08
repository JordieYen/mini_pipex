/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits_and_frees.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jking-ye <jking-ye@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:29:18 by jking-ye          #+#    #+#             */
/*   Updated: 2022/06/08 15:33:37 by jking-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	freearg(char **arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		free(arg[i]);
		i++;
	}
	free(arg);
}

void	close_pipes(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->pnums)
	{
		close(data->pipe[i]);
		i++;
	}
}

void	createpipes(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->pnums)
	{
		pipe(data->pipe + 2 * i);
		i++;
	}
}

void	init_data(t_data *data, int argc, char **argv, char **envp)
{
	int	i;

	data->paths = getpwd(envp);
	data->infile = open(argv[1], O_RDONLY);
	data->outfile = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0000644);
	data->cmds = malloc((argc - 2) * sizeof(char *));
	data->pnums = argc - 4;
	data->pipe = malloc(2 * data->pnums * sizeof(int));
	i = 2;
	while (i < argc -1)
	{
		data->cmds[i - 2] = argv[i];
		i++;
	}
	createpipes(data);
}
