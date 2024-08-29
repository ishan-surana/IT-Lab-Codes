echo -n "Enter Basics: "
read basic
echo -n "Enter TA: "
read ta
echo "Gross Salary = "`echo "1.1*$basic+$ta" | bc`
