#include "../includes/raytracer.h"

static t_world	create_spheres(t_world world)
{
	world.objects[0] = c_sphere();
	world.objects[0] = setf_transform(world.objects[0], scaling(10, 0.01, 10));
	world.objects[0].material->color = c_color(1, 0.9, 0.9);
	world.objects[0].material->specular = 0;
	world.objects[1] = c_sphere();
	world.objects[1] = setf_transform(world.objects[1], translation(0, 0, 5));
	world.objects[1] = setf_transform(world.objects[1], rotation_y(-M_PI / 4));
	world.objects[1] = setf_transform(world.objects[1], rotation_x(M_PI / 2));
	world.objects[1] = setf_transform(world.objects[1], scaling(10, 0.01, 10));
	world.objects[1].material->color = c_color(1, 0.9, 0.9);
	world.objects[1].material->specular = 0;
	world.objects[2] = c_sphere();
	world.objects[2] = setf_transform(world.objects[2], translation(0, 0, 5));
	world.objects[2] = setf_transform(world.objects[2], rotation_y(M_PI / 4));
	world.objects[2] = setf_transform(world.objects[2], rotation_x(M_PI / 2));
	world.objects[2] = setf_transform(world.objects[2], scaling(10, 0.01, 10));
	world.objects[2].material->color = c_color(1, 0.9, 0.9);
	world.objects[2].material->specular = 0;
	world.objects[3] = c_sphere();
	world.objects[3] = setf_transform(world.objects[3], translation(-0.5, 1, 0.5));
	world.objects[3].material->color = c_color(0.1, 1, 0.5);
	world.objects[3].material->diffuse = 0.7;
	world.objects[3].material->specular = 0.3;
	world.objects[4] = c_sphere();
	world.objects[4] = setf_transform(world.objects[4], translation(1.5, 0.5, -0.5));
	world.objects[4] = setf_transform(world.objects[4], scaling(0.5, 0.5, 0.5));
	world.objects[4].material->color = c_color(0.5, 1, 0.1);
	world.objects[4].material->diffuse = 0.7;
	world.objects[4].material->specular = 0.3;
	world.objects[5] = c_sphere();
	world.objects[5].transform = mult_free(world.objects[5].transform, translation(-1.5, 0.33, -0.75));
	world.objects[5].transform = mult_free(world.objects[5].transform, scaling(0.33, 0.33, 0.33));
	world.objects[5].material->color = c_color(1, 0.8, 0.1);
	world.objects[5].material->diffuse = 0.7;
	world.objects[5].material->specular = 0.3;
	return (world);
}

int	main(void)
{
	t_world		world;
	t_camera	camera;
	t_canvas	canvas;

	world = c_world(1, 6);
//	world = c_world(1, 1);
	world = create_spheres(world);
//	world.objects[0] = c_sphere();
//	world.objects[0].transform = mult_free(world.objects[0].transform, translation(-1.5 , 0.5, -0.5));
//	world.objects[0].transform = mult_free(world.objects[0].transform, scaling(0.5, 0.5, 0.5));
	world.lights[0] = c_light(c_point(-10, 10, -10), c_color(1, 1, 1));
	camera = c_camera(500, 250, M_PI / 3);
	camera = view_transform(camera, c_point(0, 1.5, -5), c_point(0, 1, 0), c_vector(0, 1, 0));
	canvas = render(camera, world);
	create_ppm("making_scene_shadow", canvas);
	free_matrix(camera.transform);
	free_canvas(canvas);
	free_world(world);
}
