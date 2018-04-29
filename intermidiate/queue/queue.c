
#include <stdlib.h>

struct s_node {
		void *content;
		struct s_node *next;
	};

	struct s_queue {
		struct s_node *first;
		struct s_node *last;
	};

struct s_queue *init(void)
{
	struct s_queue	*new_queue;

	new_queue = malloc(sizeof(struct s_queue));
	new_queue->first = NULL;
	new_queue->last = NULL;
	return (new_queue);
}

void			enqueue(struct s_queue *queue, void *content)
{
	struct s_node *node;

	node = malloc(sizeof(struct s_node));
	node->content = content;
	node->next = NULL;
	if (!queue->first)
	{
		queue->first = node;
		queue->last = node;
	}
	else
	{
		queue->last->next = node;
		queue->last = node;
	}	
}

void			*dequeue(struct s_queue *queue)
{
	if (!queue || !queue->first)
		return (NULL);
	else
	{
		struct s_node	*tmp_node;
		void			*tmp_content;
		tmp_node = queue->first;
		queue->first = queue->first->next;
		if (!queue->first)
			queue->last = NULL;
		tmp_content = tmp_node->content;
		free(tmp_node);
		return (tmp_content);
	}
}

void			*peek(struct s_queue *queue)
{
	if (!queue || !queue->first)
		return (NULL);
	else
		return (queue->first->content);
}

int				isEmpty(struct s_queue *queue)
{
	return ((!queue->first) ? 1 : 0);
}

