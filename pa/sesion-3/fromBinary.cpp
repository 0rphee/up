#include <iostream>
#include <string>
using namespace std;

void mPrint(string text){
  cout << text << endl;
}


string reverseStr(string str){
	string reversed {str};
	for (int i = str.length()-1, j = 0; i >= 0; i--, j++){
		reversed[j] = str[i];
	}
	return reversed;
}

int pow(int a, int b){
	int accum{1};
	for (int i = 0; i < b; i++){
		accum = accum * a;
	}
	return accum;
}


int main(){
  string bnum ;
	int finalNum {0};
	
  mPrint("Ingrese un número binario");
  cin >> bnum;

	string rev = reverseStr(bnum);

	for (int i = 0; i < rev.length(); i++){
		char currentDigit = rev[i];

		if (currentDigit == '1'){
			finalNum += pow(2, i) ;

		} else if (currentDigit != '0'){

			mPrint("Carácter inválido para conversión a binario");
			break;
		}

	}
	
	mPrint("The final number is: ");;
	mPrint(to_string(finalNum));
  
  return 0;
}


