#include "Hesap.h"
#include <iostream>
#include "ctime"
#include "Islem.h"

using namespace std;

string Hesap::ParaGirisi(int tutar, Islem islem) {
	this->HesapTutari += tutar;
	islem.IslemTipi = "Para Yatırma";
	islem.Tutar = tutar;
	struct tm newTime;
	islem.Tarih = newTime;

	Islemler.push_back(islem);
}
string Hesap::ParaCikisi(int tutar, Islem islem) {
	this->HesapTutari -= tutar;
	islem.IslemTipi = "Para Cekme";
	islem.Tutar = tutar;
	struct tm newTime;
	islem.Tarih = newTime;
	
	Islemler.push_back(islem);
}
string Hesap::HesapBilgileriGetir() {
	string temp = "Musteri tc: " + this->TcNumarasi +
		"\nHesap numarasi: " + this->HesapNumarasi +
		"\nHesap tutari: " + to_string(this->HesapTutari);
	return temp;
}

Hesap::Hesap(string tcNumarasi, string hesapNumarasi, string sifre) {
	this->HesapTutari = 0;
	this->TcNumarasi = tcNumarasi;
	this->Sifre = sifre;
	this->HesapNumarasi = hesapNumarasi;
}