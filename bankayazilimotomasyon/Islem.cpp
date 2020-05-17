#include "Islem.h"
Islem::Islem(time_t milliseconds, string islemTipi, int tutar)
{
	
	localtime_s(&Tarih, &milliseconds);
	this->IslemTipi = islemTipi;
	this->milliseconds = milliseconds;
	this->Tutar = tutar;
}
string Islem::TarihDondur()
{
	return std::to_string((Tarih.tm_mday + 1)) + " " + std::to_string(Tarih.tm_mon) + " " + std::to_string(Tarih.tm_year + 1900) ;
}
string Islem::IslemBilgileriniDondur()
{
	return "\nÝþlem Tipi : " + this->IslemTipi +
		"\nTutar: " + std::to_string(this->Tutar) +
		"\nTarih: " + TarihDondur();

}
