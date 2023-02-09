#include "DoHoa.h"

// Hàm thay đổi kích cỡ của khung cmd với tham số truyền vào là chiều cao, chiều rộng.
void ResizeConsole(int width, int height)
{
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, width, height, TRUE);
}

// Hàm tô màu.
void TextColor(int x)
{
    HANDLE mau;
    mau = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(mau, x);
}

// Hàm dịch chuyển con trỏ đến tọa độ x, y.
void Gotoxy(int posX, int posY)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD Position;
    Position.X = posX;
    Position.Y = posY;

    SetConsoleCursorPosition(hStdout, Position);
}

// Hàm xóa màn hình.
void ClearScreen()
{
    // HANDLE hOut;
    // COORD Position;
    // hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    // Position.X = 0;
    // Position.Y = 0;
    // SetConsoleCursorPosition(hOut, Position);

    HANDLE hStdOut;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD count;
    DWORD cellCount;
    COORD homeCoords = {0, 0};

    hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hStdOut == INVALID_HANDLE_VALUE)
        return;

    // Get the number of cells in the current buffer
    if (!GetConsoleScreenBufferInfo(hStdOut, &csbi))
        return;
    cellCount = csbi.dwSize.X * csbi.dwSize.Y;

    // Fill the entire buffer with spaces
    if (!FillConsoleOutputCharacter(
            hStdOut,
            (TCHAR)' ',
            cellCount,
            homeCoords,
            &count))
        return;

    // Fill the entire buffer with the current colors and attributes
    if (!FillConsoleOutputAttribute(
            hStdOut,
            csbi.wAttributes,
            cellCount,
            homeCoords,
            &count))
        return;

    // Move the cursor home
    SetConsoleCursorPosition(hStdOut, homeCoords);
}

// Hàm lấy Key từ bàn phím
/* GetAsyncKeyState(VK_ESCAPE) => bắt sự kiện phím Esc */

// Hàm tự viết
// x, y là tọa độ con trỏ cần nhảy đến để viết, a là chuỗi cần truyền vào, color là màu truyền vào.
void ToMau(int x, int y, char *a, int color)
{
    Gotoxy(x, y);
    TextColor(color);
    cout << a;
    TextColor(7);
}

// vô hiệu hóa các nút thu nhỏ, phóng to, đóng cửa sổ
void DisableCtrButton(bool Min, bool Max, bool Close)
{
    HWND hWnd = GetConsoleWindow();
    HMENU hMenu = GetSystemMenu(hWnd, false);

    if (Min == 1)
    {
        DeleteMenu(hMenu, SC_MINIMIZE, MF_BYCOMMAND);
    }
    if (Max == 1)
    {
        DeleteMenu(hMenu, SC_MAXIMIZE, MF_BYCOMMAND);
    }
    if (Close == 1)
    {
        DeleteMenu(hMenu, SC_CLOSE, MF_BYCOMMAND);
    }
}

// vô hiệu hóa thay đổi kích thước màn hình
void DisableResizeWindow()
{
    HWND hWnd = GetConsoleWindow();
    SetWindowLong(hWnd, GWL_STYLE, GetWindowLong(hWnd, GWL_STYLE) & ~WS_SIZEBOX);
}

// thay đổi kích thước của screen buffer
void SetScreenBufferSize(int width, int height)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD NewSize;
    NewSize.X = width;
    NewSize.Y = height;

    SetConsoleScreenBufferSize(hStdout, NewSize);
}

// thay đổi window size
void SetWindowSize(int width, int height)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    SMALL_RECT WindowSize;
    WindowSize.Top = 0;
    WindowSize.Left = 0;
    WindowSize.Right = width;
    WindowSize.Bottom = height;

    SetConsoleWindowInfo(hStdout, 1, &WindowSize);
}

// thay đổi màu chữ và nền của chữ
void SetColor(int backgound_color, int text_color)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    int color_code = backgound_color * 16 + text_color;
    SetConsoleTextAttribute(hStdout, color_code);
}

// ẩn hiện con trỏ chuột
// true là hiện, false là ẩn
void ShowCur(bool CursorVisibility)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO ConCurInf;

    ConCurInf.dwSize = 10;
    ConCurInf.bVisible = CursorVisibility;

    SetConsoleCursorInfo(handle, &ConCurInf);
}

// vô hiệu hóa select text
void DisableSelection()
{
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);

    SetConsoleMode(hStdin, ~ENABLE_QUICK_EDIT_MODE);
}

// ẩn hiện thanh cuộn
void ShowScrollbar(bool Show)
{
    HWND hWnd = GetConsoleWindow();
    ShowScrollBar(hWnd, SB_BOTH, Show);
}

void SetFontSize(int font_size)
{
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 0;         // Width of each character in the font
    cfi.dwFontSize.Y = font_size; // Height
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    wcscpy(cfi.FaceName, L"Consolas"); // Choose your font
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}

// hiển thị tiếng việt: SetConsoleOutputCP(65001)
// Thay đổi console title: SetConsoleTitle(char *name)