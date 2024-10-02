
#include "CanCoutPeriph.h"
#include <iostream>

using namespace std;

    void CanCout::SendFrame(const Frame& frame){

        cout << "frame am can: id: 0x" << hex << (int)frame.id << "  and data : " ;
        for (int i: frame.data){
            cout  << "0x" << hex << (int)frame.data[i] << " , " ;
        }
        cout << endl;
    }