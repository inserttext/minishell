#include "../libft/includes/libft.h"
#include "../includes/minishell.h"
#include <sys/wait.h>
#include <unistd.h>

struct s_func
{
	char *name;
	int (*f)(char**);
};

static struct s_func tbl[128] = {
	[5] = {"exit", &__exit},
	[24] = {"env", &__env},
	[36] = {"echo", &__echo},
	[60] = {"unset", &__unset},
	[97] = {"export", &__export},
	[98] = {"cd", &__cd},
};

static unsigned long	hash(unsigned char *str)
{
	unsigned long hash;

	hash = 5381;
	while (*str)
	{
		hash = ((hash << 5U) + hash) ^ *str;
		str++;
	}
	return (hash);
}

static int				forkexec(char *run, char **tok)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(run, tok, g_environ) == -1)
			perror("msh");
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
		perror("msh");
	else
	{
		waitpid(pid, &status, WUNTRACED);
		while (!WIFEXITED(status) && !WIFSIGNALED(status))
			waitpid(pid, &status, WUNTRACED);
	}
	return (0);
}

static int				searchpath(char **tok)
{
	char *fullpath;
	char *path;
	char *run;

	fullpath = ft_strdup(__getenv("PATH"));
	path = ft_strtok(fullpath, ":");
	while (path != NULL)
	{
		run = ft_strjoin(3, path, "/", tok[0]);
		if (access(run, X_OK) == 0)
		{
			forkexec(run, tok);
			free(run);
			break;
		}
		free(run);
		path = ft_strtok(NULL, ":");
	}
	if (path == NULL)
		ft_printf("msh: command not found: %s\n", tok[0]);
	free(fullpath);
	return (0);
}

int						launcher(char **tok)
{
	unsigned long	hashed;
	int				ret;

	hashed = hash((unsigned char *)tok[0]) % 128;
	if (tbl[hashed].name != NULL && ft_strcmp(tok[0], tbl[hashed].name) == 0)
		ret = tbl[hashed].f(tok);
	else
		ret = searchpath(tok);
	return (ret);
}
