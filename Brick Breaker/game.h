#ifndef GAME_H
#define GAME_H
#include<SDL.h>
#include<string>
#include"textureM.h"
#include"soundM.h"
#include"paddle.h"
#include<stdio.h>
#include"fontManager.h"
#include<iostream>
#include"defines.h"
class game{

public:
    bool init(const char* title, int x, int y, int w, int h, int flag);
    void render();
    void handleEvents();
    void update();
    bool running(){return m_running;}
    void clean();
private:
    bool m_running = true;
    SDL_Window* win = nullptr;
    SDL_Renderer* renderer = nullptr;
    textureManager m_textureManager;
    soundManager m_soundManager;
    paddle m_paddle;
    ball m_ball[P_MAX_BALLS];
    button m_button[3];
    light m_light;
    arrow m_arrow;
    brick m_brick[26][16];
    power m_power[20];
    beam m_beam[30];
    bool m_start = false;
    int hit=0;
    int m_counter=0;
    int m_wait = 0;
    int m_currentLevel;
    int m_screen;
    int m_life = 3;
    int m_score = 0;
    speakerIcon m_speaker;
};
#endif // GAME_H
