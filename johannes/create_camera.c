/*
** EPITECH PROJECT, 2019
** create_camera
** File description:
** create_camera
*/

#include "../rpg.h"

camera_t *create_camera(void)
{
    camera_t *camera = malloc(sizeof(camera_t));

    sfFloatRect view_rect = create_rectf(0, 1850, 1080, 1920);
    camera->animation = sfFalse;
    camera->animation_cicle = 0;
    camera->pos = create_vectf(1850, 0);
    camera->view = sfView_createFromRect(view_rect);
    camera->timer = sfClock_create();
    return (camera);
}
