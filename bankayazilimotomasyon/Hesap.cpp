#include "Hesap.h"

string Hesap::ParaGirisi(int tutar) {
	this->HesapTutari += tutar;
}
string Hesap::ParaCikisi(int tutar) {
	this->HesapTutari -= tutar;
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