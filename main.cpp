#include "graphics.h"
#include "Game.h"




void update(float ms)
{
    Game* g = (Game*)graphics::getUserData();

    g->update();

}

// The window content drawing function.
void draw()
{
    Game* g = (Game*)graphics::getUserData();
    
    g->draw();
}

int main()
{

    Game BallBattle;
    graphics::createWindow(BallBattle.width_window, BallBattle.height_window,BallBattle.NameofGame);

    graphics::setDrawFunction(draw);
    graphics::setUpdateFunction(update);

    graphics::setCanvasSize(BallBattle.width_camva, BallBattle.height_camva);
    graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);

    graphics::Brush br = BallBattle.br;
    br.fill_color[0] = 1.0f;
    br.fill_color[1] = 1.0f;
    br.fill_color[2] = 0.9f;
    
    graphics::setWindowBackground(br);

    graphics::setFont(BallBattle.font_window);

    graphics::setUserData(&BallBattle);

    graphics::playMusic("assets\\space.mp3", 0.3, true, 0);
    graphics::startMessageLoop();
    

   

    return 0;
}