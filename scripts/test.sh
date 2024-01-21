#!/usr/bin/env bash

count=$1
for i in $(seq $count); do
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

#numb = 1 + int(rand() * range * ((-1) ^ (rand() % 2 )))
#printf "${ARGS}"  > ./a.txt
#cat <<< "${ARGS}" > a.txt
  
  RETURN=$(./push_swap ${ARGS} | wc  -l)
  echo "${ARGS} => ${RETURN}" >> ./a.txt
  #echo "VALOR: _${RETURN}_"
  if [ $RETURN -gt 12 ]; then echo "MAL => ${RETURN} => ${ARGS}" ;
  fi
  #echo ${ARGS} 
done
