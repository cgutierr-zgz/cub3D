/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 19:48:28 by cgutierr          #+#    #+#             */
/*   Updated: 2021/04/22 10:30:40 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub_bonus.h"

/*
** If there was a problem reading the file we handle the error
*/

static void	error_read(t_cub *cub)
{
	free_content_cub(cub);
	ft_lstclear(&cub->map.map_list, clear_matrix_content);
	print_simple_errors("An error ocurred reading the file");
	exit(1);
}

/*
** Aux function to get rid of the norm
*/

static int	reading(int *n, t_cub *cub, char **line)
{
	*n = get_next_line(cub->fd, line);
	return (*n);
}

/*
** We loop with get_next_line trogh the given fd storing the data depending on
**	wich point we are
** If everything it's OK -> start_graphics
*/

static void	read_file(t_cub *cub)
{
	char	*line;
	int		n;

	while (reading(&n, cub, &line) >= 0)
	{
		cub->actual_line++;
		if (line[0] == '\0')
		{
			if (cub->is_map)
				cub->end_map = 1;
			free(line);
		}
		else if (cub->elems != 255)
			parse_specificators(cub, line);
		else
			parse_map(line, cub);
		if (n == 0)
			break ;
	}
	if (n == -1)
		error_read(cub);
	start_graphics(cub);
}

/*
** We check if the map is a valid file
** Check of the '--save' command
** If everything it's OK -> read_file
*/

static void	good_args(int argc, char **argv, t_cub *cub)
{
	if (ft_strrchr(argv[1], '.')
		&& (!ft_strcmp(".cub", ft_strrchr(argv[1], '.'))))
	{
		print_simple_errors("Map must be a \".cub\" file");
		exit(1);
	}
	cub->fd = open(argv[1], O_RDONLY);
	if (cub->fd < 0)
	{
		print_simple_errors("An error ocurred when opening the map");
		exit(1);
	}
	if (argc == 3)
	{
		if (!ft_strcmp("--save", argv[2]))
		{
			printf("Error\nUnknown command: ");
			printf(W_B_RED "\"%s\"\n" RESET, argv[2]);
			exit(1);
		}
		cub->save_first = 1;
	}
	read_file(cub);
}

/*
** First we initialize our main structure
** We do some error checking
** If everything it's OK -> good_args
*/

int	main(int argc, char **argv)
{
	t_cub	cub;

	ft_bzero(&cub, sizeof(t_cub));
	if (argc < 2)
	{
		print_simple_errors("A map is needed");
		exit(1);
	}
	if (argc == 2 || argc == 3)
	{
		if (!(ft_strcmp("./cub3D", argv[0]) || ft_strcmp("cub3D", argv[0])))
		{
			print_simple_errors("Executable must be a \"cub3D\" file");
			exit(1);
		}
		good_args(argc, argv, &cub);
	}
	if (argc > 3)
	{
		print_simple_errors("Too many arguments");
		exit(1);
	}
	return (0);
}
