class Game{
public:
    GameObjs gameObjs = GameObjs();
    Camera camera = Camera(0, 0, 1);
    Game(){
        Player player = Player(100, 100);
        gameObjs.players.push_back(player);
    }
    void update(){

    }
};