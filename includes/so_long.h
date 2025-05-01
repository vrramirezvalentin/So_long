#ifndef SO_LONG_H
# define so_long

# include <strings.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>
# include <fcntl.h>
# include <X11/keysym.h>
# include "mlx.h"


#ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
#endif

#ifndef NUM_IMAGES
#  define NUM_IMAGES 4
#endif


enum e_image_type
{
    FLOOR,
    WALL,
    COIN,
    EXIT,
    PLAYER
};

typedef struct s_image
{
    void    *img;
    char    *relative_path;
    int     img_width;
    int     img_height;
}           t_image;

typedef struct s_animation {
    void    *sprite[3];    // Tableau pour les 3 frames de sprites
    int     current_frame; // Frame actuelle pour l'animation
    int     sprite_width;
    int     sprite_height;
} t_animation;

typedef struct s_map {
    char **map;
    char **copy_map;
    int width;
    int height;
} t_map;

typedef struct s_player {
    int x;
    int y;
    int moves;
} t_player;

typedef struct  s_data
{
    void        *mlx_ptr;
    void        *win_ptr;
    int         total_coins;
    int         coins;
    t_image     images[NUM_IMAGES];
    t_map       map;
    t_player    player;
    t_animation animation;
}               t_data;




//GNL
void ft_bzero(void *s, size_t n);
size_t ft_strlen(const char *s);
char *ft_strjoin(char const *s1, char const *s2);
char *ft_strchr(const char *s, int c);
void *ft_memcpy(void *dest, const void *src, size_t n);
char *clean_stash(char *stash);
char *buftostash(int fd, char *stash);
char *extract_line(int i, char **stash);
char *ifstashnotnull(char *stash);
char *get_next_line(int fd);

//main
int ft_clean(t_data *data);
int close_window_esc(int keysym, t_data *data);


//maps
int count_lines(const char *filename);
int init_map(t_map *map, const char *filename);
int load_map(t_map *map, const char *filename);
int init_and_load_map(t_map *map, const char *filename);
void free_map(t_map *map);

//copy_map
void free_copy_map(t_map *map);
void free_sprites(t_data *data);


//utils
//strdup
char *ft_strdup(const char *s);
//itoa
char	*ft_itoa(int n);

#endif