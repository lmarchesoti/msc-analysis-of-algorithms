#!/bin/bash

# instructional print
echo ""
echo TEST CASE : TIME TO RUN
echo DIFF
echo "-------------------------------------------"

# run prog for each valid test in input
# calculates time to run each instance
# prints difference in output from target
for test_case in `ls input`; do

  if [ -s input/$test_case ]
  then

    START=$(date -u +"%s.%N")
    ./prog < input/$test_case > output/$test_case
    END=$(date -u +"%s.%N")
    TIME=$(echo "$END - $START" | bc -l)

    printf "\n%s : %.3fs\n" $test_case $TIME
    diff output/$test_case target/$test_case
    echo "-------------------------------------------"

  fi

done
