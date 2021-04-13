#ifndef PHIL_H
# define PHIL_H
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <errno.h>
# include <dirent.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "../libft/libft.h"
#include <pthread.h>
#include <semaphore.h>
 #include <sys/time.h>
typedef struct	s_phil
{
	int id;
	int nbr_meal;
	pid_t pid;
	long time_last_meal;
}				t_phil;

typedef struct	s_central
{
	int nbr_phil;
	long start_time;
	int nbr_meal_max;
	int time_die;
	int time_eat;
	int time_sleep;
	sem_t *print_sem;
	sem_t *afork_sem;
	t_phil **phil;
}				t_central;
int			ft_isnumber(char *str);
int    ft_verif(char **av, int ac);
void	ft_print_aphill(t_central *central);
void	ft_eat(t_central *central, t_phil *phil);
void	ft_action(t_central *central, t_phil *phil);
void	ft_create_child(t_central *central, t_phil *phil);
long	ft_get_time(long start_time);
t_central		ft_create_t_central(int ac, char **av);
t_central		*ft_malloc_t_central(int ac, char **av);
void		ft_free_t_central(t_central *to_free);
t_phil		ft_create_t_phil(int id);
t_phil		*ft_malloc_t_phil(int id);
void		ft_free_t_phil(t_phil *to_free);
void	ft_launch(t_central *central);
#endif