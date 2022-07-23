//---------------------------------------------------------------------------

#include<vcl.h>
#include<stdio.h>
#pragma hdrstop

#include "BlankLoad.h"
#define MAXBUFFER 1001
#define NEWLINE 0x0A
#define RETURN  0x0D
//---------------------------------------------------------------------------

#pragma package(smart_init)
AnsiString replace1(AnsiString inp,AnsiString search,AnsiString replace) {
 AnsiString s=inp;
 int where=s.Pos(search);
   if (where>0) {
      s.Delete(where,search.Length());
      s.Insert(replace,where);
   }
   return s;
}
AnsiString overwrite1(AnsiString inp,AnsiString search,AnsiString replace) {
 AnsiString s=inp;
 int where=s.Pos(search);
   if (where>0) {
      s.Delete(where,replace.Length());
      s.Insert(replace,where);
   }
   return s;
}

AnsiString replaceAll(AnsiString inp,AnsiString search,AnsiString replace) {
 AnsiString s=inp;
 int where=s.Pos(search);
 AnsiString res;
   while (where>0) {
      s.Delete(where,search.Length());
      s.Insert(replace,where);
      res=res+s.SubString(1,where+replace.Length()-1);
      s=s.SubString(where+replace.Length(),s.Length());
      where=s.Pos(search);
   }
   if (!s.IsEmpty()) res=res+s;
   if (res.IsEmpty()) res=inp;
   return res;
}

AnsiString overwriteAll(AnsiString inp,AnsiString search,AnsiString replace) {
 AnsiString s=inp;
 int where=s.Pos(search);
 AnsiString res;
   while (where>0) {
      s.Delete(where,replace.Length());
      s.Insert(replace,where);
      res=res+s.SubString(1,where+replace.Length()-1);
      s=s.SubString(where+replace.Length(),s.Length());
      where=s.Pos(search);
   }
   if (!s.IsEmpty()) res=res+s;
   if (res.IsEmpty()) res=inp;
   return res;
}

/*
*
*
*
*
*
*
*
*
*/
BlankLoader::BlankLoader(AnsiString source,bool inputIsFile) {
 FILE *bl;
 int bytes;
 char buffer[MAXBUFFER];
   if (inputIsFile==true) {
      bl=fopen(source.c_str(),"r");
      while (!feof(bl)) {
         bytes=fread(buffer,1,MAXBUFFER-2,bl);
         buffer[bytes]='\0';
         input=input+StrPas(buffer);
         buffer[0]='\0';
      }
      fclose(bl);
   } else {
      input=source;
   }
   FormatText();
}
BlankLoader::~BlankLoader() {}
void BlankLoader::FormatText() {
   output=input;
   output=replaceAll(output,"/R\\","\r");
   output=replaceAll(output,"/N\\","\n");
   //output=input;
}
int BlankLoader::SaveToFile(AnsiString filename) {
 FILE *out=fopen(filename.c_str(),"w");
   if (out==NULL) return 0;
   for (int i=0;i<output.Length();i++) {
      fputc((output.c_str())[i],out);
   }
   fclose(out);
   return 1;
}
int BlankLoader::DoRepetition(int times,AnsiString start,AnsiString end,bool keepLength) {
 int i=output.Pos(start),j=output.Pos(end);
 AnsiString tmp;
 char *t;
   if (i==0||j==0||(i>=j)) return 0;
   output.Delete(i,start.Length());
   j-=start.Length();
   output.Delete(j,end.Length());
   //ShowMessage(output);
   tmp=output.SubString(i,j-i);
   for (int i=1;i<times;i++) {
      output.Insert(tmp,j);
      j+=tmp.Length();
      // cutting last line if blank...
      if (keepLength==true) {
         t=new char[output.Length()+1];
         strcpy(t,output.c_str());
         if (t[output.Length()-1]=='\n') {
            t[output.Length()-1]='\0';
            output=StrPas(t);
         }
         delete[] t;
         //if (output..Length()
      }
      //ShowMessage(output);
   }
   //ShowMessage(output);
   return 1;
}

CustomCodeTable::CustomCodeTable(AnsiString codetable) {
 table=new int[257];
 FILE *inp;
 int index,val;
   if (codetable=="") {
      for (int i=1;i<256;i++) {
         table[i]=i;
      }
      return;
   }
   inp=fopen(codetable.c_str(),"r");
   if (inp==NULL) {
      ShowMessage("Cannot open codetable file!");
      return;
   }
   for (int i=1;i<256;i++) {
      table[i]=i;
   }
   if (feof(inp)) {
      fclose(inp);
      return;
   }
   for (int j=1;j<256;j++) {
      fscanf(inp,"%d=%d",&index,&val);
      table[index]=val;
      if (feof(inp)) break;
   }
   fclose(inp);
}
AnsiString CustomCodeTable::decodeString(AnsiString input) {
 char *res,*inp;
 AnsiString out;
 int len=input.Length();
 char tmp;
   res=new char[len+2];
   inp=new char[len+2];
   strcpy(inp,input.c_str());
   for (int i=0;i<len;i++) {
      tmp=inp[i];
      res[i]=decode(tmp);
   }
   res[len]='\0';
   out=StrPas(res);
   delete[] res;
   delete[] inp;
   return out;
}
int CustomCodeTable::decode(int ch) {
   if (ch<0)
      return table[ch+256];
   else return table[ch];
}
CustomCodeTable::~CustomCodeTable() {
   delete[] table;
}

