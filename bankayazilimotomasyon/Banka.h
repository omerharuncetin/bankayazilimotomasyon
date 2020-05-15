#pragma once
#include <string>
#include <vector>
#include "Hesap.h"
#include "BireyselMusteri.h"
#include "TicariMusteri.h"
using namespace std;
class Banka
{
private:
	vector< Hesap > Hesaplar;
	vector <int> Deneme;
	vector <BireyselMusteri> BireyselMusteriler;
	vector <TicariMusteri> TicariMusteriler;
	int sonMusteriNumarasi = 1000;
	int sonHesapNumarasi = 4440;
	vector< Hesap > MusteriHesaplariniBul(int musteriNo, int hesapNo);
	Hesap HesapBul(int hesapNo);
public:
	bool HesapEkle(Hesap hesap);
	bool HesapSil(int HesapNumarasi);
	string HesaptanParaCek(int musteriNo, int hesapNo, int tutar);
	bool HesabaParaYatir(int hesapNo, int tutar);
	int YeniMusteriNumarasi() { return this->sonMusteriNumarasi++; };
	int YeniHesapNumarasi() { return this->sonHesapNumarasi++; };
	bool BireyselMusteriEkle(BireyselMusteri musteri);
	bool TicariMusteriEkle(TicariMusteri musteri);
	Banka();
};
