#include "DoHoa.h"

const int WIDTH = 41;
const int HEIGHT = 30;
string dot = "  ";
const int _ = INT_MIN;
vector<vector<vector<vector<int>>>> shapes = {
    {{{19, 1}, {21, 1}, {23, 1}}, // 0
    {{_, _}, {21, 2}, {_, _}}},

    {{{_, _}, {21, 1}, {_, _}}, // 1
    {{19, 2}, {21, 2}, {23, 2}}},

    {{{_, _}, {21, 1}}, // 2
     {{19, 2}, {21, 2}},
     {{_, _}, {21, 3}}
    },

    {{{21, 1}, {_, _}}, // 3
     {{21, 2}, {23, 2}},
     {{21, 3}, {_, _}}
    },

    {{{19, 1}, {21, 1}, {23, 1}}, // 4
     {{19, 2}, {_, _}, {_, _}}
    },

    {{{19, 1}, {21, 1}, {23, 1}}, // 5
     {{_, _}, {_, _}, {23, 2}}
    },

    {{{19, 1}, {21, 1}}, // 6
     {{19, 2}, {_, _}},
     {{19, 3}, {_, _}}
    },

    {{{19, 1}, {_, _}}, // 7
     {{19, 2}, {_, _}},
     {{19, 3}, {21, 3}}
    },

    {{{19, 1}, {21, 1}}, // 8
     {{_, _}, {21, 2}},
     {{_, _}, {21, 3}}
    },

    {{{_, _}, {21, 1}}, // 9
     {{_, _}, {21, 2}},
     {{19, 3}, {21, 3}}
    },

    {{{_, _}, {_, _}, {23, 1}}, // 10
     {{19, 2}, {21, 2}, {23, 2}}
    },

    {{{19, 1}, {_, _}, {_, _}}, // 11
     {{19, 2}, {21, 2}, {23, 2}}
    },

    {{{19, 1}, {21, 1}, {23, 1}, {25, 1}}}, // 12

    {{{21, 1}}, // 13
     {{21, 2}},
     {{21, 3}},
     {{21, 4}}
    },

    {{{19, 1}, {21, 1}}, // 14
     {{19, 2}, {21, 2}}
    },

    {{{19, 1}, {21, 1}, {_, _}}, // 15
     {{_, _}, {21, 2}, {23, 2}}
    },

    {{{_, _}, {21, 1}, {23, 1}}, // 16
     {{19, 2}, {21, 2}, {_, _}}
    },

    {{{_, _}, {21, 1}}, // 17
     {{19, 2}, {21, 2}},
     {{19, 3}, {_, _}},
    },

    {{{19, 1}, {_, _}}, // 18
     {{19, 2}, {21, 2}},
     {{_, _}, {21, 3}},
    },
};
vector<vector<int>> center = {
    {21, 1}, {21, 1},{21, 2}, {21, 2}, {21, 1},
    {21, 1}, {19, 2}, {19, 2}, {21, 2}, {21, 2},
    {21, 2}, {21, 2}, {21, 1}, {21, 2}, {19, 1},
    {21, 1}, {21, 1}, {21, 2}, {21, 2}
};
vector<vector<vector<int>>> current_shape;
vector<vector<vector<vector<int>>>> next_shapes = {
    {{{59, 11}, {61, 11}, {63, 11}}, // 0
    {{_, _}, {61, 12}, {_, _}}},

    {{{_, _}, {61, 11}, {_, _}}, // 1
    {{59, 12}, {61, 12}, {63, 12}}},

    {{{_, _}, {63, 11}}, // 2
     {{61, 12}, {63, 12}},
     {{_, _}, {63, 13}}
    },

    {{{61, 11}, {_, _}}, // 3
     {{61, 12}, {63, 12}},
     {{61, 13}, {_, _}}
    },

    {{{59, 11}, {61, 11}, {63, 11}}, // 4
     {{59, 12}, {_, _}, {_, _}}
    },

    {{{59, 11}, {61, 11}, {63, 11}}, // 5
     {{_, _}, {_, _}, {63, 12}}
    },

    {{{61, 11}, {63, 11}}, // 6
     {{61, 12}, {_, _}},
     {{61, 13}, {_, _}}
    },

    {{{61, 11}, {_, _}}, // 7
     {{61, 12}, {_, _}},
     {{61, 13}, {63, 13}}
    },

    {{{59, 11}, {61, 11}}, // 8
     {{_, _}, {61, 12}},
     {{_, _}, {61, 13}}
    },

    {{{_, _}, {61, 11}}, // 9
     {{_, _}, {61, 12}},
     {{59, 13}, {61, 13}}
    },

    {{{_, _}, {_, _}, {63, 11}}, // 10
     {{59, 12}, {61, 12}, {63, 12}}
    },

    {{{59, 11}, {_, _}, {_, _}}, // 11
     {{59, 12}, {61, 12}, {63, 12}}
    },

    {{{59, 11}, {61, 11}, {63, 11}, {65, 11}}}, // 12

    {{{61, 10}}, // 13
     {{61, 11}},
     {{61, 12}},
     {{61, 13}}
    },

    {{{61, 11}, {63, 11}}, // 14
     {{61, 12}, {63, 12}}
    },

    {{{59, 11}, {61, 11}, {_, _}}, // 15
     {{_, _}, {61, 12}, {63, 12}}
    },

    {{{_, _}, {61, 11}, {63, 11}}, // 16
     {{59, 12}, {61, 12}, {_, _}}
    },

    {{{_, _}, {61, 11}}, // 17
     {{59, 12}, {61, 12}},
     {{59, 13}, {_, _}},
    },

    {{{59, 11}, {_, _}}, // 18
     {{59, 12}, {61, 12}},
     {{_, _}, {61, 13}},
    },
};
int current_index;
int current_color;
vector<int> current_center;
int dict[19];
int next_index = 0;
int next_color = 0;
pair<int, int> board[WIDTH + 1][HEIGHT];
int dx[] = {-2, 2, 0};
int dy[] = {0, 0, 1};
char c;
int minY = INT_MAX;
bool game_over = false;
bool quit_game = false;
string status[] = {"PLAYING...", "PAUSING...", "GAME OVER "};
int score = 0;
int high_score = 0;

