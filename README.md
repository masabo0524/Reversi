# Reversi
## how to use
1. build a container
sudo docker compose up -d --build
2. Compile C++ project
sudo docker compose exec cpp-builder cmake -S . -B build -G Ninja
sudo docker compose exec cpp-builder cmake --build build
