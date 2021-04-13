#include "../includes/phil.h"

t_phil		ft_create_t_phil(int id)
{
	t_phil phil;

	phil.id = id;
	phil.nbr_meal = 0;
	phil.time_last_meal = 0;
	return (phil);
}

t_phil		*ft_malloc_t_phil(int id)
{
	t_phil	*phil;

	phil = (t_phil*)malloc(sizeof(t_phil));
	*phil = ft_create_t_phil(id);
	return (phil);
}

void		ft_free_t_phil(t_phil *to_free)
{
	free(to_free);
}