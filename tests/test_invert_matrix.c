#include "../includes/raytracer.h"

int main ()
{
	t_matrix original;
	t_matrix inverted;

	original = c_matrix(4, 4);
	original.value[0][0] = 4;
	original.value[0][1] = 5;
	original.value[0][2] = 6;
	original.value[0][3] = 7;
	original.value[1][0] = 8;
	original.value[1][1] = 7;
	original.value[1][2] = 8;
	original.value[1][3] = 9;
	original.value[2][0] = 1;
	original.value[2][1] = 2;
	original.value[2][2] = 5;
	original.value[2][3] = 4;
	original.value[3][0] = 3;
	original.value[3][1] = 3;
	original.value[3][2] = 0;
	original.value[3][3] = 1;
	inverted = invert_matrix(original);
	print_matrix(original);
	print_matrix(inverted);
}
