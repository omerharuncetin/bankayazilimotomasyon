#include "TicariMusteri.h"


TicariMusteri::TicariMusteri(string sirketVergiNumarasi, string sirketFaksNumarasi, BireyselMusteri musteriBilgileri) {
	this->MusteriBilgileri = musteriBilgileri;
	this->SirketFaksNumarasi = sirketFaksNumarasi;
	this->SirketVergiNumarasi = sirketVergiNumarasi;
}

string TicariMusteri::SirketBilgileriniGetir() {
	string temp = "Sirket vergi numarasi : " + this->SirketVergiNumarasi + ", " +
				  "Sirket faks numarasi : " + this->SirketFaksNumarasi;
	return temp;
}
// Kisi bilgilerini getirmek icin ekstra fonksiyona gerek yok. Nesne üzerinden cagiririz.
string TicariMusteri::ParaCek(int tutar) {
	//to do;
}
string TicariMusteri::ParaYatir(int tutar) {
	//to do;
}
void TicariMusteri::BilgiGuncelle(string sirketVergiNumarasi, string sirketFaksNumarasi, BireyselMusteri musteriBilgileri) {
	this->SirketFaksNumarasi = sirketFaksNumarasi;
	this->SirketVergiNumarasi = sirketVergiNumarasi;
	this->MusteriBilgileri = musteriBilgileri;
}


