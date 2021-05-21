#include<stdint.h>
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/mman.h>
#include<stdint.h>
#include "../shared/error.h"

//======================================================
// This section is about types describing the physical
// frame header.
// - Defining types relevant for the physical header
// - Defining lookup-arrays, which convert raw bits to
//    relevant information by using raw bits as index.
//======================================================

#define SYNCWORD_1 0x7FFF
#define VALID_LAYER 2

extern uint16_t sync_word_token; //declared in frames.c
extern uint8_t layer_token;      //declared in frames.c

typedef bool protection_bit;
typedef bool padding_bit;
typedef bool private_bit;
typedef bool copyright_bit;
typedef bool original_bit;

typedef enum syncword{
	sw1 = 0x7FF,
	sw2 = 0xEFF,
	sw3 = 0xFFF,
} syncword;
extern const int syncword_arr[4];

typedef enum mpeg_ver{
	mpeg2_5 = -1,
	MPEG_reserved = -1,
	mpeg2 = -1,
	mpeg1 = 1, //We only support MPEG1.

} mpeg_ver;
extern const int mpegver_arr[4];

typedef enum layer{
	LAYER_reserved = -1,
	layer3 = 1, //We only support LAYER3.
	layer2 = -1,
	layer1 = -1,
} layer;
extern const int layer_arr[4];

//kilo bits / second 32 40 48 56 64 80 96 112 128 160 192 224 256 320 -1
typedef enum bitrate{
	bitrate_nan = -1,
	br32 = 32,
	br40 = 40,
	br48 = 48,
	br56 = 56,
	br64 = 64,
	br80 = 80,
	br96 = 96,
	br112 = 112,
	br128 = 128,
	br160 = 160,
	br192 = 192,
	br224 = 224,
	br256 = 256,
	br320 = 320,
} bitrate;
extern const int bitrate_arr[16];

// Rate of sampling (kHz) given in hz.
typedef enum samplerate{
	sr32 = 32000,
	sr44 = 44100,
	sr48 = 48000,
	nan = -1,
} samplerate;
extern const int samplerate_arr[4];

// Number of audio channels
typedef enum channel{
	stereo,
	joint_stereo,
	dual_channel,
	mono,
} channel;
extern const int channel_arr[4];

typedef enum mode_extenstion{
	mode1,
	mode2,
	mode3,
	mode4,
} mode_extenstion;
extern const int modeext_arr[4];

// Bits pr sample
typedef enum emphasize{
	none,
	fifty, //50/15
	emphasize_res,
	CCIT,
} emphasize;
extern const int emphasize_arr[4];






//======================================================
// This section is about parsing the physical header
// - Declare functions for parsing
// - Declare struct for parsing
//======================================================

typedef struct physical_header_metadata{
	// Header for physical frame is given
	// by first 4-bytes. I will denote what bits
	// decodes what below as start:end
	// Note: syncword can be at 31 or 32 start pos
	bool parsed;
	syncword syncword;              // 32:21
	mpeg_ver mpeg;                  // 20:19 MUST be MPEG1 = 0b11;
	layer layer;                    // 18:17 MUST be Layer3 = 0b01
	protection_bit protection;      // 16:16
	bitrate br;                     // 15:12
	samplerate sr;                  // 11:10
	padding_bit padding;            // 09:09
	private_bit private_bit;        // 08:08
	channel ch;                     // 07:06
	mode_extenstion mode_extension; // 05:04
	copyright_bit copyright;        // 03:03
	original_bit original;          // 02:02
	emphasize emphasize;            // 01:00

} physical_header_metadata;



int init_physical_header(physical_header_metadata *phm);
int destroy_physical_header(physical_header_metadata *phm);
int parse_physical_header(physical_header_metadata *phm, unsigned int header); // Parse physical_header
int validateMP3_physical_header(physical_header_metadata *phm);
