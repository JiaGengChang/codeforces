g++ sol.cpp -o sol -DONLINE_JUDGE
g++ brute.cpp -o brute -DONLINE_JUDGE
g++ random.cpp -o random

for ((i=1; ; ++i)); do
  ./random $i > random_input.txt
  ./sol <random_input.txt > my_output.txt 
  ./brute <random_input.txt > brute_output.txt 
  diff -w my_output.txt brute_output.txt|| break
  echo "Passed test: $i"
done

echo -e "\nWA on the following test:"
cat random_input.txt
echo "Your answer is: "
cat my_output.txt
echo "Correct answer is: "
cat brute_output.txt
