/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** leveling stats
*/

#include "../../rpg.h"

void display_level_player(sfRenderWindow *window, player_t *player)
{
    button_t *tmp = player->inventory->level_up;
    if (player->stats->lv_available == 0)
        return;
    while (tmp != NULL) {
        sfRenderWindow_drawSprite(window, tmp->visual->sprite, NULL);
        tmp = tmp->next;
    }
}

void release_inventory_effect(player_t *player, int type)
{
    if (type == 1) {
        player->stats->current_health += 50;
        player->stats->max_health += 50;
        player->stats->lv_available -= 1;
    }
    if (type == 2) {
        player->stats->healthreg += 2;
        player->stats->lv_available -= 1;
    }
    if (type == 3) {
        player->stats->damage += 5;
        player->stats->lv_available -= 1;
    }
}

void check_inventory_release(sfMouseButtonEvent m, button_t *opt,
    menu_t *menu, player_t *player)
{
    button_t *tmp = opt;
    sfVector2f vector = sfSprite_getPosition(menu->back->sprite);

    m.x = m.x + vector.x;
    m.y = m.y + vector.y;
    while (tmp != NULL) {
        if (sfIntRect_contains(&tmp->visual->hitbox, m.x, m.y) == sfTrue
            && tmp->visual->animrect.top == 192) {
            tmp->visual->animrect.top = tmp->visual->animrect.top - 96;
            release_inventory_effect(player, tmp->type);
        }
        sfSprite_setTextureRect(tmp->visual->sprite, tmp->visual->animrect);
        tmp = tmp->next;
    }
}

void manage_inventory_events(sfEvent *e, menu_t *m, player_t *p)
{
    if (p->stats->lv_available == 0)
        return;
    if (e->type == sfEvtMouseMoved)
        check_menu_position(e->mouseMove, p->inventory->level_up, m);
    if (e->type == sfEvtMouseButtonPressed)
        check_menu_click(e->mouseButton, p->inventory->level_up, m);
    if (e->type == sfEvtMouseButtonReleased)
        check_inventory_release(e->mouseButton, p->inventory->level_up, m, p);
}