class GameObjs{
public:
    std::vector<Player>players = std::vector<Player>();
    std::vector<Food>food = std::vector<Food>();
    GameObjs(){}
    void createNewFood(){
        Params params = Params();
        Food foodObj = Food(random(0, params.SIZE_MAP_X),
            random(0, params.SIZE_MAP_Y),
            random(params.MIN_SAT, params.MAX_SAT),
            sf::Color(randint(0, 255), randint(0, 255), randint(0, 255)));
        food.push_back(foodObj);
    }
};