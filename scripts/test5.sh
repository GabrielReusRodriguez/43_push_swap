#!/bin/bash

count=$1

for i in $(seq $count); do
  SEED=$(date +%s)
  ARGS=$(awk -v loop=5 -v range=100 -v seed=$SEED 'BEGIN{
      count = 0
      srand(seed)
      do {
        numb = 1 + int(rand() * range) 
        if (!(numb in prev)) {
            printf "%d ", numb 
            prev[numb] = 1
            count++
        }
      } while (count<loop)
    }')
  sleep 1
#numb = 1 + int(rand() * range * ((-1) ^ (rand() % 2 )))
#printf "${ARGS}"  > ./a.txt
#cat <<< "${ARGS}" > a.txt
  echo NUMBERS = $ARGS  
  #RETURN=$(../42/bin/push_swap ${ARGS} | wc  -l)
  
  #echo "${ARGS} => ${RETURN}" >> ./a.txt
  #VALIDADOR=$(../v1/bin/push_swap ${ARGS} | ../checkers/checker_Mac ${ARGS})
  #if [ $RETURN -gt 12 ]; then echo -n "MAL => ${RETURN} => ${ARGS}" ;
  #else echo -n "BIEN => ${RETURN} => ${ARGS}";
  #fi
  #if [ $RETURN -gt 12 ]; then echo -n "OK"; else echo -n "FAIL";
  #fi
  #echo *
done
