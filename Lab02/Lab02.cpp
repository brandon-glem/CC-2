#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int sumador_mod(int num1, int num2, int mod) {
    int res = ((num1 % mod) + (num2 % mod)) % mod;
    return res;
}

int restador_mod(int num1, int num2, int mod) {
    int res = ((num1 % mod) - (num2 % mod)) % mod;
    return res;
}

int multiplicador_mod(int num1, int num2, int mod) {
    int res = ((num1 % mod) * (num2 % mod)) % mod;
    return res;
}

int euclides_ext(int a, int b, int* x, int* y) {
	if (a == 0) {
		*x = 0;
		*y = 1;
		return b;
	}

	int x1, y1;
	int gcd = euclides_ext(b % a, a, &x1, &y1);

	*x = y1 - (b / a) * x1;
	*y = x1;

	return gcd;
}

int inversa(int a, int m) {
	int x, y;
	int g = euclides_ext(a, m, &x, &y);
	if (g != 1)
		return false;

	else {
		int res = (x % (m + m)) % m;
		if (res < 0)
			res = res + m;
		return res;
	}
}


class cifrador {
private:
	int clav_publica;
	int clav_privada;
	int mod = 256;

public:
	cifrador(int numero1, int numero2) {
		clav_privada = numero1;
		clav_publica = numero2;
	}
	void encriptar(string archivo) {
		ofstream salida("encriptado.txt");

		ifstream ingreso;
		ingreso.open(archivo);

		string oracion;
		string cif;

		while (!ingreso.eof()) {	

			getline(ingreso, oracion);
			for (int i = 0; i < oracion.size(); i++) {
				//cout << oracion[i] << " => " << (int)oracion[i] << " => ";
				int t = multiplicador_mod((int)oracion[i], clav_privada, mod);
				//cout << t << " => "<< (char*)(&t)<<endl;
				cif = cif + (char*)(&t);
			}
			int t = 13;
			t = multiplicador_mod(t, clav_privada, mod);
			cif = cif + (char*)(&t);
		}
		//salida << cif << '\n';
		salida << cif;
		ingreso.close();
		salida.close();
	}

	void desencriptar(string archivo) {
		ofstream salida("desencriptado.txt");

		ifstream ingreso;
		ingreso.open(archivo);

		while (!ingreso.eof()) {
			string oracion;
			string cif;

			getline(ingreso, oracion);
			for (int i = 0; i < oracion.size(); i++) {
				//cout << oracion[i] << " => " << ((int)oracion[i] + 256) << " => ";
				int t = multiplicador_mod(((int)oracion[i] + 256), clav_publica, mod);
				//cout << t << " => " << (char*)(&t) << endl;
				cif = cif + (char*)(&t);
			}
			salida << cif;
		}
		ingreso.close();
		salida.close();
	}
};


int main(){
	/*
	int opcion, num1, num2, mod;
	cout << "1 => Suma Modular" << endl << "2 => Resta Modular" << endl << "3 => Multiplicacion Modular" << endl << "4 => Inverso Modular" << endl;
	cout << endl << "Ingrese Opcion: ";
	cin >> opcion;

	if (opcion == 1) {
		cout << "Primer Numero: ";
		cin >> num1;
		cout << "Segundo Numero: ";
		cin >> num2;
		cout << "Modulo: ";
		cin >> mod;
		int res = sumador_mod(num1, num2, mod);
		cout << "La respuesta es: " << res << endl;
	}

	if (opcion == 2) {
		cout << "Primer Numero: ";
		cin >> num1;
		cout << "Segundo Numero: ";
		cin >> num2;
		cout << "Modulo: ";
		cin >> mod;
		int res = restador_mod(num1, num2, mod);
		cout << "La respuesta es: " << res << endl;
	}

	if (opcion == 3) {
		cout << "Primer Numero: ";
		cin >> num1;
		cout << "Segundo Numero: ";
		cin >> num2;
		cout << "Modulo: ";
		cin >> mod;
		int res = multiplicador_mod(num1, num2, mod);
		cout << "La respuesta es: " << res << endl;
	}

	if (opcion == 4) {
		cout << "Numero: ";
		cin >> num1;
		cout << "Modulo: ";
		cin >> mod;
		int res = inversa(num1, mod);
		cout << "La respuesta es: " << res << endl;
	}
	else
		cout << "Opcion Incorrecta" << endl;
	*/

	
	int num, inver, option;
	cout << "ENCRIPTADOR" << endl;
	cout << "1 Encriptar" << endl << "2 Desencriptar" << endl;
	cout << endl << "Ingrese Opcion: ";
	cin >> option;
	if (option == 1) {
		cout << "ingrese un numero impar desde 2 a 255: ";
		cin >> num;
		inver = inversa(num, 256);
		while (inver == false) {
			cout << "Su numero no tiene inversa" << endl;
			cout << "ingrese un numero IMPAR desde 2 a 255: ";
			cin >> num;
			inver = inversa(num, 256);
		}
		cout << "Su clave privada es: " << num << endl << "Su clave publica es: " << inver << endl;
		cifrador a(num, inver);
		a.encriptar("origen.txt");
		cout << "Su archivo fue encriptado satisfactoriamente." << endl;
	}

	else if (option == 2) {
		int publica;
		cout << "Ingrese su clave publica: ";
		cin >> publica;
		cifrador a(0, publica);
		a.desencriptar("encriptado.txt");
		cout << "Su archivo fue desencriptado satisfactoriamente." << endl;
	}
	else
		cout << "OPCION INCORRECTA." << endl;
	//*/
	return 0;
}
