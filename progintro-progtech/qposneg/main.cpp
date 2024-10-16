#include <iostream>


using namespace std;

class queue {
public:
       queue   ();       /* κατασκευαστής:  κατασκευάζει μία κενή ουρά */
  bool empty   ();       /* ελέγχει αν η ουρά είναι κενή */
  void enqueue (int x);  /* εισάγει ένα στοιχείο στην ουρά */
  int  dequeue ();       /* αφαιρεί ένα στοιχείο από μια μη κενή ουρά */
  int  peek    (); /* επιστρέφει (χωρίς να αφαιρεί) το πρώτο στοιχείο μιας μη κενής ουράς */
private:
struct node {
    int info;
    node *next;
};
node *front, *rear;
};

queue::queue() { front = rear = nullptr; }

bool queue::empty() { return front==nullptr; }

void queue::enqueue(int x) {
    node *p= new node;
    p->info=x;
    p->next=nullptr;
    if (front==nullptr) front = p;
    else rear->next=p;
    rear=p;
}

int queue::dequeue() {
  node *p=front;
  int result=front->info;
  if(front == rear) rear=nullptr;
  front=front->next;
  delete p;
  return result;
}

int queue::peek() {
    int result=front->info;
    return result;
}

int main()
{
    queue arn, the;
    int i, a, t;
    a=t=0;
    
    while (cin>>i)
    {
          
      if(i>0)   { the.enqueue(i); t++; }
         
       else { arn.enqueue(i); a++; }
        
    }
   
    
    if(a!=t) { cout << "no" << endl; return 0; }
    
    for(int j=0; j<a; j++) {
            if(the.dequeue()!=-arn.dequeue()) { cout << "no" << endl; return 0; }
        }
    
    cout << "yes" << endl;
    
    return 0;
}





