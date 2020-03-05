#include <windows.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
  ifstream ifs;
  ofstream ofs;
  ofs.open("C:\\Users\\lexa3\\OneDrive\\Рабочий стол\\git-playground-master\\nice-project\\OP_LR1_IP96_Horobets_Zamrii\\Lexa_sdelal_fiziku.csv");
  WIN32_FIND_DATA FindFileData;
	HANDLE hf;
	string path = "C:\\Users\\lexa3\\OneDrive\\Рабочий стол\\git-playground-master\\nice-project\\OP_LR1_IP96_Horobets_Zamrii\\Sanya_sdelay_fiziku\\";
	hf = FindFirstFile("C:\\Users\\lexa3\\OneDrive\\Рабочий стол\\git-playground-master\\nice-project\\OP_LR1_IP96_Horobets_Zamrii\\Sanya_sdelay_fiziku\\*.csv", &FindFileData);
	int sum = 0;
	if (hf!=INVALID_HANDLE_VALUE)
	{
		do
		{
			path += FindFileData.cFileName;
		 	ifs.open(path.c_str());
			int n;
		  	ifs >> n;
		  	sum += n;
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
				ofs << ";" << k << endl;
			}
			ifs.close();
			path = "C:\\Users\\lexa3\\OneDrive\\Рабочий стол\\git-playground-master\\nice-project\\OP_LR1_IP96_Horobets_Zamrii\\Sanya_sdelay_fiziku\\";
		}
		while (FindNextFile(hf,&FindFileData) != 0);
		FindClose(hf);
	}
	ofs.close();
	
	ifs.open("C:\\Users\\lexa3\\OneDrive\\Рабочий стол\\git-playground-master\\nice-project\\OP_LR1_IP96_Horobets_Zamrii\\Lexa_sdelal_fiziku.csv");
	string* Name = new string[sum];
	int* Score = new int[sum];
	string s;
	getline(ifs, s);
	for(int k = 0; k < sum; k++ ) {
		getline(ifs, s);
	for  (int i = 0; i<s.find(";"); i++) {
		Name[k] += s[i];
	}
	int t=0;
	for(int i = s.find(";"); i < s.size(); i++) {
		t*=10;
		t+=(int)s[i]-48;
	}
}

ifs.close();

 int k = 0; 
 string h;
for(int j = 0; j < sum; j++) { 
/*for(int i = 1; i < sum; i++) {
	if(Score[i - 1] < Score[i]) {
		k = Score[i - 1];
		Score[i - 1] = Score[i];
		Score[i] = k;
		h = Name[i - 1];
		Name[i - 1] = Name[i];
		Name[i] = h;
	}
	
}*/
cout << Name[j] << ";" << Score[j] << endl;
}
ofs.open("C:\\Users\\lexa3\\OneDrive\\Рабочий стол\\git-playground-master\\nice-project\\OP_LR1_IP96_Horobets_Zamrii\\Lexa_sdelal_fiziku.csv");

for(int i =0; i < sum; i++) {
	ofs << Name[i] << ";" << Score[i] << endl;
}
ofs.close();
	return 0;
}
