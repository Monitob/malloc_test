/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/17 08:49:11 by jbernabe          #+#    #+#             */
/*   Updated: 2014/04/20 21:24:42 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_MALLOC
# define MY_MALLOC

# include <libft.h>

# define ALIGN_BITS(x)	(((((x) - 1) >> 2) << 2) + 4)
# define BLOCK_SIZE sizeof(struct s_block)
# define TINY 100
# define SMALL 1000
# define LARGE 4096
# define TOTAL_BYTES TINY + SMALL

typedef struct		s_zone
{
	void			*addr;
	size_t			size;
	int				is_free;
}					t_zone;

typedef struct		s_block
{
	t_zone			*tiny;
	t_zone			*small;
	t_zone			*large;
} 					t_block;

t_block base_malloc;
t_block	*free_list;


t_block			*tab_index(void);
void			init_heap(void);
void			assign_addr(t_block **tab, t_block *b);


#endif