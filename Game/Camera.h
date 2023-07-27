class Camera{
public:
    float x, y, z;
    Camera(float x, float y, float z){
        this->x = x;
        this->y = y;
        this->z = z;
    }
    void follow(float x, float y){
        Params params = Params();
        float soft = 0.025;
        x -= params.Width / 2;
        y -= params.Height / 2;
        this->x += (x - this->x) * soft;
        this->y += (y - this->y) * soft;
    }
};