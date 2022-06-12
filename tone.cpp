#include "tone.h"
#include <math.h>

Tone::Tone()
{ }


std::vector<short> Tone::generateSineInTimeDomain(float frequency) {
    this->sample_size = round(duration * samplingRate);

    std::vector<short> sample(this->sample_size);
    for (int i = 0; i < sample.size(); ++i)
    {
        float currentTime = (float)(i) / this->samplingRate;
        sample[i] = (short)(32767 * sin(M_PI * 2 * frequency * currentTime));
    }
    return sample;
}



// to implement
void Tone::PlayTone() { }
void Tone::StopTone() { }
