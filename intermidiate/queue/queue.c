
#include <stdlib.h>

struct s_queue	*init(void)
{
	struct s_queue	*new_queue;

	new_queue = malloc(sizeof(struct s_queue));
	new_queue->first = NULL;
	new_queue->last = NULL;
	return (new_queue);
}

void			enqueue(struct s_queue *queue, void *content)
{
	struct s_node	*new_node;

	new_node = malloc(sizeof(struct s_node));
	new_node->content = content;
	new_node->next = NULL;
	if (!queue->first)
	{
		queue->first = new_node;
		queue->last = new_node;
	}
	else
		queue->last = new_node;
}

void			*dequeue(struct s_queue *queue)
{
	struct s_node	*tmp_node;
	void			*tmp_content;

	if (!queue->first)
		return (NULL);
	tmp_node = queue->first;
	queue->first = queue->first->next;
	tmp_content = tmp_node->content;
	free (tmp_node);
	return (tmp_content);
}

void			*peek(struct s_queue *queue)
{
	return ((queue->first) ? queue->first->content : NULL);
}

int				isEmpty(struct s_queue *queue)
{
	return ((queue->first) ? 0 : 1);
}
