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
		printf("infos about texture are not correct\n");
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

int	recup_texture(char **file, t_data *data)
{
	int	i;

	i = 0;
	malloc_texture(data);
	while (file[i] != NULL && !texture_is_full(data))
	{
		if (file[i] && file[i][0] != '\n' && file[i][0] != '\0')
			if (!stock_texture(file[i], data))
				return (0);
		i++;
	}
	if (file[i] == NULL)
	{
		printf("file not complet\n");
		return (0);
	}
	return (i);
}

int	texture_recover(char **file, t_data *data, int i)
{
	i = recup_texture(file, data);
	if (i == 0)
		return (0);
	if (file[i] == NULL)
		return (0);
	return (i);
}