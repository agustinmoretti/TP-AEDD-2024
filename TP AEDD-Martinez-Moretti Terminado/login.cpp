#include <windows.h>
#include <iostream>
// INCLUIR ARCHIVOS CABECERA ACA
#include "menu.h"
#include "submenu_gen_competencia.h"
#include "login.h"
#include "visual.h"

bool esCapicua(int num)
{
	int original = num;
	int invertido = 0;
	while (num > 0)
	{
		invertido = invertido * 10 + num % 10;
		num /= 10;
	}
	return original == invertido;
}
int passwordgenerada(int user)
{
	int N, ultimosTres;
	N = user;
	N = (user % 10) + ((user / 100) % 10) * 10 + (user / 10000) * 100;
	int capicua = N + 1;
	while (!esCapicua(capicua))
	{
		capicua++;
	}
	
	ultimosTres = (user % 1000);
	
	int year = 2024;                       // Año actual
	return (year * capicua) + ultimosTres; // Fórmula para generar la contraseña
}
bool login(archivoCompetencia &file_competencia)
{
	
	int user, passwordUser;
	bool correcto1 = false, ret = false;
	
	cout << "-----------------------------------" << endl;
	cout << "             LOGIN                 " << endl;
	cout << "-----------------------------------" << endl;
	// Ingreso de Usuario
	do
	{
		cout << "Ingrese su Numero de Legajo: (5 digitos): ";
		cin >> user;
		if (user < 10000 || user > 99999)
		{
			cout << "ID invalida. Pruebe con un numero de 5 cifras." << endl;
		}
		
		correcto1 = (user >= 10000 && user <= 99999);
		
	} while (!correcto1);
	
	file_competencia.legajo = user;
	
	cout << "-----------------------------------" << endl;
	
	int password = passwordgenerada(user);
	int intentos = 3;
	bool correcto2 = false;
	
	//cout << "Password Generada -- > " << password << endl; --> Solo para probar
	cout << "---------------------------------------" << endl;
	
	do
	{
		
		cout << "Ingrese su password (Combinacion de Numeros enteros) : ";
		cin >> passwordUser;
		
		if (passwordUser != password)
		{
			cout << "Password Incorrecta" << endl;
			Sleep(1000);
			intentos--;
			cout << "Le quedan " << intentos << " intentos restantes ..." << endl;
			system("cls");
		}
		if (passwordUser == password)
			correcto2 = true;
		
	} while (!correcto2 && intentos > 0);
	
	system("cls");
	
	ret = correcto1 && correcto2;
	if (ret)
	{
		cout << "¡Ingresado al Sistema con Exito!" << endl;
		Sleep(1000);
		system("cls");
		barradecarga(1000, 100);
	}
	
	system("cls");
	
	return ret;
}
