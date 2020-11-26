#include<iostream>
#include "hashtable.h"
using namespace std;


int main(){

	Hashtable h;
	h.insert("Mango",100);
	h.insert("Banana",20);
	h.insert("MangoShake",150);
	h.insert("pineapple",90);
	h.insert("Kiwi",120);

	cout<<h.search("Kiwi")<<endl;

	

	h["Papaya"] = 30; 
	h["Papaya"] += 50; 
	h["Papaya"] *= 10;
	cout<<h["Papaya"]; 


	h.print();
	return 0;
}
