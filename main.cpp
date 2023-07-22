#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Game/Eat.h"
#include "Game/Players.h"
#include "Game/GameObjs.h"
#include "Game/Game.h"
#include "Graph.h"

int main(){
    Graph gr = Graph();
    Game game = Game();
    while(gr.isOpen){
        gr.update();
        gr.render();
    }
    return 0;
}