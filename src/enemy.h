#ifndef _ENEMY_H
#define _ENEMY_H

void enemy_render(void);
void enemy_update(void);

extern struct Enemy {
    int w, h;
    float x, y;
    float dx, dy;
    const char* filename;

    void (*render)(void);
    void (*update)(void);
};

#endif //_ENEMY_H
