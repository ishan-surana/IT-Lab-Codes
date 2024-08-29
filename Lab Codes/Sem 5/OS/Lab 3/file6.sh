for file in `ls`; do
  if [ -f "$file" ]; then
    sed -i -e 's/^ex:/Example:/g ; s/\. ex:/\. Example:/g' "$file"
  fi
done