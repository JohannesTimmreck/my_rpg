/*
** EPITECH PROJECT, 2018
** PROJECT NAME
** File description:
** FILE NAME
*/

#include "../rpg.h"

button_t *create_end_button(sfVector2f vector, int type)
{
    button_t *button = malloc(sizeof(button_t));

    button->hover = sfFalse;
    button->visual = create_menu_button_visual(vector);
    button->next = NULL;
    button->type = type;
    return (button);
}

end_t *create_end(enum end_status status)
{
    end_t *end;
    sfVector2f pos = create_vectf(((1920 - 600)/2) + 1850, 700);

    if (status == Menu)
        return (NULL);
    end = malloc(sizeof(end_t));
    end->buttons = create_end_button(pos, 1);
    pos.y += 150;
    end->buttons->next = create_end_button(pos, 2);
    end->font = sfFont_createFromFile(FONT);
    end->text = sfText_create();
    end->color = sfColor_fromRGBA(0, 0, 0, 0);
    end->timer_text = sfClock_create();
    end->animation = sfTrue;
    sfText_setFont(end->text, end->font);
    sfText_setColor(end->text, end->color);
    return (end);
}

sfBool trigger_ending(game_t *game)
{
    if ((game->ingame->boss->state == 3 && game->ingame->boss->health == 0)) {
        game->next_status = Ending;
        game->end_status = Win;
        game->switching = sfTrue;
        return (sfTrue);
    } else if (game->ingame->player->stats->current_health == 0) {
        game->next_status = Ending;
        game->end_status = Lose;
        game->switching = sfTrue;
        return (sfTrue);
    }
    return (sfFalse);
}

void check_for_action(game_t *game)
{
    int result = 0;

    while (sfRenderWindow_pollEvent(game->window, game->event) == sfTrue)
        result = manage_end_event(game->window, game->event, game->end);

    if (result == 2) {
        game->next_status = MainMenu;
        game->switching = sfTrue;
        return;
    }
    if (result == -1)
        game->end_status = Menu;
}

void handle_ending(game_t *game)
{
    switch (game->end_status) {
        case Menu:
            sfRenderWindow_close(game->window);
            return;
        case Win:
            check_for_action(game);
            display_win(game->end, game->window);
            break;
        case Lose:
            check_for_action(game);
            display_lose(game->end, game->window);
            break;
    }
    sfRenderWindow_display(game->window);
}