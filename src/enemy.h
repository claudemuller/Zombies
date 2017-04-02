#ifndef _ENEMY_H
#define _ENEMY_H

extern struct Enemy {
    int w, h;
    float x, y;
    float dx, dy;
    float speed;
    const char* filename;

    void (*render)(struct Enemy* enemy);
    void (*update)(void);
};

void enemy_render(struct Enemy* enemy);
void enemy_update(void);
void detectCollision(void);

#endif //_ENEMY_H
