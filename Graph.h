class Graph{
public:
    bool isOpen = true;
    Params params = Params();
    const int Width = 1080;
    const int Height = 720;
    sf::Event ev;
    sf::RenderWindow window = sf::RenderWindow(sf::VideoMode(params.Width, params.Height), "Evolution");
    Graph(){
        this->window.setFramerateLimit(params.FRAMERATE);
    }
    void update(){
        this->isOpen = this->window.isOpen();
        while(this->window.pollEvent(this->ev)){
            switch(this->ev.type){
            case sf::Event::Closed:
                this->window.close();
                break;
            }
        }
    }
    void render(Game game, float x, float y){
        this->window.clear(sf::Color(150, 150, 150));

        for(int i = 0; i < game.gameObjs.food.size(); i++){
            if( game.gameObjs.food[i].x - game.camera.x > 0 &&
                game.gameObjs.food[i].x - game.camera.x < params.Width &&
                game.gameObjs.food[i].y - game.camera.y > 0 &&
                game.gameObjs.food[i].y - game.camera.y < params.Height){
                sf::CircleShape circle(this->params.FOOD_SIZE * (game.gameObjs.food[i].sat / 10));
                circle.setPosition( game.gameObjs.food[i].x - game.camera.x - this->params.FOOD_SIZE * (game.gameObjs.food[i].sat / 10), 
                                    game.gameObjs.food[i].y - game.camera.y - this->params.FOOD_SIZE * (game.gameObjs.food[i].sat / 10));
                circle.setFillColor(game.gameObjs.food[i].color);
                this->window.draw(circle);
            }
        }

        for(int i = 0; i < game.gameObjs.players.size(); i++){
            sf::CircleShape circle(game.gameObjs.players[i].mass);
            circle.setPosition( game.gameObjs.players[i].x - game.camera.x - game.gameObjs.players[i].mass,
                                game.gameObjs.players[i].y - game.camera.y - game.gameObjs.players[i].mass);
            circle.setFillColor(game.gameObjs.players[i].color);
            this->window.draw(circle);
        }

        sf::CircleShape circle(15);
        circle.setPosition(sf::Mouse::getPosition(this->window).x - 15, sf::Mouse::getPosition(this->window).y - 15);
        circle.setFillColor(sf::Color(100, 100, 100));
        this->window.draw(circle);

        this->window.display();
    }

    void drawLine(int x1, int y1, int x2, int y2, int s, sf::Color color){
        sf::ConvexShape convex;

        convex.setPointCount(4);

        convex.setPoint(0, sf::Vector2f(x1, y1));
        convex.setPoint(1, sf::Vector2f(x2, y2));
        convex.setPoint(2, sf::Vector2f(x2, y2));
        convex.setPoint(3, sf::Vector2f(x1, y1));

        convex.setOutlineThickness(1);
        convex.setOutlineColor(color);

        this->window.draw(convex);
    }
};