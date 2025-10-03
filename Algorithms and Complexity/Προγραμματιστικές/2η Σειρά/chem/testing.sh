#!/bin/bash

# Function to process a single test case
process_test_case() {
  index=$1

  # Construct the corresponding input and output file names
  input_file="input${index}.txt"
  output_file="output${index}.txt"

  # Check if the input and output files exist
  if [[ ! -f "$input_file" ]]; then
    echo "Input file $input_file does not exist for test case $index."
    return
  fi
  if [[ ! -f "$output_file" ]]; then
    echo "Expected output file $output_file does not exist for test case $index."
    return
  fi

  # Start timing
  start_time=$(date +%s%N)

  # Run the program with a timeout and capture its output
  program_output=$(timeout 10 ./chem < "$input_file")

  # Check if the program timed out
  if [[ $? -eq 124 ]]; then
    echo "Test case $index failed due to timeout (Exceeded 10 seconds)"
    return
  fi

  # Stop timing
  end_time=$(date +%s%N)
  elapsed_time=$(( (end_time - start_time) / 1000000 )) # Convert nanoseconds to milliseconds

  # Compare the program's output with the expected output
  if [[ "$program_output" != "$(cat "$output_file")" ]]; then
    echo "Test case $index failed (Time: ${elapsed_time}ms). Output mismatch."
  else
    echo "Test case $index passed (Time: ${elapsed_time}ms)"
  fi
}

# Loop through test cases from 1 to 20
for i in {1..20}; do
  process_test_case $i
done
