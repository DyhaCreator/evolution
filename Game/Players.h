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
        Params params = Params();
        float max_speed = 10;
        float acceleration = 0.1;
        float r = acos(x / sqrt(x * x + y * y));
        if(y < 0)r = M_PI * 2 - r;
        speedX += cos(r) * acceleration;
        speedY += sin(r) * acceleration;
        if(sqrt(speedX * speedX + speedY * speedY) > max_speed){
            //std::cout << "h" << std::endl;
            speedX -= cos(r) * acceleration;
            speedY -= sin(r) * acceleration;
        }
        this->x += speedX;
        this->y += speedY;
    }
};