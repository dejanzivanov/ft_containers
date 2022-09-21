#!/bin/bash

Color_Off='\033[0m'       # Text Reset

# Regular Colors
Black='\033[0;30m'        # Black
Red='\033[0;31m'          # Red
Green='\033[0;32m'        # Green
Yellow='\033[0;33m'       # Yellow
Blue='\033[0;34m'         # Blue
Purple='\033[0;35m'       # Purple
Cyan='\033[0;36m'         # Cyan
White='\033[0;37m'        # White

# Bold
BBlack='\033[1;30m'       # Black
BRed='\033[1;31m'         # Red
BGreen='\033[1;32m'       # Green
BYellow='\033[1;33m'      # Yellow
BBlue='\033[1;34m'        # Blue
BPurple='\033[1;35m'      # Purple
BCyan='\033[1;36m'        # Cyan
BWhite='\033[1;37m'       # White

#test for all containers at the same time
std_all_binary=std_all_binary
ft_all_binary=ft_all_binary


# 42 main test 
std_42_binary=./42_std_binary
ft_42_binary=./42_ft_binary


# container tests separately
std_stack_binary=std_stack_binary
ft_stack_binary=ft_stack_binary

std_vector_binary=std_vector_binary
ft_vector_binary=ft_vector_binary

std_map_binary=std_map_binary
ft_map_binary=ft_map_binary

printf "\n"

echo -e "${Red}Compiling Binaries...${Color_Off}"

make std_all > "/dev/null"
make ft_all > "/dev/null"

make std_42 > "/dev/null"
make ft_42 > "/dev/null"

make std_stack > "/dev/null"
make ft_stack > "/dev/null"

make std_vector > "/dev/null"
make ft_vector > "/dev/null"

make std_map > "/dev/null"
make ft_map > "/dev/null"

echo -e "${Green}Compiling done...${Color_Off}"

printf "\n"

echo -e "${BRed}Running test with main from 42 STD vs FT...${Color_Off}"

./42_std_binary 1 > std_42.txt
./42_ft_binary 1 > ft_42.txt

std_seed="`cat std_42.txt | grep "seed" | sed "s/should be constant with the same seed: //g"`"
ft_seed="`cat ft_42.txt | grep "seed" | sed "s/should be constant with the same seed: //g"`"

echo -e ${BYellow}SEED CHECK ${Color_Off}

echo -e ${BRed}STD seed is: ${Color_Off}${BGreen}${std_seed}${Color_Off}
echo -e ${BRed}FT  seeed is: ${Color_Off}${BGreen}${ft_seed}${Color_Off}



if [ "$std_seed" == "$ft_seed" ]
then
	echo -e ${BRed}Seed is the same${Color_Off}
else
	echo -e ${BRed}Seed is different${Color_Off}
fi

printf "\n"

echo -e "${BYellow}MEMORY CHECK ${Color_Off}"

echo -e "${BRed}Performing valgrind(memory check) ${Color_Off}"

valgrind ./42_std_binary 1 &> std_42_memory.txt
valgrind ./42_ft_binary 1 &> ft_42_memory.txt

echo -e "${BGreen}Memory check is done ${Color_Off}"

echo -e "${BYellow}STD vs FT ${Color_Off}"

ft_mem="`cat ft_42_memory.txt | grep "All heap blocks were freed -- no leaks are possible"`"
std_mem="`cat std_42_memory.txt | grep "All heap blocks were freed -- no leaks are possible"`"


echo -e "${BRed}STD: ${Color_Off} ${std_mem}" 
echo -e "${BRed}FT: ${Color_Off} ${ft_mem}" 

ft_mem="`cat ft_42_memory.txt | grep "All heap blocks were freed -- no leaks are possible" |  sed "s/[[:digit:]]//g"`"
std_mem="`cat std_42_memory.txt | grep "All heap blocks were freed -- no leaks are possible" | sed "s/[[:digit:]]//g"`"

if [ "$ft_mem" == "$ft_mem" ]
then
	echo -e "${BYellow}There are no memory leaks in either tests ${Color_Off}"
else
	echo -e "${BYellow}There is a memory problem ${Color_Off}"
fi

printf "\n"

echo -e "${BYellow}TIME CHECK ${Color_Off}"

echo -e "${BRed}Performing time check ${Color_Off}"

