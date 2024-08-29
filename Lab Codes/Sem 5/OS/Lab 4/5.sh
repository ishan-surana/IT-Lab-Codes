search_patterns() {
    for pattern in "${patterns[@]}"; do
        echo "Lines containing pattern '$pattern':"
        grep -n "$pattern" "$input_file"
        echo
    done
}

delete_patterns() {
    cp "$input_file" "$input_file.temp"
    echo "Temp file created: $input_file.temp"
    for pattern in "${patterns[@]}"; do
        sed -i "s/$pattern//g" "$input_file.temp"
    done
    mv "$input_file.temp" "$input_file"
    echo "Deleted all occurrences of patterns in '$input_file'."
}

while true; do
    echo "Menu:"
    echo "1. Search patterns in the given input file"
    echo "2. Delete all occurrences of patterns in the given input file"
    echo "3. Exit"
    echo -n "Enter your choice (1-3): "
    read choice
    input_file=$1
    patterns=("${@:2}")
    case $choice in
        1) search_patterns "$input_file" "${patterns[@]}";;
        2) delete_patterns "$input_file" "${patterns[@]}";;
        3) echo "Exiting the script."
            exit 0;;
        *) echo "Invalid choice. Please enter 1, 2, or 3.";;
    esac
done
