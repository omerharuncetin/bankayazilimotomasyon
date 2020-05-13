#include "BireyselMusteri.h"

BireyselMusteri::BireyselMusteri(string ad, string soyad, string telefon, string eposta, string tc, int musteriNo)
{
	this->MusteriNo = musteriNo;
	this->Ad = ad;
	this->Soyad = soyad;
	this->Telefon = telefon;
	this->Eposta = eposta;
	this->TCNO = tc;
}

string BireyselMusteri::BilgileriniGetir()
{
	return "Ad Soyad: " + this->Ad + " " + this->Soyad + "\nTelefon: " + this->Telefon + " Eposta: " + this->Eposta;
}

string BireyselMusteri::ParaCek(int tutar)
{
	return "test";
}

string BireyselMusteri::ParaYatir(int tutar)
{
	return "test";
}

BireyselMusteri::BireyselMusteri(int musteriNo)
{
	this->MusteriNo = musteriNo;
}

BireyselMusteri::~BireyselMusteri()
{
}
string BireyselMusteri::BilgiGuncelle(string ad, string soyad, string telefon, string eposta, string tc)
{
	this->Ad = ad;
	this->Soyad = soyad;
	this->Telefon = telefon;
	this->Eposta = eposta;
	this->TCNO = tc;
}
