#include <iostream>
#include <stdlib.h>
 
using namespace std;

int posfixa(string s1, string s2){
	
	if(s1[0] == NULL && s2[0] == NULL){
		
	}else if(s1.length()==1 && s2.length()==1){
		if(s1[0] == s2[0])
			cout << s1;
	}else{
		char No = s1[0];
		int aux, gg=0;
		
		
		//Pegar a raiz
		for(int k=0; k<s2.length(); k++){
			if(s2[k]==No){
				aux = k;
				
			}
		}
		
		
		//Formar s1_esq
		for(int k=1; k<=aux; k++){
			gg++;
		}
		std::string s1_esq (gg, ' ');
		gg=0;
		for(int k=1; k<=aux; k++){
			s1_esq[k-1] = s1[k];
		}
		
		
		//Formar s2_esq
		for(int k=0; k<aux; k++){
			gg++;
		}
		std::string s2_esq (gg, ' ');
		gg=0;
		for(int k=0; k<aux; k++){
			s2_esq[k] = s2[k];
		}
		
		
		//Colocar s1_esq e s2_esq na função recursiva
		posfixa(s1_esq, s2_esq);
		
		//Formar s1_dir
		for(int k=aux+1, j=0; k<s1.length(); k++,j++){
			gg++;
		}
		std::string s1_dir (gg, ' ');
		gg=0;
		for(int k=aux+1, j=0; k<s1.length(); k++,j++){
			s1_dir[j] = s1[k];
		}
		
		
		//Formar s2_dir
		for(int k=aux+1, j=0; k<s2.length(); k++,j++){
			gg++;
		}
		std::string s2_dir (gg, ' ');
		gg=0;
		for(int k=aux+1, j=0; k<s2.length(); k++,j++){
			s2_dir[j] = s2[k];
		}
		
		
		//Colocar s1_dir e s2_dir na função recursiva
		posfixa(s1_dir, s2_dir);
		
		//SAIDA FINAL
		cout << No;
		
	}
	
}

int main() {

	string s1,s2;
	int c,n;
	cin >> c;
	for(int j=0; j<c; j++){
		cin >> n >> s1 >> s2;
		posfixa(s1,s2);
		cout << endl;
	}

	return 0;
}