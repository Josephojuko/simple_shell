#include "shell.h"

/**
* main - point
* @ak: arg count
* @v: arg vector
* Return: 0 on ss, 1 on e
*/
int main(int ak, char **v)
{
	io_t io[] = { INFO_INIT };
	int cod = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (cod)
		: "r" (cod));

	if (ak == 2)
	{
		cod = open(v[1], O_RDONLY);
		if (cod == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				eputting(v[0]);
				eputting(": 0: I cannot open it Can't open ");
				eputting(v[1]);
				putting_charact('\n');
				putting_charact(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		io->readfd = cod;
	}
	popu_envr_list(io);
	read_his_tory(io);
	hsh(io, v);
	return (EXIT_SUCCESS);
}
