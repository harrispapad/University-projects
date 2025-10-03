#include "iostream"
#include "cstdio"
using namespace std;

class queue {

  public:
    queue();
    bool empty();
    void enqueue (int x);
    int dequeue();
    int peek();

  private:
    int data[1000000];
    int top;
};

queue::queue(){
  top = 0;
}

bool queue::empty(){
  return top == 0;
}

void queue::enqueue(int x){
  data[top++] = x;
}

int queue::dequeue(){
  return data[--top];
}

int queue::peek(){
  return data[top];
}

int main(){

int a[10000000], i=0;
bool same = false, empty = false;
queue positive;
queue negative;

while(true){
  cin>>a[i];
  if (a[i] > 0) positive.enqueue(a[i]);
  else if (a[i] < 0) negative.enqueue(a[i]);
  else break;
  i++;
}

while (!positive.empty() && !negative.empty()){
  same = true;
  if(abs(positive.dequeue()) != abs(negative.dequeue())) {
    same = false;
    break;
  }
}

if (positive.empty() && negative.empty()) empty = true;

if(same && empty) cout<<"yes"<<endl;
else cout<<"no"<<endl;
}
