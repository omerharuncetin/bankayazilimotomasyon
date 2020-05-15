#pragma once
#include <string>
#include "BireyselMusteri.h"
#include "TicariMusteri.h"

using namespace  std;
class Hesap
{
protected:
	string TcNumarasi;
	string HesapNumarasi;
	int HesapTutari ;
	int IslemTutari;
	string Sifre;
	string operator<<(int hesapNumarasi);

public:
	Hesap(string tcNumarasi, string hesapNumarasi, string sifre);
	virtual string ParaGirisi(int tutar);
	virtual string ParaCikisi(int tutar);
	string HesapBilgileriGetir();
	
	
};

