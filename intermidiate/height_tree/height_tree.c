
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

struct s_node {
		int           value;
		struct s_node **nodes;
};


int	height_tree(struct s_node *root)
{
	if (!root)
		return (-1);
	int len;
	int max;
	for (len = 0; root->nodes[len]; len++) {}
	max = 0;
		int current_height;
		for (int i = 0; i < len; i++)
		{
			current_height = height_tree(root->nodes[i]) + 1;
			if (current_height > max)
				max = current_height;
		}
		return (max);
}
