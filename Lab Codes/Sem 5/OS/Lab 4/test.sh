search_patterns() {
    for pattern in "${@:2}"; do
        echo "Lines containing pattern '$pattern':"
        grep -n "$pattern" "$1"
        echo
    done
}

search_patterns "$@"