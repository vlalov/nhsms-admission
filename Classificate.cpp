//---------------------------------------------------------------------------

#include <vcl.h>

#include "Classificate_types.h"
#include "Classificate.h"
#include "DataModule.h"
#include "Main.h"
#pragma hdrstop

#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall TClassificate::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------
extern bool DEBUG;
__fastcall TClassificate::TClassificate(bool CreateSuspended)
   : TThread(CreateSuspended)
{
}
//---------------------------------------------------------------------------
//-------------------------------------------------------------------
// Allocate all needed memory for the operation... 
//-------------------------------------------------------------------
void __fastcall TClassificate::CreateData(int &all) {
   MainForm->ShowProgress("Заделяне на необходимата памет...",0,0);
   Data->SingleQuery->Active=false;
   Data->SingleQuery->SQL->Clear();
   Data->SingleQuery->SQL->Add("SELECT MAX(ID) THEMAX FROM Persons");
   Data->SingleQuery->Active=true;
   all=Data->SingleQuery->FieldByName("THEMAX")->AsInteger;
   Data->SingleQuery->Active=false;

   ProfilesTable=new Profile*[Data->ProfilesTable->RecordCount+1];
   for (int p=1;p<=Data->ProfilesTable->RecordCount;p++) {
      ProfilesTable[p]=new Profile();
   }

 // Persons Table
   Persons=new Person*[all+2];
   for (int i=1;i<=all;i++) {
      Persons[i]=new Person(Data->ProfilesTable->RecordCount+1);
   }

 // Register Table
   regtable=new Register***[Data->ProfilesTable->RecordCount+2];
   for (int i=1;i<=Data->ProfilesTable->RecordCount;i++) {
      regtable[i]=new Register**[2];
      for (int sex=0;sex<=1;sex++) {
         regtable[i][sex]=new Register*[Data->PersonsQuery->RecordCount+5];
         for (int j=1;j<=Data->PersonsQuery->RecordCount;j++) {
            regtable[i][sex][j]=new Register();
         }
      }
   }
 // reg_count
   reg_count=new int*[Data->ProfilesTable->RecordCount+1];
   for (int i=1;i<=Data->ProfilesTable->RecordCount;i++) {
      reg_count[i]=new int[2];
      reg_count[i][0]=0; reg_count[i][1]=0;
   }
}
//-------------------------------------------------------------------
// Freeing allocated memory...
//-------------------------------------------------------------------
void __fastcall TClassificate::ClearData(int all) {
   MainForm->ShowProgress("Освобождаване на заетата памет...",0,0);
   for (int i=1;i<=all;i++) {
      delete Persons[i];
   }
   delete[] Persons;

   for (int i=1;i<=Data->ProfilesTable->RecordCount;i++) {
      for (int sex=0;sex<=1;sex++) {
         for (int j=1;j<=Data->PersonsQuery->RecordCount;j++) {
            delete regtable[i][sex][j];
         }
         delete[] regtable[i][sex];
      }
      delete[] regtable[i];
   }
   delete[] regtable;

   for (int p=1;p<=Data->ProfilesTable->RecordCount;p++) {
      delete ProfilesTable[p];
   }
   delete[] ProfilesTable;

   for (int i=1;i<=Data->ProfilesTable->RecordCount;i++) {
      delete[] reg_count[i];
   }
   delete[] reg_count;
}
//------------------------------------------------------------------
// read all needed data from the database...
//------------------------------------------------------------------
void __fastcall TClassificate::InitData() {
 int id,priority,profile_id;
 int times=Data->ProfilesTable->RecordCount*Data->PersonsQuery->RecordCount,t;
 float bal;
 TLocateOptions lo;
   Data->CalcBALQuery->Active=false;
   Data->CalcBALQuery->Active=true;
   Data->CalcBALQuery->First();
   for (int i=0;i<Data->CalcBALQuery->RecordCount;i++) {
      if (i%50==0) MainForm->ShowProgress("Инициализиране на данните...",i,Data->CalcBALQuery->RecordCount+times);
      id=Data->CalcBALQuery->FieldByName("ID")->AsInteger;
      priority=Data->CalcBALQuery->FieldByName("Priority")->AsInteger;
      profile_id=Data->CalcBALQuery->FieldByName("Profile_ID")->AsInteger;
      bal=Data->CalcBALQuery->FieldByName("BAL")->AsFloat;

      Persons[id]->exist=true; // person exist in the database
      Persons[id]->sex=Data->CalcBALQuery->FieldByName("Sex")->AsInteger;
      Persons[id]->wsh[priority]->profile_id=profile_id;
      if (Data->CalcBALQuery->FieldByName("Exam")->AsFloat>=3&&Data->CalcBALQuery->FieldByName("FirstExamScore")->AsFloat>=3)
         Persons[id]->wsh[priority]->bal=bal;
      else
         Persons[id]->wsh[priority]->bal=0;
      Persons[id]->reg_index=0;
      Persons[id]->reg_priority=0;

      Data->CalcBALQuery->Next();
   }
   t=Data->CalcBALQuery->RecordCount;
   Data->CalcBALQuery->Active=false;
   for (int ri=1;ri<=Data->ProfilesTable->RecordCount;ri++) {
      for (int rj=1;rj<=Data->PersonsQuery->RecordCount;rj++) {
         if (rj%50==0) MainForm->ShowProgress("Инициализиране на данните...",t+ri*rj,times+t);
         regtable[ri][0][rj]->person_id=0;
         regtable[ri][0][rj]->priority=0;

         regtable[ri][1][rj]->person_id=0;
         regtable[ri][1][rj]->priority=0;
      }
   }

   for (int p=1;p<=Data->ProfilesTable->RecordCount;p++) {
      Data->ProfilesTable->Locate("ID",p,lo);
      if (Data->ProfilesTable->FieldByName("ID")->AsInteger!=p) continue;
      ProfilesTable[p]->DiffMW=Data->ProfilesTable->FieldByName("DiffMW")->AsBoolean;
      if (ProfilesTable[p]->DiffMW==true) {
         ProfilesTable[p]->spaceM=Data->ProfilesTable->FieldByName("SpaceOther")->AsInteger;
         ProfilesTable[p]->spaceW=Data->ProfilesTable->FieldByName("Space")->AsInteger-
            Data->ProfilesTable->FieldByName("SpaceOther")->AsInteger;
         if (ProfilesTable[p]->spaceW<=0) ProfilesTable[p]->spaceW=ProfilesTable[p]->spaceM;
      } else {
         ProfilesTable[p]->spaceM=Data->ProfilesTable->FieldByName("Space")->AsInteger;
         ProfilesTable[p]->spaceW=Data->ProfilesTable->FieldByName("Space")->AsInteger;
      }
   }
}
//-------------------------------------------------------------------
// Used for sorting of regtable
//-------------------------------------------------------------------
void __fastcall TClassificate::swap(int i,int j,int profile,int sex) {
 Register *w;
   w=regtable[profile][sex][i];
   regtable[profile][sex][i]=regtable[profile][sex][j];
   regtable[profile][sex][j]=w;
}
void __fastcall TClassificate::sortRegTable(int s,int n,int profile,int sex) {
/* Quick Sort
 int i=s,j=n;
 Register *x=regtable[profile][sex][(i+j)/2],*w;
   if (s>=n) return;
   do {
      while (getBAL(regtable[profile][sex][i]->person_id,regtable[profile][sex][i]->priority)>getBAL(x->person_id,x->priority))
         i++;
      while (getBAL(regtable[profile][sex][j]->person_id,regtable[profile][sex][j]->priority)<getBAL(x->person_id,x->priority))
         j--;
      if (i<j) {
         swap(i,j,profile,sex);
      } else {
         if (i==j) {i++; j--;}
         break;
      }
   } while (++i<=--j);
   if (j>0) sortRegTable(s,j+1,profile,sex);
   if (i<n-1) sortRegTable(s+i,n-i,profile,sex);
  */
 // Bubble sort
 unsigned int i,k,right=n;
   while (right>0) {
      k=0;
      for (i=s; i<right; i++)
         if (Persons[regtable[profile][sex][i+1]->person_id]->wsh[regtable[profile][sex][i+1]->priority]->bal > Persons[regtable[profile][sex][i]->person_id]->wsh[regtable[profile][sex][i]->priority]->bal) {
            swap(i,i+1,profile,sex);
            k=i;
         }
      right=k;
   }

}
void __fastcall TClassificate::PrepareFirstClassification(int all) {
 int w;
   for (int p=1;p<=all;p++) {
      if (Persons[p]->exist!=true) continue;
         for (w=1;(w<=Persons[p]->wsh_cnt)&&(Persons[p]->wsh[w]->profile_id!=0);w++);
         Persons[p]->bound=w-1;
   }
}
void __fastcall TClassificate::PrepareNextClassification(int all) {
 int w;
 int s;
 int person;
   for (int prof=1;prof<=Data->ProfilesTable->RecordCount;prof++) {
      if (ProfilesTable[prof]->DiffMW) s=0; else s=1;
      for (int sextype=1;sextype>=s;sextype--) {
         for (int r=1;r<=reg_count[prof][sextype];r++) {
            person=regtable[prof][sextype][r]->person_id;
            if (Persons[person]->isIn)
               Persons[person]->bound=Persons[person]->PriorityOfProfile(prof);
            else
               Persons[person]->bound=Persons[person]->PriorityOfProfile(prof)-1;
         }
      }
   }
   for (int p=1;p<=all;p++) {
      if (Persons[p]->exist!=true) continue;
      if (Persons[p]->reg_index<1) Persons[p]->bound=Persons[p]->reg_priority;
   }
}

