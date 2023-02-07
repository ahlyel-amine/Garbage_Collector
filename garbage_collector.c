/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 20:31:50 by aahlyel           #+#    #+#             */
/*   Updated: 2023/02/07 21:26:52 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbage_collector.h"

void    ft_exit(char *err_messg, int exit_status)
{
	if (!exit_status)
	{
		ft_lstclear(&g_garbg, free);
		exit(EXIT_SUCCESS);
	}
	if (err_messg)
		ft_putendl_fd(err_messg, STDERR_FILENO);
	else if (errno)
		perror("");
	ft_lstclear(&g_garbg, free);
	exit(EXIT_FAILURE);
}

void    *ft_malloc(void *pointer, int is_tmp)
{
	t_list	*new;
	
	new = NULL;
	if (!pointer)
		ft_exit(ERR_ALLOC, 1);
	new = ft_lstnew(pointer);
	if (!new)
	{
		free(pointer);
		ft_exit(ERR_ALLOC, 1);
	}
	ft_lstadd_front(&g_garbg, new);
	return (pointer);
}

t_list	*ft_lstnew(void	*pointer)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = pointer;
	new->is_tmp = 0;
	return (NULL);
}


// #include <stdio.h>
// t_list *xor(t_list *prev, t_list *curr)
// {
// 	return (t_list *)((uintptr_t)prev ^ (uintptr_t)curr);
// }

// void traverse(t_list *head)
// {
// 	t_list	*curr = head;
// 	t_list	*prev = NULL;
// 	t_list	*next;
 
//     while (curr != NULL)
//     {
//         printf("%d\n", curr->data);
 
//         // `next` node would be xor of the address of the previous node
//         // and current node link
//         next = (t_list *)xor(prev, curr->next);
 
//         // update `prev` and `curr` pointers for the next iteration of the loop
//         prev = curr;
//         curr = next;
//     }
 
// }
// static int i = 1;
// void push(t_list **head, int data)
// {
//     // allocate a new list node and set its data
//     t_list	*newNode = (t_list *)malloc(sizeof(t_list));
// 	printf("alloc %d\n", i++);
//     newNode->data = data;
 
//     // The link field of the new node is XOR of the current head and `NULL`
//     // since a new node is being inserted at the beginning
//     newNode->next = (t_list *)xor(*head, NULL);
 
//     // update link value of the current head node if the linked list is not empty
//     if (*head)
//     {
//         // *(head)->link is XOR of `NULL` and address of the next node.
//         // To get the address of the next node, XOR it with `NULL`
// 		(*head)->next = (t_list *)xor(newNode, (t_list *)xor((*head)->next, NULL));
//     }
 
//     // update the head pointer
//     *head = newNode;
// }

// int	main()
// {
// 	t_list	*lol = NULL, *pop;

// 	for (int i = 0; i++ < 10;)
// 		push(&lol, i);
// 	traverse(lol);
// 	traverse(lol);


// 	// while (lol)
// 	// {
// 	// 	printf("2 : %d\n", lol->data);
// 	// 	lol = lol->next;
// 	// }


// }