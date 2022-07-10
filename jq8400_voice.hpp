/**
 * @file jq8400_voice.hpp
 * @author Felícito Manzano (felicito.manzano@detektor.com.sv)
 * @brief 
 * @version 0.1
 * @date 2020-09-22
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef __JQ8400_VOICE_H
#define __JQ8400_VOICE_H 

   
    extern const char SET_VOLUME_MUTE[5];
    extern const char SET_VOLUME_VERY_LOW[5];
    extern const char SET_VOLUME_LOW[5];
    extern const char SET_VOLUME_MEDIUM[5];
    extern const char SET_VOLUME_HIGH[5];
    extern const char SET_VOLUME_VERY_HIGH[5];
    extern const char SET_VOLUME_MAXIMUM[5];


    //FUNTIONS
    extern bool jq8400_playID(int id_voice_file, BufferedSerial *puertoCOM);
    extern bool jq8400_iniVol(int id_volume, BufferedSerial *puertoCOM);
    extern bool jq8400_setVol(int *id_volume, BufferedSerial *puertoCOM);
    extern bool jq8400_addQueue(int id_voice_file);
    
#endif  //__JQ8400_VOICE_H 
