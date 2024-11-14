#!/bin/bash

# Read arguments into an array
arr=("$@")

# Print array elements
echo "Array elements: ${arr[@]}"

# Print the number of arguments
echo "Number of arguments: ${#arr[@]}"

# Loop through array elements
echo "Looping through array:"
for element in "${arr[@]}"; do
  echo "$element"
done

# Access the last element (using negative indexing)
last_index=$((${#arr[@]} - 1))
echo "Last element: ${arr[$last_index]}"

# Add an element to the array
arr+=("new_element")
echo "Updated array: ${arr[@]}"

# Remove an element by index
index_to_remove=2
unset arr[$index_to_remove]

# Print updated array
echo "Updated array: ${arr[@]}"

# Get the length of the array
length=${#arr[@]}
echo "Array length: $length"

search_element="search_element"

# Check if the element exists
if [[ " ${arr[@]} " =~ " $search_element " ]]; then
  echo "$search_element is in the array."
else
  echo "$search_element is NOT in the array."
fi

# Sort the array
sorted_arr=($(echo "${arr[@]}" | tr ' ' '\n' | sort -n | tr '\n' ' '))
echo "Sorted array: ${sorted_arr[@]}"