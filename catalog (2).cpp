#include <windows.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
  ifstream ifs;
  ofstream ofs;
  ofs.open("C:\\Users\\home\\Documents\\GitHub\\OP_LR1_IP96_Horobets_Zamrii\\Lexa_sdelal_fiziku.csv");
  WIN32_FIND_DATA FindFileData;
	HANDLE hf;
	string path = "C:\\Users\\home\\Documents\\GitHub\\OP_LR1_IP96_Horobets_Zamrii\\Sanya_sdelay_fiziku\\";
	hf = FindFirstFile("C:\\Users\\home\\Documents\\GitHub\\OP_LR1_IP96_Horobets_Zamrii\\Sanya_sdelay_fiziku\\*.csv", &FindFileData);
	if (hf!=INVALID_HANDLE_VALUE)
	{
		do
		{
			path += FindFileData.cFileName;
		 	ifs.open(path.c_str());
			int n;
		  	ifs >> n;
		  	string s;
		  	getline(ifs,s);
		  	for (int i = 0; i < n; i++){
		  		int k=0;
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
				ofs<<";"<<k<<endl;
			}
			ifs.close();
			path = "C:\\Users\\home\\Documents\\GitHub\\OP_LR1_IP96_Horobets_Zamrii\\Sanya_sdelay_fiziku\\";
		}
		while (FindNextFile(hf,&FindFileData) != 0);
		FindClose(hf);
	}
	ofs.close();
	return 0;
}
