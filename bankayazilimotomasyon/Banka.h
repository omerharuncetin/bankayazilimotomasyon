#pragma once
#include <string>
#include <vector>
using namespace std;
#include "Hesap.h"
#include "BireyselMusteri.h"
#include "TicariMusteri.h"
class Banka
{
private:
	vector< Hesap > Hesaplar;
	vector <BireyselMusteri> BireyselMusteriler[];
	vector <TicariMusteri> TicariMusteriler[];
	int sonMusteriNumarasi = 0;
public:
	bool HesapEkle(Hesap hesap);
	bool HesapSil(int HesapNumarasi);
	int YeniMusteriNumarasi();
	bool BireyselMusteriEkle(BireyselMusteri musteri);
	bool TicariMusteriEkle(TicariMusteri musteri);
	Banka();
};

