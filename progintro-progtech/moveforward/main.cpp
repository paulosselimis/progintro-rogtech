#include <iostream>  
using namespace std;  
  
class list {  
public:  
       list   ();              /* κατασκευαστής:  κατασκευάζει μία κενή λίστα */  
  bool empty  ();              /* ελέγχει αν η λίστα είναι κενή */  
  int  size   ();              /* επιστρέφει το μέγεθος της λίστας */  
  void add    (int k, int x);  /* εισάγει το στοιχείο x στη θέση k της λίστας */  
  int  get    (int k);         /* επιστρέφει την τιμή του στοιχείου στη θέση k της λίστας */  
  void remove(int k);         /* διαγράφει το στοιχείο στη θέση k της λίστας */  
  int searchMF (int x);  
private:   
  struct node {  
    int info;  
    node *next;  
};  
  node *head;  
   
};  
  
list::list() { head=nullptr; }  
bool list::empty() { return head==nullptr; }  
int list::size() { node *p; int s=0;  
for(p=head; p!=nullptr; p=p->next) s++;  
return s; }  
  
void list::add(int k, int x) {  
    node *extranode=new node;    
    extranode->info=x;    
    node *p=head;    
    if (k==1){    
extranode->next=head;    
 head=extranode;    
}    
else{    
 for (int i=1; i<k-1; i++){    
p=p->next;    
}    
extranode->next=p->next;    
 p->next=extranode;    
 }    
}  
  
int list::get(int k) { node *p=head;  
     for (int i=1; i<k; i++) p=p->next;  
     return p->info;  
}  
  
void list::remove(int k) {  
    node *extranode=head;  
      
    if(k==1) {  
        head=extranode->next;  
        delete extranode;  
    }  
    else {  
        node *p=head;  
    for (int i=1; i<k-1; i++){    
p=p->next;  }  
    for (int i=1; i<k; i++) extranode=extranode->next;  
    p->next=extranode->next;  
    delete extranode;  
} }  
  
int list::searchMF(int x) {  
    node *p;  
    node *q=head;  
    int thesi=1;  
    for(p=head; p!=nullptr; p=p->next) {  
        if(p->info==x) break;  
        thesi++;  
        if(p->next==nullptr) return 0;  
    }  
    for (int i=1; i<thesi-1; i++) q=q->next;  
    q->next=p->next;  
    p->next=head;  
    head=p;  
      
    return thesi;  
}  
  
int main () {  
    list l;  
    int sum=0;  
    int N; cin >> N;  
    int k, x;  
    for(int i=0; i<N; i++) {  
        cin >> k; cin >> x;  
        l.add(k, x);  
    }  
    int M; cin >> M;  
    for(int i=0; i<M; i++) {  
        cin >> x;  
        sum=sum+l.searchMF(x);  
    }  
    cout << sum << endl;  
      
    return 0;  
}  