void GamePlay();

void SoundEffect(string file_name) {
    PlaySound(TEXT(file_name.c_str()), NULL, SND_LOOP);
}

void ReadData() {
    ifstream input("high_score.txt");
    input >> high_score;
    input.close();
}

void WriteData() {
    ofstream output("high_score.txt");
    output << high_score << endl;
    output.close();
}

void DrawRectBorder(int x, int y, int width, int height, int color) {
    SetColor(color, 5);
    for (int i = 0; i < height; i++) {
        Gotoxy(x, y + i);
        cout << "░" << endl;
        Gotoxy(x + width, y + i);
        cout << "░" << endl;
    }
    for (int i = 0; i < width; i++) {
        Gotoxy(x + i, y);
        cout << "░";
        Gotoxy(x + i, y + height - 1);
        cout << "░";
    }
}

void DrawShape(vector<vector<vector<int>>> shape, int color) {
    SetColor(color, 0);
    for (int i = 0; i < shape.size(); i++) {
        for (int j = 0; j < shape[0].size(); j++) {
            int x = shape[i][j][0];
            int y = shape[i][j][1];
            if (x > 0 && y > 0) {
                Gotoxy(x, y);
                cout << dot;
            }
        }
    }
}

void DeleteShape(vector<vector<vector<int>>> shape) {
    SetColor(0, 0);
    for (int i = 0; i < shape.size(); i++) {
        for (int j = 0; j < shape[0].size(); j++) {
            int x = shape[i][j][0];
            int y = shape[i][j][1];
            if (x > 0 && y > 0) {
                Gotoxy(x, y);
                cout << dot;
            }
        }
    }
}

bool CanMoveX() {
    for (int i = 0; i < current_shape.size(); i++) {
        for (int j = 0; j < current_shape[0].size(); j++) {
            int x = current_shape[i][j][0];
            int y = current_shape[i][j][1];
            if (x == _ && y == _) continue;
            if (x == 1 && c == 'a') {
                return false;
            }
            if (x == WIDTH - 2 && c == 'd') {
                return false;
            }
            if (x == 1 && c == 'd') {
                return true;
            }
            if (x == WIDTH - 2 && c == 'a') {
                return true;
            }
            for (int k = 0; k < 2; k++) {
                int u = x + dx[k];
                int v = y + dy[k];
                if (u >= 0 && u <= WIDTH && v >= 0 && v < HEIGHT && board[u][v].first == 1) {
                    return false;
                }
            }
        }
    }
    return true;
}

bool CanMoveY() {
    for (int i = 0; i < current_shape.size(); i++) {
        for (int j = 0; j < current_shape[0].size(); j++) {
            int x = current_shape[i][j][0];
            int y = current_shape[i][j][1];
            if (x == _ && y == _) continue;
            int u = x + dx[2];
            int v = y + dy[2];
            if (u >= 0 && u <= WIDTH && v >= 0 && v < HEIGHT && board[u][v].first == 1) {
                return false;
            }
        }
    }
    return true;
}

