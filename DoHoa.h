#pragma once
#include <bits/stdc++.h>
#include <conio.h>
#include <Windows.h>
#include <mmsystem.h>
using namespace std;

// Hàm thay đổi kích cỡ của khung cmd với tham số truyền vào là chiều cao, chiều rộng.
void ResizeConsole(int width, int height);

// Hàm tô màu.
void TextColor(int x);

// Hàm dịch chuyển con trỏ đến tọa độ x, y.
void Gotoxy(int posX, int posY);

// Hàm xóa màn hình.
void ClearScreen();

// Hàm lấy Key từ bàn phím
/* GetAsyncKeyState(VK_ESCAPE) => bắt sự kiện phím Esc */

// Hàm tự viết
// x, y là tọa độ con trỏ cần nhảy đến để viết, a là chuỗi cần truyền vào, color là màu truyền vào.
void ToMau(int x, int y, char *a, int color);

// vô hiệu hóa các nút thu nhỏ, phóng to, đóng cửa sổ
void DisableCtrButton(bool Min, bool Max, bool Close);

// vô hiệu hóa thay đổi kích thước màn hình
void DisableResizeWindow();

// thay đổi kích thước của screen buffer
void SetScreenBufferSize(int width, int height);

// thay đổi window size
void SetWindowSize(int width, int height);

// thay đổi màu chữ và nền của chữ
void SetColor(int backgound_color, int text_color);

// ẩn hiện con trỏ chuột
// true là hiện, false là ẩn
void ShowCur(bool CursorVisibility = true);

// vô hiệu hóa select text
void DisableSelection();

// ẩn hiện thanh cuộn
void ShowScrollbar(bool Show = true);

// Ham thay doi co chu
void SetFontSize(int font_size);

// hiển thị tiếng việt: SetConsoleOutputCP(65001)
// Thay đổi console title: SetConsoleTitle(char *name)
// Thay đổi console title: SetConsoleTitle(char *name)