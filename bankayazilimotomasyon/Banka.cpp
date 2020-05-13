#include "Banka.h"
int Banka::YeniMusteriNumarasi()
{
	return this->sonMusteriNumarasi++;
}

bool Banka::HesapEkle(Hesap hesap)
{
	if(sonHesapYeri == 199)
		return false;
	Hesaplar[sonHesapYeri++] = hesap;
	return true;
}

bool Banka::HesapSil(int HesapNumarasi)
{
	
}


Banka::Banka()
{
	
}