exec 3>std_time_test.txt 4>std_time_test.txt
foo=$({ time ./42_std_binary 1 1>std_time_test.txt 2>std_time_test.txt;} 2>std_time_test.txt | awk -F'[s.]' '/user/{print $3}')
foo=$({ time ./42_ft_binary 1 1>ft_time_test.txt 2>ft_time_test.txt;} 2>ft_time_test.txt | awk -F'[s.]' '/user/{print $3}')
exec 3>&- 4>&-

std_time="`cat std_time_test.txt | grep "real" | sed "s/m //g" | sed "s/s //g" | sed "s/real//g"`"
ft_time="`cat ft_time_test.txt | grep "real" | sed "s/m //g" | sed "s/s //g" | sed "s/real//g"`"
echo "execution time of std is: $std_time"
echo "execution time of ft is:: $ft_time"

printf "\n"

echo -e "${BRed}Performing output difference ${Color_Off}"

./42_std_binary 1 > std_42.txt
./42_ft_binary 1 > ft_42.txt

diff std_42.txt ft_42.txt > diff.txt

if [ -s diff.txt ]
then
	echo -e "${BRed}There is a difference, and there has been a problem. ${Color_Off}"
else
	echo -e "${BRed}There is no difference and code output is the same. ${Color_Off}"
fi

printf "\n"

echo -e "${BCyan}PERFORMING TESTS ON ALL CONTAINERS COMBINED ${Color_Off}"

printf "\n"

./std_all_binary 1 > std_all.txt
./ft_all_binary 1 > ft_all.txt

printf "\n"

echo -e "${BYellow}MEMORY CHECK ${Color_Off}"

echo -e "${BRed}Performing valgrind(memory check) ${Color_Off}"

valgrind ./std_all_binary 1 &> std_all_memory.txt
valgrind ./ft_all_binary 1 &> ft_all_memory.txt

echo -e "${BGreen}Memory check is done ${Color_Off}"

echo -e "${BYellow}STD vs FT ${Color_Off}"

ft_mem="`cat ft_all_memory.txt | grep "All heap blocks were freed -- no leaks are possible"`"
std_mem="`cat std_all_memory.txt | grep "All heap blocks were freed -- no leaks are possible"`"


echo -e "${BRed}STD: ${Color_Off} ${std_mem}" 
echo -e "${BRed}FT: ${Color_Off} ${ft_mem}" 

ft_mem="`cat ft_all_memory.txt | grep "All heap blocks were freed -- no leaks are possible" |  sed "s/[[:digit:]]//g"`"
std_mem="`cat std_all_memory.txt | grep "All heap blocks were freed -- no leaks are possible" | sed "s/[[:digit:]]//g"`"

if [ "$ft_mem" == "$ft_mem" ]
then
	echo -e "${BYellow}There are no memory leaks in either tests ${Color_Off}"
else
	echo -e "${BYellow}There is a memory problem ${Color_Off}"
fi

printf "\n"

echo -e "${BYellow}TIME CHECK ${Color_Off}"

echo -e "${BRed}Performing time check ${Color_Off}"

exec 3>std_time_test.txt 4>std_time_test.txt
foo=$({ time ./std_all_binary 1 1>std_time_test.txt 2>std_time_test.txt;} 2>std_time_test.txt | awk -F'[s.]' '/user/{print $3}')
foo=$({ time ./ft_all_binary 1 1>ft_time_test.txt 2>ft_time_test.txt;} 2>ft_time_test.txt | awk -F'[s.]' '/user/{print $3}')
exec 3>&- 4>&-

std_time="`cat std_time_test.txt | grep "real" | sed "s/m //g" | sed "s/s //g" | sed "s/real//g"`"
ft_time="`cat ft_time_test.txt | grep "real" | sed "s/m //g" | sed "s/s //g" | sed "s/real//g"`"
echo "execution time of std is: $std_time"
echo "execution time of ft is:: $ft_time"

printf "\n"

echo -e "${BRed}Performing output difference ${Color_Off}"

./std_all_binary 1 > std_all.txt
./ft_all_binary 1 > ft_all.txt

diff std_all.txt ft_all.txt > diff.txt

if [ -s diff.txt ]
then
	echo -e "${BRed}There is a difference, and there has been a problem. ${Color_Off}"
else
	echo -e "${BGreen}There is no difference and code output is the same. ${Color_Off}"
fi

echo -e "${BCyan}PERFORMING TESTS ON VECTOR CONTAINER ${Color_Off}"

./std_vector_binary 1 > std_all.txt
./ft_vector_binary 1 > ft_all.txt

printf "\n"

