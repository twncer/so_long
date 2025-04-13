#include "./../so_long.h"
#include "./../render/render.h"

unsigned int	count_digits(unsigned int n)
{
	unsigned int	digits;
	unsigned int	h;

	if (n == 0)
		return (1);
	digits = 0;
		h = n;
	while (h >= 1)
	{
		digits++;
		h = h / 10;
	}
	return (digits);
}

unsigned int	power_of10(unsigned int len)
{
	unsigned int	i;

	i = 1;
	while (len--)
		i = i * 10;
	return (i);
}

void display_moves(struct s_eventpkg *evpkg, unsigned int moves)
{
	unsigned int	len;
	unsigned int margin;

	len = count_digits(moves);
    margin = 0;
    while (len--)
	{
		put_img_to_hud(&evpkg->mlx, evpkg->images.numbers[moves / power_of10(len)], margin, 660);
		moves = moves % power_of10(len);
        margin += 60;
	}
    put_img_to_hud(&evpkg->mlx, evpkg->images.numbers[10], margin, 660);
}