##
## EPITECH PROJECT, 2018
## PROJECT
## File description:
## Makefile
##

SRC	=	utils/my_strlen.c   \
		utils/my_str_isnum.c    \
		utils/my_getnbr.c   \
		utils/split_str.c   \
		utils/my_strdup.c   \
		utils/my_arrlen.c   \
		utils/my_strcmp.c   \
		utils/free_array.c   \
		utils/rect.c	\
		utils/vector.c	\
		utils/create_window.c	\
		room/load_tiles.c	\
		room/create_doors.c	\
		room/destroy_room.c	\
		room/draw_room.c	\
		room/create_room.c	\
		room/create_objects.c	\
		room/create_objects_two.c	\
		room/handle_objects.c	\
		alex/player/animate_move_player.c	\
		alex/player/change_direction_player.c	\
		alex/player/check_move_player.c \
		alex/player/create_player.c	\
		alex/player/manage_player.c	\
		alex/player/manage_health.c \
		alex/player/player_attack.c	\
		alex/player/damage_boss.c \
		alex/player/check_for_wall.c \
		alex/player/check_for_diagonal_wall_walk.c \
		alex/inventory/create_inventory.c \
		alex/inventory/manage_inventory.c \
		alex/inventory/level_screen.c \
		alex/buttons/create_menu_button.c	\
		alex/buttons/create_level_button.c \
		alex/buttons/put_space_into_hover.c	\
		alex/destroy/destroy_buttons_and_visuals.c	\
		alex/destroy/destroy_menu.c	\
		alex/destroy/destroy_player.c	\
		alex/pause_menu/create_pause.c	\
		alex/pause_menu/manage_pause_and_menu_event.c	\
		alex/pause_menu/pause_menu.c \
		alex/utils/combine_strings.c \
		alex/utils/add_to_last_button.c	\
		alex/utils/create_vector.c	\
		alex/utils/my_int_to_str.c	\
		alex/utils/rect.c	\
		alex/utils/text.c	\
		alex/utils/push_string_in.c \
		alex/utils/my_str_to_word_array.c \
		alex/talking_to_others/starting_sequence.c \
		alex/talking_to_others/create_textbox.c \
		alex/talking_to_others/create_dialouge.c \
		alex/talking_to_others/manage_dialouge.c \
		alex/talking_to_others/interact_with_npc.c \
		patryk/boss.c \
		patryk/move.c \
		patryk/transform.c \
		patryk/attack.c \
		johannes/boss_attack_circle.c \
		main.c	\
		johannes/destroy_boss.c	\
		music.c	\
		johannes/ingame.c \
		johannes/destroy.c \
		johannes/camera.c \
		johannes/create_camera.c \
		johannes/items.c	\
		johannes/ending.c	\
		manage_ending_buttons.c \
		johannes/display_end.c	\
		patryk/menu.c \
		johannes/boss_dmg_calculation.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=   my_rpg


CC	=	gcc

CFLAGS	+=	-g -W -Wall -Wextra # -Werror

all:	$(NAME)

$(NAME):	$(OBJ)
			$(CC) -o $(NAME) $(OBJ) -l csfml-graphics -l csfml-system -l csfml-audio -l csfml-window -lm

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
