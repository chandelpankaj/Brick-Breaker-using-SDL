#include"paddle.h"
#include"extras.h"
#include<time.h>
void ball::update_velocity()
{
    ///x^2 + y^2 = vel^2
    ///since the direction of the ball should be same after increasing the velocity of ball
    ///ie x/y = const => x = const*y
    ///=> y^2 = vel^2\sqrt(const^2 + 1)
    ///similarly x^2 = vel^2\sqrt(1\const^2 + 1)


    double constant = x_vel/y_vel;
    if(x_vel!=0)
    {
        y_vel = (y_vel/abs_double(y_vel))*(vel)/(sqrt(constant*constant+1));
        x_vel = (x_vel/abs_double(x_vel))*(vel)/(sqrt(1/(constant*constant)+1));
    }
    else
    {
        y_vel = vel;
    }
}
void ball::update(ball& p_ball)
{

    //std::cout<<"before 27 x,y= "<<p_ball.x_vel<<" y="<<p_ball.y_vel<<" ";
    if(p_ball.y_vel!=0)
        p_ball.y_vel = p_ball.y_vel/abs_double(p_ball.y_vel)*sqrt(p_ball.vel*p_ball.vel - p_ball.x_vel*p_ball.x_vel);
    p_ball.x_pos += p_ball.x_vel;
    p_ball.y_pos += p_ball.y_vel;
    p_ball.c_x = p_ball.x_pos + p_ball.width/2;
    p_ball.c_y = p_ball.y_pos + p_ball.height/2;
    if(x_vel==0)
        if(y_vel > 0)
            p_ball.angle = 90;
        else
            p_ball.angle = -90;
    else
        p_ball.angle = atan(abs_double(p_ball.y_vel)/abs_double(p_ball.x_vel)) * 57.296; // to convert to degrees 180/pi = 57.29577;
    if(p_ball.x_vel > 0)
    {
        if(p_ball.y_vel > 0)
            p_ball.angle = p_ball.angle;
        else if(p_ball.y_vel < 0)
            p_ball.angle = -p_ball.angle;
    }
    else if(p_ball.x_vel < 0)
    {
        if(p_ball.y_vel < 0)
            p_ball.angle += 180;
        else
            p_ball.angle = 180 - p_ball.angle;
    }

    //std::cout<<"after27 "<<p_ball.y_vel<<"\n";
}
int randomNumber(int max)
{

    return rand()%(max+1);
}
void paddle::init(paddle &p_paddle, int x_pos, int y_pos, int height, int width, int frame)
{
    p_paddle.x_pos = x_pos;
    p_paddle.y_pos = y_pos;
    p_paddle.height = height;
    p_paddle.width = width;
    p_paddle.frame = frame;
}
void ball::init( double x, double y, int h, int w, int _frameWidth, int _frameHeight, double _max_vel, double _vel, double _radius, int _frame, int _maxFrame, double _angle, std::string _type)
{
    x_pos = x;
    y_pos = y;
    height = h;
    width = w;
    max_vel = _max_vel;
    x_vel = 0;
    y_vel = -1;
    vel = _vel;
    c_x = x_pos + width/2;
    c_y = y_pos + height/2;
    radius = _radius;
    frame = _frame;
    angle = _angle;
    type = _type;
    frameWidth = _frameWidth;
    maxFrame = _maxFrame;
    frameHeight = _frameHeight;
    alive = true;
    normal_vel = _vel;
}
void levelInit(brick p_brick[26][16], int level)
{
    time_t t;
	srand((unsigned)time(&t));
///first deactivate all the powers
    Uint64 l[50][27] = {

        0x0000000000000000,
0x0000000000000000,
0x0000000000000000,
0x0000000000000000,
0x0000000000000000,
0x0000000000000000,
0x0000000000000000,
0x1111111111111111,
0x1111111111111111,
0x8880008888000888,
0x8880008888000888,
0x6666666666666666,
0x6666666666666666,
0x4444444444444444,
0x4444444444444444,
0x0000000000000000,
0x0000000000000000,
0x0000000000000000,
0x0000000000000000,
0x0000000000000000,
0x0000000000000000,
0x0000000000000000,
0x0000000000000000,
0x0000000000000000,
0x0000000000000000,
0x0000000000000000,
0x0000000000000000,


0x0000000000000000,
0x0000000000000000,
0x0000000000000000,
0x0000000000000000,
0x0000000000000000,
0x1110001110001110,
0x1410001410001410,
0x1110001110001110,
0x0004440004440000,
0x0004140004140000,
0x0004440004440000,
0x1110001110001110,
0x1410001410001410,
0x1110001110001110,
0x0000000000000000,
0x0000000000000000,
0x0000000000000000,
0x0000000000000000,
0x0000000000000000,
0x0000000000000000,
0x0000000000000000,
0x0000000000000000,
0x0000000000000000,
0x0000000000000000,
0x0000000000000000,
0x0000000000000000,
0x0000000000000000,

0x0000000000000000,
0x0000000000000000,
0x0000001110000000,
0x0000011111000000,
0x0000111111111000,
0x0000666cc6c00000,
0x0006c6ccc6ccc000,
0x0006c66ccc6ccc00,
0x00066cccc6666000,
0x00000ccccccc0000,
0x0000114111000000,
0x0001114114111000,
0x0011114444111100,
0x00dd14844841dd00,
0x00ddd444444ddd00,
0x00dd44444444dd00,
0x0000444004440000,
0x0006660000666000,
0x0066660000666600,
0x0000000000000000,
0x0000000000000000,
0x0000000000000000,
0x0000000000000000,
0x0000000000000000,
0x0000000000000000,
0x0000000000000000,
0x0000000000000000,


0x0000000000000000,
0x0000000000000000,
0x0000000000000000,
0x0000000000000000,
0x0000000000000000,
0x0000000000000000,
0x0000000000000000,
0x0000000000000000,
0x000eee0000eee000,
0x00ee11e00e11ee00,
0x0ee1c11ee11c1ee0,
0xee1c11111111c1ee,
0xe1c1114414411c1e,
0xe1c1144646441c1e,
0xe1c1144666441c1e,
0x9e1c11443441c1e9,
0x09e1c114441c1e90,
0x009e1c1141c1e900,
0x0009e1c11c1e9000,
0x000094e11ee90000,
0x000009eeee900000,
0x0000009ee9000000,
0x0000000990000000,
0x0000000000000000,
0x0000000000000000,
0x0000000000000000,
0x0000000000000000,



0x0000000000000000,
0x0000000000000000,
0x0000000000000000,
0x0000000000000000,
0x0000000000000000,
0x0000044444400000,
0x0000401111040000,
0x000401eeee104000,
0x00401eeddee10400,
0x0401eeddddee1040,
0x4011111111111104,
0x4444444444444444,
0x4888848888488884,
0x4811148008481114,
0x4810148008481014,
0x4811148008481114,
0x4888848008488884,
0x4444448008444444,
0x0000000000000000,
0x0000000000000000,
0x0000000000000000,
0x0000000000000000,
0x0000000000000000,
0x0000000000000000,
0x0000000000000000,
0x0000000000000000,
0x0000000000000000,

0x0000000000000000,
0x0000000000000000,
0x0000000000000000,
0x0000000000000000,
0x0000100000100000,
0x0000010001000000,
0x0000010001000000,
0x0000666666600000,
0x0000666666600000,
0x00066e666e660000,
0x00066e666e660000,
0x0060666666606000,
0x0060666666606000,
0x0060600000606000,
0x0000600000600000,
0x0000060006000000,
0x0000000000000000,
0x0000000000000000,
0x0000000000000000,
0x0000000000000000,
0x0000000000000000,
0x0000000000000000,
0x0000000000000000,
0x0000000000000000,
0x0000000000000000,
0x0000000000000000,
0x0000000000000000,

0x0000000000000000,
0x4818181818181818,
0x1000000000000000,
0x8000000000000000,
0x1004181818181818,
0x8008000000000001,
0x1001000000000008,
0x8008004181814001,
0x1001008000008008,
0x8008001000101001,
0x1001004818408008,
0x8008000000001001,
0x1004181818184008,
0x8000000000000001,
0x1000000000000008,
0x4818101008181814,
0x0000000000000000,
0x0000000000000000,
0x0000000000000000,
0x0000000000000000,
0x0000000000000000,
0x0000000000000000,
0x0000000000000000,
0x0000000000000000,
0x0000000000000000,
0x0000000000000000,
0x0000000000000000,



0x0000000000000000,
0x0000000000000000,
0x0000000000000000,
0x00bbb00000bbb000,
0x00b8b00100b8b000,
0x00bbb01110bbb000,
0x0000011c11000000,
0x000011c8c1100000,
0x00011c8d8c110000,
0x0011c8ddd8c11000,
0x0011cedddec11000,
0x0011cedddec11000,
0x0011c8ddd8c11000,
0x0001c88888c10000,
0x00001ccccc100000,
0x0000011111000000,
0x000004ece4000000,
0x00004ec0ce400000,
0x0004ecc0cce40000,
0x004ec0c0c0ce4000,
0x0000000000000000,
0x0000000000000000,
0x0000000000000000,
0x0000000000000000,
0x0000000000000000,
0x0000000000000000,
0x0000000000000000


};
    for(int m=0;m<26;m++)
    {
        for(int n=0;n<16;n++)
        {

           p_brick[m][n].x_pos = 276 + n * 50;
            p_brick[m][n].y_pos = m * 25;
            p_brick[m][n].visible = true;
            p_brick[m][n].power = NONE;
                switch(0b1111 & (l[level][m]>>(60-4*n)))
                {
                case 0:
                    p_brick[m][n].visible = false;
                    break;
                case 1:
                    p_brick[m][n].type = "brickRed1";
                    break;
                case 2:
                    p_brick[m][n].type = "brickRed2";
                    break;
                case 3:
                    p_brick[m][n].type = "brickRed3";
                    break;
                case 4:
                    p_brick[m][n].type = "brickBlue1";
                    break;
                case 5:
                    p_brick[m][n].type = "brickBlue2";
                    break;
                case 6:
                    p_brick[m][n].type = "brickGreen1";
                    break;
                case 7:
                    //green2 is invincible
                    p_brick[m][n].type = "brickGreen2";
                    break;
                case 8:
                    p_brick[m][n].type = "brickYellow1";
                    break;
                case 9:
                    p_brick[m][n].type = "brickInvisible";
                    break;
                case 10:
                    p_brick[m][n].type = "brick";
                    break;
                case 11:
                    p_brick[m][n].type = "brickSilver1";
                    break;
                case 12:
                    p_brick[m][n].type = "brickOrange1";
                    break;
                case 13:
                    p_brick[m][n].type = "brickGrey1";
                    break;
                case 14:
                    p_brick[m][n].type = "brickPurple1";
                    break;
                default:
                    std::cout<<"type other\n";
                }
            }
            /*p_brick[m][n].visible = 1&(l[level][m]>>(15-n));
            p_brick[m][n].x_pos = 100 + n * 50;
            p_brick[m][n].y_pos = m * 25;
            if(1&(l[level][m]>>31-n))*/

    }


    //10 are max levels and other 15 number of powers in that level
    //10 means no power
    int powers[30][15]={1,1,3,4,4,6,10,14,14,14,14,14,14,14,14,
        //11,11,11,11,11,11,11,11,14,14,14,14,14,14,14,
    //level 2
    1,1,3,4,6,8,10,10,14,14,14,14,14,14,14,
    //level 3
    0,1,1,3,4,4,6,8,10,10,10,14,14,14,14,
    //level 4
    1,1,2,4,4,6,7,8,10,14,14,14,14,14,14,
    //level 5
    1,1,2,3,4,5,6,10,14,14,14,14,14,14,14,
    //level 6
    0,1,2,3,4,5,6,7,14,14,14,14,14,14,14,
    //level 7
    0,0,1,1,3,3,4,6,7,8,10,10,12,14,14,
    //level 8
    1,1,3,4,4,5,6,10,11,14,14,14,14,14,14,
    //level 9
    1,1,3,3,4,5,6,9,10,10,14,14,14,14,14,
    //level 10
    0,1,1,2,2,3,3,6,7,8,9,10,14,14,14,
    //level 11
    0,1,1,1,3,4,5,6,7,7,12,10,14,14,14
    };
/*int powers[10][15]={1,1,1,6,6,6,6,6,1,1,6,6,1,1,1,
    1,1,1,6,6,6,6,1,1,5,6,1,1,1,10,

    1,1,1,6,6,1,1,6,1,1,1,1,6,6,6,
    1,1,1,6,6,6,6,6,6,1,6,1,1,9,2,
    };*/
    for(int i = 0;i<15;i++)
    {
        int x,y;
        while(1)
        {
            //keep generating number until you found a visible brick of that coordinate
            y = randomNumber(P_MAX_BRICKS_COLUMN);
            x = randomNumber(P_MAX_BRICKS_ROW);
            if(p_brick[x][y].visible)
                break;
        }
        if(powers[level][i]==14)
            continue;
        p_brick[x][y].power = static_cast<powerType>(powers[level][i]);
        double xVelOfPower = static_cast<double>(randomNumber(30) - 15)/10;
        p_brick[x][y].power_vel = xVelOfPower;
    }


    ///initialise bricks with powers
    //6 means max 6 powers
   /* for(int i = 0; i < 50; i++)
    {
        int x,y;
        while(1)
        {
            //keep generating number until you found a visible brick of that coordinate
            y = randomNumber(P_MAX_BRICKS_COLUMN);
            x = randomNumber(P_MAX_BRICKS_ROW);
            if(p_brick[x][y].visible)
                break;
        }
        //now we have brick to give power to
        //but should decide power
        //we'll give more prefernces to some powers and less to some others
        //we have to generate a number between 0 and 29
        //power0 is given 1 time priority, power 1 is 4 times, power 2 is 2 times
        //p3 is 3 times, p4 is 4 times p5 is 2 times, p6 is 4 times
        //p7 is 4 times, p8 is 5 times, p9 is 1 time p10 is one time
        int rand_num =  randomNumber(32);

        if(rand_num < 1)
            p_brick[x][y].power = NONE;
        else if(rand_num < 5)
            p_brick[x][y].power = FAST_BALL;
        else if(rand_num < 7)
            p_brick[x][y].power = INCREASE_BALLS;
        else if(rand_num < 11)
            p_brick[x][y].power = BIG_PADDLE;
        else if(rand_num < 14)
            p_brick[x][y].power = SMALL_PADDLE;
        else if(rand_num < 16)
            p_brick[x][y].power = STICKY_PADDLE;
        else if(rand_num < 20)
            p_brick[x][y].power = SLOW_BALL;
        else if(rand_num < 24)
            p_brick[x][y].power = BIG_BALL;
        else if(rand_num < 29)
            p_brick[x][y].power = SMALL_BALL;
        else if(rand_num < 31)
            p_brick[x][y].power = FIRE_BALL;
        else
            p_brick[x][y].power = FIRE;

        ///now we have power set in any random brick
        //now we also have to set the random x_vel of the power
        //which is between -1 to +1 up to one decimal place
        //so we can generate a number between 0 and 21 and subtract 10 from it
        // so we'll have a number between -10 and +10 and divide it by 10
        double xVelOfPower = static_cast<double>(randomNumber(20) - 10)/10;
        p_brick[x][y].power_vel = xVelOfPower;
    }*/
}
void paddle::update()
{
    int mousex, mousey;
    SDL_GetMouseState(&mousex, &mousey);
    if(mousex>276 && mousex < 1076-width)
        x_pos = mousex;
    else if(mousex<=276)
    {
        x_pos = 276;
        SDL_WarpMouseGlobal(x_pos, mousey);
    }
    else if(mousex >=1076-width){
        x_pos = 1076-width;
        SDL_WarpMouseGlobal(x_pos, mousey);
    }
}
updateBallPaddle(ball &p_ball, paddle p_paddle)
{

    //return 1 if hit wall
    //return 2 if hit paddle
    // return 0 if hits nothing
    p_ball.c_x = p_ball.x_pos + p_ball.width/2.0;
    p_ball.c_y = p_ball.y_pos + p_ball.height/2.0;
    //keep the ball within wall
    //checks for hit with walls left right and up
    if(p_ball.c_x - p_ball.radius <= 276) //area is b/w 276 and 1076
    {
        p_ball.x_vel = abs_double(p_ball.x_vel);

        return 1;
    }
    else if(p_ball.c_x + p_ball.radius >=1076)
    {
        p_ball.x_vel = -abs_double(p_ball.x_vel);
        return 1;
    }
    if(p_ball.c_y - p_ball.radius <= 0)
    {
        p_ball.y_vel = abs_double(p_ball.y_vel);
        return 1;
    }

    if(p_ball.c_y > p_paddle.y_pos + (p_paddle.height + 10)/2) // checks if ball is ball is too below the paddle to hit
        return 0;
    if(p_ball.c_y + p_ball.radius < p_paddle.y_pos) // checks if ball is above the paddle
        return 0;

    //checks  if the ball is in the paddle
    if(p_ball.c_x >= p_paddle.x_pos && p_ball.c_x <= p_paddle.x_pos + p_paddle.width && p_ball.c_y >= p_paddle.y_pos)
        p_ball.y_pos = p_paddle.y_pos - p_ball.radius - p_ball.width/2;

    if(p_ball.c_x >= p_paddle.x_pos + p_paddle.width/10 && p_ball.c_x <= p_paddle.x_pos + p_paddle.width - p_paddle.width/10) //checks if ball hit the bat anywhere except corners
    {
        //check the distance from center of ball and paddle's left+10 ie except left corner
        double v = p_ball.c_x - (p_paddle.x_pos + p_paddle.width/10);
        //v increases towards right
        if(v <= (p_paddle.width - 20)/21.0) //divides by 13.0 to make it double
            p_ball.x_vel = -0.60*p_ball.vel; //paddle is divided in 13 parts 1 is zero vel other are in pairs having same abs(velocity)
        else if(v <= 2*(p_paddle.width - 20)/21.0)
            p_ball.x_vel = -0.54*p_ball.vel;
        else if(v <= 3*(p_paddle.width - 20)/21.0)
            p_ball.x_vel = -0.48*p_ball.vel;
        else if(v <= 4*(p_paddle.width - 20)/21.0)
            p_ball.x_vel = -0.42*p_ball.vel;
        else if(v <= 5*(p_paddle.width - 20)/21.0)
            p_ball.x_vel = -0.36*p_ball.vel;
        else if(v < 6*(p_paddle.width - 20)/21.0)
            p_ball.x_vel = -0.30*p_ball.vel;
        else if(v <= 7*(p_paddle.width - 20)/21.0)
            p_ball.x_vel = -0.24*p_ball.vel;
        else if(v <= 8*(p_paddle.width - 20)/21.0)
            p_ball.x_vel = -0.18*p_ball.vel;
        else if(v <= 9*(p_paddle.width - 20)/21.0)
            p_ball.x_vel = -0.12*p_ball.vel;
        else if(v < 10*(p_paddle.width - 20)/21.0) //equals towards left
            p_ball.x_vel = -0.06*p_ball.vel;         //side of paddle
        else if(v <= 11*(p_paddle.width - 20)/21.0)  //center area is max
            p_ball.x_vel = 0;                       //and not equal right side
        else if(v < 12*(p_paddle.width - 20)/21.0)   //so both sides area of impact is same
            p_ball.x_vel = 0.06*p_ball.vel;
        else if(v < 13*(p_paddle.width - 20)/21.0)
            p_ball.x_vel = 0.12*p_ball.vel;
        else if(v < 14*(p_paddle.width - 20)/21.0)
            p_ball.x_vel = 0.18*p_ball.vel;
        else if(v < 15*(p_paddle.width - 20)/21.0)
            p_ball.x_vel = 0.24*p_ball.vel;
        else if(v < 16*(p_paddle.width - 20)/21.0)
            p_ball.x_vel = 0.30*p_ball.vel;
        else if(v < 17*(p_paddle.width - 20)/21.0)
            p_ball.x_vel = 0.36*p_ball.vel;
        else if(v < 18*(p_paddle.width - 20)/21.0)
            p_ball.x_vel = 0.42*p_ball.vel;
        else if(v < 19*(p_paddle.width - 20)/21.0)
            p_ball.x_vel = 0.48*p_ball.vel;
        else if(v < 20*(p_paddle.width - 20)/21.0)
            p_ball.x_vel = 0.54*p_ball.vel;
        else
            p_ball.x_vel = 0.60*p_ball.vel;

        p_ball.y_vel = -abs_double(p_ball.y_vel);
        return 2;
    }
    if(distance(p_ball.c_x, p_ball.c_y, p_paddle.x_pos+10, p_paddle.y_pos+10) < p_ball.radius + 10)//10 is the radius of left circile of the paddle
    {
        //for corners as corners are round and also ball
        // it checks for left corner
        p_ball.x_vel = -0.8*p_ball.vel; //multiply by 0.8 so x vel becomes a little higher
        p_ball.y_vel = -abs_double(p_ball.y_vel);
        return 2;
    }
    else if(distance(p_ball.c_x, p_ball.c_y, p_paddle.x_pos+p_paddle.width -10, p_paddle.y_pos+10) < p_ball.radius + 10)//10 is the radius of left circile of the paddle
    {
        //checks for collision between right corner and ball
        p_ball.x_vel = 0.8*p_ball.vel;
        p_ball.y_vel = -abs_double(p_ball.y_vel);
        return 2;
    }
    return 0;
}
int updateBallBrick(ball & p_ball, brick & p_brick)
{
    //return binary
    //last 5 bits will be used
    // last bit 1 if colision 1 otherwise
    // 2nd last 1 if xvel is +ve ,0 if no change
    // 3rd last 1 if xvel is -ve, 0 if no change
    // 4th last 1 if yvel is +ve, 0 if no change
    // 5th last 1 if yvel is -ve ,0 if no change
    //6th last bit 1 if xvel may need to be increased a little
    p_ball.c_x = p_ball.x_pos + p_ball.width/2.0;
    p_ball.c_y = p_ball.y_pos + p_ball.height/2.0;

    if(p_ball.c_x + p_ball.radius < p_brick.x_pos) //checks if ball is too left to the brick
        return 0;
    if(p_ball.c_y +p_ball.radius < p_brick.y_pos)//checks if ball is too above
        return 0;
    if(p_ball.c_x - p_ball.radius > p_brick.x_pos + p_brick.width)//checks if ball is too right
        return 0;
    if(p_ball.c_y - p_ball.radius > p_brick.y_pos + p_brick.height)//checks if ball is too below
        return 0;


    //if it hits only down part not bottom corners;
    if(p_ball.c_y > p_brick.y_pos+p_brick.height && p_ball.c_x >= p_brick.x_pos &&p_ball.c_x <= p_brick.x_pos + p_brick.width)//checks if ball hits below brick
    {

        //p_ball.y_vel = abs_double(p_ball.y_vel);
        return 0b01001;
    }

    //checks if ball hits upper face of brick but not corners
    if(p_ball.c_y < p_brick.y_pos && p_ball.c_x >= p_brick.x_pos &&p_ball.c_x <= p_brick.x_pos + p_brick.width)
    {
        //std::cout<<"upper\n";
        //p_ball.y_vel = -abs_double(p_ball.y_vel);
        return 0b10001;
    }

    //checks if ball hits left side but not corners
    if(p_ball.c_x < p_brick.x_pos && p_ball.c_y >= p_brick.y_pos && p_ball.c_y <= p_brick.y_pos + p_brick.height)
    {
        //std::cout<<"left\n";

       // if(p_ball.x_vel==0)
         //   p_ball.x_vel = 0.5;  //sets a little velocity so that ball don't keep hitting other bricks above or below it
        //p_ball.x_vel = -abs_double(p_ball.x_vel);//if it hits a brick on left side it should be deflected toward right

        return 0b100101;
    }

    //checks if bal hits right side but not corners
    if(p_ball.c_x > p_brick.x_pos +p_brick.width && p_ball.c_y >= p_brick.y_pos && p_ball.c_y <= p_brick.y_pos + p_brick.height)
    {
        //std::cout<<"right\n";

        //if(p_ball.x_vel==0)
       //     p_ball.x_vel = 0.5;
        //p_ball.x_vel = abs_double(p_ball.x_vel);

        return 0b100011;
    }

    // checks for left upper corner
    if(distance(p_ball.c_x, p_ball.c_y , p_brick.x_pos, p_brick.y_pos)< p_ball.radius-2)
    {
        //std::cout<<"upper left\n";
        //check if ball hit left or upper side
        if(abs_double(p_ball.x_vel) > abs_double(p_ball.y_vel)) //if x vel is greater that
        {                                                   //means ball hits on left side
            //p_ball.x_vel = -abs_double(p_ball.x_vel);

            return 0b00101;
        }
        else if(abs_double(p_ball.x_vel) < abs_double(p_ball.y_vel))
        {
            //checks if ball hit upper side
            //p_ball.y_vel = -abs_double(p_ball.y_vel);

            return 0b01001;
        }
        else
        {
            // ball hit at exactly 45 degree ball should go upper left
            //p_ball.x_vel = -abs_double(p_ball.x_vel);
            //p_ball.y_vel = -abs_double(p_ball.y_vel);

            return 0b10101;
        }
    }

    //checks for upper
    //right corner
    if(distance(p_ball.c_x, p_ball.c_y , p_brick.x_pos+p_brick.width, p_brick.y_pos) < p_ball.radius-2)
    {
        //std::cout<<"upper right\n";
        if(abs_double(p_ball.x_vel) > abs_double(p_ball.y_vel)) //if x vel is greater that
        {                                                   //means ball hits on right side
            //p_ball.x_vel = -abs_double(p_ball.x_vel);

            return 0b00101;
        }
        else if(abs_double(p_ball.x_vel) < abs_double(p_ball.y_vel))
        {
            //checks if ball hit uright side of corner
            //p_ball.x_vel = abs_double(p_ball.x_vel);

            return 0b00011;
        }
        else
        {
            // ball hit at exactly 45 degree ball should go upper left
           // p_ball.x_vel = abs_double(p_ball.x_vel);
            //p_ball.y_vel = -abs_double(p_ball.y_vel);

            return 0b10011;
        }
    }

    //checks for bottom right corner
    if(distance(p_ball.c_x, p_ball.c_y , p_brick.x_pos+p_brick.width, p_brick.y_pos+p_brick.height) < p_ball.radius-2)//-2 just for less sensitivity of corners so that
    {                                                                                                                 //if 2 tiles are together bottom get hits first not corner of other tile
        if(abs_double(p_ball.x_vel) > abs_double(p_ball.y_vel)) //if x vel is greater that
        {                                                   //means ball hits on right side
            //checks for right side of corner
            //also checks if x velocity is not zero if so the set some little value
            //if(p_ball.x_vel == 0)
              //  p_ball.x_vel = 0.5;
            //p_ball.x_vel = abs_double(p_ball.x_vel);

            return 0b100011;
        }
        else if(abs_double(p_ball.x_vel) < abs_double(p_ball.y_vel))
        {
            //checks if ball hit uright side of corner
            //p_ball.y_vel = abs_double(p_ball.y_vel);

            return 0b01001;
        }
        else
        {
            // ball hit at exactly 45 degree ball should go upper left
            //p_ball.x_vel = abs_double(p_ball.x_vel);
            //p_ball.y_vel = abs_double(p_ball.y_vel);

            return 01011;
        }
    }

    //checks for bottom left corner
    if(distance(p_ball.c_x, p_ball.c_y , p_brick.x_pos, p_brick.y_pos+p_brick.height) < p_ball.radius-2)
    {
        if(abs_double(p_ball.x_vel) > abs_double(p_ball.y_vel)) //if x vel is greater that
        {                                                   //means ball hits on left side
            //checks for left side of corner
            //also checks if x velocity is not zero if so the set some little value
            //if(p_ball.x_vel == 0)
              //  p_ball.x_vel = 0.5;
            //p_ball.x_vel = -abs_double(p_ball.x_vel);

            return 0b100101;
        }
        else if(abs_double(p_ball.x_vel) < abs_double(p_ball.y_vel))
        {
            //checks if ball hit bottom side of corner
            //p_ball.y_vel = abs_double(p_ball.y_vel);

            return 0b01001;
        }
        else
        {
            // ball hit at exactly 45 degree ball should go upper left
            //p_ball.x_vel = -abs_double(p_ball.x_vel);
            //p_ball.y_vel = abs_double(p_ball.y_vel);

            return 0b01101;
        }
    }
    return 0;
}

