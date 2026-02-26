#################################################################################################################
#                                           VARIABLES SET                                                       #
#################################################################################################################
NAME = cub3D

CC = gcc
FLAGS = -Wall -Wextra -Werror -g

INCLUDES = includes
OBJ_DIR = objets/
VPATH = srcs
UNAME_S = ${shell uname -s}

ifeq (${UNAME_S}, Linux)
	EXTRA = -L${MINILIBX} -lXext -lX11 -lm -lz
else ifeq (${UNAME_S}, Darwin)
	EXTRA = -L${MINILIBX} -lmlx -framework OpenGl -framework AppKit
endif

SRCS = main.c extension.c get_file.c clean.c get_texture.c get_map.c\
		get_rgb.c begin_file.c file_checking.c get_infos.c\
		parsing.c dda.c convert_rgb.c announce.c init_texture.c\
		convert_rgb_2.c init_data.c mlx_hook.c draw.c mlx_hook_2.c\
		utils_begin.c utils_get_map.c tools.c clean2.c

SRCS_PATH = ${addprefix srcs/, ${SRCS}}
INCLUDES_PATH = ${addprefix includes/, ${INCLUDES}}
OBJS = ${patsubst srcs/%.c, ${OBJ_DIR}/%.o, ${SRCS_PATH}}

LIB = ${MINILIBX_A} ${LIBFT_A}

LIBFT = ./libft/
LIBFT_A= ./libft.a

MINILIBX = ./minilibx-linux/
MINILIBX_A = ./libmlx.a
#################################################################################################################
#                                           RULES COMPILATION                                                   #
#################################################################################################################
all: ${LIBFT_A} ${MINILIBX_A} ${NAME}

${NAME}: ${OBJS}
	${CC} ${FLAGS} ${OBJS} ${LIB} ${EXTRA} -I ${INCLUDES} -o ${NAME}

${OBJ_DIR}/%.o: %.c
	@mkdir -p ${OBJ_DIR}
	${CC} ${FLAGS} -c $< -o $@ -I${INCLUDES}

${LIBFT_A}:
	@make -C ${LIBFT}
	@cd ${LIBFT} && cp ${LIBFT_A} ..

${MINILIBX_A}:
	@make -C ${MINILIBX}
	@cd ${MINILIBX} && cp ${MINILIBX_A} ..
#################################################################################################################
#                                           RULES CLEAN                                                         #
#################################################################################################################
clean:
	rm -rf ${OBJ_DIR}/ ${OBJS} ${OBJ_DIR_BONUS}/ ${OBJS_BONUS}

fclean: clean
	rm -rf ${NAME} ${BONUS_NAME} ${LIBFT_A} ${MINILIBX_A}

fclean_lib:
	@make fclean -C ${LIBFT}
	@rm -rf ${LIBFT_A}
	@make clean -C ${MINILIBX}
	@rm -rf ${MINILIBX_A}

re: fclean_lib fclean all
#################################################################################################################
#                                           NO RELINK                                                           #
#################################################################################################################

.PHONY: all clean fclean re fclean_lib bonus

#################################################################################################################
#                                           BONUS	                                                            #
#################################################################################################################
BONUS_NAME =

OBJS_BONUS = ${addprefix ${OBJ_DIR_BONUS}/,${SRCS_BONUS:.c=.o}}
OBJ_DIR_BONUS = objets_bonus

${OBJ_DIR_BONUS}/%.o: %.c ${INCLUDES}
	@mkdir -p ${OBJ_DIR_BONUS}
	${CC} ${FLAGS} -c $< -o $@

${BONUS_NAME}: ${OBJS_BONUS}
	${CC} ${FLAGS} ${OBJS_BONUS} ${LIB} ${EXTRA} -I ${INCLUDES} -o ${BONUS_NAME}

bonus: ${MINILIBX_A} ${LIBFT_A} ${BONUS_NAME}