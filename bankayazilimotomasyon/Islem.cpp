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
	return std::to_string((Tarih.tm_mday)) + "/" + std::to_string(Tarih.tm_mon + 1) + "/" + std::to_string(Tarih.tm_year + 1900);
}
string Islem::IslemBilgileriniDondur()
{
	return "\nİşlem Tipi : " + this->IslemTipi +
		"\nTutar: " + std::to_string(this->Tutar) +
		"\nTarih: " + TarihDondur();
}

bool Islem::TarihKiyasla(tm tarih1, tm tarih2)
{
	if (tarih1.tm_year <= Tarih.tm_year && tarih2.tm_year > Tarih.tm_year)
		return true;

	if (tarih1.tm_year < Tarih.tm_year && tarih2.tm_year >= Tarih.tm_year)
		return true;

	if ((tarih1.tm_year <= Tarih.tm_year && tarih2.tm_year >= Tarih.tm_year) &&
		(tarih1.tm_mon <= Tarih.tm_mon && tarih2.tm_mon > Tarih.tm_mon))
		return true;

	if ((tarih1.tm_year <= Tarih.tm_year && tarih2.tm_year >= Tarih.tm_year) &&
		(tarih1.tm_mon < Tarih.tm_mon && tarih2.tm_mon >= Tarih.tm_mon))
		return true;

	if ((tarih1.tm_year <= Tarih.tm_year && tarih2.tm_year >= Tarih.tm_year) &&
		(tarih1.tm_mon <= Tarih.tm_mon && tarih2.tm_mon >= Tarih.tm_mon) &&
		(tarih1.tm_mday <= Tarih.tm_mday && tarih2.tm_mday > Tarih.tm_mday))
		return true;

	if ((tarih1.tm_year <= Tarih.tm_year && tarih2.tm_year >= Tarih.tm_year) &&
		(tarih1.tm_mon <= Tarih.tm_mon && tarih2.tm_mon >= Tarih.tm_mon) &&
		(tarih1.tm_mday < Tarih.tm_mday && tarih2.tm_mday >= Tarih.tm_mday))
		return true;

	if ((tarih1.tm_year <= Tarih.tm_year && tarih2.tm_year >= Tarih.tm_year) &&
		(tarih1.tm_mon <= Tarih.tm_mon && tarih2.tm_mon >= Tarih.tm_mon) &&
		(tarih1.tm_mday == Tarih.tm_mday && tarih2.tm_mday == Tarih.tm_mday))
		return true;

	return false;
}