int updateBallBrick(ball& p_ball, brick p_brick[26][16], power p_power[10])
{
    //returns 3 if brick type 1 is hit
    //returns 4 if brick type 2 is hit and turns to brick type 1
    //returns 0 if no brick hit
    int i{0},j{0};

    while(1)
    {
        if(p_brick[i][j].visible)
        {

            int status = updateBallBrick(p_ball, p_brick[i][j]);
            if(status & 1)
            {// only to update power type
                //set particular power and make that brick off power
                if(p_brick[i][j].power != NONE)
                {
                    for(int index=0 ;index<10;index++)
                    {
                        if(!p_power[index].alive)
                        {
                            p_power[index].type = p_brick[i][j].power;
                            p_power[index].x_pos = p_brick[i][j].x_pos;
                            p_power[index].y_pos = p_brick[i][j].y_pos;
                            p_power[index].alive = true;
                            p_power[index].y_vel = -1.4;
                            p_power[index].x_vel = p_brick[i][j].power_vel;
                            p_brick[i][j].power = NONE;
                            break;
                        }

                    }
                }
                //means there is collision as last bit is one
                //now check type of ball..it should be affected by ocllision or not
                if(p_ball.type == "ballFire"&&p_brick[i][j].type!="brickInvisible")
                {
                    //it should not be affected
                    //but brick hit should be changed
                    //if(p_brick[i][j].type == "brick1")

                        //if brick is type 1 then
                        p_brick[i][j].visible = false;
                        return 3;
                        //ball will not be affected

                    /*else if(p_brick[i][j].type == "brick2") //as fireball acts differently only for brick type 1 not 2 so this is not necessary
                    {
                        //ball should also be affected
                        p_brick[i][j].type = "brick1";
                        //just change type
                        //now change velocity of ball
                        if(status & 0b100000)
                            p_ball.x_vel += 0.5;
                        if(status & 0b010000)
                            p_ball.y_vel = -abs_double(p_ball.y_vel);
                        else if(status & 0b001000)
                            p_ball.y_vel = abs_double(p_ball.y_vel);
                        if(status & 0b000100)
                            p_ball.x_vel = -abs_double(p_ball.x_vel);
                        else if(status & 0b000010)
                            p_ball.x_vel = abs_double(p_ball.x_vel);
                        return 4;
                    }*/
                }
                else
                {
                    // logic if ball of anotehr type
                    //as for now only two ball types
                    //so change brick and also
                    //first change velocity of ball
                    if((status & 0b100000)&&p_ball.x_vel==0)
                        p_ball.x_vel = 0.5;
                    if(status & 0b010000)
                        p_ball.y_vel = -abs_double(p_ball.y_vel);
                    else if(status & 0b001000)
                        p_ball.y_vel = abs_double(p_ball.y_vel);
                    if(status & 0b000100)
                        p_ball.x_vel = -abs_double(p_ball.x_vel);
                    else if(status & 0b000010)
                        p_ball.x_vel = abs_double(p_ball.x_vel);

                    if(p_brick[i][j].type == "brickInvisible")
                    {
                        p_brick[i][j].type = "brick";
                        return 5;
                    }
                    else if(p_brick[i][j].type == "brickSilver1")
                    {
                        p_brick[i][j].type = "brickRed1";
                        return 4;
                    }
                    else if(p_brick[i][j].type == "brick")
                    {
                        p_brick[i][j].visible = false;
                        return 7;
                    }
                    else
                        p_brick[i][j].visible = false;
                    return 3;

                }
            }

        }
        j++;
        if(j==16)
        {
            i++;
            j=0;
        }
        if(i==26)
        {
            break;
        }
    }
    return 0;
}
bool isThereAnyBrick(brick p_brick[26][16])
{
    for(int i=0; i<26;i++)
        for(int j=0;j<16;j++)
            if(p_brick[i][j].visible)
                return true;
    return false;
}
bool changeBallType(ball& p_ball, std::string ball_type)
{
    if(ball_type == "ballFire")
    {
        if(p_ball.type == "ballFire")
        {

        p_ball.height = P_FBALL_N_SIDE;
        p_ball.width = P_FBALL_N_SIDE;
        p_ball.radius = P_FBALL_N_RADIUS;
            return true;
        }
        p_ball.frameHeight = 512;
        p_ball.frameWidth = 512;
        p_ball.height = P_FBALL_N_SIDE;
        p_ball.width = P_FBALL_N_SIDE;
        p_ball.x_pos = p_ball.c_x - p_ball.width/2;
        p_ball.y_pos = p_ball.c_y - p_ball.height/2;
        p_ball.maxFrame = 6;
        p_ball.radius = P_FBALL_N_RADIUS;
        p_ball.type = "ballFire";
        return true;
    }
    else
    {
        //didnt use beelow two statement because i have also used this function to make the ball of normal size of same type
        if(p_ball.type == "ballSimple")
        {

        p_ball.height = P_NBALL_N_SIDE;
        p_ball.width = P_NBALL_N_SIDE;
        p_ball.radius = P_NBALL_N_RADIUS;
            return true;
        }
        p_ball.frame = 0;
        p_ball.frameHeight = 111;
        p_ball.frameWidth = 111;
        p_ball.height = P_NBALL_N_SIDE;
        p_ball.width = P_NBALL_N_SIDE;

        p_ball.x_pos = p_ball.c_x - p_ball.width/2;
        p_ball.y_pos = p_ball.c_y - p_ball.height/2;
        p_ball.maxFrame = 1;
        p_ball.radius = P_NBALL_N_RADIUS;
        p_ball.type = "ballSimple";
        return true;
    }
    return false;
}
bool anyBallAlive(ball p_ball[P_MAX_BALLS])
{
    for(int i = 0;i<P_MAX_BALLS;i++)
        if(p_ball[i].alive)
        return true;
    return false;
}
void copyBall(ball& fromBall, ball& toBall)
{
    toBall.angle = fromBall.angle;
    toBall.c_x = fromBall.c_x;
    toBall.c_y = fromBall.c_y;
    toBall.frame = fromBall.frame;
    toBall.frameHeight= fromBall.frameHeight;
    toBall.frameWidth = fromBall.frameWidth;
    toBall.height = fromBall.height;
    toBall.maxFrame = fromBall.maxFrame;
    toBall.max_vel = fromBall.max_vel;
    toBall.time_multiple_balls = fromBall.time_multiple_balls;
    toBall.radius = fromBall.radius;
    toBall.type = fromBall.type;
    toBall.vel = fromBall.vel;
    toBall.width = fromBall.width;
    toBall.x_pos = fromBall.x_pos;
    toBall.y_pos = fromBall.y_pos;
    toBall.y_vel = fromBall.y_vel;
    toBall.x_vel = fromBall.x_vel;
    toBall.normal_vel = fromBall.normal_vel;
    toBall.stick = fromBall.stick;
    toBall.stick_pos = fromBall.stick_pos;
}
void increaseBalls(ball p_ball[P_MAX_BALLS])
{
    //first sort balls to the starting
    int j = P_MAX_BALLS - 1;

    for(int i = 0 ;i< P_MAX_BALLS;i++)
    {
        if(!p_ball[i].alive)
        {
            for(;j>0; j--)
            {
                if(p_ball[j].alive)
                {
                    if(i<j)
                    {
                        p_ball[i].alive = true;
                        copyBall(p_ball[j], p_ball[i]);
                        p_ball[j].alive = false;
                        break;
                    }
                }

            }
        }
    }

    int totalBalls = 0;
    for(int i = 0;i< P_MAX_BALLS; i++)
    {
        if(p_ball[i].alive)
        {

            totalBalls++;
        }

    }
    //check total alive balls


    for(int i = 0 ; i<totalBalls;i++)
    {
        if(2*i+totalBalls+1>P_MAX_BALLS - 1)
            break;
        copyBall( p_ball[i], p_ball[2*i+totalBalls]);
        p_ball[2*i+totalBalls].x_vel = -sqrt(p_ball[i].vel) + (randomNumber(4)-2)/10.0;
        p_ball[2*i+totalBalls].y_vel = -sqrt(p_ball[i].vel);
        p_ball[2*i+totalBalls].alive = true;
        copyBall( p_ball[i], p_ball[2*i+totalBalls+1]);
        p_ball[2*i+totalBalls+1].x_vel = sqrt(p_ball[i].vel)+ (randomNumber(4)-2)/10.0;
        p_ball[2*i+totalBalls+1].y_vel = -sqrt(p_ball[i].vel);
        p_ball[2*i+totalBalls+1].alive = true;
    }
}

