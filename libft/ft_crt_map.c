/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_crt_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 15:42:39 by aherrera          #+#    #+#             */
/*   Updated: 2018/06/29 17:01:48 by aherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_crt_map(int x, int y)
{
	char	**words;
	int		i;

	words = (char **)malloc((x + 1) * sizeof(char *));
	i = -1;
	while (++i < y)
		words[i] = (y == 0 ? NULL : ft_strnew(y));
	words[i] = NULL;
	return (words);
}
