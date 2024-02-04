#!/bin/bash
SEED=$(date +%s)
awk -v loop=5 -v range=100 -v seed=$SEED 'BEGIN{
      count = 0
      delete prev
      srand(seed)
      do {
        numb = 1 + int(rand() * range) 
        if (!(numb in prev)) {
            printf "%d ", numb 
            prev[numb] = 1
            count++
        }
      } while (count<loop)
    }'
sleep 1