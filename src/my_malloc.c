/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/17 08:47:32 by jbernabe          #+#    #+#             */
/*   Updated: 2014/04/19 05:16:55 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/mman.h>
#include <stdio.h>
#
#include "my_malloc.h"

t_block			*extend_heap(t_block *last_ptr, size_t req_size)
{
	ft_putendl("entro en extend_heap");
	t_block 	*z_page;

	z_page = NULL;
	
	if (last_ptr)
	{
		if (req_size > 512)
		{
			z_page->large.size = req_size;
			z_page->next = NULL;
			z_page->is_available = 0;
		}
		if (req_size > 200  &&  req_size < 512)
		{
			z_page->small.size = req_size;
			z_page->next = NULL;
			z_page->is_available = 0;
		}
		if (req_size < 200)
		{
			z_page->tiny.size = req_size;
			z_page->next = NULL;
			z_page->is_available = 0;
		}
	}
	else
	{
		if (req_size > 512)
		{
			ft_putendl("entro en extend_heap LARGE");
			z_page->large.addr = mmap(0, getpagesize() * 3, PROT_READ
				| PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
			z_page->large.size = req_size;
			z_page->next = NULL;
		}
		if (req_size > 200  &&  req_size < 512)
		{
			ft_putendl("entro en extend_heap SMALL");
			z_page->small.addr = mmap(0, getpagesize() * 2, PROT_READ
				| PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
			z_page->small.size = req_size;
			z_page->next = NULL;
		}
		if (req_size < 200)
		{
			ft_putendl("entro en extend_heap TINY");
			z_page->tiny.addr = mmap(0, getpagesize(), PROT_READ
				 | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
			 z_page->tiny.size = req_size;
			z_page->next = NULL;
			ft_putendl("SALGO en extend_heap TINY");
		}
	
			if (z_page->tiny.addr == MAP_FAILED
				|| z_page->small.addr == MAP_FAILED
				|| z_page->large.addr == MAP_FAILED)
			{

				ft_putendl("exit");
				return (NULL);
			}
				ft_putendl("here is the seg");
	}
	ft_putendl("salgo en extend_heap");
	return (z_page);
}


void			*my_malloc(size_t size_str)
{	
	ft_putendl("entro en malloc");	
	t_block		*b;
	t_block		last_ptr;
	size_t		n_units;

	n_units = ((size_str + sizeof(t_block) - 1) / sizeof(t_block)) + 1;
	if (!(base))
	{
		b = extend_heap(NULL, n_units);
		if (!b)
			return (NULL);
		base = b;
	}
	else
	{
		(void)last_ptr;

	}
	return (b->data);
	ft_putendl("salgo en malloc");
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		base = NULL;
		printf("%d\n", ft_atoi(av[1]));
		char *a = my_malloc(ft_atoi(av[1]));
		// a[0] = 'a';
		// printf("malloc address: %p\n", a);
		// printf("%s \n", a);
		// printf("chunk_bloc size %lu\n", sizeof(t_block));
	}
	else
	{
		return (0);
	}
}