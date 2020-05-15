#pragma once
#include <string>
#include "BireyselMusteri.h"
#include "TicariMusteri.h"
#include "Islem.h"
#include <vector>

using namespace  std;
class Hesap
{
protected:
	string TcNumarasi;
	string HesapNumarasi;
	int HesapTutari;
	int IslemTutari;
	string Sifre;
	string operator<<(int hesapNumarasi);
	vector <Islem> Islemler;
	

public:
	Hesap(string tcNumarasi, string hesapNumarasi, string sifre);
	virtual string ParaGirisi(int tutar, Islem islem);
	virtual string ParaCikisi(int tutar, Islem islem);
	string HesapBilgileriGetir();
	
};
