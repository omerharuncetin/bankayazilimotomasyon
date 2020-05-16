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


bool BireyselMusteriOlustur(string ad, string soyad, string telefon, string eposta, string tcno, int sifre);
void BireyselMusteriBilgileriAl(string& ad, string& soyad, string& telefon, string& eposta, string& tcno, int& sifre);

void TicariMusteriBilgileriAl(string& ad, string& soyad, string& telefon, string& eposta, string& tcno, int& sifre, string& sirketFaksNo, string& sirketVergiNo);
bool TicariMusteriOlustur(string ad, string soyad, string telefon, string eposta, string tcno, int sifre, string sirketFaksNo, string sirketVergiNo);

void YeniHesapOlustur(int musteriNo);
void IslemSecimi(int hesapNo, int musteriNo);


int main()
{
	setlocale(LC_ALL, "Turkish");
	
	while (true)
	{
		cout << "SuperBanka Hoþ Geldiniz!\n Giriþ Yapmak için 1 \n Müþterimiz Olmak Ýçin 2 Yazýnýz" << endl;
		int secilenDurum;
		string ad = "", soyad = "", telefon = "", eposta = "", tcno = "", sirketVergiNo ="", sirketFaksNo ="";
		int sifre = 0;
		cin >> secilenDurum;
		switch (secilenDurum)
		{
		case 1:
			break;
		case 2:
			cout << "Bireysel Müþteri Olmak Ýçin 1 \n Ticari Müþteri Olmak Ýçin 2 Giriniz ";
			int secilenDurum2;
			cin >> secilenDurum;

			switch (secilenDurum)
			{
			case 1:
				cout << "Bilgileriniz Giriniz" << endl;
				BireyselMusteriBilgileriAl(ad, soyad, telefon, eposta, tcno, sifre);
				if (BireyselMusteriOlustur(ad, soyad, telefon, eposta, tcno, sifre))
				{
					cout << "Bilgileriniz" << endl;
					cout << _bireyselMusteri.BilgileriniGetir() << endl;
					vector <Hesap> MusteriHesaplari = SuperBank.MusteriHesaplariniGetir(_bireyselMusteri.MusteriNo);
					if (MusteriHesaplari.empty())
					{
						YeniHesapOlustur(_bireyselMusteri.MusteriNo);
						MusteriHesaplari = SuperBank.MusteriHesaplariniGetir(_bireyselMusteri.MusteriNo);
						
					}
					Hesap tempHesap = MusteriHesaplari[0];
					tempHesap.HesapBilgileriGetir();
					IslemSecimi(tempHesap.HesapNumarasiAl(), _bireyselMusteri.MusteriNo);
					
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
					cout << "Bilgileriniz" << endl;
					cout << _ticariMusteri.BilgileriniGetir() << endl;
					vector <Hesap> MusteriHesaplari = SuperBank.MusteriHesaplariniGetir(_ticariMusteri.MusteriNo);
					if (MusteriHesaplari.empty())
					{
						YeniHesapOlustur(_ticariMusteri.MusteriNo);

					}
					//IslemSecimi();

				}
				else
				{
					cout << "Lütfen bilgileri eksiksiz giriniz" << endl;
				}
				break;
			default:
				cout << "Hata" << endl;
				break;
			}
			break;
		default:
			cout << "Hata" << endl;
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
void BireyselMusteriBilgileriAl(string &ad, string &soyad, string &telefon, string &eposta, string &tcno, int &sifre)
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
	TicariMusteri yeniMusteri(sirketVergiNo, sirketFaksNo,ad, soyad, telefon, eposta, tcno, sifre, musteriNo);
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

void IslemSecimi(int hesapNo, int musteriNo) {
	int secilenIslem;
	int tutar;

	cout << "Hangi islemi yapmak istersiniz?" << endl;
	cout << "Para cekmek icin 1, para yatýrmak icin 2 yazýn." << endl;
	cin >> secilenIslem;

	switch (secilenIslem)
	{
	case 1:
		cout << "Para cekmeyi sectiniz." << endl;
		cout << "Kac Turk Lirasi çekmek istiyorsunuz?";
		cin >> tutar;
		SuperBank.HesaptanParaCek(musteriNo, hesapNo, tutar);
		
	case 2:
		cout << "Para yatirmayi sectiniz." << endl;
		cout << "Kac Turk Lirasi yatýrmak istiyorsunuz?";
		cin >> tutar;
		SuperBank.HesabaParaYatir(hesapNo, tutar);
	default:
		break;
	}

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

