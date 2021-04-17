#include "../includes/phil.h"

t_phil		ft_create_t_phil(int id, int nbr_phil)
{
	t_phil phil;

	phil.id = id;
	phil.nbr_meal = 0;
	phil.time_last_meal = 0;
	phil.afork_sem = sem_open("afork_sem", O_RDWR | O_CREAT, 0664, nbr_phil);
	phil.print_sem = sem_open("print_sem", O_RDWR | O_CREAT, 0664, 1);
	return (phil);
}

t_phil		*ft_malloc_t_phil(int id, int nbr_phil)
{
	t_phil	*phil;

	phil = (t_phil*)malloc(sizeof(t_phil));
	*phil = ft_create_t_phil(id, nbr_phil);
	return (phil);
}

void		ft_free_t_phil(t_phil *to_free)
{
	free(to_free);
}