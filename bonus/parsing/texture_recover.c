/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_recover.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmustin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 12:25:54 by fmustin           #+#    #+#             */
/*   Updated: 2022/10/12 12:25:56 by fmustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	texture_already_fill(char **str, t_data *data)
{
	if ((ft_strcmp(str[0], "NO") == 0 && data->tex.textures[0] != NULL)
		|| (ft_strcmp(str[0], "SO") == 0 && data->tex.textures[1] != NULL)
		|| (ft_strcmp(str[0], "WE") == 0 && data->tex.textures[2] != NULL)
		|| (ft_strcmp(str[0], "EA") == 0 && data->tex.textures[3] != NULL))
		return (0);
	return (1);
}

int	stock_texture(char *file, t_data *data)
{
	char	**str;

	str = file_to_texture(file);
	if (!str)
		return (0);
	if (!texture_already_fill(str, data))
	{
		printf("Error\n");
		printf("infos about texture are not correct\n");
		free_tab(str);
		return (0);
	}
	if (ft_strcmp(str[0], "NO") == 0 && data->tex.textures[0] == NULL)
		data->tex.textures[0] = ft_strdup_modif(str[1], '\n');
	if (ft_strcmp(str[0], "SO") == 0 && data->tex.textures[1] == NULL)
		data->tex.textures[1] = ft_strdup_modif(str[1], '\n');
	if (ft_strcmp(str[0], "WE") == 0 && data->tex.textures[2] == NULL)
		data->tex.textures[2] = ft_strdup_modif(str[1], '\n');
	if (ft_strcmp(str[0], "EA") == 0 && data->tex.textures[3] == NULL)
		data->tex.textures[3] = ft_strdup_modif(str[1], '\n');
	free_tab(str);
	return (1);
}

int	texture_is_full(t_data *data)
{
	if (data->tex.textures[0] != NULL
		&& data->tex.textures[1] != NULL && data->tex.textures[2] != NULL
		&& data->tex.textures[3] != NULL)
		return (1);
	else
		return (0);
}

int	recup_texture(char *file, t_data *data)
{
	if (!stock_texture(file, data))
		return (0);
	return (1);
}

int	texture_recover(char *file, t_data *data)
{
	if (!recup_texture(file, data))
	{
		free_texture(data);
		return (0);
	}
	return (1);
}
