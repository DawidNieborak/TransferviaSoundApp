#include <iostream>

const int numbers[] = {0,1,2,3,4,5,6,7,8,9};
const int lowerBound[] = {896, 1408, 1920, 2432, 2944, 3456, 3968, 4480, 4992, 5504};
const int upperBound[] = {1152, 1664, 2176, 2688, 3200, 3712, 4224, 4736, 5248, 5760};
const int frequency[] = {1024, 1536, 2048, 2560, 3072, 3584, 4096, 4608, 5120, 5632};
int ASCIIValue;

void setASCIIValue(int asciiValue) {
    ASCIIValue = asciiValue;
}

int indexOf(int digit){
    for(int i = 0; i< sizeof(numbers); i++){
        if(numbers[i] == digit) {
            return i;
        }
    }
    return -1;
}


char * ASCIIToFrequency (){
    char a[9]; // the frequency
    int i = 0;
    while (ASCIIValue*2) { // loop till there's nothing left
        a[i++] = ASCIIValue % 10; // assign the last digit
        ASCIIValue /= 10; // "right shift" the number
    }

    for(int i = 0;i<sizeof(a); i++) {
        if(i%2 == 0) {
            int digit = a[i];


            int index = indexOf(digit);
            if (index != -1)
                a[i] = a[index];
        } else {
            a[i] = 9000;
        }

    }

    for (int j = 0; j < sizeof(a); j++){
        std::cout << a[j] << std::endl;
    }

    return a;
}

int frequencyToNumber(int frequency){
    for(int i = 0; i< sizeof(lowerBound); i++) {
        if(frequency >= lowerBound[i] && frequency <= upperBound[i]){
            return numbers[i];
        }
    }
    return 0;
}


