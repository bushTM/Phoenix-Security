#include<cstdio>
#include <ctime>
#include <cstdlib>
#include<iostream>
#include<fstream>
#include<filesystem>
#include"AES.hpp"
#include"SHA256.h"
#include"SHA256.cpp"
using namespace std;

string String_To_Hash(string str)
{ 
    SHA256 sha;

    sha.update(str);
    array<uint8_t,32> rawHash = sha.digest();

    string hash = SHA256::toString(rawHash);

    return hash;
}

class SVAULT
{
	public:
		string ext="";
		string len="";
		
		string randomString() {

		    const string chars =
		        "abcdefghijklmnopqrstuvwxyz"
		        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		        "0123456789";
		
		
		    int length = 10 + rand() % 6; // 10–15
		    string result;
		
		    for (int i = 0; i < length; ++i){
		        result += chars[rand() % chars.size()];
		    }
		    
		    return result;
		}
		
		int getHeader(string vfname)
		{
			ifstream vfile(vfname,ios::binary);
						
			char c;
			int i=0;
			ext="";
			len="";
			
			while(vfile.get(c))
			{
				if(i<=6){
					i++;
					continue;
				}
					
				else if(i>=7 && i<=9)
					len = len + c;
				
				else if (i>=10 && i<=9+stoi(len))
					ext = ext + c;
				
				else {
					vfile.close();
					return i;
				}
				
				i++;
			}
			
			
		}
		
		string makeHeader(string fname)
		{
			string ext = fname;
			int l = ext.length();
			
			if(l<=9)
				len = "00"+to_string(l);
			else if(l<=99)
				len = "0"+to_string(l);
			else if(l<=999)
				len = to_string(l);
			
			string header = "PHOENIX" + len + ext;
			
			return header;
		}
		
		string v_f(string vfname){
			
			getHeader(vfname);
			string fname = ext;
			return fname;
		}
		
		string f_v(string fname){
			
			string vfname = randomString();
			return vfname;
		}
		
	public:
		string vault_to_file(string vfname)
		{
			string fname = v_f(vfname);
			
			int l = getHeader(vfname);
			
			ifstream vfile(vfname,ios::binary);
			if(!vfile){return "false";}
			ofstream file(fname,ios::binary);
			
			char ch;
			for(int i=0;i<l;i++){
				vfile.get(ch);
			}
			
			file<<vfile.rdbuf();			
			
			file.close();
			vfile.close();
			remove(vfname.c_str());
			
			return fname;
		}
		
		
		string file_to_vault(string& fname)
		{
			string vfname = f_v(fname);
			string ext = fname.substr(fname.find('.')+1, fname.length());
			
			ifstream file(fname,ios::binary);
			if(!file){return "false";}
			ofstream vfile(vfname,ios::binary|ios::app);
			
			
			string header = makeHeader(fname);
			
			vfile.write(header.c_str(),header.size());
			vfile<<file.rdbuf();
			
			vfile.close();
			file.close();
			remove(fname.c_str());
			
			return vfname;			
		}		
	
};

class VAULT
{
	private:
		string ext="";
		string len="";
		
		int getHeader(string vfname)
		{
			ifstream vfile(vfname,ios::binary);
						
			char c;
			int i=0;
			ext="";
			len="";
			
			while(vfile.get(c))
			{
				if(i<=6){
					i++;
					continue;
				}
					
				else if(i>=7 && i<=9)
					len = len + c;
				
				else if (i>=10 && i<=9+stoi(len))
					ext = ext + c;
				
				else {
					vfile.close();
					return i;
				}
				
				i++;
			}
			
			
		}
		
		string makeHeader(string fname)
		{
			string ext = fname.substr(fname.find('.')+1, fname.length());
			string len;
			int l = ext.length();
			
			if(l<=9)
				len = "00"+to_string(l);
			else if(l<=99)
				len = "0"+to_string(l);
			else if(l<=999)
				len = to_string(l);
			
			string header = "PHOENIX" + len + ext;
			
			return header;
		}
		
		
	public:
		string v_f(string vfname){
			getHeader(vfname);
			
			string fname = vfname.substr(0,vfname.find('.')) + "." + ext;
			
			return fname;
		}
		
		string f_v(string fname){
			string vfname = fname.substr(0,fname.find('.')) + ".vault";
			return vfname;
		}
		
		bool vault_to_file(string vfname)
		{
			string fname = v_f(vfname);
			
			int l = getHeader(vfname);
			
			ifstream vfile(vfname,ios::binary);
			if(!vfile){return false;}
			ofstream file(fname,ios::binary);
			
			char ch;
			for(int i=0;i<l;i++){
				vfile.get(ch);
			}
			
			file<<vfile.rdbuf();			
			
			file.close();
			vfile.close();
			remove(vfname.c_str());
			return true;
		}
		
		
		bool file_to_vault(string fname)
		{
			string vfname = f_v(fname);
			string ext = fname.substr(fname.find('.')+1, fname.length());
			
			ifstream file(fname,ios::binary);
			if(!file){return false;}
			ofstream vfile(vfname,ios::binary|ios::app);
			
			
			string header = makeHeader(fname);
			
			vfile.write(header.c_str(),header.size());
			vfile<<file.rdbuf();
			
			vfile.close();
			file.close();
			remove(fname.c_str());
			
			return true;			
		}		
	
};


class AES
{
	public :
		void add_padding(string fname)
		{
			ifstream file(fname,ios::binary);
			ofstream Pfile("temp.bin",ios::binary);
			
			size_t size = filesystem::file_size(fname);
			
			int pad = 16 - (size % 16);
			
			Pfile<<file.rdbuf();
			
			vector<char> LastChunk;
			
			for(int i=0;i<pad;i++){
				Pfile.put((char)pad);
			}
			
			file.close();
			Pfile.close();
			
			filesystem::remove(fname.c_str());
		    filesystem::rename("temp.bin", fname);
		}
		
		void remove_padding(string fname)
		{
			ifstream file(fname,ios::binary);
			
			file.seekg(-1,ios::end);
			char ch;
			file.get(ch);
			file.close();
			
			int pad = (int)(unsigned char)ch;
			int size = filesystem::file_size(fname);
			
			file.close();
			
			filesystem::resize_file(fname, size - pad);	
		}
		
		void AES_Encrypt(string fname,string password)
		{
			ifstream in(fname, ios::binary);
			ofstream out("temp.bin", ios::binary);
			
			string k = String_To_Hash(password);
			unsigned char key[32];
			memcpy(key, k.data(), 32);
		    
		    
			Cipher::Aes<256> aes(key);
		    
			    
		    char buffer[16];
		    while (in.read(buffer, 16))
		    {
		        aes.encrypt_block((unsigned char*)buffer);        
				out.write(buffer, 16);
		    }
		
		    in.close();
		    out.close();
		    
		    filesystem::remove(fname.c_str());
		    filesystem::rename("temp.bin", fname);
		}
		
		void AES_Decrypt(string fname,string password)
		{
			ifstream in(fname, ios::binary);
		    ofstream out("temp.bin", ios::binary);
		
		    string k = String_To_Hash(password);
			unsigned char key[32];
			memcpy(key, k.data(), 32);
			
			
			Cipher::Aes<256> aes(key);
		
		
		    char buffer[16];
		
		    while (in.read(buffer, 16))
		    {
		        aes.decrypt_block((unsigned char*)buffer);
				out.write(buffer, 16);
		    }
		
		    in.close();
		    out.close();
		    
		    filesystem::remove(fname.c_str());
		    filesystem::rename("temp.bin", fname);
		}
		
};