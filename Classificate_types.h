#ifndef __CLASSIFICATE_TYPES_H
#define __CLASSIFICATE_TYPES_H
struct wish {
   int profile_id;
   float bal;
};

class Person {
public:
   Person(int wishes_c) {
      wsh=new wish*[wishes_c+1];
      wsh_cnt=wishes_c;
      for (int x=1;x<=wishes_c;x++) {
         wsh[x]=new wish();
         wsh[x]->profile_id=0;
      }
      exist=false; // does not exist if this isn't overitten
      isIn=false;
      reg_index=0;
      reg_priority=0;
      bound=-1;
      prev_priority=wsh_cnt;
   }
   ~Person() {
      for (int x=1;x<=wsh_cnt;x++) {
         delete wsh[x];
      }
      delete[] wsh;
   }
   int PriorityOfProfile(int profile_id) {
      for (int pri=1;pri<=wsh_cnt;pri++) {
         if (wsh[pri]->profile_id==0) break;
         if (wsh[pri]->profile_id==profile_id) return pri;
      }
      return 0;
   }
   //int id;
   char sex;
   wish **wsh;
   char wsh_cnt;
   bool isIn;
   int reg_index; // index of regtable where this person is classificated
   int reg_priority; // index of profile in regtable ...
   int prev_priority;
   bool exist;
   int bound;
};
struct Register {
   int person_id;
   int priority;
   //bool classificated;
};
struct Profile {
   int spaceForSex(int sex) {
      if (DiffMW==true)
         switch (sex) {
            case 1: return spaceM;
            case 0: return spaceW;
         }
      return spaceM;
   }
   int sexindex(int sex) {
      if (DiffMW==true) return sex;
      else return 1;
   }
   int spaceM,spaceW;
   bool DiffMW;
};
//------------------------

struct node {
   node *next;
   float data;
};

class LinkedList {
public:
   LinkedList() {
      root=NULL;
      last=NULL;
      items=0;
   }
   LinkedList(float data) {
      root=new node();
      root->data=data;
      root->next=NULL;
      last=root;
      items=1;
   }
   ~LinkedList() {
    node *r=root,*n;
      while (r!=NULL) {
         n=r->next;
         delete r;
         r=n;
      }
   }
   void AppendNode(float value) {
    node *n=new node();
      n->data=value;
      n->next=NULL;
      items++;
      if (root==NULL) {
         root=n;
         last=n;
         return;
      }
      if (last==NULL) {
         last=n;
         return;
      }
      last->next=n;
      last=n;
   }
   void AddNewRoot(float value) {
    node *n=new node();
      n->data=value;
      items++;
      if (root==NULL) {
         root=n;
         last=n;
         return;
      }
      n->next=root;
      root=n;
   }
   void DeleteRoot() {
    node *s;
      s=root->next;
      delete root;
      root=s;
      if (items==1) last=s;
      items--;
   }
   node *root;
   node *last;
   int items;
};

#endif
