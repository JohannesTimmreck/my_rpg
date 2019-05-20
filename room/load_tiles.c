/*
** EPITECH PROJECT, 2018
** PROJECT NAME
** File description:
** FILE NAME
*/

#include "../rpg.h"

visual_t *create_wall_visual(sfVector2f pos, char def)
{
    visual_t *visual = malloc(sizeof(visual_t));
    char *str = "ABCEFGHIJKLMNPQRSTUVWXabcd";
    int i = 0;

    while (def != str[i])
        i += 1;
    visual->animrect = create_recti(0, 50 * i, TILESIZE, TILESIZE);
    visual->hitbox = create_recti(pos.x, pos.y,
        TILESIZE, TILESIZE);
    visual->pos = pos;
    visual->texture = sfTexture_createFromFile(WALL_TEXTURE, NULL);
    visual->sprite = sfSprite_create();
    sfSprite_setTexture(visual->sprite, visual->texture, sfTrue);
    sfSprite_setPosition(visual->sprite, visual->pos);
    sfSprite_setTextureRect(visual->sprite, visual->animrect);
    return (visual);
}

visual_t *create_tile_visual(type_t type, sfVector2f pos)
{
    visual_t *visual = malloc(sizeof(visual_t));
    char *textures[3] = {GROUND_TEXTURE, WALL_TEXTURE, DOOR_TEXTURE};

    visual->animrect = create_recti(0, 0, TILESIZE, TILESIZE);
    visual->hitbox = create_recti(pos.x, pos.y,
        TILESIZE, TILESIZE);
    visual->pos = pos;
    visual->texture = sfTexture_createFromFile(textures[type], NULL);
    visual->sprite = sfSprite_create();
    sfSprite_setTexture(visual->sprite, visual->texture, sfTrue);
    sfSprite_setPosition(visual->sprite, visual->pos);
    sfSprite_setTextureRect(visual->sprite, visual->animrect);
    return (visual);
}

tile_t *create_tile(char def, sfVector2f pos)
{
    tile_t *tile = malloc(sizeof(tile_t));

    tile->c = def;
    if ((((def >= 'A' && def <= 'W') || (def >= 'a' && def <= 'd'))
        && def != 'O' && def != 'D')
        || def == 'X') {
        tile->type = Wall;
        tile->solid = sfTrue;
        tile->visual = create_wall_visual(pos, def);
    } else if (def == 'D') {
        tile->type = Door;
        tile->solid = sfFalse;
        tile->visual = create_tile_visual(tile->type, pos);
    } else {
        tile->type = Ground;
        tile->solid = sfFalse;
        tile->visual = create_tile_visual(tile->type, pos);
    }
    return (tile);
}

tile_t ***create_tiles(room_config_t *config)
{
    tile_t ***tiles = malloc(sizeof(tile_t **) * (config->size.y + 1));

    for (int line = 0; line < config->size.y; line++) {
        tiles[line] = malloc(sizeof(tile_t *) * (config->size.x + 1));
        for (int column = 0; column < config->size.x; column++)
            tiles[line][column] = create_tile(config->layout[line][column],
                create_vectf(column * TILESIZE + config->pos_in_map.x,
                    line * TILESIZE + config->pos_in_map.y));
        tiles[line][config->size.x] = NULL;
    }
    tiles[config->size.y] = NULL;
    return (tiles);
}