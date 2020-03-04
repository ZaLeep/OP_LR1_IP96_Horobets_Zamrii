#include <windows.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
  ifstream ifs;
  ofstream ofs;
  ofs.open("D:\\Lexa_sdelal_fiziku", ofstream::app);
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
		  	int k=0;
		  	string s;
		  	getline(ifs,s);
		  	for (int i = 0; i < n; i++){
				getline(ifs, s);
				for (int i=0; i<s.find(","); i++){
					ofs<<s[i];	
				}
				for  (int i=s.find(",")+1; i<s.size(); i++){
					if (s[i]==':'){
						if ((int)s[i-1]>(int)s[i+1])k+=3;
						else if((int)s[i-1]==(int)s[i+1])k++;
					}
				}
				ofs<<" "<<k<<endl;
			}
		  path = "D:\\Sanya_sdelay_fiziku\\";
		}
		while (FindNextFile(hf,&FindFileData) != 0);
		FindClose(hf);
	}
	return 0;
}
