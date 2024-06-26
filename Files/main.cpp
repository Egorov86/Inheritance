//Files
#define _CRT_SECURE_NO_WARNINGS  // чтобы старые функции работали.
#include <windows.h>
#include<iostream>
#include<fstream>
#include<ctime>
using std::cin;
using std::cout;
using std::endl;
//using std::fout;

//#define WRITE_TO_FILE
//#define READ_FROM_FILE

void main()
{
	setlocale(LC_ALL, "");

#ifdef WRITE_TO_FILE
	//1) НУЖНО СОЗДАТЬ ПОТОК:
	std::ofstream fout;
	//2) ОТКРЫВАЕМ ПОТОК
	fout.open("File.txt", std::ios_base::app); // std::ios_base::app дописать в конец файла
	//3) ПИШЕМ В ПОТОК
	fout << "HelloWorld" << endl;
	time_t now = time(NULL);
	fout << ctime(&now)<< endl;
	//fout << ctime(&now) << endl; // Выводим время и 
	//4) ЗАКРЫВАЕМ ПОТОК
	fout.close();
	// ПОТОКИ КАК ХОЛОДИЛЬНИК, ЕСЛИ ОНИ БЫДИ 
	// ОТКРЫТЫ, ИХ ОБЯЗАТЕЛЬНО НУЖНО ЗАКРЫТЬ
	system("notepad File.txt");
#endif // WRITE_TO_FILE
#ifdef READ_FROM_FILE
	// 1) Cоздаём и открываем поток:
	std::ifstream fin("File.txt");
	if (fin.is_open())
	{
		//Здесь будем читать файл:
		const int SIZE = 256; // размер буффера
		char buffer[SIZE]{};   //буфер

		while (!fin.eof())    // NOT EndOfFile, если не конец
		{
			//fin >> buffer;            // читают до пробела
			fin.getline(buffer, SIZE); //читают строку с пробелами 
			cout << buffer << endl;
		}

		fin.close();
	}
	else
	{
		std::cerr << " Error: File not found" << endl;
	}


#endif // READ_FROM_FILE


}