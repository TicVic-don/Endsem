def find_minimum_integer(a):
    even_digits = []
    odd_digits = []

    for digit_char in a:
        digit = int(digit_char)
        if digit % 2 == 0:
            even_digits.append(digit)
        else:
            odd_digits.append(digit)

    result = ""
    even_index, odd_index = 0, 0

    while even_index < len(even_digits) and odd_index < len(odd_digits):
        if even_digits[even_index] < odd_digits[odd_index]:
            result += str(even_digits[even_index])
            even_index += 1
        else:
            result += str(odd_digits[odd_index])
            odd_index += 1

    while even_index < len(even_digits):
        result += str(even_digits[even_index])
        even_index += 1

    while odd_index < len(odd_digits):
        result += str(odd_digits[odd_index])
        odd_index += 1

    return result

def solve():
    s = input().strip()
    print(find_minimum_integer(s))

def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    t = int(data[0])
    cases = data[1:]
    
    for i in range(t):
        solve()

if __name__ == "_main_":
    main()