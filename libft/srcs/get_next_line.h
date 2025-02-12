/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:25:04 by asene             #+#    #+#             */
/*   Updated: 2025/02/12 12:49:57 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif
# if BUFFER_SIZE < 1
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 1
# elif BUFFER_SIZE > 1000000
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif
#endif