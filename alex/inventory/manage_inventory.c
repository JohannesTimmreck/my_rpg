/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** create_inventory
*/

#include "../../rpg.h"

void display_quest(sfRenderWindow *w, inventory_t *inventory, sfVector2f pos)
{
    sfText_setCharacterSize(inventory->text, 30);
    sfText_setString(inventory->text, inventory->quest_title);
    sfText_setPosition(inventory->text, pos);
    sfRenderWindow_drawText(w, inventory->text, NULL);
    pos.y += 50;
    sfText_setCharacterSize(inventory->text, 20);
    sfText_setString(inventory->text, inventory->quest);
    sfText_setPosition(inventory->text, pos);
    sfRenderWindow_drawText(w, inventory->text, NULL);
}

void display_text(sfRenderWindow *w, sfText *text, sfVector2f pos, char *str)
{
    sfText_setString(text, str);
    sfText_setPosition(text, pos);
    sfRenderWindow_drawText(w, text, NULL);
}

void display_level(sfRenderWindow *w, stats_t *stats, sfVector2f pos)
{
    char *tmp;

    sfText_setCharacterSize(stats->text, 30);
    tmp = combine_strings("LEVEL " , my_int_to_str(stats->level), 2);
    display_text(w, stats->text, pos, tmp);
    free (tmp);
    if (stats->lv_available > 0) {
        pos.x += 250;
        sfText_setCharacterSize(stats->text, 10);
        tmp = combine_strings("SKILL", "POINTS  ", 0);
        tmp = combine_strings(tmp,  my_int_to_str(stats->lv_available), 2);
        display_text(w, stats->text, pos, tmp);
        free (tmp);
    }
}

void display_stats(sfRenderWindow *w, stats_t *stats, sfVector2f pos)
{
    char *tmp;

    display_level(w, stats, pos);
    pos.y += 75;
    sfText_setCharacterSize(stats->text, 20);
    tmp = combine_strings("EXP.               " , my_int_to_str(stats->exp), 2);
    tmp = combine_strings(tmp, "/", 1);
    tmp = combine_strings(tmp, my_int_to_str(stats->exp_needed), 3);
    tmp = combine_strings(tmp, "\nHEALTH         ", 1);
    tmp = combine_strings(tmp, my_int_to_str(stats->current_health), 3);
    tmp = combine_strings(tmp, "/", 1);
    tmp = combine_strings(tmp, my_int_to_str(stats->max_health), 3);
    tmp = combine_strings(tmp, "\nHEALTHREG. ", 1);
    tmp = combine_strings(tmp, my_int_to_str(stats->healthreg), 3);
    tmp = combine_strings(tmp, "\nDAMAGE         ", 1);
    tmp = combine_strings(tmp, my_int_to_str(stats->damage), 2);
    display_text(w, stats->text, pos, tmp);
    free (tmp);
}

void display_inventory(sfRenderWindow *w, player_t *player)
{
    sfVector2f pos = sfSprite_getPosition(player->pause->back->sprite);

    pos.x = pos.x + 1350;
    pos.y = pos.y + 180;
    display_quest(w, player->inventory, pos);
    pos.x = pos.x - 850;
    display_stats(w, player->stats, pos);
    display_level_player(w, player);
    for (int i = 0; player->inventory->items[i] != NULL; i++) {
        if (player->inventory->items[i]->type != empty)
            sfRenderWindow_drawSprite(w,
                player->inventory->items[i]->visual->sprite, NULL);
    }
}