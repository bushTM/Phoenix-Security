#include <vector>
#include <string>
#include <filesystem>
#include <iostream>

//#pragma comment(lib, "Ole32.lib")
//#pragma comment(lib, "Shell32.lib")

using namespace std;
namespace fs = std::filesystem;

class Utility
{
	private:
		string GetCurrentTime()
		{
		    time_t now = time(0);
		    tm* ltm = localtime(&now);
		
		    char buffer[80];
		
		    strftime(buffer, sizeof(buffer),
		             "[%d/%b/%Y:%H:%M:%S]",
		             ltm);
		
		    return string(buffer);
		}
	
	public:
		
		vector<string> FileIterator(string address)
		{
		    vector<string> files;
		
		    for (const auto& entry : fs::directory_iterator(address))
		    {
		        if (entry.is_regular_file())
		            files.push_back(entry.path().filename().string());
		        
		    }
		
		    return files;
		}
		
		void log(string msg, string fname)
		{
			
			string time = GetCurrentTime();
			
			fstream file(fname,ios::in|ios::out|ios::app);
			file<<"--"<<msg<<"--"<<time<<"\n";
			file.close();
		}
		
		void clearlog(string fname)
		{
			fstream file(fname,ios::trunc);
			file.close();
		}
		
		
		
		
	
};