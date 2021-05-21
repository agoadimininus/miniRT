#include "../includes/raytracer.h"

t_canvas				draw_dot(t_pos_w hour, t_canvas canvas)
{
	t_color				c1;

	c1 = c_color(1, 0.5, 0.6);
	canvas = write_pixel(canvas, canvas.width / 2 + hour.x - 1, canvas.height / 2 + hour.y - 1, c1);
	canvas = write_pixel(canvas, canvas.width / 2 + hour.x, canvas.height / 2 + hour.y - 1, c1);
	canvas = write_pixel(canvas, canvas.width / 2 + hour.x + 1, canvas.height / 2 + hour.y - 1, c1);
	canvas = write_pixel(canvas, canvas.width / 2 + hour.x - 1, canvas.height / 2 + hour.y, c1);
	canvas = write_pixel(canvas, canvas.width / 2 + hour.x, canvas.height / 2 + hour.y, c1);
	canvas = write_pixel(canvas, canvas.width / 2 + hour.x + 1, canvas.height / 2 + hour.y, c1);
	canvas = write_pixel(canvas, canvas.width / 2 + hour.x - 1, canvas.height / 2 + hour.y + 1, c1);
	canvas = write_pixel(canvas, canvas.width / 2 + hour.x, canvas.height / 2 + hour.y + 1, c1);
	canvas = write_pixel(canvas, canvas.width / 2 + hour.x + 1, canvas.height / 2 + hour.y + 1, c1);
	return (canvas);
}

t_pos_w			rotate_hour(t_pos_w hour, int i)
{
	t_matrix	rot;

	rot = rotation_z(deg_to_rad(360/12));
	if (i == 1)
		hour = mult_matrix_pos_w(rot, hour);
	else if (i > 1)
	{
		i--;
		hour = rotate_hour(hour, i);
		hour = mult_matrix_pos_w(rot, hour);
	}
	free_matrix(rot);
	return (hour);
}

int				main (void)
{
	t_canvas	canvas;
	t_pos_w		*hour;
	t_matrix	trans;
	int			i;
	char		*file_name;
	int			display;

	display = 200;
	c_canvas(display, display, &canvas);
	hour = (t_pos_w *)malloc(sizeof(t_pos_w) * 12);
	i = 0;
	trans = translation(display / 4, 0, 0);
	while (i < 12)
	{
		hour[i] = c_point(0, 0, 0);
		hour[i] = mult_matrix_pos_w(trans, hour[i]);
		hour[i] = rotate_hour(hour[i], i);
		canvas = draw_dot(hour[i], canvas);
		i++;
	}
	file_name = ft_strdup("hour_test");
	create_ppm(file_name, canvas);
	free_canvas(canvas);
	free(hour);
}

