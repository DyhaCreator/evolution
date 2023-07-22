echo "compile"
g++ -c main.cpp -I /SFML/include
g++ main.o -o sfml-app -L /SFML/lib -lsfml-graphics -lsfml-window -lsfml-system
rm main.o
echo "start>"
./sfml-app