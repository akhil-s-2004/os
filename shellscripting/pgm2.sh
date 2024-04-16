!/bin/bash
ch="y"
while [ $ch == "y" ]
do
        echo "Enter number 1: "
        read num1
        echo "Enter number 2: "
        read num2
        echo "1.Addition"
        echo "2.Subtraction"
        echo "3.Multiplication"
        echo "4.Division"
        echo "5.Modulus"
        echo "Enter your choice: "
        read op
        case $op in
                1)
                        sum=$(($num1 + $num2))
                        echo "Sum = $sum";;
                2)
! /bin/bash
echo "OS and version, release date"
uname -a
echo
cat /etc/os-release
echo
echo "kernel version"
uname -r
echo
echo "Avaiolble shells"
cat /etc/shells
echo
echo "CPU INFORMATION"
cat /proc/cpuinfo
echo
echo "Memory Information"
cat /proc/meminfo
echo
echo "Hard disk information"
lsblk
echo
echo "File system(mounted)"
df -h
                        dif=$(($num1 - $num2))
                        echo "Difference = $dif";;
                3)
                        mul=$(($num1 * $num2))
                        echo "Product = $mul";;
                4)
                        div=$(($num1 / $num2))
                        echo "result = $div";;
                5)
                        mod=$(($num1 % $num2))
                        echo "Modulus= $mod";;
                *)
                        echox "Invalid choice";;
        esac
        echo "do you want to continue(y/n): "
        read ch
done