void IncreaseX() {
    if (CanMoveX() == false) {
        return;
    }
    for (int i = 0; i < current_shape.size(); i++) {
        for (int j = 0; j < current_shape[0].size(); j++) {
            if (current_shape[i][j][0] != _ && current_shape[i][j][0] != _) {
                current_shape[i][j][0] += 2;
            }
        }
    }
    current_center[0] += 2;
}

void DecreaseX() {
    if (CanMoveX() == false) {
        return;
    }
    for (int i = 0; i < current_shape.size(); i++) {
        for (int j = 0; j < current_shape[0].size(); j++) {
            if (current_shape[i][j][0] != _ && current_shape[i][j][0] != _) {
                current_shape[i][j][0] -= 2;
            }
        }
    }
    current_center[0] -= 2;
}

void RotateCurrentShape() {
    if (current_index == 14) return;
    int x = current_center[0];
    int y = current_center[1];
    current_index = dict[current_index];
    current_shape = shapes[current_index];
    current_center = center[current_index];
    while (current_center[1] != y) {
        for (int i = 0; i < current_shape.size(); i++) {
            for (int j = 0; j < current_shape[0].size(); j++) {
                if (current_shape[i][j][0] != _ && current_shape[i][j][1] != _) {
                    current_shape[i][j][1]++;
                }
            }
        }
        current_center[1]++;
    }
    while (current_center[0] != x) {
        for (int i = 0; i < current_shape.size(); i++) {
            for (int j = 0; j < current_shape[0].size(); j++) {
                if (current_shape[i][j][0] != _ && current_shape[i][j][1] != _) {
                    if (current_center[0] < x) {
                        current_shape[i][j][0] += 2;
                    }
                    else if (current_center[0] > x) {
                        current_shape[i][j][0] -= 2;
                    }
                }
            }
        }
        if (current_center[0] < x) {
            current_center[0] += 2;
        }
        else if (current_center[0] > x) {
            current_center[0] -= 2;
        }
    }
    int minX = INT_MAX;
    int maxX = INT_MIN;
    int minY = INT_MAX;
    for (int i = 0; i < current_shape.size(); i++) {
        for (int j = 0; j < current_shape[0].size(); j++) {
            if (current_shape[i][j][0] != _ && current_shape[i][j][1] != _) {
                minX = min(minX, current_shape[i][j][0]);
                maxX = max(maxX, current_shape[i][j][0]);
                minY = min(minY, current_shape[i][j][1]);
            }
        }
    }
    while (minX <= 0) {
        current_center[0] += 2;
        minX += 2;
        for (int i = 0; i < current_shape.size(); i++) {
            for (int j = 0; j < current_shape[0].size(); j++) {
                if (current_shape[i][j][0] != _ && current_shape[i][j][1] != _) {
                    current_shape[i][j][0] += 2;
                }
            }
        }
    }
    while (maxX >= WIDTH) {
        current_center[0] -= 2;
        maxX -= 2;
        for (int i = 0; i < current_shape.size(); i++) {
            for (int j = 0; j < current_shape[0].size(); j++) {
                if (current_shape[i][j][0] != _ && current_shape[i][j][1] != _) {
                    current_shape[i][j][0] -= 2;
                }
            }
        }
    }
    while (minY <= 0) {
        current_center[1]++;
        minY++;
        for (int i = 0; i < current_shape.size(); i++) {
            for (int j = 0; j < current_shape[0].size(); j++) {
                if (current_shape[i][j][0] != _ && current_shape[i][j][1] != _) {
                    current_shape[i][j][1]++;
                }
            }
        }
    }
}

void Insertboard() {
    for (int i = 0; i < current_shape.size(); i++) {
        for (int j = 0; j < current_shape[0].size(); j++) {
            int x = current_shape[i][j][0];
            int y = current_shape[i][j][1];
            if (x != _ && y != _) {
                board[x][y].first = 1;
                board[x][y].second = current_color;
                minY = min(minY, y);
            }
        }
    }
    if (minY == 1) {
        game_over = true;
    }
}

void DeleteLine(int line) {
    SetColor(0, 0);
    for (int i = 1; i <= WIDTH - 2; i += 2) {
        board[i][line].first = 0;
        board[i][line].second = 0;
        Gotoxy(i, line);
        cout << dot;
    }
}

