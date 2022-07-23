#include<vcl.h>
#pragma hdrstop

#include<string.h>
#define CharToInt(x) ((x)-'0')
//---------------------------------------------------------------------------
AnsiString replaceString(AnsiString inp,AnsiString search,AnsiString replace) {
 AnsiString s=inp;
 int where=s.Pos(search);
   if (where>0) {
      s.Delete(where,search.Length());
      s.Insert(replace,where);
   }
   return s;
}
int is_leap(int year)  {
   if (((year%4)==0)&&((year%100)!=0))  return 1;
   else
      if ((year%400)==0)  return 1;
      else return 0;
}

char out_of_month(int month,int year=0)  {
 char ans;
   switch(month)  {
      case 1: ans=31; break;
      case 2: ans=28+is_leap(year); break;
      case 3: ans=31; break;
      case 4: ans=30; break;
      case 5: ans=31; break;
      case 6: ans=30; break;
      case 7: ans=31; break;
      case 8: ans=31; break;
      case 9: ans=30; break;
      case 10: ans=31; break;
      case 11: ans=30; break;
      case 12: ans=31; break;
      default: ans=0;
   }
   return ans;
}

bool CheckEGN(char *EGN) {
 int day,month,year;
 int correct;
 char flag=0;
// Checking the lenght...
   if (strlen(EGN)!=10) return false;
// Checking the digits...
   for (int i=0;i<10;i++)
      if (EGN[i]<'0'||EGN[i]>'9') return false;
// Checking the date...
   year=(CharToInt(EGN[0]))*10+(CharToInt(EGN[1]));
   month=(CharToInt(EGN[2]))*10+(CharToInt(EGN[3]));
   day=(CharToInt(EGN[4]))*10+(CharToInt(EGN[5]));

   if (month<1||month>52) return false;
   if (month>12&&month<33) {month-=20; flag=1;}
   if (month>40&&month<53) {month-=40; flag=2;}
   switch (flag) {
      case 0:
         correct=out_of_month(month,year);
      break;
      case 1:
         correct=out_of_month(month,year+1800);
      break;
      case 2:
         correct=out_of_month(month,year+2000);
      break;
   }
   if (correct==0||day>correct) return false;
// Calculating and checking checksum
// 2 4 8 5 10 9 7 3 6 chk
// 0 1 2 3  4 5 6 7 8
   correct=CharToInt(EGN[0])*2+CharToInt(EGN[1])*4+CharToInt(EGN[2])*8+CharToInt(EGN[3])*5+
           CharToInt(EGN[4])*10+CharToInt(EGN[5])*9+CharToInt(EGN[6])*7+CharToInt(EGN[7])*3+
           CharToInt(EGN[8])*6;
   if (correct%11==10&&CharToInt(EGN[9])==0) return true;
   if (CharToInt(EGN[9])!=correct%11) return false;

// All went OK
   return true;
}
//===============================================================
//---------------------------------------------------------------
//===============================================================
#define SQL_ONECHAR   '_'
#define SQL_MANYCHARS '%'

void ReplaceChars(AnsiString &name) {
 char *str=new char[name.Length()+1];
 int len;
   strcpy(str,name.c_str());
   len=strlen(str);
   for (int i=0;i<len;i++) {
      if (str[i]=='?') str[i]=SQL_ONECHAR;
      if (str[i]=='*') str[i]=SQL_MANYCHARS;
   }
   name=StrPas(str);
   delete[] str;
}

