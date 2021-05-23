/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ticks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 21:26:27 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/04/15 16:06:55 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/raytracer.h"

typedef struct			s_projectile
{
	t_pos_w				velocity;
	t_pos_w				position;
}						t_projectile;

typedef struct			s_environment
{
	t_pos_w				gravity;
	t_pos_w				wind;
}						t_environment;

t_canvas				draw_dot(t_projectile tick, t_canvas canvas)
{
	t_color				c1;

	c1 = c_color(1, 0.5, 0.6);
	canvas = write_pixel(canvas, tick.position.x, canvas.height - tick.position.y, c1);
	canvas = write_pixel(canvas, tick.position.x + 1, canvas.height - tick.position.y, c1);
	canvas = write_pixel(canvas, tick.position.x + 1, canvas.height - tick.position.y - 1, c1);
	canvas = write_pixel(canvas, tick.position.x, canvas.height - tick.position.y - 1, c1);
	return (canvas);
}

void	draw_trajectory(t_projectile tick, t_environment env, t_canvas canvas)
{
	t_pos_w				env_velocity;

	env_velocity = add_pos_w(env.gravity, env.wind);
	tick.velocity = add_pos_w(env_velocity, tick.velocity);
	if (tick.velocity.y > 0)
		while (tick.position.y > 0 && tick.position.x < canvas.width - 1)
		{
			canvas = draw_dot(tick, canvas);
			tick.position = add_pos_w(tick.velocity, tick.position);
			tick.velocity = add_pos_w(env_velocity, tick.velocity);
		}
}

int						main()
{
	t_projectile		tick;
	t_environment		env;
	t_canvas			canvas;
	int					height;
	int					width;

	width = 900;
	height = 500;
	c_canvas(width, height, &canvas);
	tick.position = c_point(0, 1, 0);
	tick.velocity =  scal_mul_pos_w(norm_pos_w(c_vector(1, 1.8, 0)), 11.25);
	env.gravity = c_vector(0, -0.1, 0);
	env.wind = c_vector(-0.01, 0, 0);
	draw_trajectory(tick, env, canvas);
	create_ppm("tick", canvas);
	free_canvas(canvas);
}
