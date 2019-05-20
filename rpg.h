/*
** EPITECH PROJECT, 2018
** PROJECT NAME
** File description:
** FILE NAME
*/

#ifndef __RPG__
#define __RPG__

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

enum tile_types {Ground, Wall, Door, Gate};
typedef enum tile_types type_t;
enum object_type {Box, Key};
enum direction_e {Up, Right, Down, Left};
typedef enum direction_e direction_t;
enum game_status {MainMenu, InGame, Ending};
enum item_type {key, empty};
enum menu_status {Start, Controls, End, NoAction};
enum end_status {Win, Lose, Menu};

struct visual {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfIntRect animrect;
    sfIntRect hitbox;
};
typedef struct visual visual_t;

struct button {
    int type;
    sfBool hover;
    visual_t *visual;
    struct button *next;
};
typedef struct button button_t;

struct menu {
    sfMusic *select;
    int active;
    sfRectangleShape *rect;
    visual_t *back;
    sfText *text;
    button_t *options;
};
typedef struct menu menu_t;

typedef struct item_s item_t;
struct item_s
{
    enum item_type type;
    int health;
    int health_regen;
    int damage;
    sfBool new;
    visual_t *visual;
};

struct inventory {
    sfText *text;
    sfFont *font;
    button_t *level_up;
    char *quest_title;
    char *quest;
    int max_items;
    item_t **items;
    sfBool Key;
};
typedef struct inventory inventory_t;

struct player_stats {
    sfText *text;
    sfFont *font;
    int level;
    int lv_available;
    int exp;
    int exp_needed;
    int max_health;
    int current_health;
    int healthreg;
    sfClock *regenclock;
    int damage;
};
typedef struct player_stats stats_t;

struct player {
    visual_t *visual;
    visual_t *sword;
    visual_t *healthbar;
    int animend;
    int status;
    int looking;
    sfVector2f centerpoint;
    sfVector2f speed;
    sfClock *walk_clock;
    sfClock *anim_clock;
    sfClock *atk_cd;
    sfFont *font;
    menu_t *pause;
    stats_t *stats;
    inventory_t *inventory;
};
typedef struct player player_t;

struct tile_s
{
    sfBool solid;
    type_t type;
    char c;
    visual_t *visual;
};
typedef struct tile_s tile_t;

struct door_s
{
    char *path_new_room;
    sfVector2f pos;
    int size;
    direction_t direction;
    sfFloatRect enter_box;
};
typedef struct door_s door_t;

struct room_config_s
{
    char * current_path;
    sfVector2i pos_in_map;
    sfVector2i size;
    int door_amount;
    int object_amount;
    char **layout;
    char **door_info;
    char **object_info;
};
typedef struct room_config_s room_config_t;

typedef struct object_s object_t;
struct object_s
{
    enum object_type type;
    sfBool collectable;
    sfBool solid;
    sfBool movable;
    sfBool destructable;
    float lives;
    int exp_drop;
    sfBool drop_item;
    enum item_type item_type;
    visual_t *visual;
    object_t *next;
};

struct room_s
{
    room_config_t *config;
    door_t **doors;
    tile_t ***tiles;
    object_t *objects;
};
typedef struct room_s room_t;

struct camera_s
{
    sfBool animation;
    sfClock *timer;
    sfVector2f pos;
    int animation_cicle;
    direction_t anim_direction;
    sfView *view;
};
typedef struct camera_s camera_t;

struct boss_attack_circle_s
{
    sfBool hit;
    sfVector2f pos;
    float radius;
    sfClock *timer;
    sfCircleShape *c;
};
typedef struct boss_attack_circle_s attack_circle_t;

struct boss {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect *rect;
    sfClock *clock;
    sfClock *clock2;
    int state;
    int transformation;
    sfVector2f position;
    int move;
    int health;
    visual_t *healthbar;
    visual_t *emptybar;
    sfFont *font;
    sfText *name;
    sfBool key;
    sfBool hit;
    int times_talked_to;
    sfIntRect *attack;
    attack_circle_t *circle;
};
typedef struct boss boss_t;

