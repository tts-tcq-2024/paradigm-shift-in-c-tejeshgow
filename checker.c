#include <stdio.h>
#include <assert.h>

int isOutOfRange(float value, float lower, float upper, const char* message) {
    if (value < lower || value > upper) {
        printf("%s\n", message);
        return 1; // Return 1 to indicate out of range
    }
    return 0; // Return 0 if within range
}

int batteryIsOk(float temperature, float soc, float chargeRate) {
    if (isOutOfRange(temperature, 0, 45, "Temperature out of range!") ||
        isOutOfRange(soc, 20, 80, "State of Charge out of range!") ||
        isOutOfRange(chargeRate, 0, 0.8, "Charge Rate out of range!")) {
        return 0; // Return 0 if any parameter is out of range
    }
    return 1; // Return 1 if all parameters are within range
}

int main() {
    assert(batteryIsOk(25, 70, 0.7));
    assert(!batteryIsOk(50, 85, 0));
    
    return 0;
}
