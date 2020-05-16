#include "Banka.h"
#include "Hesap.h"

bool Banka::HesapEkle(Hesap hesap)
{
	Hesaplar.push_back(hesap);
	return true;
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
	Hesap musteriHesabi = HesapBul(hesapNo);
	vector<Hesap> musteriHesaplari = MusteriHesaplariniBul(musteriNo, hesapNo);
	int toplamTutar = musteriHesabi.HesapTutariAl();
	for (int i = 0; i < musteriHesaplari.max_size(); i++)
	{
		toplamTutar += musteriHesaplari[i].HesapTutariAl();
	}
	if (toplamTutar < tutar)
		return "Bakiye yetersiz!";
	
	string returnString = "---------------------------------------------\n";
	if(!musteriHesabi.ParaCikisi(tutar))
	{
		int kalanTutar = tutar - musteriHesabi.HesapTutariAl();
		musteriHesabi.ParaCikisi(musteriHesabi.HesapTutariAl());
		returnString += musteriHesabi.HesapBilgileriGetir();
		
		for (int i = 0; i < musteriHesaplari.max_size(); i++)
		{
			if(kalanTutar <= musteriHesaplari[i].HesapTutariAl())
			{
				musteriHesaplari[i].ParaCikisi(kalanTutar);
				returnString += "\n---------------------------------------------";
				return returnString;
			}
				
			
			kalanTutar -= musteriHesaplari[i].HesapTutariAl();
			musteriHesaplari[i].ParaCikisi(musteriHesaplari[i].HesapTutariAl());
			returnString += musteriHesaplari[i].HesapBilgileriGetir();
			
		}
	}
	else
	{
		musteriHesabi.ParaCikisi(musteriHesabi.HesapTutariAl());
		returnString += musteriHesabi.HesapBilgileriGetir();
		returnString += "\n---------------------------------------------";
		return returnString;
	}
}

bool Banka::HesabaParaYatir(int hesapNo, int tutar)
{
	Hesap musteriHesabi = HesapBul(hesapNo);
	musteriHesabi.ParaGirisi(tutar);
	return true;
}

vector <Hesap> Banka::MusteriHesaplariniBul(int musteriNo, int hesapNo)
{
	vector <Hesap> musteriHesaplari;
	for (int i = 0; i < Hesaplar.max_size(); i++)
	{
		if (Hesaplar[i].MusteriNumarasiAl() == musteriNo && Hesaplar[i].HesapNumarasiAl() != hesapNo)
			musteriHesaplari.push_back(Hesaplar[i]);
	}
	return musteriHesaplari;
}

Hesap Banka::HesapBul(int hesapNo)
{
	for (int i = 0; i < Hesaplar.max_size(); i++)
	{
		if(Hesaplar[i].HesapNumarasiAl() == hesapNo)
			return Hesaplar[i];
	}
}

int Banka::HesapIndexiBul(int hesapNumarasi)
{
	for (int i = 0; i < Hesaplar.max_size(); i++)
	{
		if (Hesaplar[i].HesapNumarasiAl() == hesapNumarasi)
			return i;
	}
}