void power::update(power& p_power)
{
////////////////////////////
////
///checks whether power is hitting the wall
///////if so divert the direction i.e. velocity
    if(p_power.x_pos <= 276)
        p_power.x_vel = abs_double(p_power.x_vel);
    else if(p_power.x_pos >= 1076-P_POWER_SIDE)
        p_power.x_vel = -abs_double(p_power.x_vel);
////////update the position according to velocity
    p_power.x_pos += p_power.x_vel;
    p_power.y_pos += p_power.y_vel;
    ////checks whether power should go left or right side
    if(p_power.x_vel < 0)
    {
        if(p_power.x_vel >= -0.08)
            p_power.x_vel = -0.08;
        p_power.x_vel += 0.001;
    }
    else
    {
        if(p_power.x_vel <= 0.08)
            p_power.x_vel = 0.08;
        p_power.x_vel -= 0.001;
    }

////////////manipulate y velocity of power;
    if(p_power.y_vel >= 1.7)
        p_power.y_vel = 1.7;
    p_power.y_vel+=0.01;

    /*static int x =0;
    x++;
    if(x<100)
    {
        p_power.y_pos -= 1;
        p_power.x_pos -= 0.3;
    }
    else
    {
        p_power.y_pos +=1;
        if(x<800 && p_power.x_pos >= 276)
            p_power.x_pos -= 0.3;
        else if(x < 800)
            p_power.x_pos += 0.4;

    }
    */


}
int checkPowerPaddle(power& p_power, paddle& p_paddle, ball p_ball[P_MAX_BALLS], brick p_brick[26][16], int& p_life)
{
    ///checks if power collides with paddle
    ///and make its effect on paddle or ball whichever it affects

    //std::cout<<"abefore956 "<<p_ball[0].y_vel<<" ";
    if(p_power.x_pos >= p_paddle.x_pos && p_power.x_pos <= p_paddle.x_pos + p_paddle.width && p_power.y_pos <= p_paddle.y_pos + p_paddle.width/2 && p_power.y_pos >= p_paddle.y_pos - P_POWER_SIDE)
    {
        //i.e. power collides with paddle
        ///first make power invisible
        p_power.alive = false;
        //std::cout<<"power is "<<p_power.type<<"\n";

        //now check what type of power is that
        if(p_power.type == INCREASE_BALLS)
        {
            increaseBalls(p_ball);
            for(int i = 0; i< P_MAX_BALLS; i++)
            {
                p_ball[i].time_multiple_balls = P_POWER_TIME;
            }

        }
        else if(p_power.type == BIG_PADDLE)
        {
            //increase size of paddle but increase equally on both sides
            p_paddle.width += 40;
            if(p_paddle.width > P_PADDLE_MAX_WIDTH)
                p_paddle.width = P_PADDLE_MAX_WIDTH;

        }
        else if(p_power.type == FAST_BALL)
        {
            for(int i=0; i<P_MAX_BALLS; i++)
            {
                //here p_max_balls is maximum numbers of balls, all velocities should be increased
                if(!p_ball[i].alive)
                    continue;
                p_ball[i].slow=false;
                if(p_ball[i].vel <= P_BALL_MAX_VEL/1.35)
                    p_ball[i].vel = p_ball[i].vel*1.35;
                else
                    p_ball[i].vel = P_BALL_MAX_VEL;
                p_ball[i].update_velocity();

                    //std::cout<<"yvel after = "<<p_ball[i].y_vel<<"\n";
            }
        }
        else if(p_power.type == SMALL_PADDLE)
        {
                p_paddle.width -= 40;
                if(p_paddle.width < P_PADDLE_MIN_WIDTH)
                    p_paddle.width = P_PADDLE_MIN_WIDTH;
        }
        else if(p_power.type == STICKY_PADDLE)
        {
            p_paddle.sticky = true;
        }
        else if(p_power.type == SLOW_BALL)
        {

            for(int i=0; i<20; i++)
            {
                    //here 20 is maximum numbers of balls, all velocities should be decreased
                if(!p_ball[i].alive)
                    continue;
                    //std::cout<<"yvel beforeslow = "<<p_ball[i].y_vel;
                ///since the ball is not alive so we dont need to change its velocity
                if(p_ball[i].slow)
                    continue;
                    p_ball[i].slow = true;
                ////if ball is already slow then dont do anything
                //just increas the time of power
                    p_ball[i].vel = P_BALL_MIN_VEL;
                p_ball[i].update_velocity();

                    //std::cout<<"yvel before slow= "<<p_ball[i].y_vel;
            }
        }
        else if(p_power.type == BIG_BALL)
        {
            for(int i = 0;i<20;i++)
            {
                //Check if ball has reached its max radius
                if(!p_ball[i].alive)
                    continue;
                //i.e if ball is max radius then dont increase size
                // as radius for both type of balls is different so two conditions
                if(p_ball[i].big)
                continue;
                    p_ball[i].big=true;
                    p_ball[i].small=false;
                if(p_ball[i].type=="ballfire")
                {

                     p_ball[i].height = P_FBALL_B_SIDE;
                    p_ball[i].width = P_FBALL_B_SIDE;
                    p_ball[i].radius = P_FBALL_B_RADIUS;
                }
                else
                {
                    p_ball[i].height = P_NBALL_B_SIDE;
                    p_ball[i].width = P_NBALL_B_SIDE;
                    p_ball[i].radius = P_NBALL_B_RADIUS;
                }
            }
        }
        else if(p_power.type == SMALL_BALL)
        {
            for(int i = 0;i<20;i++)
            {
                if(!p_ball[i].alive)
                    continue;
                ///check if ball is already small enough
                ///
                if(p_ball[i].small)
                    continue;
                    p_ball[i].slow=true;
                    p_ball[i].big=false;
                    if(p_ball[i].type=="ballfire")
                {

                     p_ball[i].height = P_FBALL_N_SIDE;
                    p_ball[i].width = P_FBALL_N_SIDE;
                    p_ball[i].radius = P_FBALL_N_RADIUS;
                }
                else
                {
                    p_ball[i].height = P_NBALL_N_SIDE;
                    p_ball[i].width = P_NBALL_N_SIDE;
                    p_ball[i].radius = P_NBALL_N_RADIUS;
                }
            }
        }
        else if(p_power.type == FIRE_BALL)
        {
            for(int i = 0 ; i<P_MAX_BALLS ;i++)
            {
                if(!p_ball[i].alive)
                    continue;
                changeBallType(p_ball[i], "ballFire");

            }
        }
        else if(p_power.type == FIRE)
        {
            p_paddle.fire = true;
        }
        else if(p_power.type == DEAD)
        {
            ///make all balls
            for(int i = 0;i<P_MAX_BALLS;i++)
            {
                p_ball[i].y_pos = 1000;
            }

        }
        else if(p_power.type == LEVEL_UP)
        {
            ///increase level
            ///make all bricks dead then automatically level will upgrade
            //dont need to add anonther code
            for(int i=0;i<26;i++)
                for(int j=0;j<16;j++)
                p_brick[i][j].visible=false;
        }
        else if(p_power.type == LIFE)
        {
            ///increase life
            p_life++;
        }
        else if(p_power.type == ALL_VISIBLE)
        {
            ///make all invisible bricks visible
            for(int i=0;i<26;i++)
            {
                for(int j =0;j<16;j++)
                {
                    if(p_brick[i][j].type =="brickInvisible")
                        p_brick[i][j].type = "brick";
                }
            }
        }
    //std::cout<<"after956 "<<p_ball[0].y_vel<<"\n";
    return true;

    }
    //std::cout<<"after956 "<<p_ball[0].y_vel<<"\n";
    return false;

}
void update_powers(ball p_ball[20], paddle& p_paddle)
{
    //std::cout<<"before1090 "<<p_ball[0].y_vel;
    //first check for balls time

    ///first decrease all power timers

    for(int i = 0; i < P_MAX_BALLS; i++)
    {
        if(!p_ball[i].alive)
            continue;


        if(p_ball[i].time_multiple_balls > 0)
            p_ball[i].time_multiple_balls--;
        //now remove those power effects whose life has been completed ie 0



    }


    ///first check total alive balls if there is only one and three balls power is still
    ///active then increase balls

    int total_balls=0;
    for(int i=0; i<P_MAX_BALLS;i++)
    {
        if(p_ball[i].alive)
            total_balls++;
    }
    if(total_balls == 1 && p_ball[0].time_multiple_balls > 0)
    {
        increaseBalls(p_ball);
        for(int i = 0;i<P_MAX_BALLS;i++)
            p_ball[i].time_multiple_balls--;
    }

}
void deactivateBalls(ball p_ball[P_MAX_BALLS])
{
    for(int i = 0 ;i< P_MAX_BALLS;i++)
    {
        p_ball[i].alive = false;
        p_ball[i].slow=false;
        p_ball[i].big=false;
        p_ball[i].small=false;
        p_ball[i].time_multiple_balls=0;

    }
}

