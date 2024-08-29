echo -n "Enter file name: "
read name
result=`file $name`
if [[ $result == "$name: directory" ]];then
echo "Is a directory"
else
echo "Not a directory"
fi