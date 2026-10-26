# Reversi
## how to use

1. build a container
```
sudo docker compose up -d --build
```
2. Compile C++ project
First, you need to configure Ninja as the build system.
And then, the code building executes.
```
sudo docker compose exec cpp-builder cmake -S . -B build -G Ninja
sudo docker compose exec cpp-builder cmake --build build
```
3. Execute application
```
sudo docker compose exec cpp-builder ./build/reversi
```

4. Generate a document
```
sudo docker compose exec cpp-builder 
```
