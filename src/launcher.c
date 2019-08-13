#include "../libft/includes/libft.h"
#include <unistd.h>

struct s_func
{
	char *name;
	int (*f)(char**);
};

static struct s_func tbl[128] = {
	[5] = {"exit", NULL},
	[36] = {"echo", NULL},
	[60] = {"unset", NULL},
	[97] = {"export", NULL},
	[98] = {"cd", NULL},
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

int						launcher(char **tok)
{
	unsigned long hashed;

	hashed = hash((unsigned char *)tok[0]) % 128;
	if (tbl[hashed].name != NULL && ft_strcmp(tok[0], tbl[hashed].name) == 0)
		return (tbl[hashed].f(tok));
	return (0);
}
