#!/bin/bash

echo 5421 7 | ../testgenRandom.exe 2> /dev/null > ./test01.in
echo 123 10 5 | ../testgenFewSolutions.exe 2> /dev/null > ./test02.in
echo 12752 10 0 | ../testgenFewSolutions.exe 2> /dev/null > ./test03.in

echo 7859 50 20 | ../testgenFewSolutions.exe 2> /dev/null > ./test04.in
echo 28935 50 50 | ../testgenFewSolutions.exe 2> /dev/null > ./test05.in

echo 652435 100 | ../testgenRandom.exe 2> /dev/null > ./test06.in
echo 535 100 | ../testgenRandom.exe 2> /dev/null > ./test07.in
echo 10 100 | ../testgenRandom.exe 2> /dev/null > ./test08.in
echo 99 100 100 | ../testgenFewSolutions.exe 2> /dev/null > ./test09.in
echo 69 100 500 | ../testgenFewSolutions.exe 2> /dev/null > ./test10.in

echo 412435 500 | ../testgenRandom.exe 2> /dev/null > ./test11.in
echo 53512 500 100 | ../testgenReverseOrder.exe 2> /dev/null > ./test12.in
echo 10000 500 10 | ../testgenReverseOrder.exe 2> /dev/null > ./test13.in
echo 99 500 0 | ../testgenReverseOrder.exe 2> /dev/null > ./test14.in
echo 69 500 1000 | ../testgenFewSolutions.exe 2> /dev/null > ./test15.in

echo 100 1000 | ../testgenRandom.exe 2> /dev/null > ./test16.in
echo 200 1000 300 | ../testgenReverseOrder.exe 2> /dev/null > ./test17.in
echo 300 1000 10 | ../testgenReverseOrder.exe 2> /dev/null > ./test18.in
echo 400 1000 0 | ../testgenFewSolutions.exe 2> /dev/null > ./test19.in
echo 500 1000 1000 | ../testgenFewSolutions.exe 2> /dev/null > ./test20.in