echo -e "${BYellow}MEMORY CHECK ${Color_Off}"

echo -e "${BRed}Performing valgrind(memory check) ${Color_Off}"

valgrind ./std_vector_binary 1 &> std_all_memory.txt
valgrind ./ft_vector_binary 1 &> ft_all_memory.txt

echo -e "${BGreen}Memory check is done ${Color_Off}"

echo -e "${BYellow}STD vs FT ${Color_Off}"

ft_mem="`cat ft_all_memory.txt | grep "All heap blocks were freed -- no leaks are possible"`"
std_mem="`cat std_all_memory.txt | grep "All heap blocks were freed -- no leaks are possible"`"


echo -e "${BRed}STD: ${Color_Off} ${std_mem}" 
echo -e "${BRed}FT: ${Color_Off} ${ft_mem}" 

ft_mem="`cat ft_all_memory.txt | grep "All heap blocks were freed -- no leaks are possible" |  sed "s/[[:digit:]]//g"`"
std_mem="`cat std_all_memory.txt | grep "All heap blocks were freed -- no leaks are possible" | sed "s/[[:digit:]]//g"`"

if [ "$ft_mem" == "$ft_mem" ]
then
	echo -e "${BYellow}There are no memory leaks in either tests ${Color_Off}"
else
	echo -e "${BYellow}There is a memory problem ${Color_Off}"
fi

printf "\n"

echo -e "${BYellow}TIME CHECK ${Color_Off}"

echo -e "${BRed}Performing time check ${Color_Off}"

exec 3>std_time_test.txt 4>std_time_test.txt
foo=$({ time ./std_vector_binary 1 1>std_time_test.txt 2>std_time_test.txt;} 2>std_time_test.txt | awk -F'[s.]' '/user/{print $3}')
foo=$({ time ./ft_vector_binary 1 1>ft_time_test.txt 2>ft_time_test.txt;} 2>ft_time_test.txt | awk -F'[s.]' '/user/{print $3}')
exec 3>&- 4>&-

std_time="`cat std_time_test.txt | grep "real" | sed "s/m //g" | sed "s/s //g" | sed "s/real//g"`"
ft_time="`cat ft_time_test.txt | grep "real" | sed "s/m //g" | sed "s/s //g" | sed "s/real//g"`"
echo "execution time of std is: $std_time"
echo "execution time of ft is:: $ft_time"

printf "\n"

echo -e "${BRed}Performing output difference ${Color_Off}"

./std_vector_binary 1 > std_all.txt
./ft_vector_binary 1 > ft_all.txt

diff std_all.txt ft_all.txt > diff.txt

if [ -s diff.txt ]
then
	echo -e "${BRed}There is a difference, and there has been a problem. ${Color_Off}"
else
	echo -e "${BGreen}There is no difference and code output is the same. ${Color_Off}"
fi

echo -e "${BCyan}PERFORMING TESTS ON STACK CONTAINER ${Color_Off}"

./std_stack_binary 1 > std_all.txt
./ft_stack_binary 1 > ft_all.txt

printf "\n"

echo -e "${BYellow}MEMORY CHECK ${Color_Off}"

echo -e "${BRed}Performing valgrind(memory check) ${Color_Off}"

valgrind ./std_stack_binary 1 &> std_all_memory.txt
valgrind ./ft_stack_binary 1 &> ft_all_memory.txt

echo -e "${BGreen}Memory check is done ${Color_Off}"

echo -e "${BYellow}STD vs FT ${Color_Off}"

ft_mem="`cat ft_all_memory.txt | grep "All heap blocks were freed -- no leaks are possible"`"
std_mem="`cat std_all_memory.txt | grep "All heap blocks were freed -- no leaks are possible"`"


echo -e "${BRed}STD: ${Color_Off} ${std_mem}" 
echo -e "${BRed}FT: ${Color_Off} ${ft_mem}" 

ft_mem="`cat ft_all_memory.txt | grep "All heap blocks were freed -- no leaks are possible" |  sed "s/[[:digit:]]//g"`"
std_mem="`cat std_all_memory.txt | grep "All heap blocks were freed -- no leaks are possible" | sed "s/[[:digit:]]//g"`"

if [ "$ft_mem" == "$ft_mem" ]
then
	echo -e "${BYellow}There are no memory leaks in either tests ${Color_Off}"
else
	echo -e "${BYellow}There is a memory problem ${Color_Off}"
fi

printf "\n"

echo -e "${BYellow}TIME CHECK ${Color_Off}"

