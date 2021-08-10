#include <stdlib.h>

int POW(int base, int k) {
	int res = 1;
	while(k--) {
		res *= base;
	}
	return res;
}

char* it(int num, char* res, int base) {
	int curr = 0;
 
	if (num == 0) {
        	return "0";
	}
 
	int num_digits = 0;
 
	if (num < 0) {
        	if (base == 10) {
			num_digits ++;
			res[curr] = '-';
			curr++;
			num *= -1;
       		}
        else return NULL;
    	}
	int cnt = 0;
	int k = num;
	while(k > 0) {
		cnt++;
		k /= 10;
	} 	


	num_digits += cnt;
	while (curr < num_digits) {
        	int bs = POW(base, num_digits-1-curr);
 
		int num_val = num / bs;
 
         char value = num_val + '0';
         res[curr] = value;
 
         curr ++;
         num -= bs * num_val;
     }
     res[curr] = '\0';
     return res;
}    

char* my_itoa(int x)
{
        char arr[256];
        char* res = it(x, arr, 10);
        return res;
}

