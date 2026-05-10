#include<iostream>
#include<fstream>
#include <unordered_set>
using namespace std;

class Antivirus
{
	private:
		static unordered_set<string> hashes;
		
		bool loadHashes(string fname)
		{
			fstream file(fname,ios::in);
			if(!file.is_open()){return false;};
			
			string h;
			
			while(getline(file,h))
				hashes.insert(h);
			
			return true;
		}
		
		string FiletoHash(string fname)
		{
			//FUNCTION HERE
			
			
		}
		
	public:
		
		bool HashSearch(string fname, string dname)
		{
			//fname =  FILE for wich we want to check hash
			//dname =  DATABASE file (Hashes.txt)
			
			if (hashes.empty())
        		loadHashes(dname);
    
    
			string fileHash = FiletoHash(fname);
			
			if(hashes.find(fileHash) != hashes.end())
				return true;
			else 
				return false;			
		}
};


//STATIC VARIABLE DECLARED OUTISDE AS WELL
unordered_set<string> Antivirus::hashes;


main()
{
	
	
}