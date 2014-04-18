/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/17 08:49:11 by jbernabe          #+#    #+#             */
/*   Updated: 2014/04/18 04:08:34 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifendef MY_MALLOC
# define MY_MALLOC

# define ALIGN_BITS(X)	(((((x) - 1) >> 2) << 2) + 4)
# define BLOCK_SIZE sizeof(struct s_block)

typedef struct	s_block
{
	size_t		size;
	t_block		next;
	int			available;

} 				t_block;

#endif