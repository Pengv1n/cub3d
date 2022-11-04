#include <stdio.h>
#include "../cub3d.h"
#include <math.h>

#define keyLeft		65361
#define keyUp 		65362
#define keyRight	65363
#define keyDown		65364

#define mapWidth 24
#define mapHeight 24
#define screenWidth 640
#define screenHeight 480

int worldMap[mapWidth][mapHeight]=
		{
				{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
				{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
				{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
		};

void	ft_declare(t_all s, char *file, int bmp)
{

}

void	ft_init(char *file, int bmp)
{
	t_all	s;
	t_mlx	mlx;

	mlx.ptr = NULL;
	s.mlx = mlx;
	ft_declare(s, file, bmp);
}



//int main(int argc, char **argv)
//{
//	if (ft_namecheck(argv[1], "cub"))
//		ft_init(argv[1], 0);
//	else
//		write(2, "Error: Invalid arguments\n", 26);
//
//	return (0);
//}

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	double	*posX;
	double	*posY;
	int		**worldMap;
	double	*dirX;
	double	*dirY;
	double	*moveSpeed;
	double	*rotSpeed;
	double	*planeX;
	double	*planeY;
	t_data	*img;
}				t_vars;

void	calc_disp(t_vars *vars)
{
//	ft_bzero(vars->img->img, screenHeight * screenHeight * 4);
//	mlx_destroy_image(vars->mlx, vars->img);
//	free(vars->img->img);
	vars->img->img = mlx_new_image(vars->mlx, screenWidth, screenHeight);
	vars->img->addr = mlx_get_data_addr(vars->img->img, &vars->img->bits_per_pixel, &vars->img->line_length,
								 &vars->img->endian);
	for (int x = 0; x < screenWidth; x++)
	{
		//calculate ray position and direction
		double cameraX = 2 * x / (double) screenWidth - 1; //x-coordinate in camera space
		double rayDirX = *vars->dirX + *vars->planeX * cameraX;
		double rayDirY = *vars->dirY + *vars->planeY * cameraX;

		//which box of the map we're in
		int mapX = (int) *vars->posX;
		int mapY = (int) *vars->posY;

		//length of ray from current position to next x or y-side
		double sideDistX;
		double sideDistY;

		//length of ray from one x or y-side to next x or y-side
		double deltaDistX = (rayDirX == 0) ? 1e30 : abs(1 / rayDirX);
		double deltaDistY = (rayDirY == 0) ? 1e30 : abs(1 / rayDirY);
		double perpWallDist;

		//what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;
		int hit = 0; //was there a wall hit?
		int side; //was a NS or a EW wall hit?

		//calculate step and initial sideDist
		if (rayDirX < 0) {
			stepX = -1;
			sideDistX = (*vars->posX - mapX) * deltaDistX;
		} else {
			stepX = 1;
			sideDistX = (mapX + 1.0 - *vars->posX) * deltaDistX;
		}

		if (rayDirY < 0) {
			stepY = -1;
			sideDistY = (*vars->posY - mapY) * deltaDistY;
		} else {
			stepY = 1;
			sideDistY = (mapY + 1.0 - *vars->posY) * deltaDistY;
		}

//		printf("X %f = %f\n", sideDistX, deltaDistX);
//		printf("Y %f = %f\n", sideDistY, deltaDistY);

		while (hit == 0) {
			//jump to next map square, either in x-direction, or in y-direction
			if (sideDistX < sideDistY) {
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			} else {
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			//Check if ray has hit a wall
			if (worldMap[mapX][mapY] > 0) {
				hit = 1;
			}
		}

		//Calculate distance projected on camera direction (Euclidean distance would give fisheye effect!)
		if (side == 0) {
			perpWallDist = (sideDistX - deltaDistX);
		} else {
			perpWallDist = (sideDistY - deltaDistY);
		}

		//Calculate height of line to draw on screen
		int lineHeight = perpWallDist != 0.0 ? (int) (screenHeight / perpWallDist) : 0.0;

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + screenHeight / 2;
		if (drawStart < 0) {
			drawStart = 0;
		}

		int drawEnd = lineHeight / 2 + screenHeight / 2;
		if (drawEnd >= screenHeight) {
			drawEnd = screenHeight - 1;
		}

		//choose wall color
		int color;
		switch (worldMap[mapX][mapY]) {
			case 1:
				color = 0x00FF0000;
				break; //red
			case 2:
				color = 0x0000FF00;
				break; //green
			case 3:
				color = 0x000000FF;
				break; //blue
			case 4:
				color = 0x00FFFFFF;
				break; //white
			default:
				color = 0x00FFFF00;
				break; //yellow
		}

		//give x and y sides different brightness
		if (side == 1) { color = color / 2; }

		while (drawStart != drawEnd) {
			my_mlx_pixel_put(vars->img, x, drawStart, color);
			drawStart++;
		}
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->	img, 0, 0);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == keyUp)
	{
		if (worldMap[(int)(*vars->posX + *vars->dirX * *vars->moveSpeed)][(int)(*vars->posY)] == 0)
			*(vars->posX) += *vars->dirX * *vars->moveSpeed;
		if (worldMap[(int)(*vars->posX)][(int)(*vars->posY + *vars->dirY * *vars->moveSpeed)] == 0)
			*(vars->posY) += *vars->dirY * *vars->moveSpeed;
	}
	//move backwards if no wall behind you
	if (keycode == keyDown)
	{
//		printf("%i - %i\n", (int)(*vars->posX - *vars->dirX * *vars->moveSpeed), (int)(*vars->posY));
		if (worldMap[(int)(*vars->posX - *vars->dirX * *vars->moveSpeed)][(int)(*vars->posY)] == 0)
			*(vars->posX) -= *vars->dirX * *vars->moveSpeed;
		if (worldMap[(int)(*vars->posX)][(int)(*vars->posY - *vars->dirY * *vars->moveSpeed)] == 0)
			*(vars->posY) -= *vars->dirY * *vars->moveSpeed;
	}
	//rotate to the right
	if (keycode == keyRight)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = *vars->dirX;
		*(vars->dirX) = *vars->dirX * cos(-*vars->rotSpeed) - *vars->dirY * sin(-*vars->rotSpeed);
		*(vars->dirY) = oldDirX * sin(-*vars->rotSpeed) + *vars->dirY * cos(-*vars->rotSpeed);
		double oldPlaneX = *vars->planeX;
		*(vars->planeX) = *vars->planeX * cos(-*vars->rotSpeed) - *vars->planeY * sin(-*vars->rotSpeed);
		*(vars->planeY) = oldPlaneX * sin(-*vars->rotSpeed) + *vars->planeY * cos(-*vars->rotSpeed);
	}
	//rotate to the left
	if (keycode == keyLeft)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = *vars->dirX;
		*(vars->dirX) = *vars->dirX * cos(*vars->rotSpeed) - *vars->dirY * sin(*vars->rotSpeed);
		*(vars->dirY) = oldDirX * sin(*vars->rotSpeed) + *vars->dirY * cos(*vars->rotSpeed);
		double oldPlaneX = *vars->planeX;
		*vars->planeX = *vars->planeX * cos(*vars->rotSpeed) - *vars->planeY * sin(*vars->rotSpeed);
		*vars->planeY = oldPlaneX * sin(*vars->rotSpeed) + *vars->planeY * cos(*vars->rotSpeed);
	}
//	printf("%f - %f\n", *vars->dirX, *vars->dirY);
//	printf("%f - %f\n", *vars->planeX, *vars->planeY);
	calc_disp(vars);

	printf("Hello from key_hook! - %i\n", keycode);
	return (0);
}

