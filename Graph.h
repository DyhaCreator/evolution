class Graph{
public:
    bool isOpen = true;
    const int Width = 1080;
    const int Height = 720;
    const int FRAMERATE = 10000;
    sf::Event ev;
    sf::RenderWindow window = sf::RenderWindow(sf::VideoMode(1080,720), "Evolution");
    Graph(){
        this->window.setFramerateLimit(FRAMERATE);
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
    void render(){
        this->window.clear(sf::Color(150, 150, 150));

        

        this->window.display();
    }
};