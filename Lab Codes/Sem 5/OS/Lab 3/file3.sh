files=`find . -name "*.txt"`
for i in $files;do
cp $i `echo $i | cut -d '.' -f 1-2`".text"
done
