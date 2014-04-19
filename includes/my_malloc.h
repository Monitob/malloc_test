/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/17 08:49:11 by jbernabe          #+#    #+#             */
/*   Updated: 2014/04/19 05:10:26 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_MALLOC
# define MY_MALLOC

# include <libft.h>

# define ALIGN_BITS(x)	(((((x) - 1) >> 2) << 2) + 4)
# define BLOCK_SIZE sizeof(struct s_block)

typedef struct		s_zone
{
	void			*addr;
	size_t			size;
}					t_zone;

typedef struct		s_block
{
	t_zone			tiny;
	t_zone			small;
	t_zone			large;
	struct s_block	*next;
	int				is_available;
	char			data[1];
} 					t_block;

void	*base = NULL;
t_block	*free_list;

void			*get_base(void);


#endif