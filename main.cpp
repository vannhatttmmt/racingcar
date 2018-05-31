#include <iostream>
#include <string>
#include <Windows.h>
#include <ctime>
#include "function.h"
#include "function.cpp"

using namespace std;

int main(){
   
	int x = 20, y = 15; // Toa do xe player
	int x1 = 2, y1; // Toa do chuong ngai vat dong(dynamic)
	int x2 = 5, y2 = 10; // Toa do chuong ngai vat tinh(static)
	int a = 0;
	while(true){

			a++;
		if(a % 2 != 0){
			VeDuongDua_1();
		}
		else{
			VeDuongDua_2();
		}

		srand(time(0)); // Reset time
		y1 = 2 + rand() % 26; // [2, 27]

		VeXePlayer(x, y);
		VeXeChuongNgaiVat(x1, y1); // Xe dong
		VeXeChuongNgaiVat(x2, y2); // Xe tinh

		XoaManHinh();

		InDuongDua();

		DiChuyenXe(x, y);

		if(a >= 30)
		{
			a = 0;
		}


		// Dang so sanh xem co bi trung voi xe tinh va xe dong hay khong
		if(map[x][y] == '!' || map[x][y - 1] == '!' || map[x][y + 1] == '!' || map[x - 1][y - 1] == '!' || map[x + 1][y - 1] == '!' || map[x - 1][y + 1] == '!' || map[x + 1][y + 1] == '!'){
			Beep(523,500);
			return 0; // Ket thuc
		}

		XoaXeChuongNgai(x1, y1);
		x1++; // Tang dong len, tao ra cam giac xe dang di chuyen
		if(x1 == 31){
			x1 = 2;
		}

		XoaXeChuongNgai(x2, y2);
		x2++;
		if(x2 == 31){
			x2 = 5;
			y2 = 2 + rand() % 26; // [2, 27]
		}

	}

	system("pause");
	return 0;
}
