#ifndef _PLAYER_H
#define _PLAYER_H

void player_init(void);
void player_render(void);
void player_update(void);

extern struct Player {
    int w, h;
    float x, y;
    float dx, dy;
    float speed;
    const char* filename;

    void (*init)(void);
    void (*render)(void);
    void (*update)(void);
};

#endif //_PLAYER_H
