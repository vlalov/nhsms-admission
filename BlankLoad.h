/*
   Sequence of usage:
   1. Create an instance of the class
   2. call DoRepetition if needed
   3. Replace or/and overwrite all variables
   4. decode using custom table (not neccesary)
   5. call 'getFormatted' to get the output text

   6. destroy the instance of the class
*/
//---------------------------------------------------------------------------
#ifndef BlankLoadH
#define BlankLoadH

#define ABOUTSTRING "(C)2004 Владимир Лалов (v_lalov@yahoo.com)\n\n"

AnsiString replaceString(AnsiString inp,AnsiString search,AnsiString replace);
AnsiString replaceAll(AnsiString inp,AnsiString search,AnsiString replace);
AnsiString overwriteAll(AnsiString inp,AnsiString search,AnsiString replace);
AnsiString replace1(AnsiString inp,AnsiString search,AnsiString replace);
AnsiString overwrite1(AnsiString inp,AnsiString search,AnsiString replace);


class CustomCodeTable {
public:
   CustomCodeTable(AnsiString codetable);
   ~CustomCodeTable();
   AnsiString decodeString(AnsiString input);
//   char decode(char ch);
   int decode(int ch);
private:
   AnsiString file;
   int *table;
};

//---------------------------------------------------------------------------
//===========================================================================
class BlankLoader {
public:
   BlankLoader(AnsiString source,bool inputIsFile=true);
   ~BlankLoader();
   void FormatText();
   void decode(AnsiString decodetable) {
    if (decodetable=="") return;
    CustomCodeTable *code=new CustomCodeTable(decodetable);
      output=code->decodeString(output);
      delete code;
   }
   AnsiString getFormatted() {
      return output;
   }
   AnsiString getNotformatted() {
      return input;
   }
   AnsiString replaceFirst(AnsiString search,AnsiString replace) {
      output=replace1(output,search,replace);
      return output;
   }

   AnsiString overwriteFirst(AnsiString search,AnsiString replace) {
      output=overwrite1(output,search,replace);
      return output;
   }
   AnsiString replace(AnsiString search,AnsiString replace) {
      output=replaceAll(output,search,replace);
      return output;
   }
   AnsiString overwrite(AnsiString search,AnsiString replace) {
      output=overwriteAll(output,search,replace);
      return output;
   }
   int SaveToFile(AnsiString filename);
   int Print(AnsiString out="LPT1") {
      return SaveToFile(out);
   }
   int DoRepetition(int times,AnsiString start,AnsiString end,bool keepLength=false);
   void AppendInitials(int type=0) {
    char *ch;
    int i;
      if (type==0) {
         ch=new char[output.Length()+1];
         strcpy(ch,output.c_str());
         for (i=output.Length();i>=0;i--) {
            if (ch[i]=='\n'||ch[i]=='\r'||ch[i]=='\0') continue;
            else break;
         }
         if (i+3<=output.Length()) {
            output=output.Insert(ABOUTSTRING,i+3);
         } else {
            output=output.Insert(ABOUTSTRING,output.Length()+1);
         }
         delete[] ch;
      } else {
         output=output.Insert(ABOUTSTRING,output.Length()+1);
      }
   }
private:
   AnsiString input;  // not modified
   AnsiString output; // formated file text
};

//---------------------------------------------------------------------------
#endif
