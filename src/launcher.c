#include "../libft/includes/libft.h"
#include "../includes/minishell.h"
#include <sys/wait.h>

int ms_exec(char **args)
{
	return (1);
}

int ms_launcher(char **args)
{
	pid_t	pid;
	pid_t	wpid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(args[0], args, g_environ) == -1)
			ft_fprintf(2, "yah dun goofed\n");
		exit(0);
	}
	else if (pid < 0)
		ft_fprintf(2, "yah dun goofed\n");
	else
	{
		wpid = waitpid(pid, &status, WUNTRACED);
		while (!WIFEXITED(status) && WIFSIGNALED(status))
			wpid = waitpid(pid, &status, WUNTRACED);
	}
	return (1);
}
