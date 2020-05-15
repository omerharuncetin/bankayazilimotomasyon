#pragma once
#include "BireyselMusteri.h"
#include <iostream>
class TicariMusteri : BireyselMusteri {
protected:
	string SirketVergiNumarasi;
	string SirketFaksNumarasi;
	BireyselMusteri MusteriBilgileri;

public:
	TicariMusteri(string sirketVergiNumarasi, string sirketFaksNumarasi, BireyselMusteri musteriBilgileri);
	virtual string SirketBilgileriniGetir();
	virtual void BilgiGuncelle(string sirketVergiNumarasi,
								 string sirketFaksNumarasi,
								 BireyselMusteri musteriBilgileri);
	
	string ParaCek(int tutar) override {

	};

	string ParaYatir(int tutar) override {

	};

	
};




