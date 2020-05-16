#include "Hesap.h"
#include <iostream>
#include "ctime"
#include "Islem.h"

using namespace std;

string Hesap::ParaGirisi(int tutar) {
	this->HesapTutari += tutar;
	time_t now = time(0);
	Islem islem(now, "Para Yatýrma", tutar);
	Islemler.push_back(islem);
	return "yatirildi";
}
bool Hesap::ParaCikisi(int tutar) {
	if (this->HesapTutari < tutar)
		return false;

	this->HesapTutari -= tutar;
	time_t now = time(0);
	Islem islem(now, "Para Cekme", tutar);
	Islemler.push_back(islem);

	return true;
}
string Hesap::HesapBilgileriGetir() {
	string temp = "Musteri no: " + to_string(this->MusteriNumarasi) +
		"\nHesap numarasi: " + to_string(this->HesapNumarasi) +
		"\nHesap tutari: " + to_string(this->HesapTutari);
	return temp;
}

Hesap::Hesap(int musteriNumarasi, int hesapNumarasi, string sifre) {
	this->HesapTutari = 0;
	this->MusteriNumarasi = musteriNumarasi;
	this->HesapNumarasi = hesapNumarasi;
	this->Sifre = sifre;
	this->TakmaHesapAdi = "Default";
}
Hesap::Hesap(int musteriNumarasi, int hesapNumarasi, string sifre, string takmaHesapAdi) {
	this->HesapTutari = 0;
	this->MusteriNumarasi = musteriNumarasi;
	this->HesapNumarasi = hesapNumarasi;
	this->Sifre = sifre;
	this->TakmaHesapAdi = takmaHesapAdi;
}