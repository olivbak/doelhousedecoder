#include "ph_header.h"

int sync_word = 0x7FF;

/* Indexing arrays;
 * Used to index parsed bytes to get correct information
 */
int const syncword_arr[4] ={sw1,sw2,sw3,-1};
int const mpegver_arr[4] = {mpeg2_5,MPEG_reserved,mpeg2,mpeg1};
int const layer_arr[4] =   {LAYER_reserved,layer3, layer2, layer1};
int const bitrate_arr[16] =
    {bitrate_nan, br32,br40,br48,br56,br64,br80,br96
    ,br112,br128,br160,br192,br224,br256,br320,bitrate_nan};
int const samplerate_arr[4] = {sr44,sr48,sr32,nan};
int const channel_arr[4]    = {stereo,joint_stereo,dual_channel,mono};
int const modeext_arr[4]   =  {mode1,mode2,mode3,mode4};
int const emphasize_arr[4] =  {none,fifty,emphasize_res,CCIT};


int init_physical_header(physical_header_metadata* phm){
	phm->parsed = false;
	return 0;
}

int destroy_physical_header(physical_header_metadata *phm)
{
	free(phm);
	return 0;
}

int parse_physical_header(physical_header_metadata *phm, unsigned int header)
{
	if(phm->parsed) return ERROR_REUSED_HEADER;
    uint32_t syncword_mask     = 0xFFF00000; //12
    uint32_t mpegver_mask      = 0x000C0000; //2
    uint32_t layer_mask        = 0x00030000; //
    uint32_t protection_mask   = 0x00008000;
    uint32_t bitrate_mask      = 0x0000F000; //v
    uint32_t sample_mask       = 0x00000C00; //v
    uint32_t padding_mask      = 0x00000200; //v
    uint32_t private_mask      = 0x00000100; //v
    uint32_t channel_mask      = 0x000000C0; //v
    uint32_t mode_mask         = 0x00000030; //v
    uint32_t copyright_mask    = 0x00000008; //v
    uint32_t original_mask     = 0x00000004; //v
    uint32_t emphasize_mask    = 0x00000003; //v
	return 0;
}