struct textbox
{
    visual_t *box;
    visual_t *picture;
    sfText *text;
    sfFont *font;
};
typedef struct textbox textbox_t;

struct ingame_s
{
    textbox_t *textbox;
    sfBool start_sequence;
    room_t *room;
    room_t *next_room;
    camera_t *camera;
    item_t **items;
    player_t *player;
    boss_t *boss;
    sfMusic *music;
};
typedef struct ingame_s ingame_t;

struct menu_s
{
    visual_t *main_menu;
    visual_t *controls;
    enum menu_status status;
};
typedef struct menu_s mainmenu_t;

struct end_s
{
    button_t *buttons;
    sfText *text;
    sfFont *font;
    sfBool animation;
    sfColor color;
    sfClock *timer_text;
};
typedef struct end_s end_t;

struct game_s
{
    enum game_status current_status;
    enum game_status next_status;
    enum end_status end_status;
    end_t *end;
    sfEvent *event;
    sfBool switching;
    sfRenderWindow *window;
    ingame_t *ingame;
};
typedef struct game_s game_t;

#define ROOM1 ("room_configs/config_startroom")

#define TILESIZE (50)

#define MENU_TEXTURE ("media/visual/menu/main_menu.png")
#define CONTROL_TEXTURE ("media/visual/menu/how_to_play.png")

#define GROUND_TEXTURE ("media/visual/rooms/Ground.png")
#define WALL_TEXTURE ("media/visual/rooms/Walls.png")
#define DOOR_TEXTURE ("media/visual/rooms/Door.png")
#define GATE_TEXTURE ("media/visual/rooms/GATE.png")

#define BOX_TEXTURE ("media/visual/rooms/Box.png")
#define KEY_TEXTURE ("media/visual/rooms/Key.png")

#define BOSS_HEALTH ("media/visual/boss/BossHealth.png")
#define DIALOUGE_BOX ("media/visual/dialouge/textbox.png")
#define JOHN_PIC ("media/visual/dialouge/boss_pic.png")
#define PROTO_PIC ("media/visual/dialouge/player_pic.png")
#define BOSS_JOHN (3)
#define JOHN (2)
#define PROTO (1)
#define START_DIALOUGE ("alex/dialouge_configs/starting dialouge.txt")
#define SMALLTALK_ONE ("alex/dialouge_configs/john1.txt")
#define SMALLTALK_TWO ("alex/dialouge_configs/john2.txt")
#define SMALLTALK_THREE ("alex/dialouge_configs/john3.txt")
#define SMALLTALK_FOUR ("alex/dialouge_configs/john_no_talks_left.txt")
#define FINSIHING_QUEST ("alex/dialouge_configs/giving_john_key.txt")
#define TRANSFORM_DIALOUGE ("alex/dialouge_configs/john_transform.txt")

#define MUSIC_ONE ("media/sounds/music/TW3.ogg")
#define MUSIC_TWO ("media/sounds/music/DS3Theme.ogg")

//player_macros
#define IDLE (0)
#define WALKING (1)
#define ATTACKING (2)
#define UP (1)
#define DOWN (2)
#define RIGHT (3)
#define LEFT (4)
#define UP_R (5)
#define UP_L (6)
#define DOWN_R (7)
#define DOWN_L (8)
#define PLAYER ("media/visual/player/rpg_player.png")
#define SWORD ("media/visual/player/sword.png")
#define SPEED (5)
#define HEALTHBAR ("media/visual/player/health.png")
#define EMPTY ("media/visual/boss/emptybar.png")

