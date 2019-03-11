/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnete <lbonnete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 15:32:17 by lbonnete          #+#    #+#             */
/*   Updated: 2019/03/11 15:35:07 by lbonnete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_realloc_map(char **map, int len)
{
	int		i;
	char	**ret;

	if (!(ret = (char **)malloc(sizeof(char *) * len + 1)))
		return (0);
	ret[len] = NULL;
	if (map)
	{
		i = 0;
		while (i < len)
		{
			if (!(ret[i] = ft_strdup(map[i])))
				return (0);
			i++;
		}
		free(ret[i - 1]);
		destroy_tab(&map);
	}
	return (ret);
}
