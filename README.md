# TETRIS-CONSOLE-GAME-CPP
Continuing the series of making console games with C++ | #2 TETRIS GAME

Text Editor: Visual Studio Code

Compiler: TDM-GCC_Mingw 11.2.0

Command line:

    windres Tetris.rc -O coff -o Tetris.res
    
    g++ -std=c++17 main.cpp DoHoa.cpp Tetris.res -o Tetris -lwinmm

Some pictures of the game:

![image](https://user-images.githubusercontent.com/88151568/217937034-8f5e0a6b-a8c6-402d-bd51-88e29a4eccf4.png)

![image](https://user-images.githubusercontent.com/88151568/217937517-6f835b49-7594-4bf8-b1c2-ad6f2fc90ba2.png)

![image](https://user-images.githubusercontent.com/88151568/217937770-d6181e1e-d2c0-4589-a3d1-45adfba95a55.png)
