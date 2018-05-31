#include"function.h"
#include <string>
#include <Windows.h>
#include <ctime>
#include <iostream>
using namespace std;
char map[50][50];
void textcolor(int x){
	HANDLE mau;
	mau=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}

// Ham dich chuyen con tro den toa do (x,y)
void gotoxy(int x,int y){
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = {x-1,y-1};
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput ,Cursor_an_Pos);
}

// Ham xoa man hinh
void XoaManHinh(){
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}

//Ben trai duong dua
void VeDuongDua_1(){
	// Dai 30, rong 30
	for(int i = 0; i < 30; i++){
		if(i % 2 == 0){
			map[i][14] = ' ';
		}

		for(int j = 1; j < 29 && j != 14; j++){
			map[i][j] = ' ';
		}
	}
}

//Ben phai duong dua
void VeDuongDua_2(){
	// Dai 30, rong 30
	for(int i = 0; i < 30; i++){
		if(i % 2 != 0){
			map[i][14] = '|';
		}

		for(int j = 1; j < 29 && j != 14; j++){
			map[i][j] = ' ';
		}
	}
}

void InDuongDua(){
	// Dai 30, rong 30
	for(int i = 0; i < 30; i++){
		cout << "\t\t\t\t\t";
		for(int j = 0; j < 30; j++){
			//In duong dua
			if(j == 0 || j == 29){
				textcolor(191);
				map[i][j] = ' ';
				cout << map[i][j];
				textcolor(7);
			}

			//In xe player
			else if(map[i][j] == 'X' || map[i][j] == '@' || map[i][j] == '#'){
				textcolor(14); // Mau vang
				cout << map[i][j];
				textcolor(7); // Tro lai mau binh thuong
			}

			//In xe computer
			else if(map[i][j] == '!'){
				textcolor(200);
				cout << map[i][j];
				textcolor(7);
			}

			// Nhung ki tu khong phai xe
			else{
				cout << map[i][j];
			}
		}
		cout << endl;
	}
}

void VeXePlayer(int x, int y){
	map[x][y] = 'X'; // Than xe
	map[x][y - 1] = '#'; // Ben trai than xe
	map[x][y + 1] = '#'; // Ben phai than xe
	map[x - 1][y - 1] = '@'; // Banh tren ben trai
	map[x + 1][y - 1] = '@'; // Banh duoi ben trai
	map[x - 1][y + 1] = '@'; // Banh tren ben phai
	map[x + 1][y + 1] = '@'; // Banh duoi ben phai
}

void VeXeChuongNgaiVat(int x, int y){
	map[x][y] = '!'; // Than xe
	map[x][y - 1] = '!'; // Ben trai than xe
	map[x][y + 1] = '!'; // Ben phai than xe
	map[x+1][y] = '!';
	map[x-1][y] = '!';
	map[x - 1][y - 1] = '!'; // Banh tren ben trai
	map[x + 1][y - 1] = '!'; // Banh duoi ben trai
	map[x - 1][y + 1] = '!'; // Banh tren ben phai
	map[x + 1][y + 1] = '!'; // Banh duoi ben phai
	}

void XoaXeChuongNgai(int x, int y){
	map[x][y] = ' '; // Than xe.
	map[x][y - 1] = ' '; // Ben trai than xe
	map[x][y + 1] = ' '; // Ben phai than xe
	map[x+1][y] = ' ';
	map[x-1][y] = ' ';
	map[x - 1][y - 1] = ' '; // Banh tren ben trai
	map[x + 1][y - 1] = ' '; // Banh duoi ben trai
	map[x - 1][y + 1] = ' '; // Banh tren ben phai
	map[x + 1][y + 1] = ' '; // Banh duoi ben phai
}

