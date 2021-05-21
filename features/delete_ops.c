#include "../includes/raytracer.h"
#include <stdarg.h>

void	print_matrix(t_matrix a)
{
	int			r;
	int			c;

	r = -1;
	while (++r < a.row)
	{
		c = -1;
		while (++c < a.col)
			printf("|%f| ", a.value[r][c]);
		printf("\n");
	}
}

t_matrix	assign_values_matrix(t_matrix a, ...)
{
	va_list		ap;
	int			r;
	int			c;

	va_start(ap, a);
	r = -1;
	while (++r < a.row)
	{
		c = -1;
		while (++c < a.col)
			a.value[r][c] = va_arg(ap, int);
	}
	va_end(ap);
	return (a);
}

void	print_inter_list(t_node_inter *list)
{
	t_node_inter	*ptr;

	ptr = list;
	while (ptr->next != NULL)
	{
		printf("count %d, t = %f, obj = %p\n", ptr->count, ptr->t, ptr->obj);
		ptr = ptr->next;
	}
	printf("count %d, t = %f, obj = %p\n", ptr->count, ptr->t, ptr->obj);
}
