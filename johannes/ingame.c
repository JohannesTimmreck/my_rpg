/*
** EPITECH PROJECT, 2018
** PROJECT NAME
** File description:
** FILE NAME
*/

#include "../rpg.h"

void draw_ingame(sfRenderWindow *w, ingame_t *ingame)
{
    sfRenderWindow_clear(w, sfRed);
    sfRenderWindow_setView(w, ingame->camera->view);
    draw_room(w, ingame->room);
    if (ingame->camera->animation == sfTrue) {
        draw_room(w, ingame->next_room);
        sfRenderWindow_setView(w, ingame->camera->view);
    }
    print_player(w, ingame->player);
    display_health(w, ingame->player);
    sfRenderWindow_drawSprite(w, ingame->boss->sprite, NULL);
    if (ingame->boss->circle != NULL)
        sfRenderWindow_drawCircleShape(w, ingame->boss->circle->c, NULL);
    if (ingame->boss->state == 3)
        display_boss_health(w, ingame->boss);
    sfRenderWindow_display(w);
}

void manage_ingame_input(game_t *game)
{
    int res = 0;

    while (sfRenderWindow_pollEvent(game->window, game->event) == sfTrue)
        res = interprete_input(game, game->event,
            game->ingame->player, game->ingame->camera);
    if (res == 2) {
        game->next_status = MainMenu;
        game->switching = sfTrue;
        return;
    } else if (res == -1) {
        game->next_status = Ending;
        game->switching = sfTrue;
        return;
    }
}

void destroy_ingame(ingame_t *ingame)
{
    destroy_room(ingame->room);
    destroy_player(ingame->player);
    if (ingame->camera->animation == sfTrue)
        destroy_room(ingame->next_room);
    sfClock_destroy(ingame->camera->timer);
    sfView_destroy(ingame->camera->view);
    sfMusic_stop(ingame->music);
    sfMusic_destroy(ingame->music);
    sfFont_destroy(ingame->textbox->font);
    sfText_destroy(ingame->textbox->text);
    destroy_visual(ingame->textbox->box);
    destroy_visual(ingame->textbox->picture);
    destroy_boss(ingame->boss);
    free (ingame->textbox);
    free(ingame->camera);
    free(ingame);
}

void ingame(game_t *game)
{
    manage_ingame_input(game);
    if (game->switching == sfTrue || trigger_ending(game) == sfTrue) {
        destroy_ingame(game->ingame);
        return;
    }
    if (game->ingame->camera->animation == sfTrue)
        animate_room_change(game->ingame);
    else
        manage_player(game->ingame->player, game->ingame);
    if (game->ingame->boss->state == 1 && game->ingame->boss->rect->left == 0)
        manage_dialouge(game->window, game->ingame->textbox,
                        TRANSFORM_DIALOUGE);
    sfRenderWindow_pollEvent(game->window, game->event);
    if (my_strcmp(game->ingame->room->config->current_path, ROOM1) == sfTrue)
        handle_boss(game->ingame->boss, game->ingame);
    handle_objects(game->ingame);
    if (game->ingame->boss->circle != NULL)
        game->ingame->boss->circle = handle_attackcircle(
            game->ingame->boss->circle, game->ingame->player);
    draw_ingame(game->window, game->ingame);
}

ingame_t *init_ingame(sfRenderWindow *window)
{
    ingame_t *ingame = malloc(sizeof(ingame_t));

    ingame->start_sequence = sfTrue;
    ingame->player = create_player();
    ingame->room = create_room(ROOM1);
    ingame->textbox = create_textbox();
    ingame->next_room = NULL;
    ingame->camera = create_camera();
    ingame->boss = malloc_boss();
    ingame->items = create_items();
    ingame->music = play_music(MUSIC_ONE);
    sfRenderWindow_setView(window, ingame->camera->view);
    return (ingame);
}
