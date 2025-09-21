#include <iostream>
#include "container.hpp"

using namespace std;

int main() {
    Container<int> container;
    container.dummy_init();
    container.remove_item(2);
    cout << container << endl;
    container.add(10);
    cout << container << endl;
    container.remove_all_items();
    cout << container << endl;
    
    Container<double> container1;
    cout << container1 << endl;
    container1.add(10.5);
    container1.add(6.5);
    cout << container1 << endl;
    container1.remove_all_items();
    cout << container << endl;

    return 0;
}
