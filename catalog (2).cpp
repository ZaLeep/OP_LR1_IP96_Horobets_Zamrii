#include <windows.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {

    WIN32_FIND_DATA FindFileData;
	HANDLE hf;
	string path;
	hf=FindFirstFile("D:\\Sanya_sdelay_fiziku\\*.txt", &FindFileData);
	if (hf!=INVALID_HANDLE_VALUE)
	{
		do
		{
			cout << FindFileData.cFileName << endl;
		}
		while (FindNextFile(hf,&FindFileData)!=0);
		FindClose(hf);
	}
	return 0;
}
