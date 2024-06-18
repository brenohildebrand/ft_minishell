/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:48:36 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/17 16:31:51 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <errno.h>

int	main(void)
{
	// manda tudo pra narnia

	const char *path = "/tmp/narnia";
	int			fd;
	int			stdout_ref;

	stdout_ref = dup(STDOUT_FILENO);
	printf("opening...\n");
	fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (dup2(fd, STDOUT_FILENO) == -1)
	{
		exit(1);
	}
	dprintf(STDOUT_FILENO, "to em narnia\n");
	if (dup2(stdout_ref, STDOUT_FILENO) == -1)
	{
		exit(1);
	}
	printf("closing...\n");
	close(fd);
	// printf("to em narnia\n");
}
