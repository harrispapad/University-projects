#include <iostream>
using namespace std;

class list {
public:
  list   ();                         // κατασκευαστής:  κατασκευάζει μία κενή λίστα
  bool empty   ();                   // ελέγχει αν η λίστα είναι κενή
  int  size    ();                   // επιστρέφει το μέγεθος της λίστας
  void add     (int k, int x);       // εισάγει το στοιχείο x στη θέση k της λίστας
  int  get     (int k);              // επιστρέφει την τιμή του στοιχείου στη θέση k της λίστας
  void remove  (int k);              // διαγράφει το στοιχείο στη θέση k της λίστας
  int searchMF (int k);              // βρίσκει το στοιχείο k και το μετακινεί στην αρχή της λίστας
  void print   ();                   // εκυπώνει την λίστα

private:
    struct node {                    // υλοποίηση με συνδεδεμένη λίστα
    int info;
    node *next;
    };
    node *head;z
};

list::list(){
    head = nullptr;
}

bool list::empty(){
    return head == nullptr;
}

int list::size(){
    node *p = head;
    int size=0;

    while(p != nullptr){
        size++;
        p = p->next;
    }

    return size;
}

void list::add(int k, int x){
    node *q = new node();
    q->info = x;
    if (k == 0){
        q->next = head;
        head = q;
    }
    else{
        node *p = head;
        while(k>1) {
            p = p->next;
            --k;
        }
        q->next = p->next;
        p->next = q;
    }
}

int list::get (int k){
    int position = 1;
    node *p = head;

    while (position != k){
        p = p->next;
        position++;
    }

    return p->info;
}

void list::remove(int k){
    if (head == nullptr){
        return;
    }
    else{
        node *p, *q;
        if (k==0){
            q = head;
            head = head->next;
            delete(q);
        }
        else{
            p = q = head;
            while(k>0){
                k--;
                p = q;
                q = q->next;
            }
            p->next = q->next;
            delete(q);
        }
    }
}

int list::searchMF(int k){
    int position=0;
    bool found = false;
    node *p = head;

    while(true){
        if(p->info == k){
            found = true;
            list::remove(position);
            list::add(0, k);
            break;
        }
        else {
            if(p->next == nullptr)
                break;
            else {
                position++;
                p = p->next;
            }
        }
    }
    if(found)
        return (position+1);
    else
        return 0;
}

void list::print(){
	if (head == nullptr){
		cout<<endl;
	}
	else{
		node *p = head;
		while (p != nullptr){
			cout<<p->info<<" ";
			p = p->next;
		}
		cout<<endl;
	}
}


int main(){
int n, k, x, m, size=1;
cin>>n;
list l;

l.add(0, 0);                         // δημιουργία της μηδενικής θέσης διότι στην εκφώνηση οι θέσεις ξεκινάνε από το 1
for (int i=0; i<n; i++){
    cin>>k>>x;
    if (k>(size+1))
        l.add(size,x);               // σε περίπτωση που δεν υπάρχουν τα απαραίτητα κουτιά πριν την ζητούμενη θέση, προσθήκη στο τωρινό τέλος της λίστας
    else l.add(k, x);
    size++;
}

l.remove(0);

cin>>m;
for (int f=0; f<m; f++){
    cin>>k;
    l.remove(k-1);
}

cin>>m;
for (int f=0; f<m; f++){
    cin>>k;
    l.remove(k-1);
}

cin>>k;
cout<<l.size()<<" "<<l.get(k)<<endl;
}
