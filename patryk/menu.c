/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include "../rpg.h"

int manage_menu_mouse_click(sfEvent *event, game_t *game)
{
    if (sfRenderWindow_pollEvent(game->window, event) != sfTrue)
        return (NoAction);
    if (event->type != sfEvtMouseButtonPressed)
        return (NoAction);
    if (event->mouseButton.x >= 400 && event->mouseButton.x <= 745 &&
        event->mouseButton.y >= 455 && event->mouseButton.y <= 545) {
        game->next_status = InGame;
        return (Start);
    }
    if (event->mouseButton.x >= 1225 && event->mouseButton.x <= 1570 &&
        event->mouseButton.y >= 460 && event->mouseButton.y <= 540)
        return (Controls);
    if (event->mouseButton.x >= 800 && event->mouseButton.x <= 1145 &&
        event->mouseButton.y >= 800 && event->mouseButton.y <= 880) {
        game->next_status = Ending;
        return (End);
        }
    return (NoAction);
}

mainmenu_t *init_menu(void)
{
    mainmenu_t *menu = malloc(sizeof(menu_t));

    menu->main_menu = malloc(sizeof(visual_t));
    menu->main_menu->texture = sfTexture_createFromFile(MENU_TEXTURE, NULL);
    menu->main_menu->sprite = sfSprite_create();
    sfSprite_setTexture(menu->main_menu->sprite,
        menu->main_menu->texture, sfTrue);
    menu->controls = malloc(sizeof(visual_t));
    menu->controls->texture = sfTexture_createFromFile(CONTROL_TEXTURE, NULL);
    menu->controls->sprite = sfSprite_create();
    sfSprite_setTexture(menu->controls->sprite,
        menu->controls->texture, sfTrue);
    menu->status = NoAction;
    return (menu);
}

void destroy_mainmenu(mainmenu_t *menu)
{
    sfTexture_destroy(menu->main_menu->texture);
    sfSprite_destroy(menu->main_menu->sprite);
    free(menu->main_menu);
    sfTexture_destroy(menu->controls->texture);
    sfSprite_destroy(menu->controls->sprite);
    free(menu->controls);
    free(menu);
}

void manage_controls(sfEvent *event, mainmenu_t *menu, game_t *game)
{
    if (sfRenderWindow_pollEvent(game->window, event) != sfTrue)
        return;
    if (event->type == sfEvtKeyReleased
        || event->type == sfEvtMouseButtonPressed)
        menu->status = NoAction;
}

void menu(sfRenderWindow* window, sfEvent *event, game_t *game)
{
    mainmenu_t *menu = init_menu();

    game->next_status = InGame;
    game->switching = sfTrue;
    while (sfRenderWindow_isOpen(window)) {
        if (menu->status == NoAction) {
            menu->status = manage_menu_mouse_click(event, game);
            sfRenderWindow_drawSprite(window, menu->main_menu->sprite, NULL);
        } else if (menu->status == Controls)  {
            manage_controls(event, menu, game);
            sfRenderWindow_drawSprite(window, menu->controls->sprite, NULL);
        }
        if (menu->status == Start || event->type == sfEvtClosed
            || menu->status == End) {
            destroy_mainmenu(menu);
            return;
        }
        sfRenderWindow_display(window);
    }
}
