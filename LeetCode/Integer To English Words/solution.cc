#include <stdio.h>        
#include <string>
#include <stdlib.h>

using namespace std;

string digitmap[20] = {"Zero","One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", 
            "Eleven", "Twelve", "Thirtenn", "Fourteen", "Fiftenn", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
string digitTenlevel[10] = {"Ten", "Twenty", "Thirty", "Fourty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        
/*
 * convert number in the range [0,999]
*/

string subNumber(int num){
    string ret = "";
    int digit;
    if(num >= 100){
        digit = num / 100;
        ret = ret + digitmap[digit] + " Hundred";
        num = num - digit * 100;
    }
    if(num >= 20) {
        digit = num / 10;
        if(ret.length() > 0) {
            ret = ret + " ";
        }
        ret = ret+ digitTenlevel[digit - 1];
        num = num - digit*10;
        if(num > 0) ret = ret + " " + digitmap[num]; 
    }else{
            if( num > 0 ){
                if(ret.length() > 0 )  ret = ret + " ";
                ret = ret + digitmap[num];  
            }
    }
        return ret;
}

int billion = 1000000000;
int million = 1000000;
int thousand = 1000;

string numberToWords(int num) {
    string ret = "";
    int subnumber;
    if(num == 0) return "Zero";
    if(num >= billion) {
        subnumber = num / billion;
        ret = subNumber(subnumber) + " Billion";
        num = num - subnumber * billion;
    }
    if(num >= million){
        if(ret.length() > 0) ret = ret + " ";
        subnumber = num / million;
        ret = ret + subNumber(subnumber) + " Million";
        num = num - subnumber * million;
    }
    if(num >= thousand){
        if(ret.length() > 0) ret = ret + " ";
        subnumber = num / thousand;
        ret = ret + subNumber(subnumber) + " Thousand";
        num = num - subnumber * thousand;
    }
    if(num > 0) {
        if(ret.length() > 0) ret = ret + " ";
        ret = ret + subNumber(num);
    }
    return ret;
}

int main() {
    string ret;
    ret = numberToWords(123);
    printf("123 --> %s\n", ret.c_str());
    ret = numberToWords(12345);
    printf("12345 --> %s\n", ret.c_str());
    ret = numberToWords(1234567);
    printf("1234567 --> %s\n", ret.c_str());
    return 0;
}
