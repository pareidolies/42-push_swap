#include "../includes/push_swap.h"
#include "../libft/libft.h"

void	find_quarters(t_info *info)
{
	int	len;
	int	i;

	info->quarters[0] = 0;
	info->quarters[4] = find_biggest(info, 'a');
	i = 1;
	len = info->size;
	while (i < 4)
	{
		info->quarters[i] = info->tab[(i*len)/4];
		i++;
	}
}

void	find_deciles(t_info *info)
{
	int	len;
	int	i;

	info->deciles[0] = 0;
	info->deciles[10] = find_biggest(info, 'a');
	i = 1;
	len = info->size;
	while (i < 10)
	{
		info->deciles[i] = info->tab[(i*len)/10];
		i++;
	}
}


