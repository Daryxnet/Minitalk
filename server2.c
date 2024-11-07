#include <signal.h>
#include <unistd.h>
#include "Libft/libft/libft.h"

static void	action(int sig, siginfo_t *info, void *context)
{
	static int				i = 0;
	static pid_t			client_pid = 0;
	static unsigned char	c = 0;

	(void)context;
	if (!client_pid)
		client_pid = info->si_pid;
	c |= (sig == SIGUSR2);
	if (++i == 8)
	{
		i = 0;
		if (!c)
		{
			kill(client_pid, SIGUSR2);
			client_pid = 0;
			return ;
		}
		ft_putchar_fd(c, 1);
		c = 0;
		kill(client_pid, SIGUSR1);
	}
	else
		c <<= 1;
}

// Función para manejar el cierre del servidor con SIGINT
static void	handle_exit(int sig)
{
	(void)sig;
	ft_putstr_fd("\nServer shutting down...\n", 1);
	exit(0);
}

int	main(void)
{
	struct sigaction	s_sigaction;

	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);

	// Configurar señales para recibir mensajes
	s_sigaction.sa_sigaction = action;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);

	// Configurar señal para manejar el cierre
	signal(SIGINT, handle_exit);

	while (1)
		pause();
	return (0);
}

