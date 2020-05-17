#pragma once
#include <string>
using namespace std;

class Musteri
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
	virtual bool GirisYap(string tcno, int sifre) = 0;
	virtual string BilgileriniGetir() = 0;
};