echo -e "${BRed}Performing time check ${Color_Off}"

exec 3>std_time_test.txt 4>std_time_test.txt
foo=$({ time ./std_stack_binary 1 1>std_time_test.txt 2>std_time_test.txt;} 2>std_time_test.txt | awk -F'[s.]' '/user/{print $3}')
foo=$({ time ./ft_stack_binary 1 1>ft_time_test.txt 2>ft_time_test.txt;} 2>ft_time_test.txt | awk -F'[s.]' '/user/{print $3}')
exec 3>&- 4>&-

std_time="`cat std_time_test.txt | grep "real" | sed "s/m //g" | sed "s/s //g" | sed "s/real//g"`"
ft_time="`cat ft_time_test.txt | grep "real" | sed "s/m //g" | sed "s/s //g" | sed "s/real//g"`"
echo "execution time of std is: $std_time"
echo "execution time of ft is:: $ft_time"

printf "\n"

echo -e "${BRed}Performing output difference ${Color_Off}"

./std_stack_binary 1 > std_all.txt
./ft_stack_binary 1 > ft_all.txt

diff std_all.txt ft_all.txt > diff.txt

if [ -s diff.txt ]
then
	echo -e "${BRed}There is a difference, and there has been a problem. ${Color_Off}"
else
	echo -e "${BGreen}There is no difference and code output is the same. ${Color_Off}"
fi


echo -e "${BCyan}PERFORMING TESTS ON MAP CONTAINER ${Color_Off}"

./std_map_binary 1 > std_all.txt
./ft_map_binary 1 > ft_all.txt

printf "\n"

echo -e "${BYellow}MEMORY CHECK ${Color_Off}"

echo -e "${BRed}Performing valgrind(memory check) ${Color_Off}"

valgrind ./std_map_binary 1 &> std_all_memory.txt
valgrind ./ft_map_binary 1 &> ft_all_memory.txt

echo -e "${BGreen}Memory check is done ${Color_Off}"

echo -e "${BYellow}STD vs FT ${Color_Off}"

ft_mem="`cat ft_all_memory.txt | grep "All heap blocks were freed -- no leaks are possible"`"
std_mem="`cat std_all_memory.txt | grep "All heap blocks were freed -- no leaks are possible"`"


echo -e "${BRed}STD: ${Color_Off} ${std_mem}" 
echo -e "${BRed}FT: ${Color_Off} ${ft_mem}" 

ft_mem="`cat ft_all_memory.txt | grep "All heap blocks were freed -- no leaks are possible" |  sed "s/[[:digit:]]//g"`"
std_mem="`cat std_all_memory.txt | grep "All heap blocks were freed -- no leaks are possible" | sed "s/[[:digit:]]//g"`"

if [ "$ft_mem" == "$ft_mem" ]
then
	echo -e "${BYellow}There are no memory leaks in either tests ${Color_Off}"
else
	echo -e "${BYellow}There is a memory problem ${Color_Off}"
fi

printf "\n"

echo -e "${BYellow}TIME CHECK ${Color_Off}"

echo -e "${BRed}Performing time check ${Color_Off}"

exec 3>std_time_test.txt 4>std_time_test.txt
foo=$({ time ./std_map_binary 1 1>std_time_test.txt 2>std_time_test.txt;} 2>std_time_test.txt | awk -F'[s.]' '/user/{print $3}')
foo=$({ time ./ft_map_binary 1 1>ft_time_test.txt 2>ft_time_test.txt;} 2>ft_time_test.txt | awk -F'[s.]' '/user/{print $3}')
exec 3>&- 4>&-

std_time="`cat std_time_test.txt | grep "real" | sed "s/m //g" | sed "s/s //g" | sed "s/real//g"`"
ft_time="`cat ft_time_test.txt | grep "real" | sed "s/m //g" | sed "s/s //g" | sed "s/real//g"`"
echo "execution time of std is: $std_time"
echo "execution time of ft is:: $ft_time"

printf "\n"

echo -e "${BRed}Performing output difference ${Color_Off}"

./std_map_binary 1 > std_all.txt
./ft_map_binary 1 > ft_all.txt

diff std_all.txt ft_all.txt > diff.txt

if [ -s diff.txt ]
then
	echo -e "${BRed}There is a difference, and there has been a problem. ${Color_Off}"
else
	echo -e "${BGreen}There is no difference and code output is the same. ${Color_Off}"
fi

make fclean
rm -rf *.txt

