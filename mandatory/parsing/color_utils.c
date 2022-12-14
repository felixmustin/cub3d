/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmustin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 12:25:01 by fmustin           #+#    #+#             */
/*   Updated: 2022/10/12 12:25:04 by fmustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	check_color(char **split_color, int *i)
{
	int	color_value;

	color_value = 0;
	if (ft_strlen(split_color[2]) > 1)
	{
		while (*i < ft_strlen_split(split_color))
		{
			color_value = ft_atoi(split_color[*i]);
			if (color_value <= 255 && color_value >= 0)
				*i += 1;
			else
				break ;
		}
	}
}

int	get_color(char	**str)
{
	char	**split_color;
	int		i;
	int		color;

	i = 0;
	color = -1;
	split_color = ft_split(str[1], ',');
	if (!split_color)
		return (0);
	if (ft_strlen_split(split_color) != 3)
	{
		free_tab(split_color);
		return (0);
	}
	check_color(split_color, &i);
	if (i == 3)
	{
		color = (pow(256, 2) * ft_atoi(split_color[0])) + \
			(256 * ft_atoi(split_color[1])) + ft_atoi(split_color[2]);
	}
	free_tab(split_color);
	return (color);
}

char	*split_to_string(char **split)
{
	int		i;
	char	*str;
	char	*str1;

	i = 2;
	str = ft_strdup(split[1]);
	if (!str)
		return (NULL);
	while (split[i])
	{
		str1 = ft_strjoin(str, split[i]);
		free(str);
		if (!str1)
			return (NULL);
		str = ft_strdup(str1);
		free(str1);
		if (!str)
			return (NULL);
		i++;
	}
	return (str);
}

char	**file_to_string(char *file)
{
	char	**str;
	char	**split;

	split = NULL;
	str = ft_split(file, 32);
	if (!str)
		return (NULL);
	if (ft_strlen_split(str) > 2)
	{
		split = fill_color(str);
		if (!split)
		{
			free_tab(str);
			return (NULL);
		}
		return (split);
	}
	return (str);
}
