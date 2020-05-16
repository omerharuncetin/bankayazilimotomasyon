#include "TicariMusteri.h"

TicariMusteri::TicariMusteri(string sirketVergiNumarasi, string sirketFaksNumarasi, string ad,
							 string soyad, string telefon, string eposta, string tcNo, int sifre, int musteriNo) {
	this->Ad = ad;
	this->Soyad = soyad;
	this->Telefon = telefon;
	this->Eposta = eposta;
	this->TCNO = tcNo;
	this->Sifre = sifre;
	this->MusteriNo = musteriNo;
	this->SirketFaksNumarasi = sirketFaksNumarasi;
	this->SirketVergiNumarasi = sirketVergiNumarasi;
}

string TicariMusteri::SirketBilgileriniGetir() {
	string temp = "Sirket vergi numarasi : " + this->SirketVergiNumarasi + ", " +
				  "Sirket faks numarasi : " + this->SirketFaksNumarasi;
	return temp;
}

string TicariMusteri::BilgileriniGetir() {
	
	string temp = "Ad : " + this->Ad + " Soyad : " + this->Soyad + 
				  "\nTelefon: " + this->Telefon + "\nEposta: " + this->Eposta + 
				  "\nSirket faks numarasi : " + this->SirketFaksNumarasi +
				  "\nSirket vergi numarasi : " + this->SirketVergiNumarasi;;
	return temp;
}
void TicariMusteri::BilgiGuncelle(string sirketVergiNumarasi, string sirketFaksNumarasi, string ad,
								  string soyad, string telefon, string eposta, string tcNo, int sifre, int musteriNo) {
	this->Ad = ad;
	this->Soyad = soyad;
	this->Telefon = telefon;
	this->Eposta = eposta;
	this->TCNO = tcNo;
	this->Sifre = sifre;
	this->MusteriNo = musteriNo;
	this->SirketFaksNumarasi = sirketFaksNumarasi;
	this->SirketVergiNumarasi = sirketVergiNumarasi;
	
}



