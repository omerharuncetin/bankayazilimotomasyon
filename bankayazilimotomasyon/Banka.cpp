#include "Banka.h"

#include <iostream>

#include "Hesap.h"
using namespace std;

bool Banka::HesapEkle(Hesap hesap)
{
	Hesaplar.push_back(hesap);
	return true;
}

string Banka::HesapIslemleriniGetir(int hesapNo, struct tm tarih1, struct tm tarih2)
{
	Hesap hesap = HesapBul(hesapNo);
	return hesap.TarihlereGoreIslemleriGetir(tarih1, tarih2);
}

bool Banka::HesapSil(int hesapNumarasi)
{
	int index = HesapIndexiBul(hesapNumarasi);
	Hesaplar.erase(Hesaplar.begin() + (index - 1));
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

string Banka::HesaptanParaCek(int musteriNo, int hesapNo, int tutar)
{
	int musteriHesabiYeri = HesapIndexiBul(hesapNo);
	vector<int> musteriHesaplarininYerleri = MusteriHesaplariniBul(musteriNo, hesapNo);
	int toplamTutar = Hesaplar[musteriHesabiYeri].HesapTutariAl();
	for (int i = 0; i < musteriHesaplarininYerleri.size(); i++)
	{
		toplamTutar += Hesaplar[musteriHesaplarininYerleri[i]].HesapTutariAl();
	}
	if (toplamTutar < tutar)
		return "Bakiye yetersiz!";

	string returnString = "---------------------------------------------\n";
	if (!Hesaplar[musteriHesabiYeri].ParaCikisi(tutar))
	{
		int kalanTutar = tutar - Hesaplar[musteriHesabiYeri].HesapTutariAl();
		Hesaplar[musteriHesabiYeri].ParaCikisi(Hesaplar[musteriHesabiYeri].HesapTutariAl());
		returnString += Hesaplar[musteriHesabiYeri].HesapBilgileriGetir();

		for (int i = 0; i < musteriHesaplarininYerleri.size(); i++)
		{
			if (kalanTutar <= Hesaplar[musteriHesaplarininYerleri[i]].HesapTutariAl())
			{
				Hesaplar[musteriHesaplarininYerleri[i]].ParaCikisi(kalanTutar);
				returnString += "\n---------------------------------------------";
				return returnString;
			}

			kalanTutar -= Hesaplar[musteriHesaplarininYerleri[i]].HesapTutariAl();
			Hesaplar[musteriHesaplarininYerleri[i]].ParaCikisi(Hesaplar[musteriHesaplarininYerleri[i]].HesapTutariAl());
			returnString += Hesaplar[musteriHesaplarininYerleri[i]].HesapBilgileriGetir();
		}
	}
	else
	{
		returnString += Hesaplar[musteriHesabiYeri].HesapBilgileriGetir();
		returnString += "\n---------------------------------------------";
		return returnString;
	}
}

string Banka::HesabaParaYatir(int hesapNo, int tutar)
{
	for (int i = 0; i < Hesaplar.size(); i++)
	{
		if (Hesaplar[i].HesapNumarasiAl() == hesapNo)
		{
			Hesaplar[i].ParaGirisi(tutar);
			return Hesaplar[i].HesapBilgileriGetir();
		}
	}
}

vector <int> Banka::MusteriHesaplariniBul(int musteriNo, int hesapNo)
{
	vector <int> musteriHesaplarininYerleri;
	for (int i = 0; i < Hesaplar.size(); i++)
	{
		if (Hesaplar[i].MusteriNumarasiAl() == musteriNo && Hesaplar[i].HesapNumarasiAl() != hesapNo)
			musteriHesaplarininYerleri.push_back(i);
	}
	return musteriHesaplarininYerleri;
}

Hesap Banka::HesapBul(int hesapNo)
{
	for (int i = 0; i < Hesaplar.size(); i++)
	{
		if (Hesaplar[i].HesapNumarasiAl() == hesapNo)
			return Hesaplar[i];
	}
}

int Banka::HesapIndexiBul(int hesapNumarasi)
{
	for (int i = 0; i < Hesaplar.size(); i++)
	{
		if (Hesaplar[i].HesapNumarasiAl() == hesapNumarasi)
			return i;
	}
}
vector <Hesap> Banka::MusteriHesaplariniGetir(int musteriNo) {
	vector <Hesap> musteriHesaplari;
	if (Hesaplar.empty())
	{
		return musteriHesaplari;
	}
	for (int i = 0; i < Hesaplar.size(); i++)
	{
		if (Hesaplar[i].MusteriNumarasiAl() == musteriNo)
			musteriHesaplari.push_back(Hesaplar[i]);
	}
	return musteriHesaplari;
}

BireyselMusteri Banka::BireyselMusteriGiris(string tcno, int sifre)
{
	for (int i = 0; i < BireyselMusteriler.size(); i++)
	{
		if (BireyselMusteriler[i].GirisYap(tcno, sifre))
			return BireyselMusteriler[i];
	}
	BireyselMusteri bos;
	return bos;
}

TicariMusteri Banka::TicariMusteriGiris(string tcno, int sifre)
{
	for (int i = 0; i < TicariMusteriler.size(); i++)
	{
		if (TicariMusteriler[i].GirisYap(tcno, sifre))
			return TicariMusteriler[i];
	}
	TicariMusteri bos;
	return bos;
}