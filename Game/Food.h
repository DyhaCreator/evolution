class Food{
public:
    float x, y, sat;
    sf::Color color;
    Food(float x, float y, float sat, sf::Color color){
        this->x = x;
        this->y = y;
        this->sat = sat;
        this->color = color;
    }
};