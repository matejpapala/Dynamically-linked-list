#include "uzel.h"
//konstruktory, gettery, settery
Seznam::Seznam() {
	this->prvni = nullptr;
	this->posledni = nullptr;
}

Uzel::Uzel() {
	this->data = 0;
	this->nasl = nullptr;
	this->pred = nullptr;
}

Uzel::Uzel(int vstup, string nazev) {
	this->nazev = nazev;
	this->data = vstup;
	this->nasl = nullptr;
	this->pred = nullptr;
}

Uzel::Uzel(int vstup, string nazev, float cena, string typ) {
	this->nazev = nazev;
	this->data = vstup;
	this->cena = cena;
	this->typ = typ;
	this->nasl = nullptr;
	this->pred = nullptr;
}

Uzel* Uzel::getNasl() {
	return this->nasl;
}
Uzel* Uzel::getPred() {
	return this->pred;
}
int Uzel::getData() {
	return this->data;
}
string Uzel::getNazev() {
	return this->nazev;
}
float Uzel::getCena() {
	return this->cena;
}
string Uzel::getTyp() {
	return this->typ;
}
void Uzel::setNasl(Uzel* vstup) {
	this->nasl = vstup;
}
void Uzel::setPred(Uzel* vstup) {
	this->pred = vstup;
}
void Uzel::setNazev(string vstup) {
	this->nazev = vstup;
}
void Uzel::setCena(float vstup) {
	this->cena = vstup;
}
void Uzel::setTyp(string vstup) {
	this->typ = vstup;
}
//pridavani na zacatek
void Seznam::pridejNaZacatek(int vstup, string nazev, float cena, string typ) {
	Uzel* novyUzel = new Uzel(vstup, nazev, cena, typ);
	if (this->prvni == nullptr) {
		this->prvni = novyUzel;//nastaveni prvniho
	} else {
		this->prvni->setPred(novyUzel);//vkladam pred prvni
		novyUzel->setNasl(this->prvni);
		this->prvni = novyUzel;
	}
}
//pridavani na konec
void Seznam::pridejNaKonec(int vstup, string nazev, float cena, string typ) {
	Uzel* novyUzel = new Uzel(vstup, nazev, cena, typ);
	Uzel* p;
	for (p = this->prvni; p != nullptr; p = p->getNasl()) {//jdu na konec seznamu a tam naslede vlozim novy uzel
		if (p->getNasl() == nullptr) {
			this->posledni = p;
		}
	}
	this->posledni->setNasl(novyUzel);
	novyUzel->setPred(this->posledni);//nastaveni v podstate stejne jako kpridavani na zacatek ale zrcadlove
	this->posledni = novyUzel;
}


void Seznam::vypisSeznamu() const {//jednoduchy vypis pomoci smycky, jdu od prvniho az na konec a vypisuju vse po ceste
	Uzel* p;
	cout << "Data ze seznamu jsou:" << endl;
	if(this->prvni == nullptr) {
		cout << "Prazdny seznam" << endl;
		return;
	}
	for (p = this->prvni; p != nullptr; p = p->getNasl()) {
		cout << "Hodnota: " << p->getData() << " , Nazev: " << p->getNazev() << " , Cena: " << p->getCena() << " , Typ: " << p->getTyp() << endl;
	}
}

void Seznam::urceniPoctuUzlu() const {//smycka pro prochazeni, pri kazdem uzlu pocet++
	Uzel* p;
	int pocet = 0;
	for (p = this->prvni; p != nullptr; p = p->getNasl()) {
		pocet++;
	}
	cout << "Pocet uzlu v seznamu je: " << pocet << endl;
}

void Seznam::vypocetPrumeru() {//stejny princip jako u poctu uzlu akorat scitam data
	Uzel* p;
	int pocet = 0;
	float prumer, soucet = 0;
	for (p = this->prvni; p != nullptr; p = p->getNasl()) {
		soucet += p->getData();
		pocet++;
	}
	prumer = soucet / pocet;
	cout << "Prumer hodnot je: " << prumer << endl;
}

ostream &operator<<(ostream &vystup, Seznam x) {//pretizeni operatora pro vypis celeho seznamu
	x.vypisSeznamu();
	return vystup;
}

/*ostream &operator<<(ostream &vystup, Uzel x) {//pretizeni operatora pro vypis uzlu
	cout << "Data jsou: " << x.getData() << " , Nazev je: " << x.getNazev();
	return vystup;
}*/

