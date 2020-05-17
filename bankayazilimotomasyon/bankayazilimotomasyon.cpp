#include <ctime>
#include <iostream>
#include <vector>
#include "Banka.h"
#include <string>
#include <clocale>
using namespace std;

Banka SuperBank;

int simdikiHesapNumarasi = 0;
int simdikiMusteriNumarasi = 0;

BireyselMusteri _bireyselMusteri;
TicariMusteri _ticariMusteri;
string MusteriTipi = "";

bool BireyselMusteriOlustur(string ad, string soyad, string telefon, string eposta, string tcno, int sifre);
void BireyselMusteriBilgileriAl(string& ad, string& soyad, string& telefon, string& eposta, string& tcno, int& sifre);

void TicariMusteriBilgileriAl(string& ad, string& soyad, string& telefon, string& eposta, string& tcno, int& sifre, string& sirketFaksNo, string& sirketVergiNo);
bool TicariMusteriOlustur(string ad, string soyad, string telefon, string eposta, string tcno, int sifre, string sirketFaksNo, string sirketVergiNo);

void YeniHesapOlustur(int musteriNo);
void IslemSecimi(int hesapNo, int musteriNo, string musteriTipi);

bool GirisYap();

void TireEkle();
string IslemleriYazdir(int hesapNo);

