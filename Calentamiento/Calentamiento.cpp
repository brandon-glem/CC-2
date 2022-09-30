#include <iostream>
#include <string.h>
#include <cmath>

using namespace std;

float main() {

	
	int comunes[12] = { 0,3,3,6,1,4,6,2,5,0,3,5 };
	int bisiestos[12] = { 0,3,4,0,2,5,0,3,6,1,4,6 };

	int normal[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int bi[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	int year;
	
	int mes;

	cout << "ingrese el year: ";
	cin >> year;
	cout << endl << "ingrse el mes: ";
	cin >> mes;
	cout << endl;

	int inicio;

	bool biciesto;
	if (year % 4 == 0) {
		if ((year % 100 == 0)) {
			if (year % 400 == 0) {
				biciesto = true;
			}
			else
				biciesto = false;
		}
		else
			biciesto = true;
	}
	else
		biciesto = false;

	year--;
	cout << "CALENDARIO: " << endl << "D" << '\t' << "L" << '\t' << "M" << '\t' << "X" << '\t' << "J" << '\t' << "V" << '\t' << "S" << endl;

	if (biciesto == true) {
		inicio = 1 + bisiestos[mes - 1] + (year % 4) * 5 + (year % 100) * 4 + (year % 400) * 6;
		inicio = inicio % 7;

		for (int i = 0, j = 1, corredor = 0; j <= bi[mes - 1]; ) {
			if (i < inicio) {
				cout << " " << '\t';
				i++;
			}
			else {
				cout << j << '\t';
				j++;
			}
			
			if (corredor >= inicio)
				corredor++;
			else
				corredor++;

			if (corredor == 7) {
				cout << endl;
				corredor = 0;
			}
		}
	}
	else {
		inicio = 1 + comunes[mes - 1] + (year % 4) * 5 + (year % 100) * 4 + (year % 400) * 6;
		inicio = inicio % 7;

		for (int i = 0, j = 1, corredor = 0; j <= normal[mes - 1]; ) {
			if (i < inicio) {
				cout << " " << '\t';
				i++;
			}
			else {
				cout << j << '\t';
				j++;
			}

			if (corredor >= inicio)
				corredor++;
			else
				corredor++;

			if (corredor == 7) {
				cout << endl;
				corredor = 0;
			}
		}
	}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/*
	int billetes[8] = { 200,100,50,20,10,5,2,1 };
	float monedas[3] = { 0.5,0.2,0.1 };

	float dinero;
	cout << endl << "ingrese la cantidad a dar vuelto: ";
	cin >> dinero;

	cout << endl << "El vuelto es:" << endl;
	dinero += 0.01;
	for (int i = 0; i < 8; i++) {
		int vuelto;
		vuelto = dinero / billetes[i];
		dinero = dinero - (vuelto * billetes[i]);
		if (i < 5) {
			cout << vuelto << " billetes de " << billetes[i] << " soles" << endl;
		}
		else {
			cout << vuelto << " monedas de " << billetes[i] << " soles" << endl;
		}
	}
	
	for (int i = 0; i < 3; i++) {
		int vuelto = dinero / monedas[i];
		dinero = dinero - (vuelto * monedas[i]);
		cout << vuelto << " monedas de " << billetes[2+i] << " centimos" << endl;
	}
	*/
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	/*
	int numero;
	cout << endl << "ingrse numero: ";
	cin >> numero;
	cout << endl;

	int uni = numero % 10;		numero /= 10;
	int dec = numero % 10;		numero /= 10;
	int cen = numero % 10;		numero /= 10;
	int unmil = numero % 10;	numero /= 10;
	int decmil = numero % 10;	numero /= 10;
	int cenmil = numero % 10;	numero /= 10;
	int unmillo = numero % 10;

	string unidades[9] = { "uno","dos","tres","cuatro","cinco","seis","siete","ocho","nueve" };
	string millon[2] = { "millon","millones" };
	string mil = "mil";
	string cente[5] = { "cien","ciento","quinientos","setecientos","novecientos" };
	string decen[10] = { "diez","once","doce","trece","catorce","quince","dieciseis","siecisiete","dieciocho","diecinueve" };
	string decimas[8] = { "veint","treinta","cuarenta","cincuenta","sesenta","setenta","ochenta","noventa" };
	string especial = "un";

	if(unmillo > 0){
		if (unmillo == 1)
			cout << especial << " " << millon[0] << " ";
		else
			cout << unidades[unmillo - 1] << " " << millon[1] << " ";
	}

	if (cenmil > 0) {
		if (cenmil == 1 && decmil == 0 && unmil == 0)
			cout << cente[0] << " ";
		else if (cenmil == 1)
			cout << cente[1] << " ";
		else if (cenmil != 5 && cenmil != 7 && cenmil != 9)
			cout << unidades[cenmil - 1] + cente[1] + "s" << " ";
		else if (cenmil == 5)
			cout << cente[2] << " ";
		else if (cenmil == 7)
			cout << cente[3] << " ";
		else
			cout << cente[4] << " ";
		
		if (decmil == 0 && unmil == 0)
			cout << mil << " ";
	}

	if (decmil > 0) {
		if (decmil == 1 && unmil == 0)
			cout << decen[0] << " mil ";
		else if (decmil == 1 && unmil != 0)
			cout << decen[unmil] << " mil ";
		else if (decmil == 2 && unmil == 0)
			cout << decimas[0] + "e" << " mil ";
		else if (decmil == 2 && unmil != 0)
			cout << decimas[0] + "i" + unidades[unmil - 1] << " mil ";
		else if (decmil > 2 && unmil == 0)
			cout << decimas[decmil - 2] << " mil ";
		else
			cout << decimas[decmil - 2] + " y ";
	}
	
	if (unmil > 0) {
		if (cenmil == 0 && decmil == 0 && unmil == 1)
			cout << "mil ";
		else if (decmil == 0 && unmil == 1)
			cout << especial << " mil ";
		else if (decmil == 0 && unmil > 1)
			cout << unidades[unmil - 1] << " mil ";
		else if (decmil > 2 && unmil == 1)
			cout << especial << " mil ";
		else if (decmil > 2)
			cout << unidades[unmil - 1] << " mil ";
	}

	if (cen > 0) {
		if (cen == 1 && dec == 0 && uni == 0)
			cout << cente[0] << " ";
		else if (cen == 1)
			cout << cente[1] << " ";
		else if (cen != 5 && cen != 7 && cen != 9)
			cout << unidades[cen - 1] + cente[1] + "s" << " ";
		else if (cen == 5)
			cout << cente[2] << " ";
		else if (cen == 7)
			cout << cente[3] << " ";
		else
			cout << cente[4] << " ";
	}
	
	if (dec > 0) {
		if (dec == 1 && uni == 0)
			cout << decen[0] << " ";
		else if (dec == 1 && uni != 0)
			cout << decen[uni];
		else if (dec == 2 && uni == 0)
			cout << decimas[0] + "e";
		else if (dec == 2 && uni != 0)
			cout << decimas[0] + "i" + unidades[uni - 1];
		else if (dec > 2 && uni == 0)
			cout << decimas[dec - 2];
		else
			cout << decimas[dec - 2] + " y ";
	}
	
	if (uni > 0 && dec != 1 && dec != 2)
		cout << unidades[uni - 1];
	*/
	return 0;
}