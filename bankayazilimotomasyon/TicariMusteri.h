#pragma once
#include <string>

using namespace std;
class TicariMusteri {
protected:
	int MusteriNo;
	int Sifre;
	string Ad;
	string Soyad;
	string Telefon;
	string Eposta;
	string TCNO;
	string SirketVergiNumarasi;
	string SirketFaksNumarasi;

public:
	TicariMusteri(string sirketVergiNumarasi, string sirketFaksNumarasi, string ad, 
				  string soyad, string telefon, string eposta, string tcNo, int sifre, int musteriNo);
	string SirketBilgileriniGetir();
	void BilgiGuncelle(string sirketVergiNumarasi, string sirketFaksNumarasi, string ad,
							   string soyad, string telefon, string eposta, string tcNo, int sifre, int musteriNo);

	string BilgileriniGetir();
};




