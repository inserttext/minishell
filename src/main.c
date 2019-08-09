#include "../includes/minishell.h"
#include "unistd.h"

size_t __env_size;

static size_t	__get_env_size()
{
	size_t len;

	len = 0;
	while (__environ[len] != NULL)
		len++;
	return (len);
}

int				main(void)
{
	__env_size = __get_env_size();
	ms_loop();
	return(0);
}
