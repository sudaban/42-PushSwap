/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GC.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaban <sdaban@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 17:46:47 by sdaban            #+#    #+#             */
/*   Updated: 2026/04/30 17:49:41 by sdaban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GC_H
# define GC_H

# include <stddef.h>

typedef struct s_memory
{
	void			*ptr;
	struct s_memory	*next;
}					t_memory;

void	*memory_malloc(size_t size);
void	memory_free(void *ptr);
void	memory_cleanup(int status);
#endif