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
void IslemSecimi(int hesapNo, int musteriNo);


bool GirisYap();

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
			if(GirisYap())
			{
				if(MusteriTipi == "Bireysel")
				{
					vector< Hesap> musteriHesaplari = SuperBank.MusteriHesaplariniGetir(_bireyselMusteri.MusteriNo);
					int hesapIndexi= 0;
					for (int i = 0; i < musteriHesaplari.size(); i++)
					{
						cout << "-----------------------------------\n" << endl;
						cout << "Seçmek için " << i << " Giriniz" << endl;
						cout << musteriHesaplari[i].HesapBilgileriGetir() << endl;
					}
					cin >> hesapIndexi;
					IslemSecimi(musteriHesaplari[hesapIndexi].HesapNumarasiAl(), _bireyselMusteri.MusteriNo);
				}
				else
				{
					vector< Hesap> musteriHesaplari = SuperBank.MusteriHesaplariniGetir(_ticariMusteri.MusteriNo);
					int hesapIndexi = 0;
					for (int i = 0; i < musteriHesaplari.size(); i++)
					{
						cout << "-----------------------------------\n" << endl;
						cout << "Seçmek için " << i << " Giriniz" << endl;
						cout << musteriHesaplari[i].HesapBilgileriGetir() << endl;
					}
					cin >> hesapIndexi;
					IslemSecimi(musteriHesaplari[hesapIndexi].HesapNumarasiAl(), _ticariMusteri.MusteriNo);
				}
			}
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
					MusteriHesaplari[0].HesapBilgileriGetir();
					IslemSecimi(MusteriHesaplari[0].HesapNumarasiAl(), _bireyselMusteri.MusteriNo);
					
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
		cout << SuperBank.HesaptanParaCek(musteriNo, hesapNo, tutar) << endl;
		break;
	case 2:
		cout << "Para yatirmayi sectiniz." << endl;
		cout << "Kac Turk Lirasi yatýrmak istiyorsunuz?";
		cin >> tutar;
		SuperBank.HesabaParaYatir(hesapNo, tutar);
		cout << "Baþarýyla eklendi!" << endl;
		break;
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
		if(bireysel.MusteriNo != 0)
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