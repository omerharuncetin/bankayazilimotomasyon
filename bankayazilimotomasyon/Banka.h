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
	int sonMusteriNumarasi = 0;
	vector< Hesap > MusteriHesaplariniBul(int musteriNo);
	Hesap HesapBul(int hesapNo);
public:
	bool HesapEkle(Hesap hesap);
	bool HesapSil(int HesapNumarasi);
	bool HesaptanParaCek(int musteriNo, int hesapNo, int tutar);
	bool HesabaParaYatir(int hesapNo, int tutar);
	int YeniMusteriNumarasi();
	bool BireyselMusteriEkle(BireyselMusteri musteri);
	bool TicariMusteriEkle(TicariMusteri musteri);
	Banka();
};

