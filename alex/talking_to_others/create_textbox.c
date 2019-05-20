/*
** EPITECH PROJECT, 2018
** PROJECT NAME
** File description:
** FILE NAME
*/

#include "../../rpg.h"

visual_t *create_box_visual(void)
{
    visual_t *box = malloc(sizeof(visual_t));

    box->sprite = sfSprite_create();
    box->texture = sfTexture_createFromFile(DIALOUGE_BOX, NULL);
    box->hitbox = create_rect(0, 0, 0, 0);
    box->animrect = create_rect(0, 0, 0, 0);
    box->pos = create_vector(2060, 630);
    sfSprite_setTexture(box->sprite, box->texture, sfTrue);
    sfSprite_setPosition(box->sprite, box->pos);
    return (box);
}

visual_t *create_picture_box(void)
{
    visual_t *pic = malloc(sizeof(visual_t));

    pic->sprite = sfSprite_create();
    pic->texture = sfTexture_createFromFile(PROTO_PIC, NULL);
    pic->hitbox = create_rect(0, 0, 0, 0);
    pic->animrect = create_rect(0, 0, 252, 252);
    pic->pos = create_vector(2119, 681);
    sfSprite_setTexture(pic->sprite, pic->texture, sfTrue);
    sfSprite_setTextureRect(pic->sprite, pic->animrect);
    sfSprite_setPosition(pic->sprite, pic->pos);
    return (pic);

}

textbox_t *create_textbox(void)
{
    textbox_t *textbox = malloc(sizeof(textbox_t));
    sfVector2f pos;

    textbox->font = sfFont_createFromFile("media/OpenSans-Light.ttf");
    textbox->box = create_box_visual();
    textbox->picture = create_picture_box();
    pos.y = textbox->box->pos.y + 20;
    pos.x = textbox->box->pos.x + 100;
    textbox->text = create_text(sfGreen, 35, pos, textbox->font);
    return (textbox);
}

void change_textbox_position(textbox_t *textbox, camera_t *camera)
{
    sfVector2f offset;
    sfVector2f textpos = sfText_getPosition(textbox->text);

    offset.x = (camera->pos.x + 110) - textbox->box->pos.x;
    offset.x = (camera->pos.y + 630) - textbox->box->pos.y;
    textbox->box->pos = move_vector(textbox->box->pos, offset);
    textbox->picture->pos = move_vector(textbox->picture->pos, offset);
    sfSprite_setPosition(textbox->box->sprite, textbox->box->pos);
    sfSprite_setPosition(textbox->picture->sprite, textbox->picture->pos);
    offset.x = (camera->pos.x + 110) - textpos.x;
    offset.y = (camera->pos.y + 630) - textpos.y;
    textpos = move_vector(textpos, offset);
    sfText_setPosition(textbox->text, textpos);
}

void change_picture_box(char *path, textbox_t *box)
{
    sfTexture_destroy(box->picture->texture);
    box->picture->texture = sfTexture_createFromFile(path, NULL);
    sfSprite_setTexture(box->picture->sprite, box->picture->texture, sfTrue);
    sfSprite_setTextureRect(box->picture->sprite, box->picture->animrect);
}
