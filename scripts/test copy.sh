#!/usr/bin/env bash


ARGS=$(awk -v loop=5 -v range=100 'BEGIN{
  srand()
  do {
    numb = 1 + int(rand() * range)
    if (!(numb in prev)) {
       printf "%d ", numb 
       prev[numb] = 1
       count++
    }
  } while (count<loop)
}')

#printf "${ARGS}"  > ./a.txt
#cat <<< "${ARGS}" > a.txt
echo ${ARGS} > ./a.txt
echo ${ARGS} 
./push_swap ${ARGS} | wc  -l
