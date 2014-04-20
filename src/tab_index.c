/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 02:00:07 by jbernabe          #+#    #+#             */
/*   Updated: 2014/04/20 20:48:30 by jbernabe         ###   ########.fr       */
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
	int		i;

	i = 0;
	while (i <= TOTAL_BYTES)
	{
		printf("%d no while, TAB ADDR%p, B %p\n", i, &tab[i], b++);
		if (i == 0)
		{	ft_putendl("test de addr1");
		 	printf("base %p\n", base_malloc.tiny);
		 	ft_putendl("test de addr2");
		}
		i++;
	}
	ft_putendl("sali del assign_addr");
}
