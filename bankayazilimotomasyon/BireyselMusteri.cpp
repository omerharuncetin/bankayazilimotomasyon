#include "BireyselMusteri.h"
BireyselMusteri::BireyselMusteri(string ad, string soyad, string telefon, string eposta, string tc, int musteriNo, int sifre)
{
	this->MusteriNo = musteriNo;
	this->Ad = ad;
	this->Soyad = soyad;
	this->Telefon = telefon;
	this->Eposta = eposta;
	this->TCNO = tc;
	this->Sifre = sifre;
}

bool BireyselMusteri::GirisYap(string tcno, int sifre)
{
	if (this->TCNO == tcno && this->Sifre == sifre)
		return true;
	return false;
}

string BireyselMusteri::BilgileriniGetir()
{
	return "Ad : " + this->Ad + " Soyad : " + this->Soyad +
		"\nTelefon: " + this->Telefon + "\nEposta: " + this->Eposta;
}

BireyselMusteri::BireyselMusteri(int musteriNo, int sifre)
{
	this->MusteriNo = musteriNo;
	this->Sifre = sifre;
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
	return "ok";
}
