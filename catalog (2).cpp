#include <windows.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
  string Path = "C:\\kdm\\"; //���� � �������� � 2 ����������
  WIN32_FIND_DATA FindFileData;
  HANDLE hf;
  hf = FindFirstFile("C:\\kdm\\*.txt", &FindFileData); //�������(����������)
  if (hf != INVALID_HANDLE_VALUE) { //���� �������� �����
    do {
      Path += FindFileData.cFileName;
      cout << FindFileData.cFileName << ":" << endl; //����� ����� findfiledata ��� �����
      ifstream ifs(Path.c_str()); //����� ������ � c_str �.�. � ������ �����, �.�. ��� ������ �� ������ �� ���������
      string s;
      while (!ifs.eof()) { //������ ����
        ifs >> s;
        cout << s << endl;
      }
      ifs.close();
      cout << endl;
      Path = "C:\\kdm\\";
    } while (FindNextFile(hf,&FindFileData) != 0); //���� ���� ��� ��������
    FindClose(hf); //��������� �������
  }
  return 0;
}
