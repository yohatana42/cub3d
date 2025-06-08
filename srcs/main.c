/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:04:52 by yohatana          #+#    #+#             */
/*   Updated: 2025/06/08 15:38:15 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
1. マップファイルをデータにする t_data, map_file
	error: malloc失敗
		free : t_data
2. マップファイルのチェック　true/false, t_data
	error: open, 要件を満たさないとき, malloc失敗
		free : t_data
3. mlxの初期化 t_mlx, t_data
	error: malloc失敗, mlx初期化
		free : t_data, t_mlx
4. 描画	void, t_data t_mlx
	error : なし
5. mlxイベントの処理 void, t_data t_mlx
	error : なし
6. クリーンアップ void, t_data t_mlx
	error : なし
*/
int	main(int argc, char **argv)
{
	(void)argv;
	t_map_data	map_data;
	t_mlx_data	mlx_data;

	if (argc != 2)
		exit_error("usage: ./cub3d [file name].cub");
	init_data(argv[1], &map_data);
	validation_map(&map_data);
	init_mlx(&mlx_data);
	draw_init(&mlx_data, &map_data);
	mlx_event(&mlx_data, &map_data);
	draw(&mlx_data, &map_data);
	clean_up(&mlx_data, &map_data);
	return (EXIT_SUCCESS);
}
