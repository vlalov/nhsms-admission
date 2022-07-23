//---------------------------------------------------------------------------

#ifndef ClassificateH
#define ClassificateH
//---------------------------------------------------------------------------
#include "Classificate_types.h"
#include <stdio.h>
#include <Classes.hpp>

//---------------------------------------------------------------------------
class TClassificate : public TThread
{
private:
protected:
   void __fastcall Execute();
public:
   __fastcall TClassificate(bool CreateSuspended);
   void __fastcall CreateData(int &all);
   void __fastcall ClearData(int all);
   void __fastcall InitData();
   void __fastcall Do1Classification(int all);
   void __fastcall Do2Classification(int all);
   void __fastcall InitPerviousClassification(int all);
   void __fastcall swap(int i,int j,int profile,int sex);
   void __fastcall sortRegTable(int s,int n,int profile,int sex);
   void __fastcall cutPersons(int all,int show_comm=1);
   void __fastcall SaveToDatabase(int all);

   void __fastcall PrepareFirstClassification(int all);
   void __fastcall PrepareNextClassification(int all);
 //-------------------------------------------------------------
   float __fastcall getBAL(int person_id,int priority) {
      return Persons[person_id]->wsh[priority]->bal;
   }
 //-------------------------------------------------------------
   float __fastcall getMinBAL(int profile,int sex) {
    int person, priority;
    int sx;
      if (ProfilesTable[profile]->DiffMW) sx=sex; else sx=1;
       if (reg_count[profile][sx]>=ProfilesTable[profile]->spaceForSex(sx)){
          if (reg_count[profile][sx]==0) return 0;
          person=regtable[profile][sx][reg_count[profile][sx]]->person_id;
          priority=regtable[profile][sx][reg_count[profile][sx]]->priority;
          return Persons[person]->wsh[priority]->bal;
       } else {
          return 0;
       }
   }
 //-------------------------------------------------------------
   int __fastcall setAccepted(int person_id,int priority) {
    int profile=Persons[person_id]->wsh[priority]->profile_id;
    int sex=Persons[person_id]->sex;
    float bal=Persons[person_id]->wsh[priority]->bal,getbal;
    int res=0;
    FILE *out;
    bool done=false;
      sex=ProfilesTable[profile]->sexindex(sex);

      if (reg_count[profile][sex]==0) {
         reg_count[profile][sex]++;
         regtable[profile][sex][reg_count[profile][sex]]->person_id=person_id;
         regtable[profile][sex][reg_count[profile][sex]]->priority=priority;
         Persons[person_id]->reg_index=reg_count[profile][sex];
         Persons[person_id]->reg_priority=priority;
         return res;
      }

      for (int i=1;i<=reg_count[profile][sex];i++) {
         getbal=getBAL(regtable[profile][sex][i]->person_id,regtable[profile][sex][i]->priority);
         if (bal<getbal) continue;
         if (bal==getbal&&person_id>=regtable[profile][sex][i]->person_id) continue;

         for (int j=reg_count[profile][sex];j>=i;j--) {
            regtable[profile][sex][j+1]->person_id=regtable[profile][sex][j]->person_id;
            regtable[profile][sex][j+1]->priority=regtable[profile][sex][j]->priority;
            //regtable[profile][sex][j+1]=regtable[profile][sex][j];
            Persons[regtable[profile][sex][j+1]->person_id]->reg_index++;
         }
         regtable[profile][sex][i]->person_id=person_id;
         regtable[profile][sex][i]->priority=priority;

         Persons[person_id]->reg_index=i;
         Persons[person_id]->reg_priority=priority;
         reg_count[profile][sex]++;
         done=true;
         if (bal==getbal) res=1;
         break;
      }
      if (reg_count[profile][sex]<ProfilesTable[profile]->spaceForSex(sex)&&done!=true) {
         reg_count[profile][sex]++;
         regtable[profile][sex][reg_count[profile][sex]]->person_id=person_id;
         regtable[profile][sex][reg_count[profile][sex]]->priority=priority;
         Persons[person_id]->reg_index=reg_count[profile][sex];
         Persons[person_id]->reg_priority=priority;
      }
      return res;
   }
   TDateTime start,end;

   Person **Persons;
   Register ****regtable;
   int **reg_count;
   Profile **ProfilesTable;
};
//---------------------------------------------------------------------------
#endif
