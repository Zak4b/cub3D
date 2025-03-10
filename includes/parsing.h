/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:51:45 by asene             #+#    #+#             */
/*   Updated: 2025/03/10 15:01:10 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

#ifndef PARSING_H
# define PARSING_H

int		open_file(char *path);
t_map	*read_file(int fd);
int		check_map_data(t_map *map);
t_map	*list_to_map(t_list *lst);

#endif