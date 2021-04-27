# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/09 15:44:26 by cgutierr          #+#    #+#              #
#    Updated: 2021/04/26 19:50:38 by cgutierr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DAY			=	$(shell date +'%d/%m/%Y %H:%M')

NAME		=	cub3D

HEADER		=	./includes/cub.h

HEADER_B	=	./includes/cub_bonus.h

SRCS		=	./src/main.c \
				./src/handle_map_r.c \
				./src/handle_map_no.c \
				./src/handle_map_so.c \
				./src/handle_map_we.c \
				./src/handle_map_ea.c \
				./src/handle_map_s.c \
				./src/handle_map_f.c \
				./src/handle_map_c.c \
				./src/bits.c \
				./src/utils.c \
				./src/print.c \
				./src/parse_map_details.c \
				./src/parse_map_details_aux.c \
				./src/parse_map.c \
				./src/iter_cub_list.c \
				./src/map_matrix.c \
				./src/map_matrix_check.c \
				./src/start_graphics.c \
				./src/events.c \
				./src/rgb.c \
				./src/raycast.c \
				./src/rc_alg.c \
				./src/key_presses.c \
				./src/rotate.c \
				./src/comma_help.c \
				./src/bubble_sort.c \
				./src/calcular_distancias.c \
				./src/rc_sprites.c \
				./src/rc_wallcasting.c \
				./src/draw_walls.c

SRCS_B		=	./src_bonus/main_bonus.c \
				./src_bonus/handle_map_r_bonus.c \
				./src_bonus/handle_map_no_bonus.c \
				./src_bonus/handle_map_so_bonus.c \
				./src_bonus/handle_map_we_bonus.c \
				./src_bonus/handle_map_ea_bonus.c \
				./src_bonus/handle_map_s_bonus.c \
				./src_bonus/handle_map_f_bonus.c \
				./src_bonus/handle_map_c_bonus.c \
				./src_bonus/bits_bonus.c \
				./src_bonus/utils_bonus.c \
				./src_bonus/print_bonus.c \
				./src_bonus/parse_map_details_bonus.c \
				./src_bonus/parse_map_details_aux_bonus.c \
				./src_bonus/parse_map_bonus.c \
				./src_bonus/iter_cub_list_bonus.c \
				./src_bonus/map_matrix_bonus.c \
				./src_bonus/map_matrix_check_bonus.c \
				./src_bonus/start_graphics_bonus.c \
				./src_bonus/events_bonus.c \
				./src_bonus/rgb_bonus.c \
				./src_bonus/raycast_bonus.c \
				./src_bonus/rc_alg_bonus.c \
				./src_bonus/key_presses_bonus.c \
				./src_bonus/rotate_bonus.c \
				./src_bonus/comma_help_bonus.c \
				./src_bonus/bubble_sort_bonus.c \
				./src_bonus/calcular_distancias_bonus.c \
				./src_bonus/rc_sprites_bonus.c \
				./src_bonus/rc_wallcasting_bonus.c \
				./src_bonus/draw_walls_bonus.c \
				./src_bonus/set_textures_bonus.c \
				./src_bonus/key_presses_extra_bonus.c \
				./src_bonus/vida_bonus.c \
				./src_bonus/rc_floorcasting_bonus.c \
				./src_bonus/rc_aux_bonus.c

OBJS			=	$(SRCS:.c=.o)

OBJS_B			=	$(SRCS_B:.c=.o)

CC				=	gcc

CFLAGS			=	-Wall -Werror -Wextra -O3#-g3 -fsanitize=address

MLXFLAGS		=	libmlx.dylib -framework Metal -framework AppKit

RM				=	rm -f

MLX				=	./mlx/

MLXNAME			=	libmlx.dylib

MINILIBX		=	$(MLX)$(MLXNAME)

LIBFTPATH		=	./libft/

LIBFTNAME		=	libft.a

LIBFT			=	$(LIBFTPATH)$(LIBFTNAME)

