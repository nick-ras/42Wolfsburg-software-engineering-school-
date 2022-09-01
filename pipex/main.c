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

char	*get_path(char **argv, char **envp)
{
	int		i;
	int		j;
	char	**paths;

	i = 0;
	j = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH", ft_strlen(envp[i])))
		{
			paths = ft_split(envp[i], ':');
			while (paths[j])
			{
				if (access(ft_strjoin(paths[j], ft_strjoin("/", argv[1])), \
				R_OK) == 0)
					return (ft_strjoin(paths[j], ft_strjoin("/", argv[1])));
				j++;
			}
		}
		i++;
	}
}

void	execute(char **argv, char **envp,char *path)
{
	char *options[3] = {NULL, NULL, NULL};
	char *arr[50];

	if (ft_strncmp(argv[1], "ls", ft_strlen("ls")) == 0)
	{
		options[0] = argv[1];
		if (argv[2])
			options[1] = argv[2];
		if (execve(path, options, envp) == -1)
		{
			perror(ft_strjoin(path, ft_strjoin("/", argv[1])));
			exit(1);
		}
		else
			execve(path, options, envp);
	}
}

int	main(int argc, char **argv, char **envp)
{
	char	*path;
	pid_t	pid1;
	int     ends[2];
	int     reader;
	char	secret[400];
	char    buffer[400];

	if (!envp)
	{
		ft_printf("could not find envp!\n");
		exit(1);
	}
	path = get_path(argv, envp);
	// Create a pipe and error check
	if (pipe(ends) == -1)
			return (1);
	// Create a child process
	pid1 = fork();
	if (pid1 == -1)
	{
		perror("pid1 is -1");
		exit(1);
	}
	else if (pid1 == 0)
	{
		// Child process
		dup2 (ends[1], STDOUT_FILENO);
		close(ends[0]);
		close(ends[1]);  // Done writing, close pipe's write end.
		execute(argv, envp, path); //child proces is replaced by execve output
	}

	int pid2 = fork();
	if (pid2 =0 -1)
		return (3);
	if(pid2 == 0)
	{
		dup2 (ends[1], STDIN_FILENO);
		close(ends[0]); 
		close(ends[1]); 
	}

	
	// Parent process	
	waitpid(pid1, NULL, 0); // Wait for child.
	waitpid(pid2, NULL, 0); // Wait for child.
	//printf("Parent: I received my child. What is its secret ?\n");
	reader = read(ends[0], buffer, 400);
	close(ends[0]); // Read everything, close pipe's read end.
	if (reader == -1)
			return (3);
	buffer[reader] = '\0';
	close(ends[1]); // Nothing to write, close pipe's write end.
	printf("%s\"\n", buffer);
	
	return (0);
}

// test evey folder using access

// for (char **env = envp; *env != 0; env++)
//   {
//     char *thisEnv = *env;
//     printf("%s\n", thisEnv);    
//   }
//   return 0;
	//PATH
	// if ( == -1)
	// 	write(1, "error\n", 6);
	//ft_strnstr

