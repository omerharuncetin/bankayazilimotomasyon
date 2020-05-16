#pragma once
#include <string>
#include "Hesap.h"


using namespace std;
class BireyselMusteri
{
protected:
	
	int Sifre;
	string Ad;
	string Soyad;
	string Telefon;
	string Eposta;
	string TCNO;

public:
	int MusteriNo = 0;
	BireyselMusteri(string ad, string soyad, string telefon, string eposta, string tc, int musteriNo, int sifre);
	BireyselMusteri(int musteriNo, int sifre);
	BireyselMusteri(){};
	bool GirisYap(string tcno, int sifre);
	string BilgileriniGetir();
	string BilgiGuncelle(string ad, string soyad, string telefon, string eposta, string tc);
	string TCNOGetir() { return this->TCNO; }
	~BireyselMusteri();
};
