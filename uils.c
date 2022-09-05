#include "fractol.h"

void	change_size(double *v_max, double *v_min, double increase)
{
	*v_max += increase;
	*v_min += increase;
}

void	change_factor(double *v_max, double *v_min, double increase)
{
	*v_max *= increase;
	*v_min *= increase;
}
