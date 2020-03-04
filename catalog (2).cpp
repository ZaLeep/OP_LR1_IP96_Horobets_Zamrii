#include <windows.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
  ifstream ifs;
  WIN32_FIND_DATA FindFileData;
	HANDLE hf;
	string path = "D:\\Sanya_sdelay_fiziku\\";
	hf = FindFirstFile("D:\\Sanya_sdelay_fiziku\\*.txt", &FindFileData);
	if (hf!=INVALID_HANDLE_VALUE)
	{
		do
		{
			path += FindFileData.cFileName;
		  ifs.open(path.c_str());
		  int n;
		  ifs >> n;
		  ifs.getline();
		  for (int i = 0; i < n; i++)
		  path = "D:\\Sanya_sdelay_fiziku\\";
		}
		while (FindNextFile(hf,&FindFileData) != 0);
		FindClose(hf);
	}
	return 0;
}
