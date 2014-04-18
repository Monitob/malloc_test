/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/17 08:47:32 by jbernabe          #+#    #+#             */
/*   Updated: 2014/04/18 04:56:31 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/mman.h>
/*
t_block		find_a_block(t_block *last, size_t size)
{
	t_block ;


}*/
void	*my_malloc(size_t size_str)
{
	mmap(0, size_str + 1, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE,
						-1, 0)
}

int main(int ac, char **av)
{
	my_malloc(av[2]);
}