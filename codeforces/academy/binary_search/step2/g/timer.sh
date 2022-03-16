
g++ sol.cpp -o sol
g++ random.cpp -o random

for ((i=1; $i <= $1 ; ++i)); do
    ./random $i > random_input.txt
    ./sol <random_input.txt >output.txt 
    echo "Test case #".$i
    cat output.txt
    echo "Execution time: "
    cat error.txt
done
