#ifndef EXTRAS_H
#define EXTRAS_H
#include<cmath>
#include<SDL.h>
#include<iostream>
#include<stdio.h>
#include"defines.h"
struct light{
    int frameWidth;
    int frameHeight;
    int currentFrame;
    int maxFrame;
    };
struct arrow{
int x;
int y;
};
arrow arrow_update();
int frameUpdate(int fps, int currentFrame, int totalFrames, int* counter);
class button
{
    public:
    std::string type;
    int x_pos;
    int y_pos;
    int width;
    int height;
    int selected;
    SDL_Color color;
    void init(std::string p_type, int p_x_pos, int p_y_pos, int p_width, int p_height);
    bool update(button p_button);
};
class beam{
    public:
    bool alive = false;
    int x_pos;
    int y_pos;
    int width = 2;
    int height = 11;
    void update_beam();
};
class speakerIcon{
public:
    std::string name;
    int x_pos;
    int y_pos;
    int width;
    int height;

    void update(speakerIcon& p_icon);
    };
enum powerType{
                FIRE = 0,
                FAST_BALL=1,
                INCREASE_BALLS=2,
                BIG_PADDLE=3,
                SMALL_PADDLE = 4,
                STICKY_PADDLE=5,
                SLOW_BALL=6,
                BIG_BALL=7,
                SMALL_BALL=8,
                FIRE_BALL = 9,
                DEAD = 10,
                LEVEL_UP = 11,
                LIFE = 12,
                ALL_VISIBLE = 13,
                NONE=14};

double abs_double(double double_number);
double distance(double ax, double ay, double bx, double by);
void get_beam(beam p_beam[30], int x_pos, int width, int y_pos);
int visible_beams(beam p_beam[30]);
std::string integerToString(int p_score);
#endif // EXTRAS_H
