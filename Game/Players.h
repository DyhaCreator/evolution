class Player{
public: 
    float x, y, mass;
    float speedX = 0, speedY = 0;
    sf::Color color;
    Player(float x, float y, float mass, sf::Color color){
        this->x = x;
        this->y = y;
        this->mass = mass;
        this->color = color;
    }
    void move(float x, float y){
        float acceleration = 0.1;
        if(x > 0)speedX+=0.1;
        if(x < 0)speedX-=0.1;
        if(y > 0)speedY+=0.1;
        if(y < 0)speedY-=0.1;
        this->x += speedX;
        this->y += speedY;
    }
};