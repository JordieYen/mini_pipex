/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jking-ye <jking-ye@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:29:24 by jking-ye          #+#    #+#             */
/*   Updated: 2022/06/08 15:32:21 by jking-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct s_data
{
	int		infile;
	int		outfile;
	int		pnums;
	char	**cmds;
	char	**exedata;
	char	**paths;
	int		*pipe;
}	t_data;

void	freearg(char **arg);
void	close_pipes(t_data *data);
char	**getpwd(char **envp);
void	createpipes(t_data *data);
void	init_data(t_data *data, int argc, char **argv, char **envp);
char	*checkcmds(t_data *data, char *cmd, char **envp);
void	double_dup2(int zero, int one);
void	child(int i, int j, t_data *data, char **envp);
int		main(int argc, char **argv, char **envp);

#endif