
#include <stdlib.h>

typedef struct s_node {
		void          *content;
		struct s_node *next;
}Node;

typedef struct s_stack {
		struct s_node *top;
}Stack;

struct s_stack *init(void)
{
	Stack* new_stack = malloc(sizeof(Stack));
	new_stack->top = NULL;
	return (new_stack);
}

void *pop(struct s_stack *stack)
{
	void	*tmp_content;
	Node	*tmp_node;

	if (!stack->top)
		return (NULL);
	tmp_node = stack->top;
	stack->top = stack->top->next;
	tmp_content = tmp_node->content;
	free(tmp_node);
	return (tmp_content);
}

void push(struct s_stack *stack, void *content)
{
	Node	*new_node;

	new_node = malloc(sizeof(Node));
	new_node->content = content;
	new_node->next = stack->top;
	stack->top = new_node;
}

void *peek(struct s_stack *stack)
{
	return ((stack->top) ? stack->top->content : NULL);
}

int isEmpty(struct s_stack *stack)
{
	return ((stack->top) ? 0 : 1);
}
