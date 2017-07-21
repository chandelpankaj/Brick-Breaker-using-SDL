#ifndef PADDLE_H
#define PADDLE_H
#include<iostream>
#include<SDL.h>
#include"extras.h"
#include"defines.h"

#include<stdio.h>
class paddle{

public:
    void init(paddle &p_paddle, int x_pos, int y_pos, int height, int width, int frame);
    void update();
    int x_pos;
    int y_pos;
    int height;
    int width;
    int frame;
    bool sticky = false;
    bool fire = false;
};
class ball{

public:
    void update(ball& p_ball);
    void update_velocity();
    void init( double x, double y, int h, int w, int _frameWidth, int _frameHeight, double _max_vel, double _vel, double _radius, int _frame, int _maxFrame, double _angle, std::string _type);
    std::string type;
    double x_pos;
    double y_pos;
    int height;
    int width;
    double max_vel;
    double x_vel;
    double y_vel;
    double vel;
    double normal_vel;
    double c_x;
    double c_y;
    double radius;
    int frame;
    int maxFrame;
    int frameWidth;
    int frameHeight;
    double angle;
    bool alive;
    bool stick = false;
    int stick_pos = -1;
    bool slow=false;
    bool big = false;
    bool small = false;
    int time_multiple_balls;
};
class brick{

public:
    int x_pos;
    int y_pos;
    std::string type;
    powerType power;
    int height = 25;
    int width = 50;
    bool visible = false;
    double power_vel = -0.8;

};
class power{
public:
    std::string name;
    powerType type;
    double x_vel= 0.8;
    double y_vel = -1.4;
    double x_pos;
    double y_pos;
    bool alive = false;
    void update(power& p_power);
};
class bullet{
public:

};
int checkPowerPaddle(power& p_power, paddle& p_paddle, ball p_ball[20], brick p_brick[26][16], int& p_life);

int updateBallBrick(ball& p_ball, brick p_brick[26][16], power p_power[10]);
int updateBallBrick(ball& p_ball, brick & p_brick);
void levelInit(brick p_brick[26][16],int level);
bool isThereAnyBrick(brick p_brick[26][16]);
int updateBallPaddle(ball &p_ball, paddle p_paddle);
bool changeBallType(ball &p_ball, std::string ball_type);
void increaseBalls(ball p_ball[20]);
bool anyBallAlive(ball p_ball[20]);
void copyBall(ball& fromBall, ball& toBall);
int randomNumber();
void update_powers(ball p_ball[20], paddle& p_paddle);
void deactivateBalls(ball p_ball[P_MAX_BALLS]);
bool updateBeamBrick(brick p_brick[26][16], beam& p_beam, power p_power[10]);
void autoPlay(ball p_ball[P_MAX_BALLS], paddle& p_paddle, brick p_brick[26][16]);
#endif // PADDLE_H
