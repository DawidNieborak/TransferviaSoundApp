#ifndef TONE_H
#define TONE_H


#include <iostream>
#include <string>
#include <vector>
#include <math.h>

class Tone
{
    // temp public
public:
    int samplingRate = 44100;
    float duration = 0.5f;
    int sample_size = round(duration * samplingRate);

    // Boolean
    bool isRunning = false;


  public:
    Tone();


    std::vector<short> generateSineInTimeDomain(float frequency);

    // Todo:
    void PlayTone();
    void StopTone();
};

#endif // TONE_H
