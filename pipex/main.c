// gcc -Wextra -Werror main.c ../libftprintf/libftprintf.a && ./a.out ls

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <errno.h>
#include <fcntl.h>
#include "../libftprintf/ft_printf.h"
#include <sys/types.h>
#include <sys/wait.h>

char **commands(char **argv)
{
	char *arr1;
	char *joined;
	char **split;

	arr1 = malloc(sizeof(argv[2] + 2));
	ft_strlcpy(arr1, argv[2], (int)ft_strlen(argv[2]));
	arr1[ft_strlen(argv[2]) - 1] = ' ';
	arr1[ft_strlen(argv[2])] = '\0';
	joined = ft_strjoin(arr1, argv[3]);
	split = ft_split(joined, ' ');

	free(arr1);
	arr1 = NULL;
	free(joined);
	joined = NULL;
	return (split);
}

char	**set_paths(char **cmds, char *envp_index)
{
	char	*str;
	char	**path_envp;
	char	*path1;
	char **both_paths;
	int found_first;
	int j;
	int	first;

	first = 0;
	j = 0;
	path_envp = ft_split(envp_index, ':');
	while (path_envp[j])
	{
		if (access(ft_strjoin(path_envp[j], ft_strjoin("/", cmds[0])), R_OK) \
			== 0 || access(ft_strjoin(path_envp[j], ft_strjoin("/", cmds[2])), \
			R_OK) == 0)
		{
			// To do: free path arrays!
			if (first == 0)
			{
				path1 = ft_strjoin(ft_strjoin(path_envp[j], ft_strjoin("/", cmds[0])), " ");
					printf("path1: %s\n", path1);
				first++;
			}
			else if (first == 1)
			{
				printf("path2: %s\n", ft_strjoin(path_envp[j],	ft_strjoin("/", cmds[2])));
				return (ft_split(ft_strjoin(path1, ft_strjoin(path_envp[j],	ft_strjoin("/", cmds[2]))), ' '));
			}
		}
		j++;
	}
}

char	**get_path1(char **cmds, char **envp)
{
	int		i;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH", ft_strlen(envp[i])))
			return (set_paths(cmds, envp[i]));
		i++;
	}
}

void execute(char **cmds, char **envp, char **path)
{
	char *options[3] = {NULL, NULL, NULL};
	char *arr[50];

	if (ft_strncmp(cmds[0], "ls", ft_strlen("ls")) == 0)
	{
		options[0] = cmds[0];
		if (cmds[1])
			options[1] = cmds[1];
		if (execve(path[0], options, envp) == -1)
		{
			perror(ft_strjoin(path[0], ft_strjoin("/", cmds[1])));
			exit(1);
		}
		else
			execve(path[0], options, envp);
	}
}


int main(int argc, char **argv, char **envp)
{
	char **paths;
	char **cmds;
	char *buffer[400];
	pid_t pid1;
	int pipefd[2];
	int reader;

	cmds = commands(argv);
	if (!envp)
	{
		ft_printf("could not find envp!\n");
		exit(1);
	}



	paths = get_path1(cmds, envp); // gets full path of cmd1 program
	printf("%s\n%s\n", paths[0], paths[1]);
	if (pipe(pipefd) == -1) // Create a pipe and error check
		return (1);



	pipefd[0] = open(argv[1], O_RDONLY);
	pipefd[1] = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 744);
	if (pipefd[0] < 0 || pipefd[1] < 0)
		return (-1);


	pid1 = fork();
	if (pid1 == -1)
	{
		perror("fork function error\n"); // will also print errno
		exit(1);
	}
	else if (pid1 == 0)
	{
		//cmd1 will be executed by the child and save in pipfd[0]
		if(dup2(pipefd[0], STDIN_FILENO) < 0) //infile becomes stdin
		{
			perror("dup2\n");
			exit(1);
		}
		if(dup2(pipefd[1], STDOUT_FILENO) < 0) //infile becomes stdin
		{
			perror("dup2\n");
			exit(1);
		}
		close(pipefd[0]);
		close(pipefd[1]);						// Done writing, close pipe's write end.
		//execute(cmds, envp, paths); // child proces is replaced by execve output
	}

	int pid2 = fork();
	if (pid2 = 0 - 1)
		return (3);
	if (pid2 == 0)
	{
		//execute2(cmds, envp, path1);
		//use execve again
		// use file2 and cm2 on stdin?
		close(pipefd[0]);
		close(pipefd[1]);
	}

	// PARENT
	waitpid(pid1, NULL, 0); // Wait for child.
	// waitpid(pid2, NULL, 0); // Wait for child.
	//execute cmd2 in parent

	reader = read(pipefd[0], buffer, 5);//SET RIGHT AMOUNT OF BYTES
	if (reader == -1)
		return (3);
	buffer[reader] = '\0';



	close(pipefd[0]);					// Read everything, close pipe's read end.
	close(pipefd[1]);					// Nothing to write, close pipe's write end.
	printf("%s\"\n", buffer); // prints output
	return (0);
}

// test evey folder using access

// for (char **env = envp; *env != 0; env++)
//   {
//     char *thisEnv = *env;
//     printf("%s\n", thisEnv);
//   }
//   return 0;
// PATH
// if ( == -1)
// 	write(1, "error\n", 6);
// ft_strnstr
