#include "Banka.h"
int Banka::YeniMusteriNumarasi()
{
	return this->sonMusteriNumarasi++;
}

bool Banka::HesapEkle(Hesap hesap)
{
	Hesaplar.push_back(hesap);
}

bool Banka::HesapSil(int HesapNumarasi)
{
	return true;
}

Banka::Banka()
{
	
}

bool Banka::BireyselMusteriEkle(BireyselMusteri musteri)
{
	BireyselMusteriler->push_back(musteri);
	return true;
}

bool Banka::TicariMusteriEkle(TicariMusteri musteri)
{
	TicariMusteriler->push_back(musteri);
	return true;
}
