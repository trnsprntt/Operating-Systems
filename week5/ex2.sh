lockfile=ex2
tmpfile=${lockfile}.$$
echo $$ > $tmpfile
if ln $tmpfile $lockfile 2>&-; then
    echo locked
else
    echo locked by $(<$lockfile)
    rm $tmpfile
    exit
fi
trap "rm ${tmpfile} ${lockfile}"
while  [ true ]
do
while read line; do
n=$((line+1))
done < ex2.txt
echo $n >> ex2.txt
done
