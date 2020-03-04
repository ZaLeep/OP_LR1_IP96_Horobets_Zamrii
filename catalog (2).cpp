#include <windows.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
  string Path = "C:\\kdm\\"; //путь к каталогу с 2 бэкслешами
  WIN32_FIND_DATA FindFileData;
  HANDLE hf;
  hf = FindFirstFile("C:\\kdm\\*.txt", &FindFileData); //хэндлер(дескриптор)
  if (hf != INVALID_HANDLE_VALUE) { //если получили хэндл
    do {
      Path += FindFileData.cFileName;
      cout << FindFileData.cFileName << ":" << endl; //берем через findfiledata имя файла
      ifstream ifs(Path.c_str()); //юзаем первод в c_str т.е. в массив чаров, т.к. оно ссылку на стринг не принимает
      string s;
      while (!ifs.eof()) { //читаем файл
        ifs >> s;
        cout << s << endl;
      }
      ifs.close();
      cout << endl;
      Path = "C:\\kdm\\";
    } while (FindNextFile(hf,&FindFileData) != 0); //пока есть еще элементы
    FindClose(hf); //закрываем хэндлер
  }
  return 0;
}
