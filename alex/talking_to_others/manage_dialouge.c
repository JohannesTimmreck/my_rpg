/*
** EPITECH PROJECT, 2018
** PROJECT NAME
** File description:
** FILE NAME
*/

#include "../../rpg.h"

int check_dialouge_input(sfEvent *event, int e_count)
{
    if (event->type == sfEvtKeyReleased) {
        if (event->key.code == sfKeyE)
            e_count++;
        if (event->key.code == sfKeyX)
            return (-1);
    }
    return (e_count);
}

void check_for_change_in_pespective(textbox_t *box, char **config,
    int e_count, int con)
{
    static int pre = 0;

    if (con == 1)
        pre = 0;
    if (con == 1 || (pre == e_count && e_count != 0))
        return;
    if (e_count != 0 && my_getnbr(config[pre]) == my_getnbr(config[e_count])) {
        pre = e_count;
        return;
    }
    pre = e_count;
    box->picture->animrect.left = 0;
    if (my_getnbr(config[e_count]) == JOHN)
        change_picture_box(JOHN_PIC, box);
    if (my_getnbr(config[e_count]) == PROTO)
        change_picture_box(PROTO_PIC, box);
    if (my_getnbr(config[e_count]) == BOSS_JOHN) {
        box->picture->animrect.left = 252;
        change_picture_box(JOHN_PIC, box);
    }
}

void destroy_dialouge(char **dia, char **config, sfEvent *event, char *stor)
{
    free_array(dia);
    free_array(config);
    free (stor);
    free (event);
}

void manage_dialouge(sfRenderWindow *w, textbox_t *box, char *filepath)
{
    int e_count = 0;
    char *storage = get_config(filepath);
    char **config = my_str_to_word_array(storage, ' ');
    char **dialouge = create_dialouge(filepath, my_strlen(storage));
    sfEvent *event = malloc(sizeof(sfEvent));
    sfVector2f pos = box->box->pos;

    pos.x += 350;
    while (e_count != -1 && dialouge[e_count] != NULL) {
        check_for_change_in_pespective(box, config, e_count, 0);
        sfRenderWindow_drawSprite(w, box->box->sprite, NULL);
        sfRenderWindow_drawSprite(w, box->picture->sprite, NULL);
        display_text(w, box->text, pos, dialouge[e_count]);
        if (sfRenderWindow_pollEvent(w, event) == sfTrue) {
            e_count = check_dialouge_input(event, e_count);
        }
        sfRenderWindow_display(w);
    }
    check_for_change_in_pespective(box, config, 0, 1);
    destroy_dialouge(dialouge, config, event, storage);
}