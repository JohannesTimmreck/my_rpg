/*
** EPITECH PROJECT, 2019
** boss
** File description:
** boss
*/

#include "../rpg.h"

boss_t *handle_boss(boss_t *boss, ingame_t *ingame)
{
    if (boss->state == 3) {
        boss = boss_fly(boss);
        boss = move_to_next_position(boss);
    }
    if (boss->key == sfTrue) {
        if (boss->state == 2) {
            boss = boss_jump(boss);
            sfMusic_stop(ingame->music);
            sfMusic_destroy(ingame->music);
            ingame->music = play_music(MUSIC_TWO);
        }
        if (boss->state == 1)
            boss = next_transform(boss);
        if (boss->state == 0)
            boss = transform(boss);
    }
    return (boss);
}

visual_t *create_boss_healthbar(int con)
{
    visual_t *visual = malloc(sizeof(visual_t));
    sfVector2f vector = create_vector(1998, 888);
    sfVector2f scale = create_vectorf(0.4, 1.0);

    visual->sprite = sfSprite_create();
    if (con == 0) {
        vector.x += 2;
        vector.y += 2;
        visual->texture = sfTexture_createFromFile(BOSS_HEALTH, NULL);
        visual->pos = vector;
    }
    if (con == 1) {
        visual->texture = sfTexture_createFromFile(EMPTY, NULL);
    }
    sfSprite_setTexture(visual->sprite, visual->texture, sfTrue);
    sfSprite_setPosition(visual->sprite, vector);
    if (con == 0)
        sfSprite_setScale(visual->sprite, scale);
    return (visual);
}

void display_boss_health(sfRenderWindow *window, boss_t *boss)
{
    sfVector2f pos = boss->healthbar->pos;

    sfRenderWindow_drawSprite(window, boss->emptybar->sprite, NULL);
    for (int x = 0; x != boss->health; x++) {
        sfSprite_setPosition(boss->healthbar->sprite, pos);
        sfRenderWindow_drawSprite(window, boss->healthbar->sprite, NULL);
        pos.x += 4;
    }
    sfSprite_setPosition(boss->healthbar->sprite, boss->healthbar->pos);
    sfRenderWindow_drawText(window, boss->name, NULL);
}

boss_t *set_fighting_variables_boss(boss_t *boss)
{
    boss->hit = sfFalse;
    boss->health = 400;
    boss->healthbar = create_boss_healthbar(0);
    boss->emptybar = create_boss_healthbar(1);
    boss->font = sfFont_createFromFile(FONT);
    boss->name = create_text(sfBlack, 20, create_vector(2000, 850), boss->font);
    sfText_setString(boss->name, "HARBRINGER OF DESTRUCTION SOREN");
    return (boss);
}

boss_t *malloc_boss(void)
{
    boss_t *boss;

    boss = malloc(sizeof(boss_t));
    boss->rect = create_rectangle(0, 0, 44, 46);
    boss->attack = create_rectangle(0, 44 * 5, 49, 44);
    boss->state = 0;
    boss->move = 0;
    boss->attack = malloc(sizeof(sfIntRect));
    boss->attack->left = 0;
    npc(boss);
    boss->clock = sfClock_create();
    boss->clock2 = sfClock_create();
    boss->key = sfFalse;
    boss->times_talked_to = 1;
    boss->circle = NULL;
    boss = set_fighting_variables_boss(boss);
    return (boss);
}
