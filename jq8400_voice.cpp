/**
 * @file jq8400_voice.cpp
 * @author Felícito Manzano (felicito.manzano@detektor.com.sv)
 * @brief 
 * @version 0.1
 * @date 2020-09-22
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "mbed.h"
#include "BufferedSerial.h"
//#include "queue.h"
#include "playlist.hpp"

//VOLUME
/**
* @brief 
* 
*/
const char      SET_VOLUME_MUTE[]        = {0xAA, 0x13, 0x01, 0x00, 0xBE};
const char      SET_VOLUME_VERY_LOW[]    = {0xAA, 0x13, 0x01, 0x05, 0xC3};
const char      SET_VOLUME_LOW[]         = {0xAA, 0x13, 0x01, 0x0A, 0xC8};
const char      SET_VOLUME_MEDIUM[]      = {0xAA, 0x13, 0x01, 0x0F, 0xCD};
const char      SET_VOLUME_HIGH[]        = {0xAA, 0x13, 0x01, 0x14, 0xD2};
const char      SET_VOLUME_VERY_HIGH[]   = {0xAA, 0x13, 0x01, 0x19, 0xD7};
const char      SET_VOLUME_MAXIMUM[]     = {0xAA, 0x13, 0x01, 0x1E, 0xDC};
extern queue    colaPlaylist;

/**
 * @brief 
 * 
 * @param id_file 
 * @param puertoCOM 
 * @return true 
 * @return false 
 */
bool jq8400_playID(int id_file, BufferedSerial *puertoCOM) {
    const int id_track = id_file;
    char char_play[6] =  {0xAA,0x07,0x02,0x00,char (id_track),char (id_track+0xB3)};
    puertoCOM->write(char_play, sizeof(char_play));
    return(true);
}

/**
 * @brief 
 * 
 * @param id_volume 
 * @param puertoCOM 
 * @return true 
 * @return false 
 */
bool jq8400_iniVol(int id_volume, BufferedSerial *puertoCOM) {

    switch (id_volume) {
        case 1:
            puertoCOM->write(SET_VOLUME_VERY_LOW, sizeof(SET_VOLUME_VERY_LOW));
            break;

        case 2:
            puertoCOM->write(SET_VOLUME_LOW, sizeof(SET_VOLUME_LOW));
            break;
            
        case 3:
            puertoCOM->write(SET_VOLUME_MEDIUM, sizeof(SET_VOLUME_MEDIUM));
            break;
            
        case 4:
            puertoCOM->write(SET_VOLUME_HIGH, sizeof(SET_VOLUME_HIGH));
            break;
            
        case 5:
            puertoCOM->write(SET_VOLUME_VERY_HIGH, sizeof(SET_VOLUME_VERY_HIGH));
            break;
            
        case 6:
            puertoCOM->write(SET_VOLUME_MAXIMUM, sizeof(SET_VOLUME_MAXIMUM));
            break;
    }
return(true);
}


/**
 * @brief 
 * 
 * @param id_volume 
 * @param puertoCOM 
 * @return true 
 * @return false 
 */
bool jq8400_setVol(int *id_volume, BufferedSerial *puertoCOM) {

    switch (*id_volume) {
        case 0:
            puertoCOM->write(SET_VOLUME_MUTE, sizeof(SET_VOLUME_MUTE));
            break;

        case 1:
            puertoCOM->write(SET_VOLUME_VERY_LOW, sizeof(SET_VOLUME_VERY_LOW));
            break;

        case 2:
            puertoCOM->write(SET_VOLUME_LOW, sizeof(SET_VOLUME_LOW));
            break;
            
        case 3:
            puertoCOM->write(SET_VOLUME_MEDIUM, sizeof(SET_VOLUME_MEDIUM));
            break;
            
        case 4:
            puertoCOM->write(SET_VOLUME_HIGH, sizeof(SET_VOLUME_HIGH));
            break;
            
        case 5:
            puertoCOM->write(SET_VOLUME_VERY_HIGH, sizeof(SET_VOLUME_VERY_HIGH));
            break;
            
        case 6:
            puertoCOM->write(SET_VOLUME_MAXIMUM, sizeof(SET_VOLUME_MAXIMUM));
            break;
    }
return(true);
}

/**
 * @brief 
 * 
 * @param id_voice_file 
 * @return true 
 * @return false 
 */
bool jq8400_addQueue(int id_voice_file) {
    colaPlaylist.enqueue(id_voice_file);
    return(true);
}