// x, y la toa do hien tai cua xe
void DiChuyenXe(int &x, int &y){
	/*

		Trai tren cung: 1, 2
		Trai duoi cung: 28, 2
		Phai tren cung: 1, 27
		Phai duoi cung: 28, 27
		*/

	// Qua trai khi click LeftArrow
	if(GetAsyncKeyState(VK_LEFT)){
		if(y > 2){
			// Dang so sanh xem co bi trung voi xe tinh va xe dong hay khong
			if(map[x][y] == '!' || map[x][y - 1] == '!' || map[x][y + 1] == '!' || map[x - 1][y - 1] == '!' || map[x + 1][y - 1] == '!' || map[x - 1][y + 1] == '!' || map[x + 1][y + 1] == '!'){
				printf("\a");
				exit(0); // Ket thuc
			}

			// Xoa xe di
			map[x][y] = ' '; // Than xe
			map[x][y - 1] = ' '; // Ben trai than xe
			map[x][y + 1] = ' '; // Ben phai than xe
			map[x - 1][y - 1] = ' '; // Banh tren ben trai
			map[x + 1][y - 1] = ' '; // Banh duoi ben trai
			map[x - 1][y + 1] = ' '; // Banh tren ben phai
			map[x + 1][y + 1] = ' '; // Banh duoi ben phai

			y--; // Giam cot xuong
			VeXePlayer(x, y); // Ve lai xe
		}

	}

	// Qua phai khi click RightArrow
	else if(GetAsyncKeyState(VK_RIGHT)){
		if(y <= 26){
			// Dang so sanh xem co bi trung voi xe tinh va xe dong hay khong
			if(map[x][y] == '!' || map[x][y - 1] == '!' || map[x][y + 1] == '!' || map[x - 1][y - 1] == '!' || map[x + 1][y - 1] == '!' || map[x - 1][y + 1] == '!' || map[x + 1][y + 1] == '!'){
				printf("\a");
				exit(0); // Ket thuc
			}

			// Xoa xe di
			map[x][y] = ' '; // Than xe
			map[x][y - 1] = ' '; // Ben trai than xe
			map[x][y + 1] = ' '; // Ben phai than xe
			map[x - 1][y - 1] = ' '; // Banh xe tren ben trai
			map[x + 1][y - 1] = ' '; // Banh xe duoi ben trai
			map[x - 1][y + 1] = ' '; // Banh xe tren ben phai
			map[x + 1][y + 1] = ' '; // Banh xe duoi ben phai

			y++; // Tang cot len
			VeXePlayer(x, y); // Ve lai xe


		}
	}

	// Di len
	else if(GetAsyncKeyState(VK_UP)){
		if(x > 1){
			// Dang so sanh xem co bi trung voi xe tinh va xe dong hay khong
			if(map[x][y] == '!' || map[x][y - 1] == '!' || map[x][y + 1] == '!' || map[x - 1][y - 1] == '!' || map[x + 1][y - 1] == '!' || map[x - 1][y + 1] == '!' || map[x + 1][y + 1] == '!'){
				printf("\a");
				exit(0); // Ket thuc
			}

			// Xoa xe di
			map[x][y] = ' '; // Than xe
			map[x][y - 1] = ' '; // Ben trai than xe
			map[x][y + 1] = ' '; // Ben phai than xe
			map[x - 1][y - 1] = ' '; // Banh tren ben trai
			map[x + 1][y - 1] = ' '; // Banh duoi ben trai
			map[x - 1][y + 1] = ' '; // Banh tren ben phai
			map[x + 1][y + 1] = ' '; // Banh duoi ben phai

			x--; // Giam so dong
			VeXePlayer(x, y); // Ve lai xe
		}
	}

	// Di xuong
	else if(GetAsyncKeyState(VK_DOWN)){
		if(x <= 27){
			// Dang so sanh xem co bi trung voi xe tinh va xe dong hay khong
			if(map[x][y] == '!' || map[x][y - 1] == '!' || map[x][y + 1] == '!' || map[x - 1][y - 1] == '!' || map[x + 1][y - 1] == '!' || map[x - 1][y + 1] == '!' || map[x + 1][y + 1] == '!'){
				printf("\a");
				exit(0); // Ket thuc
			}

			// Xoa xe di
			map[x][y] = ' ';
			map[x][y - 1] = ' ';
			map[x][y + 1] = ' ';
			map[x - 1][y - 1] = ' ';
			map[x + 1][y - 1] = ' ';
			map[x - 1][y + 1] = ' ';
			map[x + 1][y + 1] = ' ';

			x++; // Tang so dong
			VeXePlayer(x, y); // Ve lai xe
		}
	}
}