void RePaint(int line) {
    for (int j = line - 1; j >= 1; j--) {
        for (int i = 1; i <= WIDTH - 2; i += 2) {
            if (board[i][j].first == 1) {
                board[i][j + 1].first = 1;
                board[i][j + 1].second = board[i][j].second;
                
                board[i][j].first = 0;
                board[i][j].second = 0;
                
                SetColor(board[i][j].second, 0);
                Gotoxy(i, j);
                cout << dot;
                
                SetColor(board[i][j + 1].second, 0);
                Gotoxy(i, j + 1);
                cout << dot;
            }
        }
    }
}

void CheckAllLine() {
    vector<int> lines;
    for (int j = HEIGHT - 2; j >= 1; j--) {
        bool ok = true;
        for (int i = 1; i <= WIDTH - 2; i += 2) {
            if (board[i][j].first == 0) {
                ok = false;
                break;
            }
        }
        if (ok == true) lines.push_back(j);
    }
    if (lines.size() > 0) {
        score += lines.size() * 10;
        high_score = max(high_score, score);
        SetColor(0, 4);
        Gotoxy(WIDTH + 14, 24);
        cout << "HIGH SCORE: " << high_score;
        Gotoxy(WIDTH + 14, 25);
        cout << "SCORE:      " << score;
        for (int line : lines) {
            DeleteLine(line);
        }
        if (lines.size() == 1) {
            thread sound_effect(SoundEffect, "sound_effect.wav");
            sound_effect.detach();
        }
        else {
            thread sound_effect(SoundEffect, "super_sound_effect.wav");
            sound_effect.detach();
        }
        Sleep(1000);
        for (int line : lines) {
            RePaint(line);
        }
    }
}

void DropCurrentShape() {
    DeleteShape(current_shape);
    while (CanMoveY() == true) {
        for (int i = 0; i < current_shape.size(); i++) {
            for (int j = 0; j < current_shape[0].size(); j++) {
                if (current_shape[i][j][0] != _ && current_shape[i][j][1] != _) {
                    current_shape[i][j][1]++;
                }
            }
        }
    }
    Insertboard();
    DrawShape(current_shape, current_color);
    CheckAllLine();
}

void MoveCurrentShape() {
    vector<vector<vector<int>>> old_shape;
    while (true) {
        old_shape = current_shape;
        if (kbhit()) {
            c = getch();
            if (c == 'a') {
                DecreaseX();
            }
            else if (c == 'd') {
                IncreaseX();
            }
            else if (c == 'p') {
                SetColor(0, 11);
                Gotoxy(WIDTH + 14, 22);
                cout << "STATUS: " << status[1];
                while((c = getch()) != 'c');
            }
            else if (c == 32) {
                RotateCurrentShape();
            }
            else if (c == 's') {
                DropCurrentShape();
                return;
            }
            else if (c == 'q') {
                quit_game = true;
                WriteData();
                return;
            }
            else if (c == 'r') {
                WriteData();
                SetColor(0, 7);
                ClearScreen();
                GamePlay();
                return;
            }
        }
        if (CanMoveY() == false) {
            Insertboard();
            CheckAllLine();
            return;
        }
        DeleteShape(old_shape);
        SetColor(current_color, 0);
        for (int i = 0; i < current_shape.size(); i++) {
            for (int j = 0; j < current_shape[0].size(); j++) {
                int x = current_shape[i][j][0];
                int y = current_shape[i][j][1];
                if (x != _ && y != _) {
                    y = ++current_shape[i][j][1];
                    Gotoxy(x, y);
                    cout << dot;
                }
            }
        }
        current_center[1]++;
        if (game_over == true) {
            return;
        }
        Sleep(200);
    }
}

void DrawLoGoGame() {
    int logo_color = 1 + rand() % 15;
    SetColor(0, logo_color);
    Gotoxy(WIDTH + 5, 1);
    cout << " _____ _____ _____ ____  _  ____";
    Gotoxy(WIDTH + 5, 2);
    cout << "/__ __Y  __//__ __Y  __\\/ \\/ ___\\";
    Gotoxy(WIDTH + 5, 3);
    cout << "  / \\ |  \\    / \\ |  \\/|| ||    \\";
    Gotoxy(WIDTH + 5, 4);
    cout << "  | | |  /_   | | |    /| |\\___ |";
    Gotoxy(WIDTH + 5, 5);
    cout << "  \\_/ \\____\\  \\_/ \\_/\\_\\\\_/\\____/";
}

