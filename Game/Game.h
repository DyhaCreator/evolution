class Game{
public:
    GameObjs gameObjs = GameObjs();
    void createNewFood(){
        Params params = Params();
        Food food = Food(random(0, params.Width), random(0, params.Width), random(params.MIN_SAT, params.MAX_SAT));
        gameObjs.food.push_back(food);
    }
    Game(){}
};