int main(int argc, char **argv)
{
	double posX = 22, posY = 12; //x and y start position
	double dirX = -1, dirY = 0; //initial direction vector
	double planeX = 0, planeY = 0.66; //the 2d raycaster version of camera plane

	double time = 0; //time of current frame
	double oldTime = 0; //time of previous frame

	void	*mlx;
	void	*mlx_win;

	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, screenWidth, screenHeight, "Raycaster");

	img.img = mlx_new_image(mlx, screenWidth, screenHeight);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								 &img.endian);

	t_vars	vars;

	double	frameTime = 0.03;
	//speed modifiers
	double moveSpeed = frameTime * 5.0; //the constant value is in squares/second
	double rotSpeed = frameTime * 3.0; //the constant value is in radians/second

	vars.mlx = mlx;
	vars.win = mlx_win;
	vars.dirX = &dirX;
	vars.dirY = &dirY;
	vars.moveSpeed = &moveSpeed;
	vars.posX = &posX;
	vars.posY = &posY;
	vars.rotSpeed = &rotSpeed;
	vars.worldMap = (int **)worldMap;
	vars.planeX = &planeX;
	vars.planeY = &planeY;
	vars.img = &img;

	calc_disp(&vars);
	mlx_key_hook(mlx_win, key_hook, &vars);
	mlx_loop(mlx);

	return (0);
}