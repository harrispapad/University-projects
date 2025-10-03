#!/bin/bash

# Loop through all input files in the current directory
for input_file in input*.txt; do
  # Extract the numeric index from the input file name
  index=$(echo "$input_file" | grep -o '[0-9]\+')

  # Construct the corresponding output file name
  output_file="output${index}.txt"

  # Start timing
  start_time=$(date +%s%N)

  # Run the program and capture its output
  program_output=$(./reveillon < "$input_file")

  # Stop timing
  end_time=$(date +%s%N)
  elapsed_time=$(( (end_time - start_time) / 1000000 )) # Convert nanoseconds to milliseconds

  # Compare the program's output with the expected output
  if [[ "$program_output" != "$(cat "$output_file")" ]]; then
    echo "Mismatch in test case: $index (Time: ${elapsed_time}ms)"
  else
    echo "Test case $index passed (Time: ${elapsed_time}ms)"
  fi
done