bool updateBeamBrick(brick p_brick[26][16], beam& p_beam, power p_power[10])
{
    for(int i = 25 ;i>=0;i--)
    {
        for(int j = 0 ;j<16;j++)
        {
            if(!p_brick[i][j].visible)
                continue;
            //for checking the collision of beam and brick
            //i have checked whether y pos of beaem is above the bottom side of brick
            // but not whether or not it is too above
            // as it doesnt matter because beam can never pass through a brick
            //it makes all the brick below beam invisible
            if(p_beam.x_pos + p_beam.width >= p_brick[i][j].x_pos && p_beam.x_pos <= p_brick[i][j].x_pos + p_brick[i][j].width && p_beam.y_pos <= p_brick[i][j].y_pos + p_brick[i][j].height)
            {
                //reaching here means colission
                p_beam.alive = false;
                p_beam.y_pos = 1000;
                if(p_brick[i][j].type=="brickGreen2")
                    continue;
                p_brick[i][j].visible = false;



                if(p_brick[i][j].power != NONE)
                {
                    for(int index=0 ;index<10;index++)
                    {
                        if(!p_power[index].alive)
                        {
                            p_power[index].type = p_brick[i][j].power;
                            p_power[index].x_pos = p_brick[i][j].x_pos;
                            p_power[index].y_pos = p_brick[i][j].y_pos;
                            p_power[index].alive = true;
                            p_power[index].y_vel = -1.4;
                            p_power[index].x_vel = p_brick[i][j].power_vel;
                            p_brick[i][j].power = NONE;
                            break;
                        }

                    }
                }


                return true;
            }
        }
    }
    return false;
}

