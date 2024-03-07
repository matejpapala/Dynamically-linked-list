#include "uzel.h"

int main() {
	Seznam mujSeznam;
	int choice, vstup, dataProEdit;
	string nazev, typ;
	float cena;
	do{
		cout << "1. Pridat hodnotu" << endl;
		cout << "2. Vypsat seznam" << endl;
		cout << "3. Urceni poctu uzlu" << endl;
		cout << "4. Pridani hodnoty na konec seznamu" << endl;
		cout << "5. Prumer hodnot" << endl;
		cout << "6. Ulozit do souboru" << endl;
		cout << "7. Nacist ze souboru" << endl;
		cout << "8. Odstranit jeden zapis" << endl;
		cout << "9. Vyhledat polozku podle dat" << endl;
		cout << "0. Konec" << endl;
		cout << "Vyberte moznost: ";
		cin >> choice;
		
		switch (choice) {
		case 1:
			system("cls");
			cout << "Zadejte hodnotu: ";
			cin >> vstup;
			cout << "Zadejte nazev: ";
			cin >> nazev;
			cout << "Zadejte cenu: ";
			cin >> cena;
			cout << "Zadejte typ: ";
			cin >> typ;
			mujSeznam.pridejNaZacatek(vstup, nazev, cena, typ);
			break;
		case 2:
			system("cls");
			//mujSeznam.vypisSeznamu();
			cout << mujSeznam;
			break;
		case 3:
			system("cls");
			mujSeznam.urceniPoctuUzlu();
			break;
		case 4:
			system("cls");
			cout << "Zadejte hodnotu: ";
			cin >> vstup;
			cout << "Zadejte nazev: ";
			cin >> nazev;
			cout << "Zadejte cenu: ";
			cin >> cena;
			cout << "Zadejte typ: ";
			cin >> typ;
			mujSeznam.pridejNaKonec(vstup, nazev, cena ,typ);
			break;
		case 5:
			system("cls");
			mujSeznam.vypocetPrumeru();
			break;
		case 6:
			system("cls");
			mujSeznam.ulozitDoSouboru();
			break;
		case 7:
			system("cls");
			mujSeznam.nacistZeSouboru();
			break;
		case 8:
			system("cls");
			cout << "Napiste data, ktere chcete odstranit: ";
			cin >> vstup;
			mujSeznam.odstranPodleDat(vstup);
			break;
		case 9:
			system("cls");
			cout << "Napiste data, ktere chcete najit: ";
			cin >> vstup;
			mujSeznam.vyhledatPodlePolozky(vstup);
			break;
		case 10:
			system("cls");
			cout << "Napiste co chcete editovat: " << endl;
			cout << "1. Nazev" << endl << "2. Cena" << endl << "3.Typ" << endl;
			cin >> vstup;
			cout << "Napiste data uzlu, ktery chcete editovat: ";
			cin >> dataProEdit;
			mujSeznam.editDat(vstup, dataProEdit);
		default:
			break;
		}
	}while(choice != 0);
	return 0;
}
