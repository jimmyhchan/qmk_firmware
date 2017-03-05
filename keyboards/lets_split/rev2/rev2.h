#ifndef REV2_H
#define REV2_H

//#include "../lets_split.h"

//void promicro_bootloader_jmp(bool program);
#include "quantum.h"

//void promicro_bootloader_jmp(bool program);

#define KEYMAP_EXTRA_BOTTOM_ROW( \
	k00, k01, k02, k03, k04, k05, k45, k44, k43, k42, k41, k40, \
	k10, k11, k12, k13, k14, k15, k55, k54, k53, k52, k51, k50, \
	k20, k21, k22, k23, k24, k25, k65, k64, k63, k62, k61, k60, \
	k30, k31, k32, k33, k34, k35, k75, k74, k73, k72, k71, k70, \
                 k85, k84, k83, k82, k81, k80 \
	) \
	{ \
		{ k00, k01, k02, k03, k04, k05 }, \
		{ k10, k11, k12, k13, k14, k15 }, \
		{ k20, k21, k22, k23, k24, k25 }, \
		{ k30, k31, k32, k33, k34, k35 }, \
		{ k40, k41, k42, k43, k44, k45 }, \
		{ k50, k51, k52, k53, k54, k55 }, \
		{ k60, k61, k62, k63, k64, k65 }, \
		{ k70, k71, k72, k73, k74, k75 }, \
		{ k80, k81, k82, k83, k84, k85 }, \
		{ k80, k81, k82, k83, k84, k85 }, \
		{ k80, k81, k82, k83, k84, k85 }, \
		{ k80, k81, k82, k83, k84, k85 } \
	}

#define KEYMAP_EXTRA_RIGHT_COLUMN( \
	k00, k01, k02, k03, k04, k05, k45, k44, k43, k42, k41, k40, k85,\
	k10, k11, k12, k13, k14, k15, k55, k54, k53, k52, k51, k50, k84,\
	k20, k21, k22, k23, k24, k25, k65, k64, k63, k62, k61, k60, k83,\
	k30, k31, k32, k33, k34, k35, k75, k74, k73, k72, k71, k70, k82,\
                                                              k81,\
                                                              k80\
	) \
	{ \
		{ k00, k01, k02, k03, k04, k05 }, \
		{ k10, k11, k12, k13, k14, k15 }, \
		{ k20, k21, k22, k23, k24, k25 }, \
		{ k30, k31, k32, k33, k34, k35 }, \
		{ k40, k41, k42, k43, k44, k45 }, \
		{ k50, k51, k52, k53, k54, k55 }, \
		{ k60, k61, k62, k63, k64, k65 }, \
		{ k70, k71, k72, k73, k74, k75 }, \
		{ k80, k81, k82, k83, k84, k85 }, \
		{ k80, k81, k82, k83, k84, k85 }, \
		{ k80, k81, k82, k83, k84, k85 }, \
		{ k80, k81, k82, k83, k84, k85 } \
	}
#define KEYMAP_EXTRA_LEFT_COLUMN( \
  k85, k00, k01, k02, k03, k04, k05, k45, k44, k43, k42, k41, k40,\
  k84, k10, k11, k12, k13, k14, k15, k55, k54, k53, k52, k51, k50,\
  k83, k20, k21, k22, k23, k24, k25, k65, k64, k63, k62, k61, k60,\
  k82, k30, k31, k32, k33, k34, k35, k75, k74, k73, k72, k71, k70,\
  k81,\
  k80\
	) \
	{ \
		{ k00, k01, k02, k03, k04, k05 }, \
		{ k10, k11, k12, k13, k14, k15 }, \
		{ k20, k21, k22, k23, k24, k25 }, \
		{ k30, k31, k32, k33, k34, k35 }, \
		{ k40, k41, k42, k43, k44, k45 }, \
		{ k50, k51, k52, k53, k54, k55 }, \
		{ k60, k61, k62, k63, k64, k65 }, \
		{ k70, k71, k72, k73, k74, k75 }, \
		{ k80, k81, k82, k83, k84, k85 }, \
		{ k80, k81, k82, k83, k84, k85 }, \
		{ k80, k81, k82, k83, k84, k85 }, \
		{ k80, k81, k82, k83, k84, k85 } \
	}
#endif
