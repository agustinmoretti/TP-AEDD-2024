#include <iostream>
// INCLUIR ARCHIVOS CABECERA ACA
#include "bienvenida.h"
#include "visual.h"
void logo()
{
	cout << "---------------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "|                                                                                                                                     |" << endl;
	cout << "| 333333333333  66666666666     9999     9999   00   111               *******  %%%   %%%         A        PPPPPPPPPPP       A        |" << endl;
	cout << "| 333333333333  6666     666    999999   9999  0  0    11              ****  **  %%% %%%         AAA       PPPP     PPP     AAA       |" << endl;
	cout << "|     3333      6666     666    9999 999 9999   00     11              ********   %%%%%         AA AA      PPPP     PPP    AA AA      |" << endl;
	cout << "|     3333      66666666666     9999  9999999          11     222222   *********   %%%         AA   AA     PPPPPPPPPPP    AA   AA     |" << endl;
	cout << "|     3333      6666            9999   999999          11              ****   ***  %%%        AAAAAAAAA    PPPP          AAAAAAAAA    |" << endl;
	cout << "|     3333      6666            9999    99999          11              ****   ***  %%%       AAAA   AAAA   PPPP         AAAA   AAAA   |" << endl;
	cout << "|     3333      6666            9999     9999        111111            *********   %%%      AAAA     AAAA  PPPP        AAAA     AAAA  |" << endl;
	cout << "|                                                                                                                                     |" << endl;
	cout << "|                                                             000000                                                                  |" << endl;
	cout << "|              2222222222       0000000000                  0000000000                  222222            444444                      |" << endl;
	cout << "|              2222222222       0000000000                 000000000000               2222222222        4444444444                    |" << endl;
	cout << "|                  2222             0000                   000000000000              222      222      444      444                   |" << endl;
	cout << "|                  2222             0000                    0000000000               222      222      444      444                   |" << endl;
	cout << "|                  2222             0000                     \\000000/                222      222      444      444                   |" << endl;
	cout << "|             222  2222  **    000  0000  **                  \\ || /                  2222222222  **    4444444444  **                |" << endl;
	cout << "|              2222222   **     0000000   **                   \\||/                     222222    **      444444    **                |" << endl;
	cout << "|                                                               °°                                                                    |" << endl;
	cout << "|                                                            |";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	cout << "^^^^^^";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << "|                                                                 |" << endl;
	cout << "|                                                            --------                                                                 |" << endl;
	cout << "---------------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "{                                                                                                                                     }" << endl;
	cout << "{                                                      MAILS DE LOS INTEGRANTES:                                                      }" << endl;
	cout << "{                                       Pedro Martinez (ISI B): pedromartinez966440@gmail.com                                         }" << endl;
	cout << "{                                       Agustin Ignacio Moretti (ISI E): furaribi.a@gmail.com                                         }" << endl;
	cout << "{                                                   Proximo integrante en progreso.                                                   }" << endl;
	cout << "{                                                                                                                                     }" << endl;
	cout << "{                                                     Pulse ENTER para continuar.                                                     }" << endl;
	cout << "{                                                                                                                                     }" << endl;
	cout << "{                                                        Version 2.0.8 - 2024.                                                         }" << endl;
	cout << "{                                                                                                                                     }" << endl;
	cout << "{~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~}" << endl;
}

void bienvenida()
{
	system("mode con: cols=136 lines=40");
	logo();
	
	if (GetAsyncKeyState(VK_RETURN))
	{
		/*CONTINUACION DEL PROGRAMA*/
	}
	system("pause");
}

