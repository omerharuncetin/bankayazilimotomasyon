#pragma once
#include <string>
#include "Musteri.h"
using namespace std;
class TicariMusteri : public Musteri {
private:
	string SirketVergiNumarasi;
	string SirketFaksNumarasi;

public:
	TicariMusteri(string sirketVergiNumarasi, string sirketFaksNumarasi, string ad,
		string soyad, string telefon, string eposta, string tcNo, int sifre, int musteriNo);
	TicariMusteri() {};
	string SirketBilgileriniGetir();
	void BilgiGuncelle(string sirketVergiNumarasi, string sirketFaksNumarasi, string ad,
		string soyad, string telefon, string eposta, string tcNo, int sifre, int musteriNo);
	bool GirisYap (string tcno, int sifre) override;
	string BilgileriniGetir() override;
};
