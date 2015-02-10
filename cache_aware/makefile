CFLAGS = -O
CC = g++
Test: 
	gcc main.c
verify:
	gcc verify_cache_aware.c naive.c version3_cache_aware.c version1_cache_aware.c version2_cache_aware.c
cache_aware:
	gcc cache_aware.c 

clean:
	rm -f core *.o
