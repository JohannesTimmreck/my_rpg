/*
** EPITECH PROJECT, 2018
** PROJECT NAME
** File description:
** FILE NAME
*/

#include "../rpg.h"

void move_camera(camera_t *camera)
{
    switch (camera->anim_direction) {
        case Up:
            sfView_move(camera->view, create_vectf(0, (float)-1000/40));
            camera->pos.y -= (float)1000/40;
            break;
        case Right:
            sfView_move(camera->view, create_vectf((float)1850/40, 0));
            camera->pos.x += (float)1850/40;
            break;
        case Down:
            sfView_move(camera->view, create_vectf(0, (float)1000/40));
            camera->pos.y += (float)1000/40;
            break;
        case Left:
            sfView_move(camera->view, create_vectf((float)-1850/40, 0));
            camera->pos.x -= (float)1850/40;
    }
}

void move_player_while_roomchange(player_t *player, direction_t direction)
{
    sfVector2f offset = create_vectf(0, 0);

    switch (direction) {
        case Up:
            offset.y = -100/40;
            break;
        case Right:
            offset.x = 100/40;
            break;
        case Down:
            offset.y = 100/40;
            break;
        case Left:
            offset.x = -100/40;
    }
    player->centerpoint = move_vector(player->centerpoint, offset);
    player->visual->pos = move_vector(player->visual->pos, offset);
    sfSprite_setPosition(player->visual->sprite, player->visual->pos);
    player->visual->hitbox.top += offset.y;
    player->visual->hitbox.left += offset.x;
}

void animate_room_change(ingame_t *ingame)
{
    sfTime time = sfClock_getElapsedTime(ingame->camera->timer);
    float sec = time.microseconds / 1000000.0;

    if (sec > 0.01) {
        move_camera(ingame->camera);
        ingame->camera->animation_cicle += 1;
        sfClock_restart(ingame->camera->timer);
        move_player_while_roomchange(ingame->player,
            ingame->camera->anim_direction);
    }
    stop_room_change_animation(ingame);
}

void stop_room_change_animation(ingame_t *ingame)
{
    if (ingame->camera->animation_cicle < 40)
        return;
    ingame->camera->animation_cicle = 0;
    ingame->camera->animation = sfFalse;
    destroy_room(ingame->room);
    ingame->room = create_room(ingame->next_room->config->current_path);
    destroy_room(ingame->next_room);
    ingame->next_room = NULL;
}

room_t *check_for_roomchange(door_t **doors, sfVector2f *player_pos,
    camera_t *camera)
{
    room_t *new_room = NULL;

    for (int i = 0; doors[i] != NULL; i++) {
        if (sfFloatRect_contains(&doors[i]->enter_box, player_pos->x,
            player_pos->y)) {
            new_room = create_room(doors[i]->path_new_room);
            camera->animation = sfTrue;
            camera->anim_direction = doors[i]->direction;
            sfClock_restart(camera->timer);
        }
    }
    return (new_room);
}
