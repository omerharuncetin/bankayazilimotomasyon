#pragma once
#include <string>
using namespace std;
#include "Hesap.h"
class Banka
{
private:
	Hesap Hesaplar[200];
	int sonMusteriNumarasi = 0;
	int sonHesapYeri = 0;
public:
	bool HesapEkle(Hesap hesap);
	bool HesapSil(int HesapNumarasi);
	int YeniMusteriNumarasi();
	Banka();
};

