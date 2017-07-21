#include"extras.h"
void get_beam(beam p_beam[30], int x_pos, int width, int y_pos)
{
    for(int i = 0;i<30;i++)
    {
        if(!p_beam[i].alive)
        {
            p_beam[i].alive = true;
            p_beam[i].x_pos = x_pos;
            p_beam[i].y_pos = y_pos;
            break;
        }

    }
    //two loops as there are two beams to be  produced but at differetn places
    for(int i = 0;i<30;i++)
    {
        if(!p_beam[i].alive)
        {
            p_beam[i].alive = true;
            p_beam[i].x_pos = x_pos + width - p_beam[i].width;
            p_beam[i].y_pos = y_pos;

            break;
        }

    }

}
void beam::update_beam()
{
    y_pos -= P_BEAM_VEL;//velocity of beam
    if(y_pos < 0)
        alive = false;
    if(alive == false)
        y_pos = 1000;
}

int visible_beams(beam p_beam[30])
{
    int counter =0;
    for(int i=0;i<30;i++)
        if(p_beam[i].alive)
            counter++;
    return counter;
}
int frameUpdate(int fps, int currentFrame, int totalFrames, int* counter)
{
    if(fps == 0)
        fps = 1;
    if(*counter%(60/fps)==0)
    {
        currentFrame++;
        return currentFrame%totalFrames;
    }
    return currentFrame;
}
double abs_double(double double_number)
{
    if(double_number > 0)
        return double_number;
    else
        return (-double_number);
}

double distance(double ax, double ay, double bx, double by)
{
    return sqrt((bx - ax)*(bx - ax) + (by - ay)*(by - ay));
}
void button::init(std::string p_type, int p_x_pos, int p_y_pos, int p_width, int p_height)
{
    type = p_type;
    x_pos = p_x_pos;
    y_pos = p_y_pos;
    width = p_width;
    height = p_height;
    selected = 0;
    color = {0, 0, 0, 0};
}
bool button::update(button p_button)
{
    ///returns  1 if pointer goes above button
    int x, y;
    SDL_GetMouseState(&x,&y);
    if(x >=  p_button.x_pos + 10 && x <= p_button.x_pos - 10 + p_button.width && y >= p_button.y_pos && y <= p_button.y_pos + p_button.height - 18)
    {
        if(p_button.selected == 1)
            return false;
        selected = 1;
        color = {0,255,0,0};
        return true;
    }
    else
    {   if(p_button.selected == 0)
            return false;
        selected = 0;
        color = {0,0,0,0};
        return false;
    }
    return 0;
}
arrow arrow_update()
{
    arrow ARROW;
    SDL_GetMouseState(&ARROW.x, &ARROW.y);
    return ARROW;
}
void speakerIcon::update(speakerIcon& p_icon)
{
    int x, y;
    static int z=0;
    int p_button = SDL_GetMouseState(&x, &y);
    z++;
    if(z <= 50)
        return ;
    if(x >= p_icon.x_pos && x <= p_icon.x_pos + p_icon.width && y >= p_icon.y_pos && y <= p_icon.y_pos + p_icon.height)
    {
        if(p_button & SDL_BUTTON_LEFT)
            {
                if(p_icon.name=="speakerOff")
                {
                    p_icon.name= "speakerOn";
                    z=0;
                }
                else
                {
                    p_icon.name = "speakerOff";
                    z=0;
                }
            }
    }
}
std::string integerToString(int p_score)
{
    std::string str="";
    if(p_score > 999999)
        str = str + static_cast<char>(p_score/100000 + 48);
    str = str +  static_cast<char>(48 + p_score/10000 - (p_score/100000)*10) +  static_cast<char>(48 + p_score/1000 - (p_score/10000)*10) +  static_cast<char>(48 + p_score/100 - (p_score/1000)*10) +  static_cast<char>(48 + p_score/10 - (p_score/100)*10) + static_cast<char>(48 + p_score%10);
return str;

}
