#include <string>
#include <vector>
#include <filesystem>
#include <vector>
#include <fstream>

using namespace std;
namespace fs = std::filesystem;

class JunkCleaner
{
	private:
    	
    	string formatSize(long long bytes) 
		{
		    double size = static_cast<double>(bytes); // Convert to double for decimal math
		    string unit = " B";
		
		    if (size >= 1024) {
		        size /= 1024;
		        unit = " KB";
		    }
		
		    if (size >= 1024) {
		        size /= 1024;
		        unit = " MB";
		    }
		
		    if (size >= 1024) {
		        size /= 1024;
		        unit = " GB";
		    }
		
		    stringstream stream;
		    stream << fixed << setprecision(2) << size << unit;
		    
		    return stream.str();
		}
    	
    	
    	long long calculateSize(vector<string> files)
		{
		    long long totalSize = 0;
		
		    for (string file : files) 
			{
		        try{
		            if (fs::exists(file)) 
		                totalSize += fs::file_size(file);
		        }
		        catch (...){continue;}  
		    }
		
		    return totalSize;
		}
    	
    	
    	vector<string> UserEnvironmentFriendly(const vector<string>& paths)
		{
		    vector<string> result;
		
		    const char* userProfile = getenv("USERPROFILE");
		
		    if (!userProfile)
		        return result;
		
		    string realUserPath = userProfile;
		
		    for (string path : paths)
		    {
		        size_t usersPos = path.find(R"(C:\Users\<USER>)");
		
		        if (usersPos != string::npos)
		        {
		            path.replace(
		                usersPos,
		                string(R"(C:\Users\<USER>)").length(),
		                realUserPath
		            );
		        }
		
		        result.push_back(path);
		    }
		
		    return result;
		}
    	
    	vector<string> P1;				//---Temporary Files & System Junk---
		vector<string> P2;				//---Browser & Internet Cache---
		vector<string> P3;				//---Graphics, Shader & Media Cache---
		vector<string> P4;				//---Application Cache & User Data Junk---
		
		
	public:
		
		
		
		vector<string> F1;				//---Temporary Files & System Junk---
		vector<string> F2;				//---Browser & Internet Cache---
		vector<string> F3;				//---Graphics, Shader & Media Cache---
		vector<string> F4;				//---Application Cache & User Data Junk---
		
		string s1;
		string s2;
		string s3;
		string s4;
		
		
		vector<string> PathScanner(vector<string> paths) 
		{

		    vector<string> Files;
		
		    for (string path : paths) 
			{
		        try {
		
		            if (!fs::exists(path)) 
		                continue;
		
		            for (const auto& entry : fs::recursive_directory_iterator(path)) 
					{
		                try {
		                	if (entry.is_regular_file()) 
						        Files.push_back(entry.path().string());
						}
						
		                catch (...){continue;}       
		            }
		
		        }
		        
		        catch (...){continue;}
		    }
		
		    return Files;
		}
	    
	    
    	void deleteFiles(vector<string> files) 
		{
		    for (string file : files) 
			{
		        try {
		
		            if (fs::exists(file))
		                fs::remove(file);
		        }
		        catch (...){continue;}
		    }
		}
    	
    	
    	
    	void loadPaths(string fname)
		{
			fstream file(fname,ios::in);
			
			string p;
			int type=0;
			while(getline(file,p))
			{
				if(p=="")
					continue;
				
				if(p == "---Temporary Files & System Junk---"){
					type = 1;
					continue;
				}	
				else if(p == "---Browser & Internet Cache---"){
					type = 2;
					continue;
				}
				else if(p == "---Graphics, Shader & Media Cache---"){
					type = 3;
					continue;
				}
				else if(p == "---Application Cache & User Data Junk---"){
					type = 4;
					continue;
				}
				
				
				switch(type)
				{
					case 1:
						P1.push_back(p);
						break;
						
					case 2:
						P2.push_back(p);
						break;
						
					case 3:
						P3.push_back(p);
						break;
						
					case 4:
						P4.push_back(p);
						break;
						
					default:
						continue;
				}
				
			}
		}
		
		void loadFiles()
		{
			P1 = UserEnvironmentFriendly(P1);
			P2 = UserEnvironmentFriendly(P2);
			P3 = UserEnvironmentFriendly(P3);
			P4 = UserEnvironmentFriendly(P4);
			
			F1 = PathScanner(P1);
			F2 = PathScanner(P2);
			F3 = PathScanner(P3);
			F4 = PathScanner(P4);
		}
			
		void loadSizes()
		{
			s1 = formatSize(calculateSize(F1));
			s2 = formatSize(calculateSize(F2));
			s3 = formatSize(calculateSize(F3));
			s4 = formatSize(calculateSize(F4));
		}
    	
    	
};