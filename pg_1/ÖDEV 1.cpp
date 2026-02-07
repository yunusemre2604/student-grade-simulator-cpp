/****************************************************************************
**					SAKARYA ÜNİVERSİTESİ
**			         BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				    BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				          PROGRAMLAMAYA GİRİŞİ DERSİ
**
**				ÖDEV NUMARASI…...:1. ÖDEV
**				ÖĞRENCİ ADI...............:YUNUS EMRE YILDIZ
**				ÖĞRENCİ NUMARASI.:B231210378
**				DERS GRUBU…………:1. ÖĞRETİM C GRUBU
****************************************************************************/

#include <iostream> // girdi çıktı kütüphanesi .
#include <string.h> //string kütüphanesi .
#include <stdlib.h>  // dinamik bellek yönetimi ve rastgele sayı üretimi kütüphanesi.
#include <time.h>  // tarih ve saat işlemleri için kütüphanesi .
#include <algorithm> 
#include<iomanip>//Giriş/Çıkış (İnput/Output) birimlerinin belirli formatlarda yazdırma fonksiyonlarını içeren bir kütüphanedir.
#include <locale.h> // dil kütüphanesi .
using namespace std;
struct Ogrenci { // Öğrenci isimli yapı veri tipi oluşturuluyor .
	string ad, soyad; //ad ,soyad tanımlanıyor.
	int vizeNotuKarisik, kisaSinav1NotuKarisik, kisaSinav2NotuKarisik, ödev1NotuKarisik, ödev2NotuKarisik, finalNotuKarisik; //vize notlarının,kısa sınav notlarının ,ödev notlarının ve final notlarının rastgele karışık hali tanımlanıyor.

