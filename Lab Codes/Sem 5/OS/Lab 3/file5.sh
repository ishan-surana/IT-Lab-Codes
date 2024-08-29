#echo -n "Enter extension: "
ext=$1
#echo -n "Enter new dir name: "
newdir=$2
mkdir $newdir
files=`ls *$ext`
for i in $files;do
mv $i $newdir
done