void Seznam::ulozitDoSouboru() {//ukladam do souboru
	Uzel* p;
	fstream soubor;
	soubor.open("textovy.txt", ios::in | ios::out);//jednoduchy fix kdyz si nejsem jisty jestli potrebuju in nebo out
	for (p = this->prvni; p != nullptr; p = p->getNasl()) {//stejna smycka jako u ostatnich, kazdy zaznam napisu do souboru
		soubor << p->getData() << ";" << p->getNazev() << ";" << p->getCena() << ";" << p->getTyp() << ";" << endl;
	}
	cout << "Zapis byl uspesny" << endl;
}

void Seznam::nacistZeSouboru() {//prozatim pridava na zacatek seznamu upravit pro to aby prepisoval
	fstream soubor;
	string slovo, slovoKterePridavam;
	int j = 0, dataKteraPridavam;
	float cenaKterouPridavam;
	soubor.open("textovy.txt", ios::in | ios::out);
	while(getline(soubor, slovo, ';')){//jdu po strednik a nacitam udaj do promenne slovo
		if(j == 0) {
			dataKteraPridavam = atoi(slovo.c_str());//pouzivam tenhle prikaz jelikoz stoi mi program vzdy zhodi
			j++;
		} else if(j == 1) {
			slovoKterePridavam = slovo;
			j++;
		}else if(j == 2){
			cenaKterouPridavam = atof(slovo.c_str());
			j++;
		}else if(j == 3) {
			pridejNaZacatek(dataKteraPridavam, slovoKterePridavam, cenaKterouPridavam, slovo);
			j = 0;
		}
		
		
		
		
	}
}

void Seznam::odstranPodleDat(int dataOdstraneneho) {
	Uzel* p;
	if(this->prvni == nullptr) {//pokud neexistuje zadny uzel
		cout << "Prazdny seznam" << endl;
		return;
	}
	for (p = this->prvni; p != nullptr; p = p->getNasl()) {
		if(dataOdstraneneho == p->getData() && p->getNasl() != nullptr && p->getPred() != nullptr) {//pokud je uzel "uprostred" neboli ma za sebou i pred sebou uzel
			p->getPred()->setNasl(p->getNasl());
			p->getNasl()->setPred(p->getPred());
			delete p;
			return;
		} else if(p->getData() == dataOdstraneneho && p->getNasl() == nullptr && p->getPred() != nullptr) {//odstranit posledni
			p->getPred()->setNasl(nullptr);
			delete p;
			return;
		} else if(p->getData() == dataOdstraneneho && p->getPred() == nullptr && p->getNasl() != nullptr) {//odstranit prvni
			this->prvni = p->getNasl();
			p->getNasl()->setPred(nullptr);
			delete p;
			return;
		} else if(p->getData() == dataOdstraneneho && p->getNasl() == nullptr && p->getPred() == nullptr) {//existuje jen jeden prvek, nefunkcni
			/*this->prvni == nullptr;
			delete p;
			return;*/
		}
	}
	cout << "Prvek nenalezen" << endl;//prvek neexistuje
}

void Seznam::vyhledatPodlePolozky(int dataPodleKterychHledam) {
	Uzel *p;
	for(p = this->prvni;p != nullptr; p = p->getNasl()){//smycka projizdi vsechny uzly az po konec
		if(p->getData() == dataPodleKterychHledam) {//pokud se hledana data rovanaji s daty, ktere jsou zrovna v uzlu ve kterem jsme
			cout << "Data jsou: " << p->getData() << " ,Nazev je: " << p->getNazev() << endl;//vypiseme, zkousel jsem i pres return, ale uprimne jsem se ztratil v pointerech a program akorat rozbil
		}
	}
}

void Seznam::sortPodleDat() {
	//vzdavam to
}

void Seznam::editDat(int coChciEditovat, int dataUzluKteryChciEditovat) {
	Uzel *p;
	string novyNazev, novyVstup;
	float novaCena;
	for(p = this->prvni;p != nullptr; p = p->getNasl()){//smycka projizdi vsechny uzly az po konec
		if(dataUzluKteryChciEditovat == p->getData()) {//podminka pro hledani spravneho uzlu
			if(coChciEditovat == 1) {//urcuju co se bude editovat
				cout << "Napiste novy nazev: ";
				cin >> novyNazev;
				p->setNazev(novyNazev);//setter pro prepsani
				return;
			} else if(coChciEditovat == 2) {
				cout << "Napiste novou cenu: ";
				cin >> novaCena;
				p->setCena(novaCena);
				return;
			} else if(coChciEditovat == 3) {
				cout << "Napiste novy typ: ";
				cin >> novyVstup;
				p->setTyp(novyVstup);
				return;
			} else {
				cout << "Spatny vstup";//v pripade jineho cisla nez je urceno
				return;
			}
		}
	}
}
