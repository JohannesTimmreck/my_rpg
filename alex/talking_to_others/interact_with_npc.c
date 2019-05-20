/*
** EPITECH PROJECT, 2019
** boss
** File description:
** boss
*/

#include "../../rpg.h"

void play_generic_dialouge(ingame_t *game, sfRenderWindow *w)
{
    if (game->boss->times_talked_to == 1) {
        manage_dialouge(w, game->textbox, SMALLTALK_ONE);
    }
    if (game->boss->times_talked_to == 2) {
        manage_dialouge(w, game->textbox, SMALLTALK_TWO);
    }
    if (game->boss->times_talked_to == 3) {
        manage_dialouge(w, game->textbox, SMALLTALK_THREE);
    }
    if (game->boss->times_talked_to >= 4)
        manage_dialouge(w, game->textbox, SMALLTALK_FOUR);
    game->boss->times_talked_to++;
    if (game->boss->times_talked_to > 5)
        game->boss->times_talked_to = 5;
}

void interact_with_npc(ingame_t *game, sfRenderWindow *w)
{
    sfVector2f pos = sfSprite_getPosition(game->boss->sprite);
    sfVector2f size = create_vector(132, 147);
    sfIntRect Interact_box;

    pos.x -= 35;
    size.x += 70;
    size.y += 40;
    if (game->boss->key == sfTrue)
        return;
    Interact_box = create_intrect(pos, size);
    if (sfIntRect_contains(&Interact_box, game->player->centerpoint.x,
        game->player->centerpoint.y)) {
        if (game->player->inventory->Key == sfFalse)
            play_generic_dialouge(game, w);
        if (game->player->inventory->Key == sfTrue) {
            manage_dialouge(w, game->textbox, FINSIHING_QUEST);
            game->boss->key = sfTrue;
        }
    }
}