#include "Hesap.h"
#include <iostream>
#include "ctime"
#include "Islem.h"

using namespace std;

string Hesap::ParaGirisi(int tutar) {
	this->HesapTutari += tutar;
	Islem islem;
	islem.IslemTipi = "Para Yatýrma";
	islem.Tutar = tutar;
	struct tm newTime;
	islem.Tarih = newTime;
	Islemler.push_back(islem);
}
bool Hesap::ParaCikisi(int tutar) {
	if (this->HesapTutari < tutar)
		return false;
	
	this->HesapTutari -= tutar;
	Islem islem;
	islem.IslemTipi = "Para Cekme";
	islem.Tutar = tutar;
	struct tm newTime;
	islem.Tarih = newTime;
	Islemler.push_back(islem);
	
	return true;
}
string Hesap::HesapBilgileriGetir() {
	string temp = "Musteri no: " + to_string(this->MusteriNumarasi)+
		"\nHesap numarasi: " + to_string(this->HesapNumarasi) +
		"\nHesap tutari: " + to_string(this->HesapTutari);
	return temp;
}

Hesap::Hesap(int musteriNumarasi, int hesapNumarasi, string sifre) {
	this->HesapTutari = 0;
	this->MusteriNumarasi = musteriNumarasi;
	this->Sifre = sifre;
	this->HesapNumarasi = hesapNumarasi;
	this->TakmaHesapAdi = "Default";
}
Hesap::Hesap(int musteriNumarasi, int hesapNumarasi, string sifre, string takmaHesapAdi) {
	this->HesapTutari = 0;
	this->MusteriNumarasi = musteriNumarasi;
	this->Sifre = sifre;
	this->HesapNumarasi = hesapNumarasi;
	this->TakmaHesapAdi = takmaHesapAdi;
}