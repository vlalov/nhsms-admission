//---------------------------------------------------------------------------

#ifndef LogGeneratorH
#define LogGeneratorH
#include<vcl.h>
#include<stdio.h>
//---------------------------------------------------------------------------
class TLog {
 private:
   AnsiString file;
   FILE *log;
   bool disabled;
 public:
   __fastcall TLog(AnsiString filename,bool disabled=false);
   __fastcall ~TLog();
   void __fastcall WriteException(AnsiString what);
   void __fastcall WriteString(AnsiString what);
};
#endif
