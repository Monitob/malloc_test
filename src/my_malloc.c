/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/17 08:47:32 by jbernabe          #+#    #+#             */
/*   Updated: 2014/04/20 21:40:09 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <sys/mman.h>
#include <stdio.h>
#include "my_malloc.h"


void		init_heap(void)
{
	base_malloc.tiny->addr = (t_block *)mmap(0, TINY, PROT_WRITE
		| PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	base_malloc	.small->addr = (t_block *)mmap(0, SMALL, PROT_WRITE
		| PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	base_malloc	.large->addr = (t_block *)mmap(0, LARGE, PROT_WRITE
		| PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
}

void			*my_malloc(size_t size_str)
{
	static int	is_first = 0;

	if (is_first == 0)
	{
		is_first = 1;
		init_heap();
	}
	else if
	{
		if (size_str <= TINY)
			return (tiny_space(size_str));
		if (size_str <= SMALL)
			return (tiny_space(size_str));
		if (size_str => LARGE)
			return (tiny_space(size_str));
	}
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		char *a = (char *)my_malloc(ft_atoi(av[1]));
		a = "hola";
		printf("malloc address: %p\n", a);
		printf("%s \n", a);
		printf("chunk_bloc size %lu\n", sizeof(t_block));
	}
	else
	{
		return (0);
	}
}