//Pause and inventory
#define LEVEL_BUTTON ("media/visual/buttons/levelbutton.png")
#define PAUSE_BUTTON ("media/visual/buttons/pause_button.png")
#define PAUSE_MENU ("media/visual/menu/pause_menu.png")
#define MOVE_SOUND ("media/sounds/menu/move.ogg")
#define SELECT_SOUND ("media/sounds/menu/select.ogg")
#define WAITING_SOUND ("media/sounds/menu/waiting.ogg")
#define FONT ("media/Pixeled.ttf")


void starting_sequence(sfRenderWindow *window, ingame_t *game);
textbox_t *create_textbox(void);
void change_textbox_position(textbox_t *textbox, camera_t *camera);
void change_picture_box(char *path, textbox_t *box);
void display_text(sfRenderWindow *w, sfText *text, sfVector2f pos, char *str);
char *push_in_by(char *str, int nb);
char **create_dialouge(char *filepath, int len);
char *get_config(char *filepath);
void manage_dialouge(sfRenderWindow *w, textbox_t *box, char *filepath);
void interact_with_npc(ingame_t *game, sfRenderWindow *w);
char **my_str_to_word_array(char *av, char seperator);

//Utils
int my_getnbr(char *str);
int my_strlen(char const *str);
char **split_str(char *str, char split);
char *my_strdup(char *oldstr);

//rect
sfIntRect create_recti(int pos_x, int pos_y, int size_x, int size_y);
sfFloatRect create_rectf(float top, float left, float height, float width);
sfIntRect *create_rectangle(int pos_x, int pos_y, int size_x, int size_y);

//vect
sfVector2i vecti_from_arr(char **arr);
sfVector2f create_vectf(float x, float y);
sfVector2i create_vecti(int x, int y);
void move_vector_s(sfVector2f *object, sfVector2f offset);

//room
char **read_file_layout(FILE *file, int lines);
tile_t ***create_tiles(room_config_t *config);
door_t **create_doors(room_config_t *config);
object_t *create_object_list(room_config_t *config);
room_t *create_room(char *filepath);
void destroy_room(room_t *room);
void draw_room(sfRenderWindow *window, room_t *room);
void apply_object_information(object_t *list, char **object_info);
visual_t *create_object_visual(sfVector2f pos, char *path);
object_t *create_object(sfVector2f pos);
object_t *connect_objects(object_t *list, object_t *new);
void set_informations(object_t *object, char **infos);
object_t *scan_for_objects(char c, sfVector2f pos);
void make_object_collectable(object_t *object);

void handle_objects(ingame_t *ingame);
item_t **create_items();
void destroy_items(item_t **items);

//camera
camera_t *create_camera(void);
void move_camera(camera_t *camera);
void animate_room_change(ingame_t *ingame);
void stop_room_change_animation(ingame_t *ingame);
room_t *check_for_roomchange(door_t **doors, sfVector2f *player_pos,
    camera_t *camera);

//player
player_t *create_player(void);
//manage_player
void print_player(sfRenderWindow *window, player_t *player);
int interprete_input(game_t *game, sfEvent *e,
    player_t *player, camera_t *camera);
void manage_player(player_t *player, ingame_t *ingame);
int check_for_wall_collision(player_t *player, room_t *room);
void check_for_diagonal_walk(player_t *player, room_t *room);
//player_attacks
void stop_attacks(player_t *player, boss_t *boss);
void set_attack(player_t *player);
void manage_boss_health(player_t *player, boss_t *boss);
//player_change_direction
void change_direction(player_t *player);
void check_move_player(player_t *player);
//animate_move_player
void check_for_idle(player_t *player);
void animate_player(player_t *player);
void move_player(player_t *player, room_t *room);
//player_health
void manage_health(player_t *player);
void display_health(sfRenderWindow *window, player_t *player);
void move_health(player_t *player);

//create_window
sfRenderWindow *create_window(unsigned int width, unsigned int height);

