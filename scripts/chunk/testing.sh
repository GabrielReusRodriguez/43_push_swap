#!/bin/bash



NUMS=$(./genera_numeros.sh)
echo -e "\tNUMS: ${NUMS}"
NUM_LINEAS=$(../42/bin/push_swap ${NUMS} | wc -l )
VALIDATOR=$(../42/bin/push_swap ${NUMS} | ../checkers/checker_linux ${NUMS})
echo -e "\tCHECKER: ${VALIDATOR}; num lines = ${NUM_LINEAS}"

#echo ${NUM_LINEAS} | xargs -1 echo 

#numb = 1 + int(rand() * range * ((-1) ^ (rand() % 2 )))
#printf "${ARGS}"  > ./a.txt
#cat <<< "${ARGS}" > a.txt
#  echo NUMBERS = $ARGS  
  #RETURN=$(../42/bin/push_swap ${ARGS} | wc  -l)
  
  #echo "${ARGS} => ${RETURN}" >> ./a.txt
  #VALIDADOR=$(../v1/bin/push_swap ${ARGS} | ../checkers/checker_Mac ${ARGS})
  #if [ $RETURN -gt 12 ]; then echo -n "MAL => ${RETURN} => ${ARGS}" ;
  #else echo -n "BIEN => ${RETURN} => ${ARGS}";
  #fi
  #if [ $RETURN -gt 12 ]; then echo -n "OK"; else echo -n "FAIL";
  #fi
  #echo *
#done
