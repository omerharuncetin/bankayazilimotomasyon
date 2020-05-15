#pragma once
#include "BireyselMusteri.h"
#include <iostream>
class TicariMusteri : BireyselMusteri {
protected:
	string SirketVergiNumarasi;
	string SirketFaksNumarasi;

public:
	TicariMusteri(string sirketVergiNumarasi, string sirketFaksNumarasi, string ad, 
				  string soyad, string telefon, string eposta, string tcNo);
	virtual string SirketBilgileriniGetir();
	virtual void BilgiGuncelle(string sirketVergiNumarasi, string sirketFaksNumarasi, string ad,
							   string soyad, string telefon, string eposta, string tcNo);
	
	string ParaCek(int tutar) override {};

	string ParaYatir(int tutar) override {};

	string BilgileriniGetir() override {};



	
};