	double yilSonuOrtalamaNotu; //yıl sonu ortalama notu tanımlanıyor. 
};
int main() {
	setlocale(LC_ALL, "Turkish"); //Türkçe dil desteği ekleniyor. 
	srand(time(NULL));
	int sinifMevcudu; // Sınıf mevcudu değişkeni tanımlanıyor.
	int vizeAgirligi, ödevAgirligi, kisaSinavAgirligi, yılİciPuaniAgirligi; //Vize ağırlığı, ödev ağırlığı , kısa sınav ağırlığı ve yıl içi notunun geçme notuna etkisi tanımlanıyor.

	cout << "Lütfen sınıf mevcudunu giriniz: "; cin >> sinifMevcudu; //Sınıf mevcudunun dışarıdan girilmesi isteniyor.


	do {//vizeAgirligi + (2 * kisaSinavAgirligi) + (2 * ödevAgirligi) değerinin 100 olması gerektiği için do while döngüsüyle 100 harici girilen değerleri kabul etmeyen bir döngü.
		cout << "2 kısa sınav ağırlığı , 2 ödev ağırlığı ve vizenin ağırlığının toplamı 100 olmalı, yıliçi puan ağırlığı 100 e küçük veya eşit olmalı!!!" << endl;
		cout << "Lütfen vize ağırlığını giriniz: "; cin >> vizeAgirligi; //Vize ağırlığının dışarıdan girilmesi isteniyor .
		cout << "Lütfen kısa sınav ağırlığını giriniz: "; cin >> kisaSinavAgirligi; //Kısa sınavların ağırlığının dışarıdan girilmesi isteniyor.
		cout << "Lütfen ödev ağırlığını giriniz: "; cin >> ödevAgirligi; //Ödev ağırlığının dışarıdan girilmesi isteniyor.

	} while (vizeAgirligi + (2 * kisaSinavAgirligi) + (2 * ödevAgirligi) != 100);
	do {//yılİciPuaniAgirligi değeri 100 den küçük olması gerektiği için do while döngüsüyle 100 ve 100 den büyük olan değerleri kaul etmeyen bir döngü.
		cout << "Yıliçi puan ağırlığı 100'den küçük olmalı!!!" << endl;
		cout << "Lütfen Yıl içi puan ağırlığını giriniz: "; cin >> yılİciPuaniAgirligi; // Yıl içi puanın geçme notuna etkisinin dışarıdan girilmesi isteniyor.
	} while (yılİciPuaniAgirligi >= 100);



	int finalAgirligi = 100 - yılİciPuaniAgirligi; // Yıl içi puanının geçme notuna etkisine göre final ağırlığının geçme nptuna etkisi hesaplanıyor.
	int* vizeNot;  //Vize notlarının rastgele karılmamış hali dinamik dizi olarak tanımlanıyor.
	vizeNot = new int[sinifMevcudu];

	for (int i = 0; i < sinifMevcudu * 20 / 100; i++) { //Vize notları sınıfın %20'si 80 ve 100 arasında alacak şekilde rastgele belirleniyor.
		vizeNot[i] = rand() % 21 + 80;

	}
	for (int i = sinifMevcudu * 20 / 100; i < sinifMevcudu * 50 / 100 + sinifMevcudu * 20 / 100; i++) { //Vize notları sınıfın %50'si 50 ile 80 arasında alacak şekilde rastgele belirleniyor.
		vizeNot[i] = rand() % (79 - 50 + 1) + 50;

	}


	for (int i = sinifMevcudu * 50 / 100 + sinifMevcudu * 20 / 100; i < sinifMevcudu; i++) {//Vize notları sınıfın %30'u 0 ile 50 arasında alacak şekilde rastgele belirleniyor.
		vizeNot[i] = rand() % (49 - 0 + 1) + 0;

	}





	int* kisaSinav1Not; //1. kısa sınav notlarının rastgele karılmamış hali dinamik dizi olarak tanımlanıyor.
	kisaSinav1Not = new int[sinifMevcudu];

	for (int i = 0; i < sinifMevcudu * 20 / 100; i++) {//1. Kısa sınav notları sınıfın %20'si 80 ve 100 arasında alacak şekilde rastgele belirleniyor.
		kisaSinav1Not[i] = rand() % 21 + 80;

	}
	for (int i = sinifMevcudu * 20 / 100; i < sinifMevcudu * 50 / 100 + sinifMevcudu * 20 / 100; i++) { //1. Kısa sınav notları sınıfın %50'si 50 ile 80 arasında alacak şekilde rastgele belirleniyor.
		kisaSinav1Not[i] = rand() % (79 - 50 + 1) + 50;

	}
	for (int i = sinifMevcudu * 50 / 100 + sinifMevcudu * 20 / 100; i < sinifMevcudu; i++) {//1. kısa sınav notları sınıfın %30'u 0 ile 50 arasında alacak şekilde rastgele belirleniyor.
		kisaSinav1Not[i] = rand() % (49 - 0 + 1) + 0;

	}




	int* kisaSinav2Not; //2. kısa sınav notlarının rastgele karılmamış hali dinamik dizi olarak tanımlanıyor.
	kisaSinav2Not = new int[sinifMevcudu];

	for (int i = 0; i < sinifMevcudu * 20 / 100; i++) {//2. Kısa sınav notları sınıfın %20'si 80 ve 100 arasında alacak şekilde rastgele belirleniyor.
		kisaSinav2Not[i] = rand() % 21 + 80;
	}
	for (int i = sinifMevcudu * 20 / 100; i < sinifMevcudu * 50 / 100 + sinifMevcudu * 20 / 100; i++) {//2. Kısa sınav notları sınıfın %50'si 50 ile 80 arasında alacak şekilde rastgele belirleniyor.
		kisaSinav2Not[i] = rand() % (79 - 50 + 1) + 50;
	}
	for (int i = sinifMevcudu * 50 / 100 + sinifMevcudu * 20 / 100; i < sinifMevcudu; i++) {//2. kısa sınav notları sınıfın %30'u 0 ile 50 arasında alacak şekilde rastgele belirleniyor.
		kisaSinav2Not[i] = rand() % (49 - 0 + 1) + 0;
	}



	int* ödev1Not;//1. ödev notlarının rastgele karılammış hali dinamik dizi oalrak tanımlanıyor. 
	ödev1Not = new int[sinifMevcudu];

	for (int i = 0; i < sinifMevcudu * 20 / 100; i++) { // 1. ödev notları sınıfın %20'si 80 ve 100 arasında alacak şekilde rastgele belirleniyor. 
		ödev1Not[i] = rand() % 21 + 80;

	}
	for (int i = sinifMevcudu * 20 / 100; i < sinifMevcudu * 50 / 100 + sinifMevcudu * 20 / 100; i++) { //1. ödev notları sınıfın %50'si 50 ile 80 arasında alacak şekilde rastgele belirleniyor.
		ödev1Not[i] = rand() % (79 - 50 + 1) + 50;

	}
	for (int i = sinifMevcudu * 50 / 100 + sinifMevcudu * 20 / 100; i < sinifMevcudu; i++) {// 1. ödev notları sınıfın %30'u 0 ile 50 arasında alacak şekilde rastgele belirleniyor.
		ödev1Not[i] = rand() % (49 - 0 + 1) + 0;

	}



	int* ödev2Not; //2. ödev notlarının rastgele karılammış hali dinamik dizi oalrak tanımlanıyor. 
	ödev2Not = new int[sinifMevcudu];

	for (int i = 0; i < sinifMevcudu * 20 / 100; i++) { // 2. ödev notları sınıfın %20'si 80 ve 100 arasında alacak şekilde rastgele belirleniyor. 
		ödev2Not[i] = rand() % 21 + 80;

	}
	for (int i = sinifMevcudu * 20 / 100; i < sinifMevcudu * 50 / 100 + sinifMevcudu * 20 / 100; i++) {//2. ödev notları sınıfın %50'si 50 ile 80 arasında alacak şekilde rastgele belirleniyor.
		ödev2Not[i] = rand() % (79 - 50 + 1) + 50;

	}
	for (int i = sinifMevcudu * 50 / 100 + sinifMevcudu * 20 / 100; i < sinifMevcudu; i++) {// 2. ödev notları sınıfın %30'u 0 ile 50 arasında alacak şekilde rastgele belirleniyor.
		ödev2Not[i] = rand() % (49 - 0 + 1) + 0;

	}







	int* finalNot; //Final notlarının rastgele karılammış hali dinamik dizi oalrak tanımlanıyor. 


	finalNot = new int[sinifMevcudu];

	for (int i = 0; i < sinifMevcudu * 20 / 100; i++) { // Final notları sınıfın %20'si 80 ve 100 arasında alacak şekilde rastgele belirleniyor. 
		finalNot[i] = rand() % 21 + 80;

	}
	for (int i = sinifMevcudu * 20 / 100; i < sinifMevcudu * 50 / 100 + sinifMevcudu * 20 / 100; i++) {//Final notları sınıfın %50'si 50 ile 80 arasında alacak şekilde rastgele belirleniyor.
		finalNot[i] = rand() % (79 - 50 + 1) + 50;

	}
	for (int i = sinifMevcudu * 50 / 100 + sinifMevcudu * 20 / 100; i < sinifMevcudu; i++) { //Final notları sınıfın %30'u 0 ile 50 arasında alacak şekilde rastgele belirleniyor.
		finalNot[i] = rand() % (49 - 0 + 1) + 0;

	}







	string isimler[52] = { "Yunus","Emre","Melis","Hasan","Asiye","Okan","Veli" , "Şeyma" , "İhsan", "Mert" , "Bartu" ,"İclal","Ayla","İrem","Beyza","Simge", "Reyyan" ,"Tutku" // İsimler dizisi oluşturuluyor. 
	,"Ebrar","Hilal","Duygu","Hale","Sanem","Murat","Salih","Ersin","Hakan","Orkun","Hüseyin","Huriye","Şamil" ,"Şimal","Sema","Ayşe","Burcu",
	"Ayhan","Doğan","Çağdaş","Hayri","Tamer","Semih","Nazlı","Gökçe","Gökberk", "İlteriş", "Erbatur","Ertunga","Gazi","Tülin","Kemal","Handan" , "İsmail" };
	string soyisimler[46] = { "YILDIZ","ŞENÖDEYİCİ","TAVŞANLI","EMEKLİKOL","ALTINOLUK","KIYAK","KAYA","KÜFECİLER","TEKİN",                                //Soyisimler dizisi oluşturuluyor.
	"ALMACIOĞLU","TÜRKDOĞAN","BODUROĞLU","ÇİLDİR","ŞENTÜRK","KARABAĞ","KARADAĞ","ATİK","YILDIRIM","YENİGÜN","ONUK","GERİLMEZ","BİÇER","ULUBA"
	,"HANCIOĞLU","VURAL","ATAY","OKÇU","ZOR","SARI","ÇELİK","KARAKOYUN","AKKOYUN","AKKOÇ","SAYGIN","KOCABAŞ","KAFALAR","EKİZ","AKMAN","AKGÜN",
	"SARSILMAZ","YAVUZER","GÜNAY","AKIN","TÜRKOĞLU","SÜLEYMANOĞLU","REÇBER" };


	Ogrenci* ogr = new Ogrenci[sinifMevcudu]; // Öğrenci isimli yapı veri tipi dinamik dizi haline dönüştürülüyor. 


	srand(time(NULL));


	for (int i = 0; i < sinifMevcudu; i++) { // Sınıf mevcudu kadar isim isimler dizisinden rastgele belirleniyor.
		int random = rand() % 52;
		ogr[i].ad = isimler[random];
	}
	for (int i = 0; i < sinifMevcudu; i++) { //Sınıf mevcudu kadar soyisim soyisimler dizisinden rastgele belirleniyor. 
		int random = rand() % 46;
		ogr[i].soyad = soyisimler[random];
	}









	random_shuffle(vizeNot, vizeNot + sinifMevcudu);     // Vize notları, kısa sınav notları,ödev notları ,final notları dizilerinin elemanları rstgele karıştırılıyor.
	random_shuffle(kisaSinav1Not, kisaSinav1Not + sinifMevcudu);
	random_shuffle(kisaSinav2Not, kisaSinav2Not + sinifMevcudu);
	random_shuffle(ödev1Not, ödev1Not + sinifMevcudu);
	random_shuffle(ödev2Not, ödev2Not + sinifMevcudu);
	random_shuffle(finalNot, finalNot + sinifMevcudu);
	for (int i = 0; i < sinifMevcudu; i++) {
		ogr[i].vizeNotuKarisik = vizeNot[i]; // Karıştılan notlar öğrenci isimli yapı veri tipinin içindeki dizilerin içine aktarılıyor.
		ogr[i].kisaSinav1NotuKarisik = kisaSinav1Not[i];
		ogr[i].kisaSinav2NotuKarisik = kisaSinav2Not[i];
		ogr[i].ödev1NotuKarisik = ödev1Not[i];
		ogr[i].ödev2NotuKarisik = ödev2Not[i];
		ogr[i].finalNotuKarisik = finalNot[i];


	}



	for (int i = 0; i < sinifMevcudu; i++) { // Sınıf'ın yıl sonu ortlamaları hesaplanıyor.
		ogr[i].yilSonuOrtalamaNotu = (vizeNot[i] * vizeAgirligi * 0.01 + (ogr[i].kisaSinav1NotuKarisik + ogr[i].kisaSinav2NotuKarisik) * kisaSinavAgirligi * 0.01 + (ogr[i].ödev1NotuKarisik + ogr[i].ödev2NotuKarisik) * ödevAgirligi * 0.01) * yılİciPuaniAgirligi * 0.01 + (100 - yılİciPuaniAgirligi) * ogr[i].finalNotuKarisik * 0.01;
	}




	cout << setw(4) << "SIRA" << setw(12) << "ADI" << setw(12) << "SOYADI" << setw(18) << " VİZE NOTU" << setw(25) << "1. KISA SINAV NOTU" << setw(25) << "2. KISA SINAV NOTU"
		<< setw(18) << "1. ÖDEV NOTU" << setw(18) << "2. ÖDEV NOTU" << setw(18) << "FİNAL NOTU" << setw(18) << "YIL SONU NOTU" << setw(18) << "HARF NOTU" << endl;

	cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	double AAalanKisiSayisi = 0;  /*Her bir harf notunu kaç kişinin aldığı değişkeni tanımlanıyor.*/
	double BAalanKisiSayisi = 0;
	double BBalanKisiSayisi = 0;
	double CBalanKisiSayisi = 0;
	double CCalanKisiSayisi = 0;
	double DCalanKisiSayisi = 0;
	double DDalanKisiSayisi = 0;
	double FDalanKisiSayisi = 0;
	double FFalanKisiSayisi = 0;

	for (int i = 0; i < sinifMevcudu; i++) { //Öğrencilere rastgele olarak verilen notlar ekrana yazdırılıyor ve harf notları yıl sonu ortalamalarına göre hesaplanarak ekrana yazdırılıyor.
		// Her bir harf notundan kaç kişinin aldığı hesaplanıyor.
		if (ogr[i].yilSonuOrtalamaNotu >= 90) {

			AAalanKisiSayisi++;
			cout << setw(4) << i + 1 << setw(12) << ogr[i].ad << setw(12) << ogr[i].soyad << setw(18) << ogr[i].vizeNotuKarisik << setw(25) << ogr[i].kisaSinav1NotuKarisik << setw(25) << ogr[i].kisaSinav2NotuKarisik
				<< setw(18) << ogr[i].ödev1NotuKarisik << setw(18) << ogr[i].ödev2NotuKarisik << setw(18) << ogr[i].finalNotuKarisik << setw(18) << ogr[i].yilSonuOrtalamaNotu << setw(18) << "AA" << endl << endl;
		}
		else if (ogr[i].yilSonuOrtalamaNotu >= 80 and ogr[i].yilSonuOrtalamaNotu < 90) {
			cout << setw(4) << i + 1 << setw(12) << ogr[i].ad << setw(12) << ogr[i].soyad << setw(18) << ogr[i].vizeNotuKarisik << setw(25) << ogr[i].kisaSinav1NotuKarisik << setw(25) << ogr[i].kisaSinav2NotuKarisik
				<< setw(18) << ogr[i].ödev1NotuKarisik << setw(18) << ogr[i].ödev2NotuKarisik << setw(18) << ogr[i].finalNotuKarisik << setw(18) << ogr[i].yilSonuOrtalamaNotu << setw(18) << "BA" << endl << endl;

			BAalanKisiSayisi++;
		}
		else if (ogr[i].yilSonuOrtalamaNotu >= 75 and ogr[i].yilSonuOrtalamaNotu < 80) {
			cout << setw(4) << i + 1 << setw(12) << ogr[i].ad << setw(12) << ogr[i].soyad << setw(18) << ogr[i].vizeNotuKarisik << setw(25) << ogr[i].kisaSinav1NotuKarisik << setw(25) << ogr[i].kisaSinav2NotuKarisik
				<< setw(18) << ogr[i].ödev1NotuKarisik << setw(18) << ogr[i].ödev2NotuKarisik << setw(18) << ogr[i].finalNotuKarisik << setw(18) << ogr[i].yilSonuOrtalamaNotu << setw(18) << "BB" << endl << endl;

			BBalanKisiSayisi++;
		}
		else if (ogr[i].yilSonuOrtalamaNotu >= 70 and ogr[i].yilSonuOrtalamaNotu < 75) {
			cout << setw(4) << i + 1 << setw(12) << ogr[i].ad << setw(12) << ogr[i].soyad << setw(18) << ogr[i].vizeNotuKarisik << setw(25) << ogr[i].kisaSinav1NotuKarisik << setw(25) << ogr[i].kisaSinav2NotuKarisik
				<< setw(18) << ogr[i].ödev1NotuKarisik << setw(18) << ogr[i].ödev2NotuKarisik << setw(18) << ogr[i].finalNotuKarisik << setw(18) << ogr[i].yilSonuOrtalamaNotu << setw(18) << "BC" << endl << endl;

			CBalanKisiSayisi++;
		}

		else if (ogr[i].yilSonuOrtalamaNotu >= 60 and ogr[i].yilSonuOrtalamaNotu < 70) {
			cout << setw(4) << i + 1 << setw(12) << ogr[i].ad << setw(12) << ogr[i].soyad << setw(18) << ogr[i].vizeNotuKarisik << setw(25) << ogr[i].kisaSinav1NotuKarisik << setw(25) << ogr[i].kisaSinav2NotuKarisik
				<< setw(18) << ogr[i].ödev1NotuKarisik << setw(18) << ogr[i].ödev2NotuKarisik << setw(18) << ogr[i].finalNotuKarisik << setw(18) << ogr[i].yilSonuOrtalamaNotu << setw(18) << "CC" << endl << endl;

			CCalanKisiSayisi++;

		}
		else if (ogr[i].yilSonuOrtalamaNotu >= 50 and ogr[i].yilSonuOrtalamaNotu < 60) {
			cout << setw(4) << i + 1 << setw(12) << ogr[i].ad << setw(12) << ogr[i].soyad << setw(18) << ogr[i].vizeNotuKarisik << setw(25) << ogr[i].kisaSinav1NotuKarisik << setw(25) << ogr[i].kisaSinav2NotuKarisik
				<< setw(18) << ogr[i].ödev1NotuKarisik << setw(18) << ogr[i].ödev2NotuKarisik << setw(18) << ogr[i].finalNotuKarisik << setw(18) << ogr[i].yilSonuOrtalamaNotu << setw(18) << "DC" << endl << endl;

			DCalanKisiSayisi++;
		}
		else if (ogr[i].yilSonuOrtalamaNotu >= 40 and ogr[i].yilSonuOrtalamaNotu < 50) {
			cout << setw(4) << i + 1 << setw(12) << ogr[i].ad << setw(12) << ogr[i].soyad << setw(18) << ogr[i].vizeNotuKarisik << setw(25) << ogr[i].kisaSinav1NotuKarisik << setw(25) << ogr[i].kisaSinav2NotuKarisik
				<< setw(18) << ogr[i].ödev1NotuKarisik << setw(18) << ogr[i].ödev2NotuKarisik << setw(18) << ogr[i].finalNotuKarisik << setw(18) << ogr[i].yilSonuOrtalamaNotu << setw(18) << "DD" << endl << endl;

			DDalanKisiSayisi++;
		}
		else if (ogr[i].yilSonuOrtalamaNotu >= 30 and ogr[i].yilSonuOrtalamaNotu < 40) {
			cout << setw(4) << i + 1 << setw(12) << ogr[i].ad << setw(12) << ogr[i].soyad << setw(18) << ogr[i].vizeNotuKarisik << setw(25) << ogr[i].kisaSinav1NotuKarisik << setw(25) << ogr[i].kisaSinav2NotuKarisik
				<< setw(18) << ogr[i].ödev1NotuKarisik << setw(18) << ogr[i].ödev2NotuKarisik << setw(18) << ogr[i].finalNotuKarisik << setw(18) << ogr[i].yilSonuOrtalamaNotu << setw(18) << "FD" << endl << endl;

			FDalanKisiSayisi++;
		}
		else if (ogr[i].yilSonuOrtalamaNotu >= 0 and ogr[i].yilSonuOrtalamaNotu < 30) {
			cout << setw(4) << i + 1 << setw(12) << ogr[i].ad << setw(12) << ogr[i].soyad << setw(18) << ogr[i].vizeNotuKarisik << setw(25) << ogr[i].kisaSinav1NotuKarisik << setw(25) << ogr[i].kisaSinav2NotuKarisik
				<< setw(18) << ogr[i].ödev1NotuKarisik << setw(18) << ogr[i].ödev2NotuKarisik << setw(18) << ogr[i].finalNotuKarisik << setw(18) << ogr[i].yilSonuOrtalamaNotu << setw(18) << "FF" << endl << endl;

			FFalanKisiSayisi++;
		}





	}


	cout << setw(4) << "AA ALAN SAYISI" << setw(20) << "BA ALAN SAYISI" << setw(20) << "BB ALAN SAYISI" << setw(20) << "BC ALAN SAYISI" // Ekrana tırnak içinde yazılı olan ifadeler yazdırılıyor.
		<< setw(20) << "CC ALAN SAYISI" << setw(20) << "DC ALAN SAYISI" << setw(20) << "DD ALAN SAYISI" << setw(20) << "FF ALAN SAYISI" << endl;

	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

	cout << setw(4) << AAalanKisiSayisi << setw(20) << BAalanKisiSayisi << setw(20) << BBalanKisiSayisi << setw(20) << CBalanKisiSayisi  //Her bir harf notundan kaç kişinin aldığı ekrana yazdırılıyor.
		<< setw(20) << CCalanKisiSayisi << setw(20) << DCalanKisiSayisi << setw(20) << DDalanKisiSayisi << setw(20) << FFalanKisiSayisi << endl << endl;

	cout << setw(4) << "AA ALAN YÜZDESİ" << setw(20) << "BA ALAN YÜZDESİ" << setw(20) << "BB ALAN YÜZDESİ" << setw(20) << "BC ALAN YÜZDESİ"
		<< setw(20) << "CC ALAN YÜZDESİ" << setw(20) << "DC ALAN YÜZDESİ" << setw(20) << "DD ALAN YÜZDESİ" << setw(20) << "FF ALAN YÜZDESİ" << endl;
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

	cout << setw(4) << (AAalanKisiSayisi / (sinifMevcudu * 0.01)) << setw(20) << (BAalanKisiSayisi / (sinifMevcudu * 0.01)) << setw(20) << (BBalanKisiSayisi / (sinifMevcudu * 0.01)) << setw(20) << (CBalanKisiSayisi / (sinifMevcudu * 0.01)) //Her bir harf notundan , sınıfta yüzde kaç olduğu ekrana yazdırılıyor. 
		<< setw(20) << (CCalanKisiSayisi / (sinifMevcudu * 0.01)) << setw(20) << (DCalanKisiSayisi / (sinifMevcudu * 0.01)) << setw(20) << (DDalanKisiSayisi / (sinifMevcudu * 0.01)) << setw(20) << (FFalanKisiSayisi / (sinifMevcudu * 0.01)) << endl;

	double enKücükOrtalama = INT32_MAX;
	for (int i = 0; i < sinifMevcudu; i++) {
		if (ogr[i].yilSonuOrtalamaNotu < enKücükOrtalama) {
			enKücükOrtalama = ogr[i].yilSonuOrtalamaNotu; // En düşük yıl sonu notu hesaplanıyor.

		}

	}
	cout << endl << endl << setw(50) << "EN DÜŞÜK YIL SONU ORTALAMASI: " << setw(100) << enKücükOrtalama << endl; // En düşük yıl sonu notu ekrana yazdırılıyor.

	double enYüksekOrtalama = INT32_MIN;
	for (int i = 0; i < sinifMevcudu; i++) {
		if (ogr[i].yilSonuOrtalamaNotu > enYüksekOrtalama) {
			enYüksekOrtalama = ogr[i].yilSonuOrtalamaNotu; // En yüksek yıl sonu notu hesaplanıyor.

		}

	}
	cout << setw(50) << "EN YÜKSEK YIL SONU ORTALAMASI: " << setw(100) << enYüksekOrtalama << endl;   // En yüksek yıl sonu notu ekrana yazdırılıyor.

	double sinifYilSonuToplamNot = 0;

	for (int i = 0; i < sinifMevcudu; i++) {

		sinifYilSonuToplamNot = ogr[i].yilSonuOrtalamaNotu + sinifYilSonuToplamNot;

	}
	double sinifOrtalama = sinifYilSonuToplamNot / sinifMevcudu;
	cout << setw(50) << "Sınıfın ortalaması: " << setw(100) << sinifOrtalama << endl; // Sınıf ortalaması hesaplanarak ekrana yazdırılıyor.


	double varyansHesaplama = 0;
	for (int i = 0; i < sinifMevcudu; i++) {
		varyansHesaplama = pow((ogr[i].yilSonuOrtalamaNotu - sinifOrtalama), 2) + varyansHesaplama; //Varyans hesaplanıyor.

	}

	double standartSapma = pow((varyansHesaplama / (sinifMevcudu - 1)), 0.5); // Standart sapma hesaplanıyor.

	cout << setw(50) << "Sınıfın standart sapması: " << setw(100) << standartSapma << endl;  // SStandart sapma ekrana yazdırılıyor.


	cout << endl << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;


	return 0;
}