$(NAME):		$(OBJS) $(LIBFT) $(MINILIBX)
				@echo $(YELLOW)Compiling ... $(RESET)
				$(CC) ${CFLAGS} ${OBJS} -I $(HEADER_B) ${LIBFT} ${MLXFLAGS} $(MLXNAME) -o ${NAME}

$(MINILIBX):
				@echo $(YELLOW)Make minilibx ... $(RESET)
				make -C $(MLX)
				cp $(MINILIBX) .

$(LIBFT):		
				@echo $(YELLOW)Make libft ... $(RESET)
				make re -C $(LIBFTPATH)

all:			$(NAME)

clean:
				@echo $(YELLOW)Cleaning ... $(RED)
				$(RM) $(OBJS) $(OBJS_B) $(LIBFTPATH)*.o $(MLX)*.o

fclean:			clean
				$(RM) $(NAME) $(LIBFT) $(MLXNAME) $(MINILIBX)

re:				fclean all

bonus:			$(OBJS_B) $(LIBFT) $(MINILIBX)
				@echo $(YELLOW)Compiling Bonus ... $(RESET)
				$(CC) ${CFLAGS} ${OBJS_B} -I $(HEADER) ${LIBFT} ${MLXFLAGS} $(MLXNAME) -o ${NAME}

#Colors
BLACK		:="\033[0;30m"
RED			:="\033[0;31m"
GREEN		:="\033[0;32m"
BROWN		:="\033[0;33m"
BLUE		:="\033[0;34m"
PURPLE		:="\033[0;35m"
CYAN		:="\033[0;36m"
LIGHT_GRAY	:="\033[0;37m"
DARK_GRAY	:="\033[1;30m"
LIGHT_RED	:="\033[1;31m"
LIGHT_GREEN	:="\033[1;32m"
YELLOW		:="\033[1;33m"
LIGHT_BLUE	:="\033[1;34m"
LIGHT_PURPLE:="\033[1;35m"
LIGHT_CYAN	:="\033[1;36m"
WHITE		:="\033[1;37m"
RESET		:="\x1b[0m"

#Easily execute your main
exe:
				@./cub3D resources/maps/map01.cub || true
save:
				@./cub3D resources/maps/map01.cub --save || true
# VALGRIND
#         --leak-check=full \ Each individual leak will be shown in detail
#         --show-leak-kinds=all \ Show all of "definite, indirect, possible, reachable" leak kinds in the "full" report.
#         --track-origins=yes \ Favor useful output over speed. This tracks the origins of uninitialized values, which could be very useful for memory errors. Consider turning off if Valgrind is unacceptably slow.
#         --verbose \ Can tell you about unusual behavior of your program. Repeat for more verbosity.
#         --log-file=valgrind-out.txt \ Write to a file. Useful when output exceeds terminal space.
#         ./executable exampleParam1
# @valgrind --leak-check=full --track-origins=yes --log-file=./resources/info/valgrind-out.txt ./cub3D resources/maps/map01.cub --save || true

#Easily push content to our repo
git:
				@echo $(YELLOW)Status:$(RESET)
				@git status || true 
				@echo $(YELLOW)GIT add ... $(RESET)
				@git add . || true 
				@echo $(YELLOW)GIT commit ... $(RESET)
				@git commit -m "$(DAY)" || true 
				@echo $(YELLOW)GIT push ... $(RESET)
				@git push -u origin master || true 

#Easily check the norm
norminette:
				@echo $(YELLOW)Norminette...
				@echo $(GREEN)
				@norminette $(SRCS) $(SRCS_B) $(HEADER) $(HEADER_B) ./libft/*.c ./libft/*.h | grep 'OK' || true 
				@echo $(RED)
				@norminette $(SRCS) $(SRCS_B) $(HEADER) $(HEADER_B) ./libft/*.c ./libft/*.h | grep 'Error!\|line:' || true
						
.PHONY:			all clean fclean re
