#include <iostream>
#include <string>
using namespace std;

int main(){
  string txt[5000];
  int  i=0, j=0, length=0;

  do {
    cin>>txt[i];
    i++;
  } while (!cin.eof());

for (j=0; j<i; j++){
  if ((length + txt[j+1].length()) > 60) {length = 0; cout<<endl<<txt[j]<<" ";}
  else cout<<txt[j]<<" ";
  length += (txt[j].length() + 1);

}

return 0;
}
