ass Solution {
  public:
       string intToRoman(int num) {
          string str;     
           int n[5];
           memset(n,0,sizeof(n));
           int tmp = num;
           int index = 0;
           while(tmp>0){
                  n[index] = tmp % 10;
                  index++;
                  tmp = tmp / 10;
          }
          int cur;
          for(int i=3;i>=0;i--){
                  switch(n[i]){
                         case 0: break;
                         case 1: 
                                  if(i==3){str.append("M");break;}
                                  if(i==2){str.append("C");break;}
                                  if(i==1){str.append("X");break;}
                                  if(i==0){str.append("I");break;}
                         case 2:
                                  if(i==3){str.append("MM");break;}
                                  if(i==2){str.append("CC");break;}
                                  if(i==1){str.append("XX");break;}
                                  if(i==0){str.append("II");break;} 
                        case 3:
                                  if(i==3){str.append("MMM");break;}
                                  if(i==2){str.append("CCC");break;}
                                  if(i==1){str.append("XXX");break;}
                                  if(i==0){str.append("III");break;} 
                        case 4:
                                  if(i==2){str.append("CD");break;}
                                  if(i==1){str.append("XL");break;}
                                  if(i==0){str.append("IV");break;} 
                        case 5:
                                  if(i==2){str.append("D");break;}
                                  if(i==1){str.append("L");break;}
                                  if(i==0){str.append("V");break;} 
                        case 6:
                                  if(i==2){str.append("DC");break;}
                                  if(i==1){str.append("LX");break;}
                                  if(i==0){str.append("VI");break;} 
                        case 7:
                                  if(i==2){str.append("DCC");break;}
                                  if(i==1){str.append("LXX");break;}
                                  if(i==0){str.append("VII");break;}
                        case 8:
                                  if(i==2){str.append("DCCC");break;}
                                  if(i==1){str.append("LXXX");break;}
                                  if(i==0){str.append("VIII");break;}
                        case 9:
                                  if(i==2){str.append("CM");break;}
                                  if(i==1){str.append("XC");break;}
                                  if(i==0){str.append("IX");break;} 
                  }
          }
          return str;
      }
};
   
