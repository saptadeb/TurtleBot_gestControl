#define _GLIBCXX_USE_CXX11_ABI 0

#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <ctime>
#include <sys/stat.h>
#include <string>
#include <sstream>

using namespace std;

string hme = "/home/fdai5587/ws/testdata";

template <typename T>
string ntos(T pNumber)
{
 ostringstream oOStrStream;
 oOStrStream << pNumber;
 return oOStrStream.str();
}

void maked(string d, int n){
  string ds = d + ntos(n);
  const char * dsc = ds.c_str();
  int dsd = mkdir(dsc, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
}

void dir(int a, int b, int c){
  maked ("p", a);
  //string hme = "/home/fdai5587/ws/testdata";
  string s = hme + "/p" + ntos(a);
  const char * cs = s.c_str();
  int dd;
  dd = chdir(cs);
  
  char the_path[256];
  getcwd(the_path, 255);
  cout<< the_path<<endl;

  maked ("g", b);
  string s1 = s+"/g"+ntos(b);
  const char * cs1 = s1.c_str();
  dd = chdir(cs1);
  
  
  getcwd(the_path, 255);
  cout<< the_path<<endl;

  maked ("t", c);
  string s2 = s1+"/t"+ntos(c);
  const char * cs2 = s2.c_str();
  dd = chdir(cs2);

  getcwd(the_path, 255);
  cout<< the_path<<endl;

}


int main(){
  //change directory to ... testdata
  const char * home = hme.c_str();
  int h;
  h = chdir(home);

  int p;
  cout << "Enter person number (1-10): "; 
  cin >> p;

  int g;
  cout << "Enter gesture class (1-4): "; 
  cin >> g;

  int t;
  cout << "Enter try number (1-10): "; 
  cin >> t;


  dir(p,g,t);
}
/*

int main(){
  int status;
  status = mkdir("testdata", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
  char the_path[256];
  getcwd(the_path, 255);
  cout<< the_path<<endl;
  string st = "/home/fdai5587/ws/testdata";
  const char * strs = st.c_str();
  int x;
  x = chdir(strs);
  getcwd(the_path, 255);
  cout<< the_path<<endl;
  return 0;

}
*/