/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/17 08:47:32 by jbernabe          #+#    #+#             */
/*   Updated: 2014/04/20 05:49:45 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/mman.h>
#include <stdio.h>
#include "my_malloc.h"


t_block			*init_heap(void)
{
	t_block 	*z_page;

	z_page = (t_block *)mmap(0, sizeof(t_block), PROT_WRITE
		| PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	ft_putendl("init_heap 0");
	// z_page->tiny->addr = mmap(0, TINY, PROT_READ
	// 	| PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	// ft_putendl("init_heap 1");
	// z_page->small->addr = mmap(0, SMALL, PROT_READ
	// 	| PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	// ft_putendl("init heap 2");
	// if (z_page->tiny->addr == MAP_FAILED
	// 	|| z_page->small->addr == MAP_FAILED)
	// {
	// 	ft_putendl("exit");
	// 	return (NULL);
	// }
	return (z_page);
}

void			*my_malloc(size_t size_str)
{
	t_block		*b;
	t_block		*tab;
	static	int	is_first = 0;

	if (size_str == 0)
		return (NULL);
	if (is_first == 0)
	{
		is_first = 1;
		ft_putendl("entro en el if de b");
		b = init_heap();
		tab = tab_index();
		ft_putendl("entro en assg_addr");
		// assign_addr(&tab, b);
		 if (!(b))
		 	return (NULL);
		base_malloc = *b;
	}
	ft_putendl("salgo de malloc");
	return (b->data);
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		char *a = (char *)my_malloc(ft_atoi(av[1]));
		printf("get_pagesize %i\n", getpagesize());
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