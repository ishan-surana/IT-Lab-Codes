case $2 in
    -linecount) echo "Lines = $(wc -l "$1" | cut -d' ' -f1)";;
    -wordcount) echo "Words = $(wc -w "$1" | cut -d' ' -f1)";;
    -charcount) echo "Characters = $(wc -m "$1" | cut -d' ' -f1)";;
    *) echo "Invalid option";;
esac