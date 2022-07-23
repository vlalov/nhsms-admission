//---------------------------------------------------------------------------


#pragma hdrstop

#include "LogGenerator.h"
#include<stdio.h>
//---------------------------------------------------------------------------

#pragma package(smart_init)
__fastcall TLog::TLog(AnsiString filename,bool disabl) {
   if (disabl!=true) {
      log=fopen(filename.c_str(),"a");
      if (log!=NULL)
         file=filename;
      else
         file="";
      if (log!=NULL) {
         fprintf(log,"--- New log started on %s\n\n",FormatDateTime("ddddd @ tt",Now()));
         fflush(log);
      }
      disabled=false;
   } else {
      log=NULL;
      disabled=true;
   }
}

__fastcall TLog::~TLog() {
   if (log==NULL) return;
   if (disabled) return;
   fprintf(log,"\n--- End of log on %s\n",FormatDateTime("ddddd @ tt",Now()));
   fflush(log);
   fclose(log);
}
void __fastcall TLog::WriteException(AnsiString what) {
   if (log==NULL) return;
   if (disabled) return;
   fprintf(log,"-- Exception on %s:\n%s\n",FormatDateTime("ddddd @ tt",Now()),what.c_str());
   fflush(log);
}
void __fastcall TLog::WriteString(AnsiString what) {
   if (log==NULL) return;
   if (disabled) return;
   fprintf(log,"-- %s:\n%s\n",FormatDateTime("ddddd @ tt",Now()),what.c_str());
   fflush(log);
}
