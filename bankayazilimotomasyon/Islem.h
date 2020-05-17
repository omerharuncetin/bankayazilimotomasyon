#pragma once
#include <ctime>
#include <string>
using namespace std;
class Islem
{
public:
	struct tm Tarih;
	time_t milliseconds;
	string IslemTipi;
	int Tutar;
	Islem(time_t milliseconds, string islemTipi, int tutar);
	string TarihDondur();
	string IslemBilgileriniDondur();
};
