#include <iostream>
using namespace std;

int main() {
    int sensorValue;

    cout << "Enter sensor value: ";
    cin >> sensorValue;

    if (sensorValue >= 0 && sensorValue <= 30) {
        cout << "Status: SAFE" << endl;
    }
    else if (sensorValue >= 31 && sensorValue <= 60) {
        cout << "Status: NORMAL" << endl;
    }
    else if (sensorValue >= 61 && sensorValue <= 80) {
        cout << "Status: WARNING" << endl;
    }
    else if (sensorValue > 80) {
        cout << "Status: CRITICAL" << endl;
    }
    else {
        cout << "Invalid sensor value" << endl;
    }

    return 0;
}