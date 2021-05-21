#include "ph_header.h"
//======================================================
// This section is about types describing the physical
// side information.
// - Defining types relevant for the side information
// - Defining lookup-arrays, which convert raw bits to
//    relevant information by using raw bits as index.
// - NOTE: Side information various depending on
//    single or dual channel mode. This is accounted for.
//======================================================

typedef uint16_t main_data_begin;
typedef uint8_t private_bits;
typedef uint8_t share;

typedef struct dual_channel_side{

} dual_channel_side;

typedef struct single_channel_side{

} single_channel_side;

typedef struct side_information_metadata{
	void* csi;
} side_information_metadata;
