// gcc -Wextra -Werror main.c ../Push_swap/printf/libftprintf.a && ./a.out ls

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <errno.h>
#include <fcntl.h>
#include "../Push_swap/printf/ft_printf.h"

int	main(int argc, char **argv, char **envp)
{
	char *options[3] = {"ls", "-la", NULL};
	int	i = 0;
	(void)argc;
	(void)argv;
	char *PATH = malloc (sizeof(char) * 200);
	
		ft_printf("arg1: %s\n",argv[1]);
	if (argv[1] == "ls")
	{
		if (execve("/usr/bin/ls", options, envp) == -1)
		{
			ft_printf("error: %s\n", strerror(errno));
			exit(1);
		}
	}
	else
		execve("/usr/bin/ls", options, envp);
	return (0);
}
