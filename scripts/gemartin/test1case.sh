#/bin/sh

ARG=$1
#echo $ARG |  xargs ./push_swap | wc -l
./push_swap $ARG | wc -l
./push_swap $ARG | ../checkers/checker_Mac $ARG