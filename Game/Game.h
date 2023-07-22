class Game{
public:
    GameObjs gameObjs = GameObjs();
    Camera camera = Camera(0, 0, 1);
    Game(){
        Params params = Params();
        Player player = Player(params.Width / 2, params.Height / 2, 40, sf::Color(255, 0, 0));
        gameObjs.players.push_back(player);
    }
    void update(float Mx, float My){
        Params params = Params();
        for(int i = 0; i < gameObjs.players.size(); i++){
            gameObjs.players[i].move(Mx - params.Width / 2, My - params.Height / 2);
        }
        camera.x = gameObjs.players[0].x - params.Width / 2;
        camera.y = gameObjs.players[0].y - params.Height / 2;
    }
};