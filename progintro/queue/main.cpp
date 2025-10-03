#include <iostream>
using namespace std;

class queue {
public:
    queue();
    bool empty();
    void enqueue(int x);
    int dequeue();
private:
    struct node{
    int info;
    node *next;
    };
    node *front, *rear;
};

queue::queue(){
    front = rear = nullptr;
}

bool queue::empty(){
    return front == nullptr;
}

void queue::enqueue(int x){
    node *p = new node;
    p->info = x;
    p->next = nullptr;
    if (front == nullptr)
        front = p;
    else
        rear->next = p;
    rear = p;
}

int queue::dequeue(){
    node *p = front;
    int result = front->info;
    if (front == rear)
        rear = nullptr;
    front = front->next;
    delete p;
    return result;
}

int main(){
    queue q;
    for(int i=0; i<10; i++) q.enqueue(i);

    while (!q.empty())
        cout<<q.dequeue()<<endl;
}

