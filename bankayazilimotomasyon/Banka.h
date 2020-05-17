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
	vector <BireyselMusteri> BireyselMusteriler;
	vector <TicariMusteri> TicariMusteriler;
	int sonMusteriNumarasi = 1000;
	int sonHesapNumarasi = 4440;
	vector <int> MusteriHesaplariniBul(int musteriNo, int hesapNo);
	int HesapIndexiBul(int hesapNumarasi);
	Hesap HesapBul(int hesapNo);

public:
	bool HesapEkle(Hesap hesap);
	bool HesapSil(int HesapNumarasi);
	BireyselMusteri BireyselMusteriGiris(string tcno, int sifre);
	TicariMusteri TicariMusteriGiris(string tcno, int sifre);
	string HesaptanParaCek(int musteriNo, int hesapNo, int tutar);
	string HesabaParaYatir(int hesapNo, int tutar);
	int YeniMusteriNumarasi() { return this->sonMusteriNumarasi++; };
	int YeniHesapNumarasi() { return this->sonHesapNumarasi++; };
	bool BireyselMusteriEkle(BireyselMusteri musteri);
	bool TicariMusteriEkle(TicariMusteri musteri);
	vector< Hesap > MusteriHesaplariniGetir(int musteriNo);
	string HesapIslemleriniGetir(int hesapNo, time_t tarih1, time_t tarih2);
	Banka();
};
