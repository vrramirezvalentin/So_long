NAME = so_long
CC = cc
FLAGS = -Wall -Wextra -Werror -g
LMLX = -L./minilibx-linux -lmlx -L/usr/lib/X11 -lXext -lX11
INCLUDES = -I./includes -I./libft/includes -I./minilibx-linux
SRCS_DIR = srcs
OBJS_DIR = objs
SRCS =  $(SRCS_DIR)/main.c \
                $(SRCS_DIR)/get_next_line_utils.c \
                $(SRCS_DIR)/get_next_line.c \
				$(SRCS_DIR)/maps.c \
                $(SRCS_DIR)/utils.c
                # $(SRCS_DIR)/input.c \
                $(SRCS_DIR)/utils_map.c \
                $(SRCS_DIR)/utils_map2.c \


OBJS = $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS) minilibx-linux/libmlx.a
		$(CC) -o $(NAME) $(OBJS) $(LMLX)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
		@mkdir -p $(OBJS_DIR)
		$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

minilibx-linux/libmlx.a:
		$(MAKE) -C minilibx-linux

clean:
		rm -f $(OBJS)
		rm -rf $(OBJS_DIR)
		$(MAKE) -C minilibx-linux clean

fclean: clean
		rm -f $(NAME)
		$(MAKE) -C minilibx-linux clean

re: fclean all

.PHONY: all clean fclean re