//buttons
button_t *add_to_last_button(button_t *list, button_t *next);
button_t *create_menu_button(int type, sfVector2f vector);
visual_t *create_menu_button_visual(sfVector2f vector);
button_t *create_level_button(int type, sfVector2f vector);
void put_space_into_hover(sfMouseMoveEvent m, button_t *t);

//pause
menu_t *create_pause(sfFont *font);
void move_pause(player_t *player, camera_t *camera);
int do_a_pause(sfRenderWindow *window, menu_t *pause, player_t *player);
void check_menu_position(sfMouseMoveEvent mouse, button_t *options,
    menu_t *menu);
void check_menu_click(sfMouseButtonEvent mouse, button_t *options,
    menu_t *menu);
int manage_pause_event(sfRenderWindow *window, sfEvent *event, menu_t *pause);
//inventory
inventory_t *create_inventory(void);
void display_inventory(sfRenderWindow *w, player_t *player);
void manage_inventory_events(sfEvent *event, menu_t *pause, player_t *player);
void display_level_player(sfRenderWindow *window, player_t *player);

//destroy
void destroy_menu(menu_t *menu, int pause);
void destroy_how_to(sfFont *f, sfText *t, sfSprite *s);
button_t *destroy_buttons(button_t *button);
void destroy_visual(visual_t *visual);
button_t *destroy_buttons(button_t *button);
void destroy_player(player_t *player);
void destroy_game(game_t *game);

//boss
boss_t *malloc_boss();
boss_t *handle_boss(boss_t *boss, ingame_t *ingame);
void display_boss_health(sfRenderWindow *window, boss_t *boss);
void menu(sfRenderWindow *window, sfEvent *event, game_t *game);
boss_t *move_one(boss_t *boss);
boss_t *move_two(boss_t *boss);
boss_t *move_three(boss_t *boss);
boss_t *move_four(boss_t *boss);
boss_t *transform(boss_t *boss);
boss_t *next_transform(boss_t *boss);
boss_t *boss_jump(boss_t *boss);
void npc(boss_t *boss);
boss_t *fly_manage_clock(boss_t *boss, int x);
boss_t *fly_animations(boss_t *boss, int x);
boss_t *boss_fly(boss_t *boss);
boss_t *attack(boss_t *boss);
boss_t *move_to_next_position(boss_t *boss);

attack_circle_t *init_attackcircle(sfVector2f pos);
void destroy_attack_circle(attack_circle_t *attack);
attack_circle_t *handle_attackcircle(attack_circle_t *attack, player_t *player);
sfBool check_for_dmg(player_t *player, attack_circle_t *attack);
void destroy_boss(boss_t *boss);

//ingame
ingame_t *init_ingame(sfRenderWindow *window);
void manage_ingame_input(game_t *game);
void destroy_ingame(ingame_t *ingame);
void ingame(game_t *game);
ingame_t *init_ingame(sfRenderWindow *window);

//end
void handle_ending(game_t *game);
sfBool trigger_ending(game_t *game);
end_t *create_end(enum end_status status);
void display_lose(end_t *end, sfRenderWindow *window);
void display_win(end_t *end, sfRenderWindow *window);
int manage_end_event(sfRenderWindow *window, sfEvent *event, end_t *end);

//utils
int my_arrlen(char **arr);
void free_array(char **);
char *combine_strings(char *one, char *two, int con);
sfVector2f create_vector(int x, int y);
sfVector2f create_vectorf(float x, float y);
sfVector2f move_vector(sfVector2f object, sfVector2f offset);
char *my_int_to_str(int nb);
sfIntRect create_rect(int top, int left, int height, int width);
sfIntRect create_intrect(sfVector2f pos, sfVector2f size);
void move_rect(sfIntRect *rect, sfVector2f offset);
void move_rect_to(sfIntRect *rect, sfVector2f new_pos, sfVector2f bottom_left);
sfText *create_text(sfColor color, int size, sfVector2f pos, sfFont *font);
int my_strcmp(char *s1, char *s2);
sfMusic *play_music(char *str);

#endif
