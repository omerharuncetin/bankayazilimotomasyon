#pragma once
#include <string>
#include "BireyselMusteri.h"
using namespace std;
class TicariMusteri : public BireyselMusteri {
protected:
	string SirketVergiNumarasi;
	string SirketFaksNumarasi;

public:
	TicariMusteri(string sirketVergiNumarasi, string sirketFaksNumarasi, string ad, 
				  string soyad, string telefon, string eposta, string tcNo, int sifre, int musteriNo);
	virtual string SirketBilgileriniGetir();
	void BilgiGuncelle(string sirketVergiNumarasi, string sirketFaksNumarasi, string ad,
							   string soyad, string telefon, string eposta, string tcNo, int sifre, int musteriNo);

	string BilgileriniGetir();
};




