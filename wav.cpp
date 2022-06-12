#include "wav.h"



wav::wav()
{    }

void write_as_bytes(std::ofstream &file, int value, int byte_size) {
    file.write(reinterpret_cast<const char*>(&value), byte_size);
}

void static wavFileCreate() {
    std::ofstream wave;
    wave.open("test.wav", std::ios::binary);

    wav wavProperies;




    if(wave.is_open()){

        wave << wavProperies.get_chunk_id();
        wave << wavProperies.get_chunk_size();
        wave << wavProperies.get_audio_format();

        wave << wavProperies.get_subchunk1_id();
        write_as_bytes(wave, wavProperies.get_subchunk1_size(), 4);
        write_as_bytes(wave, wavProperies.get_audio_format(), 2);
        write_as_bytes(wave, wavProperies.get_num_channels(), 2);
        write_as_bytes(wave, wavProperies.get_sample_rate(), 4);
        write_as_bytes(wave, wavProperies.get_byte_rate(), 4);
        write_as_bytes(wave, wavProperies.get_block_alitn(), 2);
        write_as_bytes(wave, wavProperies.get_bits_per_sample(), 2);

        wave << wavProperies.get_subchunk2_id();
        wave << wavProperies.get_subchunk2_size();


        // tests
        const unsigned short n_frequencies = 8;
        const unsigned short n_seconds_each = 1;
        float frequencies[n_frequencies] = { 55.0, 110.0, 220.0, 440.0, 880.0, 1760.0, 3520.0, 7040.0 };


        int start_audio = wave.tellp();

//        for (unsigned short i = 0; i < n_frequencies; ++i) {
            for(int i = 0; i < wavProperies.get_sample_rate() * wavProperies.get_duration(); i++){
                double amplitude = (double)i / wavProperies.get_sample_rate() * wavProperies.get_max_amplitude();
                double value = sin((2 * 3.14 * i * wavProperies.get_frequency()) / wavProperies.get_sample_rate());

                double channel = amplitude * value;
                // 2 or 4?
                write_as_bytes(wave, channel, 4);
            }

//        }


        int end_audio = wave.tellp();
        wave.seekp(start_audio - 4);
        write_as_bytes(wave, end_audio - start_audio, 4);

        wave.seekp(4, std::ios::beg);
        write_as_bytes(wave, end_audio - 8, 4);

    }
    wave.close();
}
