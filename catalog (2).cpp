#include <windows.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {

    WIN32_FIND_DATA FindFileData;
	HANDLE hf;
	hf=FindFirstFile("C:\\Users\\lexa3\\OneDrive\\Рабочий стол\\git-playground-master\\nice-project\\OP_LR1_IP96_Horobets_Zamrii\\Test\\*txt", &FindFileData);
	if (hf!=INVALID_HANDLE_VALUE)
	{
		do
		{
			cout << FindFileData.cFileName << endl;
		}
		while (FindNextFile(hf,&FindFileData)!=0);
		FindClose(hf);
		
  return 0;
}
}
