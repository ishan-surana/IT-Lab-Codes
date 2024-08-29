echo -n "Enter file name: "
read file
if [ -f $file ]; then
    sed -ne '1~2p' $file >> $file"2"
    rm $file
    mv $file"2" $file
fi