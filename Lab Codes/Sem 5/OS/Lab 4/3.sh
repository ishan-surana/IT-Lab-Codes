strings=("$@")
custom_sort() {
    for ((i=0; i<$#-1; i++)); do
        for((j=0; j<$#-i-1; j++)); do
            if [[ ${strings[j]} > ${strings[j+1]} ]]; then
                temp=${strings[j]}
                strings[j]=${strings[j+1]}
                strings[j+1]=$temp
            fi
        done
    done
    echo ${strings[@]}
}

custom_sort ${strings[@]}