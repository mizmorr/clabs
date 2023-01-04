#include <iostream>
#include <set>
using namespace std;

bool cont3(int t,std::set <int> *obj)
{
    auto i  = obj->find(t);
    return i!=obj->end();

}

    bool contains(set<int> a, int b){
	return a.count(b)!=0;
   }
int main() {

std::set <int> obj{1,2,3,4};
if (!contains(obj,1))
    cout<<"not cont";
else cout<<"cont";
cout<<cont3(3,&obj);
return 0;
}