void GamePlay() {
    quit_game = false;
    SetConsoleOutputCP(65001);
    ShowCur(false);
    DisableSelection();
    DisableResizeWindow();
    DisableCtrButton(true, true, false);
    SetConsoleTitle("Tetris");
    SetFontSize(20);
    ShowScrollbar(false);
    ResizeConsole(825, 645);
    DrawRectBorder(0, 0, WIDTH, HEIGHT, 15);
    DrawRectBorder(WIDTH + 13, 8, 16, 8, 15);
    Gotoxy(0, 0);

    dict[0] = 2;
    dict[1] = 3;
    dict[2] = 1;
    dict[3] = 0;
    dict[4] = 8;
    dict[5] = 9;
    dict[6] = 5;
    dict[7] = 4;
    dict[8] = 10;
    dict[9] = 11;
    dict[10] = 7;
    dict[11] = 6;
    dict[12] = 13;
    dict[13] = 12;
    dict[14] = 14;
    dict[15] = 17;
    dict[16] = 18;
    dict[17] = 15;
    dict[18] = 16;

    for (int i = 1; i <= WIDTH - 2; i += 2) {
        for (int j = 1; j <= HEIGHT - 2; j++) {
            board[i][j].first = 0;
            board[i][j].second = 0;
        }
    }
    for (int i = 0; i < HEIGHT; i++) {
        board[0][0 + i].first = 1;
        board[0][0 + i].second = 15;
        board[0 + WIDTH][0 + i].first = 1;
        board[0 + WIDTH][0 + i].second = 15;
    }
    for (int i = 0; i < WIDTH; i++) {
        board[0 + i][0].first = 1;
        board[0 + i][0].second = 15;
        board[0 + i][0 + HEIGHT - 1].first = 1;
        board[0 + i][0 + HEIGHT - 1].second = 15;
    }

    score = 0;
    SetColor(14, 13);
    Gotoxy(WIDTH + 15, 7);
    cout << " NEXT  SHAPE ";
    SetColor(0, 6);
    Gotoxy(WIDTH + 16, 17);
    cout << "INSTRUCTION";
    Gotoxy(WIDTH + 5, 18);
    cout << "LEFT:   A";
    Gotoxy(WIDTH + 5, 19);
    cout << "RIGHT:  D";
    Gotoxy(WIDTH + 5, 20);
    cout << "DROP:   S";
    Gotoxy(WIDTH + 5, 21);
    cout << "PAUSE:  P";
    Gotoxy(WIDTH + 25, 18);
    cout << "ROTATE:   SPACE";
    Gotoxy(WIDTH + 25, 19);
    cout << "RE PLAY:  R";
    Gotoxy(WIDTH + 25, 20);
    cout << "QUIT:     Q";
    Gotoxy(WIDTH + 25, 21);
    cout << "CONTINUE: C";
    SetColor(0, 11);
    Gotoxy(WIDTH + 14, 22);
    cout << "STATUS: " << status[0];
    SetColor(0, 4);
    Gotoxy(WIDTH + 14, 24);
    cout << "HIGH SCORE: " << high_score;
    Gotoxy(WIDTH + 14, 25);
    cout << "SCORE:      " << score;
    SetColor(0, 12);
    Gotoxy(WIDTH + 10, 28);
    cout << "AUTHOR: NGUYỄN NGỌC NAM";

    srand(time(NULL));
    current_index = rand() % shapes.size();
    do {
        current_color = rand() % 16;
    }
    while (current_color == 0 || current_color == 7 || current_color == 15);
    while (game_over == false) {
        if (kbhit()) {
            c = getch();
            if (c == 'q') {
                WriteData();
                return;
            }
            else if (c == 'r') {
                WriteData();
                GamePlay(); 
            }
        }
        current_shape = shapes[current_index];
        current_center = center[current_index];
        DrawShape(current_shape, current_color);
        DrawLoGoGame();
        next_index = rand() % shapes.size();
        do {
            next_color = rand() % 16;
        }
        while (next_color == 0 || next_color == 7 || next_color == 15);
        DrawShape(next_shapes[next_index], next_color);
        Sleep(300);
        MoveCurrentShape();
        if (quit_game == true) {
            return;
        }
        DeleteShape(next_shapes[next_index]);
        current_index = next_index;
        current_color = next_color;
    }
    SetColor(0, 11);
    Gotoxy(WIDTH + 14, 22);
    cout << "STATUS: " << status[2];
    WriteData();
    thread sound_effect(SoundEffect, "game_over.wav");
    sound_effect.detach();
    while (true) {
        c = getch();
        if (c == 'q') {
            return;
        }
        else if (c == 'r') {
            SetColor(0, 7);
            ClearScreen();
            GamePlay();
            return;
        }
    }
}

int main() {
    ReadData();
    GamePlay();

    return 0;
}