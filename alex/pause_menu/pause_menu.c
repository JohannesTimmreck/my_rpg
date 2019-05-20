/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** johannes utils
*/

#include "../../rpg.h"

void move_buttons(button_t *tmp, sfVector2f offset)
{
    while (tmp != NULL) {
        tmp->visual->pos = move_vector(tmp->visual->pos, offset);
        tmp->visual->hitbox.top = tmp->visual->pos.y;
        tmp->visual->hitbox.left = tmp->visual->pos.x;
        sfSprite_setPosition(tmp->visual->sprite, tmp->visual->pos);
        tmp = tmp->next;
    }
}

void move_pause(player_t *player, camera_t *camera)
{
    sfVector2f old = sfSprite_getPosition(player->pause->back->sprite);
    sfVector2f offset;
    button_t *tmp = player->pause->options;
    button_t *tmp2 = player->inventory->level_up;

    offset.x = camera->pos.x - old.x;
    offset.y = camera->pos.y - old.y;
    player->pause->back->pos = move_vector(player->pause->back->pos, offset);
    sfSprite_setPosition(player->pause->back->sprite, player->pause->back->pos);
    old = move_vector(old, offset);
    sfRectangleShape_setPosition(player->pause->rect, old);
    move_buttons(tmp, offset);
    move_buttons(tmp2, offset);
    for (int i = 0; player->inventory->items[i] != NULL; i++) {
        if (player->inventory->items[i]->type != empty) {
            move_vector_s(&player->inventory->items[i]->visual->pos, offset);
            sfSprite_setPosition(player->inventory->items[i]->visual->sprite,
                player->inventory->items[i]->visual->pos);
        }
    }
}

void display_pause_text(sfRenderWindow *window, sfText *text, menu_t *pause)
{
    sfVector2f up_left = sfRectangleShape_getPosition(pause->rect);
    sfVector2f pos = create_vector((up_left.x + 145), (up_left.y + 705));

    sfText_setPosition(text, pos);
    sfText_setString(text, "CONTINUE");
    sfRenderWindow_drawText(window, text, NULL);
    pos.y = pos.y + 120;
    sfText_setPosition(text, pos);
    sfText_setString(text, "BACK TO MENU");
    sfRenderWindow_drawText(window, text, NULL);
    pos.y = pos.y + 120;
    sfText_setPosition(text, pos);
    sfText_setString(text, "EXIT");
    sfRenderWindow_drawText(window, text, NULL);
}

void display_pause(sfRenderWindow *window, menu_t *pause)
{
    button_t *tmp = pause->options;

    sfRenderWindow_drawRectangleShape(window, pause->rect, NULL);
    sfRenderWindow_drawSprite(window, pause->back->sprite, NULL);

    while (tmp != NULL) {
        sfRenderWindow_drawSprite(window, tmp->visual->sprite, NULL);
        tmp = tmp->next;
    }
    display_pause_text(window, pause->text, pause);
}

int do_a_pause(sfRenderWindow *window, menu_t *pause, player_t *player)
{
    sfEvent *event = malloc(sizeof(sfEvent));
    int res = 0;

    while (pause->active == 1 && sfRenderWindow_isOpen(window) == sfTrue) {
        while (sfRenderWindow_pollEvent(window, event) == sfTrue) {
            pause->active = manage_pause_event(window, event, pause);
            manage_inventory_events(event, pause, player);
        }
        display_pause(window, pause);
        display_inventory(window, player);
        sfRenderWindow_display(window);
    }
    res = pause->active;
    pause->active = 0;
    free (event);
    return (res);
}