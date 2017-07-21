#include"game.h"

bool game::init(const char* title, int x, int y, int w, int h, int flag)
{
    if(SDL_Init(SDL_INIT_EVERYTHING)!=0)
    {
        std::cout<<"SDL Initialisation failed "<<SDL_GetError()<<std::endl;
        SDL_Quit();
        return false;
    }
    else
    {
        std::cout<<"SDL Initialisation successful\n";
    }
    win = SDL_CreateWindow(title, x, y, w, h, flag);
    if(!win)
    {
        std::cout<<"Window creation failed "<<SDL_GetError()<<std::endl;
        SDL_DestroyWindow(win);
        SDL_Quit();
        return false;
    }
    else
    {
        std::cout<<"Window creation successful\n";
    }
    renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
    if(!renderer)
    {
        std::cout<<"Renderer creation failed "<<SDL_GetError()<<std::endl;
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return false;
    }
    else
    {
        std::cout<<"renderer creation successful";
    }

    SDL_ShowCursor(SDL_DISABLE);
    SDL_SetRenderDrawColor(renderer, 255, 0, 100, 255);
    m_paddle.init(m_paddle, w/2 ,h-40, P_PADDLE_NORMAL_HEIGHT, P_PADDLE_NORMAL_WIDTH, 0);
    m_ball[0].init( w/2+40, h-60, 14, 14, 111, 111, P_BALL_MAX_VEL, P_BALL_NORMAL_VEL, 7, 0, 1, -90, "ballSimple");
    m_button[0].init("RESUME", 540, 200, 250, 80);
    m_button[1].init ("START", 540, 350, 250, 80);
    m_button[2].init("EXIT", 540, 500, 250, 80);
    m_speaker = {"speakerOn", 70, 50, 40, 40};
    m_light = {200, 36, 0, 5};
    m_textureManager.load("assets/paddleRed.png", "paddle1", renderer);
    m_textureManager.load("assets/beam.png", "beam", renderer);
    m_textureManager.load("assets/paddle2.png", "paddle", renderer);
    m_textureManager.load("assets/ballFlame.png", "ballFire", renderer);
    m_textureManager.load("assets/ball.png", "ballSimple", renderer);
    m_textureManager.load("assets/background.png", "background", renderer);
    m_textureManager.load("assets/lightening2.png", "light", renderer);
    m_textureManager.load("assets/button_green.png", "button", renderer);
    m_textureManager.load("assets/cursor.png", "cursor", renderer);
    m_textureManager.load("assets/background1.jpg", "background1", renderer);
    m_textureManager.load("assets/speakerOff.png", "speakerOff", renderer);
    m_textureManager.load("assets/gameOver.png", "gameOver", renderer);
    m_textureManager.load("assets/bullet.png", "bullet", renderer);

    m_textureManager.load("assets/brickBlue.png", "brickBlue1",renderer);
    m_textureManager.load("assets/brickGreen.png", "brickGreen1",renderer);
    m_textureManager.load("assets/brickGrey.png", "brickGrey1",renderer);
    m_textureManager.load("assets/brickPurple.png", "brickPurple1",renderer);
    m_textureManager.load("assets/brickRed.png", "brickRed1",renderer);
    m_textureManager.load("assets/brickRed2.png", "brickRed2",renderer);
    m_textureManager.load("assets/brickSilver.png", "brickSilver1",renderer);
    m_textureManager.load("assets/brickYellow.png", "brickYellow1",renderer);
    m_textureManager.load("assets/brickOrange.png", "brickOrange1",renderer);

    m_textureManager.load("assets/brick.png", "brick",renderer);



    m_textureManager.load("assets/power00.png", "power00", renderer);
    m_textureManager.load("assets/power15.png", "power01", renderer);
    m_textureManager.load("assets/power02.png", "power02", renderer);
    m_textureManager.load("assets/power03.png", "power03", renderer);
    m_textureManager.load("assets/power04.png", "power04", renderer);
    m_textureManager.load("assets/power05.png", "power05", renderer);
    m_textureManager.load("assets/power06.png", "power06", renderer);
    m_textureManager.load("assets/power08.png", "power07", renderer);
    m_textureManager.load("assets/power08.png", "power08", renderer);
    m_textureManager.load("assets/power09.png", "power09", renderer);
    m_textureManager.load("assets/power10.png", "power10", renderer);
    m_textureManager.load("assets/power12.png", "power11", renderer);
    m_textureManager.load("assets/power13.png", "power12", renderer);
    m_textureManager.load("assets/power14.png", "power13", renderer);

    m_textureManager.load("assets/speakerOn.png", "speakerOn", renderer);
    m_textureManager.loadFont("fonts/SEASRN.ttf", "font_one", 100);
    m_textureManager.loadFont("fonts/FFF_Tusj.ttf", "font_two", 64);
    m_textureManager.loadFont("fonts/StampyLight.ttf","font_three",50);

    m_soundManager.load("assets/musicBackground.mp3", "musicBackground", SOUND_MUSIC);
    m_soundManager.load("sounds/AMemoryAway.ogg", "musicMenu", SOUND_MUSIC);
    m_soundManager.load("sounds/Gunfire.wav", "beam", SOUND_SFX);
    m_soundManager.load("assets/paddle.wav", "paddle", SOUND_SFX);
    m_soundManager.load("assets/brick.wav", "brick1", SOUND_SFX);
    m_soundManager.load("assets/brick2.wav", "brick2", SOUND_SFX);
    m_soundManager.load("assets/wall.wav", "wall", SOUND_SFX);
    m_soundManager.load("assets/glass.wav", "glass", SOUND_SFX);
    m_soundManager.load("assets/beat.mp3", "beat", SOUND_MUSIC);
    m_soundManager.load("assets/beat.wav", "beat2", SOUND_MUSIC);
    m_soundManager.load("assets/drum.wav", "drum", SOUND_SFX);
    m_soundManager.load("assets/Saucer.wav", "saucer", SOUND_SFX);
    m_soundManager.load("assets/fire.wav", "fire", SOUND_SFX);
    m_soundManager.load("sounds/switch2.wav", "switch2", SOUND_SFX);
    m_soundManager.play_music("musicMenu", 0);



    m_currentLevel = 0;
    levelInit(m_brick, m_currentLevel);
    m_arrow = arrow_update();
    m_screen = 0;
    return true;
}
void game::render()
{
    SDL_RenderClear(renderer);
    /*std::cout<<"\n\n\n\n";
    for(int i = 0;i<20;i++)
    {
        if(m_ball[i].alive)
        std::cout<<"live = "<<m_ball[i].alive<<" x = "<<m_ball[i].x_pos<<" y = "<<m_ball[i].y_pos<<" rad = "<<m_ball[i].radius<<" xvel= "<<m_ball[i].x_vel<<"y_vel = "<<m_ball[i].y_vel<<"\n";
    }*/
    m_textureManager.draw("background1",0,0,1366,768,renderer);
    if(m_screen==1||m_screen==3)
    {


       m_textureManager.draw("background", 250, 0, 851, 768, renderer);

       for(int i=0;i<m_life;i++)
       {
           m_textureManager.draw("paddle1", 1016 - i*60 , 5, 60, 14, renderer);
       }

       for(int i = 0;i<30;i++)
       {
           if(m_beam[i].alive)
                m_textureManager.draw("beam", m_beam[i].x_pos, m_beam[i].y_pos, m_beam[i].width, m_beam[i].height, renderer);
       }

        for(int i = 0;i<26;i++)
            for(int j=0;j<16;j++)
            {
            if(m_brick[i][j].visible == true&&m_brick[i][j].type!="brickInvisible")
                m_textureManager.draw(m_brick[i][j].type, m_brick[i][j].x_pos, m_brick[i][j].y_pos, m_brick[i][j].width, m_brick[i][j].height, renderer);
            }
        if(!m_start || m_paddle.sticky)
            m_textureManager.drawFrame("light", m_paddle.x_pos, m_paddle.y_pos-m_paddle.height, m_paddle.width, m_paddle.height, m_light.frameWidth, m_light.frameHeight, m_light.currentFrame, 0, renderer);

        //m_textureManager.draw("cursor", m_paddle.x_pos,105,127,127, renderer);
        for(int i=0;i<20;i++)
        {
            if(m_ball[i].alive)
                m_textureManager.drawFrame(m_ball[i].type, m_ball[i].x_pos, m_ball[i].y_pos, m_ball[i].width, m_ball[i].height, m_ball[i].frameWidth, m_ball[i].frameHeight, m_ball[i].frame, m_ball[i].angle, renderer);

        }
        //104 PIXEL WIDTH OF PADDLE AND 24 HEIGHT
        m_textureManager.drawFrame("paddle", m_paddle.x_pos, m_paddle.y_pos, m_paddle.width, m_paddle.height, 92, 19, m_paddle.frame, 0, renderer);
        if(m_paddle.fire)
        {
            m_textureManager.draw("bullet", m_paddle.x_pos, m_paddle.y_pos-10, 5,10,renderer);
            m_textureManager.draw("bullet", m_paddle.x_pos+m_paddle.width-5, m_paddle.y_pos-10, 5,10,renderer);
        }
        //to draw the power
        for(int i = 0;i< 20 ;i++)
        {
            if(m_power[i].alive)
            {
                m_textureManager.draw(std::string("power")+static_cast<char>(m_power[i].type/10+48) + static_cast<char>(m_power[i].type%10+48), m_power[i].x_pos, m_power[i].y_pos, 40, 40, renderer);
            }
        }

        m_textureManager.drawText("font_three", integerToString(m_score),0,0,renderer);

        if(m_screen==3)
            m_textureManager.draw("gameOver", 300, 200, 0,0, renderer);

    }
    else if(m_screen == 0)
    {
        for(int i = 0; i < 3; i++)
        {
            m_textureManager.draw("button" , m_button[i].x_pos, m_button[i].y_pos, m_button[i].width, m_button[i].height, renderer);

            m_textureManager.drawText("font_two", m_button[i].type, m_button[i].x_pos+m_button[i].width/5, m_button[i].y_pos+m_button[i].height/7, m_button[i].width/1.6, m_button[i].height/1.8,m_button[i].color, renderer);
        }
        m_textureManager.draw(m_speaker.name, m_speaker.x_pos, m_speaker.y_pos, m_speaker.width, m_speaker.height, renderer);

        m_textureManager.draw("cursor", m_arrow.x, m_arrow.y, 20,30, renderer);
    }
    else if(m_screen == 2)
    {
        m_textureManager.drawText("font_two", std::string("LEVEL ") + static_cast<char>(m_currentLevel/10+48) + static_cast<char>(m_currentLevel - m_currentLevel/10 + 48), 100,100, renderer);
    }
     SDL_RenderPresent(renderer);

}
void game::handleEvents()
{
    static int wait =0;
    wait++;
    SDL_Event ev;
    int button_x, button_y;
    int buttons = SDL_GetMouseState(&button_x, &button_y);
    if(buttons & SDL_BUTTON_LEFT)
    {
        if(m_screen == 1 && m_counter>30)
        {
            m_start = true;
            for(int i=0; i<20;i++)
                m_ball[i].stick = false;
            if(visible_beams(m_beam)<5&&wait>10 && m_paddle.fire)
            {
                wait = 0;
                m_soundManager.play_sound("beam",0);
                get_beam(m_beam, m_paddle.x_pos, m_paddle.width, m_paddle.y_pos);
            }

        }
        else if(m_screen == 0)
        {
            if(m_button[0].selected&&m_life)
                {
                    //m_counter to zero so we can wait till next screen
                    m_screen = 1;
                    m_counter = 0;

                    SDL_WarpMouseGlobal(m_paddle.x_pos, m_button[0].y_pos); // to keep the paddle at original position
                }
            else if(m_button[1].selected)
            {
                m_life=3;
                m_score = 0;
                m_paddle.init(m_paddle, 500 ,728, P_PADDLE_NORMAL_HEIGHT, P_PADDLE_NORMAL_WIDTH, 0);
                for(int i=0;i<20;i++)
                {
                   if(m_ball[i].alive)
                        m_ball[i].init( 540, 708, 14, 14, 111, 111, P_BALL_MAX_VEL, P_BALL_NORMAL_VEL, 7, 0, 1, -90, "ballSimple");
                }
                levelInit(m_brick, 0);
                //m_soundManager.play_music("musicBackground", 0);

                m_screen = 1;
                m_counter = 0;
                m_start = false;
            }
            else if(m_button[2].selected)
            {
                m_running = false;
            }
        }
    }
    while(SDL_PollEvent(&ev)!=0)
    {
        switch(ev.type)
        {
        case SDL_QUIT:
            m_running = false;
            break;
        case SDL_KEYDOWN:
            switch(ev.key.keysym.scancode)
            {
            case SDL_SCANCODE_1:
                for(int i=0;i<20;i++)
                {
                    if(m_ball[i].alive)
                        if(m_ball[i].type!="ballSimple")
                            changeBallType(m_ball[i], "ballSimple");
                }
                break;
            case SDL_SCANCODE_2:
                for(int i=0;i<20;i++)
                {
                    if(m_ball[i].alive)
                        if(m_ball[i].type!="ballFire")
                            changeBallType(m_ball[i], "ballFire");
                }
                break;
            case SDL_SCANCODE_O:
                if(m_currentLevel!=0)
                    levelInit(m_brick, 0);
                    m_currentLevel = 0;
                break;
            case SDL_SCANCODE_P:
                if(m_currentLevel!=1)
                    levelInit(m_brick, 1);
                    m_currentLevel = 1;
                break;
            case SDL_SCANCODE_K:
                if(m_currentLevel!=2)
                    levelInit(m_brick, 2);
                    m_currentLevel = 2;
                break;
            case SDL_SCANCODE_L:
                if(m_currentLevel!=3)
                    levelInit(m_brick, 3);
                    m_currentLevel = 3;
                break;
            case SDL_SCANCODE_ESCAPE:
                    m_screen = 0;
                break;
            case SDL_SCANCODE_F4:
                m_paddle.width++;
                break;
            case SDL_SCANCODE_F3:
                m_paddle.width--;
                break;
            case SDL_SCANCODE_F11:
                increaseBalls(m_ball);
                break;
            case SDL_SCANCODE_Z:
                for(int i=0;i<P_MAX_BALLS;i++)
                    {if(m_ball[i].alive)
                std::cout<<"\n\nx vel =" <<m_ball[i].x_vel<<"xpos = "<<m_ball[i].x_pos<<"yvel ="<<m_ball[i].y_vel<<"ypos= "<<m_ball[i].y_pos<<" vel= "<<m_ball[i].vel<<" nvel= "<<m_ball[i].normal_vel<<" rad= "<<m_ball[i].radius<<" wid= "<<m_ball[i].width<<std::endl;


                    }
                break;
            default:
                break;
            }
            break;

        }
    }
}
void game::update()
{
    ///////////////counter just to use for frame updation of various sprites
    //////////////outside loop so that frame updates only once every rendering
   /////////////////////////////////////////////////////////////////////////////////


    m_counter++;
    ////////update the frame of lightening
     m_light.currentFrame = frameUpdate(30, m_light.currentFrame, m_light.maxFrame, &m_counter);
     m_paddle.frame=frameUpdate(10,m_paddle.frame, 2,&m_counter);

     ///////loop 4 times so that everything updated 4 times every rendering
     //////made it 4 times so that ball movement in every updation can be kept low while keeping velocity per rendering high
     /////so that collision detection can be made more accurately

    for(int i = 0; i<4; i++)
    {

        m_arrow = arrow_update();
        if(m_screen == 0)
        {
            for(int i = 0; i < 3; i++)
                if(m_button[i].update(m_button[i]))
                    m_soundManager.play_sound("switch2",0);
                    m_speaker.update(m_speaker);
                if(m_speaker.name=="speakerOff")
                {
                    Mix_PauseMusic();
                }
                else
                {
                    if(Mix_PlayingMusic()!=0)
                    Mix_ResumeMusic();
                }
        }
        else if(m_screen == 1)
        {
            m_wait++;

            for(int i = 0;i<20;i++)
            {
           	 //just to update the falling power
                if(m_power[i].alive)
                {
                    m_power[i].update(m_power[i]);

                    if(checkPowerPaddle(m_power[i], m_paddle, m_ball , m_brick, m_life))
                	{
                	    m_score += 5*P_SCORE;
                   	 ///play some music power collides with paddle
               		}

                }

            }
            //turns the power off after a certain time
        update_powers(m_ball, m_paddle);
        m_paddle.update(); //just update the paddle poisition to the mouse pointer

        //autoPlay(m_ball, m_paddle,m_brick, m_fp);
        for(int i=0;i<30;i++)
        {
            if(m_beam[i].alive)
            {
                //first update the pos of beam
                m_beam[i].update_beam();
                //now check for colision of beam and brick;
                if(updateBeamBrick(m_brick, m_beam[i],m_power))
                {
                    m_score += P_SCORE;
                    m_soundManager.play_sound("brick1",0);
                }
            }
        }
        ///we also have to check for colision of beam and brick

        for(int j = 0 ;j< P_MAX_BALLS ;j++)
        {
            //if there is no j ball the skip everything
            if(!m_ball[j].alive)
                continue;   // to update the pointer poisition stored in m_arrow


                m_ball[j].frame = frameUpdate(7, m_ball[j].frame, m_ball[j].maxFrame, &m_counter);

                hit = updateBallBrick(m_ball[j], m_brick, m_power);
                if(hit)
                    m_score+= 1.5*P_SCORE + (m_currentLevel/7)*P_SCORE;
                //hit is zero if no brick is hit
                //if ball falls down make its alive to false
                if(m_ball[j].y_pos!=m_ball[j].y_pos)
                {
                    m_ball[j].y_pos = P_WINDOW_HEIGHT + 100;
                    std::cout<<"inside reseting y pos ";
                }
                if(m_ball[j].y_pos > P_WINDOW_HEIGHT)
                {
                        m_ball[j].alive = false;
                        if(!anyBallAlive(m_ball))
                        {
                            ///reaching here means no balls so one life should be reduced
                            m_start = false;
                            m_life--;
                            //if there is no ball then make first ball alive
                            m_ball[0].alive = true;
                            m_ball[0].y_pos = m_paddle.y_pos- m_ball[j].height;
                            changeBallType(m_ball[0], "ballSimple");
                            m_ball[0].vel = P_BALL_NORMAL_VEL;
                            m_paddle.fire = false;
                            m_paddle.sticky = false;
                            m_ball[0].stick = true;
                            m_paddle.width = P_PADDLE_NORMAL_WIDTH;
                            if(m_life == 0)
                            {
                                m_screen=3;
                                m_ball[0].x_pos = m_paddle.x_pos + m_paddle.width/2;
                            }
                            break;
                        }

                }



            if(!m_start){
                m_ball[j].x_pos = m_paddle.x_pos + m_paddle.width/2 - m_ball[j].width/2 + m_paddle.width/50;
                m_ball[j].y_pos = m_paddle.y_pos - (m_ball[j].height/2 + m_ball[j].radius);


            }
            else if(m_ball[j].stick)
            {

                m_ball[j].x_pos = m_paddle.x_pos + m_ball[j].stick_pos;
                if(m_ball[j].stick_pos<=0 || m_ball[j].stick_pos >= m_paddle.width - m_ball[j].width)
                    m_ball[j].y_pos =m_paddle.y_pos - (m_ball[j].height/2 + m_ball[j].radius) + m_ball[j].radius/5;
                else
                    m_ball[j].y_pos = m_paddle.y_pos - (m_ball[j].height/2 + m_ball[j].radius);

            }
            else
            {

                m_ball[j].update(m_ball[j]); // update velocity and other things of ball

                hit = (updateBallPaddle(m_ball[j], m_paddle)|hit);

                if(hit==2 && m_paddle.sticky == true)
                {
                    // hit == 2 means that ball hits paddle and if
                    //paddle is sticky then stick ball to it
                    //calculate stick_pos that is distance where ball hit paddle from x coord of paddle
                    // if ball hits far left or far right make it inward
                    m_ball[j].stick = true;
                    m_ball[j].stick_pos = m_ball[j].x_pos - m_paddle.x_pos;
                    if(m_ball[j].stick_pos < 0)
                    {

                        m_ball[j].stick_pos = 0;
                    }
                    else if(m_ball[j].stick_pos > m_paddle.width - m_ball[j].width)
                    {
                        m_ball[j].stick_pos = m_paddle.width - m_ball[j].width;

                    }
                }
                else
                {
                    //-1 means that ball dont stick
                    m_ball[j].stick = false;
                    m_ball[j].stick_pos = -1;
                }
                if(m_start)
                    m_start = isThereAnyBrick(m_brick);
                if(!isThereAnyBrick(m_brick))
                {
                    // if there is no brick then upgrade level
                    m_currentLevel = (m_currentLevel + 1)%P_MAX_LEVELS;
                    //make all balls except first dead and make that simpleball
                    ///deactivate all powers
                    deactivateBalls(m_ball);
                    for(int i = 0; i< 20;i++)
                        m_power[i].alive = false;
                    m_ball[0].alive = true;
                    m_ball[0].y_pos=0;
                    changeBallType(m_ball[0], "ballSimple");
                    m_ball[0].vel = m_ball[0].normal_vel;
                    m_paddle.fire = false;
                    m_paddle.sticky = false;
                    m_paddle.width = P_PADDLE_NORMAL_WIDTH;
                    m_ball[j].y_pos = m_paddle.y_pos - m_ball[j].height;
                    levelInit(m_brick, m_currentLevel);
                    m_screen = 2;
                    m_wait=0;
                    //m_soundManager.play_music("musicBackground",0);
                }
            }

        if(hit==2)
            m_soundManager.play_sound("paddle", 0);
        else if(hit==1)
            m_soundManager.play_sound("wall", 0);
        else if(hit==3)
            m_soundManager.play_sound("brick1", 0);
        else if(hit==4)
            m_soundManager.play_sound("brick2", 0);
        else if(hit==5)
            m_soundManager.play_sound("glass", 0);
        else if(hit==6)
            m_soundManager.play_sound("drum", 0);
        else if(hit==7)
            m_soundManager.play_sound("saucer", 0);
        else if(hit==8)
            m_soundManager.play_sound("fire",0);
        hit = 0;

        }

        }
        else if(m_screen == 2||m_screen==3)
        {
            m_wait++;
            hit = 0;
            if(m_wait >= 1000)// wait for 1000 frame updates not fps
            {
                if(m_screen==2)
                m_screen = 1;
                else if(m_screen==3){
                    m_screen = 0;

                }
                m_wait = 0;
            }
        }
    }







   /*
    m_counter++;
    ////////update the frame of lightening
     m_light.currentFrame = frameUpdate(30, m_light.currentFrame, m_light.maxFrame, &m_counter);

     ///////loop 4 times so that everything updated 4 times every rendering
     //////made it 4 times so that ball movement in every updation can be kept low while keeping velocity per rendering high
     /////so that collision detection can be made more accurately
    for(int i = 0; i<4; i++)
    {

        for(int i = 0;i<10;i++)
        {
            //just to update the falling power
            if(m_power[i].alive)
            {
                m_power[i].update(m_power[i]);

                if(checkPowerPaddle(m_power[i], m_paddle, m_ball))
                {
                    ///play some music
                }

            }

        }

        for(int j = 0 ;j<20 ;j++)
        {
            //if there is no j ball the skip everything
            if(!m_ball[j].alive)
                continue;
            m_arrow = arrow_update();   // to update the pointer poisition stored in m_arrow
            if(m_screen == 1)
            {
                m_paddle.update();      //just update the paddle poisition to the mouse pointer
                m_ball[j].frame = frameUpdate(7, m_ball[j].frame, m_ball[j].maxFrame, &m_counter);

                hit = updateBallBrick(m_ball[j], m_brick, m_power);
                //hit is zero if no brick is hit
                //if ball falls down make its alive to false
                if(m_ball[j].y_pos > P_WINDOW_HEIGHT){
                        m_ball[j].alive = false;
                        if(!anyBallAlive(m_ball))
                        {
                            //if there is no ball then make first ball alive
                            m_start = false;
                            m_ball[0].alive = true;
                            m_ball[0].stick = true;
                        }
                }



            if(!m_start){
                m_ball[j].x_pos = m_paddle.x_pos + m_paddle.width/2 - m_ball[j].width/2 + m_paddle.width/50;
                m_ball[j].y_pos = m_paddle.y_pos - (m_ball[j].height/2 + m_ball[j].radius);


            }
            else if(m_ball[j].stick)
            {

                m_ball[j].x_pos = m_paddle.x_pos + m_ball[j].stick_pos;
                if(m_ball[j].stick_pos<=0 || m_ball[j].stick_pos >= m_paddle.width - m_ball[j].width)
                    m_ball[j].y_pos =m_paddle.y_pos - (m_ball[j].height/2 + m_ball[j].radius) + m_ball[j].radius/5;
                else
                    m_ball[j].y_pos = m_paddle.y_pos - (m_ball[j].height/2 + m_ball[j].radius);

            }
            else
            {

                m_ball[j].update(m_ball[j]); // update velocity and other things of ball

                hit = (updateBallPaddle(m_ball[j], m_paddle)|hit);

                if(hit==2 && m_paddle.sticky == true)
                {
                    // hit == 2 means that ball hits paddle and if
                    //paddle is sticky then stick ball to it
                    //calculate stick_pos that is distance where ball hit paddle from x coord of paddle
                    // if ball hits far left or far right make it inward
                    m_ball[j].stick = true;
                    m_ball[j].stick_pos = m_ball[j].x_pos - m_paddle.x_pos;
                    if(m_ball[j].stick_pos < 0)
                    {

                        m_ball[j].stick_pos = 0;
                    }
                    else if(m_ball[j].stick_pos > m_paddle.width - m_ball[j].width)
                    {
                        m_ball[j].stick_pos = m_paddle.width - m_ball[j].width;

                    }
                }
                else
                {
                    m_ball[j].stick = false;
                    //-1 means that ball dont stick
                    m_ball[j].stick_pos = -1;
                }
                if(m_start)
                    m_start = isThereAnyBrick(m_brick);
                if(!isThereAnyBrick(m_brick))
                {
                    // if there is no brick then upgrade level
                    m_currentLevel = (m_currentLevel + 1)%4;
                    //make all balls except first dead and make that simpleball
                    for(int i = 1;i<20;i++)
                        m_ball[i].alive = false;
                    m_ball[0].alive = true;
                    changeBallType(m_ball[0], "ballSimple");
                    m_paddle.fire = false;
                    m_paddle.sticky = false;
                    m_ball[j].y_pos = m_paddle.y_pos - m_ball[j].height;
                    levelInit(m_brick, m_currentLevel);
                    m_screen = 2;
                    //m_soundManager.play_music("musicBackground",0);
                }
            }
        }


        else if(m_screen == 0)
        {
            hit = 0;
            for(int i = 0; i < 3; i++)
                hit = hit|m_button[i].update(m_button[i]);
                m_speaker.update(m_speaker);
                if(m_speaker.name=="speakerOff")
                {
                    Mix_PauseMusic();
                }
                else
                {
                    if(Mix_PlayingMusic()!=0)
                    Mix_ResumeMusic();
                }
        }
        else if(m_screen == 2)
        {
            m_wait++;
            hit = 0;
            if(m_wait >= 1000)// wait for 1000 frame updates not fps
            {
                m_screen = 1;
                m_wait = 0;
            }
        }

        if(hit==2)
            m_soundManager.play_sound("paddle", 0);
        else if(hit==1)
            m_soundManager.play_sound("wall", 0);
        else if(hit==3)
            m_soundManager.play_sound("brick1", 0);
        else if(hit==4)
            m_soundManager.play_sound("brick2", 0);
        else if(hit==5)
            m_soundManager.play_sound("glass", 0);
        else if(hit==6)
            m_soundManager.play_sound("drum", 0);
        else if(hit==7)
            m_soundManager.play_sound("saucer", 0);
        else if(hit==8)
            m_soundManager.play_sound("fire",0);
        else if(hit==9)
            m_soundManager.play_sound("switch2",0);
        hit = 0;
    }
    }*/
 }
void game::clean()
{
    SDL_DestroyWindow(win);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}
