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
    void render(Game game){
        this->window.clear(sf::Color(150, 150, 150));

        for(int i = 0; i < game.gameObjs.food.size(); i++){
            sf::CircleShape circle(game.gameObjs.food[i].sat);
            circle.setPosition(game.gameObjs.food[i].x, game.gameObjs.food[i].y);
            circle.setFillColor(game.gameObjs.food[i].color);
            this->window.draw(circle);
        }

        this->window.display();
    }
};