int main()
{
	setlocale(LC_ALL, "Turkish");

	while (true)
	{
		TireEkle();
		cout << "SuperBanka Hoþ Geldiniz! \nGiriþ Yapmak için 1 \nMüþterimiz Olmak Ýçin 2 Yazýnýz" << endl;
		int secilenDurum;
		string ad = "", soyad = "", telefon = "", eposta = "", tcno = "", sirketVergiNo = "", sirketFaksNo = "";
		int sifre = 0;
		cin >> secilenDurum;
		switch (secilenDurum)
		{
		case 1:
			if (GirisYap())
			{
				if (MusteriTipi == "Bireysel")
				{
					while (true)
					{
						vector< Hesap> musteriHesaplari = SuperBank.MusteriHesaplariniGetir(_bireyselMusteri.MusteriNo);
						int hesapIndexi = 0;

						for (int i = 0; i < musteriHesaplari.size(); i++)
						{
							TireEkle();
							cout << "Bu hesabý seçmek için " << i << " giriniz" << endl;
							cout << musteriHesaplari[i].HesapBilgileriGetir() << endl;
						}
						cout << "Yeni hesap açmak için -1(eksi bir) yazýnýz." << endl;
						cin >> hesapIndexi;
						if (hesapIndexi == -1) {
							TireEkle();
							YeniHesapOlustur(_bireyselMusteri.MusteriNo);
						}
						else
						{
							TireEkle();
							IslemSecimi(musteriHesaplari[hesapIndexi].HesapNumarasiAl(), _bireyselMusteri.MusteriNo, MusteriTipi);
							break;
						}
					}
				}
				else
				{
					vector< Hesap> musteriHesaplari = SuperBank.MusteriHesaplariniGetir(_ticariMusteri.MusteriNo);
					int hesapIndexi = 0;
					for (int i = 0; i < musteriHesaplari.size(); i++)
					{
						TireEkle();
						cout << "Seçmek için " << i << " Giriniz" << endl;
						cout << musteriHesaplari[i].HesapBilgileriGetir() << endl;
					}
					cout << "Yeni hesap açmak için -1(eksi bir) yazýnýz." << endl;
					cin >> hesapIndexi;
					if (hesapIndexi == -1) {
						TireEkle();
						YeniHesapOlustur(_ticariMusteri.MusteriNo);
					}
					else
					{
						TireEkle();
						IslemSecimi(musteriHesaplari[hesapIndexi].HesapNumarasiAl(), _ticariMusteri.MusteriNo, "no");
						break;
					}
				}
			}
			break;
		case 2:
			cout << "Bireysel Müþteri Olmak Ýçin 1 \nTicari Müþteri Olmak Ýçin 2 Giriniz " << endl;
			int secilenDurum2;
			cin >> secilenDurum;

			switch (secilenDurum)
			{
			case 1:
				cout << "Bilgileriniz Giriniz" << endl;
				BireyselMusteriBilgileriAl(ad, soyad, telefon, eposta, tcno, sifre);
				if (BireyselMusteriOlustur(ad, soyad, telefon, eposta, tcno, sifre))
				{
					TireEkle();
					cout << "Bilgileriniz" << endl;
					cout << _bireyselMusteri.BilgileriniGetir() << endl;
					vector <Hesap> MusteriHesaplari = SuperBank.MusteriHesaplariniGetir(_bireyselMusteri.MusteriNo);
					if (MusteriHesaplari.empty())
					{
						TireEkle();
						YeniHesapOlustur(_bireyselMusteri.MusteriNo);
						MusteriHesaplari = SuperBank.MusteriHesaplariniGetir(_bireyselMusteri.MusteriNo);
					}
					TireEkle();
					MusteriHesaplari[0].HesapBilgileriGetir();
					TireEkle();
					IslemSecimi(MusteriHesaplari[0].HesapNumarasiAl(), _bireyselMusteri.MusteriNo, "Bireysel");
				}
				else
				{
					cout << "Lütfen bilgileri eksiksiz giriniz" << endl;
				}
				break;
			case 2:
				cout << "Bilgileriniz Giriniz" << endl;
				TicariMusteriBilgileriAl(ad, soyad, telefon, eposta, tcno, sifre, sirketFaksNo, sirketVergiNo);
				if (TicariMusteriOlustur(ad, soyad, telefon, eposta, tcno, sifre, sirketFaksNo, sirketVergiNo))
				{
					TireEkle();
					cout << "Bilgileriniz" << endl;
					cout << _ticariMusteri.BilgileriniGetir() << endl;
					vector <Hesap> MusteriHesaplari = SuperBank.MusteriHesaplariniGetir(_ticariMusteri.MusteriNo);
					if (MusteriHesaplari.empty())
					{
						TireEkle();
						YeniHesapOlustur(_ticariMusteri.MusteriNo);
						MusteriHesaplari = SuperBank.MusteriHesaplariniGetir(_ticariMusteri.MusteriNo);
					}
					MusteriHesaplari[0].HesapBilgileriGetir();
					TireEkle();
					IslemSecimi(MusteriHesaplari[0].HesapNumarasiAl(), _ticariMusteri.MusteriNo, "no");
				}
				else
				{
					TireEkle();
					cout << "Lütfen bilgileri eksiksiz giriniz!!!" << endl;
					TireEkle();
				}
				break;
			default:
				TireEkle();
				cout << "Hata" << endl;
				TireEkle();
				break;
			}
			break;
		default:
			TireEkle();
			cout << "Hata" << endl;
			TireEkle();
			break;
		}
	}
}

bool BireyselMusteriOlustur(string ad, string soyad, string telefon, string eposta, string tcno, int sifre)
{
	if (ad == "" || soyad == "" || telefon == "" || eposta == "" || tcno == "" || (sifre == 0 && std::to_string(sifre).length() != 4))
		return false;

	int musteriNo = SuperBank.YeniMusteriNumarasi();
	BireyselMusteri yeniMusteri(ad, soyad, telefon, eposta, tcno, musteriNo, sifre);
	_bireyselMusteri = yeniMusteri;
	SuperBank.BireyselMusteriEkle(yeniMusteri);
	return true;
}
void BireyselMusteriBilgileriAl(string& ad, string& soyad, string& telefon, string& eposta, string& tcno, int& sifre)
{
	cout << "Adýnýz: " << endl;
	cin >> ad;
	cout << "Soyadýnýz: " << endl;
	cin >> soyad;
	cout << "Telefon Numaranýz: " << endl;
	cin >> telefon;
	cout << "Eposta Adresiniz: " << endl;
	cin >> eposta;
	cout << "TC Kimlik Numaranýz: " << endl;
	cin >> tcno;
	cout << "Þifreniz (4 karakter uzunluðunda olmalý ve sadece rakamlardan oluþmalýdýr): " << endl;
	cin >> sifre;
}