void autoPlay(ball p_ball[P_MAX_BALLS], paddle& p_paddle,brick p_brick[26][16])
{














    /*int lowestBall=-1;//index of ball that have highest y coordinate so that paddle will set itself according to the ball;
    double timeToPaddle = 0;
    int alive = 0;
    for(int i=0;i<P_MAX_BALLS;i++)
    {
        //to find lowest ball;
        if(!p_ball[i].alive)
            continue;
            alive = i;
        //if(p_ball[i].y_pos > p_ball[lowestBall].y_pos)
        if(p_ball[i].y_vel<=0)
            continue;
        if(lowestBall==-1){
            timeToPaddle = (p_paddle.y_pos - p_ball[i].y_pos-(p_ball[i].height-2*p_ball[i].radius)/2.0)/p_ball[i].y_vel;
        lowestBall=i;}
        if((p_paddle.y_pos - p_ball[i].y_pos-(p_ball[i].height-2*p_ball[i].radius)/2.0)/p_ball[i].y_vel < timeToPaddle)
        {

            lowestBall = i;
            timeToPaddle=  (p_paddle.y_pos - p_ball[i].y_pos-(p_ball[i].height-2*p_ball[i].radius)/2.0)/p_ball[i].y_vel ;
        }
    }
    if(lowestBall==-1)
        lowestBall =alive;
    timeToPaddle = (p_paddle.y_pos - p_ball[lowestBall].y_pos-(p_ball[lowestBall].height-2*p_ball[lowestBall].radius)/2.0)/p_ball[lowestBall].y_vel;
    /* this is just a try for artificial intelligence


    */
    //pos where the ball will touch the paddle...it is x coordinate of the screen not paddle
/*
    int meetPos = p_ball[lowestBall].c_x + p_ball[lowestBall].x_vel * timeToPaddle;
    p_paddle.x_pos = meetPos;

    if(p_paddle.x_pos<276)
        p_paddle.x_pos=276;
    if(p_paddle.x_pos+p_paddle.width>1076)
        p_paddle.x_pos=1076-p_paddle.width;*/
}
