// В одну из программ, написанных на предыдущих шагах , вставить методы, изменяющие состояние потоков.

#include <iostream>
#include <fstream>
#include <ctype.h>
using namespace std;

int main()
{
    char fname[15], c;
    cout << "Enter input file name: ";
    cin >>fname;
    // Открытие входного файла
    ifstream ifs(fname);
    if(!ifs) // Проверяем поток
    {
        cout<< "Input file not open" << fname;
    }
    cout << "Enter the name of the output file: ";
    cin >>fname;
    // Открытие выходного файла
    ofstream  ofs(fname);
    if(!ofs) // Проверяем поток
    {
        cout<< "Output file not open" << fname;
    }
    // Пока не произойдет ошибки, делаем:
    while (ifs && ofs)
    {
        ifs.get(c); // Чтение символа из файла
        // Переводим прочитанный символ в верхний регистр
        c = toupper(c);
        ofs.put(c); // Запись символа в файл
        cout << '.';
    }

    // Проверяем, что файл полностью считан
    if (ifs.eof())
    {
        cout << endl << "The input file is fully read." << endl;
    }
    // Записываем все буферизованные данные в выходной файл
    ofs.flush();
    // Закрываем файлы
    ifs.close();
    ofs.close();

    cout << endl << "The output file is an uppercase copy of the input file." << endl;
    return 0;
}
