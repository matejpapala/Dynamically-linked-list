#ifndef UZEL_H
#define UZEL_H

#include <iostream>
#include <fstream>
using namespace std;


class Uzel {
private:
	int data;
	string nazev;
	float cena;
	string typ;
	Uzel* pred;
	Uzel* nasl;
public:
	Uzel();
	Uzel(int vstup, string nazev);
	Uzel(int vstup, string nazev, float cena, string typ);
	Uzel* getNasl();
	Uzel* getPred();
	int getData();
	string getNazev();
	string getTyp();
	float getCena();
	//friend ostream &operator<<(ostream &vystup, Uzel x);
	void setNasl(Uzel* vstup);
	void setPred(Uzel* vstup);
	void setNazev(string vstup);
	void setCena(float vstup);
	void setTyp(string vstup);
};

class Seznam {
private:
	Uzel* prvni;
	Uzel* posledni;
public:
	Seznam();
	void pridejNaZacatek(int vstup, string nazev, float cena, string typ);
	void vypisSeznamu() const;
	void urceniPoctuUzlu() const;
	void pridejNaKonec(int vstup, string nazev, float cena, string typ);
	void vypocetPrumeru();
	friend ostream &operator<<(ostream &vystup, Seznam x);
	void ulozitDoSouboru();
	void nacistZeSouboru();
	void odstranPodleDat(int dataOdstraneneho);
	void vyhledatPodlePolozky(int dataPodleKterychHledam);
	void sortPodleDat();
	void editDat(int coChciEditovat, int dataUzluKteryChciEditovat);
};

#endif

//TODO: 
