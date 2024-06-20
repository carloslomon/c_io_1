#include <stdio.h>
#include <math.h>
#include "gcd.h"
int gcd(int n1, int n2){
	//we could have a gcd val set to 1 but it is redundant	 

	if(n2>n1){ /*switches the values of n1 and n2 so n1 is always the larger number*/
		int a=n1; 
		n1=n2; 
		n2=a; 
	}

	while(n2 !=0){
		int b= n1%n2; 
		n1=n2; 
		n2=b;
	}/*end*/

	return n1; 
}
int gcd_sol_2(int n1, int n2){
	int gcdval =1; 
	int limit; 
	if(n1> n2 ){
		limit = n1;
	}
	else{
		limit = n2;
	}
	for(int i =2; i < limit; i++){
		if(n1%i== 0 && n2%i==0){
			gcdval = i;
		}
	}
	return gcdval;
}


