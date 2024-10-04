#include "CanCoutPeriph.h"
#include <iostream>

using namespace std;

namespace dts {

void CanCout::SendFrame(const Frame& frame){

    cout << "frame am can: id: 0x" << hex << (int)frame.id << ", dlc: " << frame.dlc << ", and data : " ;
    for (int i: frame.data){
        cout  << "0x" << hex << i << " , " ;
    }
    cout << endl;
}

}