bool TicariMusteriOlustur(string ad, string soyad, string telefon, string eposta, string tcno, int sifre, string sirketFaksNo, string sirketVergiNo)
{
	if (ad == "" || soyad == "" || telefon == "" || eposta == "" || tcno == "" || (sifre == 0 && std::to_string(sifre).length() != 4) || sirketFaksNo == "" || sirketVergiNo == "")
		return false;

	int musteriNo = SuperBank.YeniMusteriNumarasi();
	TicariMusteri yeniMusteri(sirketVergiNo, sirketFaksNo, ad, soyad, telefon, eposta, tcno, sifre, musteriNo);
	_ticariMusteri = yeniMusteri;
	SuperBank.TicariMusteriEkle(yeniMusteri);
	return true;
}
void TicariMusteriBilgileriAl(string& ad, string& soyad, string& telefon, string& eposta, string& tcno, int& sifre, string& sirketFaksNo, string& sirketVergiNo)
{
	cout << "Adýnýz: " << endl;
	cin >> ad;
	cout << "Soyadýnýz: " << endl;
	cin >> soyad;
	cout << "Telefon Numaranýz: " << endl;
	cin >> telefon;
	cout << "Eposta Adresiniz: " << endl;
	cin >> eposta;
	cout << "TC Kimlik Numaranýz: " << endl;
	cin >> tcno;
	cout << "Þifreniz (4 karakter uzunluðunda olmalý ve sadece rakamlardan oluþmalýdýr): " << endl;
	cin >> sifre;
	cout << "Sirketinizin Faks Numarasi : " << endl;
	cin >> sirketFaksNo;
	cout << "Sirketinizin Vergi Numarasi: " << endl;
	cin >> sirketVergiNo;
}

void IslemSecimi(int hesapNo, int musteriNo, string musteriTipi) {
	int secilenIslem;
	int tutar;
	int devamKontrolu;
	string tarih1, tarih2;
	do
	{
		devamKontrolu = 0;
		cout << "Hangi islemi yapmak istersiniz?" << endl;
		cout << "Para cekmek icin 1, para yatýrmak icin 2 , gireceðiniz tarihler arasýndaki hesap özetinizi görmek için 3 yazýn." << endl;
		cin >> secilenIslem;

		switch (secilenIslem)
		{
		case 1:
			cout << "Para cekmeyi sectiniz." << endl;
			cout << "Kac Turk Lirasi çekmek istiyorsunuz?" << endl;
			cin >> tutar;
			if (musteriTipi == "Bireysel" && tutar > 2000)
			{
				TireEkle();
				cout << "Bireysel müsterilerin limiti 2000 Türk Lirasý ile sýnýrlýdýr.";
				TireEkle();
				break;
			}
			TireEkle();
			cout << SuperBank.HesaptanParaCek(musteriNo, hesapNo, tutar) << endl;
			break;
		case 2:
			cout << "Para yatirmayi sectiniz." << endl;
			cout << "Kac Turk Lirasi yatýrmak istiyorsunuz?" << endl;
			cin >> tutar;
			TireEkle();
			cout << SuperBank.HesabaParaYatir(hesapNo, tutar) << endl;
			cout << "Baþarýyla eklendi!" << endl;
			break;
		case 3:
			cout << IslemleriYazdir(hesapNo) << endl;
			break;
		default:
			break;
		}
		cout << "Ýslem yapmaya devam etmek icin 1 yazýn." << endl;
		cout << "Çýkmak icin 0 yazýn." << endl;
		TireEkle();
		cin >> devamKontrolu;
	} while (devamKontrolu == 1);
}
void YeniHesapOlustur(int musteriNo) {
	int karar;
	string takmaAd;

	Hesap hesap(musteriNo, SuperBank.YeniHesapNumarasi());

	cout << "Hesabýnýz olustu. Hesabýnýza isim vermek isterseniz 1 yazin." << endl;
	cout << "Hesap islemlerine devam etmek icin 2 yazin." << endl;
	cin >> karar;
	switch (karar)
	{
	case 1:
		cout << "Takma adi giriniz : " << endl;
		cin >> takmaAd;
		hesap.TakmaHesapAdi = takmaAd;
	default:
		break;
	}

	SuperBank.HesapEkle(hesap);

	cout << hesap.HesapBilgileriGetir() << endl;
}

