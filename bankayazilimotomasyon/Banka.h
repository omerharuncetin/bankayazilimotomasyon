#pragma once
#include <string>
using namespace std;
#include "Hesap.h"
class Banka
{
private:
	Hesap hesaplar[100];
public:
	string operator<<(int hesapNumarasi);
	void HesapEkle(Hesap hesap);
};

