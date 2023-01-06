#!/bin/bash

make && clear
# Replace with the name of your binary
BIN=sedisforlosers
echo -e "first line\nsecond line second line\nthird line\nfourth line\nlast line" > test

echo -e "\e[1;32mCreated file\e[0m"
cat test

echo

echo -e "\e[1;32mTest 1: Replace character 'i' for 'q'\e[0m"
./$BIN test "i" "q" && cat test.replace
echo -e "\e[0;33msed:\e[0m"
sed 's/i/q/g' test

echo

echo -e "\e[1;32mTest 2: Replace 'line' for 'sentence'\e[0m"
./$BIN test "line" "sentence" && cat test.replace
echo -e "\e[0;33msed:\e[0m"
sed 's/line/sentence/g' test

echo

echo -e "\e[1;32mTest 3: Replace 'apple' for 'orange'\e[0m"
./$BIN test "apple" "orange" && cat test.replace
echo -e "\e[0;33msed:\e[0m"
sed 's/apple/orange/g' test

echo

echo -e "\e[1;32mTest 4: Replace 'line' for 'a longer string to replace original string'\e[0m"
./$BIN test "line" "a longer string to replace original string" && cat test.replace
echo -e "\e[0;33msed:\e[0m"
sed 's/line/a longer string to replace original string/g' test

echo

echo -e "\e[1;31mTest 5: Invalid file\e[0m"
./$BIN invalid_file "line" "a longer string to replace line"
echo -e "\e[0;33msed:\e[0m"
sed 's/line/a longer string to replace line/g' invalid_file

echo

echo -e "\e[1;31mTest 6: 4 arguments\e[0m"
./$BIN test "line" "sentence" "sentence"

echo

echo -e "\e[1;31mTest 7: 2 arguments\e[0m"
./$BIN test

echo

echo -e "\e[1;31mTest 8: First string is empty\e[0m"
./$BIN test "" "sentence"

echo

echo -e "\e[1;31mTest 9: Both strings are empty\e[0m"
./$BIN test "" ""

echo

echo -e "\e[1;32mTest 10: Test infinite loop\e[0m"
./$BIN test "line" "line break" && cat test.replace
echo -e "\e[0;33msed:\e[0m"
sed 's/line/line break/g' test

echo

rm -f test