bool GirisYap()
{
	int tip = 0;
	cout << "Bireysel Müþteri Ýçin 1 \nTicari Müþteri Ýçin 2 Yazýnýz" << endl;
	cin >> tip;
	int sifre;
	string tcno;
	BireyselMusteri bireysel;
	TicariMusteri ticari;
	switch (tip)
	{
	case 1:
		cout << "Lütfen Bilgileriniz Giriniz:\n" << endl;

		cout << "TC Kimlik Numaranýzý Giriniz: " << endl;
		cin >> tcno;
		cout << "Þifrenizi Giriniz: " << endl;
		cin >> sifre;
		bireysel = SuperBank.BireyselMusteriGiris(tcno, sifre);
		if (bireysel.MusteriNo != 0)
		{
			_bireyselMusteri = bireysel;
			MusteriTipi = "Bireysel";
			return true;
		}

		cout << "Hatalý Giriþ Bilgileri" << endl;
		return false;

	case 2:
		cout << "Lütfen Bilgileriniz Giriniz:\n" << endl;

		cout << "TC Kimlik Numaranýzý Giriniz: " << endl;
		cin >> tcno;
		cout << "Þifrenizi Giriniz: " << endl;
		cin >> sifre;
		ticari = SuperBank.TicariMusteriGiris(tcno, sifre);
		if (ticari.MusteriNo != 0)
		{
			_ticariMusteri = ticari;
			MusteriTipi = "Ticari";
			return true;
		}

		cout << "Hatalý Giriþ Bilgileri" << endl;
		return false;

	default:
		return false;
	}
}

void TireEkle() {
	cout << "----------------------------\n";
}

string IslemleriYazdir(int hesapNo)
{
	int saat, dakika, saniye, gun, yil, ay;
	string tarih1, tarih2;
	struct tm ilkTarih, ikinciTarih;

	cout << "Lütfen Birinci tarihi giriniz (Tarih formatý Gün/Ay/YýlTSaat:Dakika:Saniye þeklinde olmalýdýr Örnek: 01/01/2020T14:24:56" << endl;
	cin >> tarih1;
	
	gun = stoi(tarih1.substr(0, 2));
	ay = stoi(tarih1.substr(3, 2));
	yil = stoi(tarih1.substr(6, 4));
	saat = stoi(tarih1.substr(11, 2));
	dakika = stoi(tarih1.substr(14, 2));
	saniye = stoi(tarih1.substr(17, 2));
	
	ilkTarih.tm_mday = gun;
	ilkTarih.tm_mon = ay;
	ilkTarih.tm_year = yil - 1900;
	ilkTarih.tm_hour = saat;
	ilkTarih.tm_min = dakika;
	ilkTarih.tm_sec = saniye;
	
	cout << "Ýkinci Tarihi giriniz (Ayný Formatta)" << endl;
	
	cin >> tarih2;
	gun = stoi(tarih2.substr(0, 2));
	ay = stoi(tarih2.substr(3, 2));
	yil = stoi(tarih2.substr(6, 4));
	saat = stoi(tarih2.substr(11, 2));
	dakika = stoi(tarih2.substr(14, 2));
	saniye = stoi(tarih2.substr(17, 2));

	ikinciTarih.tm_mday = gun;
	ikinciTarih.tm_mon = ay;
	ikinciTarih.tm_year = yil - 1900;
	ikinciTarih.tm_hour = saat;
	ikinciTarih.tm_min = dakika;
	ikinciTarih.tm_sec = saniye;
	

	time_t milliseconds1 = mktime(&ilkTarih);
	time_t milliseconds2 = mktime(&ikinciTarih);

	return SuperBank.HesapIslemleriniGetir(hesapNo, milliseconds1, milliseconds2);
}