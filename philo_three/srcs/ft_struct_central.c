#include "../includes/phil.h"

t_central		ft_create_t_central(int ac, char **av)
{
	t_central central;
	int i;

	i = -1;
	central.start_time = 0;
	central.dad = 1;
	central.nbr_phil = ft_atoi(av[1]);
	central.time_die = ft_atoi(av[2]);
	central.time_eat = ft_atoi(av[3]);
	central.time_sleep = ft_atoi(av[4]);
	if(ac > 5)
		central.nbr_meal_max = ft_atoi(av[5]);
	else
		central.nbr_meal_max = -1;
	central.phil = malloc(sizeof(t_phil*) * central.nbr_phil);
	while(++i < central.nbr_phil)
		central.phil[i] = ft_malloc_t_phil(i + 1, central.nbr_phil);
	return (central);
}

t_central		*ft_malloc_t_central(int ac, char **av)
{
	t_central	*central;

	central = (t_central*)malloc(sizeof(t_central));
	*central = ft_create_t_central(ac, av);
	return (central);
}

void		ft_free_t_central(t_central *to_free)
{
	free(to_free);
}