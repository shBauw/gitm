#!/bin/bash

for i in {A..B}; do
    for j in {1..19}; do
        echo "place ${i}${j}" >> tie.in
    done
done 

for i in {C..D}; do
    for j in {1..9}; do
        var=$(($j*2))
        var2=$(($var-1))
        echo "place ${i}${var}" >> tie.in
        echo "place ${i}${var2}" >> tie.in
    done
    echo "place ${i}19" >> tie.in
done 

for i in {E..F}; do
    for j in {1..19}; do
        echo "place ${i}${j}" >> tie.in
    done
done 

for i in {G..H}; do
    for j in {1..9}; do
        var=$(($j*2))
        var2=$(($var-1))
        echo "place ${i}${var}" >> tie.in
        echo "place ${i}${var2}" >> tie.in
    done
    echo "place ${i}19" >> tie.in
done 

for i in {I..J}; do
    for j in {1..19}; do
        echo "place ${i}${j}" >> tie.in
    done
done 

for i in {K..L}; do
    for j in {1..9}; do
        var=$(($j*2))
        var2=$(($var-1))
        echo "place ${i}${var}" >> tie.in
        echo "place ${i}${var2}" >> tie.in
    done
    echo "place ${i}19" >> tie.in
done 

for i in {M..N}; do
    for j in {1..19}; do
        echo "place ${i}${j}" >> tie.in
    done
done 

for i in {O..P}; do
    for j in {1..9}; do
        var=$(($j*2))
        var2=$(($var-1))
        echo "place ${i}${var}" >> tie.in
        echo "place ${i}${var2}" >> tie.in
    done
    echo "place ${i}19" >> tie.in
done 

for i in {Q..R}; do
    for j in {1..19}; do
        echo "place ${i}${j}" >> tie.in
    done
done 


for j in {1..9}; do
    var=$(($j*2))
    var2=$(($var-1))
    echo "place S${var}" >> tie.in
    echo "place S${var2}" >> tie.in
done
echo "place S19" >> tie.in

cat tie.in | less