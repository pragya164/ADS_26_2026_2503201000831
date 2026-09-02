#include<iostream>
#include<queue>
using namespace std;
int main() {
    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    q.pop();
    q.pop();
    q.pop();
    q.pop();

    q.push(60);
    q.push(70);
    cout<<"queue elements: ";
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }


}