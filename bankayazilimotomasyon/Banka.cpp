#include "Banka.h"
int Banka::YeniMusteriNumarasi()
{
	return this->sonMusteriNumarasi++;
}

bool Banka::HesapEkle(Hesap hesap)
{
	Hesaplar.push_back(hesap);
	return true;
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
	BireyselMusteriler.push_back(musteri);
	return true;
}

bool Banka::TicariMusteriEkle(TicariMusteri musteri)
{
	TicariMusteriler.push_back(musteri);
	return true;
}

bool Banka::HesaptanParaCek(int musteriNo, int hesapNo, int tutar)
{
	Hesap musteriHesabi = HesapBul(hesapNo);
	vector<Hesap> musteriHesaplari = MusteriHesaplariniBul(musteriNo);
}

bool Banka::HesabaParaYatir(int hesapNo, int tutar)
{
	Hesap musteriHesabi = HesapBul(hesapNo);
}

vector<Hesap> Banka::MusteriHesaplariniBul(int musteriNo)
{
	vector <Hesap> MusteriHesaplari;
	for (int i = 0; i < Hesaplar.max_size(); i++)
	{
		Hesaplar[i];
	}
	return MusteriHesaplari;
}

Hesap Banka::HesapBul(int hesapNo)
{
	for (int i = 0; i < Hesaplar.max_size(); i++)
	{
		return Hesaplar[i];
	}
}