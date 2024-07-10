def find_largest(num1,num2,num3):
    if num1 >= num2 and num1 >= num3:
        return num1
    elif num2 >= num3 and num2 >= num1:
        return num2
    return num3

num1 = 5
# num2 = float(input("Enter second number: "))
# num3 = float(input("Enter third number: "))

print("\nThe largest number is=%.2f"%num1)