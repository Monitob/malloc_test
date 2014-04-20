/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 02:00:07 by jbernabe          #+#    #+#             */
/*   Updated: 2014/04/20 04:14:47 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/mman.h>
#include <stdio.h>
#include "my_malloc.h"

t_block		*tab_index(void)
{
	t_block	*tab;

	tab =  mmap(0, TINY + SMALL, PROT_WRITE
		| PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	return (tab);
}

void		assign_addr(t_block **tab, t_block *b)
{
	ft_putendl("test de addr");
	//printf("entro en assign addr tab %p,  b -> %p", tab, b);
	int		i;

	i = 0;
	while (i < TOTAL_BYTES)
	{
		if (i == 0)
		{	ft_putendl("test de addr1");
			tab[i]->tiny->addr = b->tiny->addr;
			ft_putendl("test de addr2");
			printf("direccion de tab %p", tab[i]->tiny->addr);
		}
		if (i == SMALL + 1)
		{
			ft_putendl("test de addr3");
			tab[i]->small->addr = b->small->addr;
			ft_putendl("test de addr4");
		}
		i++;
	}
	ft_putendl("sali del assign_addr");
}
