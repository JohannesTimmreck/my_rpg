/*
** EPITECH PROJECT, 2018
** PROJECT NAME
** File description:
** FILE NAME
*/

#include "../rpg.h"

void display_end_buttons(end_t *end, sfRenderWindow *w)
{
    char *menu_button = "RETURN TO MENU";
    char *exit_button = "EXIT";
    sfVector2f pos = create_vectf(((1920 - 400)/2) + 1850, 735);

    sfRenderWindow_drawSprite(w, end->buttons->visual->sprite, NULL);
    sfRenderWindow_drawSprite(w, end->buttons->next->visual->sprite, NULL);
    sfText_setColor(end->text, sfBlack);
    sfText_setCharacterSize(end->text, 30);
    sfText_setPosition(end->text, pos);
    sfText_setString(end->text, menu_button);
    sfRenderWindow_drawText(w, end->text, NULL);
    pos.y += 150;
    pos.x += 130;
    sfText_setPosition(end->text, pos);
    sfText_setString(end->text, exit_button);
    sfRenderWindow_drawText(w, end->text, NULL);
}

void display_win(end_t *end, sfRenderWindow *window)
{
    char *message = "YOU ESCAPED";
    sfTime time = sfClock_getElapsedTime(end->timer_text);
    float sec = time.microseconds / 1000000.0;

    if (end->animation == sfTrue && sec > 0.01) {
        end->color.a += 1;
        sfClock_restart(end->timer_text);
        sfText_setColor(end->text, end->color);
    } else if (end->animation == sfFalse)
        display_end_buttons(end, window);
    if (end->color.a == 80) {
        end->animation = sfFalse;
    }
    sfText_setCharacterSize(end->text, 80);
    sfText_setString(end->text, message);
    sfText_setPosition(end->text, create_vectf(((1920 - 800)/2) + 1850, 400));
    sfRenderWindow_drawText(window, end->text, NULL);
}

void display_lose(end_t *end, sfRenderWindow *window)
{
    char *message = "YOU DIED";
    sfTime time = sfClock_getElapsedTime(end->timer_text);
    float sec = time.microseconds / 1000000.0;

    if (end->animation == sfTrue && sec > 0.01) {
        end->color.a += 1;
        sfClock_restart(end->timer_text);
        sfText_setColor(end->text, end->color);
    } else if (end->animation == sfFalse)
        display_end_buttons(end, window);
    if (end->color.a == 80) {
        end->animation = sfFalse;
    }
    sfText_setCharacterSize(end->text, 80);
    sfText_setString(end->text, message);
    sfText_setPosition(end->text, create_vectf(((1920 - 550)/2) + 1850, 400));
    sfRenderWindow_drawText(window, end->text, NULL);
}