//-------------------------------------------------------------------
// Start of First classification process
//-------------------------------------------------------------------
void __fastcall TClassificate::cutPersons(int all,int show_comm) {
 bool done;
 int count,available,index,past;
 float last;
 int s;
 FILE *out;
   past=0;
   for (int profile_id=1;profile_id<=Data->ProfilesTable->RecordCount;profile_id++) {

      if (ProfilesTable[profile_id]->DiffMW) s=0; else s=1;
      for (int sextype=1;sextype>=s;sextype--) {
         done=false;
         last=0; count=0;
         available=ProfilesTable[profile_id]->spaceForSex(sextype);
         index=1;
         if (reg_count[profile_id][sextype]<index) done=true;
         while (!done) {
            if (count<available||getBAL(regtable[profile_id][sextype][index]->person_id,regtable[profile_id][sextype][index]->priority)==last) {
               last=getBAL(regtable[profile_id][sextype][index]->person_id,regtable[profile_id][sextype][index]->priority);
               count++;
               index++;
            } else {
             // unregister this person
               Persons[regtable[profile_id][sextype][index]->person_id]->reg_index=0;
               //Persons[regtable[profile_id][sextype][index]->person_id]->reg_priority=Persons[regtable[profile_id][sextype][index]->person_id]->wsh_cnt;
               index++;
            }
            if (index>reg_count[profile_id][sextype]) done=true; // finishing
            if (show_comm==1&&past%50==0) MainForm->ShowProgress("Генериране на временно класиране...",past,all);
            past++;
         }
         reg_count[profile_id][sextype]=count;
         if (DEBUG==true&&show_comm==1) {
            out=fopen(("After cutting persons."+String(profile_id)+"-"+String(sextype)+".txt").c_str(),"w");
            for (int prn=1;prn<=reg_count[profile_id][sextype];prn++) {
               fprintf(out,"%5d %2d: %.2f\n",regtable[profile_id][sextype][prn]->person_id,regtable[profile_id][sextype][prn]->priority,getBAL(regtable[profile_id][sextype][prn]->person_id,regtable[profile_id][sextype][prn]->priority));
            }
            fclose(out);
         }
      }
   }
}
void __fastcall TClassificate::Do1Classification(int all) {
 int counter,s;
 int xid;
 /*
   At first regtable must be filled with persons who have the wanted profile as first wish.
   The sex of persons is very important!
 */
   for (int profile_id=1;profile_id<=Data->ProfilesTable->RecordCount;profile_id++) {
      if (ProfilesTable[profile_id]->DiffMW) s=0; else s=1;
      for (int sextype=1;sextype>=s;sextype--) {
         counter=1;
         for (int pID=1;pID<=all;pID++) {
            if (Persons[pID]->exist!=true) continue;
            xid=1;
            while (Persons[pID]->wsh[xid]->bal<1&&Persons[pID]->wsh[xid]->profile_id!=0) xid++;
            if (Persons[pID]->wsh[xid]->profile_id!=profile_id) continue;
            if (ProfilesTable[profile_id]->DiffMW&&Persons[pID]->sex!=sextype) continue;
            if (Persons[pID]->wsh[xid]->bal<1) continue;
            if (Persons[pID]->bound<xid) continue;
            regtable[profile_id][sextype][counter]->person_id=pID;
            regtable[profile_id][sextype][counter]->priority=xid;
          // saving in Persons classification...
            Persons[pID]->reg_index=counter;
            Persons[pID]->reg_priority=xid;

            counter++;
         }
         reg_count[profile_id][sextype]=counter-1;
      }
   }

 /*
   Then searching regtable for everyone able to classificate
 */
 FILE *out;

   for (int profile_id=1;profile_id<=Data->ProfilesTable->RecordCount;profile_id++) {

      if (ProfilesTable[profile_id]->DiffMW) s=0; else s=1;
      for (int sextype=1;sextype>=s;sextype--) {
         MainForm->ShowProgress("Класиране по първо желание...",profile_id*(sextype+1),2*Data->ProfilesTable->RecordCount);
         sortRegTable(1,reg_count[profile_id][sextype],profile_id,sextype);
         if (DEBUG==true) {
            out=fopen(("After sorting."+String(profile_id)+"-"+String(sextype)+".txt").c_str(),"w");
            for (int prn=1;prn<reg_count[profile_id][sextype];prn++) {
               fprintf(out,"%5d %2d: %.2f\n",regtable[profile_id][sextype][prn]->person_id,regtable[profile_id][sextype][prn]->priority,getBAL(regtable[profile_id][sextype][prn]->person_id,regtable[profile_id][sextype][prn]->priority));
            }
            fclose(out);
         }
      }
   }
 /*
   Now it's time to cut some candidates
 */
   cutPersons(1);
 /*
   Now shifting down unaccepted persons in their wishes
 */
 int r;
 bool ok;
   do {
      r=0;
      for (int pID=1;pID<=all;pID++) {
         if (Persons[pID]->exist!=true) continue;
         if (Persons[pID]->reg_index!=0||Persons[pID]->reg_priority==0) continue; // already accepted
         r++;
         ok=false;
         for (int pri=1;pri<=Persons[pID]->bound;pri++) {
            //if (pri<=Persons[pID]->reg_priority) continue;
            if (Persons[pID]->wsh[pri]->profile_id==0) break; // end of wishes
            if (Persons[pID]->wsh[pri]->bal==0) continue;     // bad wish
            if (Persons[pID]->wsh[pri]->bal>=getMinBAL(Persons[pID]->wsh[pri]->profile_id,Persons[pID]->sex)) {
             // registering person with current wish...
               if (setAccepted(pID,pri)) r--;
               ok=true;
               break;
            }
         }
         if (ok==false) Persons[pID]->reg_index=-1; // removed from classification
      }
      cutPersons(all,0);
   } while (r!=0);
 /*
   That's it! All done.
 */
   if (DEBUG==true) {
      for (int profile_id=1;profile_id<=Data->ProfilesTable->RecordCount;profile_id++) {

         if (ProfilesTable[profile_id]->DiffMW) s=0; else s=1;
         for (int sextype=1;sextype>=s;sextype--) {
            out=fopen(("First Classification."+String(profile_id)+"-"+String(sextype)+".txt").c_str(),"w");
            for (int prn=1;prn<=reg_count[profile_id][sextype];prn++) {
               fprintf(out,"%5d %2d: %.2f\n",regtable[profile_id][sextype][prn]->person_id,regtable[profile_id][sextype][prn]->priority,getBAL(regtable[profile_id][sextype][prn]->person_id,regtable[profile_id][sextype][prn]->priority));
            }
            fclose(out);
         }
      }
   }
}
//===================================================================
void __fastcall TClassificate::SaveToDatabase(int all) {
 int s;
 int ix=0;
   MainForm->ShowProgress("Записване на класирането...",0,0);
   Data->SingleQuery->Active=false;
   Data->SingleQuery->SQL->Clear();
   Data->SingleQuery->SQL->Add("INSERT INTO Register(Classificated,Profile_ID,Person_ID,Amount,IsIn) \
VALUES (:SET_CLASSIFICATED,:SET_PROFILE,:SET_PERSON,:SET_AMOUNT,:SET_ISIN)");
   Data->SingleQuery->Prepare();

   for (int profile_id=1;profile_id<=Data->ProfilesTable->RecordCount;profile_id++) {
      if (ProfilesTable[profile_id]->DiffMW) s=0; else s=1;
      for (int sextype=1;sextype>=s;sextype--) {
         MainForm->ShowProgress("Записване на класирането.",ix,0);
         ix++;
         for (int p=1;p<=reg_count[profile_id][sextype];p++) {
            Data->SingleQuery->ParamByName("SET_CLASSIFICATED")->AsInteger=1;
            Data->SingleQuery->ParamByName("SET_PROFILE")->AsInteger=profile_id;
            Data->SingleQuery->ParamByName("SET_PERSON")->AsInteger=regtable[profile_id][sextype][p]->person_id;
            Data->SingleQuery->ParamByName("SET_AMOUNT")->AsFloat=Persons[regtable[profile_id][sextype][p]->person_id]->wsh[regtable[profile_id][sextype][p]->priority]->bal;
            Data->SingleQuery->ParamByName("SET_ISIN")->AsInteger=Persons[regtable[profile_id][sextype][p]->person_id]->isIn;
            Data->SingleQuery->ExecSQL();
         }
      }
   }
 // saving persons in waiting wishes as unregistered
   for (int n=1;n<=all;n++) {
      if (Persons[n]->exist!=true) continue;
      //if (Persons[n]->reg_index!=0&&Persons[n]->reg_index!=-1) continue;
      if (n%100==0) {
         ix++;
         MainForm->ShowProgress("Записване на класирането.",ix,0);
      }
      for (int w=1;w<=Persons[n]->bound;w++) {
         if (Persons[n]->wsh[w]->profile_id==0) break;
         if (Persons[n]->wsh[w]->bal==0) continue;
         if (Persons[n]->reg_index>0&&w>=Persons[n]->reg_priority) break;
         // don't save lower than registered wishes
         Data->SingleQuery->ParamByName("SET_CLASSIFICATED")->AsInteger=0;
         Data->SingleQuery->ParamByName("SET_PROFILE")->AsInteger=Persons[n]->wsh[w]->profile_id;
         Data->SingleQuery->ParamByName("SET_PERSON")->AsInteger=n;
         Data->SingleQuery->ParamByName("SET_AMOUNT")->AsFloat=Persons[n]->wsh[w]->bal;
         //Data->SingleQuery->ParamByName("SET_ISIN")->AsInteger=Persons[n]->isIn;
         Data->SingleQuery->ParamByName("SET_ISIN")->AsInteger=0;
         Data->SingleQuery->ExecSQL();
      }
   }

   Data->SingleQuery->UnPrepare();
}
//==========================================================
//       Second Classification
void __fastcall TClassificate::InitPerviousClassification(int all) {
 int s;
 bool Classificated,isIn;
 int person_id,priority,sextype,profile_id;
 float amount;
   for (int t=1;t<=all;t++) Persons[t]->exist=false;
   for (int p=1;p<=Data->ProfilesTable->RecordCount;p++)
      for (int s=0;s<=1;s++) reg_count[p][s]=0;

   Data->InitClassifQuery->Active=false;
   Data->InitClassifQuery->SQL->Clear();
   Data->InitClassifQuery->SQL->Add("SELECT r.*,p.Sex,wsh.Priority FROM Register r LEFT OUTER JOIN Persons p ON r.Person_id=p.ID,Wishes wsh \
WHERE wsh.Person_id=p.ID AND wsh.Profile_id=r.Profile_ID \
ORDER BY Classificated DESC,r.Profile_ID,Amount DESC,r.Person_ID");
   Data->InitClassifQuery->Active=true;

   Data->InitClassifQuery->First();
   for (int p=1;p<=Data->InitClassifQuery->RecordCount;p++) {
      profile_id=Data->InitClassifQuery->FieldByName("Profile_ID")->AsInteger;
      sextype=ProfilesTable[profile_id]->sexindex(Data->InitClassifQuery->FieldByName("Sex")->AsInteger);
      Classificated=Data->InitClassifQuery->FieldByName("Classificated")->AsBoolean;
      person_id=Data->InitClassifQuery->FieldByName("Person_ID")->AsInteger;
      isIn=Data->InitClassifQuery->FieldByName("IsIn")->AsBoolean;
      priority=Data->InitClassifQuery->FieldByName("Priority")->AsInteger;
      if (p%20==0) MainForm->ShowProgress("Инициализиране на класирането...",p,all);

      Persons[person_id]->exist=true;
      if (Classificated) {
         reg_count[profile_id][sextype]++;
         regtable[profile_id][sextype][reg_count[profile_id][sextype]]->person_id=person_id;
         regtable[profile_id][sextype][reg_count[profile_id][sextype]]->priority=priority;
      }

      if (Classificated) {
         Persons[person_id]->reg_index=reg_count[profile_id][sextype];
         Persons[person_id]->reg_priority=priority;
         Persons[person_id]->isIn=isIn;
      } else {
         if (Persons[person_id]->reg_index==0) { // not registered yet
            if (Persons[person_id]->reg_priority<priority)
               Persons[person_id]->reg_priority=priority;
          // the lowest priority
         }
      }
      Data->InitClassifQuery->Next();
   }
}
void __fastcall TClassificate::Do2Classification(int all) {
 FILE *out;
 int s;
 int profile_id,sextype,index;
 bool remove;
   for (int pID=1;pID<=all;pID++) {
      if (Persons[pID]->exist!=true) continue;
      // veroiatno greshka. ako ne se e zapisal?
      profile_id=Persons[pID]->wsh[Persons[pID]->reg_priority]->profile_id;
      sextype=ProfilesTable[profile_id]->sexindex(Persons[pID]->sex);

      index=Persons[pID]->reg_index;
      if (index>0&&Persons[pID]->isIn!=true) { // delete person from classification
         for (int x=Persons[pID]->reg_index;x<reg_count[profile_id][sextype];x++) {
            regtable[profile_id][sextype][x]->person_id=regtable[profile_id][sextype][x+1]->person_id;
            regtable[profile_id][sextype][x]->priority=regtable[profile_id][sextype][x+1]->priority;
            Persons[regtable[profile_id][sextype][x]->person_id]->reg_index--;
         }
         reg_count[profile_id][sextype]--;
         Persons[pID]->reg_index=0;
      }
      if (index>0) { // already accepted
         remove=true;
         for (int w=1;w<Persons[pID]->reg_priority;w++) {
            if (Persons[pID]->wsh[w]->profile_id==0) break;
            if (Persons[pID]->wsh[w]->bal==0) continue;
            if (Persons[pID]->wsh[w]->bal>=getMinBAL(Persons[pID]->wsh[w]->profile_id,sextype)) {
               setAccepted(pID,w);
               remove=false;
               break;
            }
         }
         if (remove==true) Persons[pID]->exist=false;
      }
   }
   cutPersons(all,0);
 int r;
 bool ok;
   if (DEBUG) {
      for (int profile_id=1;profile_id<=Data->ProfilesTable->RecordCount;profile_id++) {
         if (ProfilesTable[profile_id]->DiffMW) s=0; else s=1;
         for (int sextype=1;sextype>=s;sextype--) {
            out=fopen(("Next Classif-after cutting."+String(profile_id)+"-"+String(sextype)+".txt").c_str(),"w");
            for (int prn=1;prn<=reg_count[profile_id][sextype];prn++) {
               if (Persons[regtable[profile_id][sextype][prn]->person_id]->exist!=true) continue;
               fprintf(out,"%5d %2d: %.2f\n",regtable[profile_id][sextype][prn]->person_id,regtable[profile_id][sextype][prn]->priority,getBAL(regtable[profile_id][sextype][prn]->person_id,regtable[profile_id][sextype][prn]->priority));
            }
            fclose(out);
         }
      }
   }
   do {
      r=0;
      for (int pID=1;pID<=all;pID++) {
         if (Persons[pID]->exist!=true) continue;
         if (Persons[pID]->reg_index!=0||Persons[pID]->reg_priority==0) continue; // already accepted
         r++;
         ok=false;
         for (int pri=1;pri<Persons[pID]->wsh_cnt;pri++) {
            if (pri>=Persons[pID]->reg_priority) continue;
            if (Persons[pID]->wsh[pri]->profile_id==0) break; // end of wishes
            if (Persons[pID]->wsh[pri]->bal==0) continue;     // bad wish
            if (Persons[pID]->wsh[pri]->bal>=getMinBAL(Persons[pID]->wsh[pri]->profile_id,Persons[pID]->sex)) {
             // registering person with current wish...
               if (setAccepted(pID,pri)) r--;
               ok=true;
               break;
            }
         }
         if (ok==false) Persons[pID]->reg_index=-1; // removed from classification
      }
      cutPersons(all,0);
   } while (r!=0);
   if (DEBUG) {
      for (int profile_id=1;profile_id<=Data->ProfilesTable->RecordCount;profile_id++) {
         if (ProfilesTable[profile_id]->DiffMW) s=0; else s=1;
         for (int sextype=1;sextype>=s;sextype--) {
            out=fopen(("Next Classification."+String(profile_id)+"-"+String(sextype)+".txt").c_str(),"w");
            for (int prn=1;prn<=reg_count[profile_id][sextype];prn++) {
               if (Persons[regtable[profile_id][sextype][prn]->person_id]->exist!=true) continue;
               fprintf(out,"%5d %2d: %.2f\n",regtable[profile_id][sextype][prn]->person_id,regtable[profile_id][sextype][prn]->priority,getBAL(regtable[profile_id][sextype][prn]->person_id,regtable[profile_id][sextype][prn]->priority));
            }
            fclose(out);
         }
      }
   }
}
//==========================================================
void __fastcall TClassificate::Execute()
{
 int all;
 bool flag=false;
   start=Now();
   try {
      CreateData(all);         // allocating required memory
      InitData();              // initialize data
      //Sleep(1000);
      switch (MainForm->Tag) {
       case 1:    // first classification
         PrepareFirstClassification(all);
         Do1Classification(all);  // make the classification
       break;
       case 2:    // next classification
         InitPerviousClassification(all);
         PrepareNextClassification(all);
         Do1Classification(all);  // make the classification
       //-------------------

         MainForm->ShowProgress("Изчистване на предишното класиране...",0,0);
         Data->SingleQuery->Active=false;
         Data->SingleQuery->SQL->Clear();
         Data->SingleQuery->SQL->Add("DELETE FROM Register");
         Data->SingleQuery->ExecSQL();

         Data->RegisterNumQuery->Active=true;
         Data->RegisterNumQuery->Edit();
         Data->RegisterNumQuery->FieldByName("RegisterNumber")->AsInteger=Data->RegisterNumQuery->FieldByName("RegisterNumber")->AsInteger+1;
         Data->RegisterNumQuery->Post();
         Data->RegisterNumQuery->CommitUpdates();

       break;

      }
      SaveToDatabase(all);     // saving work to database
      ClearData(all);          // freeing allocated memory

      end=Now();
   } catch (Exception *E) {
      if (DEBUG)
         Application->ShowException(E);
      else
         Application->MessageBox("Грешка при генериране на класирането.\nМоля, потърсете системния администратор!","Вътрешна грешка",MB_ICONERROR|MB_APPLMODAL|MB_OK);
      MainForm->mainlog->WriteException(E->Message);
      flag=true;
   }
   start=end-start;
   if (flag==false) MainForm->ShowProgress("Класирането завършено ("+FormatDateTime("hh:nn:ss.z",start)+")",0,0);
   else MainForm->ShowProgress("Грешка при класирането! ("+FormatDateTime("hh:nn:ss.z",start)+")",0,0);

   MainForm->ClassificateBtn->Enabled=true;
   MainForm->ClassificateClearBtn->Enabled=true;
   MainForm->ScndClassificateBtn->Enabled=true;
   //MessageBeep(MB_ICONASTERISK);
   MessageBeep(0xFFFFFFFF);
}
//---------------------------------------------------------------------------
