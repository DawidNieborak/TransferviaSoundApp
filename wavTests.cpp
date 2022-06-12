//#include <iostream>
//#include <math.h>
//#include <string.h>
//#include <fstream>

//const std::string chunk_id = "RIFF";
//const std::string  chunk_size ="----";
//const std::string format = "WAVE";
//const std::string  subchunk1_id = "fmt ";

//const int subchunk1_size = 16;
//const int audio_format = 1;
//const int num_channels = 1;
//const int sample_rate = 44100;
//const int byte_rate = sample_rate * num_channels *(subchunk1_size / 8);
//const int block_alitn = num_channels * (subchunk1_size / 8);
//const int bits_per_sample = 16;

//// Data sub-chunk
//const std::string subchunk2_id = "data";
//const std::string subchunk2_size = "----";

//const int duration = 3;
//const int max_amplitude = 32760;
//const double frequency = 250;

//void write_as_bytes(std::ofstream &file, int value, int byte_size){
//    file.write(reinterpret_cast<const char*>(&value), byte_size);
//}

//void wavFileTestsRun() {
//    std::ofstream wav;
//    wav.open("test.wav", std::ios::binary);

//    if(wav.is_open()){
//        wav << chunk_id;
//        wav << chunk_size;
//        wav << format;

//        wav << subchunk1_id;
//        write_as_bytes(wav, subchunk1_size, 4);
//        write_as_bytes(wav, audio_format, 2);
//        write_as_bytes(wav, num_channels, 2);
//        write_as_bytes(wav, sample_rate, 4);
//        write_as_bytes(wav, byte_rate, 4);
//        write_as_bytes(wav, block_alitn, 2);
//        write_as_bytes(wav, bits_per_sample, 2);

//        wav << subchunk2_id;
//        wav << subchunk2_size;

//        int start_audio = wav.tellp();

//        for(int i = 0; i < sample_rate * duration; i++){
//            double amplitude = (double)i / sample_rate * max_amplitude;
//            double value = sin((2 * 3.14 * i * frequency) / sample_rate);

//            double channel = amplitude * value;
//            // 2 or 4?
//            write_as_bytes(wav, channel, 4);
//        }

//        int end_audio = wav.tellp();
//        wav.seekp(start_audio - 4);
//        write_as_bytes(wav, end_audio - start_audio, 4);

//        wav.seekp(4, std::ios::beg);
//        write_as_bytes(wav, end_audio - 8, 4);

//    }
//    wav.close();
//}
