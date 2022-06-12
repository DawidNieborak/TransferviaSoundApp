#ifndef WAV_H
#define WAV_H

#include <math.h>
#include <iostream>
#include <string.h>
#include <fstream>
#include <limits>
#include <stdio.h>


class wav
{
public:
    wav();
    const std::string chunk_id = "RIFF";
    const std::string  chunk_size ="----";
    const std::string format = "WAVE";
    const std::string  subchunk1_id = "fmt ";

    const int subchunk1_size = 16;
    const int audio_format = 1;
    const int num_channels = 1;
    const int sample_rate = 44100;
    const int byte_rate = sample_rate * num_channels *(subchunk1_size / 8);
    const int block_alitn = num_channels * (subchunk1_size / 8);
    const int bits_per_sample = 16;

    // Data sub-chunk
    const std::string subchunk2_id = "data";
    const std::string subchunk2_size = "----";

    const int duration = 3;
    const int max_amplitude = 32760;
    double frequency = 250;

    // getters
    std::string get_chunk_id() {
        return this->chunk_id;
    }

    std::string get_chunk_size() {
        return this->chunk_size;
    }

    std::string get_chunk_format() {
        return this->format;
    }

    std::string get_subchunk1_id() {
        return this->subchunk1_id;
    }

    int get_subchunk1_size() {
        return this->subchunk1_size;
    }

    int get_audio_format() {
        return this->audio_format;
    }

    int get_num_channels() {
        return this->num_channels;
    }

    int get_sample_rate() {
        return this->sample_rate;
    }

    int get_byte_rate() {
        return this->byte_rate;
    }

    int get_block_alitn() {
        return this->block_alitn;
    }

    int get_bits_per_sample() {
        return this->bits_per_sample;
    }

    std::string get_subchunk2_id() {
        return this->subchunk2_id;
    }

    std::string get_subchunk2_size(){
        return this->subchunk2_size;
    }

    int get_duration() {
        return this->duration;
    }

    int get_max_amplitude() {
        return this->max_amplitude;
    }


    // frequency geeters
    int get_frequency() {
        return this->frequency;
    }
    // sfrequency etters
    void set_frequency(double frequency) {
        this->frequency = frequency;
    }


    // functions

    void write_as_bytes(std::ofstream &file, int value, int byte_size);
    void static wavFileCreate();
};

#endif // WAV_H
