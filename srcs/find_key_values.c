#include "../includes/push_swap.h"
#include "../libft/libft.h"

int	*sort_table(int *tab)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = 0;
	while (tab[i])
	{
		j = i + 1;
		while (tab[j])
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (tab);
}

void	find_quarters(t_info *info)
{
	int	len;
	int	i;

	info->quarters[0] = 0;
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
	i = 1;
	len = info->size;
	while (i < 10)
	{
		info->deciles[i] = info->tab[(i*len)/10];
		i++;
	}
}
