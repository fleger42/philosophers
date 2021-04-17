#include "../includes/phil.h"

int	pair;

int			ft_isnumber(char *str)
{
	int i;

	i = 0;
	if (ft_strcmp(str, "-") == 0)
		return (0);
	if (str[0] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int    ft_verif(char **av, int ac)
{
	if(ac < 5 || ac > 6)
		return (1);
	if(ft_isnumber(av[1]) == 0 || ft_atoi(av[1]) < 0)
		return (1);
	if(ft_isnumber(av[2]) == 0 || ft_atoi(av[2]) < 0)
		return (1);
	if(ft_isnumber(av[3]) == 0 || ft_atoi(av[3]) < 0)
		return (1);
	if(ft_isnumber(av[4]) == 0 || ft_atoi(av[4]) < 0)
		return (1);
	if(ac == 6 && (ft_isnumber(av[5]) == 0 || ft_atoi(av[5]) < 0))
		return (1);
	return (0);
}

void	ft_print_aphill(t_central *central)
{
	int i;

	i = 0;
	while(i < central->nbr_phil)
	{
		printf("TOTEM\n");
		printf("\nPhilosopher %d\n", central->phil[i]->id);
		printf("Ate %d meal\n",  central->phil[i]->nbr_meal);
		printf("Last meal was %ld ms ago\n",  central->phil[i]->time_last_meal);
		i++;
	}
}

void	ft_sleep(t_central *central, t_phil *phil)
{
	(void)phil;
	sem_wait(phil->print_sem);
	printf("%ld %d is sleeping\n", ft_get_time(central->start_time), phil->id);
	sem_post(phil->print_sem);
	usleep(central->time_sleep*1000);
}

void	ft_think(t_central *central, t_phil *phil)
{
	(void)phil;
	sem_wait(phil->print_sem);
	printf("%ld %d is thinking\n", ft_get_time(central->start_time), phil->id);
	sem_post(phil->print_sem);
}

void	ft_eat(t_central *central, t_phil *phil)
{
	(void)phil;
	sem_wait(phil->afork_sem);
	sem_wait(phil->print_sem);
	printf("%ld %d has taken a fork\n", ft_get_time(central->start_time), phil->id);
	sem_post(phil->print_sem);

	sem_wait(phil->afork_sem);
	sem_wait(phil->print_sem);
	printf("%ld %d is eating\n", ft_get_time(central->start_time), phil->id);;
	phil->time_last_meal = ft_get_time(central->start_time);
	sem_post(phil->print_sem);
	usleep(central->time_eat*1000);
	sem_post(phil->afork_sem);
	sem_post(phil->afork_sem);
}

void	*ft_thread(void *arg)
{
	t_phil *phil;

	phil = arg;
	while(ft_get_time(phil->start_time) - phil->time_last_meal < phil->time_die)
	{
		//printf("%d last meal %ld/%d\n", phil->id, ft_get_time(phil->start_time) - phil->time_last_meal, phil->time_die);
		usleep(20);
	}
	sem_wait(phil->print_sem);
	printf("%ld %d died\n", ft_get_time(phil->start_time), phil->id);
	exit(0);
}

void	ft_action(t_central *central, t_phil *phil)
{
	pthread_t process;

	if (pthread_create(&process, NULL, ft_thread, phil) <  0)
	{
		ft_putstr_fd("Error creating thread\n", 2);
		exit(0);
	}
	pthread_detach(process);
	printf("%d start his routine\n", phil->id);
	while(1)
	{
		//printf("%d last meal %ld/%d\n", phil->id, ft_get_time(central->start_time) - phil->time_last_meal, central->time_die);
		ft_eat(central, phil);
		ft_sleep(central, phil);
		ft_think(central, phil);
	}
}


void	ft_create_child(t_central *central, t_phil *phil)
{
	pid_t pid;

	if((pid = fork()) == -1)
	{
		ft_putstr_fd("Failed to fork\n", 2);
		ft_free_t_central(central);
		exit(1);
	}
	if(pid == 0)
	{
		central->dad = 0;
		phil->start_time = central->start_time;
		phil->time_die = central->time_die;
		ft_action(central, phil);
		exit(1);
	}
	else
	{
		phil->pid = pid;
	}
	usleep((central->time_eat  * (phil->id % 2)) / 2);
}

long	ft_get_time(long start_time)
{
	long passed_time;
	struct timeval time;

	gettimeofday(&time, NULL);
	passed_time = ((time.tv_sec*1000) + time.tv_usec/1000) - start_time;
	return (passed_time);
}


void	ft_launch(t_central *central)
{
	int i;
	int pid;

	pid = 0;
	i = 0;
	while(i < central->nbr_phil && central->dad)
	{
		ft_create_child(central, central->phil[i]);
		i++;
	}
}

void	ft_end(t_central *central)
{
	int i;
	pid_t pid;

	i = 0;
	while(i < central->nbr_phil)
	{
		waitpid(-1, &pid, 0);
		if (WIFEXITED(pid))
		{
			pid = WEXITSTATUS(pid);
			i++;
		}
		if(central->dad == 0)
			exit(0);
	}
	
}
void	ft_kill(t_central *central)
{
	int i;

	i = 0;
	while(i < central->nbr_phil)
	{
		kill(central->phil[i]->pid, SIGTERM);
		i++;
	}
}

int     main(int ac, char **av)
{
	t_central *central;
	int i;
	int		stat_loc;

	i = 0;
	if(ft_verif(av, ac) == 1)
	{
		ft_putstr_fd("Parsing error\n", 2);
		exit(1);
	}
    central = ft_malloc_t_central(ac, av);
	sem_unlink("afork_sem");
	sem_unlink("print_sem");
	central->start_time = ft_get_time(0);
	ft_launch(central);
	waitpid(-1, &stat_loc, 0);
	ft_kill(central);
}