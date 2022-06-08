/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jking-ye <jking-ye@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 19:44:42 by jking-ye          #+#    #+#             */
/*   Updated: 2022/06/08 15:33:17 by jking-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**getpwd(char **envp)
{
	int		i;
	char	*temp;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", 5) != 0)
			temp = ft_strnstr(envp[i], "PATH=", ft_strlen(envp[i]));
		i++;
	}
	return (ft_split(temp, ':'));
}

char	*checkcmds(t_data *data, char *cmd, char **envp)
{
	int		i;
	char	**temp_cmd;
	char	*temp_path;

	i = 0;
	temp_cmd = ft_split(cmd, ' ');
	temp_cmd[0] = ft_strjoin("/", temp_cmd[0]);
	while (data->paths[i])
	{
		temp_path = ft_strjoin(data->paths[i], temp_cmd[0]);
		if (access(temp_path, 0) == 0)
		{
			execve(temp_path, temp_cmd, envp);
			freearg(temp_cmd);
			return (temp_path);
		}
		free(temp_path);
		i++;
	}
	return (0);
}

void	double_dup2(int zero, int one)
{
	dup2(zero, 0);
	dup2(one, 1);
}

void	child(int i, int j, t_data *data, char **envp)
{
	int		pid;

	pid = fork();
	if (pid == 0)
	{
		if (i == 0)
			double_dup2(data->infile, data->pipe[1]);
		else if (i == data->pnums)
			double_dup2(data->pipe[i - j], data->outfile);
		else
			double_dup2(data->pipe[i - j], data->pipe[i - j + 3]);
		close_pipes(data);
		checkcmds(data, data->cmds[i], envp);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	int		i;
	int		j;

	if (argc >= 5)
	{
		init_data(&data, argc, argv, envp);
		i = 0;
		j = 2;
		while (i < argc - 3)
		{
			child(i, j, &data, envp);
			j--;
			i++;
		}
	}
	else
		printf("error input 4 args");
	return (0);
}
